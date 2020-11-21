#pragma once


struct BRONZE
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

class BRONZE_CUSTOM
{
public:
	void LoadDropBox();
	bool LoadSettings();
	void Dropitem(int aIndex);
	DWORD SectionCount;
};

extern BRONZE BronzeBox[1000];

extern BRONZE_CUSTOM BronzeCustom;

#define CFG_BOX			"./configurações/_administrador.settings/_settings.box.ID"