#include "InputController.h"
#include "BaseEntity.h"
#include "Transform.h"

#include <iostream>



InputController::InputController() {}



InputController::InputController(BaseEntity *entity) {

	parentEntity = entity;
	_keyboardState = SDL_GetKeyboardState(NULL);

}



InputController::~InputController() {}



void InputController::update() {

	// TODO: Should do?
	//SDL_PumpEvents();


	processInputs();

}



bool InputController::processInputs() {

	//----------------
	// Directional movements (WASD)
	//------------

	// Horizontal Movement
	if (_keyboardState[SDL_SCANCODE_A])
		parentEntity->_transform->moveLeft();

	if (_keyboardState[SDL_SCANCODE_D])
		parentEntity->_transform->moveRight();


	// Vertical Movement
	if (_keyboardState[SDL_SCANCODE_W])
		parentEntity->_transform->moveForward();

	if (_keyboardState[SDL_SCANCODE_S])
		parentEntity->_transform->moveBackward();



	return 0;

}



