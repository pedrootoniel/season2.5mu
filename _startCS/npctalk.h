#pragma once

#include "stdafx.h"
#include "users.h"

//----------------------------------------------------------------------------------------//
//struct npc
struct _NPC_TALK
{
	WORD classe;
	signed char mapa;
	WORD x;
	WORD y;
	signed char tipo;
};

//----------------------------------------------------------------------------------------//
class _npc_talking
{
public:
	//----------- arquivo de configuração
	void loadfile(char * file);

	//----------- variavel
	int v;

	//----------- struct
	_NPC_TALK npc[255];

private:
	//----------- reload
	void _reload();
};

//----------------------------------------------------------------------------------------//
//extern
extern _npc_talking _npc;

//----------------------------------------------------------------------------------------//
//hook
BOOL _NpcTalk(LPOBJ lpNpc, LPOBJ lpObj);