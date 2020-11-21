#include "stdafx.h"

//----------------------------------------------------------------------------------------//
_reset_classe _reset_iniciar;

//----------------------------------------------------------------------------------------//
//configuração
void _reset_classe::_reset_config_simples()
{
	_reset_iniciar._r_struct->_ativar[0]   = iniciar_dll.iniciar_getprivateint("settings","iniciar_reset[0]",    0, ".\\configurações\\_administrador.settings\\_settings.reset.ID");
	_reset_iniciar._r_struct->_ativar[1]   = iniciar_dll.iniciar_getprivateint("settings","iniciar_reset[1]",    0, ".\\configurações\\_administrador.settings\\_settings.reset.ID");
	_reset_iniciar._r_struct->_ativar[2]   = iniciar_dll.iniciar_getprivateint("settings","iniciar_reset[2]",    0, ".\\configurações\\_administrador.settings\\_settings.reset.ID");
	_reset_iniciar._r_struct->_ativar[3]   = iniciar_dll.iniciar_getprivateint("settings","iniciar_reset[3]",    0, ".\\configurações\\_administrador.settings\\_settings.reset.ID");
	_reset_iniciar._r_struct->_ativar[4]   = iniciar_dll.iniciar_getprivateint("settings","iniciar_reset[4]",    0, ".\\configurações\\_administrador.settings\\_settings.reset.ID");
	_reset_iniciar._r_struct->_ativar[5]   = iniciar_dll.iniciar_getprivateint("settings","iniciar_reset[5]",    0, ".\\configurações\\_administrador.settings\\_settings.reset.ID");

	_reset_iniciar._r_struct->_tipo[0]     = iniciar_dll.iniciar_getprivateint("settings","iniciar_tipo[0]",     0, ".\\configurações\\_administrador.settings\\_settings.reset.ID");
	_reset_iniciar._r_struct->_tipo[1]     = iniciar_dll.iniciar_getprivateint("settings","iniciar_tipo[1]",     0, ".\\configurações\\_administrador.settings\\_settings.reset.ID");
	_reset_iniciar._r_struct->_tipo[2]     = iniciar_dll.iniciar_getprivateint("settings","iniciar_tipo[2]",     0, ".\\configurações\\_administrador.settings\\_settings.reset.ID");
	_reset_iniciar._r_struct->_tipo[3]     = iniciar_dll.iniciar_getprivateint("settings","iniciar_tipo[3]",     0, ".\\configurações\\_administrador.settings\\_settings.reset.ID");
	_reset_iniciar._r_struct->_tipo[4]     = iniciar_dll.iniciar_getprivateint("settings","iniciar_tipo[4]",     0, ".\\configurações\\_administrador.settings\\_settings.reset.ID");
	_reset_iniciar._r_struct->_tipo[5]     = iniciar_dll.iniciar_getprivateint("settings","iniciar_tipo[5]",     0, ".\\configurações\\_administrador.settings\\_settings.reset.ID");

	_reset_iniciar._r_struct->_mover[0]    = iniciar_dll.iniciar_getprivateint("settings","iniciar_move[0]",     0, ".\\configurações\\_administrador.settings\\_settings.reset.ID");
	_reset_iniciar._r_struct->_mover[1]    = iniciar_dll.iniciar_getprivateint("settings","iniciar_move[1]",     0, ".\\configurações\\_administrador.settings\\_settings.reset.ID");
	_reset_iniciar._r_struct->_mover[2]    = iniciar_dll.iniciar_getprivateint("settings","iniciar_move[2]",     0, ".\\configurações\\_administrador.settings\\_settings.reset.ID");
	_reset_iniciar._r_struct->_mover[3]    = iniciar_dll.iniciar_getprivateint("settings","iniciar_move[3]",     0, ".\\configurações\\_administrador.settings\\_settings.reset.ID");
	_reset_iniciar._r_struct->_mover[4]    = iniciar_dll.iniciar_getprivateint("settings","iniciar_move[4]",     0, ".\\configurações\\_administrador.settings\\_settings.reset.ID");
	_reset_iniciar._r_struct->_mover[5]    = iniciar_dll.iniciar_getprivateint("settings","iniciar_move[5]",     0, ".\\configurações\\_administrador.settings\\_settings.reset.ID");

	_reset_iniciar._r_struct->_comando[0]  = iniciar_dll.iniciar_getprivateint("settings","iniciar_comando[0]",  0, ".\\configurações\\_administrador.settings\\_settings.reset.ID");
	_reset_iniciar._r_struct->_comando[1]  = iniciar_dll.iniciar_getprivateint("settings","iniciar_comando[1]",  0, ".\\configurações\\_administrador.settings\\_settings.reset.ID");
	_reset_iniciar._r_struct->_comando[2]  = iniciar_dll.iniciar_getprivateint("settings","iniciar_comando[2]",  0, ".\\configurações\\_administrador.settings\\_settings.reset.ID");
	_reset_iniciar._r_struct->_comando[3]  = iniciar_dll.iniciar_getprivateint("settings","iniciar_comando[3]",  0, ".\\configurações\\_administrador.settings\\_settings.reset.ID");
	_reset_iniciar._r_struct->_comando[4]  = iniciar_dll.iniciar_getprivateint("settings","iniciar_comando[4]",  0, ".\\configurações\\_administrador.settings\\_settings.reset.ID");
	_reset_iniciar._r_struct->_comando[5]  = iniciar_dll.iniciar_getprivateint("settings","iniciar_comando[5]",  0, ".\\configurações\\_administrador.settings\\_settings.reset.ID");
}

