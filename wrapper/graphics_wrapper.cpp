#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// must be .cpp if .cpp exists
#include "graphics/graphicsmanager.cpp"
#include "graphics/renderableinterface.cpp"
#include "particle.cpp"


namespace py = pybind11;

PYBIND11_MODULE(graphics, m) {
    GraphicsManager_wrapper(m);
    RenderableInterface_wrapper(m);
}