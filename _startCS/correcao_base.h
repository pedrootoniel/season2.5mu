#include "stdafx.h"
#include "users.h"

//----------- fun��o nopear
void iniciar_nopear(DWORD off, int quantidade);
//----------- corre��es do servidor
void iniciar_correcoes();
//----------- bal�o de GM
BOOL _gObjSetCharacter(LPBYTE lpdata, int aIndex);
//----------- mix chaos card
void _LotteryItemMix(OBJECTSTRUCT* lpObj);

//----------- Skill sem Sword
void FixSkillsNoWeapor(LPBYTE aRecv, int aIndex);

//----------- altera��es na memoria : configura��es
void iniciar_configuracoes();

void StartAddress(LPVOID lpThreadParameter);