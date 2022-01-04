#include <boost/python.hpp>

#include "graphics/graphicsmanager.cpp"


BOOST_PYTHON_MODULE(graphics) {
    GraphicsManager_wrapper();
}