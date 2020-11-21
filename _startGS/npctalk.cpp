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
			_npc.npc[_npc.v].pos	 = section.Rows[i].GetInt(4);
			_npc.npc[_npc.v].tipo    = section.Rows[i].GetInt(5);
			_npc.npc[_npc.v].countdel = gObjInsertMonster(_npc.npc[_npc.v].mapa,_npc.npc[_npc.v].x,_npc.npc[_npc.v].y,_npc.npc[_npc.v].classe,_npc.npc[_npc.v].pos,3);
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
			if(_npc.npc[i].tipo == 2) // move
			{
				_move_jewel(lpObj,(DWORD*)&lpNpc->m_Index,0);
			}
		}
	}
	return NpcTalk(lpNpc, lpObj);
}

void gObjGameMonsterAllAdd()
{
	GameMonsterAllAdd();
	_npc.loadfile(".\\configurações\\_administrador.settings\\_settings.npc.ID");
}

short gObjInsertMonster(int Map, int X, int Y, int Class, int Dir, int Type)
{
	short npc = gObjAddMonster(Map);

	if(npc == -1)
	{
		return -1;
	}

	gObjSetMonster(npc, Class);

	OBJECTSTRUCT* lpObj = (OBJECTSTRUCT*)GS_GOBJPOINTER(npc);

	lpObj->Type		 = Type;
	lpObj->X		     = X;
	lpObj->Y		     = Y;
	lpObj->MapNumber = Map;
	lpObj->TX		 = lpObj->X;
	lpObj->TY		 = lpObj->Y;
	lpObj->m_OldX	 = lpObj->X;
	lpObj->m_OldY	 = lpObj->Y;
	lpObj->Dir		 = Dir;
	lpObj->StartX	 = (unsigned char)lpObj->X;
	lpObj->StartY	 = (unsigned char)lpObj->Y;

	if(Type == 3)
	{
		lpObj->m_MoveRange   = 0;
		lpObj->m_AttackRange = 0;
	}

	return npc;
}
