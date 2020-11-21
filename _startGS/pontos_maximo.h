#pragma once

#include "stdafx.h"
#include "users.h"

//----------------------------------------------------------------------------------------//
//struct maximo de pontos
struct _MAXIMO_PONTOS
{
	short _classe;
	WORD  _forca;
	WORD _agilidade;
	WORD _vitalidade;
	WORD _energia;
	WORD _comando;
};

//----------------------------------------------------------------------------------------//
class _classe_maximo
{
public:
	//----------- arquivo de configuração
	void loadfile(char * file);

	//----------- variavel
	int variavel;

	//----------- struct _MAXIMO_PONTOS
	_MAXIMO_PONTOS pontos[255];

private:
	//----------- alteração na memoria
	void status();

	//----------- reload
	void _reload();
};

//----------------------------------------------------------------------------------------//
//extern
extern _classe_maximo _maximo;

//----------------------------------------------------------------------------------------//
//adicionar pontos
BOOL _gObjLevelUpPointAdd(BYTE type, LPOBJ lpObj);
void gObjGCLevelUpMsgSend(int aIndex, int iSendEffect);