//----------------------------------------------------------------------------------------//
//configuração
void _reset_classe::_reset_loadfile(char * filename)
{

	this->_reload();

	this->_reset_config_simples();

	Tokenizer          token;
	TokenizerGroup     group;
	TokenizerSection   section;

	token.ParseFile(std::string(filename), group);

	if(group.GetSection(3, section))
	{
		for(int i = 0; i < section.RowCount; i++)
		{ 
			_reset_iniciar._r_struct[_reset_iniciar.v]._vip              = section.Rows[i].GetInt(0);
			_reset_iniciar._r_struct[_reset_iniciar.v]._min_reset        = section.Rows[i].GetInt(1);
			_reset_iniciar._r_struct[_reset_iniciar.v]._max_reset        = section.Rows[i].GetInt(2);
			_reset_iniciar._r_struct[_reset_iniciar.v]._level            = section.Rows[i].GetInt(3);
			_reset_iniciar._r_struct[_reset_iniciar.v]._money            = section.Rows[i].GetInt(4);
			_reset_iniciar._r_struct[_reset_iniciar.v]._remover          = section.Rows[i].GetInt(5);
			_reset_iniciar._r_struct[_reset_iniciar.v]._pontos           = section.Rows[i].GetInt(6);
			_reset_iniciar._r_struct[_reset_iniciar.v]._retornar_level   = section.Rows[i].GetInt(7);
			_reset_iniciar.v++;
		}
	}
}

//----------------------------------------------------------------------------------------//
//reload
void _reset_classe::_reload()
{
	_reset_iniciar.v = 0;
    memset(_reset_iniciar._r_struct, 0, sizeof(_reset_iniciar._r_struct));
}

//----------------------------------------------------------------------------------------//
//inicio do reset
void _reset_classe::_reset_init(LPOBJ lpObj, DWORD* NpcIndex, char _tp)
{

	if(_reset_iniciar._r_struct->_ativar[lpObj->vip] == 0)
	{
		if(_tp == 0)
		{
			_mensagem(lpObj->m_Index,5,0,NpcIndex,1);
		}
		else
		{
			_mensagem(lpObj->m_Index,5,0,0,0);
		}
	}
	else
	{
		this->_reset_pontuativo(lpObj,NpcIndex,_tp,lpObj->vip);
	}

}

