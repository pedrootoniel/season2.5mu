#include "stdafx.h"

struct CameraStruct 
{
	float Zoom;
	float RotY;
	float RotZ;
	float PosZ;
	float ClipX;
	float ClipY;
	float GlClip;
} Camera;

bool Enable;

float *Camera_Zoom    = (float*) 0x006B20D0;//006B1490
float *Camera_RotY    = (float*) 0x007858B8;//007838B8
float *Camera_RotZ    = (float*) 0x07E80758;//07E7E350
float *Camera_PosZ    = (float*) 0x00783720;//00781720
float *Camera_ClipX   = (float*) 0x007857D4;//007837D4
float *Camera_ClipY   = (float*) 0x0065F837;//0065EA54
float *Camera_GlClip  = (float*) 0x006B2373;//006B1733



int MouseX; 
int MouseY; 

bool InitCamera = true; 
bool MoveCamera = false;

bool SWITCH_CAMERA = true;

#define RETURN (*Camera_PosZ != 150.0f || *Camera_RotZ != -45.0f || *Camera_RotY != -48.5f || *Camera_Zoom != 35.0f)

void RetCamPos(void *lpParam)
{
	while (RETURN)
	{
		(*Camera_PosZ > 150.0f) ? *Camera_PosZ -= 5.0f : *Camera_PosZ += 5.0f;
		if(*Camera_PosZ > 146.0f && *Camera_PosZ < 152.0f)
			*Camera_PosZ = 150.0f;
		(*Camera_RotZ > -45.0f) ? *Camera_RotZ -= 1.0f : *Camera_RotZ += 1.0f;
		if(*Camera_RotZ > -47.0f && *Camera_RotZ < -43.0f)
			*Camera_RotZ = -45.0f;
		(*Camera_RotY > -48.5f) ? *Camera_RotY -= 0.5f : *Camera_RotY += 0.5f;
		if(*Camera_RotY > -50.5f && *Camera_RotY < -46.5f)
			*Camera_RotY = -48.5f; 
		(*Camera_Zoom > 35.0f) ? *Camera_Zoom -= 1.0f : *Camera_Zoom += 1.0f;
		if(*Camera_Zoom > 33.0f && *Camera_Zoom < 37.0f)
			*Camera_Zoom = 35.0f;
		Sleep(10);
	}
	_endthread();
} 

BOOL KeyboardSetHook(BOOL set_or_remove)
{
	if(set_or_remove == TRUE)
	{
		if(KeyboardHook == NULL)
		{
			KeyboardHook = SetWindowsHookEx(WH_KEYBOARD, (HOOKPROC)KeyboardProc, hInstance, GetCurrentThreadId());
			if(!KeyboardHook)
			{
				return FALSE; 
			}
		}
	}
	else
	{
		return UnhookWindowsHookEx(KeyboardHook);
		KeyboardHook = NULL;
	}

	return TRUE;
}

BOOL MouseSetHook(BOOL set_or_remove)
{
	if(set_or_remove == TRUE)
	{
		if(MouseHook == NULL)
		{
			MouseHook = SetWindowsHookEx(WH_MOUSE, (HOOKPROC)MouseProc, hInstance, GetCurrentThreadId());
			if(!MouseHook)
			{ 
				return FALSE; 
			}
		}
	} 
	else 
	{ 
		return UnhookWindowsHookEx(MouseHook); 
	}

	return TRUE;
}

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{        
	if(wParam == VK_HOME) 
	{
		if (!Enable)
		{
			Enable = 1;
			if (SWITCH_CAMERA == true) 
			{
				_beginthread(RetCamPos, 0, NULL);
			}
			SWITCH_CAMERA = false;
		}
		else
		{
			Enable = 0; 
			SWITCH_CAMERA = true;
		}
	}

	if(wParam == VK_F8) 
	{
		gEffectManager.Load();
		gGlow.Load();
		gSmokeEffect.Load();	
	}

	return CallNextHookEx(KeyboardHook, nCode, wParam, lParam);
}

LRESULT CALLBACK MouseProc(int code, WPARAM wParam, LPARAM lParam)
{
	MOUSEHOOKSTRUCTEX* mhs = (MOUSEHOOKSTRUCTEX*)lParam;

	HWND MuWnd = FindWindow(gConfig.SystemTitle, NULL);

	if(SWITCH_CAMERA)
	{
		if(GetForegroundWindow() == MuWnd)
		{ 
			if(InitCamera) 
			{ 
				Camera.ClipX  = *Camera_ClipX;
				Camera.ClipY  = *Camera_ClipY;
				Camera.GlClip = *Camera_GlClip;
				Camera.PosZ   = *Camera_PosZ;
				Camera.RotY   = *Camera_RotY;
				Camera.RotZ   = *Camera_RotZ;
				Camera.Zoom   = *Camera_Zoom;
				InitCamera = false; 
			}

			if(wParam == WM_MOUSEWHEEL) 
			{
				int direction = mhs->mouseData;
				if(direction > 0)
				{
					if(*Camera_Zoom < 60) 
					{

						*Camera_Zoom += 2; 
					}
				}
				else if(direction < 0)
				{
					if(*Camera_Zoom > 12) 
					{
						*Camera_Zoom -= 2; 
					}
				}

				*Camera_ClipX  = 1190 + (abs(*Camera_PosZ - 150) * 3) + 4000;
				*Camera_ClipY  = 2400 + (abs(*Camera_PosZ - 150) * 3) + 4000;
				*Camera_GlClip = 4000 + (abs(*Camera_PosZ - 150) * 3) + 1500; 
			}
			else if (wParam == WM_MBUTTONDOWN) 
			{
				MouseX = mhs->pt.x; 
				MouseY = mhs->pt.y; 
				MoveCamera = true;
			}
			else if(wParam == WM_MBUTTONUP)
			{
				MoveCamera = false;
			}		
			else if(wParam == WM_MOUSEMOVE)
			{
				if(MoveCamera)
				{
					if(MouseX < mhs->pt.x)
					{
						*Camera_RotZ += 5;

						if(*Camera_RotZ > 315) 
						{
							*Camera_RotZ = -45;
						}
					}
					else if(MouseX > mhs->pt.x)
					{
						*Camera_RotZ -= 5;
						if(*Camera_RotZ < -405) 
						{
							*Camera_RotZ = -45;
						}
					}
					if(MouseY < mhs->pt.y)
					{
						if(*Camera_RotY < -45)
						{	
							*Camera_PosZ -= 44;
							*Camera_RotY += (float)2.42;
						}
					}
					else if(MouseY > mhs->pt.y)
					{
						if(*Camera_RotY > -90)
						{
							*Camera_PosZ += 44;
							*Camera_RotY -= (float)2.42;
						}
					}

					MouseX = mhs->pt.x;
					MouseY = mhs->pt.y;

					*Camera_ClipX  = 1190 + (abs(*Camera_PosZ - 150) * 3) + 4000; 
					*Camera_ClipY  = 2400 + (abs(*Camera_PosZ - 150) * 3) + 4000; 
					*Camera_GlClip = 4000 + (abs(*Camera_PosZ - 150) * 3) + 1500; 
				}
			}
		}
	}

	return CallNextHookEx(MouseHook, code, wParam, lParam);
}