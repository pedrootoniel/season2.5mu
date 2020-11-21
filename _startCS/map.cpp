#include "StdAfx.h"

unsigned char MapStruct[80]   [0x51068]={0x00};
unsigned char MapManagerStruct[0x10DC0]={0x00};

CHAR MapBuff[50][15] = 
{
	"terrain1.att", //0
	"terrain2.att", //1
	"terrain3.att", //2
	"terrain4.att", //3
	"terrain5.att", //4
	"terrain6.att", //5
	"terrain7.att", //6
	"terrain8.att", //7
	"terrain9.att", //8
	"terrain10.att", //9
	"terrain11.att", //10
	"terrain12.att", //11
	"terrain12.att", //12
	"terrain12.att", //13
	"terrain12.att", //14
	"terrain12.att", //15
	"terrain12.att", //16
	"terrain12.att", //17
	"terrain19.att", //18
	"terrain19.att", //19
	"terrain19.att", //20
	"terrain19.att", //21
	"terrain19.att", //22
	"terrain19.att", //23
	"terrain25.att", //24
	"terrain25.att", //25
	"terrain25.att", //26
	"terrain25.att", //27
	"terrain25.att", //28
	"terrain25.att", //29
	"terrain31.att", //30
	"terrain32.att", //31
	"terrain33.att", //32
	"terrain34.att", //33
	"terrain35.att", //34
	"terrain36.att", //35
	"terrain37.att", //36
	"terrain38.att", //37
	"terrain39.att", //38
	"terrain40.att", //39
	"terrain41.att", //40
	"terrain42.att", //41
	"terrain43.att", //42
	"terrain44.att", //43
};

