#pragma once
#include "stdafx.h"
#include <map>
#include <string>

class BaseEntity;


class InputController {

	public:
	BaseEntity *parentEntity;
	const Uint8 *_keyboardState;


	InputController();
	InputController(BaseEntity *entity);

	~InputController();

	void update();

	bool processInputs();


};
