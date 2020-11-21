#include "stdafx.h"

//----------------------------------------------------------------------------------------//
_npc_talking _npc;

//----------------------------------------------------------------------------------------//
//extern
void _npc_talking::_reload()
{
	_npc.v = 0;
    memset(_npc.npc, 0, sizeof(_npc.npc));
}

void _npc_talking::loadfile(char* filename)
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
			_npc.npc[_npc.v].classe  = section.Rows[i].GetInt(0);
			_npc.npc[_npc.v].mapa    = section.Rows[i].GetInt(1);
			_npc.npc[_npc.v].x       = section.Rows[i].GetInt(2);
			_npc.npc[_npc.v].y       = section.Rows[i].GetInt(3);
			_npc.npc[_npc.v].tipo    = section.Rows[i].GetInt(4);
			_npc.v++;

		}
	}
}

//----------------------------------------------------------------------------------------//
//hook
BOOL _NpcTalk(LPOBJ lpNpc, LPOBJ lpObj)
{
	for(int i = 0; i < _npc.v; i++)
	{
		if(lpNpc->Class == _npc.npc[i].classe && lpNpc->MapNumber == _npc.npc[i].mapa && lpNpc->X == _npc.npc[i].x && lpNpc->Y == _npc.npc[i].y)
		{
			if(_npc.npc[i].tipo == 0) // pkclear
			{
				_iniciar_comandos._comando_pkclear(lpObj,1,(DWORD*)&lpNpc->m_Index);
			}
			if(_npc.npc[i].tipo == 1) // reset
			{
				_reset_iniciar._reset_init(lpObj,(DWORD*)&lpNpc->m_Index,0);
			}
		}
	}

	return NpcTalk(lpNpc, lpObj);
}