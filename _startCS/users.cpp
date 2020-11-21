#include "stdafx.h"


OBJECTSTRUCT* gObj = ( OBJECTSTRUCT* ) ( OBJECT_BASE );

PLAYER_STRUCT  player_struct[MAX_PLAYERID];

//----------------------------------------------------------------------------------------//
//item convert [hot]
__declspec(naked) void CItem::Convert(int type, BYTE Option1, BYTE Option2, BYTE Option3,BYTE Attribute2, BYTE SetOption, BYTE ItemEffectEx, BYTE DbVersion)
{
    _asm
	{
		MOV EAX, 0x005217B0
		JMP EAX
	}
}