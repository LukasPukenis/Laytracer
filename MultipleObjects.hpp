//
//  MultipleObjects.hpp
//  Laytracer
//
//  Created by Lukas on 01/12/16.
//  Copyright © 2016 Lukas. All rights reserved.
//

#ifndef MultipleObjects_hpp
#define MultipleObjects_hpp

#include "Tracer.hpp"

class MultipleObjects: public Tracer {
public:
  RGBColor trace_ray(const Ray & ray) const;
  MultipleObjects(World * w_ptr): Tracer(w_ptr) {}
};

#endif /* MultipleObjects_hpp */
