
#include "pressure.h"


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
    compute_pressure(P, P0, P1, dPdX, dPdZ, velocity, source, timesamples, dx, dz, dt);

    return 0;
}
