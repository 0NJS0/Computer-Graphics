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


    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(-100,0);
    glVertex2f(100,0);
    glVertex2f(0,-100);
    glVertex2f(0,100);
    glEnd();

        float dx=x_2-x_1;
        float dy=y_2-y_1;
        float x=x_1;
        float y=y_1;

        float m=dy/dx;

        glPointSize(5.0);
        glBegin(GL_POINTS);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(x,y);

        m=abs(m);

        if(m==1)
        {
            while(x !=x_2 && y !=y_2)
            {
                x++;
                y++;
                glVertex2f(round(x),round(y));
            }
        }

        if(m>1)
        {
            while(x !=x_2 && y !=y_2)
            {
                float n=(1/m);
                x+=n;
                y++;
                glVertex2f(round(x),round(y));
            }
        }

        if(m<1)
        {
            while(x !=x_2 && y !=y_2)
            {
                x++;
                y+=m;
                glVertex2f(round(x),round(y));
            }
        }



    glEnd();

    glFlush(); // Render now
}

void init() {
    glClearColor(0, 0, 0, 0.0);//last er ta opacity
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10);
}


/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
    cin>>x_1;
    cin>>y_1;
    cin>>x_2;
    cin>>y_2;
    glutInit(&argc, argv);
    glutInitWindowSize(400, 400); // Set the window's initial width & height
    glutInitWindowPosition(100, 100);  // Set the window's initial position according to the monitor
    glutCreateWindow("DDA"); // Create a window with the given title
    init();
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop(); // Enter the event-processing loop
    return 0;
}
