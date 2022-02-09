#ifndef GRAPHICSMANAGER_HPP
#define GRAPHICSMANAGER_HPP

namespace graphics {

class GraphicsManager {

public:
    GraphicsManager();

    // set up window
    bool init(double width, double height);

    // run window
    static void run();

    // render to the window
    // temporary - need to find a good long term plan here
    static void render(void);

    // allows user to set the update interval
    int fps;

    // whether the graphics manager has been initialized yet
    bool active;
    bool is_active();

};

} // namespace graphics



// wrapper
#include <boost/python.hpp>
inline void GraphicsManager_wrapper() {
    namespace py = boost::python;

    py::class_<graphics::GraphicsManager>("GraphicsManager", py::init<>())
        .def("init", &graphics::GraphicsManager::init)
        .def("is_active", &graphics::GraphicsManager::is_active)
    ;
}

#endif