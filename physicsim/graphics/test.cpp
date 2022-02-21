#include <GL/freeglut.h>
#include <cstdio>
#include "renderableinterface.hpp"

/*
static float f = 0.0;

void render(void) {

    //glClearColor(0.8, 0.6, 0.95, 0);
    //glClear(GL_COLOR_BUFFER_BIT);
    //glFlush();

    // tells GL to clear color buffer AND depth buffer
    // I'm guessing each is a bit in an int and the OR signals
    //      that both bits should be 1
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_POINTS);
    glVertex3f(f, 0.8, 0.0);
    glVertex3f(0.0, -0.8, 0.0);
    glEnd();


    glutSwapBuffers();

    f+=0.2;
}

#include "graphicsmanager.cpp"
int main() {
    graphics::GraphicsManager g;
    printf("Active: %d\n", g.is_active());
    printf("Initialized successfully: %d\n", g.init(0.0f, 0.0f));
    printf("Active: %d\n", g.is_active());
    printf("Initialized successfully: %d\n", g.init(0.0f, 0.0f));
}
int main() {
    printf("hello\n");
    int argc = 0;
    char** argv;
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(100, 100);
    glutCreateWindow("holaaa title");

    glutDisplayFunc(render);
    glutMainLoop();
    sleep(2);
    glutPostRedisplay();

    return 0;
}
*/

int main() {
    printf("hello\n");
    graphics::Implementation i;
    i.render();
}