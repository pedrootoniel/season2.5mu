#include "stdafx.h"
#include "packets.h"

void ProtocolCore(DWORD protoNum, LPBYTE lpRecv, int Len, int aIndex);

void ProtocolLoad();

void gObjPoints(PLAYER_POINTS * p);
void gObjMix(GLOBIN_MIX * p);
void gObjCalCharacter(CALCHARACTER * p);
void ApplyDexterityFix();