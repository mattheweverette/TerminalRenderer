
#include "vector.h"

#include <math.h>

float dot(vector_t v, vector_t u) {
	return v.x * u.x + v.y * u.y + v.z * u.z;
}

float norm(vector_t v) {
	return sqrt(dot(v, v));
}

void normalize(vector_t* v) {
	float n = norm(*v);
	v->x /= n;
	v->z /= n;
	v->y /= n;
}

void sub(vector_t v, vector_t u, vector_t* res) {
	res->x = v.x - u.x;
	res->y = v.y - u.y;
	res->z = v.z - u.z;
}
