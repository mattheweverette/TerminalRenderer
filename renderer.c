#include "renderer.h"

#include <stdio.h>

const vector_t camera_pos = { 0.0f, 0.0f, -20.0f };
const vector_t light_pos = { 5.0f, -20.0f, 0.0f };

void cast_ray(vector_t* ray, float (*sdf)(vector_t)) {
	vector_t direction;
	sub(*ray, camera_pos, &direction);
	normalize(&direction);

	for (int i = 0; i < MAX_STEPS; i++) {
		if (sdf(*ray) < 0.0f)
			return;

		ray->x += direction.x * STEP_SIZE;
		ray->y += direction.y * STEP_SIZE;
		ray->z += direction.z * STEP_SIZE;
	}

	ray->x = -1;
	ray->y = -1;
	ray->z = -1;
}

char calculate_lighting(vector_t ray, void (*normal)(vector_t, vector_t*))  {
	vector_t light_dir;
	sub(light_pos, ray, &light_dir);
	normalize(&light_dir);

	vector_t n;
	normal(ray, &n);

	float diff = (dot(n, light_dir) > 0.0f) ? dot(n, light_dir) : 0.0f;
	if (diff < 0.1)
		return '.';
	else if (diff < 0.2)
		return ':';
	else if (diff < 0.3)
		return '-';
	else if (diff < 0.4)
		return '=';
	else if (diff < 0.5)
		return '+';
	else if (diff < 0.6)
		return '*';
	else if (diff < 0.7)
		return '#';
	else if (diff < 0.8)
		return '%';
	else
		return '@';
}

void render(float (*sdf)(vector_t), void (*normal)(vector_t, vector_t*)) {		
	vector_t ray;
	for (int y = 0; y < Y_RES; y++) {
		for (int x = 0; x < X_RES; x++) {
			ray.x = x - X_RES / 2.0f;
			ray.y = 2.0f * y - Y_RES;
			ray.z = 0.0f;

			cast_ray(&ray, sdf);

			if (ray.x != -1 || ray.y != -1 || ray.z != -1)
				putchar(calculate_lighting(ray, normal));	
			else
				putchar(' ');
		}
		putchar('\n');
	}
}
