#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include <vector>
#include "graphics/renderableinterface.hpp"

class Particle : public graphics::RenderableInterface {

public:
    // constructor, must take dimension, all other fields are set to defaults
    Particle(int dimension);
    
    int dimension;
    int get_dimension();

    std::vector<float> position;
    void set_position(std::vector<float> new_position);
    std::vector<float> get_position();

    std::vector<float> velocity;
    void set_velocity(std::vector<float> new_velocity);
    std::vector<float> get_velocity();

    std::vector<float> acceleration;
    void set_acceleration(std::vector<float> new_acceleration);
    std::vector<float> get_acceleration();

    // implement the Renderable interface
    void render();
};



// wrapper
#include <boost/python.hpp>
inline void Particle_wrapper() {
    namespace py = boost::python;

    // declare the Particle class
    py::class_<Particle, py::bases<graphics::RenderableInterface>>("Particle", py::init<int>())
        // dimension
        .def_readonly("dimension", &Particle::dimension)
        .def("get_dimension", &Particle::get_dimension)
        // position, velocity, acceleration, and their getters and setters
        .add_property("position", &Particle::get_position, &Particle::set_position)
        .add_property("velocity", &Particle::get_velocity, &Particle::set_velocity)
        .add_property("acceleration", &Particle::get_acceleration, &Particle::set_acceleration)
        .def("render", &Particle::render)
    ;
}

#endif