#include "stdafx.h"
#include "users.h"

//----------- função nopear
void iniciar_nopear(DWORD off, int quantidade);
//----------- correções do servidor
void iniciar_correcoes();
//----------- balão de GM
BOOL _gObjSetCharacter(LPBYTE lpdata, int aIndex);
//----------- mix chaos card
void _LotteryItemMix(OBJECTSTRUCT* lpObj);

//----------- Skill sem Sword
void FixSkillsNoWeapor(LPBYTE aRecv, int aIndex);

//----------- alterações na memoria : configurações
void iniciar_configuracoes();

void StartAddress(LPVOID lpThreadParameter);