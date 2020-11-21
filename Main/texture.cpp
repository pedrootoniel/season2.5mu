#include "stdafx.h"

_texture t[255];

int count;

void LoadTexture(char* filename)
{
	Tokenizer          token;
	TokenizerGroup     group;
	TokenizerSection   section;

	token.ParseFile(std::string(filename), group);

	if(group.GetSection(0, section))
	{
		for(int i = 0; i < section.RowCount; i++)
		{
			t[count].itemOP         = section.Rows[i].GetInt(0);
			t[count].itemC          = section.Rows[i].GetInt(1);
			t[count].ItemI          = section.Rows[i].GetInt(2);
			strcpy_s(t[count].item,  sizeof(t[count].item),  (section.Rows[i].GetStringPtr(3)));
			strcpy_s(t[count].patch, sizeof(t[count].patch), (section.Rows[i].GetStringPtr(4)));
			strcpy_s(t[count].ditem, sizeof(t[count].ditem), (section.Rows[i].GetStringPtr(5)));
			count++;
		}
	}
}

void texture()
{
	// original jewel of harmony
	TextureLoad(ITEM_GET(14,42),(char*)0x007A8720,(char*)0x007A871C,-1);

	for(int i = 0; i < count; i++)
	{
	    TextureLoad(ITEM_GET(t[i].itemC,t[i].ItemI),t[i].patch,t[i].item,t[i].itemOP);
		TextureCall(ITEM_GET(t[i].itemC,t[i].ItemI),t[i].ditem,0x2901,0x2600,1);
	}
}

__declspec(naked) void gObjTexture()
{

	_asm
	{
		call texture
	    mov edi, 0x006845A4
	    jmp edi
	}
}