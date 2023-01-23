#include <iostream>
#include <cstdlib>
#include <ctime>
#include <GL/glut.h>

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glBegin(GL_TRIANGLES);
    for (int i = 0; i < 100; i++) {
        float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        float g = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        float b = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        glColor3f(r, g, b);
        float x1 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        float y1 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        float z1 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        float x2 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        float y2 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        float z2 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        float x3 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        float y3 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        float z3 = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        glVertex3f(x1, y1, z1);
        glVertex3f(x2, y2, z2);
        glVertex3f(x3, y3, z3);
    }
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    srand(time(NULL));
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}