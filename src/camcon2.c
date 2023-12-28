#include <cglm/cglm.h>
#include <math.h>

#include "../include/camcon2.h"

void camcon2(init)(Camcon2()* camcon) {
	camcon->x = 0.0f;
	camcon->y = 0.0f;
	camcon->theta = 0.0f;
	camcon->k = 1.0f;
	camcon->mirror = false;
}

void camcon2(rotate_view)(Camcon2()* camcon, float angle) {
	if (camcon->mirror) {
		camcon->theta -= angle;
	} else {
		camcon->theta += angle;
	}
}

static void build_scalerot(Camcon2()* camcon, CglmMat4 mat) {
	glm_mat4_identity(mat);
	float ct = cosf(camcon->theta);
	float st = sinf(camcon->theta);
	mat[0][0] = camcon->k * ct;
	mat[1][1] = camcon->k * ct;
	mat[0][1] = camcon->k * st;
	mat[1][0] = camcon->k * -st;
	if (camcon->mirror) {
		mat[0][0] = -mat[0][0];
		mat[1][0] = -mat[1][0];
	}
}

void camcon2(build)(Camcon2()* camcon, CglmMat4 mat) {
	CglmMat4 translate;
	glm_mat4_identity(translate);
	translate[3][0] = camcon->x;
	translate[3][1] = camcon->y;
	build_scalerot(camcon, mat);
	glm_mat4_mul(mat, translate, mat);
}
