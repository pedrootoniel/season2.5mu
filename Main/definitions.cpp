#include "stdafx.h"

pProtocolCore                         ProtocoloCore                      =     (pProtocolCore)0x004FF790; //004FFE40 - 1.02.44
pTextureLoad                           TextureLoad                        =     (pTextureLoad)0x0067FFA3;
pTextureCall                           TextureCall                        =     (pTextureCall)0x0067FB27;
pSendChatText						   MU_SendChatText					  =     (pSendChatText)(0x0058DDE0);

void datasend(LPBYTE buf, int len)
{
	_asm
	{
		mov eax, len;
		push eax;
		mov ecx, buf;
		push ecx;
		mov ecx, dword ptr ds:[0x7A2854];
		mov edi,0x00403D10;
		call edi;
	}
}