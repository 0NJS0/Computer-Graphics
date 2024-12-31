#include <GL/gl.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */

void display() {
    //glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

    /*glPointSize(20.0);
    glBegin(GL_POINTS);
    glColor3f(1.0f, 0.0f, 0.0f); // Red
	glVertex2f(250,250);

	glColor3f(0.0f, 1.0f, 0.0f); // green
	glVertex2f(-250,-250);

	glColor3f(0.247f,0.686f, 0.478f); // blue
	glVertex2f(0,0);

    glEnd();*/

    for(int i=0;i<=240;i=i+60)
    {
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(i,0);
    glVertex2f(i,30);
    glVertex2f(i+30,30);
    glVertex2f(i+30,0);
    glEnd();
    }

    for(int i=30;i<=240;i=i+60)
    {
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(i,30);
    glVertex2f(i,60);
    glVertex2f(i+30,60);
    glVertex2f(i+30,30);
    glEnd();
    }

    for(int i=0;i<=240;i=i+60)
    {
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(i,60);
    glVertex2f(i,90);
    glVertex2f(i+30,90);
    glVertex2f(i+30,60);
    glEnd();
    }

    for(int i=30;i<=240;i=i+60)
    {
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(i,90);
    glVertex2f(i,120);
    glVertex2f(i+30,120);
    glVertex2f(i+30,90);
    glEnd();
    }

    for(int i=0;i<=240;i=i+60)
    {
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(i,120);
    glVertex2f(i,150);
    glVertex2f(i+30,150);
    glVertex2f(i+30,120);
    glEnd();
    }

    for(int i=30;i<=240;i=i+60)
    {
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(i,150);
    glVertex2f(i,180);
    glVertex2f(i+30,180);
    glVertex2f(i+30,150);
    glEnd();
    }

    for(int i=0;i<=240;i=i+60)
    {
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(i,180);
    glVertex2f(i,210);
    glVertex2f(i+30,210);
    glVertex2f(i+30,180);
    glEnd();
    }

    for(int i=30;i<=240;i=i+60)
    {
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(i,210);
    glVertex2f(i,240);
    glVertex2f(i+30,240);
    glVertex2f(i+30,210);
    glEnd();
    }




    glFlush(); // Render now
}

void init() {
    glClearColor(0, 0, 0, 0.0);//last er ta opacity
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,240,0,240);
}


/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500); // Set the window's initial width & height
    glutInitWindowPosition(500, 100);  // Set the window's initial position according to the monitor
    glutCreateWindow("Task-1"); // Create a window with the given title
    init();
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop(); // Enter the event-processing loop
    return 0;
}
