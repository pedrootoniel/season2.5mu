#include "stdafx.h"

CRecordSet crec;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CRecordSet::ReplaceSingleQuotes(char *sData, int iDataSz)
{
    int iRPos = 0;

    while(iRPos < iDataSz)
    {
        if(sData[iRPos] == '\'')
		{
            sData[iRPos] = '`';
		}
        iRPos++;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int CRecordSet::RTrim(char *sData, int iDataSz)
{
    int iPos = iDataSz;

    if(iDataSz == 0)
        return iDataSz;//Return the new data length.

    if(sData[iDataSz-1] != ' ')
        return iDataSz;//Return the new data length.

    iPos--;

    while(iPos != 0 && sData[iPos] == ' ')
        iPos--;

    if(sData[iPos] != ' ')
        iPos++;

    sData[iPos] = '\0';

    return iPos; //Return the new data length.
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool CRecordSet::Close(void)
{
	bool bResult = 0;

	RowCount = 0;
	ColCount = 0;
	
	bResult = (SQLFreeHandle(SQL_HANDLE_STMT, hSTMT) == SQL_SUCCESS);

	hSTMT = NULL;

	return bResult;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool CRecordSet::FetchEx(long *lErrCode)
{
    SQLRETURN lResult = 0;

	if(SQL_SUCCEEDED((lResult = SQLFetch(hSTMT))))
	{
		*lErrCode = lResult;
        return true;
	}
	else {
		*lErrCode = lResult;
		ThrowErrorIfSet();
		return false;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool CRecordSet::Fetch(void)
{
    if(SQL_SUCCEEDED(SQLFetch(hSTMT)))
	{
        return true;
	}
	else {
		ThrowErrorIfSet();
		return false;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool CRecordSet::GetData(const SQLUSMALLINT iCol, SQLSMALLINT iType, SQLPOINTER pvBuf, SQLINTEGER iBufSz, SQLINTEGER *piOutBufSz)
{
    if(SQL_SUCCEEDED(SQLGetData(hSTMT, iCol, iType, pvBuf, iBufSz, piOutBufSz)))
	{
		return true;
	}
	else {
		ThrowErrorIfSet();
		return false;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool CRecordSet::GetColInfo(const int iCol, char *sOutName, int iSzOfOutName, int *iOutColNameLen,
							int *ioutDataType, int *iOutColSize, int *iNumOfDeciPlaces, int *iColNullable)
{
	if(SQL_SUCCEEDED(SQLDescribeCol(hSTMT, iCol, (SQLCHAR *)sOutName, (SQLSMALLINT)iSzOfOutName,
		(SQLSMALLINT *)iOutColNameLen, (SQLSMALLINT *)ioutDataType, (SQLUINTEGER *)iOutColSize,
		(SQLSMALLINT *)iNumOfDeciPlaces, (SQLSMALLINT *)iColNullable)))
	{
		return true;
	}
	else return false;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool CRecordSet::sColumnEx(const int iCol, char *sBuf, const int iBufSz, int *iOutLen)
{
	int iLen = 0;

	if(SQL_SUCCEEDED(SQLGetData(hSTMT, iCol, SQL_C_CHAR, sBuf, iBufSz, (SQLINTEGER *)&iLen)))
	{
		if(iLen > iBufSz)
		{
			iLen = iBufSz;
		}

		if(bReplaceSingleQuotes)
		{
			ReplaceSingleQuotes(sBuf, iLen);
		}

		if(bTrimCharData)
		{
			iLen = RTrim(sBuf, iLen);
		}

		if(iOutLen)
		{
			*iOutLen = iLen;
		}
		
		return true;
	}
	else {
		ThrowErrorIfSet();
		return false;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool CRecordSet::lColumnEx(const int iCol, long *plOutVal)
{
	long piOutBufSz = 0;

	if(SQL_SUCCEEDED(SQLGetData(hSTMT, iCol, SQL_C_LONG, plOutVal, sizeof(long), &piOutBufSz)))
	{
		return true;
	}
	else {
		ThrowErrorIfSet();
		return false;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

long CRecordSet::lColumn(const int iCol)
{
	long lTemp = 0;

	if(lColumnEx(iCol, &lTemp))
	{
	    return lTemp;
	}
	else return -1;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool CRecordSet::dColumnEx(const int iCol, double *pdOutVal)
{
	long piOutBufSz = 0;

	if(SQL_SUCCEEDED(SQLGetData(hSTMT, iCol, SQL_FLOAT, pdOutVal, sizeof(double), &piOutBufSz)))
	{
		return true;
	}
	else {
		ThrowErrorIfSet();
		return false;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

double CRecordSet::dColumn(const int iCol)
{
	double dTemp = 0;

	if(dColumnEx(iCol, &dTemp))
	{
	    return dTemp;
	}
	else return -1;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool CRecordSet::fColumnEx(const int iCol, float *pfOutVal)
{
	long piOutBufSz = 0;

	if(SQL_SUCCEEDED(SQLGetData(hSTMT, iCol, SQL_FLOAT, pfOutVal, sizeof(float), &piOutBufSz)))
	{
		return true;
	}
	else {
		ThrowErrorIfSet();
		return false;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

float CRecordSet::fColumn(const int iCol)
{
	float fTemp = 0;

	if(fColumnEx(iCol, &fTemp))
	{
	    return fTemp;
	}
	else return -1;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

CRecordSet::CRecordSet()
{
	hSTMT = NULL;
	RowCount = 0;
	ColCount = 0;

	bTrimCharData = true;
	bReplaceSingleQuotes = true;
	bThrowErrors = true;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

CRecordSet::~CRecordSet()
{
	hSTMT = NULL;
	RowCount = 0;
	ColCount = 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool CRecordSet::GetErrorMessage(char *sOutError, const int iErrBufSz)
{
	SQLCHAR     sSQLState[20];
	SQLINTEGER  iOutNativeErr;
	SQLSMALLINT iOutErrorMsgSz;
	return SQL_SUCCEEDED(SQLError(NULL, NULL, hSTMT, sSQLState, &iOutNativeErr, (SQLCHAR *)sOutError, iErrBufSz, &iOutErrorMsgSz));
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool CRecordSet::ThrowErrorIfSet(void)
{
	if(bThrowErrors == true)
	{
		return ThrowError();
	}

	return false;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool CRecordSet::ThrowError(void)
{
	char sErrorMsg[1024];

	if(GetErrorMessage(sErrorMsg, sizeof(sErrorMsg)))
	{
		MessageBox(GetActiveWindow(), sErrorMsg, "CRecordSet::Error", MB_ICONERROR);
		return true;
	}

	return false;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////