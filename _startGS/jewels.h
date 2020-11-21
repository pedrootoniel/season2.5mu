#pragma once


//----------------------------------------------------------------------------------------//
//relacionado a novas joias
int	MyRand(int min, int max);
void UseItemRecv(PMSG_USEITEM* lpMsg,int aIndex);
void deleteRecv(int aIndex, char slot, char target);