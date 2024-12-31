#include <GL/gl.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h
#include <cmath>
#include <iostream>

using namespace std;

int operation;
int xi1, yi1, xi2, yi2, xi3, yi3;
float tx, ty;
float sx, sy;
int angle;
int rotation;

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */

void display() {
    //glClearColor(0.5f, 0.5f, 0.5f, 0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(-10,0);
    glVertex2f(10,0);
    glVertex2f(0,-10);
    glVertex2f(0,10);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.7f, 0.1f);
    glVertex2f(xi1,yi1);
    glVertex2f(xi2,yi2);
    glVertex2f(xi3,yi3);
    glEnd();

    switch(operation){
    case 1:
    {
        int x_1=round(xi1+tx);
        int y_1=round(yi1+ty);

        int x_2=round(xi2+tx);
        int y_2=round(yi2+ty);

        int x_3=round(xi3+tx);
        int y_3=round(yi3+ty);

        glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.7f, 0.1f);
        glVertex2f(x_1,y_1);
        glVertex2f(x_2,y_2);
        glVertex2f(x_3,y_3);
        glEnd();
        break;
   }
    case 2:
    {
        int xs1=round(xi1*sx);
        int ys1=round(yi1*sy);

        int xs2=round(xi2*sx);
        int ys2=round(yi2*sy);

        int xs3=round(xi3*sx);
        int ys3=round(yi3*sy);

        glBegin(GL_TRIANGLES);
        glColor3f(0.5f, 0.7f, 0.1f);
        glVertex2f(xs1,ys1);
        glVertex2f(xs2,ys2);
        glVertex2f(xs3,ys3);
        glEnd();
        break;
    }
    case 3:
    {
        float radians = angle * M_PI / 180.0f;

        float cosTheta = cos(radians);
        float sinTheta = sin(radians);

        if(rotation==2)
        {
            float rx1 = round(xi1*cosTheta-yi1*sinTheta);
            float ry1 = round(xi1*sinTheta+yi1*cosTheta);

            float rx2 = round(xi2*cosTheta-yi2*sinTheta);
            float ry2 = round(xi2*sinTheta+yi2*cosTheta);

            float rx3 = round(xi3*cosTheta-yi3*sinTheta);
            float ry3 = round(xi3*sinTheta+yi3*cosTheta);

            glBegin(GL_TRIANGLES);
            glColor3f(0.5f, 0.8f, 1.0f);
            glVertex2f(rx1, ry1);
            glVertex2f(rx2, ry2);
            glVertex2f(rx3, ry3);
            glEnd();
        }

        if (rotation==1)
        {
            float rx1 = round(xi1*cosTheta+yi1*sinTheta);
            float ry1 = round(yi1*cosTheta-xi1*sinTheta);

            float rx2 = round(xi2*cosTheta+yi2*sinTheta);
            float ry2 = round(yi2*cosTheta-xi2*sinTheta);

            float rx3 = round(xi3*cosTheta+yi3*sinTheta);
            float ry3 = round(yi3*cosTheta-xi3*sinTheta);

            glBegin(GL_TRIANGLES);
            glColor3f(0.5f, 0.8f, 1.0f);
            glVertex2f(rx1, ry1);
            glVertex2f(rx2, ry2);
            glVertex2f(rx3, ry3);
            glEnd();
        }
        break;
    }

        default:
            break;
    }

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
    cout << "Enter Vertex 1: ";
    cin>>xi1>>yi1;
    cout << "Vertex 2: ";
    cin>>xi2>>yi2;
    cout << "Vertex 3: ";
    cin>>xi3>>yi3;

    cout << "Press what you want to do: ";
    cout << "1.Translate ";
    cout << "2.Scalling ";
    cout << "3.Rotate ";
    cin>>operation;

    switch(operation){
    case 1:
    cout << "Enter tx and ty :";
    cin>>tx>>ty;
    break;

    case 2:
    cout << "Enter tx and ty :";
    cin>>sx>>sy;
    break;

    case 3:
    cout << "Enter rotation angle (degrees): ";
    cin >> angle;
    cout << "Choose rotation direction: "<<endl;
    cout<<"1.Clockwise"<<endl;
    cout<<"2.Anticlockwise"<<endl;
    cin >> rotation;
    break;

    default:
    cout << "Exiting!!" << endl;
    return 0;
    }
    glutInit(&argc, argv);
    glutInitWindowSize(400, 400); // Set the window's initial width & height
    glutInitWindowPosition(100, 100);  // Set the window's initial position according to the monitor
    glutCreateWindow("Breshenham"); // Create a window with the given title
    init();
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop(); // Enter the event-processing loop
    return 0;
}
