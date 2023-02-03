#ifndef SPHERE_h
#define SPHERE_h

#define SPHERE_RADIUS 50.0f

#include "vector.h"

extern vector_t sphere_pos;

float sphere_sdf(vector_t pos);
void sphere_normal(vector_t pos, vector_t* res);

#endif
