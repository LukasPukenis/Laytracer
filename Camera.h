#pragma once
#include "World.hpp"

class Camera {
public:
	SDL_Surface * surface;
	void compute_uvw(void);

	virtual void render(World & world) = 0;
	Point3D eye;
	Point3D lookat;
	Vector3D up;
protected:	
	Vector3D u, v, w;
	float exposure;
};
