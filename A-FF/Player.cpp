#include "Player.h"
#include "Transform.h"
#include "Collider.h"
#include "Renderer.h"


Player::Player() {
	_inputController = new InputController();
}


Player::Player(double x, double y, int width, int height, std::string texturePath) {

	// Setup transform component with data
	_transform->_position.x = x;
	_transform->_position.y = y;
	_transform->_width = width;
	_transform->_height = height;
	
	// Setup Renderer component with data (assign texture)
	_renderer->generateTexture(texturePath);
	
	// Setup InputController component
	_inputController = new InputController(this);

}

Player::~Player() {}


void Player::update(double dt) {

	//_renderer->update();
	_transform->update();
	//_collider->update();
	_inputController->update();

}