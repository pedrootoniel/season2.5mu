#pragma once



class Font
{
public:
	Font(){};
	~Font(){};
	void Load();
	HFONT LoadFont();
}; 
extern Font gFont;

