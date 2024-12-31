#include <GL/gl.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */

void display() {
    //glClearColor(0.5f, 0.5f, 0.5f, 0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)


    glBegin(GL_QUADS);
    glColor3f(0.58f, 0.0f, 0.83f);
    glVertex2f(0,0);
    glVertex2f(0,100);
    glVertex2f(1000,100);
    glVertex2f(1000,0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0,100);
    glVertex2f(0,200);
    glVertex2f(1000,200);
    glVertex2f(1000,100);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0,200);
    glVertex2f(0,300);
    glVertex2f(1000,300);
    glVertex2f(1000,200);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0,300);
    glVertex2f(0,400);
    glVertex2f(1000,400);
    glVertex2f(1000,300);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.49f, 0.0f);
    glVertex2f(0,400);
    glVertex2f(0,500);
    glVertex2f(1000,500);
    glVertex2f(1000,400);
    glEnd();

    glFlush(); // Render now
}

void init() {
    glClearColor(1, 0.0, 0.0, 0.0);//last er ta opacity
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
