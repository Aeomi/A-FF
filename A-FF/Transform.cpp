#include "Transform.h"
#include "Util.h"


Transform::Transform() {

	_position = { 0, 0 };
	_velocity = { 0, 0 };
	_angle = 0;
	_width = 1;
	_height = 1;	

}



Transform::~Transform() {}



void Transform::update() {

	// Apply velocity to position
	_position.x += _velocity.x;
	_position.y += _velocity.y;

	// Decay velocity
	if (_velocity.x > 0)
		_velocity.x -= 0.01;
	else if (_velocity.x < 0)
		_velocity.x += 0.01;

	if (_velocity.y > 0)
		_velocity.y -= 0.01;
	else if (_velocity.y < 0)
		_velocity.y += 0.01;

	_velocity.x = Util::Math::clamp(_velocity.x, -1.0, 1.0);
	_velocity.y = Util::Math::clamp(_velocity.y, -1.0, 1.0);

}



void Transform::moveForward() {

	//_velocity

}



void Transform::moveBackward() {}



void Transform::moveLeft() {}



void Transform::moveRight() {}

