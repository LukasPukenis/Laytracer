//
//  World.cpp
//  Laytracer
//
//  Created by Lukas on 11/11/16.
//  Copyright © 2016 Lukas. All rights reserved.
//

#include "Settings.hpp"
#include "World.hpp"
#include "ViewPlane.hpp"
#include "RGBColor.hpp"
#include "Tracer.hpp"
#include "Sphere.hpp"
#include "ShadeRec.hpp"
#include "Ray.hpp"
#include "MultipleObjects.hpp"
#include <memory>
#include <iostream>

void World::build(void) {
  vp.hres = Settings::Width;
  vp.vres = Settings::Height;
  vp.gamma = 1.0;
  background_color = RGBColor(0.0, 0.0, 0.0);
}

World::World() {
  
}

void World::setTracer(Tracer * tracer) {
  tracer_ptr = tracer;
}

float RandomFloat(float a, float b) {
  float random = ((float) rand()) / (float) RAND_MAX;
  float diff = b - a;
  float r = random * diff;
  return a + r;
}

#include "Pinhole.h"

void World::render_scene(SDL_Window* window) {
  Pinhole pinhole;
  pinhole.surface = SDL_GetWindowSurface(window);
  pinhole.eye = Point3D(0.0, 0.0, 1000.0);
  pinhole.lookat = Point3D(0.0, 0.0, 0.0);
  pinhole.up = Vector3D(0.0, 1.0, 0.0);
  pinhole.compute_uvw();
  pinhole.render(*this);  
  SDL_UpdateWindowSurface(window);
}

void World::addLight(Light* light) {
	lights.push_back(light);
}

void World::addObject(GeometricObject* obj) {
  objects.push_back(obj);
}

ShadeRec World::hitBareBoneObjects(const Ray & ray) {
  ShadeRec sr;
  double t;
  double tmin = 99999999999;
  
  GeometricObject * _obj = nullptr;

  for (auto &obj : objects) {
    if (obj->hit(ray, t, sr) && t < tmin) {
      sr.hit_an_object = true;
      tmin = t;
	  _obj = obj;
    }
  }

  // at this point we have a color, now we need to iterate through all the lights
  // and if we hit those we have a color
  double lt;
  double ltmin = 99999999999;

  if (_obj != nullptr) {
	  for (auto &light : lights) {
		  auto lray = Ray(sr.local_hit_point, glm::normalize(light->getPos() - sr.local_hit_point));

		  auto hit = false;
		  for (auto &obj : objects) {
			  if (obj->hit(lray, lt, sr)) {
				  hit = true;
				  break;
			  }
		  }

		  if (hit) {
			  break;
		  }
		  else {
			  glm::vec3 p1 = glm::normalize(sr.normal);
			  glm::vec3 p2 = glm::normalize(-ray.d);
			  sr.color = _obj->getColor() * glm::dot(p1, p2);
		  }
	  }
  }
  
  return sr;
}
