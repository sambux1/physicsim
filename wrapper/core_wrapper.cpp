#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "particle.cpp"

namespace py = pybind11;

PYBIND11_MODULE(core, m) {
    Particle_wrapper(m);
}