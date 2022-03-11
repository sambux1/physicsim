#include <boost/python.hpp>

// must be .cpp if .cpp exists
#include "graphics/graphicsmanager.cpp"
#include "graphics/renderableinterface.cpp"
#include "particle.cpp"


BOOST_PYTHON_MODULE(graphics) {
    GraphicsManager_wrapper();
    RenderableInterface_wrapper();

    Particle_wrapper();
}