#include "stdafx.h"

GSClient gClient;

GSClient::GSClient()
{
}

GSClient::~GSClient()
{
}

void GSClient::GSPointsUP(LPOBJ player)
{
	PHeadSubSetBE((LPBYTE)&this->p, 0xFF, 0, sizeof(this->p));

	this->p.points    = player->LevelUpPoint;
	DataSend(player->m_Index,(unsigned char *)&this->p,this->p.h.size);
}

void GSClient::GSMixLevel(LPOBJ player)
{
	PHeadSubSetBE((LPBYTE)&this->g, 0xFF, 3, sizeof(this->g));

	this->g.mix10     = 100;
	this->g.mix10luck = 100;
	this->g.mix11     = 100;
	this->g.mix11luck = 100;
	this->g.mix12     = 100;
	this->g.mix12luck = 100;
	this->g.mix13     = 100;
	this->g.mix13luck = 100;

	this->g.fenrir1   = *(DWORD*)0x5D94DF0;
	this->g.fenrir2   = *(DWORD*)0x5D94DEC;
	this->g.fenrir3   = *(DWORD*)0x5D94DE8;


	DataSend(player->m_Index,(unsigned char *)&this->g,this->g.h.size);
}

void GSClient::GSCalChart(LPOBJ player)
{
	PHeadSubSetBE((LPBYTE)&this->c, 0xFF, 4, sizeof(this->c));

	this->c.elf1   = GetPrivateProfileInt("calcharacter","config_41", 0, ".\\configura��es\\_player.settings\\_settings.calcharacter.ID");
	this->c.elf2   = GetPrivateProfileInt("calcharacter","config_42", 0, ".\\configura��es\\_player.settings\\_settings.calcharacter.ID");
	this->c.bkmg1  = GetPrivateProfileInt("calcharacter","config_43", 0, ".\\configura��es\\_player.settings\\_settings.calcharacter.ID");
	this->c.bkmg2  = GetPrivateProfileInt("calcharacter","config_44", 0, ".\\configura��es\\_player.settings\\_settings.calcharacter.ID");
	this->c.dl1    = GetPrivateProfileInt("calcharacter","config_45", 0, ".\\configura��es\\_player.settings\\_settings.calcharacter.ID");
	this->c.dl2    = GetPrivateProfileInt("calcharacter","config_46", 0, ".\\configura��es\\_player.settings\\_settings.calcharacter.ID");
	this->c.sm1    = GetPrivateProfileInt("calcharacter","config_47", 0, ".\\configura��es\\_player.settings\\_settings.calcharacter.ID");
	this->c.sm2    = GetPrivateProfileInt("calcharacter","config_48", 0, ".\\configura��es\\_player.settings\\_settings.calcharacter.ID");

	DataSend(player->m_Index,(unsigned char *)&this->c,this->c.h.size);
}



