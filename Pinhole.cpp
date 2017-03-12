#include "Pinhole.h"
#include "World.hpp"
#include "Tracer.hpp"
#include <iostream>

Vector3D Pinhole::ray_direction(const Point2D & p) const {
	Vector3D dir = p.x * u + p.y * v - d * w;
	dir = glm::normalize(dir);
	return dir;
}

void Pinhole::render(World & w) {
	d = 500.0;
	RGBColor L;
	Ray ray;
	int depth = 0;
	Point2D sp;	// sample point in 0..1 x 0..1
	Point2D pp;	// sample point on a pixel

	const int NUM_SAMPLES = 4;

	ray.o = eye;
	
	for (int r = 0; r < w.vp.vres; r++) {
		for (int c = 0; c < w.vp.hres; c++) {
			L.x = 0.0;
			L.g = 0.0;
			L.b = 0.0;

			for (int j = 0; j < NUM_SAMPLES; j++) {
				sp.x = 0.0;
				sp.y = 0.0;

				pp.x = c - 0.5 * w.vp.hres + sp.x;
				pp.y = r - 0.5 * w.vp.vres + sp.y;
				ray.d = ray_direction(pp);
				L += w.tracer_ptr->trace_ray(ray);
			}

			L /= NUM_SAMPLES;
			//L *= exposure;

			auto pixel = L;			

			//if (pixel.r > 0.0 || pixel.g > 0.0 || pixel.b > 0.0) __debugbreak();

			auto pixels = (Uint32*)surface->pixels;
			glm::u8vec4 pix(pixel, 255.0f);
			
			//ARGB
			pixels[(surface->w * r) + c + 0] = ((pix.r & 0xff) << 16) + ((pix.g & 0xff) << 8) + (pix.b & 0xff);
		}
	}
}