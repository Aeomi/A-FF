#include "BaseEntity.h"

#include "RenderHandler.h"
#include "EntityHandler.h"
#include "Transform.h"
#include "Collider.h"
#include "Renderer.h"


BaseEntity::BaseEntity() {
	_transform = new Transform();
	_collider = new Collider();
	_renderer = new Renderer(this);

	EntityHandler::registerEntity(this);
}



BaseEntity::~BaseEntity() {}



void BaseEntity::update(double dt) {}
