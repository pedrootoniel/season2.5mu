#pragma once

#include "stdafx.h"

struct OBJECTSTRUCT
{
	char	Name[11];        //ok
	BYTE	Class;           //ok
	BYTE	Unknown12;       //value 0
	BYTE	Unknown13;       //value 0
	short	Level;           //ok
	DWORD	Experience;      //ok
	DWORD	NextExp;         //ok
	WORD	Strength;        //ok
	WORD	Dexterity;       //ok
	WORD	Vitality;        //ok
	WORD	Energy;          //ok
	WORD	Leadership;      //ok
	WORD	Life;            //ok
	WORD	Mana;            //ok
	WORD	MaxLife;         //ok
	WORD	MaxMana;         //ok
	WORD    unk;             //
};