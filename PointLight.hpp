#pragma once
#include "Light.hpp"
#include "Ray.hpp"

class PointLight : public Light {
public:
	PointLight(const Point3D & pos, double str, const RGBColor & col);
	bool hit(const Ray& ray, double& tmin) const;
private:
	static constexpr double kEpsilon = 0.12;
};