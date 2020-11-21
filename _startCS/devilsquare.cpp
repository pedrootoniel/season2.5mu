#include "stdafx.h"

//----------------------------------------------------------------------------------------//
_devil_square _devil;

//----------------------------------------------------------------------------------------//
//reload
void _devil_square::_reload()
{
   for(int i = 0; i < 7; i++)
   {
       _devil.devil[i] = 0;
   }
   memset(_devil.drop, 0, sizeof(_devil.drop));
}

//----------------------------------------------------------------------------------------//
//configuração
void _devil_square::_iniciar_devil_square(char * filename)
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
			_devil.drop[_devil.devil[0]].index[0]         = section.Rows[i].GetInt(0);
			_devil.drop[_devil.devil[0]].id[0]            = section.Rows[i].GetInt(1);
			_devil.drop[_devil.devil[0]].level[0]         = section.Rows[i].GetInt(2);
			_devil.drop[_devil.devil[0]].skill[0]         = section.Rows[i].GetInt(3);
			_devil.drop[_devil.devil[0]].luck[0]          = section.Rows[i].GetInt(4);
			_devil.drop[_devil.devil[0]].addopt[0]        = section.Rows[i].GetInt(5);
			_devil.drop[_devil.devil[0]].addoptex[0]      = section.Rows[i].GetInt(6);
			_devil.devil[0]++;
		}
	}

	if(group.GetSection(1, section))
	{
		for(int i = 0; i < section.RowCount; i++)
		{
			_devil.drop[_devil.devil[1]].index[1]         = section.Rows[i].GetInt(0);
			_devil.drop[_devil.devil[1]].id[1]            = section.Rows[i].GetInt(1);
			_devil.drop[_devil.devil[1]].level[1]         = section.Rows[i].GetInt(2);
			_devil.drop[_devil.devil[1]].skill[1]         = section.Rows[i].GetInt(3);
			_devil.drop[_devil.devil[1]].luck[1]          = section.Rows[i].GetInt(4);
			_devil.drop[_devil.devil[1]].addopt[1]        = section.Rows[i].GetInt(5);
			_devil.drop[_devil.devil[1]].addoptex[1]      = section.Rows[i].GetInt(6);
			_devil.devil[1]++;
		}
	}

	if(group.GetSection(2, section))
	{
		for(int i = 0; i < section.RowCount; i++)
		{
			_devil.drop[_devil.devil[2]].index[2]         = section.Rows[i].GetInt(0);
			_devil.drop[_devil.devil[2]].id[2]            = section.Rows[i].GetInt(1);
			_devil.drop[_devil.devil[2]].level[2]         = section.Rows[i].GetInt(2);
			_devil.drop[_devil.devil[2]].skill[2]         = section.Rows[i].GetInt(3);
			_devil.drop[_devil.devil[2]].luck[2]          = section.Rows[i].GetInt(4);
			_devil.drop[_devil.devil[2]].addopt[2]        = section.Rows[i].GetInt(5);
			_devil.drop[_devil.devil[2]].addoptex[2]      = section.Rows[i].GetInt(6);
			_devil.devil[2]++;
		}
	}

	if(group.GetSection(3, section))
	{
		for(int i = 0; i < section.RowCount; i++)
		{
			_devil.drop[_devil.devil[3]].index[3]         = section.Rows[i].GetInt(0);
			_devil.drop[_devil.devil[3]].id[3]            = section.Rows[i].GetInt(1);
			_devil.drop[_devil.devil[3]].level[3]         = section.Rows[i].GetInt(2);
			_devil.drop[_devil.devil[3]].skill[3]         = section.Rows[i].GetInt(3);
			_devil.drop[_devil.devil[3]].luck[3]          = section.Rows[i].GetInt(4);
			_devil.drop[_devil.devil[3]].addopt[3]        = section.Rows[i].GetInt(5);
			_devil.drop[_devil.devil[3]].addoptex[3]      = section.Rows[i].GetInt(6);
			_devil.devil[3]++;
		}
	}

	if(group.GetSection(4, section))
	{
		for(int i = 0; i < section.RowCount; i++)
		{
			_devil.drop[_devil.devil[4]].index[4]         = section.Rows[i].GetInt(0);
			_devil.drop[_devil.devil[4]].id[4]            = section.Rows[i].GetInt(1);
			_devil.drop[_devil.devil[4]].level[4]         = section.Rows[i].GetInt(2);
			_devil.drop[_devil.devil[4]].skill[4]         = section.Rows[i].GetInt(3);
			_devil.drop[_devil.devil[4]].luck[4]          = section.Rows[i].GetInt(4);
			_devil.drop[_devil.devil[4]].addopt[4]        = section.Rows[i].GetInt(5);
			_devil.drop[_devil.devil[4]].addoptex[4]      = section.Rows[i].GetInt(6);
			_devil.devil[4]++;
		}
	}

	if(group.GetSection(5, section))
	{
		for(int i = 0; i < section.RowCount; i++)
		{
			_devil.drop[_devil.devil[5]].index[5]         = section.Rows[i].GetInt(0);
			_devil.drop[_devil.devil[5]].id[5]            = section.Rows[i].GetInt(1);
			_devil.drop[_devil.devil[5]].level[5]         = section.Rows[i].GetInt(2);
			_devil.drop[_devil.devil[5]].skill[5]         = section.Rows[i].GetInt(3);
			_devil.drop[_devil.devil[5]].luck[5]          = section.Rows[i].GetInt(4);
			_devil.drop[_devil.devil[5]].addopt[5]        = section.Rows[i].GetInt(5);
			_devil.drop[_devil.devil[5]].addoptex[5]      = section.Rows[i].GetInt(6);
			_devil.devil[5]++;
		}
	}
	
}

//----------------------------------------------------------------------------------------//
//função de drops
void _devil_square::_devil_drop(LPOBJ lpObj, char vector)
{
	for(int i = 0; i < _devil.devil[vector]; i++)
	{
		int item = ::ItemGetNumberMake(_devil.drop[i].index[vector],_devil.drop[i].id[vector]);
		ItemSerialCreateSend(lpObj->m_Index,lpObj->MapNumber,lpObj->X,lpObj->Y,item,_devil.drop[i].level[vector],0,_devil.drop[i].skill[vector],_devil.drop[i].luck[vector],_devil.drop[i].addopt[vector],lpObj->m_Index,_devil.drop[i].addoptex[vector],0);
	}
}

//----------------------------------------------------------------------------------------//
//função original modificada
void _devil_square_original(LPOBJ lpObj)
{

	switch(lpObj->m_bDevilSquareIndex)
	{
	case 0:
		_devil._devil_drop(lpObj,0);
		break;
	case 1:
		_devil._devil_drop(lpObj,1);
		break;
	case 2:
		_devil._devil_drop(lpObj,2);
		break;
	case 3:
		_devil._devil_drop(lpObj,3);
		break;
	case 4:
		_devil._devil_drop(lpObj,4);
		break;
	case 5:
		_devil._devil_drop(lpObj,5);
		break;
	default:
		break;
	}
}

//----------------------------------------------------------------------------------------//
//hook na função original asm
__declspec(naked) void _devil_square_hook()
{
	_asm
	{
		MOV  EAX,DWORD PTR SS:[EBP+8] // LPOBJ
		PUSH EAX
		CALL _devil_square_original
		MOV  BYTE PTR SS:[EBP-0x2C],0x0C1
        MOV  BYTE PTR SS:[EBP-0x2A],1
		MOV  EDI, 0x00467E62
		JMP  EDI
	}
}