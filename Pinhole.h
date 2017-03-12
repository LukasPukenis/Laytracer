#pragma once
#include "Camera.h"

class Pinhole : public Camera {
public:
	virtual void render(World & w);
private:
	Vector3D ray_direction(const Point2D & p) const;	
	float d, zoom;
};