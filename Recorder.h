#pragma once

#ifdef __APPLE__
	#include <OpenGL/gl.h>
	#include <OpenGL/glext.h>
	#include <SDL2/SDL.h>
#else
	#include <gl/glew.h>	
	#include <SDL.h>
#endif

#include "ActionTree.h"
#include "Action.h"

class Recorder {
public:
	void setSDLSurface(SDL_Surface * _surface);
	void setActionTree(ActionTree actionTree);
private:
	SDL_Surface * surface;
	ActionTree actionTree;
};