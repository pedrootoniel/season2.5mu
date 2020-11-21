#pragma once

#include "stdafx.h"
#include "users.h"

//----------------------------------------------------------------------------------------//
//struct reset
struct _RESET_CHECK
{
	//----------- primeira parte basica
	char _ativar[6];
	char _tipo[6];
	BYTE _mover[6];
	BYTE _comando[6];
	//----------- segunda parte
	char  _vip;
	int   _min_reset;
	int   _max_reset;
	short _level;
	int   _money;
	char  _remover;
	short _retornar_level;
	int   _pontos;
};

class _reset_classe
{
public:
	//----------- struct
	_RESET_CHECK _r_struct[255];
	//----------- configurações
	void _reset_config_simples();
	void _reset_loadfile(char * filename);
	//----------- funções
	void _reset_init(LPOBJ lpObj, DWORD* NpcIndex, char _tp);
	void _reset_pontuativo(LPOBJ, DWORD* NpcIndex, char _tp, BYTE vip);
	bool _reset_remove(LPOBJ);
	void _move(LPOBJ lpObj, BYTE vip);
	void _reset_calc(LPOBJ lpObj);

	int v;

private:
	//----------- reload
	void _reload();
};

//----------------------------------------------------------------------------------------//
//extern
extern _reset_classe _reset_iniciar;