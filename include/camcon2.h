#ifndef INCLUDEGUARD_CAMCON2_CAMCON2H
#define INCLUDEGUARD_CAMCON2_CAMCON2H

#include <cglm/cglm.h>

typedef struct {
float x;
float y;
float theta;
float k;
} Camcon2;

void camcon2_init(Camcon2* camcon);
void camcon2_build(Camcon2* camcon, mat4 mat);

#endif
