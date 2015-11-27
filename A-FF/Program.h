#pragma once
#include "stdafx.h"

class RenderHandler;
class CollisionHandler;
class NPCHandler;
class EntityHandler;


class Program {	// SINGLETON

	public:
	enum STATES { RUNNING, STOPPED, QUIT };
	Uint8 _state;

	// FPS Interval - One second by default
	Uint8 FRAMERATE_INTERVAL;

	double _framerate;
	double _deltaTime;


	Uint32 _framerateLastTime;
	Uint32 _framesSinceLastCheck;


	EntityHandler    *entityHandler;
	RenderHandler	 *renderHandler;
	CollisionHandler *collisionHandler;
	NPCHandler		 *npcHandler;


	Program();
	~Program();

	void quit();

	void run();
	void mainUpdate();

	void calculateFramerate();
	void limitFramerate();

};

