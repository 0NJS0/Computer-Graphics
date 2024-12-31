#include <GL/gl.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */

void display() {
    //glClearColor(0.5f, 0.5f, 0.5f, 0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)


    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.6f, 0.0f);
    glVertex2f(0,480);
    glVertex2f(1000,480);
    glVertex2f(1000,360);
    glVertex2f(0,360);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.6f, 0.0f);
    glVertex2f(0,120);
    glVertex2f(1000,120);
    glVertex2f(1000,240);
    glVertex2f(0,240);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.1f, 0.2f);
    glVertex2f(0,600);
    glVertex2f(0,240);
    glVertex2f(360,240);
    glVertex2f(360,600);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2i(140, 400);
    glVertex2i(115, 330);
    glVertex2i(180, 375);
    glVertex2i(245, 330);
    glVertex2i(220, 400);
    glVertex2i(285, 450);
    glVertex2i(205, 450);
    glVertex2i(180, 520);
    glVertex2i(165, 450);
    glVertex2i(80, 450);
    glEnd();

    /*glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(200, 540);
    glVertex2f(284, 320);
    glVertex2f(200, 370);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(200, 540);
    glVertex2f(117, 320);
    glVertex2f(200, 370);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(84, 460);
    glVertex2f(317, 460);
    glVertex2f(200, 370);
    glEnd(); */

    glFlush(); // Render now
}

void init() {
    glClearColor(0.0, 0.4, 0.2, 0.0);//last er ta opacity
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1000, 0, 600);
}


/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1000, 600); // Set the window's initial width & height
    glutInitWindowPosition(300, 50);  // Set the window's initial position according to the monitor
    glutCreateWindow("Rainbow Flag"); // Create a window with the given title
    init();
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop(); // Enter the event-processing loop
    return 0;
}
