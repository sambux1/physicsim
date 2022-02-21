#include "graphicsmanager.hpp"
#include <GL/freeglut.h>
#include <cstdio>
#include <thread>

namespace graphics {

GraphicsManager::GraphicsManager() {
    printf("Created graphics manager\n");
    this->active = false;
}

bool GraphicsManager::init(double width, double height) {
    if (this->active) {
        // raise error - there can be only one
        printf("Graphics manager is already initialized\n");
        return false;
    }

    // set up the window
    
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

    this->active = true;

    glutDisplayFunc(this->render);

    std::thread graphics_thread(this->run);

    // this causes a segfault but it works until the end
    graphics_thread.detach();

    return true;
}

// set the display callback function and run the main loop
// runs in a separate thread
void GraphicsManager::run() {
    glutMainLoop();
}

// close the window
// this does not work
void GraphicsManager::stop() {
    glutDestroyWindow(glutGetWindow());
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

bool GraphicsManager::is_active() {
    return this->active;
}

} // namespace graphics