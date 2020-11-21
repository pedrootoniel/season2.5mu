#include "stdafx.h"

void Premio_Hora_Online(LPOBJ lpObj)
{
	if(GetTickCount() - lpObj->AutoSaveTime > 180000)
	{
		GJSetCharacterInfo(lpObj,lpObj->m_Index,0);
		lpObj->AutoSaveTime = GetTickCount();
	}

	if(iniciar_dll.horasonline == 1)
	{
	    if(GetTickCount() - lpObj->ConnectCheckTime > iniciar_dll.tempo_online * 60000) // Tempo definido em Minutos.
	    {
			if(iniciar_dll.premio_type == 1)
			{
				MsgOutput(lpObj->m_Index,"Você acaba de ser premiado com %d Gold",iniciar_dll.premio_valor);
				_subC.subCSQL_retornar(lpObj->AccountID,_subC._query_bonus_on_gold,_subC.subCSQLtabela,_subC.subCSQLcoluna_id,0,"+");
				lpObj->ConnectCheckTime = GetTickCount();
			}
			else
			{
				MsgOutput(lpObj->m_Index,"Você acaba de ser premiado com %d Cash",iniciar_dll.premio_valor);
				_subC.subCSQL_retornar(lpObj->AccountID,_subC._query_bonus_on_cash,_subC.subCSQLtabela,_subC.subCSQLcoluna_id,0,"+");		    
				lpObj->ConnectCheckTime = GetTickCount();
			}
		
	    }
	}
}