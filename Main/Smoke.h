#ifndef _SmokeEffect_H_
#define _SmokeEffect_H_

class cSmokeEffect
{
	public:
		cSmokeEffect();
		virtual ~cSmokeEffect();

		void Load();
		INT GetLineId(DWORD ItemType);

		struct sEffect
		{
			int Id;

			float R;
			float G;
			float B;
		};
};

extern cSmokeEffect gSmokeEffect;

extern cSmokeEffect::sEffect eColor[256];

#endif