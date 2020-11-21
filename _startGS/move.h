#pragma once

#include "stdafx.h"

struct moveS
{
	//
	char  string[255];
	char  vip;
	char  pk;
	short level;
	short map;
	short cordx;
	short cordy;
	//
	int   count;
	//
	void  load();
};

struct commandS
{
	//variaveis
	char string[255][255];
	int  active[40];
	int  level[40];
	int  zen[40];
	int  vip[40];
	int  resets[40];
	int  temp[40];
	int  maxbau[4];

	//comandos
	void ChatPost(char * string, LPOBJ lpObj);
	void ChatAdd(char * string, LPOBJ lpObj, BYTE select);
	void ChatPKClear(LPOBJ lpObj);
	void ChatWare(char * string, LPOBJ lpObj);
	void ChatClass(LPOBJ lpObj, char index, char type);

	//comandos GM
	void ChatDrop(char * string, LPOBJ lpObj);
	void ChatSkin(char * string, LPOBJ lpObj);
	void ChatMove(char * string, LPOBJ lpObj);
	void ChatRelo(char * string, LPOBJ lpObj);

	//protocolo
	void ChatProto(LPBYTE aRecv, int aIndex);
public:
	//configurações
	void load();

	//move
	moveS movesarray[255];
	moveS moves;
	void  movestart(LPOBJ lpObj, char vip, char pk, short level, short map, short x, short y);
};

extern commandS cmds;