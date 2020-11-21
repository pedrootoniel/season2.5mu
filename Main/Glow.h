#pragma once

class cGlowEffect
{
	public:
		cGlowEffect();
		virtual ~cGlowEffect();

		struct sITEM
		{
			int Type;
			int Item;
		};

		struct sFRGB
		{
			/* 0 .. 1 */
			float R,G,B;
		};

		int g_iItemCount;
		sFRGB eColor[515];
		sITEM eItem[512];

		void Load();
		static void GlowEffect(DWORD dwItemId,DWORD uk1,DWORD uk2,sFRGB& Color,BYTE bUkn);
};

extern cGlowEffect gGlow;
