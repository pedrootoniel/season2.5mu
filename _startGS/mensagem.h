#pragma once

#include "stdafx.h"

//----------------------------------------------------------------------------------------//
//struct
struct _MENSAGEM_ALL
{
	//----------- variaveis
	BYTE  _posicao;
	char  _mensagem[255];
	short _tipo;

	//----------- variavel principal
	int v;

	//----------- arquivo de configuração
	void _mensagem_load(char * filename);

	//----------- reload
	void _reload();
};

//----------------------------------------------------------------------------------------//
//extern
extern _MENSAGEM_ALL _mensagem_all[255];
void _mensagem(int aIndex, unsigned char numero,int _default, DWORD * NpcIndex, char _npc_player);
void message(int index, int numero, int x);