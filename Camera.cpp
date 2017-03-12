#include "Camera.h"

void Camera::compute_uvw(void) {
	w = eye - lookat;
	w = glm::normalize(w);
	u = glm::cross(up, w);
	u = glm::normalize(u);
	v = glm::cross(w, u);
}