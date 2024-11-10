#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define WIDTH 1024
#define HEIGHT 1024

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
        P[i] = 2*P0[i] - P1[i] + (velocity[i]*velocity[i]*dt*dt)*(dPdX[i] + dPdZ[i]);
    }
}


//use ricker wavelet to create source
void create_source(float *source, int timesamples, float dt, float freq){

    float wp = 2.0*M_PI*freq;
    for(int i=0; i<timesamples; i++){
        float tau = i*dt;
        source[i] = (1 - 0.5*wp*wp*tau*tau)*exp(-0.25*wp*wp*tau*tau);
    }
}


int main(){
    
    int timesamples = 3000;

    float dx = 25.0;
    float dz = 25.0;
    float dt = 0.001;
    float freq = 3.0;

    float *source = calloc(timesamples, sizeof(float));
    float *velocity = calloc(WIDTH*HEIGHT, sizeof(float));
    float *P = calloc(WIDTH*HEIGHT, sizeof(float));
    float *P0 = calloc(WIDTH*HEIGHT, sizeof(float));
    float *P1 = calloc(WIDTH*HEIGHT, sizeof(float));
    float *dPdX = calloc(WIDTH*HEIGHT, sizeof(float));
    float *dPdZ = calloc(WIDTH*HEIGHT, sizeof(float));

    for(int i=0; i<WIDTH*HEIGHT;i++){
        velocity[i] = 2500.0;
    }

    //initialize source
    create_source(source, timesamples, dt, freq);

    for(int t=0; t<timesamples; t++){
        //update pressure field
        d2P_dX2(P, dPdX, dx);
        d2P_dZ2(P, dPdZ, dz);
        d2P_dt2(P, P0, P1, dPdX, dPdZ, velocity, dx, dz, dt);

        //apply source
        P[WIDTH*HEIGHT/2] += source[t];

        //update pressure field
        P1 = P0;
        P0 = P;
    }

    return 0;
}
