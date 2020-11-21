#pragma once


struct SILVER
{
	DWORD ItemType;       
	DWORD ItemNr;       
	DWORD ItemLevel;
	DWORD ItemLuck;
	DWORD ItemSkill;
	DWORD ItemDur;       
	DWORD ItemOpt;       
	DWORD ItemExc;  
	DWORD ItemAnc;
};

class SILVER_CUSTOM
{
public:
	void LoadDropBox();
	bool LoadSettings();
	void Dropitem(int aIndex);
	DWORD SectionCount;
};

extern SILVER SilverBox[1000];

extern SILVER_CUSTOM SilverCustom;
