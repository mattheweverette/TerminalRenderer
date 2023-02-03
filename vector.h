#ifndef VECTOR_h
#define VECTOR_h

typedef struct {
	float x;
	float y;
	float z;
} vector_t;

float dot(vector_t v, vector_t u);
float norm(vector_t v);
void normalize(vector_t* v);
void sub(vector_t v, vector_t u, vector_t* res);

#endif
