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

    int counter=0;
    int x;

    for(int y=0;y<=240;y=y+30)
    {
    if(counter%2==1)
    {
    x=30;
    }
    else
    {
    x=0;
    }

        for(x;x<=240;x+=60)
        {
        glBegin(GL_QUADS);
        glColor3f(.24f, .54f, .12f);
        glVertex2f(x,y);
        glVertex2f(x+30,y);
        glVertex2f(x+30,y+30);
        glVertex2f(x,y+30);
        glEnd();

        }

        counter++;

    }

    glFlush(); // Render now
}

void init() {
    glClearColor(1, 1, 1, 0.0);//last er ta opacity
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
