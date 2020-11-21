#include "stdafx.h"

void _move_jewel(LPOBJ lpObj, DWORD* NpcIndex, char _tp)
{
	int CHAVE  = ITEMGET(14,JEWEL14);
	int ItenCount = 1;
	int map;
	int x;
	int y;

	if(lpObj->Level < 200)
	{
		if(_tp == 0)
		{
			_mensagem(lpObj->m_Index,97,0,NpcIndex,1);
			return;
		}
		else
		{
			_mensagem(lpObj->m_Index,97,0,NpcIndex,1);
			return;
		}

	}
	else if(gObjGetItemCountInInventory(lpObj->m_Index,CHAVE,0) < ItenCount)
	{
		if(_tp == 0)
		{
			_mensagem(lpObj->m_Index,98,0,NpcIndex,1);
			return;
		}
		else
		{
			_mensagem(lpObj->m_Index,98,0,NpcIndex,1);
			return;
		}
	}
	else
	{
		gObjTeleport(lpObj->m_Index,31,61,10);
		gObjDeleteItemsCount(lpObj->m_Index,CHAVE, 0, ItenCount);
	}
}