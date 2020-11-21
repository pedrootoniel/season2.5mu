#include "StdAfx.h"

unsigned char MapStruct[80][0x51068]={0x00};
unsigned char MapManagerStruct[0x10DC0]={0x00};

void FixMapAttribute()
{
    *(DWORD*)(0x40BAF6) = (DWORD)&MapStruct;
    *(DWORD*)(0x40C059) = (DWORD)&MapStruct;
    *(DWORD*)(0x40CB3D) = (DWORD)&MapStruct;
    *(DWORD*)(0x40CBDA) = (DWORD)&MapStruct;
    *(DWORD*)(0x40CC8E) = (DWORD)&MapStruct;
    *(DWORD*)(0x40D182) = (DWORD)&MapStruct;
    *(DWORD*)(0x40D1C1) = (DWORD)&MapStruct;
    *(DWORD*)(0x40D313) = (DWORD)&MapStruct;
    *(DWORD*)(0x4106D4) = (DWORD)&MapStruct;
    *(DWORD*)(0x410834) = (DWORD)&MapStruct;
    *(DWORD*)(0x4116F0) = (DWORD)&MapStruct;
    *(DWORD*)(0x411D44) = (DWORD)&MapStruct;
    *(DWORD*)(0x413D20) = (DWORD)&MapStruct;
    *(DWORD*)(0x413D96) = (DWORD)&MapStruct;
    *(DWORD*)(0x413EB8) = (DWORD)&MapStruct;
    *(DWORD*)(0x4141C1) = (DWORD)&MapStruct;
    *(DWORD*)(0x414229) = (DWORD)&MapStruct;
    *(DWORD*)(0x4142CF) = (DWORD)&MapStruct;
    *(DWORD*)(0x414858) = (DWORD)&MapStruct;
    *(DWORD*)(0x414C21) = (DWORD)&MapStruct;
    *(DWORD*)(0x414C68) = (DWORD)&MapStruct;
    *(DWORD*)(0x414E01) = (DWORD)&MapStruct;
    *(DWORD*)(0x417A0C) = (DWORD)&MapStruct;
    *(DWORD*)(0x417A67) = (DWORD)&MapStruct;
    *(DWORD*)(0x417D24) = (DWORD)&MapStruct;
    *(DWORD*)(0x417D50) = (DWORD)&MapStruct;
    *(DWORD*)(0x417FFA) = (DWORD)&MapStruct;
    *(DWORD*)(0x4187D9) = (DWORD)&MapStruct;
    *(DWORD*)(0x418818) = (DWORD)&MapStruct;
    *(DWORD*)(0x418934) = (DWORD)&MapStruct;
    *(DWORD*)(0x419F99) = (DWORD)&MapStruct;
    *(DWORD*)(0x41AACC) = (DWORD)&MapStruct;
    *(DWORD*)(0x41B69F) = (DWORD)&MapStruct;
    *(DWORD*)(0x41B7E6) = (DWORD)&MapStruct;
    *(DWORD*)(0x41B8FE) = (DWORD)&MapStruct;
    *(DWORD*)(0x421D99) = (DWORD)&MapStruct;
    *(DWORD*)(0x421F9F) = (DWORD)&MapStruct;
    *(DWORD*)(0x4220E0) = (DWORD)&MapStruct;
    *(DWORD*)(0x42ABB8) = (DWORD)&MapStruct;
    *(DWORD*)(0x435E60) = (DWORD)&MapStruct;
    *(DWORD*)(0x43644C) = (DWORD)&MapStruct;
    *(DWORD*)(0x43690E) = (DWORD)&MapStruct;
    *(DWORD*)(0x436AED) = (DWORD)&MapStruct;
    *(DWORD*)(0x439115) = (DWORD)&MapStruct;
    *(DWORD*)(0x43961D) = (DWORD)&MapStruct;
    *(DWORD*)(0x448F7E) = (DWORD)&MapStruct;
    *(DWORD*)(0x4496B6) = (DWORD)&MapStruct;
    *(DWORD*)(0x4496EA) = (DWORD)&MapStruct;
    *(DWORD*)(0x449D86) = (DWORD)&MapStruct;
    *(DWORD*)(0x449DB8) = (DWORD)&MapStruct;
    *(DWORD*)(0x46D294) = (DWORD)&MapStruct;
    *(DWORD*)(0x470EA1) = (DWORD)&MapStruct;
    *(DWORD*)(0x47149C) = (DWORD)&MapStruct;
    *(DWORD*)(0x4718F2) = (DWORD)&MapStruct;
    *(DWORD*)(0x471D20) = (DWORD)&MapStruct;
    *(DWORD*)(0x472176) = (DWORD)&MapStruct;
    *(DWORD*)(0x47263B) = (DWORD)&MapStruct;
    *(DWORD*)(0x472A54) = (DWORD)&MapStruct;
    *(DWORD*)(0x47319E) = (DWORD)&MapStruct;
    *(DWORD*)(0x473310) = (DWORD)&MapStruct;
    *(DWORD*)(0x473578) = (DWORD)&MapStruct;
    *(DWORD*)(0x473D07) = (DWORD)&MapStruct;
    *(DWORD*)(0x476D8E) = (DWORD)&MapStruct;
    *(DWORD*)(0x4776A6) = (DWORD)&MapStruct;
    *(DWORD*)(0x477BCF) = (DWORD)&MapStruct;
    *(DWORD*)(0x47DDA9) = (DWORD)&MapStruct;
    *(DWORD*)(0x47E277) = (DWORD)&MapStruct;
    *(DWORD*)(0x47E6B7) = (DWORD)&MapStruct;
    *(DWORD*)(0x47EB47) = (DWORD)&MapStruct;
    *(DWORD*)(0x47EFC7) = (DWORD)&MapStruct;
    *(DWORD*)(0x47F407) = (DWORD)&MapStruct;
    *(DWORD*)(0x47F897) = (DWORD)&MapStruct;
    *(DWORD*)(0x47FD17) = (DWORD)&MapStruct;
    *(DWORD*)(0x480157) = (DWORD)&MapStruct;
    *(DWORD*)(0x4805E7) = (DWORD)&MapStruct;
    *(DWORD*)(0x481283) = (DWORD)&MapStruct;
    *(DWORD*)(0x481683) = (DWORD)&MapStruct;
    *(DWORD*)(0x4B6221) = (DWORD)&MapStruct;
    *(DWORD*)(0x4C80B7) = (DWORD)&MapStruct;
    *(DWORD*)(0x4D004E) = (DWORD)&MapStruct;
    *(DWORD*)(0x4D3CC9) = (DWORD)&MapStruct;
    *(DWORD*)(0x4D3D73) = (DWORD)&MapStruct;
    *(DWORD*)(0x4D3DB9) = (DWORD)&MapStruct;
    *(DWORD*)(0x4D3E3C) = (DWORD)&MapStruct;
    *(DWORD*)(0x4D3EEC) = (DWORD)&MapStruct;
    *(DWORD*)(0x4D40B2) = (DWORD)&MapStruct;
    *(DWORD*)(0x4D412B) = (DWORD)&MapStruct;
    *(DWORD*)(0x4D427A) = (DWORD)&MapStruct;
    *(DWORD*)(0x4D438F) = (DWORD)&MapStruct;
    *(DWORD*)(0x4D44C7) = (DWORD)&MapStruct;
    *(DWORD*)(0x4D4510) = (DWORD)&MapStruct;
    *(DWORD*)(0x4D5269) = (DWORD)&MapStruct;
    *(DWORD*)(0x4D5581) = (DWORD)&MapStruct;
    *(DWORD*)(0x4D7C5F) = (DWORD)&MapStruct;
    *(DWORD*)(0x4D9ADB) = (DWORD)&MapStruct;
    *(DWORD*)(0x4D9B0F) = (DWORD)&MapStruct;
    *(DWORD*)(0x4DA5B4) = (DWORD)&MapStruct;
    *(DWORD*)(0x4DA5FB) = (DWORD)&MapStruct;
    *(DWORD*)(0x4DA61D) = (DWORD)&MapStruct;
    *(DWORD*)(0x4DA63F) = (DWORD)&MapStruct;
    *(DWORD*)(0x4DA661) = (DWORD)&MapStruct;
    *(DWORD*)(0x4DBE40) = (DWORD)&MapStruct;
    *(DWORD*)(0x4DBEE1) = (DWORD)&MapStruct;
    *(DWORD*)(0x4DBF07) = (DWORD)&MapStruct;
    *(DWORD*)(0x4DC079) = (DWORD)&MapStruct;
    *(DWORD*)(0x4DC33A) = (DWORD)&MapStruct;
    *(DWORD*)(0x4DC360) = (DWORD)&MapStruct;
    *(DWORD*)(0x4E0A47) = (DWORD)&MapStruct;
    *(DWORD*)(0x4F04EC) = (DWORD)&MapStruct+0x10;
    *(DWORD*)(0x4F0569) = (DWORD)&MapStruct+0x10;
    *(DWORD*)(0x4F0597) = (DWORD)&MapStruct+0x10;
    *(DWORD*)(0x4F1C0F) = (DWORD)&MapStruct;
    *(DWORD*)(0x4F46A3) = (DWORD)&MapStruct;
    *(DWORD*)(0x4F4724) = (DWORD)&MapStruct;
    *(DWORD*)(0x4F47E9) = (DWORD)&MapStruct;
    *(DWORD*)(0x4F4881) = (DWORD)&MapStruct;
    *(DWORD*)(0x4F48DD) = (DWORD)&MapStruct;
    *(DWORD*)(0x4F4967) = (DWORD)&MapStruct;
    *(DWORD*)(0x4F49F1) = (DWORD)&MapStruct;
    *(DWORD*)(0x4F4AA3) = (DWORD)&MapStruct;
    *(DWORD*)(0x4F4AF3) = (DWORD)&MapStruct;
    *(DWORD*)(0x4F4B46) = (DWORD)&MapStruct;
    *(DWORD*)(0x4F4D37) = (DWORD)&MapStruct;
    *(DWORD*)(0x4F508D) = (DWORD)&MapStruct;
    *(DWORD*)(0x4F601C) = (DWORD)&MapStruct;
    *(DWORD*)(0x4FA9FC) = (DWORD)&MapStruct;
    *(DWORD*)(0x4FAA2E) = (DWORD)&MapStruct;
    *(DWORD*)(0x501231) = (DWORD)&MapStruct;
    *(DWORD*)(0x50127B) = (DWORD)&MapStruct;
    *(DWORD*)(0x50160A) = (DWORD)&MapStruct;
    *(DWORD*)(0x501666) = (DWORD)&MapStruct;
    *(DWORD*)(0x501D77) = (DWORD)&MapStruct;
    *(DWORD*)(0x501D9B) = (DWORD)&MapStruct;
    *(DWORD*)(0x505E6F) = (DWORD)&MapStruct;
    *(DWORD*)(0x505FDF) = (DWORD)&MapStruct;
    *(DWORD*)(0x508087) = (DWORD)&MapStruct;
    *(DWORD*)(0x5084BC) = (DWORD)&MapStruct;
    *(DWORD*)(0x521B52) = (DWORD)&MapStruct;
    *(DWORD*)(0x521B83) = (DWORD)&MapStruct;
    *(DWORD*)(0x52E901) = (DWORD)&MapStruct;
    *(DWORD*)(0x52FF67) = (DWORD)&MapStruct;
    *(DWORD*)(0x53444E) = (DWORD)&MapStruct;
    *(DWORD*)(0x5361FF) = (DWORD)&MapStruct+0x10;
    *(DWORD*)(0x536220) = (DWORD)&MapStruct+0x10;
    *(DWORD*)(0x53630F) = (DWORD)&MapStruct+0x10;
    *(DWORD*)(0x536330) = (DWORD)&MapStruct+0x10;
    *(DWORD*)(0x53641F) = (DWORD)&MapStruct+0x10;
    *(DWORD*)(0x536440) = (DWORD)&MapStruct+0x10;
    *(DWORD*)(0x536533) = (DWORD)&MapStruct+0x10;
    *(DWORD*)(0x536554) = (DWORD)&MapStruct+0x10;
    *(DWORD*)(0x536693) = (DWORD)&MapStruct+0x10;
    *(DWORD*)(0x5366B4) = (DWORD)&MapStruct+0x10;
    *(DWORD*)(0x5367F3) = (DWORD)&MapStruct+0x10;
    *(DWORD*)(0x536814) = (DWORD)&MapStruct+0x10;
    *(DWORD*)(0x5368F5) = (DWORD)&MapStruct+0x10;
    *(DWORD*)(0x536913) = (DWORD)&MapStruct+0x10;
    *(DWORD*)(0x5369C5) = (DWORD)&MapStruct+0x10;
    *(DWORD*)(0x5369E3) = (DWORD)&MapStruct+0x10;
    *(DWORD*)(0x53B6F7) = (DWORD)&MapStruct;
    *(DWORD*)(0x53FADE) = (DWORD)&MapStruct;
    *(DWORD*)(0x53FC54) = (DWORD)&MapStruct+0x10;
    *(DWORD*)(0x53FF3D) = (DWORD)&MapStruct+0x10;
    *(DWORD*)(0x540568) = (DWORD)&MapStruct+0x10;
    *(DWORD*)(0x540589) = (DWORD)&MapStruct+0x10;
    *(DWORD*)(0x5406F3) = (DWORD)&MapStruct+0x10;
    *(DWORD*)(0x540714) = (DWORD)&MapStruct+0x10;
    *(DWORD*)(0x5448FD) = (DWORD)&MapStruct;
    *(DWORD*)(0x54497F) = (DWORD)&MapStruct;
    *(DWORD*)(0x5449A5) = (DWORD)&MapStruct;
    *(DWORD*)(0x544AD4) = (DWORD)&MapStruct;
    *(DWORD*)(0x544B08) = (DWORD)&MapStruct;
    *(DWORD*)(0x544E17) = (DWORD)&MapStruct+0x10;
    *(DWORD*)(0x54555F) = (DWORD)&MapStruct+0x10;
    *(DWORD*)(0x545580) = (DWORD)&MapStruct+0x10;
    *(DWORD*)(0x54562F) = (DWORD)&MapStruct+0x10;
    *(DWORD*)(0x545650) = (DWORD)&MapStruct+0x10;
    *(DWORD*)(0x54577F) = (DWORD)&MapStruct+0x10;
    *(DWORD*)(0x5457A0) = (DWORD)&MapStruct+0x10;
    *(DWORD*)(0x54584F) = (DWORD)&MapStruct+0x10;
    *(DWORD*)(0x545870) = (DWORD)&MapStruct+0x10;
    *(DWORD*)(0x545BF4) = (DWORD)&MapStruct;
    *(DWORD*)(0x545DC9) = (DWORD)&MapStruct+0x10;
    *(DWORD*)(0x5461B3) = (DWORD)&MapStruct+0x10;
    *(DWORD*)(0x54BCF8) = (DWORD)&MapStruct;
    *(DWORD*)(0x556D6C) = (DWORD)&MapStruct;
    *(DWORD*)(0x55B98F) = (DWORD)&MapStruct;
    *(DWORD*)(0x561211) = (DWORD)&MapStruct;
    *(DWORD*)(0x564D40) = (DWORD)&MapStruct;
    *(DWORD*)(0x564D90) = (DWORD)&MapStruct;
    *(DWORD*)(0x564FFE) = (DWORD)&MapStruct;
    *(DWORD*)(0x56502A) = (DWORD)&MapStruct;
    *(DWORD*)(0x565329) = (DWORD)&MapStruct;
    *(DWORD*)(0x5655B6) = (DWORD)&MapStruct;
    *(DWORD*)(0x56562A) = (DWORD)&MapStruct;
    *(DWORD*)(0x5656DE) = (DWORD)&MapStruct;
    *(DWORD*)(0x5659AA) = (DWORD)&MapStruct;
    *(DWORD*)(0x565A20) = (DWORD)&MapStruct;
    *(DWORD*)(0x565AD2) = (DWORD)&MapStruct;
    *(DWORD*)(0x579F58) = (DWORD)&MapStruct;
    *(DWORD*)(0x57A037) = (DWORD)&MapStruct;
    
    
    *(DWORD*)(0x42AC0F) = (DWORD)&MapStruct+0xDC;
    *(DWORD*)(0x42AC36) = (DWORD)&MapStruct+0xE4;
    *(DWORD*)(0x42AC75) = (DWORD)&MapStruct+0xDC;
    *(DWORD*)(0x42AC9C) = (DWORD)&MapStruct+0xE4;
    *(DWORD*)(0x4359CC) = (DWORD)&MapStruct+0x20;
    *(DWORD*)(0x4E5C58) = (DWORD)&MapStruct+0xD6;
    *(DWORD*)(0x4E5C84) = (DWORD)&MapStruct+0x24;
    *(DWORD*)(0x4E5D80) = (DWORD)&MapStruct+0x20;
    *(DWORD*)(0x4E5D9D) = (DWORD)&MapStruct+0x24;
    *(DWORD*)(0x4F0D46) = (DWORD)&MapStruct+0x24;
    *(DWORD*)(0x4F0D74) = (DWORD)&MapStruct+0xD5;
    *(DWORD*)(0x4F0DB1) = (DWORD)&MapStruct+0xD5;
    *(DWORD*)(0x4F0DFD) = (DWORD)&MapStruct+0xD4;
    *(DWORD*)(0x4F0E3A) = (DWORD)&MapStruct+0xD4;
    *(DWORD*)(0x4F0EB0) = (DWORD)&MapStruct+0xD5;
    *(DWORD*)(0x4F0ED2) = (DWORD)&MapStruct+0xD4;
    *(DWORD*)(0x4F0EF2) = (DWORD)&MapStruct+0x24;
    *(DWORD*)(0x4F2853) = (DWORD)&MapStruct+0x24;
    *(DWORD*)(0x4F287B) = (DWORD)&MapStruct+0xD8;
    *(DWORD*)(0x4F28AD) = (DWORD)&MapStruct+0xD5;
    *(DWORD*)(0x4F28CA) = (DWORD)&MapStruct+0xD4;
    *(DWORD*)(0x4F290B) = (DWORD)&MapStruct+0xD6;
    *(DWORD*)(0x4F292B) = (DWORD)&MapStruct+0xD7;
    *(DWORD*)(0x4F89E5) = (DWORD)&MapStruct+0xD8;
    *(DWORD*)(0x4F8A16) = (DWORD)&MapStruct+0xD4;
    *(DWORD*)(0x4F8A3E) = (DWORD)&MapStruct+0xD5;
    *(DWORD*)(0x4F8A94) = (DWORD)&MapStruct+0x88;
    *(DWORD*)(0x4F8AC0) = (DWORD)&MapStruct+0x88;
    *(DWORD*)(0x4F8AF1) = (DWORD)&MapStruct+0x2A;
    *(DWORD*)(0x4F8BCC) = (DWORD)&MapStruct+0x20;
    *(DWORD*)(0x4F8BF2) = (DWORD)&MapStruct+0x24;
    *(DWORD*)(0x5400CD) = (DWORD)&MapStruct+0x24;
    *(DWORD*)(0x5400FB) = (DWORD)&MapStruct+0xD4;
    *(DWORD*)(0x540122) = (DWORD)&MapStruct+0xD5;
    *(DWORD*)(0x540197) = (DWORD)&MapStruct+0xD8;
    *(DWORD*)(0x5401BA) = (DWORD)&MapStruct+0xD7;
    *(DWORD*)(0x5401DA) = (DWORD)&MapStruct+0xD6;
       
    *(DWORD*)(0x4F8A67) = (DWORD)&MapStruct+0x2A;
    *(DWORD*)(0x4F8B6C) = (DWORD)&MapStruct+0x2A;
    
    *(DWORD*)(0x52020B) = (DWORD)&MapStruct;
    *(DWORD*)(0x520276) = (DWORD)&MapStruct;

	*(DWORD*)(0x00582B15) = (DWORD)&MapStruct[39][0x10];
	*(DWORD*)(0x00569974) = (DWORD)&MapStruct[34][0x10];

}
void FixMapManager()
{
	BYTE NewSize = 0x9D;

	*(DWORD*)(0x0054DC97) = NewSize*0x190+0x08;
	*(DWORD*)(0x0054E040) = NewSize*0x190+0x08;
	*(DWORD*)(0x0054E09F) = NewSize*0x190+0x08;
	*(DWORD*)(0x0054E13C) = NewSize*0x190+0x08;
	*(DWORD*)(0x0054E14D) = NewSize*0x190+0x08;

	*(DWORD*)(0x0054daa2) = NewSize*0x190+0x58;
	*(DWORD*)(0x0054dbd6) = NewSize*0x190+0x58;
	*(DWORD*)(0x0054dcdf) = NewSize*0x190+0x58;
	*(DWORD*)(0x0054e129) = NewSize*0x190+0x58;
	*(DWORD*)(0x0054e28f) = NewSize*0x190+0x58;
	*(DWORD*)(0x0054e2a4) = NewSize*0x190+0x58;
	*(DWORD*)(0x0054e52E) = NewSize*0x190+0x58;
	*(DWORD*)(0x0054e543) = NewSize*0x190+0x58;
	*(DWORD*)(0x0054eef3) = NewSize*0x190+0x58;
	*(DWORD*)(0x0054ef05) = NewSize*0x190+0x58;
	*(DWORD*)(0x0054ef89) = NewSize*0x190+0x58;
	*(DWORD*)(0x0054efab) = NewSize*0x190+0x58;
	*(DWORD*)(0x0054f13e) = NewSize*0x190+0x58;
	*(DWORD*)(0x0054f150) = NewSize*0x190+0x58;
	*(DWORD*)(0x0054f1c6) = NewSize*0x190+0x58;
	*(DWORD*)(0x0054f1ee) = NewSize*0x190+0x58;
	*(DWORD*)(0x0054f38b) = NewSize*0x190+0x58;
	*(DWORD*)(0x0054f3a0) = NewSize*0x190+0x58;
	*(DWORD*)(0x0054f422) = NewSize*0x190+0x58;
	*(DWORD*)(0x0054f44f) = NewSize*0x190+0x58;
	*(DWORD*)(0x0054f7ee) = NewSize*0x190+0x58;
	*(DWORD*)(0x0054f800) = NewSize*0x190+0x58;

	*(DWORD*)(0x0054DAE2) = NewSize*0x190+0x68;
	*(DWORD*)(0x0054DBC6) = NewSize*0x190+0x68;
	*(DWORD*)(0x0054DD7D) = NewSize*0x190+0x68;
	*(DWORD*)(0x0054E5E4) = NewSize*0x190+0x68;
	*(DWORD*)(0x0054EED4) = NewSize*0x190+0x68;
	*(DWORD*)(0x0054EF33) = NewSize*0x190+0x68;
	*(DWORD*)(0x0054EF75) = NewSize*0x190+0x68;
	*(DWORD*)(0x0054F00E) = NewSize*0x190+0x68;
	*(DWORD*)(0x0054F11F) = NewSize*0x190+0x68;
	*(DWORD*)(0x0054F17E) = NewSize*0x190+0x68;
	*(DWORD*)(0x0054F1B2) = NewSize*0x190+0x68;
	*(DWORD*)(0x0054F248) = NewSize*0x190+0x68;
	*(DWORD*)(0x0054F366) = NewSize*0x190+0x68;
	*(DWORD*)(0x0054F3CE) = NewSize*0x190+0x68;
	*(DWORD*)(0x0054F40B) = NewSize*0x190+0x68;
	*(DWORD*)(0x0054F4A8) = NewSize*0x190+0x68;
	*(DWORD*)(0x0054F7CA) = NewSize*0x190+0x68;
	*(DWORD*)(0x0054F82D) = NewSize*0x190+0x68;

	*(DWORD*)(0x0042d531) = NewSize*0x190+0x80;
	*(DWORD*)(0x0042d53d) = NewSize*0x190+0x80;
	*(DWORD*)(0x0054dad6) = NewSize*0x190+0x80;
	*(DWORD*)(0x0054e56e) = NewSize*0x190+0x80;
	*(DWORD*)(0x0054e579) = NewSize*0x190+0x80;
	*(DWORD*)(0x0054e586) = NewSize*0x190+0x80;
	*(DWORD*)(0x0054ecd5) = NewSize*0x190+0x80;
	*(DWORD*)(0x0054ede7) = NewSize*0x190+0x80;

	*(DWORD*)(0x0054dcbe) = NewSize*0x14;
	*(DWORD*)(0x0054e08a) = NewSize*0x14;

	*(DWORD*)(0x0042268E) = (DWORD)&MapManagerStruct;
	*(DWORD*)(0x0042286A) = (DWORD)&MapManagerStruct;
	*(DWORD*)(0x004233D1) = (DWORD)&MapManagerStruct;
	*(DWORD*)(0x004235CC) = (DWORD)&MapManagerStruct;
	*(DWORD*)(0x004283DB) = (DWORD)&MapManagerStruct;
	*(DWORD*)(0x0042D419) = (DWORD)&MapManagerStruct;
	*(DWORD*)(0x0042D663) = (DWORD)&MapManagerStruct;
	*(DWORD*)(0x0042D7E3) = (DWORD)&MapManagerStruct;
	*(DWORD*)(0x0042F21E) = (DWORD)&MapManagerStruct;
	*(DWORD*)(0x0042F260) = (DWORD)&MapManagerStruct;
	*(DWORD*)(0x004D3FCB) = (DWORD)&MapManagerStruct;
	*(DWORD*)(0x004D851E) = (DWORD)&MapManagerStruct;
	*(DWORD*)(0x004F4D5E) = (DWORD)&MapManagerStruct;
	*(DWORD*)(0x004FC040) = (DWORD)&MapManagerStruct;
	*(DWORD*)(0x004FCB71) = (DWORD)&MapManagerStruct;
	*(DWORD*)(0x005210B6) = (DWORD)&MapManagerStruct;
	*(DWORD*)(0x0052E15A) = (DWORD)&MapManagerStruct;
	*(DWORD*)(0x0054d505) = (DWORD)&MapManagerStruct;
	*(DWORD*)(0x0054f8da) = (DWORD)&MapManagerStruct;
	*(DWORD*)(0x0054f92a) = (DWORD)&MapManagerStruct;
	*(DWORD*)(0x0056c093) = (DWORD)&MapManagerStruct;
	*(DWORD*)(0x0056c0e8) = (DWORD)&MapManagerStruct;
	*(DWORD*)(0x0056c137) = (DWORD)&MapManagerStruct;
	*(DWORD*)(0x0056f9f6) = (DWORD)&MapManagerStruct;
}
void HookNovosMapas()
{
	FixMapAttribute();
	FixMapManager();

	BYTE cMapLoadFix[] = { 0xFF,0x15,0x4B,0x4A,0x5D,0x00,0xE9,0xC2,0x08,0x00,0x00 } ;
	*(DWORD*)(0x005D4A4B) = (DWORD)&MapLoad;
	memcpy ((int *)0x005212C1 ,cMapLoadFix ,sizeof(cMapLoadFix));
		
	memset((PBYTE) 0x0040BA80, 0x3C, 1 );
	memset((PBYTE) 0x0042A4DC, 0x3C, 1 );
	memset((PBYTE) 0x0043595B, 0x3C, 1 );
	memset((PBYTE) 0x0048F732, 0x3C, 1 );//27
	memset((PBYTE) 0x004D2983, 0x3C, 1 );//27
	memset((PBYTE) 0x004D3C5A, 0x3C, 1 );//27
	memset((PBYTE) 0x004D9AA3, 0x3C, 1 );
	memset((PBYTE) 0x004DA42E, 0x3C, 1 );
	memset((PBYTE) 0x004DBD00, 0x3C, 1 );
	memset((PBYTE) 0x004DC170, 0x3C, 1 );
	memset((PBYTE) 0x0054E442, 0x3C, 1 );
	memset((PBYTE) 0x004F507F, 0x3D, 1 );//33
	memset((PBYTE) 0x00501209, 0x3D, 1 );
	memset((PBYTE) 0x00501594, 0x3D, 1 );//33
	memset((PBYTE) 0x005015BE, 0x3D, 1 );//33
	memset((PBYTE) 0x00520204, 0x3D, 1 );//33
	memset((PBYTE) 0x0052026F, 0x3D, 1 );
	memset((PBYTE) 0x0052E8F3, 0x3D, 1 );
	memset((PBYTE) 0x0054D9D7, 0x3D, 1 );//33
	memset((PBYTE) 0x0047CAB2, 0x3D, 1 );//33

	_asm
	{
		MOV BYTE PTR DS:[0x4DA66A],0x0E9;
		MOV BYTE PTR DS:[0x4DA66B],0x0A1;
		MOV BYTE PTR DS:[0x4DA66C],0x00;
		MOV BYTE PTR DS:[0x4DA66D],0x00;
		MOV BYTE PTR DS:[0x4DA66E],0x00;
		MOV BYTE PTR DS:[0x4DA66F],0x90;
		MOV BYTE PTR DS:[0x54ED09],0x0EB;
	}
}
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
	"terrain45.att", //44  //IllusionTemple 1
	"terrain46.att", //45  //IllusionTemple 2
	"terrain47.att", //46  //IllusionTemple 3
	"terrain48.att", //47  //IllusionTemple 4
	"terrain49.att", //48  //IllusionTemple 5
	"terrain50.att", //49  //IllusionTemple 6
};

void MapLoad()
{
	for(int i=0;i<50;i++)
	{
		_asm
		{
			Mov Ecx, i
			Imul Ecx, Ecx, 0x51068
			Add Ecx, offset MapStruct
			Mov Eax, 0x00403A6C
			Call Eax
			Mov Eax, i
			Push Eax
			Mov Ecx, i
			Imul Ecx, Ecx, 0FH
			Add Ecx, offset MapBuff
			Push Ecx
			Mov Ecx, 0x0AC9DC10
			Mov Eax, 0x00402EDC
			Call Eax
			Push Eax
			Mov Ecx, i
			Imul Ecx, Ecx, 0x51068
			Add Ecx, offset MapStruct
			Mov Eax,  0x00403698
			Call Eax
		}
	}
}