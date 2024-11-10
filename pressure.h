#ifndef PRESSURE_H
#define PRESSURE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 1024
#define HEIGHT 1024


//finite difference method to compute horizontal derivative
void d2P_dX2(float *P, float *dPdX, float dx);

//finite difference method to compute vertical derivative
void d2P_dZ2(float *P, float *dPdZ, float dz);

//finite difference method to compute second time derivative. therefore, pressure field at time t+1
void d2P_dt2(float *P, float *P0, float *P1, float *dPdX, float *dPdZ, float *velocity, float dx, float dz, float dt);

//use ricker wavelet to create source
void create_source(float *source, int timesamples, float dt, float freq);

//main loop to compute pressure
void compute_pressure(float *P, float *P0, float *P1, float *dPdX, float *dPdZ, float *velocity, float *source, int timesamples, float dx, float dz, float dt);

#endif