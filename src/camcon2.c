#include <cglm/cglm.h>
#include <math.h>

#include "../include/camcon2.h"

void camcon2_init(Camcon2* camcon) {
	camcon->x = 0.0f;
	camcon->y = 0.0f;
	camcon->theta = 0.0f;
	camcon->k = 1.0f;
}

static void camcon2_build_scalerot(Camcon2* camcon, mat4 mat) {
	glm_mat4_identity(mat);
	float ct = cosf(camcon->theta);
	float st = sinf(camcon->theta);
	mat[0][0] = camcon->k * ct;
	mat[1][1] = camcon->k * ct;
	mat[0][1] = camcon->k * st;
	mat[1][0] = camcon->k * -st;
}

void camcon2_build(Camcon2* camcon, mat4 mat) {
	mat4 translate;
	glm_mat4_identity(translate);
	translate[3][0] = camcon->x;
	translate[3][1] = camcon->y;
	camcon2_build_scalerot(camcon, mat);
	glm_mat4_mul(mat, translate, mat);
}

void camcon2_s2w(Camcon2* camcon, vec2 s, vec2 w) {
	mat4 cam;
	camcon2_build_scalerot(camcon, cam);
	glm_mat4_inv(cam, cam);
	vec4 s4 = {s[0], s[1], 0.0, 1.0};
	glm_mat4_mulv(cam, s4, s4);
	w[0] = s4[0] / s4[3];
	w[1] = s4[1] / s4[3];
}
