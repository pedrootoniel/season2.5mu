#pragma once

//----------------------------------------------------------------------------------------//
//struct
struct _BALANCE
{
	//----------- carregar configuração
	void iniciar_balance();
	void Main(LPOBJ lpObj, LPOBJ lpTargetObj, int & AttackDamage);
	//----------- variavel basica
	int balance[26];
};

//----------------------------------------------------------------------------------------//
//extern
extern _BALANCE _balance;


BOOL _gObjAttack(LPOBJ lpObj, LPOBJ lpTargetObj, void * lpMagic, BOOL magicsend, BYTE MSBFlag, int AttackDamage, BOOL bCombo);