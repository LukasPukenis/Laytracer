//
//  GeometricObject.hpp
//  Laytracer
//
//  Created by Lukas on 11/11/16.
//  Copyright © 2016 Lukas. All rights reserved.
//

#ifndef GeometricObject_hpp
#define GeometricObject_hpp

#include "Ray.hpp"
#include "ShadeRec.hpp"
#include "RGBColor.hpp"

class GeometricObject {
public:
  virtual bool hit(const Ray& ray, double& tmin, ShadeRec& sr) const = 0;
  Point3D getNormal() { return normal; }
  void setNormal(const Point3D & _normal) {
	  normal = glm::normalize(_normal);
  }

  Point3D getPos();
  void setPos(const Point3D & pos);

  RGBColor getColor();
  void setColor(RGBColor col) {
    color = col;
  }
  Point3D normal;
protected:
  RGBColor color;
  Point3D position;
  
};

#endif /* GeometricObject_hpp */
