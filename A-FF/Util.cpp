#include "Util.h"

using namespace Util;

//----------------
// Config
//------------

const char *Config::title	= "A-FF";
int Config::screenWidth		= 1024;
int Config::screenHeight	= 720;



//----------------
// Globals
//------------

SDL_Renderer *Globals::sdlRenderer = nullptr;



//----------------
// Math
//------------

int Util::Math::min(int a, int b) {
	return ((a < b) ? a : b);
}

double Util::Math::min(double a, double b) {
	return ((a < b) ? a : b);
}



int Util::Math::clamp(int value, int min, int max) {

	return ((value < min) ? min : ((value > max) ? max : value));

}



double Util::Math::clamp(double value, double min, double max) {

	return ((value < min) ? min : ((value > max) ? max : value));

}
