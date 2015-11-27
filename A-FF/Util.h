#pragma once
#include "stdafx.h"

namespace Util {
	
	namespace Config {

		extern const char *title;
		extern int screenHeight;
		extern int screenWidth;

	}
	
	namespace Globals {

		extern SDL_Renderer *sdlRenderer;

	}

	namespace Math {

		extern int min(int a, int b);
		extern double min(double a, double b);

		// TODO: Use template
		extern int clamp(int value, int min, int max);
		extern double clamp(double value, double min, double max);

	}
	
};

