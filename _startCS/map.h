//========================================================================================================================================//
//                                                                                                                                        //
//                     #############  Advanced Coderz Team Season 2.5 Plugin GS 1.00.18 e CS 1.00.18  #############                       //
//                                                                                                                                        //
//                     #############               Codado Por Hamiltontsz 2012 ~ 2013                 #############                       //
//                                                                                                                                        //
//                     #############       Contato: hamiltonts@hotmail.com / Skype: hamiltontsz       #############                       //
//                                                                                                                                        //
//========================================================================================================================================//

#include "StdAfx.h"

void HookNovosMapas     ();
void MapLoad            ();

#define MapMemoryAlloc_001					0x0050328A+2	//83B8 509BE005 CMP DWORD PTR DS:[EAX+5E09B50],0
#define MapMemoryAlloc_002					0x00503307+2	//8B90 509BE005 MOV EDX,DWORD PTR DS:[EAX+5E09B50]
#define MapMemoryAlloc_003					0x00503335+2	//8B81 509BE005 MOV EAX,DWORD PTR DS:[ECX+5E09B50]
#define MapMemoryAlloc_004					0x0054B26D+2	//8B8A 509BE005 MOV ECX,DWORD PTR DS:[EDX+5E09B50]
#define MapMemoryAlloc_005					0x0054B28E+2	//8B80 509BE005 MOV EAX,DWORD PTR DS:[EAX+5E09B50]
#define MapMemoryAlloc_006					0x0054B37D+2	//8B8A 509BE005 MOV ECX,DWORD PTR DS:[EDX+5E09B50]
#define MapMemoryAlloc_007					0x0054B39E+2	//8B80 509BE005 MOV EAX,DWORD PTR DS:[EAX+5E09B50]
#define MapMemoryAlloc_008					0x0054B48D+2	//8B8A 509BE005 MOV ECX,DWORD PTR DS:[EDX+5E09B50]
#define MapMemoryAlloc_009					0x0054B4AE+2	//8B80 509BE005 MOV EAX,DWORD PTR DS:[EAX+5E09B50]
#define MapMemoryAlloc_010					0x0054B5A1+2	//8B8A 509BE005 MOV ECX,DWORD PTR DS:[EDX+5E09B50]
#define MapMemoryAlloc_011					0x0054B5C2+2	//8B80 509BE005 MOV EAX,DWORD PTR DS:[EAX+5E09B50]
#define MapMemoryAlloc_012					0x0054B701+2	//8B81 509BE005 MOV EAX,DWORD PTR DS:[ECX+5E09B50]
#define MapMemoryAlloc_013					0x0054B722+2	//8B92 509BE005 MOV EDX,DWORD PTR DS:[EDX+5E09B50]
#define MapMemoryAlloc_014					0x0054B861+2	//8B81 509BE005 MOV EAX,DWORD PTR DS:[ECX+5E09B50]
#define MapMemoryAlloc_015					0x0054B882+2	//8B92 509BE005 MOV EDX,DWORD PTR DS:[EDX+5E09B50]
#define MapMemoryAlloc_016					0x0054B963+2	//8B81 509BE005 MOV EAX,DWORD PTR DS:[ECX+5E09B50]
#define MapMemoryAlloc_017					0x0054B981+2	//8B92 509BE005 MOV EDX,DWORD PTR DS:[EDX+5E09B50]
#define MapMemoryAlloc_018					0x0054BA33+2	//8B81 509BE005 MOV EAX,DWORD PTR DS:[ECX+5E09B50]
#define MapMemoryAlloc_019					0x0054BA51+2	//8B92 509BE005 MOV EDX,DWORD PTR DS:[EDX+5E09B50]
#define MapMemoryAlloc_020					0x00554CC2+2	//8B81 509BE005 MOV EAX,DWORD PTR DS:[ECX+5E09B50]
#define MapMemoryAlloc_021					0x00554FAB+2	//8B8A 509BE005 MOV ECX,DWORD PTR DS:[EDX+5E09B50]
#define MapMemoryAlloc_022					0x005555D6+2	//8B8A 509BE005 MOV ECX,DWORD PTR DS:[EDX+5E09B50]
#define MapMemoryAlloc_023					0x005555F7+2	//8B80 509BE005 MOV EAX,DWORD PTR DS:[EAX+5E09B50]
#define MapMemoryAlloc_024					0x00555761+2	//8B8A 509BE005 MOV ECX,DWORD PTR DS:[EDX+5E09B50]
#define MapMemoryAlloc_025					0x00555782+2	//8B80 509BE005 MOV EAX,DWORD PTR DS:[EAX+5E09B50]
#define MapMemoryAlloc_026					0x00559E85+2	//8B90 509BE005 MOV EDX,DWORD PTR DS:[EAX+5E09B50]
#define MapMemoryAlloc_027					0x0055A5CD+2	//8B8A 509BE005 MOV ECX,DWORD PTR DS:[EDX+5E09B50]
#define MapMemoryAlloc_028					0x0055A5EE+2	//8B80 509BE005 MOV EAX,DWORD PTR DS:[EAX+5E09B50]
#define MapMemoryAlloc_029					0x0055A69D+2	//8B81 509BE005 MOV EAX,DWORD PTR DS:[ECX+5E09B50]
#define MapMemoryAlloc_030					0x0055A6BE+2	//8B92 509BE005 MOV EDX,DWORD PTR DS:[EDX+5E09B50]
#define MapMemoryAlloc_031					0x0055A7ED+2	//8B8A 509BE005 MOV ECX,DWORD PTR DS:[EDX+5E09B50]
#define MapMemoryAlloc_032					0x0055A80E+2	//8B80 509BE005 MOV EAX,DWORD PTR DS:[EAX+5E09B50]
#define MapMemoryAlloc_033					0x0055A8BD+2	//8B81 509BE005 MOV EAX,DWORD PTR DS:[ECX+5E09B50]
#define MapMemoryAlloc_034					0x0055A8DE+2	//8B92 509BE005 MOV EDX,DWORD PTR DS:[EDX+5E09B50]
#define MapMemoryAlloc_035					0x0055AE37+2	//8B90 509BE005 MOV EDX,DWORD PTR DS:[EAX+5E09B50]
#define MapMemoryAlloc_036					0x0055B221+2	//8B8A 509BE005 MOV ECX,DWORD PTR DS:[EDX+5E09B50]

