#include "Program.h"
#include <stdio.h>

#include "RenderHandler.h"
#include "CollisionHandler.h"
#include "NPCHandler.h"
#include "EntityHandler.h"


Program::Program() {

	_state = STATES::STOPPED;

	FRAMERATE_INTERVAL = 1;

	_framerate = 0.0;
	_deltaTime = 0.0;

	_framerateLastTime	  = SDL_GetTicks();
	_framesSinceLastCheck = 0;


	SDL_Init(SDL_INIT_EVERYTHING);	// Alter this as needed on release

	entityHandler		= new EntityHandler();
	renderHandler		= new RenderHandler();
	collisionHandler	= new CollisionHandler();
	npcHandler			= new NPCHandler();

}



Program::~Program() {}



void Program::quit() {

	SDL_Quit();

}



void Program::run() {
	
	_state = STATES::RUNNING;

	
	mainUpdate();

}



void Program::mainUpdate() {

	SDL_Event sdlEvent;

	while (_state != STATES::QUIT) {

		// Check SDL_Event queue for quit event, else update handlers
		// -	Do not interrupt by using nested loop to check queue
		SDL_PollEvent(&sdlEvent);

		if (sdlEvent.type == SDL_QUIT) {
			_state = STATES::QUIT;
			break;
		}

		//------------------------
		//	Update handlers (Maintain appropriate order)
		//--------------------

		//entityHandler->update(_deltaTime);
		//collisionHandler->update();
		//npcHandler->update();
		renderHandler->update();
		
		// Calculate FPS at the end of each frame
		calculateFramerate();
		printf("FPS: %f\n", _framerate);

	}
	

}



void Program::calculateFramerate() {

	_framesSinceLastCheck++;

	Uint32 currentTime = SDL_GetTicks();

	if (_framerateLastTime < (currentTime - FRAMERATE_INTERVAL * 1000)) {

		_framerateLastTime = SDL_GetTicks();
		_framerate = _framesSinceLastCheck;

		_framesSinceLastCheck = 0;

	}


}



void Program::limitFramerate() {	// OBSOLETE

	// The functionality of this method is currently executed via applying VSYNC
	// -	to the SDL_Renderer, or RenderTarget.

}