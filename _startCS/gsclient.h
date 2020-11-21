#pragma once

#include "stdafx.h"
#include "packets.h"

class GSClient
{
public:
	GSClient();
	~GSClient();

	void GSPointsUP(LPOBJ player);
	void GSMixLevel(LPOBJ player);
	void GSCalChart(LPOBJ player);
	void GSMainOpts(LPOBJ player);

private:
	PLAYER_POINTS p;
	PLAYER_STATUS s;
	PLAYER_RESET  r;
	GLOBIN_MIX    g;
	CALCHARACTER  c;
	MAIN          m;
};

extern GSClient gClient;