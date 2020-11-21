#include "StdAfx.h"

CEffectManager gEffectManager;

void CEffectManager::Load()
{
	CMemScript* lpMemScript = new CMemScript;

	if(lpMemScript == 0)
	{
		printf(MEM_SCRIPT_ALLOC_ERROR, CONFIG_EFFECT_FILE);
		return;
	}

	if(lpMemScript->SetBuffer(CONFIG_EFFECT_FILE) == 0)
	{
		printf(lpMemScript->GetLastError());
		delete lpMemScript;
		return;
	}

	int Type,Index;

	try
	{
		while(true)
		{
			if(lpMemScript->GetToken() == TOKEN_END)
			{
				break;
			}

			if(strcmp("end",lpMemScript->GetString()) == 0)
			{
				break;
			}

			Type = lpMemScript->GetNumber();

			Index = lpMemScript->GetAsNumber();

			this->m_EffectInfo[this->Count].ItemIndex = GET_ITEM_MODEL(Type,Index);

			this->m_EffectInfo[this->Count].EffectDynamicIndex = lpMemScript->GetAsNumber();

			this->m_EffectInfo[this->Count].EffectDynamicSize = lpMemScript->GetAsFloatNumber();

			this->m_EffectInfo[this->Count].EffectStaticIndex = lpMemScript->GetAsNumber();

			this->m_EffectInfo[this->Count].EffectStaticSize = lpMemScript->GetAsFloatNumber();

			this->m_EffectInfo[this->Count].EffectBone = lpMemScript->GetAsNumber();

			this->m_EffectInfo[this->Count].Color[0] = lpMemScript->GetAsFloatNumber();

			this->m_EffectInfo[this->Count].Color[1] = lpMemScript->GetAsFloatNumber();

			this->m_EffectInfo[this->Count].Color[2] = lpMemScript->GetAsFloatNumber();

			this->Count++;
		}
	}
	catch(...)
	{
		printf(lpMemScript->GetLastError());
	}

	delete lpMemScript;

	if(this->Count)
	{
		SetOp((LPVOID)(0x0052581F),this->DrawItemEffect,ASM::CALL);// ok
		SetOp((LPVOID)(0x0067D478),this->DrawItemEffect,ASM::CALL);// ok


	}
}

void CEffectManager::DrawItemEffect(int lpModel, int ItemModel, int a3, GLfloat alpha, int a5, int a6, int a7, int a8, int a9)
{
	for(int i = 0; i <= gEffectManager.Count; i++)
	{
		EFFECT_INFO* lpInfo = &gEffectManager.m_EffectInfo[i];

		if(ItemModel == lpInfo->ItemIndex)
		{
			vec3_t Bone;
			float Unknow = 0;

			DWORD Model = 240 * ItemModel + *(DWORD*)0x5848440; //OK

			DWORD* ItemTransform = (DWORD*)(0x6990184);

			pPlayStaticEffect(Model, lpInfo->EffectStaticIndex, lpInfo->EffectBone, 0x40000000, lpInfo->Color, lpModel);
		}
	}

	pDrawItemEffect(lpModel, ItemModel, a3, alpha, a5, a6, a7, a8, a9);
}

