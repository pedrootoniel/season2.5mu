#include "stdafx.h"


int	MyRand(int min, int max)
{
	if(min == max) 
		return min;

	int rnd = rand();
	int r = min + rnd / (RAND_MAX / (max - min) + 1);

	return r;
}

void UseItemRecv(PMSG_USEITEM* lpMsg,int aIndex)
{	
	OBJECTSTRUCT *lpObj = (OBJECTSTRUCT*)GS_GOBJPOINTER(aIndex);

	CItem* DTitem = &lpObj->pInventory[lpMsg->inventoryPos];
	CItem* DTadd  = &lpObj->pInventory[lpMsg->invenrotyTarget];

	int option    = MyRand(1,20);	

	if(DTitem->m_Type == ITEMGET(14,JEWEL01)) //Jewel Excellente
	{	
		if(DTadd->m_NewOption >= 1 || DTadd->m_SetOption > 0)
		{
			_mensagem(lpObj->m_Index,77,0,0,0);
			return;
		}

		if(rand()%100 <= iniciar_dll.jewel_up01)
		{
			DTadd->m_NewOption = option;
			deleteRecv(aIndex,lpMsg->inventoryPos,lpMsg->invenrotyTarget);
			MsgOutput(lpObj->m_Index,"%s Que Sorte Obteve sucesso no seu Up!",lpObj->Name);
		}
		else
		{
			MsgOutput(lpObj->m_Index,"%s Que pena seu Up falhou!",lpObj->Name);
			deleteRecv(aIndex,lpMsg->inventoryPos,lpMsg->invenrotyTarget);
		}
	}

	if(DTitem->m_Type == ITEMGET(14,JEWEL02)) //Jewel Level + 13
	{	
		if(DTadd->m_Level >= 13)
		{
			_mensagem(lpObj->m_Index,78,0,0,0);
			return;
		}

		if(rand()%100 <= iniciar_dll.jewel_up02)
		{
			DTadd->m_Level = 13;
			deleteRecv(aIndex,lpMsg->inventoryPos,lpMsg->invenrotyTarget);
			MsgOutput(lpObj->m_Index,"%s Que Sorte Obteve sucesso no seu Up!",lpObj->Name);
		}
		else
		{
			MsgOutput(lpObj->m_Index,"%s Que pena seu Up falhou!",lpObj->Name);
			deleteRecv(aIndex,lpMsg->inventoryPos,lpMsg->invenrotyTarget);
		}


	}

	if(DTitem->m_Type == ITEMGET(14,JEWEL03)) //Jewel Anciet
	{	
		if(DTadd->m_SetOption >= 3)
		{
			_mensagem(lpObj->m_Index,79,0,0,0);
			return;
		}

		if(rand()%100 <= iniciar_dll.jewel_up03)
		{
			for(int x = 1; x < 6; x++)
			{
				DTadd->m_SetOption = x;
			}
			deleteRecv(aIndex,lpMsg->inventoryPos,lpMsg->invenrotyTarget);
			MsgOutput(lpObj->m_Index,"%s Que Sorte Obteve sucesso no seu Up!",lpObj->Name);
		}
		else
		{
			MsgOutput(lpObj->m_Index,"%s Que pena seu Up falhou!",lpObj->Name);
			deleteRecv(aIndex,lpMsg->inventoryPos,lpMsg->invenrotyTarget);
		}
	}

	if(DTitem->m_Type == ITEMGET(14,JEWEL04)) //Jewel Luck
	{	
		if(DTadd->m_Option2 == 1)
		{
			_mensagem(lpObj->m_Index,80,0,0,0);
			return;
		}
		if(rand()%100 <= iniciar_dll.jewel_up04)
		{
			DTadd->m_Option2 = 1;
			deleteRecv(aIndex,lpMsg->inventoryPos,lpMsg->invenrotyTarget);
			MsgOutput(lpObj->m_Index,"%s Que Sorte Obteve sucesso no seu Up!",lpObj->Name);
		}
		else
		{
			MsgOutput(lpObj->m_Index,"%s Que pena seu Up falhou!",lpObj->Name);
			deleteRecv(aIndex,lpMsg->inventoryPos,lpMsg->invenrotyTarget);
		}
	}

	if(DTitem->m_Type == ITEMGET(14,JEWEL05)) //Jewel Skill
	{	
		if(DTadd->m_Option1 == 1)
		{
			_mensagem(lpObj->m_Index,81,0,0,0);
			return;
		}

		if(rand()%100 <= iniciar_dll.jewel_up05)
		{
			DTadd->m_Option1 = 1;
			deleteRecv(aIndex,lpMsg->inventoryPos,lpMsg->invenrotyTarget);
			MsgOutput(lpObj->m_Index,"%s Que Sorte Obteve sucesso no seu Up!",lpObj->Name);
		}
		else
		{
			MsgOutput(lpObj->m_Index,"%s Que pena seu Up falhou!",lpObj->Name);
			deleteRecv(aIndex,lpMsg->inventoryPos,lpMsg->invenrotyTarget);
		}
	}

	if(DTitem->m_Type == ITEMGET(14,JEWEL06)) //Jewel Option life
	{	
		if(DTadd->m_Option3 >= 4)
		{
			_mensagem(lpObj->m_Index,82,0,0,0);
			return;
		}
		if(rand()%100 <= iniciar_dll.jewel_up06)
		{
			DTadd->m_Option3 = 4;
			deleteRecv(aIndex,lpMsg->inventoryPos,lpMsg->invenrotyTarget);
			MsgOutput(lpObj->m_Index,"%s Que Sorte Obteve sucesso no seu Up!",lpObj->Name);
		}
		else
		{
			MsgOutput(lpObj->m_Index,"%s Que pena seu Up falhou!",lpObj->Name);
			deleteRecv(aIndex,lpMsg->inventoryPos,lpMsg->invenrotyTarget);
		}
	}

	if(DTitem->m_Type == ITEMGET(14,JEWEL07)) //Jewel +14 e +15
	{	
		if(DTadd->m_Level <= 12)
		{
			_mensagem(lpObj->m_Index,87,0,0,0);
			return;
		}
		if(DTadd->m_Level == 15)
		{
			_mensagem(lpObj->m_Index,83,0,0,0);
			return;
		}
		if(rand()%100 <= iniciar_dll.jewel_up07)
		{
			DTadd->m_Level += 1;
			deleteRecv(aIndex,lpMsg->inventoryPos,lpMsg->invenrotyTarget);
			MsgOutput(lpObj->m_Index,"%s Que Sorte Obteve sucesso no seu Up!",lpObj->Name);
		}
		else
		{
			MsgOutput(lpObj->m_Index,"%s Que pena seu Up falhou!",lpObj->Name);
			deleteRecv(aIndex,lpMsg->inventoryPos,lpMsg->invenrotyTarget);
		}
	}

	if(DTitem->m_Type == ITEMGET(14,JEWEL08)) //Jewel Remove Harmony
	{	
		DTadd->m_JewelOfHarmonyOption = 0;
		deleteRecv(aIndex,lpMsg->inventoryPos,lpMsg->invenrotyTarget);
	}

	if(DTitem->m_Type == ITEMGET(14,JEWEL09)) //Jewel Remove Anciet
	{	
		DTadd->m_SetOption = 0;
		deleteRecv(aIndex,lpMsg->inventoryPos,lpMsg->invenrotyTarget);
	}

	if(DTitem->m_Type == ITEMGET(14,JEWEL10)) //Jewel cash
	{	
		_mensagem(lpObj->m_Index,88,0,0,0);
		_subC.subCSQL_retornar(lpObj->AccountID,_subC._query_cash,_subC.subCSQLtabela,_subC.subCSQLcoluna_id,0,"+");
		deleteRecv(aIndex,lpMsg->inventoryPos,lpMsg->invenrotyTarget);
	}

	if(DTitem->m_Type == ITEMGET(14,JEWEL11)) //Jewel gold
	{	
		_mensagem(lpObj->m_Index,89,0,0,0);
		_subC.subCSQL_retornar(lpObj->AccountID,_subC._query_gold,_subC.subCSQLtabela,_subC.subCSQLcoluna_id,0,"+");
		deleteRecv(aIndex,lpMsg->inventoryPos,lpMsg->invenrotyTarget);
	}

	if(DTitem->m_Type == ITEMGET(14,JEWEL12)) //Jewel reset
	{	
		_mensagem(lpObj->m_Index,90,0,0,0);
		_subC.subCSQL_retornar(lpObj->Name,_subC._query_reset,_subC.subCSQLtabela_r,_subC.subCSQLcoluna_id_r,0,"+");
		deleteRecv(aIndex,lpMsg->inventoryPos,lpMsg->invenrotyTarget);
	}

	if(DTitem->m_Type == ITEMGET(14,JEWEL13)) //Jewel Return
	{	
		if(DTadd->m_Level <= 13)
		{
			_mensagem(lpObj->m_Index,91,0,0,0);
			return;
		}
		if(rand()%100 <= iniciar_dll.jewel_up13)
		{

			DTadd->m_Level -= 1;
			deleteRecv(aIndex,lpMsg->inventoryPos,lpMsg->invenrotyTarget);
			MsgOutput(lpObj->m_Index,"%s Que Sorte Obteve sucesso no seu Up!",lpObj->Name);
		}
		else
		{
			MsgOutput(lpObj->m_Index,"%s Que pena seu Up falhou!",lpObj->Name);
			deleteRecv(aIndex,lpMsg->inventoryPos,lpMsg->invenrotyTarget);
		}

	}

	if(DTitem->m_Type == ITEMGET(14,JEWEL14))
	{
		return;
	}
}

void deleteRecv(int aIndex, char slot, char target)
{
	OBJECTSTRUCT *lpObj = (OBJECTSTRUCT*)GS_GOBJPOINTER(aIndex);

	gObjInventoryDeleteItem(aIndex, slot);
	GCInventoryItemDeleteSend(aIndex, slot, 1);
	GCInventoryItemOneSend(aIndex, target);	
	lpObj->pInventory[target].Convert(lpObj->pInventory[target].m_Type,lpObj->pInventory[target].m_Option1, lpObj->pInventory[target].m_Option2, lpObj->pInventory[target].m_Option3, lpObj->pInventory[target].m_NewOption,lpObj->pInventory[target].m_SetOption, lpObj->pInventory[target].m_ItemOptionEx,3);
}