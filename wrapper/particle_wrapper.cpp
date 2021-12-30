#include <boost/python.hpp>
using namespace boost::python;

#include "particle.hpp"
#include "converters.cpp"

// TODO
// xxx make new file just for conversions
// start off just with float vectors
// eventually this will need to be a template
// make a custom converter
    // check for validity - convertible()
    // convert - construct()
// figure out how to chain multiple modules together


BOOST_PYTHON_MODULE(physicsim) {

    // custom converter from converters.cpp
    // converts vector<float> to Python list
    to_python_converter<std::vector<float>, vector_to_pylist>();

    class_<Particle>("Particle", init<int>())
        // dimension
        .def_readonly("dimension", &Particle::dimension)
        .def("get_dimension", &Particle::get_dimension)
        // position, velocity, acceleration, and their getters and setters
        .add_property("position", &Particle::get_position, &Particle::set_position)
        .add_property("velocity", &Particle::get_velocity, &Particle::set_velocity)
        .add_property("acceleration", &Particle::get_acceleration, &Particle::set_acceleration)
    ;

    def("functiontest", functiontest);
}