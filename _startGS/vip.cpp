#include "stdafx.h"

_VIP _vip;

void _VIP::VipSettings()
{
	_vip.vip[0] = GetPrivateProfileInt("settings","iniciar_servidor_vip",0, ".\\configurações\\_settings.ID");
	_vip.vip[1] = GetPrivateProfileInt("settings","iniciar_vip_level",0, ".\\configurações\\_settings.ID");
}