//[+0x20][+3]
#define MapMemoryAlloc_037					0x00438A09+3	//8D9408 609BE0 LEA EDX,DWORD PTR DS:[EAX+ECX+5E09B60]
#define MapMemoryAlloc_038					0x004F889D+3	//8D8411 609BE0 LEA EAX,DWORD PTR DS:[ECX+EDX+5E09B60]
#define MapMemoryAlloc_039					0x0050C274+3	//8D8411 609BE0 LEA EAX,DWORD PTR DS:[ECX+EDX+5E09B60]

//[+0x24][+3]
#define MapMemoryAlloc_040					0x004F87A1+3	//8D8C11 649BE0 LEA ECX,DWORD PTR DS:[ECX+EDX+5E09B64]
#define MapMemoryAlloc_041					0x004F88BA+3	//8D840A 649BE0 LEA EAX,DWORD PTR DS:[EDX+ECX+5E09B64]
#define MapMemoryAlloc_042					0x00503AE3+3	//8D8C02 649BE0 LEA ECX,DWORD PTR DS:[EDX+EAX+5E09B64]
#define MapMemoryAlloc_043					0x00503C8F+3	//8D8C11 649BE0 LEA ECX,DWORD PTR DS:[ECX+EDX+5E09B64]
#define MapMemoryAlloc_044					0x00505610+3	//8D8C02 649BE0 LEA ECX,DWORD PTR DS:[EDX+EAX+5E09B64]
#define MapMemoryAlloc_045					0x0050C29A+3	//8D8C08 649BE0 LEA ECX,DWORD PTR DS:[EAX+ECX+5E09B64]
#define MapMemoryAlloc_046					0x0055513A+3	//8D8C08 649BE0 LEA ECX,DWORD PTR DS:[EAX+ECX+5E09B64]

//[+0x2A][+3/+4]
#define MapMemoryAlloc_047					0x0050C10B+4	//0FBF9408 6A9B MOVSX EDX,WORD PTR DS:[EAX+ECX+5E09B6A]
#define MapMemoryAlloc_048					0x0050C197+3	//8A9408 6A9BE0 MOV DL,BYTE PTR DS:[EAX+ECX+5E09B6A]
#define MapMemoryAlloc_049					0x0050C213+4	//0FBF9408 6A9B MOVSX EDX,WORD PTR DS:[EAX+ECX+5E09B6A]

//[+0x88][+3]
#define MapMemoryAlloc_050					0x0050C13A+3	//8B8411 C89BE0>|MOV EAX,DWORD PTR DS:[ECX+EDX+5E09BC8]
#define MapMemoryAlloc_051					0x0050C166+3	//8B8C02 C89BE0>|MOV ECX,DWORD PTR DS:[EDX+EAX+5E09BC8]

