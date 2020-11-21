#include "stdafx.h"

CSQL _iniciar_csql;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

CSQL::CSQL()
{
    bThrowErrors = true;
	bConnected = false;
    Disconnect();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

CSQL::~CSQL()
{
    Disconnect();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool CSQL::Connect(char *sServer)
{
    SQLRETURN Result;
    char sConnStr[1024];
    SQLCHAR sConStrOut[1024];
    SQLSMALLINT iConStrOutSz = 0;

    if(bConnected)
	{
        return false;
	}

    sprintf(sConnStr, "DRIVER={SQL Server}; SERVER=%s; DATABASE=MuOnline; Integrated Security=SSPI;",sServer);

    // Allocate the environment handle
    Result = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hSQLEnvironment);
    if(!SQL_SUCCEEDED(Result))
    {
        ThrowErrorIfSet(NULL);
		return false;
    }

    // Set the environment attributes
    Result = SQLSetEnvAttr(hSQLEnvironment, SQL_ATTR_ODBC_VERSION, (void *) SQL_OV_ODBC3, 0);
    if(!SQL_SUCCEEDED(Result))
    {
        ThrowErrorIfSet(NULL);
        SQLFreeHandle(SQL_HANDLE_ENV, hSQLEnvironment);
        return false;
    }

    // Allocate the connection handle
    Result = SQLAllocHandle(SQL_HANDLE_DBC, hSQLEnvironment, &hSQLConnection);
    if(!SQL_SUCCEEDED(Result))
    {
        ThrowErrorIfSet(NULL);
        SQLFreeHandle(SQL_HANDLE_DBC, hSQLConnection);
        SQLFreeHandle(SQL_HANDLE_ENV, hSQLEnvironment);
        return false;
    }

    // Set login timeout to 5 seconds.
    SQLSetConnectOption(hSQLConnection, SQL_LOGIN_TIMEOUT, 5);
    SQLSetConnectOption(hSQLConnection, SQL_CURSOR_TYPE, SQL_CURSOR_STATIC);

    // Connect
    Result = SQLDriverConnect(
        hSQLConnection,           // Connection handle.
        NULL,                     // Window handle.
        (SQLCHAR *)sConnStr,      // Input connect string.
        SQL_NTS,                  // Null-terminated string.
        sConStrOut,               // Address of output buffer.
        sizeof(sConStrOut),       // Size of output buffer.
        &iConStrOutSz,            // Address of output length.
        SQL_DRIVER_NOPROMPT
    );

    if(!SQL_SUCCEEDED(Result))
    {
        ThrowErrorIfSet(NULL);
        SQLFreeHandle(SQL_HANDLE_DBC, hSQLConnection);
        SQLFreeHandle(SQL_HANDLE_ENV, hSQLEnvironment);
        return false;
    }

    bConnected = true;
    return true;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool CSQL::GetErrorMessage(char *sOutError, const int iErrBufSz, HSTMT hStmt)
{
	SQLCHAR     sSQLState[20];
	SQLINTEGER  iOutNativeErr;
	SQLSMALLINT iOutErrorMsgSz;

	return SQL_SUCCEEDED(SQLError(hSQLEnvironment, hSQLConnection, hStmt, sSQLState, &iOutNativeErr, (SQLCHAR *)sOutError, iErrBufSz, &iOutErrorMsgSz));
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool CSQL::ThrowErrorIfSet(HSTMT hStmt)
{
	if(bThrowErrors == true)
	{
		return ThrowError(hStmt);
	}

	return false;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool CSQL::ThrowError(HSTMT hStmt)
{
	char sErrorMsg[1024];

	if(GetErrorMessage(sErrorMsg, sizeof(sErrorMsg), hStmt))
	{
		MessageBox(GetActiveWindow(), sErrorMsg, "CSQL::Error", MB_ICONERROR);
		return true;
	}

	return false;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CSQL::Disconnect(void)
{
    if(bConnected)
    {
        SQLDisconnect(hSQLConnection);
        SQLFreeHandle(SQL_HANDLE_DBC, hSQLConnection);
        SQLFreeHandle(SQL_HANDLE_ENV, hSQLEnvironment);
    }

    hSQLConnection = NULL;
    hSQLEnvironment = NULL;

    bConnected = false;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool CSQL::ExecuteNonQuery(const char *sSQL)
{
    if(!bConnected)
        return false;

    SQLRETURN Result = 0;

	bool bResult = false;

    HSTMT stmtHandle;

	Result = SQLAllocHandle(SQL_HANDLE_STMT, hSQLConnection, &stmtHandle);
    if(SQL_SUCCEEDED(Result))
    {
        Result = SQLPrepare(stmtHandle, (unsigned char *)sSQL, strlen(sSQL));
        if(SQL_SUCCEEDED(Result))
        {
            Result = SQLExecute(stmtHandle);
            if(Result == SQL_SUCCESS || Result == SQL_SUCCESS_WITH_INFO || Result == SQL_NO_DATA)
            {
                bResult = true;
            } else ThrowErrorIfSet(stmtHandle);
        } else ThrowErrorIfSet(stmtHandle);
    } else ThrowErrorIfSet(stmtHandle);

	SQLFreeHandle(SQL_HANDLE_STMT, stmtHandle);

	stmtHandle = NULL;
    
	return bResult;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool CSQL::Execute(const char *sSQL, CRecordSet *lpMyRS)
{
	if(!bConnected)
	{
        return false;
	}

    SQLRETURN Result = 0;

    Result = SQLAllocHandle(SQL_HANDLE_STMT, hSQLConnection, &lpMyRS->hSTMT);
    if(SQL_SUCCEEDED(Result))
    {
        Result = SQLPrepare(lpMyRS->hSTMT, (unsigned char *)sSQL, strlen(sSQL));
        if(SQL_SUCCEEDED(Result))
        {
			Result = SQLExecute(lpMyRS->hSTMT);
            if(Result == SQL_SUCCESS || Result == SQL_SUCCESS_WITH_INFO || Result == SQL_NO_DATA)
            {
				if(SQLRowCount(lpMyRS->hSTMT, &lpMyRS->RowCount) != SQL_SUCCESS)
				{
					lpMyRS->RowCount = 0;
				}

				if(SQLNumResultCols(lpMyRS->hSTMT, (SQLSMALLINT *) &lpMyRS->ColCount) != SQL_SUCCESS)
				{
					lpMyRS->ColCount = 0;
				}

				return true;
            } else ThrowErrorIfSet(lpMyRS->hSTMT);
        } else ThrowErrorIfSet(lpMyRS->hSTMT);
    } else ThrowErrorIfSet(lpMyRS->hSTMT);

	return false;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int CSQL::GetInt()
{
    long lSize,lResult=0;

    while(true)
	{
	    if(SQL_SUCCEEDED(SQLFetch(crec.hSTMT)) == 0)
		{
		    break;
		}

		if(SQL_SUCCEEDED(SQLGetData(crec.hSTMT,1,SQL_C_LONG,&lResult,sizeof(long),&lSize)) == 0)
		{
            break;
		}

		return lResult;
	}

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int SQLSyntaxCheckConvert(char* SQLString)
{

	char tempSQL[256];
	char* temp;
	char* temp2;

	temp2 = SQLString;
	int lOfs=0;
	int tOfs=0;
	int sOfs=0;

	if (SQLString == 0)
	{
		return 0;
	}

	temp = strchr(temp2, 39);
	if(temp == 0) return 0;

	while (true)
	{
		temp = strchr(temp2, 39);
		if (temp != 0 )
		{
			if (temp - temp2 != 0)
			{
				memcpy(&tempSQL[tOfs], temp2, temp-temp2);
			}

			lOfs = temp - (temp2 + sOfs);
			tOfs += lOfs;
			temp2 += lOfs;

			tempSQL[tOfs] = 0;

			tOfs += 2;
			temp2++;

			strcat(tempSQL, "''");

		}
		else
		{
			strcpy(&tempSQL[tOfs], temp2);
			break;
		}
	}

    memcpy(&SQLString[0], &tempSQL[0], strlen(tempSQL));

	return 1;

}