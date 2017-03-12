//
//  Plane.cpp
//  Laytracer
//
//  Created by Lukas on 11/11/16.
//  Copyright © 2016 Lukas. All rights reserved.
//

#include "Plane.hpp"

Plane::Plane(const Point3D &p, const Point3D& n) {	
	position = p;
	normal = glm::normalize(n);
}

bool Plane::hit(const Ray& ray, double& tmin, ShadeRec& sr) const {
  double t = glm::dot(position - ray.o, normal) / glm::dot(ray.d, normal);
  	
  if (t > kEpsilon) {
    tmin = t;
    sr.normal = normal;
    sr.local_hit_point = ray.o + (ray.d*static_cast<float>(t));
    return true;
  } else {
    return false;
  }
}
