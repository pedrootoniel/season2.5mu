#include "stdafx.h"

commandS cmds;

void moveS::load()
{
    this->count = 0;
    memset(cmds.movesarray, 0, sizeof(cmds.movesarray));

	Tokenizer          token;
	TokenizerGroup     group;
	TokenizerSection   section;

	token.ParseFile(std::string(".\\configurações\\_administrador.settings\\_settings.move.ID"), group);

	if(group.GetSection(0, section))
	{
		for(int i = 0; i < section.RowCount; i++)
		{
			strcpy_s(cmds.movesarray[this->count].string, sizeof(cmds.movesarray[this->count].string), (section.Rows[i].GetStringPtr(0)) );
			cmds.movesarray[this->count].vip       = section.Rows[i].GetInt(1);
			cmds.movesarray[this->count].map       = section.Rows[i].GetInt(2);
			cmds.movesarray[this->count].cordx     = section.Rows[i].GetInt(3);
			cmds.movesarray[this->count].cordy     = section.Rows[i].GetInt(4);
			cmds.movesarray[this->count].level     = section.Rows[i].GetInt(5);
			cmds.movesarray[this->count].pk        = section.Rows[i].GetInt(6);
			this->count++;
		}
	}
}

void commandS::load()
{
	this->moves.load();
}

void commandS::movestart(LPOBJ lpObj, char vip, char pk, short level, short map, short x, short y)
{
	if(lpObj->Level < level)
	{
		message(lpObj->m_Index,99,0);
		return;
	}
	if(lpObj->vip < vip)
	{
		message(lpObj->m_Index,100,0);
		return;
	}
	if(pk == 1)
	{
	    if(lpObj->m_PK_Level > 3)
	    {
			message(lpObj->m_Index,101,0);
			return;
	    }
	}
	if(lpObj->m_IfState.use == 1)
	{
		return;
	}
	if(lpObj->m_bPShopOpen == true)
	{
		return;
	}

	gObjTeleport(lpObj->m_Index,map,x,y);
}

void commandS::ChatProto(LPBYTE aRecv, int aIndex)
{
	OBJECTSTRUCT* player = (OBJECTSTRUCT*)GS_GOBJPOINTER(aIndex);

	for(int i = 0; i <  this->moves.count; i++)
	{
		if(!memicmp(&aRecv[13],this->movesarray[i].string,strlen(this->movesarray[i].string)))
		{
			this->movestart(player,this->movesarray[i].vip,this->movesarray[i].pk,this->movesarray[i].level,this->movesarray[i].map,this->movesarray[i].cordx,this->movesarray[i].cordy);
		}
	}

}