#include "stdafx.h"

#ifdef ENG
char type[20]	= "1.00.18";
char ini[]		= ".\\configurações\\_settings.ID";
#endif

#ifdef PHI
char type[20]	= "1.00.18";
char ini[]		= ".\\configurações\\_settings.ID";
#endif

bool GameServer2(char* ini)
{
	char tmp[500];
	DWORD *offset = (DWORD*)(0x0073884C);
	sprintf_s (tmp,type);
	memset(&offset[0],0,18);
	memcpy(&offset[0],tmp,strlen(tmp));
	return 1;
}

bool IniciaIni()
{
	bool rResultado;
	rResultado = GameServer2 (ini);
	return 1;
}