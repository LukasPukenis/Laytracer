//
//  MultipleObjects.cpp
//  Laytracer
//
//  Created by Lukas on 01/12/16.
//  Copyright © 2016 Lukas. All rights reserved.
//
#include <iostream>

#include "MultipleObjects.hpp"

RGBColor MultipleObjects::trace_ray(const Ray & ray) const {
  ShadeRec sr(world_ptr->hitBareBoneObjects(ray));
  
  if (sr.hit_an_object) {    
    return RGBColor(sr.color.r, sr.color.g, sr.color.b);
  } else {
    return RGBColor(0.0); // todo ambient
  }
}
