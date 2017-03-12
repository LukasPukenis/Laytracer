//
//  GeometricObject.cpp
//  Laytracer
//
//  Created by Lukas on 11/11/16.
//  Copyright © 2016 Lukas. All rights reserved.
//

#include "GeometricObject.hpp"
RGBColor GeometricObject::getColor() {
  return color;
}

Point3D GeometricObject::getPos() {
	return position;
}

void GeometricObject::setPos(const Point3D & pos) {
	position = pos;
}