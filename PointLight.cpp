#pragma once
#include "glm/glm/vec3.hpp"
#include "glm/glm/vec4.hpp"
#include "glm/glm/mat4x4.hpp"
#include "glm/glm/gtc/matrix_transform.hpp"
#include "PointLight.hpp"

PointLight::PointLight(const Point3D & pos, double str, const RGBColor & col) {
	position = pos,
	strength = str,
	color = col;
}

bool PointLight::hit(const Ray& ray, double& tmin) const {
	double t;
	Vector3D temp = ray.o - position;

	double a = glm::dot(ray.d, ray.d);
	double b = 2.0 * glm::dot(temp, ray.d);
	double c = glm::dot(temp, temp) - glm::dot(strength, strength);
	double disc = b*b - 4.0 * a * c;

	if (disc < 0.0) {
		return false;
	}
	else {
		double e = sqrt(disc);
		double denom = 2.0 * a;
		t = (-b - e) / denom;

		if (t > kEpsilon) {
			tmin = t;
			return true;
		}

		t = (-b + e) / denom;

		if (t > kEpsilon) {
			tmin = t;
			return true;
		}
	}
}