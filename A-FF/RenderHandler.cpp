#include "RenderHandler.h"
#include "Util.h"
#include "Transform.h"
#include "Renderer.h"
#include <iostream>
#include "BaseEntity.h"
#include "Program.h"


std::vector<Renderer *> RenderHandler::_renderComponents;



RenderHandler::RenderHandler() {

	// Set up window to hold renderTarget
	_window = SDL_CreateWindow(
		Util::Config::title,
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		Util::Config::screenWidth, Util::Config::screenHeight,
		SDL_WINDOW_SHOWN
	);

	// Set up SDL_Renderer and globalize it
	_renderTarget = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	Util::Globals::sdlRenderer = _renderTarget;

}



RenderHandler::~RenderHandler() {

	SDL_DestroyWindow(_window);
	SDL_DestroyRenderer(_renderTarget);

	_renderComponents.clear();

}



void RenderHandler::update() {

	// Clear Screen
	SDL_RenderClear(_renderTarget);


	// Set Background Color
	SDL_SetRenderDrawColor(_renderTarget, 0, 0, 0, 255);


	//--------------------
	// Gather renderable data from all entities that own a renderer component
	//----------------
	for (Uint8 rendererIndex = 0; rendererIndex < _renderComponents.size(); rendererIndex++) {

		Renderer *renderComponent = _renderComponents[rendererIndex];
		
		// Generate SDL_Rect from entity's transform component
		SDL_Rect rect = SDL_Rect();
		rect.w = renderComponent->parentEntity->_transform->_width;
		rect.h = renderComponent->parentEntity->_transform->_height;
		rect.x = (int) renderComponent->parentEntity->_transform->_position.x;
		rect.y = (int) renderComponent->parentEntity->_transform->_position.y;

		// Get Texture angle from entity's transform component
		double angle = renderComponent->parentEntity->_transform->_angle;


		// Blit texture to screen (Make a simpler call if we can)
		if (!angle)
			SDL_RenderCopy(_renderTarget, renderComponent->_texture, NULL, &rect);
		else
			SDL_RenderCopyEx(_renderTarget, renderComponent->_texture, NULL, &rect, angle, NULL, SDL_FLIP_NONE);

		SDL_draw

	}


	// Render textures to screen
	SDL_RenderPresent(_renderTarget);

}



void RenderHandler::registerRenderer(Renderer *renderer) {

	_renderComponents.push_back(renderer);

}