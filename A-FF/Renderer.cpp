#include "Renderer.h"
#include "Util.h"
#include "BaseEntity.h"

// Don't like that I have to do this...
#include "RenderHandler.h"


int Renderer::total = 0;



Renderer::Renderer(BaseEntity *entity) {
	
	this->parentEntity = entity;

	_id = total + 1;
	_texture = nullptr;

	RenderHandler::registerRenderer(this);

}



Renderer::Renderer(BaseEntity *entity, std::string texturePath) {

	this->parentEntity = entity;

	_id = total + 1;
	generateTexture(texturePath);

	RenderHandler::registerRenderer(this);

}

 

Renderer::~Renderer() {
	SDL_DestroyTexture(_texture);
}



void Renderer::generateTexture(std::string texturePath) {

	SDL_Surface *surface = IMG_Load(texturePath.c_str());

	_texture = SDL_CreateTextureFromSurface(Util::Globals::sdlRenderer, surface);
	SDL_FreeSurface(surface);
}


