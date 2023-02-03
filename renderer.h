
#ifndef RENDERER_h
#define RENDERER_h

#define X_RES 80
#define Y_RES 22

#define MAX_STEPS 100
#define STEP_SIZE 5.0f

#include "vector.h"

extern const vector_t camera_pos;
extern const vector_t light_pos;

void cast_ray(vector_t* ray, float (*sdf)(vector_t));
char calculate_lighting(vector_t ray, void (*normal)(vector_t, vector_t*));
void render(float (*sdf)(vector_t), void (*normal)(vector_t, vector_t*));

#endif
