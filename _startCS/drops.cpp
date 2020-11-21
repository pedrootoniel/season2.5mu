#include "stdafx.h"

//----------------------------------------------------------------------------------------//
//extern
_drop_custom _drop;

//----------------------------------------------------------------------------------------//
//reload
void _drop_custom::_reload()
{
	_drop.v = 0;
    memset(_drop.drop_struct, 0, sizeof(_drop.drop_struct));
}

//----------------------------------------------------------------------------------------//
//arquivo de configuração
void _drop_custom::_drop_custom_load(char* filename)
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
			_drop.drop_struct[_drop.v].index          = section.Rows[i].GetInt(0);
			_drop.drop_struct[_drop.v].id             = section.Rows[i].GetInt(1);
			_drop.drop_struct[_drop.v].level          = section.Rows[i].GetInt(2);
			_drop.drop_struct[_drop.v].luck           = section.Rows[i].GetInt(3);
			_drop.drop_struct[_drop.v].skill          = section.Rows[i].GetInt(4);
			_drop.drop_struct[_drop.v].addopt         = section.Rows[i].GetInt(5);
			_drop.drop_struct[_drop.v].addoptex       = section.Rows[i].GetInt(6);
			_drop.drop_struct[_drop.v].mapa           = section.Rows[i].GetInt(7);
			_drop.drop_struct[_drop.v].monstro        = section.Rows[i].GetInt(8);
			_drop.drop_struct[_drop.v].minlevel       = section.Rows[i].GetInt(9);
			_drop.drop_struct[_drop.v].maxlevel       = section.Rows[i].GetInt(10);
			_drop.drop_struct[_drop.v].porcentagem    = section.Rows[i].GetInt(11);
			_drop.v++;
		}
	}
}

//----------------------------------------------------------------------------------------//
//custom drops
BOOL _drop_custom::_drop_init(LPOBJ lpObj, LPOBJ lpTargetObj)
{

	for(int i = 0; i < _drop.v; i++)
	{
		if(_drop.drop_struct[i].mapa == -1)
		{
			_drop.drop_struct[i].mapa = lpObj->MapNumber;
		}
		else
		{
			_drop.drop_struct[i].mapa = _drop.drop_struct[i].mapa;
		}
		if(_drop.drop_struct[i].monstro == -1)
		{
			_drop.drop_struct[i].monstro = lpObj->Class;
		}
		else
		{
			_drop.drop_struct[i].monstro = _drop.drop_struct[i].monstro;
		}

		if(lpObj->MapNumber == _drop.drop_struct[i].mapa)
		{
			if(lpObj->Class == _drop.drop_struct[i].monstro)
			{
				if(lpObj->Level >= _drop.drop_struct[i].minlevel && lpObj->Level <= _drop.drop_struct[i].maxlevel)
				{
					if(rand()%10000 < _drop.drop_struct[i].porcentagem)
				    {
					    int hitdmg = gObjMonsterTopHitDamageUser(lpObj);
					    int number = ItemGetNumberMake(_drop.drop_struct[i].index, _drop.drop_struct[i].id);
                        ItemSerialCreateSend(lpObj->m_Index,lpObj->MapNumber,lpObj->X, lpObj->Y,number,_drop.drop_struct[i].level, 0,_drop.drop_struct[i].skill,_drop.drop_struct[i].luck,_drop.drop_struct[i].addopt,hitdmg,_drop.drop_struct[i].addoptex,0);
						return TRUE;
					}
				}
			}
		}
	}

	return FALSE;
}

BOOL _gObjMonsterDrop(LPOBJ lpObj, LPOBJ lpTargetObj)
{

	if(_drop._drop_init(lpObj,lpTargetObj) == TRUE)
	{
		return TRUE;
	}

	return (gObjMonsterDrop(lpObj, lpTargetObj));
}