#pragma once

#include "stdafx.h"
#include "crecord.h"

#define MAXSQLBUFLEN  255

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class CSQL{

	public:
		bool Connect(char *sServer);
		bool GetErrorMessage(char *sOutError, const int iErrBufSz, HSTMT hStmt);
		bool ThrowErrorIfSet(HSTMT hStmt);
		bool ThrowError(HSTMT hStmt);
		void Disconnect(void);
		bool ExecuteNonQuery(const char *sSQL);
		bool Execute(const char *sSQL, CRecordSet *lpMyRS);
		int  GetInt();

        CSQL();
        virtual ~CSQL();

		bool bThrowErrors;

    private:
        HENV hSQLEnvironment;
        HDBC hSQLConnection;
        bool bConnected;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
extern CSQL _iniciar_csql;

int SQLSyntaxCheckConvert(char* SQLString);