//[+0xD4][+3]
#define MapMemoryAlloc_052					0x00503B9A+3	//8A8411 149CE0>MOV AL,BYTE PTR DS:[ECX+EDX+5E09C14]
#define MapMemoryAlloc_053					0x00503BD7+3	//8A8C02 149CE0>MOV CL,BYTE PTR DS:[EDX+EAX+5E09C14]
#define MapMemoryAlloc_054					0x00503C6F+3	//8A8411 149CE0>MOV AL,BYTE PTR DS:[ECX+EDX+5E09C14]
#define MapMemoryAlloc_055					0x00505687+3	//8A8C02 149CE0>|MOV CL,BYTE PTR DS:[EDX+EAX+5E09C14]
#define MapMemoryAlloc_056					0x0050C0BC+3	//8A8411 149CE0>|MOV AL,BYTE PTR DS:[ECX+EDX+5E09C14]
#define MapMemoryAlloc_057					0x00555168+3	//8A8C02 149CE0>MOV CL,BYTE PTR DS:[EDX+EAX+5E09C14]

//[+0xD5][+3]
#define MapMemoryAlloc_058					0x00503B11+3	//8A8411 159CE0 MOV AL,BYTE PTR DS:[ECX+EDX+5E09C15]
#define MapMemoryAlloc_059					0x00503B4E+3	//8A8C02 159CE0 MOV CL,BYTE PTR DS:[EDX+EAX+5E09C15]
#define MapMemoryAlloc_060					0x00503C4D+3	//8A8411 159CE0 MOV AL,BYTE PTR DS:[ECX+EDX+5E09C15]
#define MapMemoryAlloc_061					0x0050566A+3	//8A8C02 159CE0 MOV CL,BYTE PTR DS:[EDX+EAX+5E09C15]
#define MapMemoryAlloc_062					0x0050C0E3+3	//8A8C02 159CE0 MOV CL,BYTE PTR DS:[EDX+EAX+5E09C15]
#define MapMemoryAlloc_063					0x0055518F+3	//8A8C02 159CE0 MOV CL,BYTE PTR DS:[EDX+EAX+5E09C15]

//[+0xD6][+3]
#define MapMemoryAlloc_064					0x004F8775+3	//8A8C02 169CE0 MOV CL,BYTE PTR DS:[EDX+EAX+5E09C16]
#define MapMemoryAlloc_065					0x005056C8+3	//8A8C02 169CE0 MOV CL,BYTE PTR DS:[EDX+EAX+5E09C16]
#define MapMemoryAlloc_066					0x00555247+3	//C68402 169CE0 MOV BYTE PTR DS:[EDX+EAX+5E09C16],0

//[+0xD7][+3]
#define MapMemoryAlloc_067					0x005056E8+3	//8A8C02 179CE0>|MOV CL,BYTE PTR DS:[EDX+EAX+5E09C17]
#define MapMemoryAlloc_068					0x00555227+3	//C68408 179CE0>MOV BYTE PTR DS:[EAX+ECX+5E09C17],1

//[+0xD8][+3]
#define MapMemoryAlloc_069					0x00505638+3	//83BC11 189CE0>|CMP DWORD PTR DS:[ECX+EDX+5E09C18],8
#define MapMemoryAlloc_070					0x0050C088+3	//83BC08 189CE0>|CMP DWORD PTR DS:[EAX+ECX+5E09C18],1
#define MapMemoryAlloc_071					0x00555204+3	//C78411 189CE0>MOV DWORD PTR DS:[ECX+EDX+5E09C18],8

//[+0xDC][+3]
#define MapMemoryAlloc_072					0x0042C5EC+3	//898411 1C9CE0>MOV DWORD PTR DS:[ECX+EDX+5E09C1C],EAX
#define MapMemoryAlloc_073					0x0042C652+3	//898411 1C9CE0>MOV DWORD PTR DS:[ECX+EDX+5E09C1C],EAX

//[+0xE4][+3]
#define MapMemoryAlloc_074					0x0042C613+3	//898411 249CE0>MOV DWORD PTR DS:[ECX+EDX+5E09C24],EAX
#define MapMemoryAlloc_075					0x0042C679+3	//898411 249CE0>MOV DWORD PTR DS:[ECX+EDX+5E09C24],EAX

