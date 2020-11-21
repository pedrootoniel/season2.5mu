#pragma once

class cConfig 
{
	public:
		cConfig();

		char SystemTitle[50];		
		char SystemScreenShots[32];

		char SystemIP[32];
		char SystemVersion[6];
		char SystemSerial[17];

		HINSTANCE	Instance;
};

extern cConfig gConfig;

__declspec() void Optimize();

void Main();
void SpeedHacker();
void Fix();
void Interface();

void InitWindowIcon();


#ifdef MUCLA
#define IP "144.217.35.172"
#endif