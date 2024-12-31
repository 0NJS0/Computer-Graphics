#include <GL/gl.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h
#include <cmath>
#include <iostream>


using namespace std;

float x_1;
float y_1;
float x_2;
float y_2;

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */

void display() {
    //glClearColor(0.5f, 0.5f, 0.5f, 0.0f); // Set background color to black and opaque
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


    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(-100,0);
    glVertex2f(100,0);
    glVertex2f(0,-100);
    glVertex2f(0,100);
    glEnd();


        int x=x_1;
        int y=y_1;
        int tempx;
        int tempy;
        tempx=x_1;
        tempy=y_1;

        int m=(y_2-y_1)/(x_2-x_1);
            if(m<0)
              {
                    abs(m);
              }

            while(x!=x_2 && y!=y_2)
                {
                    glPointSize(20.0);
                    glBegin(GL_POINTS);
                    glColor3f(1.0f, 0.0f, 0.0f); // Red
                    glVertex2f(x,y);
                    glEnd();
                    if(m==1)
                        {
                           x= x++;
                           y=y++;
                        }
                    if(m>1)
                        {
                        tempx= tempx+(1/m);
                        x=round(tempx);
                        y=y++;
                        }
                    if(m<1)
                        {
                        x= x++;
                        tempy=tempy+m;
                        y=round(tempy);
                        }
                }

    glEnd();

    glFlush(); // Render now
}

void init() {
    glClearColor(0, 0, 0, 0.0);//last er ta opacity
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);
}


/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
    cin>>x_1;
    cin>>y_1;
    cin>>x_2;
    cin>>y_2;
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600); // Set the window's initial width & height
    glutInitWindowPosition(500, 100);  // Set the window's initial position according to the monitor
    glutCreateWindow("Task-1"); // Create a window with the given title
    init();
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop(); // Enter the event-processing loop
    return 0;
}
