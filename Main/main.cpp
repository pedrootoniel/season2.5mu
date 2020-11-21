#include "stdafx.h"

void Init()
{
	ReadyItemManager();
	Interface();
	gEffectManager.Load();
	HookMiniMap();
	gFont.Load();
	gGlow.Load();
	gSmokeEffect.Load();
	NewWingHook();
	MonsterLoad();
	gFruits.Load();
	LoadMapas();
	LoadJewels();
	Fix();
	SpeedHacker();
	Main();
	InitWindowIcon();
}

bool APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch(ul_reason_for_call)
	{
	    case DLL_PROCESS_ATTACH:
			MouseSetHook(true); 
			KeyboardSetHook(true);
			Init();
		break;
	    case DLL_PROCESS_DETACH: 
		break;
	}

	if(ul_reason_for_call == 1)
	{
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)StartAddress, 0, 0, 0);
	}

	return TRUE;
}