#include "stdafx.h"

//----------------------------------------------------------------------------------------//
_classe_maximo _maximo;

//----------------------------------------------------------------------------------------//
//reload
void _classe_maximo::_reload()
{
	_maximo.variavel = 0;
    memset(_maximo.pontos, 0, sizeof(_maximo.pontos));
}

//----------------------------------------------------------------------------------------//
//leitura do arquivo de configuração
void _classe_maximo::loadfile(char* filename)
{
	this->_reload();

	Tokenizer          token;
	TokenizerGroup     group;
	TokenizerSection   section;

	token.ParseFile(std::string(filename), group);

	if(group.GetSection(0, section))
	{
		for(int i = 0; i < section.RowCount; i++)
		{
			_maximo.pontos[_maximo.variavel]._classe         = section.Rows[i].GetInt(0);
			_maximo.pontos[_maximo.variavel]._forca          = section.Rows[i].GetInt(1);
			_maximo.pontos[_maximo.variavel]._agilidade      = section.Rows[i].GetInt(2);
			_maximo.pontos[_maximo.variavel]._vitalidade     = section.Rows[i].GetInt(3);
			_maximo.pontos[_maximo.variavel]._energia        = section.Rows[i].GetInt(4);
			_maximo.pontos[_maximo.variavel]._comando        = section.Rows[i].GetInt(5);
			if(_maximo.pontos[_maximo.variavel]._forca > 32767 || _maximo.pontos[_maximo.variavel]._agilidade > 32767 || _maximo.pontos[_maximo.variavel]._vitalidade > 32767 || _maximo.pontos[_maximo.variavel]._energia > 32767 || _maximo.pontos[_maximo.variavel]._comando > 32767)
			{
				this->status();

			}
			_maximo.variavel++;
		}
	}
}

