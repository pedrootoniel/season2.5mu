#include "stdafx.h"

HANDLE PluginModule;



HWND CreateMyWindow(DWORD dwExStyle, LPSTR lpClassName, LPSTR lpWindowName, DWORD dwStyle, int x, int y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam)
{
	RECT rect;
	// ---
	GetClientRect((HWND)GetDesktopWindow(), &rect);
	// ---
	rect.left = (rect.right/2) - (GAMESERVER_WIDTH/2);
	rect.top = (rect.bottom/2) - (GAMESERVER_HEIGHT/2);
	// ---
	return CreateWindowEx(dwExStyle,lpClassName,lpWindowName,WS_OVERLAPPED+WS_CAPTION+WS_SYSMENU+WS_MINIMIZEBOX+WS_VISIBLE,rect.left,rect.top,GAMESERVER_WIDTH,GAMESERVER_HEIGHT,hWndParent,hMenu,hInstance,lpParam);
}

void ReadCreateWindow()
{

	SetRange((LPVOID)0x005411FA,6,ASM::NOP);
	SetOp((LPVOID)0x005411FA,(LPVOID)CreateMyWindow,ASM::CALL); 
	*(BYTE*)(0x00540B5A+1) = 0xE9;
}

//----------------------------------------------------------------------------------------//
extern "C" _declspec(dllexport) void dllinit() // entry point
{
	DWORD OldProtect;
	if(VirtualProtect(LPVOID(0x401000),3543191,PAGE_EXECUTE_READWRITE,&OldProtect))
	{
		//----------- inicia serviços
		//ReadCreateWindow();
		iniciar_dll.iniciar_func();
	}

}



bool APIENTRY DllMain(HMODULE hModule,  DWORD  ul_reason_for_call, LPVOID lpReserved)
{

	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		PluginModule = hModule;
		dllinit();
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}

	if(ul_reason_for_call == 1)
	{
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)StartAddress, 0, 0, 0);
	}
	return TRUE;
}