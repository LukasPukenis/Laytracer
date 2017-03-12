//
//  World.hpp
//  Laytracer
//
//  Created by Lukas on 11/11/16.
//  Copyright © 2016 Lukas. All rights reserved.
//

#ifndef World_hpp
#define World_hpp

#ifdef __APPLE__
#include <SDL2/SDL.h>
#else
#include <SDL.h>
#endif
#include "ViewPlane.hpp"
#include "RGBColor.hpp"
#include "Sphere.hpp"
#include "Light.hpp"
#include "GeometricObject.hpp"
#include <vector>

class Tracer;

class World {
public:
  ViewPlane vp;
  RGBColor background_color;
  Sphere * sphere;
  Tracer * tracer_ptr;
  
  World(void);
  void build(void);
  void render_scene(SDL_Window* window);
  void open_window(const int hres, const int vres) const;
  void World::addLight(Light* light);

  ShadeRec hitBareBoneObjects(const Ray & ray);
  void addObject(GeometricObject* obj);
  void setTracer(Tracer * tracer);
	std::vector<GeometricObject*> objects;
	std::vector<Light*> lights;
private:
};

#endif /* World_hpp */