//----------------------------------------------------------------------------------------//
//alteração no gameserver
void _classe_maximo::status()
{
	*(BYTE*) GS_MAXSTRPOINT1 = 0xB7;
	*(BYTE*) GS_MAXSTRPOINT2 = 0xB7;
	*(BYTE*) GS_MAXSTRPOINT3 = 0xB7;
	*(BYTE*) GS_MAXSTRPOINT4 = 0xB7;
	*(BYTE*) GS_MAXSTRPOINT5 = 0xB7;
	*(BYTE*) GS_MAXSTRPOINT6 = 0xB7;
	*(BYTE*) GS_MAXSTRPOINT7 = 0xB7;
	*(BYTE*) GS_MAXSTRPOINT8 = 0xB7;
	*(BYTE*) GS_MAXSTRPOINT9 = 0xB7;
	*(BYTE*) GS_MAXSTRPOINT10 = 0xB7;
	*(BYTE*) GS_MAXSTRPOINT11 = 0xB7;
	*(BYTE*) GS_MAXSTRPOINT12 = 0xB7;
	*(BYTE*) GS_MAXSTRPOINT13 = 0xB7;
	*(BYTE*) GS_MAXSTRPOINT14 = 0xB7;
	*(BYTE*) GS_MAXSTRPOINT15 = 0xB7;
	*(BYTE*) GS_MAXSTRPOINT16 = 0xB7;
	*(BYTE*) GS_MAXSTRPOINT17 = 0xB7;
	*(BYTE*) GS_MAXSTRPOINT18 = 0xB7;
	*(BYTE*) GS_MAXSTRPOINT19 = 0xB7;
	*(BYTE*) GS_MAXSTRPOINT20 = 0xB7;
	*(BYTE*) GS_MAXSTRPOINT21 = 0xB7;
	*(BYTE*) GS_MAXSTRPOINT22 = 0xB7;
	*(BYTE*) GS_MAXSTRPOINT23 = 0xB7;
	*(BYTE*) GS_MAXSTRPOINT24 = 0xB7;
	*(BYTE*) GS_MAXSTRPOINT25 = 0xB7;
	*(BYTE*) GS_MAXSTRPOINT26 = 0xB7;
	*(BYTE*) GS_MAXSTRPOINT27 = 0xB7;
	*(BYTE*) GS_MAXSTRPOINT28 = 0xB7;
	*(BYTE*) GS_MAXSTRPOINT29 = 0xB7;
	*(BYTE*) GS_MAXAGIPOINT1 = 0xB7;
	*(BYTE*) GS_MAXAGIPOINT2 = 0xB7;
	*(BYTE*) GS_MAXAGIPOINT3 = 0xB7;
	*(BYTE*) GS_MAXAGIPOINT4 = 0xB7;
	*(BYTE*) GS_MAXAGIPOINT5 = 0xB7;
	*(BYTE*) GS_MAXAGIPOINT6 = 0xB7;
	*(BYTE*) GS_MAXAGIPOINT7 = 0xB7;
	*(BYTE*) GS_MAXAGIPOINT8 = 0xB7;
	*(BYTE*) GS_MAXAGIPOINT9 = 0xB7;
	*(BYTE*) GS_MAXAGIPOINT10 = 0xB7;
	*(BYTE*) GS_MAXAGIPOINT11 = 0xB7;
	*(BYTE*) GS_MAXAGIPOINT12 = 0xB7;
	*(BYTE*) GS_MAXAGIPOINT13 = 0xB7;
	*(BYTE*) GS_MAXAGIPOINT14 = 0xB7;
	*(BYTE*) GS_MAXAGIPOINT15 = 0xB7;
	*(BYTE*) GS_MAXAGIPOINT16 = 0xB7;
	*(BYTE*) GS_MAXAGIPOINT17 = 0xB7;
	*(BYTE*) GS_MAXAGIPOINT18 = 0xB7;
	*(BYTE*) GS_MAXAGIPOINT19 = 0xB7;
	*(BYTE*) GS_MAXAGIPOINT20 = 0xB7;
	*(BYTE*) GS_MAXAGIPOINT21 = 0xB7;
	*(BYTE*) GS_MAXAGIPOINT22 = 0xB7;
	*(BYTE*) GS_MAXAGIPOINT23 = 0xB7;
	*(BYTE*) GS_MAXAGIPOINT24 = 0xB7;
	*(BYTE*) GS_MAXAGIPOINT25 = 0xB7;
	*(BYTE*) GS_MAXAGIPOINT26 = 0xB7;
	*(BYTE*) GS_MAXAGIPOINT27 = 0xB7;
	*(BYTE*) GS_MAXAGIPOINT28 = 0xB7;
	*(BYTE*) GS_MAXAGIPOINT29 = 0xB7;
	*(BYTE*) GS_MAXAGIPOINT30 = 0xB7;
	*(BYTE*) GS_MAXAGIPOINT31 = 0xB7;
	*(BYTE*) GS_MAXAGIPOINT32 = 0xB7;
	*(BYTE*) GS_MAXAGIPOINT33 = 0xB7;
	*(BYTE*) GS_MAXAGIPOINT34 = 0xB7;
	*(BYTE*) GS_MAXAGIPOINT35 = 0xB7;
	*(BYTE*) GS_MAXAGIPOINT36 = 0xB7;
	*(BYTE*) GS_MAXAGIPOINT37 = 0xB7;
	*(BYTE*) GS_MAXAGIPOINT38 = 0xB7;
	*(BYTE*) GS_MAXAGIPOINT39 = 0xB7;
	*(BYTE*) GS_MAXAGIPOINT40 = 0xB7;
	*(BYTE*) GS_MAXAGIPOINT41 = 0xB7;
	*(BYTE*) GS_MAXAGIPOINT42 = 0xB7;
	*(BYTE*) GS_MAXAGIPOINT43 = 0xB7;
	*(BYTE*) GS_MAXAGIPOINT44 = 0xB7;
	*(BYTE*) GS_MAXAGIPOINT45 = 0xB7;
	*(BYTE*) GS_MAXAGIPOINT46 = 0xB7;
	*(BYTE*) GS_MAXVITPOINTS1 = 0xB7;
	*(BYTE*) GS_MAXVITPOINTS2 = 0xB7;
	*(BYTE*) GS_MAXVITPOINTS3 = 0xB7;
	*(BYTE*) GS_MAXVITPOINTS4 = 0xB7;
	*(BYTE*) GS_MAXVITPOINTS5 = 0xB7;
	*(BYTE*) GS_MAXVITPOINTS6 = 0xB7;
	*(BYTE*) GS_MAXVITPOINTS7 = 0xB7;
	*(BYTE*) GS_MAXVITPOINTS8 = 0xB7;
	*(BYTE*) GS_MAXVITPOINTS9 = 0xB7;
	*(BYTE*) GS_MAXVITPOINTS10 = 0xB7;
	*(BYTE*) GS_MAXVITPOINTS11 = 0xB7;
	*(BYTE*) GS_MAXVITPOINTS12 = 0xB7;
	*(BYTE*) GS_MAXVITPOINTS13 = 0xB7;
	*(BYTE*) GS_MAXVITPOINTS14 = 0xB7;
	*(BYTE*) GS_MAXVITPOINTS15 = 0xB7;
	*(BYTE*) GS_MAXVITPOINTS16 = 0xB7;
	*(BYTE*) GS_MAXVITPOINTS17 = 0xB7;
	*(BYTE*) GS_MAXVITPOINTS18 = 0xB7;
	*(BYTE*) GS_MAXVITPOINTS19 = 0xB7;
	*(BYTE*) GS_MAXVITPOINTS20 = 0xB7;
	*(BYTE*) GS_MAXVITPOINTS21 = 0xB7;
	*(BYTE*) GS_MAXVITPOINTS22 = 0xB7;
	*(BYTE*) GS_MAXVITPOINTS23 = 0xB7;
	*(BYTE*) GS_MAXVITPOINTS24 = 0xB7;
	*(BYTE*) GS_MAXVITPOINTS25 = 0xB7;
	*(BYTE*) GS_MAXVITPOINTS26 = 0xB7;
	*(BYTE*) GS_MAXVITPOINTS27 = 0xB7;
	*(BYTE*) GS_MAXENEPOINTS1 = 0xB7;
	*(BYTE*) GS_MAXENEPOINTS2 = 0xB7;
	*(BYTE*) GS_MAXENEPOINTS3 = 0xB7;
	*(BYTE*) GS_MAXENEPOINTS4 = 0xB7;
	*(BYTE*) GS_MAXENEPOINTS5 = 0xB7;
	*(BYTE*) GS_MAXENEPOINTS6 = 0xB7;
	*(BYTE*) GS_MAXENEPOINTS7 = 0xB7;
	*(BYTE*) GS_MAXENEPOINTS8 = 0xB7;
	*(BYTE*) GS_MAXENEPOINTS9 = 0xB7;
	*(BYTE*) GS_MAXENEPOINTS10 = 0xB7;
	*(BYTE*) GS_MAXENEPOINTS11 = 0xB7;
	*(BYTE*) GS_MAXENEPOINTS12 = 0xB7;
	*(BYTE*) GS_MAXENEPOINTS13 = 0xB7;
	*(BYTE*) GS_MAXENEPOINTS14 = 0xB7;
	*(BYTE*) GS_MAXENEPOINTS15 = 0xB7;
	*(BYTE*) GS_MAXENEPOINTS16 = 0xB7;
	*(BYTE*) GS_MAXENEPOINTS17 = 0xB7;
	*(BYTE*) GS_MAXENEPOINTS18 = 0xB7;
	*(BYTE*) GS_MAXENEPOINTS19 = 0xB7;
	*(BYTE*) GS_MAXENEPOINTS20 = 0xB7;
	*(BYTE*) GS_MAXENEPOINTS21 = 0xB7;
	*(BYTE*) GS_MAXENEPOINTS22 = 0xB7;
	*(BYTE*) GS_MAXENEPOINTS23 = 0xB7;
	*(BYTE*) GS_MAXENEPOINTS24 = 0xB7;
	*(BYTE*) GS_MAXENEPOINTS25 = 0xB7;
	*(BYTE*) GS_MAXENEPOINTS26 = 0xB7;
	*(BYTE*) GS_MAXENEPOINTS27 = 0xB7;
	*(BYTE*) GS_MAXENEPOINTS28 = 0xB7;
	*(BYTE*) GS_MAXENEPOINTS29 = 0xB7;
	*(BYTE*) GS_MAXENEPOINTS30 = 0xB7;
	*(BYTE*) GS_MAXENEPOINTS31 = 0xB7;
	*(BYTE*) GS_MAXENEPOINTS32 = 0xB7;
	*(BYTE*) GS_MAXENEPOINTS33 = 0xB7;
	*(BYTE*) GS_MAXENEPOINTS34 = 0xB7;
	*(BYTE*) GS_MAXENEPOINTS35 = 0xB7;
	*(BYTE*) GS_MAXENEPOINTS36 = 0xB7;
	*(BYTE*) GS_MAXENEPOINTS37 = 0xB7;
}

