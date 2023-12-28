#ifndef INCLUDEGUARD_CAMCON2
#define INCLUDEGUARD_CAMCON2

#include <cglm/cglm.h>
#define CglmMat4 mat4

typedef struct {
	float x;
	float y;
	float theta;
	float k;
	bool mirror;
} Camcon2();

void camcon2(init)(Camcon2()* camcon);
void camcon2(build)(Camcon2()* camcon, CglmMat4 mat);
void camcon2(rotate_view)(Camcon2()* camcon, float angle);

#endif
