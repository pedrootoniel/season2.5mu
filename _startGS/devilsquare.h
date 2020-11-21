#pragma once

#include "stdafx.h"
#include "users.h"

//----------------------------------------------------------------------------------------//
//struct
struct _DROP_DEVIL
{
	BYTE index[6];
	BYTE id[6];
	BYTE level[6];
	BYTE skill[6];
	BYTE luck[6];
	BYTE addopt[6];
	BYTE addoptex[6];
};

//----------------------------------------------------------------------------------------//
class _devil_square
{
public:
	//----------- variavel
	int devil[6];
	//----------- struct
	_DROP_DEVIL drop[255];
	//----------- configura��es
	void _iniciar_devil_square(char * filename);
	//----------- fun��es
	void _devil_drop(LPOBJ lpObj, char vector);

private:
	void _reload();
};

//----------------------------------------------------------------------------------------//
//extern
extern _devil_square _devil;

//----------------------------------------------------------------------------------------//
//original fun��o
void _devil_square_original(LPOBJ lpObj);
//----------------------------------------------------------------------------------------//
//hook da fun��o em assembly
__declspec() void _devil_square_hook();