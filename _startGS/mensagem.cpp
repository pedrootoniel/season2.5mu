#include "stdafx.h"

//----------------------------------------------------------------------------------------//
_MENSAGEM_ALL _mensagem_all[255];

//----------------------------------------------------------------------------------------//
//reload
void _MENSAGEM_ALL::_reload()
{
   _mensagem_all->v = 0;
   memset(_mensagem_all, 0, sizeof(_mensagem_all));
}

//----------------------------------------------------------------------------------------//
//configuração
void _MENSAGEM_ALL::_mensagem_load(char * filename)
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

			_mensagem_all[_mensagem_all->v]._posicao    = section.Rows[i].GetInt(0);
			strcpy_s(_mensagem_all[_mensagem_all->v]._mensagem, sizeof(_mensagem_all[_mensagem_all->v]._mensagem), (section.Rows[i].GetStringPtr(1)));
			_mensagem_all[_mensagem_all->v]._tipo      = section.Rows[i].GetInt(2);
			_mensagem_all->v++;
		}
	}
}

//----------------------------------------------------------------------------------------//
//envio de mensagem
void _mensagem(int aIndex, unsigned char numero,int _default, DWORD * NpcIndex, char _npc_player)
{
	for(int i = 0; i < _mensagem_all->v; i++)
	{
		if(_mensagem_all[i]._posicao == numero)
		{
			char mensagem[255];
			wsprintf(mensagem,_mensagem_all[i]._mensagem,_default);
			if(_npc_player == 0)
			{
			   GCServerMsgStringSend(mensagem,aIndex,_mensagem_all[i]._tipo);
			}
			else
			{
			   ChatTargetSend(NpcIndex,mensagem,aIndex);
			}
		}
	}
}

void message(int index, int numero, int x)
{
	for(int i = 0; i < _mensagem_all->v; i++)
	{
		if(_mensagem_all[i]._posicao == numero)
		{
			char message[255];
			wsprintf(message,_mensagem_all[i]._mensagem,x);
			GCServerMsgStringSend(message,index,(BYTE)_mensagem_all[i]._tipo);
		}
	}
}