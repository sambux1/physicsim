#include "particle.hpp"
#include <cstdio>

Particle::Particle(int dimension) {
    this->dimension = dimension;

    for (int i = 0; i < this->dimension; i++) {
        this->position.push_back(0.0f);
        this->velocity.push_back(0.0f);
        this->acceleration.push_back(0.0f);
    }

}

int Particle::get_dimension() {
    return this->dimension;
}

void Particle::set_position(vector<float> new_position) {
    if (new_position.size() != this->dimension) {
        // throw error
        return;
    }

    this->position = new_position;
}

vector<float> Particle::get_position() {
    return this->position;
}

void Particle::set_velocity(vector<float> new_velocity) {
    if (new_velocity.size() != this->dimension) {
        // throw error
        return;
    }

    this->velocity = new_velocity;
}

vector<float> Particle::get_velocity() {
    return this->velocity;
}

void Particle::set_acceleration(vector<float> new_acceleration) {
    if (new_acceleration.size() != this->dimension) {
        // throw error
        return;
    }

    this->acceleration = new_acceleration;
}

vector<float> Particle::get_acceleration() {
    return this->acceleration;
}

void functiontest() {
    printf("function test successful\n");
}


/*int main() {
    printf("hello\n");
    Particle p(3);
    printf("%d\n", p.get_dimension());
}*/
