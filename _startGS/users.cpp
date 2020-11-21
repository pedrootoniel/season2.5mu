#include "stdafx.h"

OBJECTSTRUCT* gObj = ( OBJECTSTRUCT* ) ( OBJECT_BASE );

OFFLINETRADELOGIN	OfflineLogin[OBJECT_MAX];

__declspec(naked) void CItem::Convert(int type, BYTE Option1, BYTE Option2, BYTE Option3,BYTE Attribute2, BYTE SetOption, BYTE ItemEffectEx, BYTE DbVersion)
{
    _asm
	{
		MOV EAX, 0x0050E390
		JMP EAX
	}
}

int CItem::IsFenrirIncLastAttackDamage()
{
	if ( this->m_Durability < 1.0f )
	{
		return 0;
	}

	if ( (this->m_NewOption&1) == 1 )
	{
		return 10;
	}

	return 0;
}

int CItem::IsFenrirDecLastAttackDamage()
{
	if ( this->m_Durability < 1.0f )
	{
		return 0;
	}

	if ( (this->m_NewOption&2) == 2 )
	{
		return 10;
	}

	return 0;
}

int CItem::IsFenrirSpecial()
{
	if ( this->m_Durability < 1.0f )
	{
		return 0;
	}

	if ( (this->m_NewOption&4) == 4 )
	{
		return 1;
	}

	return 0;
}