#include "EntityHandler.h"
#include "BaseEntity.h"



std::vector<BaseEntity *> EntityHandler::_entities;



EntityHandler::EntityHandler() {}



EntityHandler::~EntityHandler() {}



void EntityHandler::update(double dt) {

	for (unsigned int i = 0; i < _entities.size(); i++) {

		BaseEntity *entity = _entities[i];
		
		entity->update(dt);

	}

}



void EntityHandler::registerEntity(BaseEntity *entity) {

	_entities.push_back(entity);

}



