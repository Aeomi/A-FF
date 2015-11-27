#pragma once
#include "stdafx.h"
#include "BaseEntity.h"
#include "InputController.h"

#include <string>

class Player : public BaseEntity {
	public:

	// Transform
	// Collider
	// Renderer
	InputController *_inputController;

	Player();
	Player(double x, double y, int width, int height, std::string texturePath);

	~Player();

	virtual void update(double dt);

};

