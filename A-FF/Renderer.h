#pragma once
#include "stdafx.h"
#include <string>

class BaseEntity;


class Renderer {

	public:
	BaseEntity *parentEntity;			// Reference to entity which it's attached to

	static int total; // Do need?

	int _id;

	SDL_Texture	*_texture;

	Renderer(BaseEntity *entity);
	Renderer(BaseEntity *entity, std::string texturePath);
	~Renderer();

	void generateTexture(std::string texturePath);

};

