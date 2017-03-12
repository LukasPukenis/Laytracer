//
//  Plane.hpp
//  Laytracer
//
//  Created by Lukas on 11/11/16.
//  Copyright © 2016 Lukas. All rights reserved.
//

#ifndef Plane_hpp
#define Plane_hpp

#include "GeometricObject.hpp"
#include "Ray.hpp"

typedef glm::vec3 Point3D;
typedef glm::vec2 Point2D;

class Plane: public GeometricObject {
public:
  Plane(void);
  Plane(const Point3D &p, const Point3D& n);
  virtual bool hit(const Ray& ray, double& t, ShadeRec& s) const;
private:
  static constexpr double kEpsilon = 0.2;
};

#endif /* Plane_hpp */
