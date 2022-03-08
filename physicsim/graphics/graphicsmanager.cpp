#include "graphicsmanager.hpp"
#include "renderableinterface.hpp"
#include <GL/freeglut.h>
#include <cstdio>
#include <thread>
#include <set>

namespace graphics {

std::set<RenderableInterface*> GraphicsManager::render_list;

GraphicsManager::GraphicsManager() {
    this->active = false;
}

bool GraphicsManager::init(double width, double height) {
    if (this->active) {
        // raise error - there can be only one
        printf("Graphics manager is already initialized\n");
        return false;
    }

    try {
        // create a new thread for the graphics window and detach it
        struct GraphicsThreadInfo info;
        std::thread graphics_thread(this->runGlutWindow, info);
        graphics_thread.detach();
        this->active = true;
        return true;
    } catch (...) {
        // something went wrong, handle error
        return false;
    }
}

// close the window
// this does not work
void GraphicsManager::stop() {
}

bool GraphicsManager::is_active() {
    return this->active;
}


// add a renderable object to the set
void GraphicsManager::add_to_render_list(RenderableInterface* object) {
    printf("Size %d\n", render_list.size());
    render_list.insert(object);
    printf("Size %d\n", render_list.size());
}

// remove a renderable object from the set
void GraphicsManager::remove_from_render_list(RenderableInterface* object) {
    printf("Size %d\n", render_list.size());
    render_list.erase(object);
    printf("Size %d\n", render_list.size());
}

// create and run the GLUT window
// runs in a separate thread
void GraphicsManager::runGlutWindow(struct GraphicsThreadInfo info) {
    // call the init function with dummy parameters
    // it needs 2 arguments, but it won't use them if argc = 0
    int argc = 0;
    char** argv;
    glutInit(&argc, argv);

    // create the window
    // using dummy numbers for now
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(100, 100);
    glutCreateWindow("physicsim");

    // set the display callback function
    glutDisplayFunc(render);

    // main event loop
    // this repeatedly calls the event handler but not glutMainLoop()
    // this allows us to do stuff between event loop iterations
    while (true) {
        glutMainLoopEvent();
        render();
    }
}

void GraphicsManager::render(void) {
    // tells GL to clear color buffer AND depth buffer
    // I'm guessing each is a bit in an int and the OR signals
    //      that both bits should be 1
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // begin drawing points
    glBegin(GL_POINTS);
        glVertex3f(0.0, 0.8, 0.0);
        glVertex3f(0.0, -0.8, 0.0);
    glEnd();

    // update the screen
    glutSwapBuffers();
}

} // namespace graphics