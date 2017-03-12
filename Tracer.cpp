//
//  Tracer.cpp
//  Laytracer
//
//  Created by Lukas on 12/11/16.
//  Copyright © 2016 Lukas. All rights reserved.
//

#ifdef __APPLE__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif
#include "Tracer.hpp"

Tracer::Tracer(void): world_ptr(nullptr) {}

Tracer::Tracer(World* w_ptr): world_ptr(w_ptr) {}

RGBColor Tracer::trace_ray(const Ray& ray) const {
  return RGBColor(0.0);
}

void Tracer::setWorld(World * w_ptr) {
  world_ptr = w_ptr;
}
