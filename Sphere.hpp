//
//  Sphere.hpp
//  Laytracer
//
//  Created by Lukas on 12/11/16.
//  Copyright © 2016 Lukas. All rights reserved.
//

#ifndef Sphere_hpp
#define Sphere_hpp

#include "GeometricObject.hpp"
#include "Ray.hpp"
#include "ShadeRec.hpp"

typedef glm::vec3 Point3D;
class Sphere: public GeometricObject {
public:
  Sphere(void);
  Sphere(const Point3D p, const Point3D& n);
  void setPosition(Point3D c);
  void setRadius(double r);
  virtual bool hit(const Ray& ray, double& t, ShadeRec& s) const;
private:
  double radius;
  Point3D normal;
  static constexpr double kEpsilon = 0.2;
};

#endif /* Sphere_hpp */
