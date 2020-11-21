#include "StdAfx.h"

GOLDEN GoldenBox[1000];

GOLDEN_CUSTOM GoldenCustom;

void GOLDEN_CUSTOM::LoadDropBox()
{   
	LoadSettings();
}

bool GOLDEN_CUSTOM::LoadSettings()
{
	Tokenizer          token;
	TokenizerGroup     group;
	TokenizerSection   Section;

	token.ParseFile(std::string(CFG_BOX), group);

	if(group.GetSection(2, Section))
	{
		GoldenCustom.SectionCount = Section.RowCount;

		for(int i = 0; i < Section.RowCount; i++)
		{
			GoldenBox[i].ItemType = Section.Rows[i].GetInt(0);
			GoldenBox[i].ItemNr	= Section.Rows[i].GetInt(1);
			GoldenBox[i].ItemLevel = Section.Rows[i].GetInt(2);
			GoldenBox[i].ItemLuck = Section.Rows[i].GetInt(3);
			GoldenBox[i].ItemSkill = Section.Rows[i].GetInt(4);
			GoldenBox[i].ItemDur	= Section.Rows[i].GetInt(5);
			GoldenBox[i].ItemOpt = Section.Rows[i].GetInt(6);
			GoldenBox[i].ItemExc = Section.Rows[i].GetInt(7);
			GoldenBox[i].ItemAnc = Section.Rows[i].GetInt(8);
		}
	}

	return true;
}

void GOLDEN_CUSTOM::Dropitem(int aIndex)
{
	OBJECTSTRUCT* lpObj = (OBJECTSTRUCT*)(aIndex * OBJECT_SIZE + OBJECT_BASE);

	int itemSorteado = rand() % GoldenCustom.SectionCount;

	DWORD Item = ITEMGET(GoldenBox[itemSorteado].ItemType,GoldenBox[itemSorteado].ItemNr);
	
	ItemSerialCreateSend(lpObj->m_Index,lpObj->MapNumber,lpObj->X, lpObj->Y,Item,GoldenBox[itemSorteado].ItemLevel,GoldenBox[itemSorteado].ItemDur,GoldenBox[itemSorteado].ItemSkill,GoldenBox[itemSorteado].ItemLuck,GoldenBox[itemSorteado].ItemOpt,aIndex,GoldenBox[itemSorteado].ItemExc,GoldenBox[itemSorteado].ItemAnc);
}