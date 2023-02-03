#include "sphere.h"

#include "renderer.h"

vector_t sphere_pos = { 0.0f, 0.0f, 60.0f };

float sphere_sdf(vector_t pos) {
	vector_t dist;
	sub(pos, sphere_pos, &dist);

	return norm(dist) - SPHERE_RADIUS;
}

void sphere_normal(vector_t pos, vector_t* res) {
	sub(pos, sphere_pos, res);
	normalize(res);
}
