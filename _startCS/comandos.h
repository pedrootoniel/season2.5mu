#pragma once  

#include "stdafx.h"
#include "users.h"

//----------------------------------------------------------------------------------------//
//struct
struct _COMANDOS
{
	//----------- variaveis comandos
	char  string[50][255];
	char  ativar[30];
	short level[30];
	char  vip[30];
	int   money[30];
	char  gm[30];
	char  maxbau[6];
	//-----------
	char  corpost;
	//----------- variaveis gm system
	char  nome[11];
	BYTE  comando[20];
};

//----------------------------------------------------------------------------------------//
class _comandos
{
public:
	//----------- struct COMANDOS
	_COMANDOS _struct[255];

	//----------- token
	int variavelgamemaster;
	int variavelcustomove;
	char _bau;

	//----------- configuração dos comandos
	void _comandos_config();
	void _reload();
	void _comandos_gmsystem(char * filename);

	//----------- hook do protocolo
	void _comandos_protocolo(LPBYTE Protocolo, int aIndex);

	//----------- comando pkclear
	void _comando_pkclear(LPOBJ lpObj, char npc_or_comando, DWORD* NpcIndex);
private:
	//----------- comando post
	void _comando_post(LPOBJ lpObj, char * String);

	//----------- comando add
	void _comando_adicionar(LPOBJ lpObj, char * String, char switchs, char arrays);

	//----------- comando drop
	void _comando_drop(LPOBJ lpObj, char * String);

	//----------- comando skin
	void _comando_skin(LPOBJ lpObj, char * String);

	//----------- comando reload
	void _comando_reload(LPOBJ lpObj, char * String);

	//----------- comando move
	void _comando_move(LPOBJ lpObj, char * String);

	//----------- comando money
	void _comando_money(LPOBJ lpObj);

	//----------- comando limpar inventario
	void _comando_limpar(LPOBJ lpObj);

	//----------- comando bau
	void _comando_ware(LPOBJ lpObj, char * String);

	//----------- comando mudar de classe
	void _comando_classe(LPOBJ lpObj, char * String, char token, char classe);

	//----------- comando infor
	void _comando_infor(LPOBJ lpObj);

	//----------- comando offtrade
	void _comando_offtrade(LPOBJ lpObj);

	//----------- comando reset
	void _comando_reset(LPOBJ lpObj);
	
	//----------- comando auto reset
	void _comando_autoreset(LPOBJ lpObj);

	//----------- adicionar status
	bool _comando_status(LPOBJ lpObj, char switchs, int pontos);
	
	//----------- readd
	void _comando_readd(LPOBJ lpObj);

	//----------- gm system
	bool gamemaster(LPOBJ lpObj, BYTE tipo);

	//----------- openware
	void _comando_openware(LPOBJ lpObj);

	//----------- variaveis
	int  _pontos;
	BYTE _index;
	BYTE _id;
	BYTE _level;
	BYTE _skill;
	BYTE _luck;
	BYTE _addopt;
	BYTE _addoptex;
	char _quantidade;
	char _nome[11];
	char _query[100];
};

//----------------------------------------------------------------------------------------//
//extern
extern _comandos _iniciar_comandos;

//----------------------------------------------------------------------------------------//
//thread para mudar de bau
void WINAPI mudarbau(int aIndex);