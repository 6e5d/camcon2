#include <cglm/cglm.h>
#include <math.h>

#include "../include/camcon2.h"

void camcon2_init(Camcon2* camcon) {
	camcon->x = 0.0f;
	camcon->y = 0.0f;
	camcon->theta = 0.0f;
	camcon->k = 1.0f;
}

void camcon2_build(Camcon2* camcon, mat4 mat) {
	glm_mat4_identity(mat);
	float ct = cosf(camcon->theta);
	float st = sinf(camcon->theta);
	mat[0][0] = camcon->k * ct;
	mat[1][1] = camcon->k * ct;
	mat[0][1] = camcon->k * st;
	mat[1][0] = camcon->k * -st;
	mat[3][0] = camcon->x;
	mat[3][1] = camcon->y;
}
