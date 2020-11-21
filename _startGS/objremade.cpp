#include "stdafx.h"

void ratemixlevel(int pos, LPOBJ lpObj)
{
	if(lpObj->pChaosBox[pos].m_Level == 9)
	{
		lpObj->ChaosSuccessRate = iniciar_dll.iniciar_mixitem0;

	    if(lpObj->pChaosBox[pos].m_Option2 == 1)
	    {
	  	    lpObj->ChaosSuccessRate += iniciar_dll.iniciar_mixitem1;
	    }
	}
	if(lpObj->pChaosBox[pos].m_Level == 10)
	{
		lpObj->ChaosSuccessRate = iniciar_dll.iniciar_mixitem2;

	    if(lpObj->pChaosBox[pos].m_Option2 == 1)
	    {
	  	    lpObj->ChaosSuccessRate += iniciar_dll.iniciar_mixitem3;
	    }
	}
	if(lpObj->pChaosBox[pos].m_Level == 11)
	{
		lpObj->ChaosSuccessRate = iniciar_dll.iniciar_mixitem4;

	    if(lpObj->pChaosBox[pos].m_Option2 == 1)
	    {
	  	    lpObj->ChaosSuccessRate += iniciar_dll.iniciar_mixitem5;
	    }
	}
	if(lpObj->pChaosBox[pos].m_Level == 12)
	{
		lpObj->ChaosSuccessRate = iniciar_dll.iniciar_mixitem6;

	    if(lpObj->pChaosBox[pos].m_Option2 == 1)
	    {
	  	    lpObj->ChaosSuccessRate += iniciar_dll.iniciar_mixitem7;
	    }
	}
}

__declspec(naked) void gObjRateMixLevel()
{
	_asm
	{
	mov edx, dword ptr ss:[ebp+8]
	push edx
    mov ecx, dword ptr ss:[ebp-0x18]
	push ecx
	call ratemixlevel
	mov edi, 0x004966FB
	jmp edi
	}
}
