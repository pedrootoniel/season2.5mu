#pragma once

#include "stdafx.h"
#include "users.h"

//----------------------------------------------------------------------------------------//
//struct
struct _DROP_BLOOD
{
	BYTE index[7];
	BYTE id[7];
	BYTE level[7];
	BYTE skill[7];
	BYTE luck[7];
	BYTE addopt[7];
	BYTE addoptex[7];
};

//----------------------------------------------------------------------------------------//
class _blood_castle
{
public:
	//----------- variavel
	int blood[7];
	//----------- struct
	_DROP_BLOOD drop[255];
	//----------- configurações
	void _iniciar_blood_castle(char * filename);
	//----------- funções
	void _blood_drop(LPOBJ lpObj, char vector);

private:
	void _reload();
};

//----------------------------------------------------------------------------------------//
//extern
extern _blood_castle _blood;

//----------------------------------------------------------------------------------------//
//hook original função
void _blood_castle_hook(int aIndex);