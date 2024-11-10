#include <stdio.h>
#include <stdlib.h>


#define WIDTH 512
#define HEIGHT 512

//finite difference method to compute horizontal derivative
void d2P_dX2(float *P, float *dPdX, float dx){
    for(int i=1; i<WIDTH*HEIGHT-1; i++){
        dPdX[i] = (P[i+1] - 2*P[i] + P[i-1])/(dx*dx);
    }
}

//finite difference method to compute vertical derivative
void d2P_dZ2(float *P, float *dPdZ, float dz){
    for(int i=1; i<WIDTH*HEIGHT-1; i++){
        dPdZ[i] = (P[i+1*WIDTH] - 2*P[i] + P[i-1*WIDTH])/(dz*dz);
    }
}

//finite difference method to compute second time derivative. therefore, pressure field at time t+1
void d2P_dt2(float *P, float *P0, float *P1, float *dPdX, float *dPdZ, float *velocity, float dx, float dz, float dt){
    for(int i=0; i<WIDTH*HEIGHT; i++){
        P1[i] = 2*P[i] - P0[i] + (velocity[i]*velocity[i]*dt*dt)*(dPdX[i] + dPdZ[i]);
    }
}


int main(){
    
    int timesamples = 3000;

    float dx = 25.0;
    float dz = 25.0;
    float dt = 0.001;

    float *source = calloc(WIDTH*HEIGHT, sizeof(float));
    float *velocity = calloc(WIDTH*HEIGHT, sizeof(float));
    float *P = calloc(WIDTH*HEIGHT, sizeof(float));
    float *P0 = calloc(WIDTH*HEIGHT, sizeof(float));
    float *P1 = calloc(WIDTH*HEIGHT, sizeof(float));
    float *dPdX = calloc(WIDTH*HEIGHT, sizeof(float));
    float *dPdZ = calloc(WIDTH*HEIGHT, sizeof(float));

    for(int i=0; i<WIDTH*HEIGHT;i++){
        velocity[i] = 2500.0;
    }



    return 0;
}
