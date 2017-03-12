#include "Recorder.h"

void Recorder::setSDLSurface(SDL_Surface * _surface) {
	surface = _surface;
}

void Recorder::setActionTree(ActionTree _actionTree) {
	actionTree = _actionTree;
}