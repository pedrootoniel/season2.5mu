#pragma once


struct GOLDEN
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

class GOLDEN_CUSTOM
{
public:
	void LoadDropBox();
	bool LoadSettings();
	void Dropitem(int aIndex);
	DWORD SectionCount;
};

extern GOLDEN GoldenBox[1000];

extern GOLDEN_CUSTOM GoldenCustom;