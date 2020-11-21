#pragma once

#include "stdafx.h"

//----------------------------------------------------------------------------------------//
//struct drop
struct _DROPS_CUSTOM
{
	BYTE index;
	BYTE id;
	BYTE level;
	BYTE skill;
	BYTE luck;
	BYTE addopt;
	BYTE addoptex;
	short mapa;
	short monstro;
	short porcentagem;
	short minlevel;
	short maxlevel;
};

//----------------------------------------------------------------------------------------//
class _drop_custom
{
public:
	//----------- arquivo de configuração
	void  _drop_custom_load(char * filename);
	//----------- custom drop
	BOOL  _drop_init(LPOBJ lpObj, LPOBJ lpTargetObj);

	//----------- struct
	_DROPS_CUSTOM drop_struct[255];

	//----------- variavel
	int v;

private:
	void _reload();
};

//----------------------------------------------------------------------------------------//
//extern
extern _drop_custom _drop;
//----------------------------------------------------------------------------------------//
//função de hook
BOOL _gObjMonsterDrop(LPOBJ lpObj, LPOBJ lpTargetObj);