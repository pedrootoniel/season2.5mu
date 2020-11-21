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
			if(_maximo.pontos[_maximo.variavel]._forca		> 32767 
			|| _maximo.pontos[_maximo.variavel]._agilidade	> 32767 
			|| _maximo.pontos[_maximo.variavel]._vitalidade > 32767 
			|| _maximo.pontos[_maximo.variavel]._energia	> 32767 
			|| _maximo.pontos[_maximo.variavel]._comando	> 32767)
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
	*(BYTE*)(0x0044F25E+1)    = 0xB7;
	*(BYTE*)(0x0044F2CB+1)    = 0xB7;
	*(BYTE*)(0x00488297+1)    = 0xB7;
	*(BYTE*)(0x004B1DB4+1)    = 0xB7;
	*(BYTE*)(0x004B1DCD+1)    = 0xB7;
	*(BYTE*)(0x004B1DE6+1)    = 0xB7;
	*(BYTE*)(0x004B1DFF+1)    = 0xB7;
	*(BYTE*)(0x004B21A1+1)    = 0xB7;
	*(BYTE*)(0x004B21B5+1)    = 0xB7;
	*(BYTE*)(0x004B21C9+1)    = 0xB7;
	*(BYTE*)(0x004B21DD+1)    = 0xB7;
	*(BYTE*)(0x004B2209+1)    = 0xB7;
	*(BYTE*)(0x004B221D+1)    = 0xB7;
	*(BYTE*)(0x004B2231+1)    = 0xB7;
	*(BYTE*)(0x004B2245+1)    = 0xB7;
	*(BYTE*)(0x004B2272+1)    = 0xB7;
	*(BYTE*)(0x004B2286+1)    = 0xB7;
	*(BYTE*)(0x004B229A+1)    = 0xB7;
	*(BYTE*)(0x004B22AE+1)    = 0xB7;
	*(BYTE*)(0x004B22C7+1)    = 0xB7;
	*(BYTE*)(0x004B22DB+1)    = 0xB7;
	*(BYTE*)(0x004B22EF+1)    = 0xB7;
	*(BYTE*)(0x004B2303+1)    = 0xB7;
	*(BYTE*)(0x004B2BDA+1)    = 0xB7;
	*(BYTE*)(0x004B37E1+1)    = 0xB7;
	*(BYTE*)(0x004B4A45+1)    = 0xB7;
	*(BYTE*)(0x004B4AD7+1)    = 0xB7;
	*(BYTE*)(0x004B4AF7+1)    = 0xB7;
	*(BYTE*)(0x004B53FF+1)    = 0xB7;
	*(BYTE*)(0x004B6B41+1)    = 0xB7;
	*(BYTE*)(0x004B6B61+1)    = 0xB7;
	*(BYTE*)(0x004B6BDB+1)    = 0xB7;
	*(BYTE*)(0x004B6BFB+1)    = 0xB7;
	*(BYTE*)(0x004B6E95+1)    = 0xB7;
	*(BYTE*)(0x004B6ED8+1)    = 0xB7;
	*(BYTE*)(0x004B6F11+1)    = 0xB7;
	*(BYTE*)(0x004B6F51+1)    = 0xB7;
	*(BYTE*)(0x004B6F90+1)    = 0xB7;
	*(BYTE*)(0x004B6FC1+1)    = 0xB7;
	*(BYTE*)(0x004B6FFC+1)    = 0xB7;
	*(BYTE*)(0x004B7037+1)    = 0xB7;
	*(BYTE*)(0x004B7072+1)    = 0xB7;
	*(BYTE*)(0x004B70AD+1)    = 0xB7;
	*(BYTE*)(0x004B99CB+1)    = 0xB7;
	*(BYTE*)(0x004B99EB+1)    = 0xB7;
	*(BYTE*)(0x004B9A15+1)    = 0xB7;
	*(BYTE*)(0x004B9DD7+1)    = 0xB7;
	*(BYTE*)(0x004B9DF7+1)    = 0xB7;
	*(BYTE*)(0x004B9E22+1)    = 0xB7;
	*(BYTE*)(0x004B9FA5+1)    = 0xB7;
	*(BYTE*)(0x004BA236+1)    = 0xB7;
	*(BYTE*)(0x004BA9F0+1)    = 0xB7;
	*(BYTE*)(0x004BAB32+1)    = 0xB7;
	*(BYTE*)(0x004BDC99+1)    = 0xB7;
	*(BYTE*)(0x004BDCBC+1)    = 0xB7;
	*(BYTE*)(0x004C2A89+1)    = 0xB7;
	*(BYTE*)(0x004C2AA2+1)    = 0xB7;
	*(BYTE*)(0x004C2ABB+1)    = 0xB7;
	*(BYTE*)(0x004C2AD4+1)    = 0xB7;
	*(BYTE*)(0x004C706C+1)    = 0xB7;
	*(BYTE*)(0x004C70A2+1)    = 0xB7;
	*(BYTE*)(0x004C70D8+1)    = 0xB7;
	*(BYTE*)(0x004C710E+1)    = 0xB7;
	*(BYTE*)(0x004C7144+1)    = 0xB7;
	*(BYTE*)(0x004C7A4C+1)    = 0xB7;
	*(BYTE*)(0x004C7A91+1)    = 0xB7;
	*(BYTE*)(0x004C7AD6+1)    = 0xB7;
	*(BYTE*)(0x004C7B51+1)    = 0xB7;
	*(BYTE*)(0x004C7C33+1)    = 0xB7;
	*(BYTE*)(0x004C7C49+1)    = 0xB7;
	*(BYTE*)(0x004C7C61+1)    = 0xB7;
	*(BYTE*)(0x004C7C79+1)    = 0xB7;
	*(BYTE*)(0x004C940E+1)    = 0xB7;
	*(BYTE*)(0x004C9427+1)    = 0xB7;
	*(BYTE*)(0x004C9440+1)    = 0xB7;
	*(BYTE*)(0x004C9459+1)    = 0xB7;
	*(BYTE*)(0x004CA9E5+1)    = 0xB7;
	*(BYTE*)(0x004CAA28+1)    = 0xB7;
	*(BYTE*)(0x004CAA61+1)    = 0xB7;
	*(BYTE*)(0x004CAAA1+1)    = 0xB7;
	*(BYTE*)(0x004CAAE0+1)    = 0xB7;
	*(BYTE*)(0x004CAB11+1)    = 0xB7;
	*(BYTE*)(0x004CAB4C+1)    = 0xB7;
	*(BYTE*)(0x004CAB87+1)    = 0xB7;
	*(BYTE*)(0x004CABC2+1)    = 0xB7;
	*(BYTE*)(0x004CABFD+1)    = 0xB7;
	*(BYTE*)(0x004D3672+1)    = 0xB7;
	*(BYTE*)(0x004D3697+1)    = 0xB7;
	*(BYTE*)(0x004D36BC+1)    = 0xB7;
	*(BYTE*)(0x004D36E1+1)    = 0xB7;
	*(BYTE*)(0x004D47BC+1)    = 0xB7;
	*(BYTE*)(0x004D485B+1)    = 0xB7;
	*(BYTE*)(0x004D61D0+1)    = 0xB7;
	*(BYTE*)(0x004D61DB+1)    = 0xB7;
	*(BYTE*)(0x004D61E6+1)    = 0xB7;
	*(BYTE*)(0x004D61F1+1)    = 0xB7;
	*(BYTE*)(0x004E7D66+1)    = 0xB7;
	*(BYTE*)(0x004E7D9E+1)    = 0xB7;
	*(BYTE*)(0x004E7E0D+1)    = 0xB7;
	*(BYTE*)(0x004E7E37+1)    = 0xB7;
	*(BYTE*)(0x004FD675+1)    = 0xB7;
	*(BYTE*)(0x004FDB21+1)    = 0xB7;
	*(BYTE*)(0x004FE0AC+1)    = 0xB7;
	*(BYTE*)(0x00502313+1)    = 0xB7;
	*(BYTE*)(0x0050231D+1)    = 0xB7;
	*(BYTE*)(0x00502329+1)    = 0xB7;
	*(BYTE*)(0x00502335+1)    = 0xB7;
	*(BYTE*)(0x0050258D+1)    = 0xB7;
	*(BYTE*)(0x00502597+1)    = 0xB7;
	*(BYTE*)(0x005025A3+1)    = 0xB7;
	*(BYTE*)(0x005025AF+1)    = 0xB7;
	*(BYTE*)(0x0050277D+1)    = 0xB7;
	*(BYTE*)(0x00502787+1)    = 0xB7;
	*(BYTE*)(0x00502793+1)    = 0xB7;
	*(BYTE*)(0x0050279F+1)    = 0xB7;
	*(BYTE*)(0x00503ACD+1)    = 0xB7;
	*(BYTE*)(0x00503B0F+1)    = 0xB7;
	*(BYTE*)(0x00503B51+1)    = 0xB7;
	*(BYTE*)(0x00503B90+1)    = 0xB7;
	*(BYTE*)(0x0050441A+1)    = 0xB7;
	*(BYTE*)(0x0050443D+1)    = 0xB7;
	*(BYTE*)(0x00504460+1)    = 0xB7;
	*(BYTE*)(0x00504483+1)    = 0xB7;
	*(BYTE*)(0x0053F15D+1)    = 0xB7;
	*(BYTE*)(0x0053F171+1)    = 0xB7;
	*(BYTE*)(0x0053F185+1)    = 0xB7;
	*(BYTE*)(0x0053F199+1)    = 0xB7;
	*(BYTE*)(0x0053F356+1)    = 0xB7;
	*(BYTE*)(0x0053F36A+1)    = 0xB7;
	*(BYTE*)(0x0053F37E+1)    = 0xB7;
	*(BYTE*)(0x0053F392+1)    = 0xB7;
	*(BYTE*)(0x0053F59F+1)    = 0xB7;
	*(BYTE*)(0x0053F5B3+1)    = 0xB7;
	*(BYTE*)(0x0053F5C7+1)    = 0xB7;
	*(BYTE*)(0x0053F5DB+1)    = 0xB7;
	*(BYTE*)(0x005819E7+1)    = 0xB7;
	*(BYTE*)(0x005819F8+1)    = 0xB7;
	*(BYTE*)(0x00581A09+1)    = 0xB7;
	*(BYTE*)(0x00581A1A+1)    = 0xB7;
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