#pragma once
#include "stdafx.h"
#include <vector>

class BaseEntity;


class EntityHandler {

	public:
	static std::vector<BaseEntity *> _entities;


	EntityHandler();
	~EntityHandler();


	void update(double dt);


	static void registerEntity(BaseEntity *entity);

};
