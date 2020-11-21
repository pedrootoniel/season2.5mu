#include "StdAfx.h"

BRONZE BronzeBox[1000];

BRONZE_CUSTOM BronzeCustom;

void BRONZE_CUSTOM::LoadDropBox()
{   
	LoadSettings();
}

bool BRONZE_CUSTOM::LoadSettings()
{
	Tokenizer          token;
	TokenizerGroup     group;
	TokenizerSection   Section;

	token.ParseFile(std::string(CFG_BOX), group);

	if(group.GetSection(0, Section))
	{
		BronzeCustom.SectionCount = Section.RowCount;

		for(int i = 0; i < Section.RowCount; i++)
		{
			BronzeBox[i].ItemType = Section.Rows[i].GetInt(0);
			BronzeBox[i].ItemNr	= Section.Rows[i].GetInt(1);
			BronzeBox[i].ItemLevel = Section.Rows[i].GetInt(2);
			BronzeBox[i].ItemLuck = Section.Rows[i].GetInt(3);
			BronzeBox[i].ItemSkill = Section.Rows[i].GetInt(4);
			BronzeBox[i].ItemDur	= Section.Rows[i].GetInt(5);
			BronzeBox[i].ItemOpt = Section.Rows[i].GetInt(6);
			BronzeBox[i].ItemExc = Section.Rows[i].GetInt(7);
			BronzeBox[i].ItemAnc = Section.Rows[i].GetInt(8);
		}
	}

	return true;
}

void BRONZE_CUSTOM::Dropitem(int aIndex)
{
	OBJECTSTRUCT* lpObj = (OBJECTSTRUCT*)(aIndex * OBJECT_SIZE + OBJECT_BASE);

	int itemSorteado = rand() % BronzeCustom.SectionCount;

	DWORD Item = ITEMGET(BronzeBox[itemSorteado].ItemType,BronzeBox[itemSorteado].ItemNr);

	ItemSerialCreateSend(lpObj->m_Index,lpObj->MapNumber,lpObj->X,lpObj->Y,Item,BronzeBox[itemSorteado].ItemLevel,BronzeBox[itemSorteado].ItemDur,BronzeBox[itemSorteado].ItemSkill,BronzeBox[itemSorteado].ItemLuck,BronzeBox[itemSorteado].ItemOpt,aIndex,BronzeBox[itemSorteado].ItemExc,BronzeBox[itemSorteado].ItemAnc);
}