#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include <vector>
using namespace std;

class Particle {

public:
    // constructor, must take dimension, all other fields are set to defaults
    Particle(int dimension);
    
    int dimension;
    int get_dimension();

    vector<float> position;
    void set_position(vector<float> position);
    vector<float> get_position();

    vector<float> velocity;
    void set_velocity(vector<float> velocity);
    vector<float> get_velocity();

    vector<float> acceleration;
    void set_acceleration(vector<float> acceleration);
    vector<float> get_acceleration();
};

void functiontest();

#endif