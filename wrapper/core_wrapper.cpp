#include <boost/python.hpp>
#include "converters.cpp"

#include "particle.cpp"


BOOST_PYTHON_MODULE(core) {

    // handle automatic type conversions
    register_conversions();

    // load all the declarations
    Particle_wrapper();
}