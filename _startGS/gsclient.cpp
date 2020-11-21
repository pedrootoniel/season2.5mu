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
	LogAddFuncColor(3,"packet enviado: nome: %s, %d pontos",player->Name,this->p.points);
}

void GSClient::GSCalChart(LPOBJ player)
{
	PHeadSubSetBE((LPBYTE)&this->c, 0xFF, 4, sizeof(this->c));

	this->c.elf1   = GetPrivateProfileInt("calcharacter","config_41", 0, ".\\configurações\\_player.settings\\_settings.calcharacter.ID");
	this->c.elf2   = GetPrivateProfileInt("calcharacter","config_42", 0, ".\\configurações\\_player.settings\\_settings.calcharacter.ID");
	this->c.bkmg1  = GetPrivateProfileInt("calcharacter","config_43", 0, ".\\configurações\\_player.settings\\_settings.calcharacter.ID");
	this->c.bkmg2  = GetPrivateProfileInt("calcharacter","config_44", 0, ".\\configurações\\_player.settings\\_settings.calcharacter.ID");
	this->c.dl1    = GetPrivateProfileInt("calcharacter","config_45", 0, ".\\configurações\\_player.settings\\_settings.calcharacter.ID");
	this->c.dl2    = GetPrivateProfileInt("calcharacter","config_46", 0, ".\\configurações\\_player.settings\\_settings.calcharacter.ID");
	this->c.sm1    = GetPrivateProfileInt("calcharacter","config_47", 0, ".\\configurações\\_player.settings\\_settings.calcharacter.ID");
	this->c.sm2    = GetPrivateProfileInt("calcharacter","config_48", 0, ".\\configurações\\_player.settings\\_settings.calcharacter.ID");

	DataSend(player->m_Index,(unsigned char *)&this->c,this->c.h.size);
	LogAddFuncColor(3,"packet enviado: nome: %s, calcharacter speed",player->Name);
}

void GSClient::GSMixLevel(LPOBJ player)
{
	PHeadSubSetBE((LPBYTE)&this->g, 0xFF, 3, sizeof(this->g));

	this->g.mix10     = iniciar_dll.iniciar_mixitem0;
	this->g.mix10luck = iniciar_dll.iniciar_mixitem1;
	this->g.mix11     = iniciar_dll.iniciar_mixitem2;
	this->g.mix11luck = iniciar_dll.iniciar_mixitem3;
	this->g.mix12     = iniciar_dll.iniciar_mixitem4;
	this->g.mix12luck = iniciar_dll.iniciar_mixitem5;
	this->g.mix13     = iniciar_dll.iniciar_mixitem6;
	this->g.mix13luck = iniciar_dll.iniciar_mixitem7;

	this->g.fenrir1   = *(DWORD*)0x9F47D3C;
	this->g.fenrir2   = *(DWORD*)0x9F47D38;
	this->g.fenrir3   = *(DWORD*)0x9F47D34;


	DataSend(player->m_Index,(unsigned char *)&this->g,this->g.h.size);
	LogAddFuncColor(3,"packet enviado: nome: %s, vip: %d - globin level mix",player->Name,player->vip);
}

