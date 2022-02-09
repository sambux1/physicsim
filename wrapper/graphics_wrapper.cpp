#include <boost/python.hpp>

// must be .cpp if .cpp exists
#include "graphics/graphicsmanager.cpp"


BOOST_PYTHON_MODULE(graphics) {
    GraphicsManager_wrapper();
}