#ifndef RENDERABLEINTERFACE
#define RENDERABLEINTERFACE

#include <cstdio>

namespace graphics {

class RenderableInterface {

public:

    //RenderableInterface();
    //virtual void render() = 0;

    /*
    These register and unregister functions provide abstractions
    so it is easy to call them from Python. They will be wrappers
    for calls to the GraphicsManager's builtin addition and
    removal methods.
    */

    int register_graphics();

    int unregister_graphics();


};

} // namespace graphics



// wrapper
#include <boost/python.hpp>
inline void RenderableInterface_wrapper() {
    namespace py = boost::python;

    py::class_<graphics::RenderableInterface>("RenderableInterface")
        .def("register_graphics", &graphics::RenderableInterface::register_graphics)
        .def("unregister_graphics", &graphics::RenderableInterface::unregister_graphics)
    ;
}

#endif