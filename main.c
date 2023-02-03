#include <stdio.h>

#include "vector.h"
#include "sphere.h"
#include "renderer.h"

int main(void) {
	for (int i = 0; i < 1000; i++) {
		sphere_pos.z += 0.1;
		printf("\x1b[2J");
		printf("\x1b[d");
		render(sphere_sdf, sphere_normal);
	}

	return 0;
}
