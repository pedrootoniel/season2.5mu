#pragma once

#include "stdafx.h"

struct PBMSG_HEAD	
{
public:
	void set(LPBYTE lpBuf, BYTE head, BYTE size)	
	{
		lpBuf[0] = 0xC1;
		lpBuf[1] = size;
		lpBuf[2] = head;
	};	

	void setE(LPBYTE lpBuf, BYTE head, BYTE size)	
	{
		lpBuf[0] = 0xC3;
		lpBuf[1] = size;
		lpBuf[2] = head;
	};	

	BYTE c;
	BYTE size;
	BYTE headcode;
};

struct PMSG_DEFAULT2
{
	PBMSG_HEAD h;
	BYTE subcode;
};

struct PLAYER_POINTS
{
	PBMSG_HEAD h;
	int points;
};

struct PLAYER_STATUS
{
	PBMSG_HEAD h;
	WORD  forca;
	WORD  agilidade;
	WORD  vitalidade;
	WORD  energia;
	WORD  comando;
};

struct PLAYER_RESET
{
	PBMSG_HEAD h;
	WORD  forca;
	WORD  agilidade;
	WORD  vitalidade;
	WORD  energia;
	WORD  comando;
	int   points;
	DWORD exp;
	DWORD nextexp;
	short level;
};

struct GLOBIN_MIX
{
	PBMSG_HEAD h;
	int mix10;
	int mix11;
	int mix12;
	int mix13;
	int mix10luck;
	int mix11luck;
	int mix12luck;
	int mix13luck;
	int fenrir1;
	int fenrir2;
	int fenrir3;
};

struct CALCHARACTER
{
	PBMSG_HEAD h;
	int elf1;
	int elf2;
	int bkmg1;
	int bkmg2;
	int dl1;
	int dl2;
	int sm1;
	int sm2;
};

struct MAIN
{
	PBMSG_HEAD h;
	int skillsiege;
	int reflete;
};

struct PMSG_NAME
{
	PBMSG_HEAD h;
	char name[11];
};

struct SEND_GAMESERVER
{
	PBMSG_HEAD h;
};

struct PMSG_CHARINFOMAIN
{
	PBMSG_HEAD h;
	BYTE Code;
	BYTE Class;
	WORD Dexterity;
	WORD AttackSpeed;
	WORD MagicSpeed;
};

struct ObjPlayer
{
	BYTE Class;
	WORD Dexterity;
	WORD AttackSpeed;
	WORD MagicSpeed;
};

extern ObjPlayer Player;

enum ChatColor
{
	Blue		= 0x01,
	Red			= 0x02,
	Chocolate	= 0x0A,
	Gold		= 0x09,
	Green		= 0x0B,
};

struct PWMSG_HEAD
{
	BYTE c;
	BYTE sizeH;
	BYTE sizeL;
	BYTE headcode;
};

struct PMSG_HEALTHBAR
{
	PWMSG_HEAD h; 
	BYTE Code;
	BYTE Count;
};

struct PMSG_HEALTHBAR_INFO
{
	short Index;
	BYTE Rate;
};