//----------------------------------------------------------------------------------------//
//reset e verificações
void _reset_classe::_reset_pontuativo(LPOBJ lpObj, DWORD* NpcIndex, char _tp, BYTE vip)
{

	PMSG_USE_STAT_FRUIT pCaseC3;

	int reset = _subC.subCSQL_retornar(lpObj->Name,_subC.subCSQLcoluna_retornar_r,_subC.subCSQLtabela_r,_subC.subCSQLcoluna_id_r,lpObj->reset,"*");

	if(subCheckConnect == true)
	{
		GCServerMsgStringSend("aguarde a reconexão com o banco de dados para resetar",lpObj->m_Index,0);
		subCheckConnect = false;
		return;
	}

	for(int i = 0; i < _reset_iniciar.v; i++)
	{
		if(vip == _reset_iniciar._r_struct[i]._vip)
		{
			if(reset >= _reset_iniciar._r_struct[i]._min_reset && reset <= _reset_iniciar._r_struct[i]._max_reset)
			{
				if(lpObj->Level < _reset_iniciar._r_struct[i]._level)
				{
					if(_tp == 0)
					{
					    _mensagem(lpObj->m_Index,6,_reset_iniciar._r_struct[i]._level,NpcIndex,1);
					}
					else
					{
						if(lpObj->autoreset != true)
						{
							_mensagem(lpObj->m_Index,6,_reset_iniciar._r_struct[i]._level,0,0);
						}
					}
					break;
				}
				if(lpObj->Money < _reset_iniciar._r_struct[i]._money)
				{
					if(_tp == 0)
					{
					    _mensagem(lpObj->m_Index,7,_reset_iniciar._r_struct[i]._money,NpcIndex,1);
					}
					else
					{
						_mensagem(lpObj->m_Index,7,_reset_iniciar._r_struct[i]._money,0,0);
					}
					break;
				}
				if(_reset_iniciar._r_struct[i]._remover == 1)
				{
					if(this->_reset_remove(lpObj) == TRUE)
					{
						if(_tp == 0)
					    {
					        _mensagem(lpObj->m_Index,8,_reset_iniciar._r_struct[i]._money,NpcIndex,1);
					    }
					    else
					    {
						   _mensagem(lpObj->m_Index,8,_reset_iniciar._r_struct[i]._money,0,0);
					    }
					    break;
				    }
				}
				//----------- deixa a experiencia em 1
				lpObj->Experience        = 1;
				lpObj->Level             = _reset_iniciar._r_struct[i]._retornar_level;
				lpObj->Money            -= _reset_iniciar._r_struct[i]._money;
				if(_reset_iniciar._r_struct->_tipo[vip] == 1)
				{
					if(reset == 0)
					{
                       lpObj->LevelUpPoint   = _reset_iniciar._r_struct[i]._pontos;
					}
					else
					{
					   lpObj->LevelUpPoint   = reset * _reset_iniciar._r_struct[i]._pontos + _reset_iniciar._r_struct[i]._pontos;
					}
					this->_reset_calc(lpObj);
				}
				this->_move(lpObj,vip);
			    GCMoneySend(lpObj->m_Index,lpObj->Money);
	            gObjCalCharacter(lpObj->m_Index);
	            
				gClient.GSPointsUP(lpObj);
				GCLevelUpMsgSend(lpObj->m_Index,1);

				//----------- fix reset sem travamento, necessário fixar no main
				//----------- envia o packet para subtrair a experiencia pela experiencia
	            PHeadSubSetBE((LPBYTE)&pCaseC3, 0xFF, 0x08, sizeof(pCaseC3));
	            DataSend(lpObj->m_Index,(unsigned char *)&pCaseC3,pCaseC3.h.size);
	            GCKillPlayerExpSend(lpObj->m_Index,lpObj->Class,0,0,0);
				//----------- adiciona 1 de experiencia
	            PHeadSubSetBE((LPBYTE)&pCaseC3, 0xFF, 0x09, sizeof(pCaseC3));
	            DataSend(lpObj->m_Index,(unsigned char *)&pCaseC3,pCaseC3.h.size);
	            GCKillPlayerExpSend(lpObj->m_Index,lpObj->Class,1,0,0);
				//----------- conexão com sql
				_subC.subCSQL_retornar(lpObj->Name,_subC.subCSQLcoluna_update[vip],_subC.subCSQLtabela_r,_subC.subCSQLcoluna_id_r,0,"+");
				//----------- desbloqueia para verificar os resets
				//lpObj->reset_check = false;
		        if(_tp == 0)
		        {
			        _mensagem(lpObj->m_Index,9,reset+1,NpcIndex,1);
		        }
		        else
		        {
			        _mensagem(lpObj->m_Index,9,reset+1,0,0);
		        }
				break;
			}
		}
	}
}

//----------------------------------------------------------------------------------------//
//verifica se tem items
bool _reset_classe::_reset_remove(LPOBJ lpObj)
{
	for(int i = 0; i < 11; i++)
	{
		if(lpObj->pInventory[i].m_Type > 0)
		{
			return TRUE;
		}
	}
	return FALSE;
}