//----------------------------------------------------------------------------------------//
//função de adicionar pontos
BOOL _gObjLevelUpPointAdd(BYTE type, LPOBJ lpObj)
{
	if(lpObj->Type > 3)
	{
		return FALSE;
	}

	if(lpObj->LevelUpPoint < 1)
	{
		return FALSE;
	}

	for(int i = 0; i < _maximo.variavel; i++)
	{
		if(lpObj->DbClass == _maximo.pontos[i]._classe)
		{
	        switch(type)
	        {
	            case 0: //----------- força
				if(lpObj->Strength >= _maximo.pontos[i]._forca)
				{
					_mensagem(lpObj->m_Index,0,_maximo.pontos[i]._forca,0,0);
					return FALSE;
				}
				else
				{
	            lpObj->Strength++;
				}
	            break;
	            case 1: //----------- agilidade
				if(lpObj->Dexterity >= _maximo.pontos[i]._agilidade)
				{
					_mensagem(lpObj->m_Index,1,_maximo.pontos[i]._agilidade,0,0);
					return FALSE;
				}
				else
				{
	            lpObj->Dexterity++;
				}
			    break;
	            case 2: //----------- vitalidade
				if(lpObj->Vitality >= _maximo.pontos[i]._vitalidade)
				{
					_mensagem(lpObj->m_Index,2,_maximo.pontos[i]._vitalidade,0,0);
					return FALSE;
				}
				else
				{
	            lpObj->Vitality++;
	            lpObj->MaxLife += lpObj->VitalityToLife;
	            gObjCalcMaxLifePower(lpObj->m_Index);
				}
			    break;
	            case 3: //----------- energia
				if(lpObj->Energy >= _maximo.pontos[i]._energia)
				{
					_mensagem(lpObj->m_Index,3,_maximo.pontos[i]._energia,0,0);
					return FALSE;
				}
				else
				{
	            lpObj->Energy++;
	            lpObj->MaxMana += lpObj->EnergyToMana;
				}
			    break;
	            case 4: //----------- comando
				if(lpObj->Leadership >= _maximo.pontos[i]._comando)
				{
					_mensagem(lpObj->m_Index,1,_maximo.pontos[i]._comando,0,0);
					return FALSE;
				}
				else
				{
	            lpObj->Leadership++;
				}
			    break;
			}
		}
	}

	lpObj->LevelUpPoint--;
	gClient.GSPointsUP(lpObj);
	gObjCalCharacter(lpObj->m_Index);
	return TRUE;
}

void gObjGCLevelUpMsgSend(int aIndex, int iSendEffect)
{
	OBJECTSTRUCT* lpObj = (OBJECTSTRUCT*)GS_GOBJPOINTER(aIndex);

	for(int i = 0; i < _reset_iniciar.v; i++)
	{
		if(lpObj->Level >= _reset_iniciar._r_struct[i]._level)
		{
			if(lpObj->autoreset != false)
			{
				_reset_iniciar._reset_init(lpObj,0,1);
			}	
		}
	}

	gClient.GSPointsUP(lpObj);
	GCLevelUpMsgSend(aIndex,iSendEffect);
}