//[+0x00][+1/+2]
#define MapMemoryAlloc_076					0x0040D7C4+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_077					0x0040DD27+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_078					0x0040E80B+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_079					0x0040E8A8+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_080					0x0040E95C+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_081					0x0040EE50+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_082					0x0040EE8F+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_083					0x0040EFE1+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_084					0x004123A2+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_085					0x00412502+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_086					0x004133BE+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_087					0x00413A12+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_088					0x0041598E+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_089					0x00415A04+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_090					0x00415B26+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_091					0x00415E2F+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_092					0x00415E97+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_093					0x00415F3D+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_094					0x004164C6+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_095					0x0041688F+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_096					0x004168D6+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_097					0x00416A6F+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_098					0x0041982A+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_099					0x00419885+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_100					0x00419B42+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_101					0x00419B6E+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_102					0x00419E18+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_103					0x0041A5F7+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_104					0x0041A636+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_105					0x0041A752+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_106					0x0041BB87+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_107					0x0041C5BA+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_108					0x0041D18D+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_109					0x0041D2D4+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_110					0x0041D3EC+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_111					0x00423777+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_112					0x0042397D+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_113					0x00423ABE+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_114					0x0042C596+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_115					0x00438E9E+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_116					0x0043948A+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_117					0x0043994C+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_118					0x00439B2B+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_119					0x0043C153+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_120					0x0043C67A+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_121					0x0044B3FC+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_122					0x0044B60A+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_123					0x0044BD73+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_124					0x0044BDA7+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_125					0x0044C4C4+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_126					0x0044C4F6+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_127					0x004731D2+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_128					0x004823BF+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_129					0x004829BA+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_130					0x00482E10+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_131					0x0048323E+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_132					0x00483694+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_133					0x00483B59+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_134					0x00483F72+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_135					0x004846BC+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_136					0x0048482E+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_137					0x00484A96+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_138					0x004851E5+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_139					0x0048826C+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_140					0x00488B84+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_141					0x004890AD+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_142					0x0048F287+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_143					0x0048F755+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_144					0x0048FB95+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_145					0x00490025+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_146					0x004904A5+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_147					0x004908E5+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_148					0x00490D75+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_149					0x004911F5+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_150					0x00491635+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_151					0x00491AC5+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_152					0x00492B31+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_153					0x00492F31+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_154					0x004C7E6F+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_155					0x004DA2A5+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_156					0x004E1C5D+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_157					0x004E5B47+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_158					0x004E5BF1+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_159					0x004E5C37+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_160					0x004E5CBA+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_161					0x004E5D6A+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_162					0x004E6003+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_163					0x004E607C+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_164					0x004E61CB+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_165					0x004E62E0+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_166					0x004E6418+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_167					0x004E6461+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_168					0x004E723E+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_169					0x004E7556+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_170					0x004E9C74+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_171					0x004EBAD9+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_172					0x004EBB0D+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_173					0x004EC5B2+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_174					0x004EC5F9+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_175					0x004EC61B+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_176					0x004EC63D+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_177					0x004EC65F+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_178					0x004EE03D+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_179					0x004EE0F1+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_180					0x004EE117+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_181					0x004EE337+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_182					0x004EE823+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_183					0x004EE847+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_184					0x004F31A5+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_185					0x005049AD+2	//81C2 409BE005 ADD EDX,GameServ.05E09B40
#define MapMemoryAlloc_186					0x00507621+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_187					0x005076A2+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_188					0x00507767+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_189					0x005077FF+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_190					0x0050785B+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_191					0x005078E5+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_192					0x0050796F+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_193					0x00507A21+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_194					0x00507BA9+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_195					0x00507CA1+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_196					0x00507CE0+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_197					0x00507D1F+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_198					0x005080D6+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_199					0x0050929A+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_200					0x0050E1DA+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_201					0x0050E20C+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_202					0x00514D1F+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_203					0x00514D69+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_204					0x005150F6+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_205					0x005157E5+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_206					0x00515809+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_207					0x0051A4FD+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_208					0x0051A66D+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_209					0x0051A7FF+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_210					0x0051C865+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_211					0x0051CC9A+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_212					0x00534E3A+1	//68   409BE005 PUSH GameServ.05E09B40
#define MapMemoryAlloc_213					0x00534EA5+1	//68   409BE005 PUSH GameServ.05E09B40
#define MapMemoryAlloc_214					0x005367DE+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_215					0x0053680F+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_216					0x005437F1+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_217					0x00544FD5+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_218					0x005494BC+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_219					0x00550765+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_220					0x00554B4C+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_221					0x0055996B+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_222					0x005599ED+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_223					0x00559A13+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_224					0x00559B42+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_225					0x00559B76+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_226					0x0055AC62+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_227					0x005628EB+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_228					0x005637B6+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_229					0x0058EAAA+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_230					0x005936CD+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_231					0x00598E4F+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_232					0x0059C8EE+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_233					0x0059C93E+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_234					0x0059CBAC+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_235					0x0059CBD8+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_236					0x0059CED7+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_237					0x0059D164+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_238					0x0059D1D8+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_239					0x0059D28C+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_240					0x0059D558+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_241					0x0059D5CE+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_242_cs				0x0059D680+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_243_cs				0x005AF476+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40
#define MapMemoryAlloc_244_cs				0x005AF555+2	//81C1 409BE005 ADD ECX,GameServ.05E09B40

