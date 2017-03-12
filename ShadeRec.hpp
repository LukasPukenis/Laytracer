//
//  ShadeRec.hpp
//  Laytracer
//
//  Created by Lukas on 11/11/16.
//  Copyright © 2016 Lukas. All rights reserved.
//

#ifndef ShadeRec_hpp
#define ShadeRec_hpp

#include "glm/glm/vec3.hpp"
#include "glm/glm/vec4.hpp"
#include "glm/glm/mat4x4.hpp"
#include "glm/glm/gtc/matrix_transform.hpp"
#include "RGBColor.hpp"

class World;
typedef glm::vec3 Point3D;
typedef glm::vec2 Point2D;

class ShadeRec {
public:
  bool hit_an_object;
  Point3D local_hit_point;
  Point3D normal;
  RGBColor color;
  World * w;
  
  ShadeRec(World& wr);
  ShadeRec(void);
  ~ShadeRec(void);
};

#endif /* ShadeRec_hpp */
