#ifndef _EFFECT_MANAGER_H
#define _EFFECT_MANAGER_H

#define pAllowStaticEffect		((void(__thiscall*)(DWORD *a1, DWORD *a2, float *a3, vec3_t *VecPos, char a5)) 0x50ACF9) // ok
#define pPlayDynamicEffect		((int(__cdecl*)(DWORD ModelID, DWORD * Arg1, int Arg2, float * Color, int Arg4, float Arg5, int Arg6)) 0x56FCA1) //ok
#define pPlayStaticEffect		((int(__cdecl*)(DWORD ModelID, __int16 a2, int a3, int a4, float *a5, int a6)) 0x525042) //ok
#define pDrawItemEffect			((void(__cdecl*)(int lpModel, int ItemModel, int a3, GLfloat alpha, int a5, int a6, int a7, int a8, int a9)) 0x6798B2) //ok

#define MAX_CUSTOM_EFFECT 3000

struct EFFECT_INFO	
{
	int ItemIndex;
	int EffectStaticIndex;
	int EffectDynamicIndex;
	int EffectBone;

	float Color[3];

	float EffectStaticSize;
	float EffectDynamicSize;
};

class CEffectManager
{
public:
	void Load();
	// ---
	static void EffectItem();
	// ---
	int Count;
	// ---
	EFFECT_INFO m_EffectInfo[MAX_CUSTOM_EFFECT];

	static void DrawItemEffect(int lpModel, int ItemModel, int a3, GLfloat alpha, int a5, int a6, int a7, int a8, int a9);
};

extern CEffectManager gEffectManager;

void ReadyEfect();

#endif