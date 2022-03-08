#ifndef TESTINSTANTIATION
#define TESTINSTANTIATION

#include "renderableinterface.hpp"

namespace graphics {

class TestInstantiation : public RenderableInterface {

public:
    int id;


};

}


// wrapper
#include <boost/python.hpp>
inline void TestInstantiation_wrapper() {
    namespace py = boost::python;

    py::class_<graphics::TestInstantiation>("TestInstantiation")
        .def("register_graphics", &graphics::TestInstantiation::register_graphics)
    ;
}

#endif