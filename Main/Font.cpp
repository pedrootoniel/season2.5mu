#include "stdafx.h"

//---------------------------------------------------------------------------
Font gFont;
//---------------------------------------------------------------------------
char MyFontFaceName[100];
char sValue[99];
//--
int Bold		= GetPrivateProfileIntA("Font", "Main_Font_Bold", 1,CONFIG_MAIN_FILE);
int Height		= GetPrivateProfileIntA("Font", "Main_Font_Height", 13, CONFIG_MAIN_FILE);
int Italic		= GetPrivateProfileIntA("Font", "Main_Font_Italic", 0, CONFIG_MAIN_FILE);
int Unicode		= GetPrivateProfileIntA("Font", "Main_Font_Unicode", 1, CONFIG_MAIN_FILE);
//--
int Width		= GetPrivateProfileIntA("Font", "Main_Font_Width", 0, CONFIG_MAIN_FILE);
int UnderLine	= GetPrivateProfileIntA("Font", "Main_Font_Underline", 0, CONFIG_MAIN_FILE);
int Quality		= GetPrivateProfileIntA("Font", "Main_Font_Quality", 3, CONFIG_MAIN_FILE);
int StrikeOut	= GetPrivateProfileIntA("Font", "Main_Font_StrikeOut", 0, CONFIG_MAIN_FILE);
//---------------------------------------------------------------------------
void Font::Load()
{
	GetPrivateProfileStringA("Font", "Main_Font_Name", "Georgia", MyFontFaceName, 100, CONFIG_MAIN_FILE);

	SetCompleteHook(0xE8, Offset_CreateFontA1, &Font::LoadFont);
	SetCompleteHook(0xE8, Offset_CreateFontA2, &Font::LoadFont);
	SetCompleteHook(0xE8, Offset_CreateFontA3, &Font::LoadFont);
	SetCompleteHook(0xE8, Offset_CreateFontA4, &Font::LoadFont);
	SetCompleteHook(0xE8, Offset_CreateFontA5, &Font::LoadFont);
	//--
	SetByte((PVOID)(Offset_CreateFontA1 + 5), 0x90);
	SetByte((PVOID)(Offset_CreateFontA2 + 5), 0x90);
	SetByte((PVOID)(Offset_CreateFontA3 + 5), 0x90);
	SetByte((PVOID)(Offset_CreateFontA4 + 5), 0x90);
	SetByte((PVOID)(Offset_CreateFontA5 + 5), 0x90);
}
//---------------------------------------------------------------------------
HFONT Font::LoadFont()
{
	HFONT MyFont;
	//--
	if (Bold == 0)
	{
		if (Unicode == 1)
		{
			MyFont = CreateFontA(Height, Width, 0, 0, 400, Italic, UnderLine, StrikeOut, 0x01, 0, 0, Quality, 0, MyFontFaceName);
		}
		else
		{
			MyFont = CreateFontA(Height, Width, 0, 0, 400, Italic, UnderLine, StrikeOut, 0x0, 0, 0, Quality, 0, MyFontFaceName);
		}
	}
	else
	{
		if (Unicode == 1)
		{
			MyFont = CreateFontA(Height, Width, 0, 0, 700, Italic, UnderLine, StrikeOut, 0x01, 0, 0, Quality, 0, MyFontFaceName);
		}
		else
		{
			MyFont = CreateFontA(Height, Width, 0, 0, 700, Italic, UnderLine, StrikeOut, 0x0, 0, 0, Quality, 0, MyFontFaceName);
		}
	}

	return MyFont;
}