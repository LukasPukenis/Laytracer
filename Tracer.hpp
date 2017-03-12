//
//  Tracer.hpp
//  Laytracer
//
//  Created by Lukas on 12/11/16.
//  Copyright © 2016 Lukas. All rights reserved.
//

#ifndef Tracer_hpp
#define Tracer_hpp

#include "World.hpp"
#include "Ray.hpp"

class Tracer {
public:
  Tracer(void);
  Tracer(World * w_ptr);
  void setWorld(World * w_ptr);
  virtual RGBColor trace_ray(const Ray& ray) const;
protected:
  World * world_ptr;
};

#endif /* Tracer_hpp */
