#ifndef GRAPHICSMANAGER_HPP
#define GRAPHICSMANAGER_HPP

#include "renderableinterface.hpp"
#include <set>
#include <cstdio>
#include <mutex>

/*
This is designed to somewhat mimic a singleton class. It is not
a singleton due to difficulties with Boost. Eventually, this should
probably be fixed, but for now workarounds are fine.
*/

namespace graphics {

// a struct to hold the info needed to set up the window
//  by the static runGlutWindow() function
struct GraphicsThreadInfo {
    double width;
    double height;
    // add more as necessary
};


class GraphicsManager {

public:
    // constructor
    GraphicsManager();

    // handle setup before creating a new thread to run a window
    bool init(double width, double height);

    // send a kill signal to the graphics thread
    void stop();

    // return whether the graphics window has been initialized yet
    bool is_active();

    // add/remove renderable object to/from the render list
    // static to mimic a singleton
    static void add_to_render_list(RenderableInterface* object);
    static void remove_from_render_list(RenderableInterface* object);

    /*
    static functions for use only by the graphics thread
    */

    // in a new thread, create and manage a GLUT window
    static void runGlutWindow(struct GraphicsThreadInfo info);

    // render to the window
    // I think this needs to be called explicitly to update
    static void render(void);

private:
    // whether the graphics window has been initialized yet
    bool active;
    // allows user to set the update interval
    int fps;
    // the list of objects to be rendered
    // static so it can be used by the graphics thread
    static std::set<RenderableInterface*> render_list;
    // lock for the render_list
    static std::mutex render_list_lock;

};

} // namespace graphics



// wrapper
#include <boost/python.hpp>
inline void GraphicsManager_wrapper() {
    namespace py = boost::python;

    py::class_<graphics::GraphicsManager>("GraphicsManager")
        .def("init", &graphics::GraphicsManager::init)
        .def("stop", &graphics::GraphicsManager::stop)
        .def("is_active", &graphics::GraphicsManager::is_active)
        .def("add_to_render_list", &graphics::GraphicsManager::add_to_render_list)
        .def("remove_from_render_list", &graphics::GraphicsManager::remove_from_render_list)
    ;
}


#endif