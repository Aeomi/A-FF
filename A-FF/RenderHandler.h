#pragma once
#include "stdafx.h"
#include <vector>

class Renderer;


class RenderHandler {
	
	public:
	SDL_Renderer *_renderTarget;
	SDL_Window   *_window;


	static std::vector<Renderer *> _renderComponents;

	RenderHandler();
	~RenderHandler();

	void update();


	static void registerRenderer(Renderer *renderer);
	
};

