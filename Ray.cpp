//
//  Ray.cpp
//  Laytracer
//
//  Created by Lukas on 11/11/16.
//  Copyright © 2016 Lukas. All rights reserved.
//

#include "Ray.hpp"

Ray::Ray(void) {
  o = Point3D(0.0, 0.0, 0.0);
  d = Point3D(0.0, 0.0, 0.0);
};

Ray::Ray(const Point3D & origin, const Vector3D & dir) {
  o = origin;
  d = dir;
};

Ray::Ray(const Ray& ray) {
  o = ray.o;
  d = ray.d;
};

Ray::~Ray() {
  
}

Ray& Ray::operator= (const Ray& rhs) {
  if (this == &rhs) {
    return *this;
  }
  o = rhs.o;
  d = rhs.d;
  
  return *this;
};
