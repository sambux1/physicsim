#ifndef RENDERABLEINTERFACE
#define RENDERABLEINTERFACE


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
#include <pybind11/pybind11.h>
void RenderableInterface_wrapper(pybind11::module_ m) {
    namespace py = pybind11;

    py::class_<graphics::RenderableInterface>(m, "RenderableInterface")
        .def("register_graphics", &graphics::RenderableInterface::register_graphics)
        .def("unregister_graphics", &graphics::RenderableInterface::unregister_graphics)
    ;
}

#endif