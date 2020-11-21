#include "stdafx.h"
#include "users.h"
#include "packets.h"

//----------------------------------------------------------------------------------------//
//protocolo
void _ProtocolCore(BYTE protoNum, unsigned char * aRecv, int aLen, int aIndex, BOOL Encrypt, int serial);
bool DataSend_Hook(int aIndex, PBYTE tpProtocol, DWORD ProtocolLen);
void gObjPlayerDataLoad(PMSG_CHARMAPJOIN * lpRecv, int index);
void gObjPlayerLoad(int aIndex);
//----------------------------------------------------------------------------------------//
//conectar no jogo
void LimiteUser(LPOBJ lpObj);
void _ConnectGame(LPOBJ lpObj);

//----------------------------------------------------------------------------------------//
//relacionado a novas joias
void UseItemRecv(PMSG_USEITEM* lpMsg,int aIndex);
void deleteRecv(int aIndex, char slot, char target);