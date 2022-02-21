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

void Particle::set_position(std::vector<float> new_position) {
    if (new_position.size() != this->dimension) {
        // throw error
        return;
    }

    this->position = new_position;
}

std::vector<float> Particle::get_position() {
    return this->position;
}

void Particle::set_velocity(std::vector<float> new_velocity) {
    if (new_velocity.size() != this->dimension) {
        // throw error
        return;
    }

    this->velocity = new_velocity;
}

std::vector<float> Particle::get_velocity() {
    return this->velocity;
}

void Particle::set_acceleration(std::vector<float> new_acceleration) {
    if (new_acceleration.size() != this->dimension) {
        // throw error
        return;
    }

    this->acceleration = new_acceleration;
}

std::vector<float> Particle::get_acceleration() {
    return this->acceleration;
}

void Particle::render() {
    printf("Rendering\n");
}
