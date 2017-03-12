/*
	this class is used to modify objects properties each time incrementing/decrementing them
	by some delta
*/
#pragma once
#include "GeometricObject.hpp"
#include "Light.hpp"

enum ACTION_TARGET_TYPE {
	LIGHT,
	PLANE,
	SPHERE
};

class Action {
public:
	Action();
	
	void modifyPos(double _dx, double _dy, double _dz) {
		dx = _dx;
		dy = _dy;
		dz = _dz;
	}

	void modifyNormal(double _dx, double _dy, double _dz) {
		nx = _dx;
		ny = _dy;
		nz = _dz;
	}

	void setObject(GeometricObject * _obj);
	void setObject(Light * _obj);
	void setType(ACTION_TARGET_TYPE _type);

	void step();
private:
	double dx, dy, dz;
	double nx, ny, nz;
	GeometricObject * obj;
	Light * light;
	ACTION_TARGET_TYPE type;
};