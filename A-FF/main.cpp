#include "stdafx.h"
#include "Program.h"
#include "Player.h"
#include <iostream>
#include "Util.h"

int main(int argc, char* argv[]) {

	Program app = Program();

	int x = -16 + Util::Config::screenWidth / 2;
	int y = -16 + Util::Config::screenHeight / 2;

	new Player(x, y, 32, 32, "data/textures/moopi.bmp");


	app.run();

	app.quit();
	
	return 0;
}