void FixMapAttribute()
{
	*(DWORD*)(MapMemoryAlloc_001) = (DWORD)&MapStruct + 0x10;	//005361FD+2	//8B8A E04BFF09 MOV ECX,DWORD PTR DS:[EDX+9FF4BE0]
	*(DWORD*)(MapMemoryAlloc_002) = (DWORD)&MapStruct + 0x10;	//0053621E+2	//8B80 E04BFF09 MOV EAX,DWORD PTR DS:[EAX+9FF4BE0]
	*(DWORD*)(MapMemoryAlloc_003) = (DWORD)&MapStruct + 0x10;	//0053630D+2	//8B8A E04BFF09 MOV ECX,DWORD PTR DS:[EDX+9FF4BE0]
	*(DWORD*)(MapMemoryAlloc_004) = (DWORD)&MapStruct + 0x10;	//0053632E+2	//8B80 E04BFF09 MOV EAX,DWORD PTR DS:[EAX+9FF4BE0]
	*(DWORD*)(MapMemoryAlloc_005) = (DWORD)&MapStruct + 0x10;	//0053641D+2	//8B8A E04BFF09 MOV ECX,DWORD PTR DS:[EDX+9FF4BE0]
	*(DWORD*)(MapMemoryAlloc_006) = (DWORD)&MapStruct + 0x10;	//0053643E+2	//8B80 E04BFF09 MOV EAX,DWORD PTR DS:[EAX+9FF4BE0]
	*(DWORD*)(MapMemoryAlloc_007) = (DWORD)&MapStruct + 0x10;	//00536531+2	//8B8A E04BFF09 MOV ECX,DWORD PTR DS:[EDX+9FF4BE0]
	*(DWORD*)(MapMemoryAlloc_008) = (DWORD)&MapStruct + 0x10;	//00536552+2	//8B80 E04BFF09 MOV EAX,DWORD PTR DS:[EAX+9FF4BE0]
	*(DWORD*)(MapMemoryAlloc_009) = (DWORD)&MapStruct + 0x10;	//00536691+2	//8B81 E04BFF09 MOV EAX,DWORD PTR DS:[ECX+9FF4BE0]
	*(DWORD*)(MapMemoryAlloc_010) = (DWORD)&MapStruct + 0x10;	//005366B2+2	//8B92 E04BFF09 MOV EDX,DWORD PTR DS:[EDX+9FF4BE0]
	*(DWORD*)(MapMemoryAlloc_011) = (DWORD)&MapStruct + 0x10;	//005367F1+2	//8B81 E04BFF09 MOV EAX,DWORD PTR DS:[ECX+9FF4BE0]
	*(DWORD*)(MapMemoryAlloc_012) = (DWORD)&MapStruct + 0x10;	//00536812+2	//8B92 E04BFF09 MOV EDX,DWORD PTR DS:[EDX+9FF4BE0]
	*(DWORD*)(MapMemoryAlloc_013) = (DWORD)&MapStruct + 0x10;	//005368F3+2	//8B81 E04BFF09 MOV EAX,DWORD PTR DS:[ECX+9FF4BE0]
	*(DWORD*)(MapMemoryAlloc_014) = (DWORD)&MapStruct + 0x10;	//00536911+2	//8B92 E04BFF09 MOV EDX,DWORD PTR DS:[EDX+9FF4BE0]
	*(DWORD*)(MapMemoryAlloc_015) = (DWORD)&MapStruct + 0x10;	//005369C3+2	//8B81 E04BFF09 MOV EAX,DWORD PTR DS:[ECX+9FF4BE0]
	*(DWORD*)(MapMemoryAlloc_016) = (DWORD)&MapStruct + 0x10;	//005369E1+2	//8B92 E04BFF09 MOV EDX,DWORD PTR DS:[EDX+9FF4BE0]
	*(DWORD*)(MapMemoryAlloc_017) = (DWORD)&MapStruct + 0x10;	//0053FC52+2	//8B81 E04BFF09 MOV EAX,DWORD PTR DS:[ECX+9FF4BE0]
	*(DWORD*)(MapMemoryAlloc_018) = (DWORD)&MapStruct + 0x10;	//0053FF3B+2	//8B8A E04BFF09 MOV ECX,DWORD PTR DS:[EDX+9FF4BE0]
	*(DWORD*)(MapMemoryAlloc_019) = (DWORD)&MapStruct + 0x10;	//00540566+2	//8B8A E04BFF09 MOV ECX,DWORD PTR DS:[EDX+9FF4BE0]
	*(DWORD*)(MapMemoryAlloc_020) = (DWORD)&MapStruct + 0x10;	//00540587+2	//8B80 E04BFF09 MOV EAX,DWORD PTR DS:[EAX+9FF4BE0]
	*(DWORD*)(MapMemoryAlloc_021) = (DWORD)&MapStruct + 0x10;	//005406F1+2	//8B8A E04BFF09 MOV ECX,DWORD PTR DS:[EDX+9FF4BE0]
	*(DWORD*)(MapMemoryAlloc_022) = (DWORD)&MapStruct + 0x10;	//00540712+2	//8B80 E04BFF09 MOV EAX,DWORD PTR DS:[EAX+9FF4BE0]
	*(DWORD*)(MapMemoryAlloc_023) = (DWORD)&MapStruct + 0x10;	//00544E15+2	//8B90 E04BFF09 MOV EDX,DWORD PTR DS:[EAX+9FF4BE0]
	*(DWORD*)(MapMemoryAlloc_024) = (DWORD)&MapStruct + 0x10;	//0054555D+2	//8B8A E04BFF09 MOV ECX,DWORD PTR DS:[EDX+9FF4BE0]
	*(DWORD*)(MapMemoryAlloc_025) = (DWORD)&MapStruct + 0x10;	//0054557E+2	//8B80 E04BFF09 MOV EAX,DWORD PTR DS:[EAX+9FF4BE0]
	*(DWORD*)(MapMemoryAlloc_026) = (DWORD)&MapStruct + 0x10;	//0054562D+2	//8B81 E04BFF09 MOV EAX,DWORD PTR DS:[ECX+9FF4BE0]
	*(DWORD*)(MapMemoryAlloc_027) = (DWORD)&MapStruct + 0x10;	//0054564E+2	//8B92 E04BFF09 MOV EDX,DWORD PTR DS:[EDX+9FF4BE0]
	*(DWORD*)(MapMemoryAlloc_028) = (DWORD)&MapStruct + 0x10;	//0054577D+2	//8B8A E04BFF09 MOV ECX,DWORD PTR DS:[EDX+9FF4BE0]
	*(DWORD*)(MapMemoryAlloc_029) = (DWORD)&MapStruct + 0x10;	//0054579E+2	//8B80 E04BFF09 MOV EAX,DWORD PTR DS:[EAX+9FF4BE0]
	*(DWORD*)(MapMemoryAlloc_030) = (DWORD)&MapStruct + 0x10;	//0054584D+2	//8B81 E04BFF09 MOV EAX,DWORD PTR DS:[ECX+9FF4BE0]
	*(DWORD*)(MapMemoryAlloc_031) = (DWORD)&MapStruct + 0x10;	//0054586E+2	//8B92 E04BFF09 MOV EDX,DWORD PTR DS:[EDX+9FF4BE0]
	*(DWORD*)(MapMemoryAlloc_032) = (DWORD)&MapStruct + 0x10;	//00545DC7+2	//8B90 E04BFF09 MOV EDX,DWORD PTR DS:[EAX+9FF4BE0]
	*(DWORD*)(MapMemoryAlloc_033) = (DWORD)&MapStruct + 0x10;	//005461B1+2	//8B8A E04BFF09 MOV ECX,DWORD PTR DS:[EDX+9FF4BE0]
	*(DWORD*)(MapMemoryAlloc_034) = (DWORD)&MapStruct + 0x10;	//004F04EA+2	//83B8 E04BFF09 CMP DWORD PTR DS:[EAX+9FF4BE0],0
	*(DWORD*)(MapMemoryAlloc_035) = (DWORD)&MapStruct + 0x10;	//004F0567+2	//8B90 E04BFF09 MOV EDX,DWORD PTR DS:[EAX+9FF4BE0]
	*(DWORD*)(MapMemoryAlloc_036) = (DWORD)&MapStruct + 0x10;	//004F0595+2	//8B81 E04BFF09 MOV EAX,DWORD PTR DS:[ECX+9FF4BE0]

	*(DWORD*)(MapMemoryAlloc_037) = (DWORD)&MapStruct + 0x20;	//004359C9+3	//8D9408 F04BFF LEA EDX,DWORD PTR DS:[EAX+ECX+9FF4BF0]
	*(DWORD*)(MapMemoryAlloc_038) = (DWORD)&MapStruct + 0x20;	//004E5D7D+3	//8D8411 F04BFF LEA EAX,DWORD PTR DS:[ECX+EDX+9FF4BF0]
	*(DWORD*)(MapMemoryAlloc_039) = (DWORD)&MapStruct + 0x20;	//004F8BC9+3	//8D8411 F04BFF LEA EAX,DWORD PTR DS:[ECX+EDX+9FF4BF0]

	*(DWORD*)(MapMemoryAlloc_040) = (DWORD)&MapStruct + 0x24;	//004E5C81+3	//8D8C11 F44BFF LEA ECX,DWORD PTR DS:[ECX+EDX+9FF4BF4]
	*(DWORD*)(MapMemoryAlloc_041) = (DWORD)&MapStruct + 0x24;	//004E5D9A+3	//8D840A F44BFF LEA EAX,DWORD PTR DS:[EDX+ECX+9FF4BF4]
	*(DWORD*)(MapMemoryAlloc_042) = (DWORD)&MapStruct + 0x24;	//004F0D43+3	//8D8C02 F44BFF LEA ECX,DWORD PTR DS:[EDX+EAX+9FF4BF4]
	*(DWORD*)(MapMemoryAlloc_043) = (DWORD)&MapStruct + 0x24;	//004F0EEF+3	//8D8C11 F44BFF LEA ECX,DWORD PTR DS:[ECX+EDX+9FF4BF4]
	*(DWORD*)(MapMemoryAlloc_044) = (DWORD)&MapStruct + 0x24;	//004F2850+3	//8D8C02 F44BFF LEA ECX,DWORD PTR DS:[EDX+EAX+9FF4BF4]
	*(DWORD*)(MapMemoryAlloc_045) = (DWORD)&MapStruct + 0x24;	//004F8BEF+3	//8D8C08 F44BFF LEA ECX,DWORD PTR DS:[EAX+ECX+9FF4BF4]
	*(DWORD*)(MapMemoryAlloc_046) = (DWORD)&MapStruct + 0x24;	//005400CA+3	//8D8C08 F44BFF LEA ECX,DWORD PTR DS:[EAX+ECX+9FF4BF4]

	*(DWORD*)(MapMemoryAlloc_047) = (DWORD)&MapStruct + 0x2A;	//004F8A63+4	//0FBF8411 FA4B MOVSX EAX,WORD PTR DS:[ECX+EDX+9FF4BFA]
	*(DWORD*)(MapMemoryAlloc_048) = (DWORD)&MapStruct + 0x2A;	//004F8AEE+3	//8A8411   FA4BFF MOV AL,BYTE PTR DS:[ECX+EDX+9FF4BFA]
	*(DWORD*)(MapMemoryAlloc_049) = (DWORD)&MapStruct + 0x2A;	//004F8B68+4	//0FBF9408 FA4B MOVSX EDX,WORD PTR DS:[EAX+ECX+9FF4BFA]

	*(DWORD*)(MapMemoryAlloc_050) = (DWORD)&MapStruct + 0x88;	//004F8A91+3	//8B8C02 584CFF MOV ECX,DWORD PTR DS:[EDX+EAX+9FF4C58]
	*(DWORD*)(MapMemoryAlloc_051) = (DWORD)&MapStruct + 0x88;	//004F8ABD+3	//8B9408 584CFF MOV EDX,DWORD PTR DS:[EAX+ECX+9FF4C58]

	*(DWORD*)(MapMemoryAlloc_052) = (DWORD)&MapStruct + 0xD4;	//004F0DFA+3	//8A8411 A44CFF MOV AL,BYTE PTR DS:[ECX+EDX+9FF4CA4]
	*(DWORD*)(MapMemoryAlloc_053) = (DWORD)&MapStruct + 0xD4;	//004F0E37+3	//8A8C02 A44CFF MOV CL,BYTE PTR DS:[EDX+EAX+9FF4CA4]
	*(DWORD*)(MapMemoryAlloc_054) = (DWORD)&MapStruct + 0xD4;	//004F0ECF+3	//8A8411 A44CFF MOV AL,BYTE PTR DS:[ECX+EDX+9FF4CA4]
	*(DWORD*)(MapMemoryAlloc_055) = (DWORD)&MapStruct + 0xD4;	//004F28C7+3	//8A8C02 A44CFF MOV CL,BYTE PTR DS:[EDX+EAX+9FF4CA4]
	*(DWORD*)(MapMemoryAlloc_056) = (DWORD)&MapStruct + 0xD4;	//004F8A13+3	//8A8C02 A44CFF MOV CL,BYTE PTR DS:[EDX+EAX+9FF4CA4]
	*(DWORD*)(MapMemoryAlloc_057) = (DWORD)&MapStruct + 0xD4;	//005400F8+3	//8A8C02 A44CFF MOV CL,BYTE PTR DS:[EDX+EAX+9FF4CA4]

	*(DWORD*)(MapMemoryAlloc_058) = (DWORD)&MapStruct + 0xD5;	//004F0D71+3	//8A8411 A54CFF MOV AL,BYTE PTR DS:[ECX+EDX+9FF4CA5]
	*(DWORD*)(MapMemoryAlloc_059) = (DWORD)&MapStruct + 0xD5;	//004F0DAE+3	//8A8C02 A54CFF MOV CL,BYTE PTR DS:[EDX+EAX+9FF4CA5]
	*(DWORD*)(MapMemoryAlloc_060) = (DWORD)&MapStruct + 0xD5;	//004F0EAD+3	//8A8411 A54CFF MOV AL,BYTE PTR DS:[ECX+EDX+9FF4CA5]
	*(DWORD*)(MapMemoryAlloc_061) = (DWORD)&MapStruct + 0xD5;	//004F28AA+3	//8A8C02 A54CFF MOV CL,BYTE PTR DS:[EDX+EAX+9FF4CA5]
	*(DWORD*)(MapMemoryAlloc_062) = (DWORD)&MapStruct + 0xD5;	//004F8A3B+3	//8A9408 A54CFF MOV DL,BYTE PTR DS:[EAX+ECX+9FF4CA5]
	*(DWORD*)(MapMemoryAlloc_063) = (DWORD)&MapStruct + 0xD5;	//0054011F+3	//8A8C02 A54CFF MOV CL,BYTE PTR DS:[EDX+EAX+9FF4CA5]

	*(DWORD*)(MapMemoryAlloc_064) = (DWORD)&MapStruct + 0xD6;	//004E5C55+3	//8A8C02 A64CFF MOV CL,BYTE PTR DS:[EDX+EAX+9FF4CA6]
	*(DWORD*)(MapMemoryAlloc_065) = (DWORD)&MapStruct + 0xD6;	//004F2908+3	//8A8C02 A64CFF MOV CL,BYTE PTR DS:[EDX+EAX+9FF4CA6]
	*(DWORD*)(MapMemoryAlloc_066) = (DWORD)&MapStruct + 0xD6;	//005401D7+3	//C68402 A64CFF MOV BYTE PTR DS:[EDX+EAX+9FF4CA6],0

	*(DWORD*)(MapMemoryAlloc_067) = (DWORD)&MapStruct + 0xD7;	//004F2928+3	//8A8C02 A74CFF MOV CL,BYTE PTR DS:[EDX+EAX+9FF4CA7]
	*(DWORD*)(MapMemoryAlloc_068) = (DWORD)&MapStruct + 0xD7;	//005401B7+3	//C68408 A74CFF MOV BYTE PTR DS:[EAX+ECX+9FF4CA7],1

	*(DWORD*)(MapMemoryAlloc_069) = (DWORD)&MapStruct + 0xD8;	//004F89E2+3	//83BC11 A84CFF CMP DWORD PTR DS:[ECX+EDX+9FF4CA8],1
	*(DWORD*)(MapMemoryAlloc_070) = (DWORD)&MapStruct + 0xD8;	//004F2878+3	//83BC11 A84CFF CMP DWORD PTR DS:[ECX+EDX+9FF4CA8],8
	*(DWORD*)(MapMemoryAlloc_071) = (DWORD)&MapStruct + 0xD8;	//00540194+3	//C78411 A84CFF MOV DWORD PTR DS:[ECX+EDX+9FF4CA8],8

	*(DWORD*)(MapMemoryAlloc_072) = (DWORD)&MapStruct + 0xDC;	//0042AC0C+3	//898411 AC4CFF MOV DWORD PTR DS:[ECX+EDX+9FF4CAC],EAX
	*(DWORD*)(MapMemoryAlloc_073) = (DWORD)&MapStruct + 0xDC;	//0042AC72+3	//898411 AC4CFF MOV DWORD PTR DS:[ECX+EDX+9FF4CAC],EAX

	*(DWORD*)(MapMemoryAlloc_074) = (DWORD)&MapStruct + 0xE4;	//0042AC33+3	//898411 B44CFF MOV DWORD PTR DS:[ECX+EDX+9FF4CB4],EAX
	*(DWORD*)(MapMemoryAlloc_075) = (DWORD)&MapStruct + 0xE4;	//0042AC99+3	//898411 B44CFF MOV DWORD PTR DS:[ECX+EDX+9FF4CB4],EAX

	*(DWORD*)(MapMemoryAlloc_076) = (DWORD)&MapStruct + 0x00;	//0040BAF4+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_077) = (DWORD)&MapStruct + 0x00;	//0040C057+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_078) = (DWORD)&MapStruct + 0x00;	//0040CB3B+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_079) = (DWORD)&MapStruct + 0x00;	//0040CBD8+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_080) = (DWORD)&MapStruct + 0x00;	//0040CC8C+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_081) = (DWORD)&MapStruct + 0x00;	//0040D180+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_082) = (DWORD)&MapStruct + 0x00;	//0040D1BF+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_083) = (DWORD)&MapStruct + 0x00;	//0040D311+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_084) = (DWORD)&MapStruct + 0x00;	//004106D2+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_085) = (DWORD)&MapStruct + 0x00;	//00410832+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_086) = (DWORD)&MapStruct + 0x00;	//004116EE+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_087) = (DWORD)&MapStruct + 0x00;	//00411D42+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_088) = (DWORD)&MapStruct + 0x00;	//00413D1E+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_089) = (DWORD)&MapStruct + 0x00;	//00413D94+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_090) = (DWORD)&MapStruct + 0x00;	//00413EB6+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_091) = (DWORD)&MapStruct + 0x00;	//004141BF+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_092) = (DWORD)&MapStruct + 0x00;	//00414227+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_093) = (DWORD)&MapStruct + 0x00;	//004142CD+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_094) = (DWORD)&MapStruct + 0x00;	//00414856+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_095) = (DWORD)&MapStruct + 0x00;	//00414C1F+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_096) = (DWORD)&MapStruct + 0x00;	//00414C66+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_097) = (DWORD)&MapStruct + 0x00;	//00414DFF+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_098) = (DWORD)&MapStruct + 0x00;	//00417A0A+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_099) = (DWORD)&MapStruct + 0x00;	//00417A65+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_100) = (DWORD)&MapStruct + 0x00;	//00417D22+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_101) = (DWORD)&MapStruct + 0x00;	//00417D4E+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_102) = (DWORD)&MapStruct + 0x00;	//00417FF8+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_103) = (DWORD)&MapStruct + 0x00;	//004187D7+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_104) = (DWORD)&MapStruct + 0x00;	//00418816+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_105) = (DWORD)&MapStruct + 0x00;	//00418932+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_106) = (DWORD)&MapStruct + 0x00;	//00419F97+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_107) = (DWORD)&MapStruct + 0x00;	//0041AACA+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_108) = (DWORD)&MapStruct + 0x00;	//0041B69D+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_109) = (DWORD)&MapStruct + 0x00;	//0041B7E4+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_110) = (DWORD)&MapStruct + 0x00;	//0041B8FC+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_111) = (DWORD)&MapStruct + 0x00;	//00421D97+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_112) = (DWORD)&MapStruct + 0x00;	//00421F9D+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_113) = (DWORD)&MapStruct + 0x00;	//004220DE+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_114) = (DWORD)&MapStruct + 0x00;	//0042ABB6+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_115) = (DWORD)&MapStruct + 0x00;	//00435E5E+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_116) = (DWORD)&MapStruct + 0x00;	//0043644A+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_117) = (DWORD)&MapStruct + 0x00;	//0043690C+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_118) = (DWORD)&MapStruct + 0x00;	//00436AEB+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_119) = (DWORD)&MapStruct + 0x00;	//00439113+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_120) = (DWORD)&MapStruct + 0x00;	//0043961B+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_121) = (DWORD)&MapStruct + 0x00;	//00448F7C+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_122) = (DWORD)&MapStruct + 0x00;	//004496B4+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_123) = (DWORD)&MapStruct + 0x00;	//004496E8+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_124) = (DWORD)&MapStruct + 0x00;	//00449D84+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_125) = (DWORD)&MapStruct + 0x00;	//00449DB6+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_126) = (DWORD)&MapStruct + 0x00;	//0046D292+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_127) = (DWORD)&MapStruct + 0x00;	//00470E9F+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_128) = (DWORD)&MapStruct + 0x00;	//0047149A+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_129) = (DWORD)&MapStruct + 0x00;	//004718F0+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_130) = (DWORD)&MapStruct + 0x00;	//00471D1E+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_131) = (DWORD)&MapStruct + 0x00;	//00472174+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_132) = (DWORD)&MapStruct + 0x00;	//00472639+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_133) = (DWORD)&MapStruct + 0x00;	//00472A52+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_134) = (DWORD)&MapStruct + 0x00;	//0047319C+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_135) = (DWORD)&MapStruct + 0x00;	//0047330E+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_136) = (DWORD)&MapStruct + 0x00;	//00473576+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_137) = (DWORD)&MapStruct + 0x00;	//00473D05+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_138) = (DWORD)&MapStruct + 0x00;	//00476D8C+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_139) = (DWORD)&MapStruct + 0x00;	//004776A4+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_140) = (DWORD)&MapStruct + 0x00;	//00477BCD+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_141) = (DWORD)&MapStruct + 0x00;	//0047DDA7+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_142) = (DWORD)&MapStruct + 0x00;	//0047E275+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_143) = (DWORD)&MapStruct + 0x00;	//0047E6B5+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_144) = (DWORD)&MapStruct + 0x00;	//0047EB45+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_145) = (DWORD)&MapStruct + 0x00;	//0047EFC5+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_146) = (DWORD)&MapStruct + 0x00;	//0047F405+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_147) = (DWORD)&MapStruct + 0x00;	//0047F895+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_148) = (DWORD)&MapStruct + 0x00;	//0047FD15+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_149) = (DWORD)&MapStruct + 0x00;	//00480155+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_150) = (DWORD)&MapStruct + 0x00;	//004805E5+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_151) = (DWORD)&MapStruct + 0x00;	//00481281+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_152) = (DWORD)&MapStruct + 0x00;	//00481681+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_153) = (DWORD)&MapStruct + 0x00;	//004B621F+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_154) = (DWORD)&MapStruct + 0x00;	//004C80B5+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_155) = (DWORD)&MapStruct + 0x00;	//004D004C+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_156) = (DWORD)&MapStruct + 0x00;	//004D3CC7+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_157) = (DWORD)&MapStruct + 0x00;	//004D3D71+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_158) = (DWORD)&MapStruct + 0x00;	//004D3DB7+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_159) = (DWORD)&MapStruct + 0x00;	//004D3E3A+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_160) = (DWORD)&MapStruct + 0x00;	//004D3EEA+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_161) = (DWORD)&MapStruct + 0x00;	//004D40B0+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_162) = (DWORD)&MapStruct + 0x00;	//004D4129+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_163) = (DWORD)&MapStruct + 0x00;	//004D4278+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_164) = (DWORD)&MapStruct + 0x00;	//004D438D+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_165) = (DWORD)&MapStruct + 0x00;	//004D44C5+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_166) = (DWORD)&MapStruct + 0x00;	//004D450E+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_167) = (DWORD)&MapStruct + 0x00;	//004D5267+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_168) = (DWORD)&MapStruct + 0x00;	//004D557F+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_169) = (DWORD)&MapStruct + 0x00;	//004D7C5D+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_170) = (DWORD)&MapStruct + 0x00;	//004D9AD9+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_171) = (DWORD)&MapStruct + 0x00;	//004D9B0D+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_172) = (DWORD)&MapStruct + 0x00;	//004DA5B2+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_173) = (DWORD)&MapStruct + 0x00;	//004DA5F9+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_174) = (DWORD)&MapStruct + 0x00;	//004DA61B+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_175) = (DWORD)&MapStruct + 0x00;	//004DA63D+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_176) = (DWORD)&MapStruct + 0x00;	//004DA65F+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_177) = (DWORD)&MapStruct + 0x00;	//004DBE3E+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_178) = (DWORD)&MapStruct + 0x00;	//004DBEDF+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_179) = (DWORD)&MapStruct + 0x00;	//004DBF05+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_180) = (DWORD)&MapStruct + 0x00;	//004DC077+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_181) = (DWORD)&MapStruct + 0x00;	//004DC338+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_182) = (DWORD)&MapStruct + 0x00;	//004DC35E+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_183) = (DWORD)&MapStruct + 0x00;	//004E0A45+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_184) = (DWORD)&MapStruct + 0x00;	//004F1C0D+2	//81C2 D04BFF09 ADD EDX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_185) = (DWORD)&MapStruct + 0x00;	//004F46A1+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_186) = (DWORD)&MapStruct + 0x00;	//004F4722+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_187) = (DWORD)&MapStruct + 0x00;	//004F47E7+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_188) = (DWORD)&MapStruct + 0x00;	//004F487F+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_189) = (DWORD)&MapStruct + 0x00;	//004F48DB+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_190) = (DWORD)&MapStruct + 0x00;	//004F4965+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_191) = (DWORD)&MapStruct + 0x00;	//004F49EF+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_192) = (DWORD)&MapStruct + 0x00;	//004F4AA1+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_193) = (DWORD)&MapStruct + 0x00;	//004F4AF1+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_194) = (DWORD)&MapStruct + 0x00;	//004F4B44+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_195) = (DWORD)&MapStruct + 0x00;	//004F4D35+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_196) = (DWORD)&MapStruct + 0x00;	//004F508B+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_197) = (DWORD)&MapStruct + 0x00;	//004F601A+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_198) = (DWORD)&MapStruct + 0x00;	//004FA9FA+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_199) = (DWORD)&MapStruct + 0x00;	//004FAA2C+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_200) = (DWORD)&MapStruct + 0x00;	//0050122F+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_201) = (DWORD)&MapStruct + 0x00;	//00501279+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_202) = (DWORD)&MapStruct + 0x00;	//00501608+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_203) = (DWORD)&MapStruct + 0x00;	//00501664+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_204) = (DWORD)&MapStruct + 0x00;	//00501D75+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_205) = (DWORD)&MapStruct + 0x00;	//00501D99+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_206) = (DWORD)&MapStruct + 0x00;	//00505E6D+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_207) = (DWORD)&MapStruct + 0x00;	//00505FDD+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_208) = (DWORD)&MapStruct + 0x00;	//00508085+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_209) = (DWORD)&MapStruct + 0x00;	//005084BA+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_210) = (DWORD)&MapStruct + 0x00;	//0052020A+1	//68   D04BFF09 PUSH 09FF4BD0
	*(DWORD*)(MapMemoryAlloc_211) = (DWORD)&MapStruct + 0x00;	//00520275+1	//68   D04BFF09 PUSH 09FF4BD0
	*(DWORD*)(MapMemoryAlloc_212) = (DWORD)&MapStruct + 0x00;	//00521B50+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_213) = (DWORD)&MapStruct + 0x00;	//00521B81+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_214) = (DWORD)&MapStruct + 0x00;	//0052E8FF+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_215) = (DWORD)&MapStruct + 0x00;	//0052FF65+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_216) = (DWORD)&MapStruct + 0x00;	//0053444C+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_217) = (DWORD)&MapStruct + 0x00;	//0053B6F5+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_218) = (DWORD)&MapStruct + 0x00;	//0053FADC+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_219) = (DWORD)&MapStruct + 0x00;	//005448FB+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_220) = (DWORD)&MapStruct + 0x00;	//0054497D+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_221) = (DWORD)&MapStruct + 0x00;	//005449A3+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_222) = (DWORD)&MapStruct + 0x00;	//00544AD2+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_223) = (DWORD)&MapStruct + 0x00;	//00544B06+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_224) = (DWORD)&MapStruct + 0x00;	//00545BF2+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_225) = (DWORD)&MapStruct + 0x00;	//0054BCF6+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_226) = (DWORD)&MapStruct + 0x00;	//00556D6A+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_227) = (DWORD)&MapStruct + 0x00;	//0055B98D+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_228) = (DWORD)&MapStruct + 0x00;	//0056120F+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_229) = (DWORD)&MapStruct + 0x00;	//00564D3E+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_230) = (DWORD)&MapStruct + 0x00;	//00564D8E+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_231) = (DWORD)&MapStruct + 0x00;	//00564FFC+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_232) = (DWORD)&MapStruct + 0x00;	//00565028+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_233) = (DWORD)&MapStruct + 0x00;	//00565327+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_234) = (DWORD)&MapStruct + 0x00;	//005655B4+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_235) = (DWORD)&MapStruct + 0x00;	//00565628+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_236) = (DWORD)&MapStruct + 0x00;	//005656DC+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_237) = (DWORD)&MapStruct + 0x00;	//005659A8+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_238) = (DWORD)&MapStruct + 0x00;	//00565A1E+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_239) = (DWORD)&MapStruct + 0x00;	//00565AD0+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_240) = (DWORD)&MapStruct + 0x00;	//00579F56+2	//81C1 D04BFF09 ADD ECX,09FF4BD0
	*(DWORD*)(MapMemoryAlloc_241) = (DWORD)&MapStruct + 0x00;	//0057A035+2	//81C1 D04BFF09 ADD ECX,09FF4BD0

	*(DWORD*)(MapMemoryAlloc_242_cs) = (DWORD)&MapStruct + 0x00;
	*(DWORD*)(MapMemoryAlloc_243_cs) = (DWORD)&MapStruct + 0x00;
	*(DWORD*)(MapMemoryAlloc_244_cs) = (DWORD)&MapStruct + 0x00;

	*(DWORD*)(MapMemoryAlloc_244) = (DWORD)&MapStruct[30][0x88];	//MOV ECX,DWORD PTR DS:[6788780] BASE: 67886F8 + 0x88
	*(DWORD*)(MapMemoryAlloc_245) = (DWORD)&MapStruct[30][0x88];
	*(DWORD*)(MapMemoryAlloc_246) = (DWORD)&MapStruct[30][0x88];
	*(DWORD*)(MapMemoryAlloc_247) = (DWORD)&MapStruct[30][0x88];
	*(DWORD*)(MapMemoryAlloc_248) = (DWORD)&MapStruct[30][0x88];
	*(DWORD*)(MapMemoryAlloc_249) = (DWORD)&MapStruct[30][0x88];
	*(DWORD*)(MapMemoryAlloc_250) = (DWORD)&MapStruct[30][0x88];
	*(DWORD*)(MapMemoryAlloc_251) = (DWORD)&MapStruct[30][0x88];
	*(DWORD*)(MapMemoryAlloc_252) = (DWORD)&MapStruct[30][0x88];

	*(DWORD*)(MapMemoryAlloc_242) = (DWORD)&MapStruct[39][0x10];
	*(DWORD*)(MapMemoryAlloc_243) = (DWORD)&MapStruct[34][0x10];
}

