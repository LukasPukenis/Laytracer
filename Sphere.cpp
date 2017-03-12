//
//  Sphere.cpp
//  Laytracer
//
//  Created by Lukas on 12/11/16.
//  Copyright © 2016 Lukas. All rights reserved.
//

#include "Sphere.hpp"

Sphere::Sphere(): radius(10) {
}

void Sphere::setRadius(double r) {
  radius = r;
}

void Sphere::setPosition(Point3D c) {
  position = c;
}

bool Sphere::hit(const Ray& ray, double& tmin, ShadeRec& sr) const {
  double t;
  Vector3D temp = ray.o - position;
  
  double a = glm::dot(ray.d, ray.d);
  double b = 2.0 * glm::dot(temp, ray.d);
  double c = glm::dot(temp, temp) - glm::dot(radius, radius);
  double disc = b*b - 4.0 * a * c;
  
  if (disc < 0.0) {
    return false;
  } else {
    double e = sqrt(disc);
    double denom = 2.0 * a;
    t = (-b - e) / denom;
    
    if (t > kEpsilon ) {
      tmin = t;
      sr.normal = (temp + (ray.d*static_cast<float>(t))) / static_cast<float>(radius);
      sr.local_hit_point = ray.o + static_cast<float>(t)*ray.d;
      return true;
    }
    
    t = (-b + e) / denom;
    
    if (t > kEpsilon) {
      tmin = t;
      sr.normal = (temp + (ray.d* static_cast<float>(t))) / static_cast<float>(radius);
      sr.local_hit_point = ray.o + static_cast<float>(t)*ray.d;
      return true;
    }
  }
  
  return false;
}
