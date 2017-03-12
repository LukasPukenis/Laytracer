#include "Action.h"

Action::Action() {
	obj = nullptr;
	light = nullptr;
}

void Action::setType(ACTION_TARGET_TYPE  _type) {
	type = _type;
}

#include <iostream>
void Action::step () {

	if (type == ACTION_TARGET_TYPE::SPHERE) {
		auto pos = obj->getPos();
		pos.x += dx;
		pos.y += dy;
		pos.z += dz;
		obj->setPos(pos);
	}
	else if (type == ACTION_TARGET_TYPE::LIGHT) {
		auto pos = light->getPos();
		pos.x += dx;
		pos.y += dy;
		pos.z += dz;
		light->setPos(pos);
	}
	else if (type == ACTION_TARGET_TYPE::PLANE) {
		auto pos = obj->getPos();
		pos.x += dx;
		pos.y += dy;
		pos.z += dz;
		obj->setPos(pos);
		
		glm::mat4 trans;
		nz = 0.005f;
		trans = glm::rotate(trans, (float)nz, glm::vec3(1.0, 0.0, 0.0));
		std::cout << nz << " ";
		auto n = trans * glm::vec4(obj->normal, 1.0f);
		obj->normal = glm::normalize(glm::vec3(n.x, n.y, n.z));
	}
}

void Action::setObject(GeometricObject * _obj) {
	obj = _obj;
}

void Action::setObject(Light * _light) {
	light = _light;
}
