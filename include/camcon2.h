#include <cglm/cglm.h>

typedef struct {
	float x;
	float y;
	float theta;
	float k;
	bool mirror;
} Camcon2();

void camcon2(init)(Camcon2()* camcon);
void camcon2(build)(Camcon2()* camcon, mat4 mat);
void camcon2(rotate_view)(Camcon2()* camcon, float angle);
