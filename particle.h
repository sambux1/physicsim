#ifndef PARTICLE_H
#define PARTICLE_H

class Particle {

public:
    Particle(int dimension);
    Particle(int dimension, float* position, float* velocity);
    int dimension;
    float* position;
    float* velocity;
};


#endif