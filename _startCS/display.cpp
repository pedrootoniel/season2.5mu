#include "stdafx.h"

char * TitleText[1] =
{
	" ]+[ SupremoTeam ]+[ "
};

cDisplay::cDisplay()
{
	this->Font = CreateFontA(80, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, 5, DEFAULT_PITCH | FF_DONTCARE, "Times New Roman");
	this->Background = CreateSolidBrush(RGB(0,0,0));
}

cDisplay::~cDisplay()
{
	DeleteObject(this->Font);
	DeleteObject(this->Background);
}

void cDisplay::ViewPaint(HWND hWnd, short aIndex)
{
	char Buffer[256];

	int iMonsterCount = 0;
	int iFreeCount = 0;
	int Staffers = 0;
	int iTotalCount = 0;
	
	for (int i = 0; i < OBJECT_MAX; i++)
	{
		OBJECTSTRUCT * lpObj = (OBJECTSTRUCT*)OBJECT_POINTER(i);

		if (i < OBJECT_MIN)
		{
			if (lpObj->Type != OBJ_USER && lpObj->Connected == 3)
			{
				iMonsterCount++;
			}
		}
		else
		{
			if (lpObj->Type == OBJ_USER && lpObj->Connected == 3)
			{
				if(lpObj->Type == OBJ_USER && lpObj->Authority == 1)
				{
					iFreeCount++;
				}
				if (lpObj->Authority > 1)
				{
					Staffers++;
				}

				iTotalCount++;
			}
		}
	}

	igObjTotalUser = iTotalCount;

	wsprintf(Buffer,"- Mob's: %d - User's: %d  -  GM's: %d  -  Total On: [ %d - %d ] -", iMonsterCount,iFreeCount,Staffers,iTotalCount,iServerMaxUser);
	
	RECT rect;
	HDC hDC = GetDC(hWnd);
	int OldBkMode = SetBkMode(hDC, TRANSPARENT);
	
	GetClientRect(hWnd, &rect);
	
	rect.top = 50;
	rect.bottom = 100;

	SetTextColor(hDC,RGB(0, 0, 0));
	TextOut(hDC,60,0,Buffer,strlen(Buffer));
	FillRect(hDC, &rect, Display.Background);

	HFONT pOldFont = (HFONT)SelectObject(hDC, Display.Font);

	SetTextColor(hDC, RGB(250, 250, 250));
	TextOutA(hDC, 250, 18, TitleText[0], strlen(TitleText[0]));
	SelectObject(hDC, pOldFont);
	SetBkMode(hDC, OldBkMode);
	ReleaseDC(hWnd, hDC);
}

void cDisplay::LogTextPaintProcEx(HWND hWnd)
{
	HDC hdc;

	int total;
	int n;

	hdc=GetDC(hWnd);

	int iOldBkMode = SetBkMode (hdc,TRANSPARENT); 

	n = Display.m_cline;

	total = 28;

	while(total-- != 0)
	{
		switch (Display.LogTextViewType[n])
		{
		case 2: 
			SetTextColor(hdc, RGB(207,3,18));        
			break;
		case 3:  
			SetTextColor(hdc, RGB(0,100,0));         
			break;
		case 4:
			SetTextColor(hdc, RGB(0,0,255));         
			break;	
		case 5:
			SetTextColor(hdc, RGB(155,0,0));
			break;
		case 6:  
			SetTextColor(hdc, RGB(0,0,100));         
			break;
		case 7:  
			SetTextColor(hdc, RGB(210,30,150));         
			break;
		case 8:  
			SetTextColor(hdc, RGB(255,255,0));         
			break;
		case 9:  
			SetTextColor(hdc, RGB(160,32,240));         
			break;
		case 10:  
			SetTextColor(hdc, RGB(255,69,0 ));         
			break;
		case 11:  
			SetTextColor(hdc, RGB(0,255,255));         
			break;
		case 12:  
			SetTextColor(hdc, RGB(255,215,0));         
			break; 
		default:  
			SetTextColor(hdc, RGB(0, 0, 0));
			break;	
		}

		if (strlen(Display.LogText[n]) > 1)
		{
		    TextOut(hdc,0,total *15 + 120,Display.LogText[n], strlen(Display.LogText[n]));
		}

		n--;

		if (n < 0)
		{
			n = 28 -1;
		}
	}

	SetBkMode(hdc,iOldBkMode);
	ReleaseDC(hWnd, hdc);
}

void cDisplay::LogTextAddEx(BYTE type, char* msg, int len)
{
	if (len > 180 -1)
	{
		len = 180 -1;
	}

	Display.m_cline++;

	if (Display.m_cline > 28 -1)
	{
		Display.m_cline = 0;
	}

	Display.LogText[Display.m_cline][0] = 0;
	memcpy(&Display.LogText[Display.m_cline],msg,len);
	Display.LogText[Display.m_cline][1+ len] = 0;
	Display.LogText[Display.m_cline][len] = 0;
	Display.LogTextLength[Display.m_cline]= len;
	Display.LogTextViewType[Display.m_cline] = type;
}

cDisplay Display;

