#pragma once

struct vec2 {
	double x, y;
};


class Transform {

	public:

	vec2 _position;
	vec2 _velocity;

	double _angle;
	int	_width, _height;

	Transform();
	~Transform();

	void update();

	void moveForward();
	void moveBackward();
	void moveLeft();
	void moveRight();

};