//----------------------------------------------------------------------------------------//
//move o personagem
void _reset_classe::_move(LPOBJ lpObj, BYTE vip)
{
	if(_reset_iniciar._r_struct->_mover[vip] == 1)
	{
		if(lpObj->DbClass == 0 || lpObj->DbClass == 1 || lpObj->DbClass == 16 || lpObj->DbClass == 17 || lpObj->DbClass == 48 || lpObj->DbClass == 64)
		{
			gObjTeleport(lpObj->m_Index,0,140,135);
		}
		if(lpObj->DbClass == 32 || lpObj->DbClass == 33)
		{
			gObjTeleport(lpObj->m_Index,3,174,114);
		}
	}
}

//----------------------------------------------------------------------------------------//
//pontuativo resetar status
void _reset_classe::_reset_calc(LPOBJ lpObj)
{
	PMSG_USE_STAT_FRUIT pResult;
	PHeadSetB((LPBYTE)&pResult,0x2C,sizeof(pResult));

	// força
	pResult.result = 3;
	pResult.btStatValue = lpObj->Strength;
	pResult.btFruitType = 3;
	DataSend(lpObj->m_Index,(unsigned char *)&pResult,pResult.h.size);
	lpObj->Strength -= lpObj->Strength;
	pResult.result = 0;
	pResult.btStatValue = 30;
	pResult.btFruitType = 3;
	DataSend(lpObj->m_Index,(unsigned char *)&pResult,pResult.h.size);
	lpObj->Strength += 30;
    // agilidade
	pResult.result = 3;
	pResult.btStatValue = lpObj->Dexterity;
	pResult.btFruitType = 2;
	DataSend(lpObj->m_Index,(unsigned char *)&pResult,pResult.h.size);
	lpObj->Dexterity -= lpObj->Dexterity;
	pResult.result = 0;
	pResult.btStatValue = 30;
	pResult.btFruitType = 2;
	DataSend(lpObj->m_Index,(unsigned char *)&pResult,pResult.h.size);
	lpObj->Dexterity += 30;
    // vitalidade
	pResult.result = 3;
	pResult.btStatValue = lpObj->Vitality;
	pResult.btFruitType = 1;
	DataSend(lpObj->m_Index,(unsigned char *)&pResult,pResult.h.size);
	lpObj->Vitality -= lpObj->Vitality;
	pResult.result = 0;
	pResult.btStatValue = 30;
	pResult.btFruitType = 1;
	DataSend(lpObj->m_Index,(unsigned char *)&pResult,pResult.h.size);
	lpObj->Vitality += 30;
	lpObj->MaxLife = lpObj->VitalityToLife * 30;
	// energia
	pResult.result = 3;
	pResult.btStatValue = lpObj->Energy;
	pResult.btFruitType = 0;
	DataSend(lpObj->m_Index,(unsigned char *)&pResult,pResult.h.size);
	lpObj->Energy -= lpObj->Energy;
	pResult.result = 0;
	pResult.btStatValue = 30;
	pResult.btFruitType = 0;
	DataSend(lpObj->m_Index,(unsigned char *)&pResult,pResult.h.size);
	lpObj->Energy += 30;
	lpObj->MaxMana = lpObj->EnergyToMana * 30;
    // comando
	if(_reset_iniciar._r_struct->_comando[lpObj->vip] == 1)
	{
    pResult.result = 3;
    pResult.btStatValue = lpObj->Leadership;
    pResult.btFruitType = 4;
    DataSend(lpObj->m_Index,(unsigned char *)&pResult,pResult.h.size);
    lpObj->Leadership -= lpObj->Leadership;
    pResult.result = 0;
    pResult.btStatValue = 30;
    pResult.btFruitType = 4;
    DataSend(lpObj->m_Index,(unsigned char *)&pResult,pResult.h.size);
    lpObj->Leadership += 30;
	}
	GCReFillSend(lpObj->m_Index,lpObj->MaxLife + lpObj->AddLife,0xFE,0,lpObj->iMaxShield + lpObj->iAddShield);
	gObjSetBP(lpObj->m_Index);
	GCManaSend(lpObj->m_Index,lpObj->MaxMana + lpObj->AddMana,0xFE,0,lpObj->MaxBP + lpObj->AddBP);
}