#include "particle.hpp"
#include <cstdio>

Particle::Particle(int dimension) {
    this->dimension = dimension;
    printf("dimension %d\n", this->dimension);
    
    /*
    float* position = new float[dimension];
    float* velocity = new float[dimension];

    for (int i = 0; i < dimension; i++) {
        position[i] = 0.0;
        velocity[i] = 0.0;
    }
    
    this->position = position;
    this->velocity = velocity;
    */

    printf("main constructorrrr\n");
}


int Particle::get_dimension() {
    printf("got heree\n");
    printf("dimensionnnnn %d\n", this->dimension);
    return this->dimension;
}

int main() {
    printf("hello\n");
    Particle p(3);
    //printf("%f\n", p.position[2]);
}