//Kanturu, CryWolf Terrains
#define MapMemoryAlloc_242					0x005B7F93+2	//MOV EDX,DWORD PTR DS:[6A61B28] //Kanturu
#define MapMemoryAlloc_243					0x005A14C2+2	//MOV EDX,DWORD PTR DS:[68CC920] //CryWolf

//Lorren Terrains
#define MapMemoryAlloc_244					0x00572764+2	//MOV ECX,DWORD PTR DS:[6788780] BASE: 67886F8 + 0x88
#define MapMemoryAlloc_245					0x00572779+2	//MOV ECX,DWORD PTR DS:[6788780]
#define MapMemoryAlloc_246					0x005727CC+2	//MOV EAX,DWORD PTR DS:[6788780]
#define MapMemoryAlloc_247					0x005727E0+2	//MOV EAX,DWORD PTR DS:[6788780]
#define MapMemoryAlloc_248					0x005768E6+2	//MOV EAX,DWORD PTR DS:[6788780]
#define MapMemoryAlloc_249					0x0057696D+2	//MOV EAX,DWORD PTR DS:[6788780]
#define MapMemoryAlloc_250					0x005769F4+2	//MOV EAX,DWORD PTR DS:[6788780]
#define MapMemoryAlloc_251					0x00576EBD+2	//MOV EAX,DWORD PTR DS:[6788780]
#define MapMemoryAlloc_252					0x00576F44+2	//MOV EAX,DWORD PTR DS:[6788780]

#define MapInit_Jump_Check						0x004EC66A
#define MapInit_Map_Quantity_01					0x00534E34
#define MapInit_Map_Quantity_02					0x00534E9F
#define MapInit_Map_Quantity_03					0x005367D2

#define MapInit_Skip_Att_Check					0x00535F4F
#define MapInit_Att_Load						0x005367F2
#define MapInit_Att_CLOSE_Addr_00				0x40 // MAP BUFFER SIZE
#define MapInit_Att_CLOSE_Addr_01				0x81 // ADD ECX
#define MapInit_Att_CLOSE_Addr_02				0xC1 // ADD ECX
#define MapInit_Att_CLOSE_Addr_03				0x0C // ATT OFFSET BACKWARDS [GSCS: terrain35_PEACE.att PUSH 00 71 96 0C]
#define MapInit_Att_CLOSE_Addr_04				0x96 // ATT OFFSET BACKWARDS
#define MapInit_Att_CLOSE_Addr_05				0x71 // ATT OFFSET BACKWARDS
#define MapInit_Att_CLOSE_Addr_06				0x00 // ATT OFFSET BACKWARDS
#define MapInit_Att_CLOSE_Addr_07				0xEB // JUMP
#define MapInit_Att_CLOSE_Addr_08				0x0A // 10 OFFSETS AWAY

#define MapInit_Att_PUSH_ECX					0x00536805
#define MapInit_Final_JMP						0x00585DE9				
#define MapInit_PUSH_MAPS_ARRAY_ADDR			005367F5h
#define MapInit_Map_Quantity_ASM_01				005367CFh
#define MapInit_Map_Quantity_ASM_02				00515081h
#define MapInit_Map_Quantity_ASM_03				005150ABh
#define MapInit_Map_Quantity_ASM_04				005080C7h
#define MapInit_Map_Quantity_ASM_05				00514CF6h
#define MapInit_Map_Quantity_ASM_06				004A08FFh
#define MapInit_Map_Quantity_ASM_07				004E5AD8h
#define MapInit_Map_Quantity_ASM_08				00438998h
#define MapInit_Map_Quantity_ASM_09				0042BEB9h
#define MapInit_Map_Quantity_ASM_10				00585520h