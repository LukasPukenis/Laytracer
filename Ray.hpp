//
//  Ray.hpp
//  Laytracer
//
//  Created by Lukas on 11/11/16.
//  Copyright © 2016 Lukas. All rights reserved.
//

#ifndef Ray_hpp
#define Ray_hpp

#include "glm/glm/vec3.hpp"
#include "glm/glm/vec4.hpp"
#include "glm/glm/mat4x4.hpp"
#include "glm/glm/gtc/matrix_transform.hpp"

typedef glm::vec3 Point3D;
typedef glm::vec3 Vector3D;
typedef glm::vec2 Point2D;

class Ray {
public:
  Point3D o;
  Vector3D d;
  Ray(void);
  Ray(const Point3D & origin, const Vector3D & dir);
  Ray(const Ray& ray);
  Ray& operator= (const Ray& rhs);
  ~Ray(void);
};

#endif /* Ray_hpp */
