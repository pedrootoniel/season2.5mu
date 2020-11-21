#include "stdafx.h"
#include "users.h"
#include "packets.h"

//----------------------------------------------------------------------------------------//
//protocolo
void _ProtocolCore(BYTE protoNum, unsigned char * aRecv, int aLen, int aIndex, BOOL Encrypt, int serial);
bool DataSend_Hook(int aIndex, PBYTE tpProtocol,DWORD ProtocolLen);


//----------------------------------------------------------------------------------------//
//conectar no jogo
void _ConnectGame(LPOBJ lpObj);
void gObjPlayerDataLoad(PMSG_CHARMAPJOIN * lpRecv, int index);
void gObjPlayerLoad(int index);
