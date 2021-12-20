#include "particle.h"
#include <cstdio>

Particle::Particle(int dimension) {
    this->dimension = dimension;
    float* position = new float[dimension];
    float* velocity = new float[dimension];

    for (int i = 0; i < dimension; i++) {
        position[i] = 0.0;
        velocity[i] = 0.0;
    }
    
    this->position = position;
    this->velocity = velocity;

    printf("main constructorrrr\n");
}

Particle::Particle(int dimension, float* position, float* velocity) {
    this->dimension = dimension;
    this->position = position;
    this->velocity = velocity;
}

/*int main() {
    printf("hello\n");
    Particle p(3);
    printf("%f\n", p.position[2]);
}*/

extern "C" {
    Particle* Particle(int dimension);
}
