#include "StdAfx.h"

SILVER SilverBox[1000];

SILVER_CUSTOM SilverCustom;

void SILVER_CUSTOM::LoadDropBox()
{   
	LoadSettings();
}

bool SILVER_CUSTOM::LoadSettings()
{
	Tokenizer          token;
	TokenizerGroup     group;
	TokenizerSection   Section;

	token.ParseFile(std::string(CFG_BOX), group);

	if(group.GetSection(1, Section))
	{
		SilverCustom.SectionCount = Section.RowCount;

		for(int i = 0; i < Section.RowCount; i++)
		{
			SilverBox[i].ItemType = Section.Rows[i].GetInt(0);
			SilverBox[i].ItemNr	= Section.Rows[i].GetInt(1);
			SilverBox[i].ItemLevel = Section.Rows[i].GetInt(2);
			SilverBox[i].ItemLuck = Section.Rows[i].GetInt(3);
			SilverBox[i].ItemSkill = Section.Rows[i].GetInt(4);
			SilverBox[i].ItemDur	= Section.Rows[i].GetInt(5);
			SilverBox[i].ItemOpt = Section.Rows[i].GetInt(6);
			SilverBox[i].ItemExc = Section.Rows[i].GetInt(7);
			SilverBox[i].ItemAnc = Section.Rows[i].GetInt(8);
		}
	}

	return true;
}

void SILVER_CUSTOM::Dropitem(int aIndex)
{
	OBJECTSTRUCT* lpObj = (OBJECTSTRUCT*)(aIndex * OBJECT_SIZE + OBJECT_BASE);

	int itemSorteado = rand() % SilverCustom.SectionCount;

	DWORD Item = ITEMGET(SilverBox[itemSorteado].ItemType,SilverBox[itemSorteado].ItemNr);

	ItemSerialCreateSend(lpObj->m_Index,lpObj->MapNumber,lpObj->X,lpObj->Y,Item,SilverBox[itemSorteado].ItemLevel,SilverBox[itemSorteado].ItemDur,SilverBox[itemSorteado].ItemSkill,SilverBox[itemSorteado].ItemLuck,SilverBox[itemSorteado].ItemOpt,aIndex,SilverBox[itemSorteado].ItemExc,SilverBox[itemSorteado].ItemAnc);
}