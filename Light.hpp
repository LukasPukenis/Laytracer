#pragma once
#include "glm/glm/vec3.hpp"
#include "RGBColor.hpp"
#include "Ray.hpp"

typedef glm::vec3 Point3D;
typedef glm::vec2 Point2D;

class Light {
public:
	virtual bool hit(const Ray& ray, double& tmin) const;
	Light() {}
	Point3D getPos() { return position; }
	Light(const Point3D & pos, double str, const RGBColor & col) :
		position(pos),
		strength(str),
		color(col)
	{}	
	void setPos(const Point3D & pos) {
		position = pos;
	}

protected:
	Point3D position;
	double strength;
	RGBColor color;
};