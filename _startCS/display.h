#pragma once

class cDisplay
{
public:
	cDisplay();
	~cDisplay();

public:
	static void ViewPaint(HWND hWnd, short aIndex);
	static void LogTextPaintProcEx(HWND hWnd);
	static void LogTextAddEx(BYTE type, char *msg, int len);

private:
	HFONT  Font;
	HBRUSH Background;
	int    m_cline;	                                       
	char   LogText[30][180];
	short  LogTextLength[30];
	BYTE   LogTextViewType[30];
};

extern cDisplay Display;
