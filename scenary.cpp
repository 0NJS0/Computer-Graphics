#include <GL/gl.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */

void display() {
    //glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
//Sky
    glBegin(GL_QUADS);
    glColor3f(.53f, 0.81f, 0.92f);
    glVertex2f(0,600);
    glVertex2f(1000,600);
    glVertex2f(1000,300);
    glVertex2f(0,300);
    glEnd();

//River
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.7f);
    glVertex2i(0, 0);
    glVertex2i(500, 0);
    glVertex2i(200, 150);
    glVertex2i(250, 300);
    glVertex2i(0, 300);
    glEnd();
//TREE
   /* glBegin(GL_POLYGON);
    glColor3f(0.59f, 0.29f, 0.0f);
    glVertex2i(780, 330);
    glVertex2i(860, 330);
    glVertex2i(820, 350);
    glVertex2i(840, 430);
    glVertex2i(780, 430);
    glVertex2i(850, 300);

    glEnd();*/


    glBegin(GL_QUADS);
    glColor3f(.59f, 0.29f, 0.0f);
    glVertex2f(780,330);
    glVertex2f(780,430);
    glVertex2f(820,430);
    glVertex2f(820,330);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(750,390);
    glVertex2f(850,390);
    glVertex2f(800,460);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(750,420);
    glVertex2f(850,420);
    glVertex2f(800,490);
    glEnd();

//House
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.43f);
    glVertex2f(720,150);
    glVertex2f(900,150);
    glVertex2f(900,310);
    glVertex2f(720,310);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.43f);
    glVertex2f(720,150);
    glVertex2f(720,340);
    glVertex2f(640,310);
    glVertex2f(640,200);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 0.3f);
    glVertex2f(720,150);
    glVertex2f(720,330);
    glEnd();
//Doors
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(790,150);
    glVertex2f(830,150);
    glVertex2f(830,240);
    glVertex2f(790,240);
    glEnd();
    //Windows
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(770,240);
    glVertex2f(770,210);
    glVertex2f(740,210);
    glVertex2f(740,240);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(850,240);
    glVertex2f(850,210);
    glVertex2f(880,210);
    glVertex2f(880,240);
    glEnd();

//HOUSE ROOF
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.15f);
    glVertex2f(730,260);
    glVertex2f(950,260);
    glVertex2f(880,350);
    glVertex2f(670,350);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.15f);
    glVertex2f(670,350);
    glVertex2f(610,280);
    glVertex2f(640,270);
    glVertex2f(690,330);
    glEnd();




    glFlush(); // Render now
}

void init() {
    glClearColor(0.59, 0.29, 0, 0.0);//last er ta opacity
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,1000,0,600);
}


/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1000, 600); // Set the window's initial width & height
    glutInitWindowPosition(300, 100);  // Set the window's initial position according to the monitor
    glutCreateWindow("Task-1"); // Create a window with the given title
    init();
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop(); // Enter the event-processing loop
    return 0;
}
