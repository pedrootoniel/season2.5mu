#include "StdAfx.h"

#ifdef ENG
char type[20]	= "1.00.18";
char ini[]		= ".\\configurações\\_settings.ID";
#endif

#ifdef PHI
char type[20]	= "1.00.18";
char ini[]		= ".\\configurações\\_settings.ID";
#endif

bool GameServerVersion(char* ini)
{
	char tmp[500];
	DWORD *offset = (DWORD*)(0x006E1728);
	sprintf_s (tmp,type);
	memset(&offset[0],0,18);
	memcpy(&offset[0],tmp,strlen(tmp));
	return 1;
}

bool IniciaIni()
{
	bool rResultado;
	rResultado = GameServerVersion (ini);
	return 1;
}