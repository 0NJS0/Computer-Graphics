#include <GL/gl.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */

void display() {
    //glClearColor(0.5f, 0.5f, 0.5f, 0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(900,0);
    glVertex2f(900,240);
    glVertex2f(490,240);
    glVertex2f(155,0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(900,600);
    glVertex2f(900,360);
    glVertex2f(490,360);
    glVertex2f(155,600);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.1f, 0.4f);
    glVertex2f(900,0);
    glVertex2f(900,200);
    glVertex2f(500,200);
    glVertex2f(220,0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.9f, 0.2f, 0.2f);
    glVertex2f(900,600);
    glVertex2f(900,400);
    glVertex2f(500,400);
    glVertex2f(220,600);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.7f, 0.1f);
    glVertex2f(0,525);
    glVertex2f(375,300);
    glVertex2f(0,70);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0,120);
    glVertex2f(300,300);
    glVertex2f(0,475);
    glEnd();

    /*glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(170,600);
    glVertex2f(450,350);
    glVertex2f(900,350);
    glVertex2f(900,400);
    glVertex2f(500,400);
    glVertex2f(220,600);
    glEnd();
    */
    glFlush(); // Render now
}

void init() {
    glClearColor(0.0, 0.48, 0.3, 0.0);//last er ta opacity
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 900, 0, 600);
}


/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(900, 600); // Set the window's initial width & height
    glutInitWindowPosition(300, 50);  // Set the window's initial position according to the monitor
    glutCreateWindow("Rainbow Flag"); // Create a window with the given title
    init();
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop(); // Enter the event-processing loop
    return 0;
}
