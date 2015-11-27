#pragma once

#include <string>

class Transform;
class Collider;	
class Renderer;

class BaseEntity {

	public:
	Transform *_transform;
	Collider  *_collider;
	Renderer  *_renderer;

	
	BaseEntity();
	~BaseEntity();

	virtual void update(double dt);

};

