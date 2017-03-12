//
//  ShadeRec.cpp
//  Laytracer
//
//  Created by Lukas on 11/11/16.
//  Copyright © 2016 Lukas. All rights reserved.
//

#include "ShadeRec.hpp"

ShadeRec::ShadeRec(World& wr):
	hit_an_object(false),
	local_hit_point(),
	normal(),
	color(0.0f, 0.0f, 0.0f),
	w(&wr)
{}

ShadeRec::ShadeRec(void):
	hit_an_object(false),
	local_hit_point(),
	normal(),
	color(0.0f, 0.0f, 0.0f)
{}

ShadeRec::~ShadeRec() {
  
}