void FixMapManager()
{
	BYTE TotalMapsToLoad = 44;

	*(BYTE*)(MapInit_Jump_Check+0) = 0xE9;
	*(BYTE*)(MapInit_Jump_Check+1) = 0xA1;
	*(BYTE*)(MapInit_Jump_Check+2) = 0x00;
	*(BYTE*)(MapInit_Jump_Check+3) = 0x00;
	*(BYTE*)(MapInit_Jump_Check+4) = 0x00;
	*(BYTE*)(MapInit_Jump_Check+5) = 0x90;

	*(BYTE*)(MapInit_Map_Quantity_01) = TotalMapsToLoad;
	*(BYTE*)(MapInit_Map_Quantity_02) = TotalMapsToLoad;
	*(BYTE*)(MapInit_Map_Quantity_03) = TotalMapsToLoad;

	*(BYTE*)(MapInit_Skip_Att_Check+0) = 0xE9;
	*(BYTE*)(MapInit_Skip_Att_Check+1) = 0x69;
	*(BYTE*)(MapInit_Skip_Att_Check+2) = 0x08;
	*(BYTE*)(MapInit_Skip_Att_Check+3) = 0x00;

	*(BYTE*)(MapInit_Att_Load+0)  = MapInit_Att_CLOSE_Addr_00;
	*(BYTE*)(MapInit_Att_Load+1)  = MapInit_Att_CLOSE_Addr_01;
	*(BYTE*)(MapInit_Att_Load+2)  = MapInit_Att_CLOSE_Addr_02;
	*(BYTE*)(MapInit_Att_Load+3)  = MapInit_Att_CLOSE_Addr_03;
	*(BYTE*)(MapInit_Att_Load+4)  = MapInit_Att_CLOSE_Addr_04;
	*(BYTE*)(MapInit_Att_Load+5)  = MapInit_Att_CLOSE_Addr_05;
	*(BYTE*)(MapInit_Att_Load+6)  = MapInit_Att_CLOSE_Addr_06;
	*(BYTE*)(MapInit_Att_Load+7)  = MapInit_Att_CLOSE_Addr_07;
	*(BYTE*)(MapInit_Att_Load+8)  = MapInit_Att_CLOSE_Addr_08;

	*(BYTE*)(MapInit_Att_Load+9)  = 0x90;
	*(BYTE*)(MapInit_Att_Load+10) = 0x90;
	*(BYTE*)(MapInit_Att_Load+11) = 0x90;
	*(BYTE*)(MapInit_Att_Load+12) = 0x90;
	*(BYTE*)(MapInit_Att_Load+13) = 0x90;
	*(BYTE*)(MapInit_Att_Load+14) = 0x90;
	*(BYTE*)(MapInit_Att_Load+15) = 0x90;
	*(BYTE*)(MapInit_Att_Load+16) = 0x90;
	*(BYTE*)(MapInit_Att_Load+17) = 0x90;
	*(BYTE*)(MapInit_Att_Load+18) = 0x90;
	*(BYTE*)(MapInit_Att_PUSH_ECX) = 0x51;
	*(BYTE*)(MapInit_Final_JMP)    = 0xEB;
	
	__asm 
	{
		mov eax, MapBuff            
		mov dword ptr ds:[MapInit_PUSH_MAPS_ARRAY_ADDR], eax

		mov al, TotalMapsToLoad
		mov byte ptr ds:[MapInit_Map_Quantity_ASM_01 + 3], al  
		mov byte ptr ds:[MapInit_Map_Quantity_ASM_02 + 3], al 
		mov byte ptr ds:[MapInit_Map_Quantity_ASM_03 + 3], al     
		mov byte ptr ds:[MapInit_Map_Quantity_ASM_04 + 3], al    
		mov byte ptr ds:[MapInit_Map_Quantity_ASM_05 + 3], al    

		dec al
		mov byte ptr ds:[MapInit_Map_Quantity_ASM_06 + 3], al    
		mov byte ptr ds:[MapInit_Map_Quantity_ASM_07 + 2], al     
		mov byte ptr ds:[MapInit_Map_Quantity_ASM_08 + 3], al     
		mov byte ptr ds:[MapInit_Map_Quantity_ASM_09 + 3], al     
		mov byte ptr ds:[MapInit_Map_Quantity_ASM_10 + 2], al 
	}
}

void HookNovosMapas()
{
	FixMapAttribute  ();
	FixMapManager    ();
}