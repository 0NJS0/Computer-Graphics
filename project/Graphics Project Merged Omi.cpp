#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <conio.h>
#include <cmath>
#include<cstdio>
#include <windows.h>
#include<math.h>
#include <vector>
#include <cstdlib>
# define PI 3.14159265358979323846
#include <GL/gl.h>
#include <GL/glut.h>
#include<MMSystem.h>
using namespace std;


//Najmus
bool batmobileautomove=false;
bool batmobilemoveforware=false;
bool planeMovement=true;
bool sunMovement = true;
int currentScene = 1;
bool batsignal=false;
float cloud1X = 500.0f;
float cloud2X = 850.0f;
float sunY=600.0f;
float carX = 0.0f;
float busX= 0.0f;
float birdX = 0.0f;
float birdWingAngle = 0.0f;
bool birdWingDirection = true;
float batmobile=0.0f;
float planeX=0.0f;
float planeY=0.0f;

void drawCircle(float centerX, float centerY, float radius) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float pi = 3.1416;
        float angle = (i * 2 * pi) / 180;
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

void drawEllipse(float centerX, float centerY, float radiusX, float radiusY) {


    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(centerX, centerY);


    for (int i = 0; i <= 360; ++i) {
        float theta = 2.0f * 3.1415926f * float(i) / float(360);

        float x = radiusX * cosf(theta);
        float y = radiusY * sinf(theta);

        glVertex2f(x + centerX, y + centerY);
    }

    glEnd();
}

void quad(float ax, float ay, float bx, float by, float cx, float cy, float dx, float dy)
{
    glBegin(GL_POLYGON);
    glVertex2f(ax, ay);
    glVertex2f(bx, by);
    glVertex2f(cx, cy);
    glVertex2f(dx, dy);
    glEnd();
}


void drawRectangle(int x, int y, int width, int height) {
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}

void drawBird(float x, float y) {
    glColor3f(0.0f, 0.0f, 0.0f);

    // Body
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + 5, y + 2);
    glVertex2f(x + 10, y);
    glVertex2f(x + 5, y - 2);
    glEnd();

    // Left wing
    glBegin(GL_TRIANGLES);
    glVertex2f(x, y);
    glVertex2f(x - 7, y + 5);
    glVertex2f(x - 7 + birdWingAngle / 2, y + 18);
    glEnd();

    // Right wing
    glBegin(GL_TRIANGLES);
    glVertex2f(x, y);
    glVertex2f(x + 7, y + 5);
    glVertex2f(x + 7 - birdWingAngle / 2, y + 17);
    glEnd();
}
//Shamim
float boatPosition1 = 700.0f; // Initial position of the ----------------------------------boat
float birdPosition = 80.0f;
//float position = 0.0f; // Position of the cycle along the x-axis----------------------------------cycle
//float angle = 0.0f;    // Rotation angle for wheels .......................................................cycle
float position = 1000.0f;  // Initial position of the cycle (right side of the screen)
float angle = 0.0f;
float sunPosition=800.0f;
GLboolean sunMoving = true; // Control flag for sun movement

GLboolean boatMoving1 = true;

GLfloat cloudPosition1 = 0.0;

GLboolean cloudMoving1 = true;

void cloud1D()
{
    int i;
    GLfloat x = (0.5f + 1.0f) * 500.0f; GLfloat y = (0.86f + 1.0f) * 500.0f; GLfloat radius = 50.0f / 2.0f; // Scale radius to one-third
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0, 1.0, 1.0); // white
        glVertex2f(x, y); // center of circle
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                x + (radius * cos(i * twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();

    GLfloat a = (0.55f + 1.0f) * 500.0f; GLfloat b = (0.83f + 1.0f) * 500.0f;
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0, 1.0, 1.0); // white
        glVertex2f(a, b); // center of circle
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                a + (radius * cos(i * twicePi / triangleAmount)),
                b + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();

    GLfloat c = (0.45f + 1.0f) * 500.0f; GLfloat d = (0.83f + 1.0f) * 500.0f;
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0, 1.0, 1.0); // white
        glVertex2f(c, d); // center of circle
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                c + (radius * cos(i * twicePi / triangleAmount)),
                d + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();

    GLfloat e = (0.52f + 1.0f) * 500.0f; GLfloat f = (0.8f + 1.0f) * 500.0f;
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0, 1.0, 1.0); // white
        glVertex2f(e, f); // center of circle
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                e + (radius * cos(i * twicePi / triangleAmount)),
                f + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();

    GLfloat g = (0.6f + 1.0f) * 500.0f; GLfloat h = (0.82f + 1.0f) * 500.0f;
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0, 1.0, 1.0); // white
        glVertex2f(g, h); // center of circle
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                g + (radius * cos(i * twicePi / triangleAmount)),
                h + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();
}

void cloud2D()
{
  int i;
    GLfloat x = (-0.5f + 1.0f) * 500.0f; GLfloat y = (0.86f + 1.0f) * 500.0f; GLfloat radius = 50.0f / 2.0f; // Scale radius to one-third
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0, 1.0, 1.0); // white
        glVertex2f(x, y); // center of circle
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                x + (radius * cos(i * twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();

    GLfloat a = (-0.55f + 1.0f) * 500.0f; GLfloat b = (0.83f + 1.0f) * 500.0f;
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0, 1.0, 1.0); // white
        glVertex2f(a, b); // center of circle
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                a + (radius * cos(i * twicePi / triangleAmount)),
                b + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();

    GLfloat c = (-0.45f + 1.0f) * 500.0f; GLfloat d = (0.83f + 1.0f) * 500.0f;
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0, 1.0, 1.0); // white
        glVertex2f(c, d); // center of circle
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                c + (radius * cos(i * twicePi / triangleAmount)),
                d + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();

    GLfloat e = (-0.52f + 1.0f) * 500.0f; GLfloat f = (0.8f + 1.0f) * 500.0f;
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0, 1.0, 1.0); // white
        glVertex2f(e, f); // center of circle
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                e + (radius * cos(i * twicePi / triangleAmount)),
                f + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();

    GLfloat g = (-0.6f + 1.0f) * 500.0f; GLfloat h = (0.82f + 1.0f) * 500.0f;
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0, 1.0, 1.0); // white
        glVertex2f(g, h); // center of circle
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                g + (radius * cos(i * twicePi / triangleAmount)),
                h + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();
}

void cloud3D()
{
    int i;
    GLfloat x = (0.0f + 1.0f) * 500.0f; GLfloat y = (0.86f + 1.0f) * 500.0f; GLfloat radius = 50.0f / 2.0f; // Scale radius to one-third
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0, 1.0, 1.0); // white
        glVertex2f(x, y); // center of circle
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                x + (radius * cos(i * twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();

    GLfloat a = (0.05f + 1.0f) * 500.0f; GLfloat b = (0.83f + 1.0f) * 500.0f;
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0, 1.0, 1.0); // white
        glVertex2f(a, b); // center of circle
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                a + (radius * cos(i * twicePi / triangleAmount)),
                b + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();

    GLfloat c = (-0.05f + 1.0f) * 500.0f; GLfloat d = (0.83f + 1.0f) * 500.0f;
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0, 1.0, 1.0); // white
        glVertex2f(c, d); // center of circle
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                c + (radius * cos(i * twicePi / triangleAmount)),
                d + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();

    GLfloat e = (0.02f + 1.0f) * 500.0f; GLfloat f = (0.8f + 1.0f) * 500.0f;
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0, 1.0, 1.0); // white
        glVertex2f(e, f); // center of circle
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                e + (radius * cos(i * twicePi / triangleAmount)),
                f + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();

    GLfloat g = (0.1f + 1.0f) * 500.0f; GLfloat h = (0.82f + 1.0f) * 500.0f;
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0, 1.0, 1.0); // white
        glVertex2f(g, h); // center of circle
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                g + (radius * cos(i * twicePi / triangleAmount)),
                h + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();
}

void cloud1N()
{
    int i;
    GLfloat x = (0.5f + 1.0f) * 500.0f; GLfloat y = (0.86f + 1.0f) * 500.0f; GLfloat radius = 50.0f / 2.0f; // Scale radius to one-third
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
glColor3f(0.3f, 0.3f, 0.4f); // Dark Gray-Blue Cloud
        glVertex2f(x, y); // center of circle
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                x + (radius * cos(i * twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();

    GLfloat a = (0.55f + 1.0f) * 500.0f; GLfloat b = (0.83f + 1.0f) * 500.0f;
    glBegin(GL_TRIANGLE_FAN);
glColor3f(0.3f, 0.3f, 0.4f); // Dark Gray-Blue Cloud
        glVertex2f(a, b); // center of circle
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                a + (radius * cos(i * twicePi / triangleAmount)),
                b + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();

    GLfloat c = (0.45f + 1.0f) * 500.0f; GLfloat d = (0.83f + 1.0f) * 500.0f;
    glBegin(GL_TRIANGLE_FAN);
glColor3f(0.3f, 0.3f, 0.4f); // Dark Gray-Blue Cloud
        glVertex2f(c, d); // center of circle
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                c + (radius * cos(i * twicePi / triangleAmount)),
                d + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();

    GLfloat e = (0.52f + 1.0f) * 500.0f; GLfloat f = (0.8f + 1.0f) * 500.0f;
    glBegin(GL_TRIANGLE_FAN);
glColor3f(0.3f, 0.3f, 0.4f); // Dark Gray-Blue Cloud
        glVertex2f(e, f); // center of circle
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                e + (radius * cos(i * twicePi / triangleAmount)),
                f + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();

    GLfloat g = (0.6f + 1.0f) * 500.0f; GLfloat h = (0.82f + 1.0f) * 500.0f;
    glBegin(GL_TRIANGLE_FAN);
glColor3f(0.3f, 0.3f, 0.4f); // Dark Gray-Blue Cloud
        glVertex2f(g, h); // center of circle
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                g + (radius * cos(i * twicePi / triangleAmount)),
                h + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();
}

void cloud2N()
{
  int i;
    GLfloat x = (-0.5f + 1.0f) * 500.0f; GLfloat y = (0.86f + 1.0f) * 500.0f; GLfloat radius = 50.0f / 2.0f; // Scale radius to one-third
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
glColor3f(0.3f, 0.3f, 0.4f); // Dark Gray-Blue Cloud
        glVertex2f(x, y); // center of circle
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                x + (radius * cos(i * twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();

    GLfloat a = (-0.55f + 1.0f) * 500.0f; GLfloat b = (0.83f + 1.0f) * 500.0f;
    glBegin(GL_TRIANGLE_FAN);
glColor3f(0.3f, 0.3f, 0.4f); // Dark Gray-Blue Cloud
        glVertex2f(a, b); // center of circle
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                a + (radius * cos(i * twicePi / triangleAmount)),
                b + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();

    GLfloat c = (-0.45f + 1.0f) * 500.0f; GLfloat d = (0.83f + 1.0f) * 500.0f;
    glBegin(GL_TRIANGLE_FAN);
glColor3f(0.3f, 0.3f, 0.4f); // Dark Gray-Blue Cloud
        glVertex2f(c, d); // center of circle
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                c + (radius * cos(i * twicePi / triangleAmount)),
                d + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();

    GLfloat e = (-0.52f + 1.0f) * 500.0f; GLfloat f = (0.8f + 1.0f) * 500.0f;
    glBegin(GL_TRIANGLE_FAN);
glColor3f(0.3f, 0.3f, 0.4f); // Dark Gray-Blue Cloud
        glVertex2f(e, f); // center of circle
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                e + (radius * cos(i * twicePi / triangleAmount)),
                f + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();

    GLfloat g = (-0.6f + 1.0f) * 500.0f; GLfloat h = (0.82f + 1.0f) * 500.0f;
    glBegin(GL_TRIANGLE_FAN);
glColor3f(0.3f, 0.3f, 0.4f); // Dark Gray-Blue Cloud
        glVertex2f(g, h); // center of circle
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                g + (radius * cos(i * twicePi / triangleAmount)),
                h + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();
}
void cloud3N()
{
    int i;
    GLfloat x = (0.0f + 1.0f) * 500.0f; GLfloat y = (0.86f + 1.0f) * 500.0f; GLfloat radius = 50.0f / 2.0f; // Scale radius to one-third
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
glColor3f(0.3f, 0.3f, 0.4f); // Dark Gray-Blue Cloud
        glVertex2f(x, y); // center of circle
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                x + (radius * cos(i * twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();

    GLfloat a = (0.05f + 1.0f) * 500.0f; GLfloat b = (0.83f + 1.0f) * 500.0f;
    glBegin(GL_TRIANGLE_FAN);
glColor3f(0.3f, 0.3f, 0.4f); // Dark Gray-Blue Cloud
        glVertex2f(a, b); // center of circle
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                a + (radius * cos(i * twicePi / triangleAmount)),
                b + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();

    GLfloat c = (-0.05f + 1.0f) * 500.0f; GLfloat d = (0.83f + 1.0f) * 500.0f;
    glBegin(GL_TRIANGLE_FAN);
glColor3f(0.3f, 0.3f, 0.4f); // Dark Gray-Blue Cloud
        glVertex2f(c, d); // center of circle
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                c + (radius * cos(i * twicePi / triangleAmount)),
                d + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();

    GLfloat e = (0.02f + 1.0f) * 500.0f; GLfloat f = (0.8f + 1.0f) * 500.0f;
    glBegin(GL_TRIANGLE_FAN);
glColor3f(0.3f, 0.3f, 0.4f); // Dark Gray-Blue Cloud
        glVertex2f(e, f); // center of circle
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                e + (radius * cos(i * twicePi / triangleAmount)),
                f + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();

    GLfloat g = (0.1f + 1.0f) * 500.0f; GLfloat h = (0.82f + 1.0f) * 500.0f;
    glBegin(GL_TRIANGLE_FAN);
glColor3f(0.3f, 0.3f, 0.4f); // Dark Gray-Blue Cloud
        glVertex2f(g, h); // center of circle
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                g + (radius * cos(i * twicePi / triangleAmount)),
                h + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();
}
float plane1X = 1000; // Starting position at the right (X = 1000)

void updateplane() {
    // Decrease the X position to move the plane to the left
    plane1X -= 2; // Adjust this value to control the speed of the movement

    if (plane1X < -300) { // Reset position when it goes off-screen
        plane1X = 1000; // Restart at the right edge
    }
}

void drawSun1(GLfloat x, GLfloat y, GLfloat radius) {
    int numSegments = 100;
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= numSegments; ++i) {
        GLfloat angle = 2.0f * 3.14159f * i / numSegments;
        glVertex2f(x + cos(angle) * radius, y + sin(angle) * radius);
    }
    glEnd();
}

void drawPlane() {
    // Cargo plane body
glColor3f(0.7f, 0.1f, 0.1f); // A deeper warm red color
    glBegin(GL_POLYGON);
    glVertex2f(60 + plane1X + 30 + 20, 850 + 50 + 20);
    glVertex2f(210 + plane1X + 30 + 20, 850 + 50 + 20);
    glVertex2f(225 + plane1X + 30 + 20, 865 + 50 + 20);
    glVertex2f(210 + plane1X + 30 + 20, 880 + 50 + 20);
    glVertex2f(60 + plane1X + 30 + 20, 880 + 50 + 20);
    glVertex2f(45 + plane1X + 30 + 20, 865 + 50 + 20);
    glEnd();

    // Cockpit
    glColor3f(0.3f, 0.6f, 0.9f); // Rich blue for the cockpit
    glBegin(GL_POLYGON);
    glVertex2f(195 + plane1X + 30 + 20, 860 + 50 + 20);
    glVertex2f(210 + plane1X + 30 + 20, 860 + 50 + 20);
    glVertex2f(219 + plane1X + 30 + 20, 870 + 50 + 20);
    glVertex2f(210 + plane1X + 30 + 20, 880 + 50 + 20);
    glVertex2f(195 + plane1X + 30 + 20, 880 + 50 + 20);
    glEnd();

   /* // Tail fin
    glColor3f(1.0f, 0.0f, 0.0f); // Red color for tail fin
    glBegin(GL_POLYGON);
    glVertex2f(60 + planeX + 30 + 20, 880 + 50 + 20);
    glVertex2f(45 + planeX + 30 + 20, 920 + 50 + 20);
    glVertex2f(54 + planeX + 30 + 20, 920 + 50 + 20);
    glVertex2f(66 + planeX + 30 + 20, 880 + 50 + 20);
    glEnd(); */

/*
    // Horizontal stabilizers
    glColor3f(0.1f, 0.2f, 0.6f); // Dark blue for stabilizers
    glBegin(GL_POLYGON);
    glVertex2f(54 + planeX + 30 + 20, 880 + 50 + 20);
    glVertex2f(36 + planeX + 30 + 20, 902 + 50 + 20);
    glVertex2f(45 + planeX + 30 + 20, 906 + 50 + 20);
    glVertex2f(60 + planeX + 30 + 20, 880 + 50 + 20);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(54 + planeX + 30 + 20, 850 + 50 + 20);
    glVertex2f(36 + planeX + 30 + 20, 828 + 50 + 20);
    glVertex2f(45 + planeX + 30 + 20, 824 + 50 + 20);
    glVertex2f(60 + planeX + 30 + 20, 850 + 50 + 20);
    glEnd();*/

    // Enhanced Wings
glColor3f(0.8f, 0.7f, 0.2f); // Deeper warm yellow for the plane wings

    glBegin(GL_POLYGON);
    glVertex2f(120 + plane1X + 30 + 20, 850 + 50 + 20);
    glVertex2f(190 + plane1X + 30 + 20, 820 + 50 + 20);
    glVertex2f(210 + plane1X + 30 + 20, 835 + 50 + 20);
    glVertex2f(140 + plane1X + 30 + 20, 850 + 50 + 20);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(120 + plane1X + 30 + 20, 880 + 50 + 20);
    glVertex2f(190 + plane1X + 30 + 20, 910 + 50 + 20);
    glVertex2f(210 + plane1X + 30 + 20, 895 + 50 + 20);
    glVertex2f(140 + plane1X + 30 + 20, 880 + 50 + 20);
    glEnd();

    // Add realistic wing structure (lines and details)
    glColor3f(0.3f, 0.3f, 0.3f);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2f(140 + plane1X + 30 + 20, 850 + 50 + 20);
    glVertex2f(170 + plane1X + 30 + 20, 835 + 50 + 20);
    glVertex2f(140 + plane1X + 30 + 20, 880 + 50 + 20);
    glVertex2f(170 + plane1X + 30 + 20, 895 + 50 + 20);
    glVertex2f(160 + plane1X + 30 + 20, 850 + 50 + 20);
    glVertex2f(180 + plane1X + 30 + 20, 845 + 50 + 20);
    glVertex2f(160 + plane1X + 30 + 20, 880 + 50 + 20);
    glVertex2f(180 + plane1X + 30 + 20, 885 + 50 + 20);
    glEnd();

    // Engines under wings
    glColor3f(0.3f, 0.3f, 0.3f); // Medium gray for engines
    glBegin(GL_POLYGON);
    glVertex2f(175 + plane1X + 30 + 20, 846 + 50 + 20);
    glVertex2f(185 + plane1X + 30 + 20, 846 + 50 + 20);
    glVertex2f(185 + plane1X + 30 + 20, 860 + 50 + 20);
    glVertex2f(175 + plane1X + 30 + 20, 860 + 50 + 20);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(175 + plane1X + 30 + 20, 880 + 50 + 20);
    glVertex2f(185 + plane1X + 30 + 20, 880 + 50 + 20);
    glVertex2f(185 + plane1X + 30 + 20, 894 + 50 + 20);
    glVertex2f(175 + plane1X + 30 + 20, 894 + 50 + 20);
    glEnd();

    // Windows
    glColor3f(0.9f, 0.9f, 0.7f); // Ash white windows for contrast
    for (int i = 66 + plane1X + 30 + 20; i <= 180 + plane1X + 30 + 20; i += 30) {
        glBegin(GL_POLYGON);
        glVertex2f(i, 870 + 50 + 20);
        glVertex2f(i + 10, 870 + 50 + 20);
        glVertex2f(i + 10, 878 + 50 + 20);
        glVertex2f(i, 878 + 50 + 20);
        glEnd();
    }

    glFlush();
}
void backgroundtree()
{
    // Palm trees (scaled height by 70%)
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(200.0f, 650.0f);
    glVertex2f(240.0f, 650.0f);
    glVertex2f(240.0f, 767.0f);
    glVertex2f(220.0f, 785.0f);
    glVertex2f(200.0f, 767.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(34, 139, 34);
    glVertex2f(220.0f, 785.0f);
    glVertex2f(200.0f, 767.0f);
    glVertex2f(140.0f, 757.0f);
    glVertex2f(170.0f, 775.0f);
    glVertex2f(140.0f, 793.0f);
    glVertex2f(200.0f, 793.0f);
    glVertex2f(200.0f, 849.0f);
    glVertex2f(220.0f, 825.0f);
    glVertex2f(240.0f, 849.0f);
    glVertex2f(240.0f, 793.0f);
    glVertex2f(300.0f, 793.0f);
    glVertex2f(270.0f, 775.0f);
    glVertex2f(300.0f, 757.0f);
    glVertex2f(240.0f, 767.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(800.0f, 650.0f);
    glVertex2f(760.0f, 650.0f);
    glVertex2f(760.0f, 767.0f);
    glVertex2f(780.0f, 785.0f);
    glVertex2f(800.0f, 767.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(34, 139, 34);
    glVertex2f(780.0f, 785.0f);
    glVertex2f(800.0f, 767.0f);
    glVertex2f(860.0f, 757.0f);
    glVertex2f(830.0f, 775.0f);
    glVertex2f(860.0f, 793.0f);
    glVertex2f(800.0f, 793.0f);
    glVertex2f(800.0f, 849.0f);
    glVertex2f(780.0f, 825.0f);
    glVertex2f(760.0f, 849.0f);
    glVertex2f(760.0f, 793.0f);
    glVertex2f(700.0f, 793.0f);
    glVertex2f(730.0f, 775.0f);
    glVertex2f(700.0f, 757.0f);
    glVertex2f(760.0f, 767.0f);
    glEnd();

    // General trees and foliage (scaled height by 70%)
    glBegin(GL_POLYGON);
    glColor3ub(34, 139, 34);
    glVertex2f(0.0f, 650.0f);
    glVertex2f(20.0f, 685.0f);
    glVertex2f(70.0f, 722.0f);
    glVertex2f(100.0f, 750.0f);
    glVertex2f(180.0f, 785.0f);
    glVertex2f(250.0f, 806.0f);
    glVertex2f(320.0f, 785.0f);
    glVertex2f(400.0f, 750.0f);
    glVertex2f(430.0f, 722.0f);
    glVertex2f(480.0f, 685.0f);
    glVertex2f(500.0f, 650.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(34, 139, 34);
    glVertex2f(1000.0f, 650.0f);
    glVertex2f(980.0f, 685.0f);
    glVertex2f(930.0f, 722.0f);
    glVertex2f(900.0f, 750.0f);
    glVertex2f(820.0f, 785.0f);
    glVertex2f(750.0f, 806.0f);
    glVertex2f(680.0f, 785.0f);
    glVertex2f(600.0f, 750.0f);
    glVertex2f(570.0f, 722.0f);
    glVertex2f(520.0f, 685.0f);
    glVertex2f(500.0f, 650.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(34, 139, 34);
    glVertex2f(250.0f, 650.0f);
    glVertex2f(270.0f, 685.0f);
    glVertex2f(300.0f, 722.0f);
    glVertex2f(330.0f, 750.0f);
    glVertex2f(380.0f, 775.0f);
    glVertex2f(430.0f, 750.0f);
    glVertex2f(460.0f, 722.0f);
    glVertex2f(480.0f, 685.0f);
    glVertex2f(500.0f, 650.0f);
    glEnd();
}




void tree_1(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{
    glBegin(GL_POLYGON);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.1416 / 180;
        float x = rx * cos(angle);
        float y = ry * sin(angle);
        glVertex2f((x + cx), (y + cy));
    }
    glEnd();
}
void tree()
{


glColor3ub(0, 128, 0);
tree_1(30, 40, 102, 670); // Original (100, 670)

glColor3ub(0, 128, 0);
tree_1(30, 40, 152, 670); // Original (150, 670)

glColor3ub(0, 128, 0);
tree_1(25, 30, 112, 720); // Original (110, 720)

glColor3ub(0, 128, 0);
tree_1(30, 30, 137, 720); // Original (135, 720)

glColor3ub(0, 128, 0);
tree_1(25, 30, 122, 750); // Original (120, 750)






    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(140.0f, 425.0f);
    glVertex2f(175.0f, 400.0f);
    glVertex2f(132.5f, 415.0f);
    glVertex2f(130.0f, 375.0f);
    glVertex2f(112.5f, 415.0f);
    glVertex2f(75.0f, 400.0f);
    glVertex2f(110.0f, 425.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(110.0f, 425.0f);
    glVertex2f(110.0f, 615.0f);
    glVertex2f(140.0f, 615.0f);
    glVertex2f(140.0f, 425.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(120.0f, 615.0f);
    glVertex2f(120.0f, 650.0f);
    glVertex2f(130.0f, 650.0f);
    glVertex2f(130.0f, 615.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(130.0f, 615.0f);
    glVertex2f(145.0f, 645.0f);
    glVertex2f(150.0f, 640.0f);
    glVertex2f(140.0f, 615.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 51, 0);
    glVertex2f(110.0f, 615.0f);
    glVertex2f(100.0f, 640.0f);
    glVertex2f(105.0f, 645.0f);
    glVertex2f(120.0f, 615.0f);
    glEnd();

    int i;
    GLfloat x = 125.0f, y = 665.0f, radius = 30.0f;
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    /////////////////////////////////////
    // glColor3ub(51, 204, 51);
    glColor3ub(0, 128, 0);

    glVertex2f(x, y);
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLfloat positions[][2] = {
        {160.0f, 655.0f}, {95.0f, 655.0f}, {70.0f, 675.0f}, {195.0f, 675.0f},
        {195.0f, 700.0f}, {70.0f, 700.0f}, {100.0f, 720.0f}, {50.0f, 720.0f},
        {160.0f, 720.0f}, {125.0f, 720.0f}, {80.0f, 720.0f}
    };

    for (int j = 0; j < 11; j++) {
        x = positions[j][0];
        y = positions[j][1];

        glBegin(GL_TRIANGLE_FAN);
         //////////////////////////////////////////////////////////////////////////////////
        glColor3ub(51, 204, 51);
        glColor3ub(0, 128, 0);

        glVertex2f(x, y);
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                x + (radius * cos(i * twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
        glEnd();
    }



}

void tree_2(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{
    glBegin(GL_POLYGON);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.1416 / 180;
        float x = rx * cos(angle);
        float y = ry * sin(angle);
        glVertex2f((x + cx), (y + cy));
    }
    glEnd();
}

void tree2()
{




// Tree trunk (shifted left by 100)
glColor3ub(139, 69, 19);
glBegin(GL_POLYGON);
glVertex2d(850, 400); // Original 950 -> 850
glVertex2d(870, 400); // Original 970 -> 870
glVertex2d(870, 550); // Original 970 -> 870
glVertex2d(850, 550); // Original 950 -> 850
glEnd();

// Tree leaves (shifted left by 100)
glColor3ub(0, 128, 0);
tree_2(30, 40, 835, 570); // Original 935 -> 835

glColor3ub(0, 128, 0);
tree_2(30, 40, 885, 570); // Original 985 -> 885

glColor3ub(0, 128, 0);
tree_2(25, 30, 845, 620); // Original 945 -> 845

glColor3ub(0, 128, 0);
tree_2(30, 30, 870, 620); // Original 970 -> 870

glColor3ub(0, 128, 0);
tree_2(25, 30, 855, 650); // Original 955 -> 855






}

void house1()
{

// 2nd House (moved 350 units upward and 200 units to the right, adjusted by -220 x and -320 y, then scaled by 20%)
glColor3ub(210, 105, 30);
glBegin(GL_POLYGON);
glVertex2d((100 + 150 + 20 + 250 - 220) * 1.2, (220 + 300 + 20 + 150 - 320) * 1.2);  // Scaled by 20%
glVertex2d((200 + 150 + 20 + 250 - 220) * 1.2, (220 + 300 + 20 + 150 - 320) * 1.2);  // Scaled by 20%
glVertex2d((175 + 150 + 20 + 250 - 220) * 1.2, (270 + 300 + 20 + 150 - 320) * 1.2);  // Scaled by 20%
glVertex2d((130 + 150 + 20 + 250 - 220) * 1.2, (270 + 300 + 20 + 150 - 320) * 1.2);  // Scaled by 20%
glEnd();

glColor3ub(244, 164, 96);
glBegin(GL_POLYGON);
glVertex2d((100 + 150 + 20 + 250 - 220) * 1.2, (170 + 300 + 20 + 150 - 320) * 1.2);  // Scaled by 20%
glVertex2d((185 + 150 + 20 + 250 - 220) * 1.2, (170 + 300 + 20 + 150 - 320) * 1.2);  // Scaled by 20%
glVertex2d((185 + 150 + 20 + 250 - 220) * 1.2, (220 + 300 + 20 + 150 - 320) * 1.2);  // Scaled by 20%
glVertex2d((100 + 150 + 20 + 250 - 220) * 1.2, (220 + 300 + 20 + 150 - 320) * 1.2);  // Scaled by 20%
glEnd();

glColor3ub(160, 82, 45);
glBegin(GL_POLYGON);
glVertex2d((100 + 150 + 20 + 250 - 220) * 1.2, (170 + 300 + 20 + 150 - 320) * 1.2);  // Scaled by 20%
glVertex2d((190 + 150 + 20 + 250 - 220) * 1.2, (170 + 300 + 20 + 150 - 320) * 1.2);  // Scaled by 20%
glVertex2d((190 + 150 + 20 + 250 - 220) * 1.2, (160 + 300 + 20 + 150 - 320) * 1.2);  // Scaled by 20%
glVertex2d((100 + 150 + 20 + 250 - 220) * 1.2, (160 + 300 + 20 + 150 - 320) * 1.2);  // Scaled by 20%
glEnd();

// 2nd house door and window
glColor3ub(160, 82, 45);
glBegin(GL_POLYGON);
glVertex2d((140 + 150 + 20 + 250 - 220) * 1.2, (170 + 300 + 20 + 150 - 320) * 1.2);  // Scaled by 20%
glVertex2d((165 + 150 + 20 + 250 - 220) * 1.2, (170 + 300 + 20 + 150 - 320) * 1.2);  // Scaled by 20%
glVertex2d((165 + 150 + 20 + 250 - 220) * 1.2, (200 + 300 + 20 + 150 - 320) * 1.2);  // Scaled by 20%
glVertex2d((140 + 150 + 20 + 250 - 220) * 1.2, (200 + 300 + 20 + 150 - 320) * 1.2);  // Scaled by 20%
glEnd();

// 1st House (moved 350 units upward and 200 units to the right, adjusted by -220 x and -320 y, then scaled by 20%)
glColor3ub(160, 82, 45);
glBegin(GL_POLYGON);
glVertex2d((0 + 150 + 20 + 250 - 220) * 1.2, (220 + 300 + 20 + 150 - 320) * 1.2);  // Scaled by 20%
glVertex2d((135 + 150 + 20 + 250 - 220) * 1.2, (220 + 300 + 20 + 150 - 320) * 1.2);  // Scaled by 20%
glVertex2d((110 + 150 + 20 + 250 - 220) * 1.2, (270 + 300 + 20 + 150 - 320) * 1.2);  // Scaled by 20%
glVertex2d((25 + 150 + 20 + 250 - 220) * 1.2, (270 + 300 + 20 + 150 - 320) * 1.2);  // Scaled by 20%
glEnd();

glColor3ub(255, 222, 173);
glBegin(GL_POLYGON);
glVertex2d((10 + 150 + 20 + 250 - 220) * 1.2, (220 + 300 + 20 + 150 - 320) * 1.2);  // Scaled by 20%
glVertex2d((50 + 150 + 20 + 250 - 220) * 1.2, (220 + 300 + 20 + 150 - 320) * 1.2);  // Scaled by 20%
glVertex2d((25 + 150 + 20 + 250 - 220) * 1.2, (255 + 300 + 20 + 150 - 320) * 1.2);  // Scaled by 20%
glEnd();

glColor3ub(255, 222, 173);
glBegin(GL_POLYGON);
glVertex2d((10 + 150 + 20 + 250 - 220) * 1.2, (150 + 300 + 20 + 150 - 320) * 1.2);  // Scaled by 20%
glVertex2d((50 + 150 + 20 + 250 - 220) * 1.2, (150 + 300 + 20 + 150 - 320) * 1.2);  // Scaled by 20%
glVertex2d((50 + 150 + 20 + 250 - 220) * 1.2, (220 + 300 + 20 + 150 - 320) * 1.2);  // Scaled by 20%
glVertex2d((10 + 150 + 20 + 250 - 220) * 1.2, (220 + 300 + 20 + 150 - 320) * 1.2);  // Scaled by 20%
glEnd();

glColor3ub(222, 184, 135);
glBegin(GL_POLYGON);
glVertex2d((50 + 150 + 20 + 250 - 220) * 1.2, (150 + 300 + 20 + 150 - 320) * 1.2);  // Scaled by 20%
glVertex2d((125 + 150 + 20 + 250 - 220) * 1.2, (150 + 300 + 20 + 150 - 320) * 1.2);  // Scaled by 20%
glVertex2d((125 + 150 + 20 + 250 - 220) * 1.2, (220 + 300 + 20 + 150 - 320) * 1.2);  // Scaled by 20%
glVertex2d((50 + 150 + 20 + 250 - 220) * 1.2, (220 + 300 + 20 + 150 - 320) * 1.2);  // Scaled by 20%
glEnd();

glColor3ub(160, 82, 45);
glBegin(GL_POLYGON);
glVertex2d((10 + 150 + 20 + 250 - 220) * 1.2, (150 + 300 + 20 + 150 - 320) * 1.2);  // Scaled by 20%
glVertex2d((125 + 150 + 20 + 250 - 220) * 1.2, (150 + 300 + 20 + 150 - 320) * 1.2);  // Scaled by 20%
glVertex2d((125 + 150 + 20 + 250 - 220) * 1.2, (140 + 300 + 20 + 150 - 320) * 1.2);  // Scaled by 20%
glVertex2d((10 + 150 + 20 + 250 - 220) * 1.2, (140 + 300 + 20 + 150 - 320) * 1.2);  // Scaled by 20%
glEnd();

// 1st house door and window
glColor3ub(160, 82, 45);
glBegin(GL_POLYGON);
glVertex2d((75 + 150 + 20 + 250 - 220) * 1.2, (150 + 300 + 20 + 150 - 320) * 1.2);  // Scaled by 20%
glVertex2d((95 + 150 + 20 + 250 - 220) * 1.2, (150 + 300 + 20 + 150 - 320) * 1.2);  // Scaled by 20%
glVertex2d((95 + 150 + 20 + 250 - 220) * 1.2, (195 + 300 + 20 + 150 - 320) * 1.2);  // Scaled by 20%
glVertex2d((75 + 150 + 20 + 250 - 220) * 1.2, (195 + 300 + 20 + 150 - 320) * 1.2);  // Scaled by 20%
glEnd();

glColor3ub(160, 82, 45);
glBegin(GL_POLYGON);
glVertex2d((20 + 150 + 20 + 250 - 220) * 1.2, (200 + 300 + 20 + 150 - 320) * 1.2);  // Scaled by 20%
glVertex2d((35 + 150 + 20 + 250 - 220) * 1.2, (200 + 300 + 20 + 150 - 320) * 1.2);  // Scaled by 20%
glVertex2d((35 + 150 + 20 + 250 - 220) * 1.2, (175 + 300 + 20 + 150 - 320) * 1.2);  // Scaled by 20%
glVertex2d((20 + 150 + 20 + 250 - 220) * 1.2, (175 + 300 + 20 + 150 - 320) * 1.2);  // Scaled by 20%
glEnd();

}

void hut()
{

    // First Polygon
glBegin(GL_POLYGON);
glColor3ub(204, 153, 0);
glVertex2f((((-0.5f + 1) * 500) * 0.7 + 200) - 100, (((0.2f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.1f + 1) * 500) * 0.7 + 200) - 100, (((0.2f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.18f + 1) * 500) * 0.7 + 200) - 100, (((0.5f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.58f + 1) * 500) * 0.7 + 200) - 100, (((0.5f + 1) * 500) * 0.7 + 200) - 25);
glEnd();

// Second Polygon
glBegin(GL_POLYGON);
glColor3ub(204, 153, 0);
glVertex2f((((-0.49f + 1) * 500) * 0.7 + 200) - 100, (((0.2f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.13f + 1) * 500) * 0.7 + 200) - 100, (((0.2f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.13f + 1) * 500) * 0.7 + 200) - 100, (((-0.2f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.49f + 1) * 500) * 0.7 + 200) - 100, (((-0.2f + 1) * 500) * 0.7 + 200) - 25);
glEnd();

// Third Polygon
glBegin(GL_POLYGON);
glColor3ub(204, 153, 0);
glVertex2f((((-0.58f + 1) * 500) * 0.7 + 200) - 100, (((0.5f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.63f + 1) * 500) * 0.7 + 200) - 100, (((0.2f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.61f + 1) * 500) * 0.7 + 200) - 100, (((0.2f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.61f + 1) * 500) * 0.7 + 200) - 100, (((-0.15f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.49f + 1) * 500) * 0.7 + 200) - 100, (((-0.2f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.17f + 1) * 500) * 0.7 + 200) - 100, (((-0.2f + 1) * 500) * 0.7 + 200) - 25);
glEnd();

// Lines
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(0,0,0);
glVertex2f((((-0.5f + 1) * 500) * 0.7 + 200) - 100, (((0.2f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.1f + 1) * 500) * 0.7 + 200) - 100, (((0.2f + 1) * 500) * 0.7 + 200) - 25);

glColor3ub(0,0,0);
glVertex2f((((-0.49f + 1) * 500) * 0.7 + 200) - 100, (((0.2f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.49f + 1) * 500) * 0.7 + 200) - 100, (((-0.2f + 1) * 500) * 0.7 + 200) - 25);

glColor3ub(0,0,0);
glVertex2f((((-0.13f + 1) * 500) * 0.7 + 200) - 100, (((-0.2f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.49f + 1) * 500) * 0.7 + 200) - 100, (((-0.2f + 1) * 500) * 0.7 + 200) - 25);

glColor3ub(0,0,0);
glVertex2f((((-0.13f + 1) * 500) * 0.7 + 200) - 100, (((-0.2f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.13f + 1) * 500) * 0.7 + 200) - 100, (((0.2f + 1) * 500) * 0.7 + 200) - 25);

glColor3ub(0,0,0);
glVertex2f((((-0.5f + 1) * 500) * 0.7 + 200) - 100, (((0.2f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.58f + 1) * 500) * 0.7 + 200) - 100, (((0.5f + 1) * 500) * 0.7 + 200) - 25);

glColor3ub(0,0,0);
glVertex2f((((-0.58f + 1) * 500) * 0.7 + 200) - 100, (((0.5f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.63f + 1) * 500) * 0.7 + 200) - 100, (((0.2f + 1) * 500) * 0.7 + 200) - 25);

glColor3ub(0,0,0);
glVertex2f((((-0.57f + 1) * 500) * 0.7 + 200) - 100, (((0.445f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.61f + 1) * 500) * 0.7 + 200) - 100, (((0.2f + 1) * 500) * 0.7 + 200) - 25);

glColor3ub(0,0,0);
glVertex2f((((-0.61f + 1) * 500) * 0.7 + 200) - 100, (((0.2f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.61f + 1) * 500) * 0.7 + 200) - 100, (((-0.15f + 1) * 500) * 0.7 + 200) - 25);

glColor3ub(0,0,0);
glVertex2f((((-0.61f + 1) * 500) * 0.7 + 200) - 100, (((-0.15f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.49f + 1) * 500) * 0.7 + 200) - 100, (((-0.2f + 1) * 500) * 0.7 + 200) - 25);

glColor3ub(0,0,0);
glVertex2f((((-0.1f + 1) * 500) * 0.7 + 200) - 100, (((0.2f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.18f + 1) * 500) * 0.7 + 200) - 100, (((0.5f + 1) * 500) * 0.7 + 200) - 25);

glColor3ub(0,0,0);
glVertex2f((((-0.18f + 1) * 500) * 0.7 + 200) - 100, (((0.5f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.58f + 1) * 500) * 0.7 + 200) - 100, (((0.5f + 1) * 500) * 0.7 + 200) - 25);
glEnd();

// Main Door
glBegin(GL_POLYGON);
glColor3ub(153, 115, 0);
glVertex2f((((-0.35f + 1) * 500) * 0.7 + 200) - 100, (((0.1f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.22f + 1) * 500) * 0.7 + 200) - 100, (((0.1f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.22f + 1) * 500) * 0.7 + 200) - 100, (((-0.2f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.35f + 1) * 500) * 0.7 + 200) - 100, (((-0.2f + 1) * 500) * 0.7 + 200) - 25);
glEnd();

// Door Lines
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(0,0,0);
glVertex2f((((-0.35f + 1) * 500) * 0.7 + 200) - 100, (((0.1f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.22f + 1) * 500) * 0.7 + 200) - 100, (((0.1f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.22f + 1) * 500) * 0.7 + 200) - 100, (((0.1f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.22f + 1) * 500) * 0.7 + 200) - 100, (((-0.2f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.35f + 1) * 500) * 0.7 + 200) - 100, (((0.1f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.35f + 1) * 500) * 0.7 + 200) - 100, (((-0.2f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.29f + 1) * 500) * 0.7 + 200) - 100, (((-0.2f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.29f + 1) * 500) * 0.7 + 200) - 100, (((0.1f + 1) * 500) * 0.7 + 200) - 25);
glEnd();
// Left Window
glBegin(GL_POLYGON);
glColor3ub(153, 115, 0);
glVertex2f(((-0.44f + 1) * 500) * 0.7 + 200 - 100, (((0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.38f + 1) * 500) * 0.7 + 200 - 100, (((0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.38f + 1) * 500) * 0.7 + 200 - 100, (((-0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.44f + 1) * 500) * 0.7 + 200 - 100, (((-0.05f + 1) * 500) * 0.7 + 200) - 25);
glEnd();

// Window Lines
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(0,0,0);
glVertex2f(((-0.44f + 1) * 500) * 0.7 + 200 - 100, (((0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.44f + 1) * 500) * 0.7 + 200 - 100, (((-0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.38f + 1) * 500) * 0.7 + 200 - 100, (((0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.38f + 1) * 500) * 0.7 + 200 - 100, (((-0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.44f + 1) * 500) * 0.7 + 200 - 100, (((0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.38f + 1) * 500) * 0.7 + 200 - 100, (((0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.44f + 1) * 500) * 0.7 + 200 - 100, (((-0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.38f + 1) * 500) * 0.7 + 200 - 100, (((-0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.41f + 1) * 500) * 0.7 + 200 - 100, (((0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.41f + 1) * 500) * 0.7 + 200 - 100, (((-0.05f + 1) * 500) * 0.7 + 200) - 25);
glEnd();

// Second Door
glBegin(GL_POLYGON);
glColor3ub(153, 115, 0);
glVertex2f(((-0.51f + 1) * 500) * 0.7 + 200 - 100, (((0.12f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.58f + 1) * 500) * 0.7 + 200 - 100, (((0.14f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.58f + 1) * 500) * 0.7 + 200 - 100, (((-0.17f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.51f + 1) * 500) * 0.7 + 200 - 100, (((-0.2f + 1) * 500) * 0.7 + 200) - 25);
glEnd();

// Second Door Lines
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(0,0,0);
glVertex2f(((-0.58f + 1) * 500) * 0.7 + 200 - 100, (((0.14f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.58f + 1) * 500) * 0.7 + 200 - 100, (((-0.17f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.51f + 1) * 500) * 0.7 + 200 - 100, (((0.12f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.51f + 1) * 500) * 0.7 + 200 - 100, (((-0.2f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.58f + 1) * 500) * 0.7 + 200 - 100, (((0.14f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.51f + 1) * 500) * 0.7 + 200 - 100, (((0.12f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.545f + 1) * 500) * 0.7 + 200 - 100, (((0.13f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.545f + 1) * 500) * 0.7 + 200 - 100, (((-0.185f + 1) * 500) * 0.7 + 200) - 25);
glEnd();

// Right Window
glBegin(GL_POLYGON);
glColor3ub(153, 115, 0);
glVertex2f(((-0.14f + 1) * 500) * 0.7 + 200 - 100, (((0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.2f + 1) * 500) * 0.7 + 200 - 100, (((0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.2f + 1) * 500) * 0.7 + 200 - 100, (((-0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.14f + 1) * 500) * 0.7 + 200 - 100, (((-0.05f + 1) * 500) * 0.7 + 200) - 25);
glEnd();

// Window Lines
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(0,0,0);
glVertex2f(((-0.14f + 1) * 500) * 0.7 + 200 - 100, (((0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.14f + 1) * 500) * 0.7 + 200 - 100, (((-0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.2f + 1) * 500) * 0.7 + 200 - 100, (((0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.2f + 1) * 500) * 0.7 + 200 - 100, (((-0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.14f + 1) * 500) * 0.7 + 200 - 100, (((0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.2f + 1) * 500) * 0.7 + 200 - 100, (((0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.14f + 1) * 500) * 0.7 + 200 - 100, (((-0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.2f + 1) * 500) * 0.7 + 200 - 100, (((-0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.17f + 1) * 500) * 0.7 + 200 - 100, (((0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.17f + 1) * 500) * 0.7 + 200 - 100, (((-0.05f + 1) * 500) * 0.7 + 200) - 25);
glEnd();

}

















///////////////////////////////////////////////////////////////
void hut2()
{
float scale = 0.7f; // Scaling factor to reduce size by 30%

// First polygon
glBegin(GL_POLYGON);
glColor3ub(204, 153, 0);
glVertex2f((0.6f + 1) * 500 * scale + 200, (0.1f + 1) * 500 * scale + 200);
glVertex2f((0.2f + 1) * 500 * scale + 200, (0.1f + 1) * 500 * scale + 200);
glVertex2f((0.28f + 1) * 500 * scale + 200, (0.4f + 1) * 500 * scale + 200);
glVertex2f((0.68f + 1) * 500 * scale + 200, (0.4f + 1) * 500 * scale + 200);
glEnd();

// Second polygon
glBegin(GL_POLYGON);
glColor3ub(204, 153, 0);
glVertex2f((0.59f + 1) * 500 * scale + 200, (0.1f + 1) * 500 * scale + 200);
glVertex2f((0.23f + 1) * 500 * scale + 200, (0.1f + 1) * 500 * scale + 200);
glVertex2f((0.23f + 1) * 500 * scale + 200, (-0.3f + 1) * 500 * scale + 200);
glVertex2f((0.59f + 1) * 500 * scale + 200, (-0.3f + 1) * 500 * scale + 200);
glEnd();

// Third polygon
glBegin(GL_POLYGON);
glColor3ub(204, 153, 0);
glVertex2f((0.68f + 1) * 500 * scale + 200, (0.4f + 1) * 500 * scale + 200);
glVertex2f((0.73f + 1) * 500 * scale + 200, (0.1f + 1) * 500 * scale + 200);
glVertex2f((0.71f + 1) * 500 * scale + 200, (0.1f + 1) * 500 * scale + 200);
glVertex2f((0.71f + 1) * 500 * scale + 200, (-0.30f + 1) * 500 * scale + 200);
glVertex2f((0.71f + 1) * 500 * scale + 200, (-0.3f + 1) * 500 * scale + 200);
glVertex2f((0.27f + 1) * 500 * scale + 200, (-0.3f + 1) * 500 * scale + 200);
glEnd();

// Lines
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(0, 0, 0);
glVertex2f((0.6f + 1) * 500 * scale + 200, (0.1f + 1) * 500 * scale + 200);
glVertex2f((0.2f + 1) * 500 * scale + 200, (0.1f + 1) * 500 * scale + 200);

glColor3ub(0, 0, 0);
glVertex2f((0.59f + 1) * 500 * scale + 200, (0.1f + 1) * 500 * scale + 200);
glVertex2f((0.59f + 1) * 500 * scale + 200, (-0.2f + 1) * 500 * scale + 200);

glColor3ub(0, 0, 0);
glVertex2f((0.23f + 1) * 500 * scale + 200, (-0.3f + 1) * 500 * scale + 200);
glVertex2f((0.59f + 1) * 500 * scale + 200, (-0.3f + 1) * 500 * scale + 200);

glColor3ub(0, 0, 0);
glVertex2f((0.23f + 1) * 500 * scale + 200, (-0.3f + 1) * 500 * scale + 200);
glVertex2f((0.23f + 1) * 500 * scale + 200, (0.1f + 1) * 500 * scale + 200);

glColor3ub(0, 0, 0);
glVertex2f((0.6f + 1) * 500 * scale + 200, (0.1f + 1) * 500 * scale + 200);
glVertex2f((0.68f + 1) * 500 * scale + 200, (0.4f + 1) * 500 * scale + 200);

glColor3ub(0, 0, 0);
glVertex2f((0.68f + 1) * 500 * scale + 200, (0.4f + 1) * 500 * scale + 200);
glVertex2f((0.73f + 1) * 500 * scale + 200, (0.1f + 1) * 500 * scale + 200);

glColor3ub(0, 0, 0);
glVertex2f((0.67f + 1) * 500 * scale + 200, (0.345f + 1) * 500 * scale + 200);
glVertex2f((0.71f + 1) * 500 * scale + 200, (0.1f + 1) * 500 * scale + 200);

glColor3ub(0, 0, 0);
glVertex2f((0.71f + 1) * 500 * scale + 200, (0.1f + 1) * 500 * scale + 200);
glVertex2f((0.71f + 1) * 500 * scale + 200, (-0.25f + 1) * 500 * scale + 200);

glColor3ub(0, 0, 0);
glVertex2f((0.71f + 1) * 500 * scale + 200, (-0.25f + 1) * 500 * scale + 200);
glVertex2f((0.59f + 1) * 500 * scale + 200, (-0.3f + 1) * 500 * scale + 200);

glColor3ub(0, 0, 0);
glVertex2f((0.2f + 1) * 500 * scale + 200, (0.1f + 1) * 500 * scale + 200);
glVertex2f((0.28f + 1) * 500 * scale + 200, (0.4f + 1) * 500 * scale + 200);

glColor3ub(0, 0, 0);
glVertex2f((0.28f + 1) * 500 * scale + 200, (0.4f + 1) * 500 * scale + 200);
glVertex2f((0.68f + 1) * 500 * scale + 200, (0.4f + 1) * 500 * scale + 200);
glEnd();

// Door
glBegin(GL_POLYGON);
glColor3ub(153, 115, 0);
glVertex2f((0.45f + 1) * 500 * scale + 200, (0.0f + 1) * 500 * scale + 200);
glVertex2f((0.32f + 1) * 500 * scale + 200, (0.0f + 1) * 500 * scale + 200);
glVertex2f((0.32f + 1) * 500 * scale + 200, (-0.3f + 1) * 500 * scale + 200);
glVertex2f((0.45f + 1) * 500 * scale + 200, (-0.3f + 1) * 500 * scale + 200);
glEnd();

// Door lines
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(0, 0, 0);
glVertex2f((0.45f + 1) * 500 * scale + 200, (0.0f + 1) * 500 * scale + 200);
glVertex2f((0.32f + 1) * 500 * scale + 200, (0.0f + 1) * 500 * scale + 200);
glVertex2f((0.32f + 1) * 500 * scale + 200, (0.0f + 1) * 500 * scale + 200);
glVertex2f((0.32f + 1) * 500 * scale + 200, (-0.3f + 1) * 500 * scale + 200);
glVertex2f((0.45f + 1) * 500 * scale + 200, (0.0f + 1) * 500 * scale + 200);
glVertex2f((0.45f + 1) * 500 * scale + 200, (-0.3f + 1) * 500 * scale + 200);
glVertex2f((0.385f + 1) * 500 * scale + 200, (0.0f + 1) * 500 * scale + 200);
glVertex2f((0.385f + 1) * 500 * scale + 200, (-0.3f + 1) * 500 * scale + 200);
glEnd();

// Left window
glBegin(GL_POLYGON);
glColor3ub(153, 115, 0);
glVertex2f((0.54f + 1) * 500 * scale + 200, (-0.05f + 1) * 500 * scale + 200);
glVertex2f((0.48f + 1) * 500 * scale + 200, (-0.05f + 1) * 500 * scale + 200);
glVertex2f((0.48f + 1) * 500 * scale + 200, (-0.15f + 1) * 500 * scale + 200);
glVertex2f((0.54f + 1) * 500 * scale + 200, (-0.15f + 1) * 500 * scale + 200);
glEnd();

// Left window lines
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(0, 0, 0);
glVertex2f((0.54f + 1) * 500 * scale + 200, (-0.05f + 1) * 500 * scale + 200);
glVertex2f((0.54f + 1) * 500 * scale + 200, (-0.15f + 1) * 500 * scale + 200);
glVertex2f((0.48f + 1) * 500 * scale + 200, (-0.05f + 1) * 500 * scale + 200);
glVertex2f((0.48f + 1) * 500 * scale + 200, (-0.15f + 1) * 500 * scale + 200);
glVertex2f((0.54f + 1) * 500 * scale + 200, (-0.05f + 1) * 500 * scale + 200);
glVertex2f((0.48f + 1) * 500 * scale + 200, (-0.05f + 1) * 500 * scale + 200);
glVertex2f((0.54f + 1) * 500 * scale + 200, (-0.15f + 1) * 500 * scale + 200);
glVertex2f((0.48f + 1) * 500 * scale + 200, (-0.15f + 1) * 500 * scale + 200);
glVertex2f((0.51f + 1) * 500 * scale + 200, (-0.05f + 1) * 500 * scale + 200);
glVertex2f((0.51f + 1) * 500 * scale + 200, (-0.15f + 1) * 500 * scale + 200);
glEnd();

// Second door
glBegin(GL_POLYGON);
glColor3ub(153, 115, 0);
glVertex2f((0.61f + 1) * 500 * scale + 200, (0.02f + 1) * 500 * scale + 200);
glVertex2f((0.68f + 1) * 500 * scale + 200, (0.04f + 1) * 500 * scale + 200);
glVertex2f((0.68f + 1) * 500 * scale + 200, (-0.27f + 1) * 500 * scale + 200);
glVertex2f((0.61f + 1) * 500 * scale + 200, (-0.3f + 1) * 500 * scale + 200);
glEnd();

// Second door lines
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(0, 0, 0);
glVertex2f((0.68f + 1) * 500 * scale + 200, (0.04f + 1) * 500 * scale + 200);
glVertex2f((0.68f + 1) * 500 * scale + 200, (-0.27f + 1) * 500 * scale + 200);
glVertex2f((0.61f + 1) * 500 * scale + 200, (0.02f + 1) * 500 * scale + 200);
glVertex2f((0.61f + 1) * 500 * scale + 200, (-0.3f + 1) * 500 * scale + 200);
glVertex2f((0.68f + 1) * 500 * scale + 200, (0.04f + 1) * 500 * scale + 200);
glVertex2f((0.61f + 1) * 500 * scale + 200, (0.02f + 1) * 500 * scale + 200);
glVertex2f((0.645f + 1) * 500 * scale + 200, (0.03f + 1) * 500 * scale + 200);
glVertex2f((0.645f + 1) * 500 * scale + 200, (-0.29f + 1) * 500 * scale + 200);
glVertex2f((0.68f + 1) * 500 * scale + 200, (-0.27f + 1) * 500 * scale + 200);
glVertex2f((0.645f + 1) * 500 * scale + 200, (-0.29f + 1) * 500 * scale + 200);
glEnd();


// Right window
glBegin(GL_POLYGON);
glColor3ub(153, 115, 0);
glVertex2f((0.24f + 1) * 500 * scale + 200, (-0.05f + 1) * 500 * scale + 200);
glVertex2f((0.3f + 1) * 500 * scale + 200, (-0.05f + 1) * 500 * scale + 200);
glVertex2f((0.3f + 1) * 500 * scale + 200, (-0.15f + 1) * 500 * scale + 200);
glVertex2f((0.24f + 1) * 500 * scale + 200, (-0.15f + 1) * 500 * scale + 200);
glEnd();

glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(0, 0, 0);
glVertex2f((0.24f + 1) * 500 * scale + 200, (-0.05f + 1) * 500 * scale + 200);
glVertex2f((0.24f + 1) * 500 * scale + 200, (-0.15f + 1) * 500 * scale + 200);
glVertex2f((0.3f + 1) * 500 * scale + 200, (-0.05f + 1) * 500 * scale + 200);
glVertex2f((0.3f + 1) * 500 * scale + 200, (-0.15f + 1) * 500 * scale + 200);
glVertex2f((0.24f + 1) * 500 * scale + 200, (-0.05f + 1) * 500 * scale + 200);
glVertex2f((0.3f + 1) * 500 * scale + 200, (-0.05f + 1) * 500 * scale + 200);
glVertex2f((0.24f + 1) * 500 * scale + 200, (-0.15f + 1) * 500 * scale + 200);
glVertex2f((0.3f + 1) * 500 * scale + 200, (-0.15f + 1) * 500 * scale + 200);
glVertex2f((0.27f + 1) * 500 * scale + 200, (-0.05f + 1) * 500 * scale + 200);
glVertex2f((0.27f + 1) * 500 * scale + 200, (-0.15f + 1) * 500 * scale + 200);
glEnd();



}
//




void hutN()
{

    // First Polygon
glBegin(GL_POLYGON);
glColor3ub(60, 45, 0); // Deep Yellow-Orange Shadow
glVertex2f((((-0.5f + 1) * 500) * 0.7 + 200) - 100, (((0.2f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.1f + 1) * 500) * 0.7 + 200) - 100, (((0.2f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.18f + 1) * 500) * 0.7 + 200) - 100, (((0.5f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.58f + 1) * 500) * 0.7 + 200) - 100, (((0.5f + 1) * 500) * 0.7 + 200) - 25);
glEnd();

// Second Polygon
glBegin(GL_POLYGON);
glColor3ub(60, 45, 0); // Deep Yellow-Orange Shadow
glVertex2f((((-0.49f + 1) * 500) * 0.7 + 200) - 100, (((0.2f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.13f + 1) * 500) * 0.7 + 200) - 100, (((0.2f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.13f + 1) * 500) * 0.7 + 200) - 100, (((-0.2f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.49f + 1) * 500) * 0.7 + 200) - 100, (((-0.2f + 1) * 500) * 0.7 + 200) - 25);
glEnd();

// Third Polygon
glBegin(GL_POLYGON);
glColor3ub(60, 45, 0); // Deep Yellow-Orange Shadow
glVertex2f((((-0.58f + 1) * 500) * 0.7 + 200) - 100, (((0.5f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.63f + 1) * 500) * 0.7 + 200) - 100, (((0.2f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.61f + 1) * 500) * 0.7 + 200) - 100, (((0.2f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.61f + 1) * 500) * 0.7 + 200) - 100, (((-0.15f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.49f + 1) * 500) * 0.7 + 200) - 100, (((-0.2f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.17f + 1) * 500) * 0.7 + 200) - 100, (((-0.2f + 1) * 500) * 0.7 + 200) - 25);
glEnd();

// Lines
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(0,0,0);
glVertex2f((((-0.5f + 1) * 500) * 0.7 + 200) - 100, (((0.2f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.1f + 1) * 500) * 0.7 + 200) - 100, (((0.2f + 1) * 500) * 0.7 + 200) - 25);

glColor3ub(0,0,0);
glVertex2f((((-0.49f + 1) * 500) * 0.7 + 200) - 100, (((0.2f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.49f + 1) * 500) * 0.7 + 200) - 100, (((-0.2f + 1) * 500) * 0.7 + 200) - 25);

glColor3ub(0,0,0);
glVertex2f((((-0.13f + 1) * 500) * 0.7 + 200) - 100, (((-0.2f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.49f + 1) * 500) * 0.7 + 200) - 100, (((-0.2f + 1) * 500) * 0.7 + 200) - 25);

glColor3ub(0,0,0);
glVertex2f((((-0.13f + 1) * 500) * 0.7 + 200) - 100, (((-0.2f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.13f + 1) * 500) * 0.7 + 200) - 100, (((0.2f + 1) * 500) * 0.7 + 200) - 25);

glColor3ub(0,0,0);
glVertex2f((((-0.5f + 1) * 500) * 0.7 + 200) - 100, (((0.2f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.58f + 1) * 500) * 0.7 + 200) - 100, (((0.5f + 1) * 500) * 0.7 + 200) - 25);

glColor3ub(0,0,0);
glVertex2f((((-0.58f + 1) * 500) * 0.7 + 200) - 100, (((0.5f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.63f + 1) * 500) * 0.7 + 200) - 100, (((0.2f + 1) * 500) * 0.7 + 200) - 25);

glColor3ub(0,0,0);
glVertex2f((((-0.57f + 1) * 500) * 0.7 + 200) - 100, (((0.445f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.61f + 1) * 500) * 0.7 + 200) - 100, (((0.2f + 1) * 500) * 0.7 + 200) - 25);

glColor3ub(0,0,0);
glVertex2f((((-0.61f + 1) * 500) * 0.7 + 200) - 100, (((0.2f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.61f + 1) * 500) * 0.7 + 200) - 100, (((-0.15f + 1) * 500) * 0.7 + 200) - 25);

glColor3ub(0,0,0);
glVertex2f((((-0.61f + 1) * 500) * 0.7 + 200) - 100, (((-0.15f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.49f + 1) * 500) * 0.7 + 200) - 100, (((-0.2f + 1) * 500) * 0.7 + 200) - 25);

glColor3ub(0,0,0);
glVertex2f((((-0.1f + 1) * 500) * 0.7 + 200) - 100, (((0.2f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.18f + 1) * 500) * 0.7 + 200) - 100, (((0.5f + 1) * 500) * 0.7 + 200) - 25);

glColor3ub(0,0,0);
glVertex2f((((-0.18f + 1) * 500) * 0.7 + 200) - 100, (((0.5f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.58f + 1) * 500) * 0.7 + 200) - 100, (((0.5f + 1) * 500) * 0.7 + 200) - 25);
glEnd();

// Main Door
glBegin(GL_POLYGON);
glColor3ub(45, 33, 0); // Deep Yellow-Orange Shadow
glVertex2f((((-0.35f + 1) * 500) * 0.7 + 200) - 100, (((0.1f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.22f + 1) * 500) * 0.7 + 200) - 100, (((0.1f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.22f + 1) * 500) * 0.7 + 200) - 100, (((-0.2f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.35f + 1) * 500) * 0.7 + 200) - 100, (((-0.2f + 1) * 500) * 0.7 + 200) - 25);
glEnd();

// Door Lines
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(0,0,0);
glVertex2f((((-0.35f + 1) * 500) * 0.7 + 200) - 100, (((0.1f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.22f + 1) * 500) * 0.7 + 200) - 100, (((0.1f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.22f + 1) * 500) * 0.7 + 200) - 100, (((0.1f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.22f + 1) * 500) * 0.7 + 200) - 100, (((-0.2f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.35f + 1) * 500) * 0.7 + 200) - 100, (((0.1f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.35f + 1) * 500) * 0.7 + 200) - 100, (((-0.2f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.29f + 1) * 500) * 0.7 + 200) - 100, (((-0.2f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f((((-0.29f + 1) * 500) * 0.7 + 200) - 100, (((0.1f + 1) * 500) * 0.7 + 200) - 25);
glEnd();
// Left Window
glBegin(GL_POLYGON);
glColor3ub(190, 140, 0);
glVertex2f(((-0.44f + 1) * 500) * 0.7 + 200 - 100, (((0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.38f + 1) * 500) * 0.7 + 200 - 100, (((0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.38f + 1) * 500) * 0.7 + 200 - 100, (((-0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.44f + 1) * 500) * 0.7 + 200 - 100, (((-0.05f + 1) * 500) * 0.7 + 200) - 25);
glEnd();

// Window Lines
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(0,0,0);
glVertex2f(((-0.44f + 1) * 500) * 0.7 + 200 - 100, (((0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.44f + 1) * 500) * 0.7 + 200 - 100, (((-0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.38f + 1) * 500) * 0.7 + 200 - 100, (((0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.38f + 1) * 500) * 0.7 + 200 - 100, (((-0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.44f + 1) * 500) * 0.7 + 200 - 100, (((0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.38f + 1) * 500) * 0.7 + 200 - 100, (((0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.44f + 1) * 500) * 0.7 + 200 - 100, (((-0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.38f + 1) * 500) * 0.7 + 200 - 100, (((-0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.41f + 1) * 500) * 0.7 + 200 - 100, (((0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.41f + 1) * 500) * 0.7 + 200 - 100, (((-0.05f + 1) * 500) * 0.7 + 200) - 25);
glEnd();

// Second Door
glBegin(GL_POLYGON);
glColor3ub(45, 33, 0); // Deep Yellow-Orange Shadow
glVertex2f(((-0.51f + 1) * 500) * 0.7 + 200 - 100, (((0.12f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.58f + 1) * 500) * 0.7 + 200 - 100, (((0.14f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.58f + 1) * 500) * 0.7 + 200 - 100, (((-0.17f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.51f + 1) * 500) * 0.7 + 200 - 100, (((-0.2f + 1) * 500) * 0.7 + 200) - 25);
glEnd();

// Second Door Lines
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(0,0,0);
glVertex2f(((-0.58f + 1) * 500) * 0.7 + 200 - 100, (((0.14f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.58f + 1) * 500) * 0.7 + 200 - 100, (((-0.17f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.51f + 1) * 500) * 0.7 + 200 - 100, (((0.12f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.51f + 1) * 500) * 0.7 + 200 - 100, (((-0.2f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.58f + 1) * 500) * 0.7 + 200 - 100, (((0.14f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.51f + 1) * 500) * 0.7 + 200 - 100, (((0.12f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.545f + 1) * 500) * 0.7 + 200 - 100, (((0.13f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.545f + 1) * 500) * 0.7 + 200 - 100, (((-0.185f + 1) * 500) * 0.7 + 200) - 25);
glEnd();

// Right Window
glBegin(GL_POLYGON);
glColor3ub(190, 140, 0);
glVertex2f(((-0.14f + 1) * 500) * 0.7 + 200 - 100, (((0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.2f + 1) * 500) * 0.7 + 200 - 100, (((0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.2f + 1) * 500) * 0.7 + 200 - 100, (((-0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.14f + 1) * 500) * 0.7 + 200 - 100, (((-0.05f + 1) * 500) * 0.7 + 200) - 25);
glEnd();

// Window Lines
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(0,0,0);
glVertex2f(((-0.14f + 1) * 500) * 0.7 + 200 - 100, (((0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.14f + 1) * 500) * 0.7 + 200 - 100, (((-0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.2f + 1) * 500) * 0.7 + 200 - 100, (((0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.2f + 1) * 500) * 0.7 + 200 - 100, (((-0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.14f + 1) * 500) * 0.7 + 200 - 100, (((0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.2f + 1) * 500) * 0.7 + 200 - 100, (((0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.14f + 1) * 500) * 0.7 + 200 - 100, (((-0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.2f + 1) * 500) * 0.7 + 200 - 100, (((-0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.17f + 1) * 500) * 0.7 + 200 - 100, (((0.05f + 1) * 500) * 0.7 + 200) - 25);
glVertex2f(((-0.17f + 1) * 500) * 0.7 + 200 - 100, (((-0.05f + 1) * 500) * 0.7 + 200) - 25);
glEnd();

}

void hut2N()
{
float scale = 0.7f; // Scaling factor to reduce size by 30%

// First polygon
glBegin(GL_POLYGON);
glColor3ub(60, 45, 0); // Deep Yellow-Orange Shadow
glVertex2f((0.6f + 1) * 500 * scale + 200, (0.1f + 1) * 500 * scale + 200);
glVertex2f((0.2f + 1) * 500 * scale + 200, (0.1f + 1) * 500 * scale + 200);
glVertex2f((0.28f + 1) * 500 * scale + 200, (0.4f + 1) * 500 * scale + 200);
glVertex2f((0.68f + 1) * 500 * scale + 200, (0.4f + 1) * 500 * scale + 200);
glEnd();

// Second polygon
glBegin(GL_POLYGON);
glColor3ub(60, 45, 0); // Deep Yellow-Orange Shadow
glVertex2f((0.59f + 1) * 500 * scale + 200, (0.1f + 1) * 500 * scale + 200);
glVertex2f((0.23f + 1) * 500 * scale + 200, (0.1f + 1) * 500 * scale + 200);
glVertex2f((0.23f + 1) * 500 * scale + 200, (-0.3f + 1) * 500 * scale + 200);
glVertex2f((0.59f + 1) * 500 * scale + 200, (-0.3f + 1) * 500 * scale + 200);
glEnd();

// Third polygon
glBegin(GL_POLYGON);
glColor3ub(60, 45, 0); // Deep Yellow-Orange Shadow
glVertex2f((0.68f + 1) * 500 * scale + 200, (0.4f + 1) * 500 * scale + 200);
glVertex2f((0.73f + 1) * 500 * scale + 200, (0.1f + 1) * 500 * scale + 200);
glVertex2f((0.71f + 1) * 500 * scale + 200, (0.1f + 1) * 500 * scale + 200);
glVertex2f((0.71f + 1) * 500 * scale + 200, (-0.30f + 1) * 500 * scale + 200);
glVertex2f((0.71f + 1) * 500 * scale + 200, (-0.3f + 1) * 500 * scale + 200);
glVertex2f((0.27f + 1) * 500 * scale + 200, (-0.3f + 1) * 500 * scale + 200);
glEnd();

// Lines
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(0, 0, 0);
glVertex2f((0.6f + 1) * 500 * scale + 200, (0.1f + 1) * 500 * scale + 200);
glVertex2f((0.2f + 1) * 500 * scale + 200, (0.1f + 1) * 500 * scale + 200);

glColor3ub(0, 0, 0);
glVertex2f((0.59f + 1) * 500 * scale + 200, (0.1f + 1) * 500 * scale + 200);
glVertex2f((0.59f + 1) * 500 * scale + 200, (-0.2f + 1) * 500 * scale + 200);

glColor3ub(0, 0, 0);
glVertex2f((0.23f + 1) * 500 * scale + 200, (-0.3f + 1) * 500 * scale + 200);
glVertex2f((0.59f + 1) * 500 * scale + 200, (-0.3f + 1) * 500 * scale + 200);

glColor3ub(0, 0, 0);
glVertex2f((0.23f + 1) * 500 * scale + 200, (-0.3f + 1) * 500 * scale + 200);
glVertex2f((0.23f + 1) * 500 * scale + 200, (0.1f + 1) * 500 * scale + 200);

glColor3ub(0, 0, 0);
glVertex2f((0.6f + 1) * 500 * scale + 200, (0.1f + 1) * 500 * scale + 200);
glVertex2f((0.68f + 1) * 500 * scale + 200, (0.4f + 1) * 500 * scale + 200);

glColor3ub(0, 0, 0);
glVertex2f((0.68f + 1) * 500 * scale + 200, (0.4f + 1) * 500 * scale + 200);
glVertex2f((0.73f + 1) * 500 * scale + 200, (0.1f + 1) * 500 * scale + 200);

glColor3ub(0, 0, 0);
glVertex2f((0.67f + 1) * 500 * scale + 200, (0.345f + 1) * 500 * scale + 200);
glVertex2f((0.71f + 1) * 500 * scale + 200, (0.1f + 1) * 500 * scale + 200);

glColor3ub(0, 0, 0);
glVertex2f((0.71f + 1) * 500 * scale + 200, (0.1f + 1) * 500 * scale + 200);
glVertex2f((0.71f + 1) * 500 * scale + 200, (-0.25f + 1) * 500 * scale + 200);

glColor3ub(0, 0, 0);
glVertex2f((0.71f + 1) * 500 * scale + 200, (-0.25f + 1) * 500 * scale + 200);
glVertex2f((0.59f + 1) * 500 * scale + 200, (-0.3f + 1) * 500 * scale + 200);

glColor3ub(0, 0, 0);
glVertex2f((0.2f + 1) * 500 * scale + 200, (0.1f + 1) * 500 * scale + 200);
glVertex2f((0.28f + 1) * 500 * scale + 200, (0.4f + 1) * 500 * scale + 200);

glColor3ub(0, 0, 0);
glVertex2f((0.28f + 1) * 500 * scale + 200, (0.4f + 1) * 500 * scale + 200);
glVertex2f((0.68f + 1) * 500 * scale + 200, (0.4f + 1) * 500 * scale + 200);
glEnd();

// Door
glBegin(GL_POLYGON);
glColor3ub(45, 33, 0); // Deep Yellow-Orange Shadow
glVertex2f((0.45f + 1) * 500 * scale + 200, (0.0f + 1) * 500 * scale + 200);
glVertex2f((0.32f + 1) * 500 * scale + 200, (0.0f + 1) * 500 * scale + 200);
glVertex2f((0.32f + 1) * 500 * scale + 200, (-0.3f + 1) * 500 * scale + 200);
glVertex2f((0.45f + 1) * 500 * scale + 200, (-0.3f + 1) * 500 * scale + 200);
glEnd();

// Door lines
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(0, 0, 0);
glVertex2f((0.45f + 1) * 500 * scale + 200, (0.0f + 1) * 500 * scale + 200);
glVertex2f((0.32f + 1) * 500 * scale + 200, (0.0f + 1) * 500 * scale + 200);
glVertex2f((0.32f + 1) * 500 * scale + 200, (0.0f + 1) * 500 * scale + 200);
glVertex2f((0.32f + 1) * 500 * scale + 200, (-0.3f + 1) * 500 * scale + 200);
glVertex2f((0.45f + 1) * 500 * scale + 200, (0.0f + 1) * 500 * scale + 200);
glVertex2f((0.45f + 1) * 500 * scale + 200, (-0.3f + 1) * 500 * scale + 200);
glVertex2f((0.385f + 1) * 500 * scale + 200, (0.0f + 1) * 500 * scale + 200);
glVertex2f((0.385f + 1) * 500 * scale + 200, (-0.3f + 1) * 500 * scale + 200);
glEnd();

// Left window
glBegin(GL_POLYGON);
glColor3ub(190, 140, 0);
glVertex2f((0.54f + 1) * 500 * scale + 200, (-0.05f + 1) * 500 * scale + 200);
glVertex2f((0.48f + 1) * 500 * scale + 200, (-0.05f + 1) * 500 * scale + 200);
glVertex2f((0.48f + 1) * 500 * scale + 200, (-0.15f + 1) * 500 * scale + 200);
glVertex2f((0.54f + 1) * 500 * scale + 200, (-0.15f + 1) * 500 * scale + 200);
glEnd();

// Left window lines
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(0, 0, 0);
glVertex2f((0.54f + 1) * 500 * scale + 200, (-0.05f + 1) * 500 * scale + 200);
glVertex2f((0.54f + 1) * 500 * scale + 200, (-0.15f + 1) * 500 * scale + 200);
glVertex2f((0.48f + 1) * 500 * scale + 200, (-0.05f + 1) * 500 * scale + 200);
glVertex2f((0.48f + 1) * 500 * scale + 200, (-0.15f + 1) * 500 * scale + 200);
glVertex2f((0.54f + 1) * 500 * scale + 200, (-0.05f + 1) * 500 * scale + 200);
glVertex2f((0.48f + 1) * 500 * scale + 200, (-0.05f + 1) * 500 * scale + 200);
glVertex2f((0.54f + 1) * 500 * scale + 200, (-0.15f + 1) * 500 * scale + 200);
glVertex2f((0.48f + 1) * 500 * scale + 200, (-0.15f + 1) * 500 * scale + 200);
glVertex2f((0.51f + 1) * 500 * scale + 200, (-0.05f + 1) * 500 * scale + 200);
glVertex2f((0.51f + 1) * 500 * scale + 200, (-0.15f + 1) * 500 * scale + 200);
glEnd();

// Second door
glBegin(GL_POLYGON);
glColor3ub(45, 33, 0); // Deep Yellow-Orange Shadow
glVertex2f((0.61f + 1) * 500 * scale + 200, (0.02f + 1) * 500 * scale + 200);
glVertex2f((0.68f + 1) * 500 * scale + 200, (0.04f + 1) * 500 * scale + 200);
glVertex2f((0.68f + 1) * 500 * scale + 200, (-0.27f + 1) * 500 * scale + 200);
glVertex2f((0.61f + 1) * 500 * scale + 200, (-0.3f + 1) * 500 * scale + 200);
glEnd();

// Second door lines
glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(0, 0, 0);
glVertex2f((0.68f + 1) * 500 * scale + 200, (0.04f + 1) * 500 * scale + 200);
glVertex2f((0.68f + 1) * 500 * scale + 200, (-0.27f + 1) * 500 * scale + 200);
glVertex2f((0.61f + 1) * 500 * scale + 200, (0.02f + 1) * 500 * scale + 200);
glVertex2f((0.61f + 1) * 500 * scale + 200, (-0.3f + 1) * 500 * scale + 200);
glVertex2f((0.68f + 1) * 500 * scale + 200, (0.04f + 1) * 500 * scale + 200);
glVertex2f((0.61f + 1) * 500 * scale + 200, (0.02f + 1) * 500 * scale + 200);
glVertex2f((0.645f + 1) * 500 * scale + 200, (0.03f + 1) * 500 * scale + 200);
glVertex2f((0.645f + 1) * 500 * scale + 200, (-0.29f + 1) * 500 * scale + 200);
glVertex2f((0.68f + 1) * 500 * scale + 200, (-0.27f + 1) * 500 * scale + 200);
glVertex2f((0.645f + 1) * 500 * scale + 200, (-0.29f + 1) * 500 * scale + 200);
glEnd();


// Right window
glBegin(GL_POLYGON);
glColor3ub(190, 140, 0);
glVertex2f((0.24f + 1) * 500 * scale + 200, (-0.05f + 1) * 500 * scale + 200);
glVertex2f((0.3f + 1) * 500 * scale + 200, (-0.05f + 1) * 500 * scale + 200);
glVertex2f((0.3f + 1) * 500 * scale + 200, (-0.15f + 1) * 500 * scale + 200);
glVertex2f((0.24f + 1) * 500 * scale + 200, (-0.15f + 1) * 500 * scale + 200);
glEnd();

glLineWidth(2);
glBegin(GL_LINES);
glColor3ub(0, 0, 0);
glVertex2f((0.24f + 1) * 500 * scale + 200, (-0.05f + 1) * 500 * scale + 200);
glVertex2f((0.24f + 1) * 500 * scale + 200, (-0.15f + 1) * 500 * scale + 200);
glVertex2f((0.3f + 1) * 500 * scale + 200, (-0.05f + 1) * 500 * scale + 200);
glVertex2f((0.3f + 1) * 500 * scale + 200, (-0.15f + 1) * 500 * scale + 200);
glVertex2f((0.24f + 1) * 500 * scale + 200, (-0.05f + 1) * 500 * scale + 200);
glVertex2f((0.3f + 1) * 500 * scale + 200, (-0.05f + 1) * 500 * scale + 200);
glVertex2f((0.24f + 1) * 500 * scale + 200, (-0.15f + 1) * 500 * scale + 200);
glVertex2f((0.3f + 1) * 500 * scale + 200, (-0.15f + 1) * 500 * scale + 200);
glVertex2f((0.27f + 1) * 500 * scale + 200, (-0.05f + 1) * 500 * scale + 200);
glVertex2f((0.27f + 1) * 500 * scale + 200, (-0.15f + 1) * 500 * scale + 200);
glEnd();



}

float batPosition = 0.0f;
void batMobile()
{
    //Batmobile

// Main body
//Batmobile

// Main body
glColor3f(0.13f, 0.13f, 0.13f);
glBegin(GL_POLYGON);
glVertex2f(60, 291 - 160);  // Adjusted y-coordinate
glVertex2f(53, 301 - 160);  // Adjusted y-coordinate
glVertex2f(30, 346 - 160);  // Adjusted y-coordinate
glVertex2f(35, 351 - 160);  // Adjusted y-coordinate
glVertex2f(140, 341 - 160); // Adjusted y-coordinate
glVertex2f(205, 331 - 160); // Adjusted y-coordinate
glVertex2f(210, 324 - 160); // Adjusted y-coordinate
glVertex2f(215, 291 - 160); // Adjusted y-coordinate
glEnd();

// Head
glColor3f(0.13f, 0.13f, 0.13f);
glBegin(GL_POLYGON);
glVertex2f(62, 341 - 160);  // Adjusted y-coordinate
glVertex2f(70, 351 - 160);  // Adjusted y-coordinate
glVertex2f(75, 366 - 160);  // Adjusted y-coordinate
glVertex2f(130, 357 - 160); // Adjusted y-coordinate
glVertex2f(135, 353 - 160); // Adjusted y-coordinate
glVertex2f(140, 341 - 160); // Adjusted y-coordinate
glEnd();

// Back fang
glColor3f(0.067f, 0.016f, 0.158f);
glBegin(GL_POLYGON);
glVertex2f(30, 346 - 160);  // Adjusted y-coordinate
glVertex2f(26, 341 - 160);  // Adjusted y-coordinate
glVertex2f(40, 336 - 160);  // Adjusted y-coordinate
glVertex2f(30, 331 - 160);  // Adjusted y-coordinate
glVertex2f(50, 326 - 160);  // Adjusted y-coordinate
glVertex2f(32, 321 - 160);  // Adjusted y-coordinate
glVertex2f(60, 316 - 160);  // Adjusted y-coordinate
glVertex2f(35, 311 - 160);  // Adjusted y-coordinate
glVertex2f(70, 306 - 160);  // Adjusted y-coordinate
glVertex2f(38, 301 - 160);  // Adjusted y-coordinate
glVertex2f(80, 296 - 160);  // Adjusted y-coordinate
glEnd();

// Shadows
glColor3f(0.05f, 0.05f, 0.05f);
glBegin(GL_QUADS);
glVertex2f(30, 346 - 160);  // Adjusted y-coordinate
glVertex2f(60, 291 - 160);  // Adjusted y-coordinate
glVertex2f(210, 291 - 160); // Adjusted y-coordinate
glVertex2f(130, 331 - 160); // Adjusted y-coordinate
glEnd();

// Wheels
// Left White Wheel Circle
glColor3f(0.0f, 0.0f, 0.0f);
drawCircle(80.0f, 293.0f - 160, 12.0f); // Adjusted y-coordinate

// Left Inner Black Wheel Circle
glColor3f(0.3f, 0.3f, 0.3f);
drawCircle(80.0f, 293.0f - 160, 7.0f); // Adjusted y-coordinate

// Right Black Wheel Circle
glColor3f(0.0f, 0.0f, 0.0f);
drawCircle(180.0f, 293.0f - 160, 12.0f); // Adjusted y-coordinate

// Right Inner White Wheel Circle
glColor3f(0.3f, 0.3f, 0.3f);
drawCircle(180.0f, 293.0f - 160, 7.0f); // Adjusted y-coordinate

// Windows
glColor3f(0.396f, 0.339f, 0.491f);
glBegin(GL_QUADS);
glVertex2f(107, 359 - 160); // Adjusted y-coordinate
glVertex2f(133, 354 - 160); // Adjusted y-coordinate
glVertex2f(139, 339 - 160); // Adjusted y-coordinate
glVertex2f(100, 341 - 160); // Adjusted y-coordinate
glEnd();

// Window shadow
glColor3f(0.296f, 0.239f, 0.391f);
glBegin(GL_QUADS);
glVertex2f(103, 349 - 160); // Adjusted y-coordinate
glVertex2f(133, 344 - 160); // Adjusted y-coordinate
glVertex2f(139, 339 - 160); // Adjusted y-coordinate
glVertex2f(100, 341 - 160); // Adjusted y-coordinate
glEnd();

}





void boat()
{

// Boat design moved up by 380 on the Y-axis

glBegin(GL_POLYGON); //body middle
glColor3f(0.0, 0.0f, 0.f);
glVertex2f(300, 530 + 70); //top right
glVertex2f(300, 510 + 70); //bottom right
glVertex2f(100, 510 + 70); //bottom left
glVertex2f(100, 530 + 70); //top left
glEnd();

glBegin(GL_TRIANGLES); //left angle
glColor3f(0.0, 0.0f, 0.f);
glVertex2f(100, 510 + 70); //bottom
glVertex2f(100, 530 + 70); //top
glVertex2f(50, 560 + 70); //bottom right
glEnd();

glBegin(GL_TRIANGLES);//right angle
glColor3f(0.0, 0.0f, 0.f);
glVertex2f(300, 510 + 70); //bottom
glVertex2f(300, 530 + 70); //top
glVertex2f(350, 560 + 70); //bottom right
glEnd();

glBegin(GL_POLYGON);//middle upper 1
glColor3f(0.55f, 0.27f, 0.07f);
glVertex2f(105, 530 + 70);
glVertex2f(110, 550 + 70);
glVertex2f(290, 550 + 70);
glVertex2f(295, 530 + 70);
glEnd();

glBegin(GL_POLYGON);//middle upper 2
glColor3f(0.55f, 0.27f, 0.07f);
glVertex2f(110, 550 + 70);
glVertex2f(115, 570 + 70);
glVertex2f(285, 570 + 70);
glVertex2f(290, 550 + 70);
glEnd();

glBegin(GL_LINES);//middle upper line 1
glColor3f(0.0, 0.0f, 0.f);
glVertex2f(110, 550 + 70);
glVertex2f(290, 550 + 70);
glEnd();

glBegin(GL_POLYGON);//middle upper 3
glColor3f(0.55f, 0.27f, 0.07f);
glVertex2f(115, 570 + 70);
glVertex2f(120, 590 + 70);
glVertex2f(280, 590 + 70);
glVertex2f(285, 570 + 70);
glEnd();

glBegin(GL_LINES);//middle upper line 2
glColor3f(0.0, 0.0f, 0.f);
glVertex2f(115, 570 + 70);
glVertex2f(285, 570 + 70);
glEnd();

glBegin(GL_LINES);//middle upper line 3
glColor3f(0.0, 0.0f, 0.f);
glVertex2f(120, 590 + 70);
glVertex2f(280, 590 + 70);
glEnd();

glBegin(GL_LINES);//line 4 upper
glColor3f(0.0, 0.0f, 0.f);
glVertex2f(120, 530 + 70);
glVertex2f(120, 590 + 70);
glEnd();

glBegin(GL_LINES);//line 5 upper
glColor3f(0.0, 0.0f, 0.f);
glVertex2f(200, 530 + 70);
glVertex2f(200, 590 + 70);
glEnd();

glBegin(GL_LINES);//line 6 upper
glColor3f(0.0, 0.0f, 0.f);
glVertex2f(280, 530 + 70);
glVertex2f(280, 590 + 70);
glEnd();









/*
   glBegin(GL_LINES);
   glColor3f(0.0, 0.0, 0.0); // Black color ,boat mast
   glVertex2f(200, 210); // Bottom
   glVertex2f(200, 280); // Top
   glEnd();


   glBegin(GL_TRIANGLES);
   glColor3f(1.0, 1.0, 0.0); // Yellow , boat sail
    glVertex2f(200, 210); // Bottom
   glVertex2f(200, 280); // Top
   glVertex2f(250, 245); // Right point of  sail //angle
    // glVertex2f(150, 245); // Right point of  sail
*/

}


void boatN()
{

// Boat design moved up by 380 on the Y-axis

glBegin(GL_POLYGON); //body middle
glColor3f(0.0, 0.0f, 0.f);
glVertex2f(300, 530 + 70); //top right
glVertex2f(300, 510 + 70); //bottom right
glVertex2f(100, 510 + 70); //bottom left
glVertex2f(100, 530 + 70); //top left
glEnd();

glBegin(GL_TRIANGLES); //left angle
glColor3f(0.0, 0.0f, 0.f);
glVertex2f(100, 510 + 70); //bottom
glVertex2f(100, 530 + 70); //top
glVertex2f(50, 560 + 70); //bottom right
glEnd();

glBegin(GL_TRIANGLES);//right angle
glColor3f(0.0, 0.0f, 0.f);
glVertex2f(300, 510 + 70); //bottom
glVertex2f(300, 530 + 70); //top
glVertex2f(350, 560 + 70); //bottom right
glEnd();

glBegin(GL_POLYGON);//middle upper 1
glColor3f(0.25f, 0.12f, 0.04f);
glVertex2f(105, 530 + 70);
glVertex2f(110, 550 + 70);
glVertex2f(290, 550 + 70);
glVertex2f(295, 530 + 70);
glEnd();

glBegin(GL_POLYGON);//middle upper 2
glColor3f(0.25f, 0.12f, 0.04f);
glVertex2f(110, 550 + 70);
glVertex2f(115, 570 + 70);
glVertex2f(285, 570 + 70);
glVertex2f(290, 550 + 70);
glEnd();

glBegin(GL_LINES);//middle upper line 1
glColor3f(0.0, 0.0f, 0.f);
glVertex2f(110, 550 + 70);
glVertex2f(290, 550 + 70);
glEnd();

glBegin(GL_POLYGON);//middle upper 3
glColor3f(0.25f, 0.12f, 0.04f);
glVertex2f(115, 570 + 70);
glVertex2f(120, 590 + 70);
glVertex2f(280, 590 + 70);
glVertex2f(285, 570 + 70);
glEnd();

glBegin(GL_LINES);//middle upper line 2
glColor3f(0.0, 0.0f, 0.f);
glVertex2f(115, 570 + 70);
glVertex2f(285, 570 + 70);
glEnd();

glBegin(GL_LINES);//middle upper line 3
glColor3f(0.0, 0.0f, 0.f);
glVertex2f(120, 590 + 70);
glVertex2f(280, 590 + 70);
glEnd();

glBegin(GL_LINES);//line 4 upper
glColor3f(0.0, 0.0f, 0.f);
glVertex2f(120, 530 + 70);
glVertex2f(120, 590 + 70);
glEnd();

glBegin(GL_LINES);//line 5 upper
glColor3f(0.0, 0.0f, 0.f);
glVertex2f(200, 530 + 70);
glVertex2f(200, 590 + 70);
glEnd();

glBegin(GL_LINES);//line 6 upper
glColor3f(0.0, 0.0f, 0.f);
glVertex2f(280, 530 + 70);
glVertex2f(280, 590 + 70);
glEnd();









/*
   glBegin(GL_LINES);
   glColor3f(0.0, 0.0, 0.0); // Black color ,boat mast
   glVertex2f(200, 210); // Bottom
   glVertex2f(200, 280); // Top
   glEnd();


   glBegin(GL_TRIANGLES);
   glColor3f(1.0, 1.0, 0.0); // Yellow , boat sail
    glVertex2f(200, 210); // Bottom
   glVertex2f(200, 280); // Top
   glVertex2f(250, 245); // Right point of  sail //angle
    // glVertex2f(150, 245); // Right point of  sail
*/

}

void river()
{
        //River
    glBegin(GL_POLYGON);
glColor3f(0.0f, 0.6f, 0.6f);  // Turquoise glacial water
    glVertex2f(1000,300);//top right
    glVertex2f(1000,0);//bottom right
    glVertex2f(0,0);//bottom left
    glVertex2f(0,300);//top left
    glEnd();
}

 /*road()
 {
                 //road
    glBegin(GL_POLYGON);
 //glColor3f(0.55f, 0.37f, 0.26f); // Brownish tone for a natural dirt road
glColor3f(0.4f, 0.4f, 0.4f);  // Medium gray

    glVertex2f(1000,350);//top right
    glVertex2f(1000,280);//bottom right
    glVertex2f(0,280);//bottom left
    //glVertex2f(700,200);//angle
    glVertex2f(0,350);//top left
    glEnd();

        /*
    //for cycle.....road line
        glBegin(GL_LINES);//middle upper line 1
   glColor3f(0.0, 0.0f, 0.f);

    glVertex2f(1000,320);  // Starting point of the line
   glVertex2f(0,320);;      // Ending point of the line
   glEnd();

   */
   /*

 } */

  void cropland()
  {
         glBegin(GL_POLYGON);
//glColor3f(0.15f, 0.6f, 0.15f); // A deeper, darker green for denser vegetation
//glColor3f(0.396, 0.263, 0.129);
    glColor3ub(0, 128, 0);


    glVertex2f(1000,530);//top right
    glVertex2f(1000,240);//bottom right
    glVertex2f(0,240);//bottom left
    //glVertex2f(700,200);//angle
    glVertex2f(0,530);//top left
    glEnd();
  }

  void croplandN()
  {
         glBegin(GL_POLYGON);
//glColor3f(0.15f, 0.6f, 0.15f); // A deeper, darker green for denser vegetation
//glColor3f(0.396, 0.263, 0.129);
//glColor3ub(0, 64, 0); // Dark green shadow
glColor3ub(0, 64, 32); // Dark green with a hint of gray


    glVertex2f(1000,530);//top right
    glVertex2f(1000,240);//bottom right
    glVertex2f(0,240);//bottom left
    //glVertex2f(700,200);//angle
    glVertex2f(0,530);//top left
    glEnd();
  }


    void river1()
  {
        glBegin(GL_POLYGON);
//glColor3f(0.15f, 0.6f, 0.15f); // A deeper, darker green for denser vegetation
//glColor3f(0.396, 0.263, 0.129);
glColor3f(0.0f, 0.6f, 0.8f);  // Crystal Blue (#0099CC)

    glVertex2f(1000,725);//top right
    glVertex2f(1000,530);//bottom right
    glVertex2f(0,530);//bottom left
    //glVertex2f(700,200);//angle
    glVertex2f(0,725);//top left
    glEnd();
  }


    void river1N()
  {
        glBegin(GL_POLYGON);
//glColor3f(0.15f, 0.6f, 0.15f); // A deeper, darker green for denser vegetation
//glColor3f(0.396, 0.263, 0.129);
glColor3f(0.0f, 0.4f, 0.6f); // Darker crystal blue with a deeper tone

    glVertex2f(1000,725);//top right
    glVertex2f(1000,530);//bottom right
    glVertex2f(0,530);//bottom left
    //glVertex2f(700,200);//angle
    glVertex2f(0,725);//top left
    glEnd();
  }

void hillsCropland()
  {
  glBegin(GL_POLYGON);
glColor3ub(0, 128, 0);
glVertex2f(0,715);
glVertex2f(0,725);
glVertex2f(1000, 725);
glVertex2f(1000, 715);


glEnd();

  }

  void hillsCroplandN()
  {
  glBegin(GL_POLYGON);
glColor3ub(0, 64, 32); // Dark green with a hint of gray
glVertex2f(0,715);
glVertex2f(0,725);
glVertex2f(1000, 725);
glVertex2f(1000, 715);


glEnd();

  }

void sky()
  {
        glBegin(GL_POLYGON);
//glColor3f(0.15f, 0.6f, 0.15f); // A deeper, darker green for denser vegetation
//glColor3f(0.396, 0.263, 0.129);
   glColor3f(0.4f, 0.7f, 1.0f);
    glVertex2f(1000,1000);//top right
    glVertex2f(1000,725);//bottom right
    glVertex2f(0,725);//bottom left
    //glVertex2f(700,200);//angle
    glVertex2f(0,1000);//top left
    glEnd();
  }

  void sky1()
  {
        glBegin(GL_POLYGON);
//glColor3f(0.15f, 0.6f, 0.15f); // A deeper, darker green for denser vegetation
//glColor3f(0.396, 0.263, 0.129);
   glColor3f(0.0f, 0.0f, 0.2f);  // Dark Night Sky (#000033)
   //glColor3f(0.0f, 0.2f, 0.4f);  // Dark Blue (#003366)


    glVertex2f(1000,1000);//top right
    glVertex2f(1000,725);//bottom right
    glVertex2f(0,725);//bottom left
    //glVertex2f(700,200);//angle
    glVertex2f(0,1000);//top left
    glEnd();
  }



  void hills2()
{


glBegin(GL_POLYGON);
glColor3ub(102, 68, 0);
glVertex2f(((-0.25f + 1) * 500) - 375, (0.45f + 1) * 500);  // (375 - 375, 725) -> (0, 725)
glVertex2f(((-0.23f + 1) * 500) - 375, (0.5f + 1) * 500);   // (385 - 375, 750) -> (10, 750)
glVertex2f(((-0.18f + 1) * 500) - 375, (0.61f + 1) * 500);  // (410 - 375, 805) -> (35, 805)
glVertex2f(((-0.15f + 1) * 500) - 375, (0.65f + 1) * 500);  // (425 - 375, 825) -> (50, 825)
glVertex2f(((-0.07f + 1) * 500) - 375, (0.69f + 1) * 500);  // (465 - 375, 845) -> (90, 845)
glVertex2f(((0.0f + 1) * 500) - 375, (0.72f + 1) * 500);    // (500 - 375, 860) -> (125, 860)
glVertex2f(((0.07f + 1) * 500) - 375, (0.69f + 1) * 500);   // (535 - 375, 845) -> (160, 845)
glVertex2f(((0.15f + 1) * 500) - 375, (0.65f + 1) * 500);   // (575 - 375, 825) -> (200, 825)
glVertex2f(((0.18f + 1) * 500) - 375, (0.61f + 1) * 500);   // (590 - 375, 805) -> (215, 805)
glVertex2f(((0.23f + 1) * 500) - 375, (0.5f + 1) * 500);    // (615 - 375, 750) -> (240, 750)
glVertex2f(((0.25f + 1) * 500) - 375, (0.45f + 1) * 500);   // (625 - 375, 725) -> (250, 725)
glEnd();



glBegin(GL_POLYGON);
glColor3ub(102, 68, 0);
glVertex2f(375 + ((-0.25f + 1) * 500), (0.45f + 1) * 500);  // (375 + 375, 725) -> (750, 725)
glVertex2f(375 + ((-0.23f + 1) * 500), (0.5f + 1) * 500);   // (375 + 385, 750) -> (760, 750)
glVertex2f(375 + ((-0.18f + 1) * 500), (0.61f + 1) * 500);  // (375 + 410, 805) -> (785, 805)
glVertex2f(375 + ((-0.15f + 1) * 500), (0.65f + 1) * 500);  // (375 + 425, 825) -> (800, 825)
glVertex2f(375 + ((-0.07f + 1) * 500), (0.69f + 1) * 500);  // (375 + 465, 845) -> (840, 845)
glVertex2f(375 + ((0.0f + 1) * 500), (0.72f + 1) * 500);    // (375 + 500, 860) -> (875, 860)
glVertex2f(375 + ((0.07f + 1) * 500), (0.69f + 1) * 500);   // (375 + 535, 845) -> (910, 845)
glVertex2f(375 + ((0.15f + 1) * 500), (0.65f + 1) * 500);   // (375 + 575, 825) -> (950, 825)
glVertex2f(375 + ((0.18f + 1) * 500), (0.61f + 1) * 500);   // (375 + 590, 805) -> (965, 805)
glVertex2f(375 + ((0.23f + 1) * 500), (0.5f + 1) * 500);    // (375 + 615, 750) -> (990, 750)
glVertex2f(375 + ((0.25f + 1) * 500), (0.45f + 1) * 500);   // (375 + 625, 725) -> (1000, 725)
glEnd();




glBegin(GL_POLYGON);
glColor3ub(102, 68, 0);
glVertex2f((-0.5f + 1) * 500, (0.45f + 1) * 500);  // (-0.5, 0.45) -> (250, 725)
glVertex2f((-0.48f + 1) * 500, (0.5f + 1) * 500);  // (-0.48, 0.5) -> (260, 750)
glVertex2f((-0.45f + 1) * 500, (0.56f + 1) * 500); // (-0.45, 0.56) -> (275, 780)
glVertex2f((-0.42f + 1) * 500, (0.6f + 1) * 500);  // (-0.42, 0.6) -> (290, 800)
glVertex2f((-0.37f + 1) * 500, (0.62f + 1) * 500); // (-0.37, 0.62) -> (315, 810)
glVertex2f((-0.32f + 1) * 500, (0.6f + 1) * 500);  // (-0.32, 0.6) -> (340, 800)
glVertex2f((-0.29f + 1) * 500, (0.56f + 1) * 500); // (-0.29, 0.56) -> (355, 780)
glVertex2f((-0.27f + 1) * 500, (0.5f + 1) * 500);  // (-0.27, 0.5) -> (365, 750)
glVertex2f((-0.25f + 1) * 500, (0.45f + 1) * 500); // (-0.25, 0.45) -> (375, 725)
glEnd();

glBegin(GL_POLYGON);
glColor3ub(102, 68, 0);
glVertex2f((0.5f + 1) * 500, (0.45f + 1) * 500);  // (0.5, 0.45) -> (750, 725)
glVertex2f((0.48f + 1) * 500, (0.5f + 1) * 500);  // (0.48, 0.5) -> (740, 750)
glVertex2f((0.45f + 1) * 500, (0.56f + 1) * 500); // (0.45, 0.56) -> (725, 780)
glVertex2f((0.42f + 1) * 500, (0.6f + 1) * 500);  // (0.42, 0.6) -> (710, 800)
glVertex2f((0.37f + 1) * 500, (0.62f + 1) * 500); // (0.37, 0.62) -> (685, 810)
glVertex2f((0.32f + 1) * 500, (0.6f + 1) * 500);  // (0.32, 0.6) -> (660, 800)
glVertex2f((0.29f + 1) * 500, (0.56f + 1) * 500); // (0.29, 0.56) -> (645, 780)
glVertex2f((0.27f + 1) * 500, (0.5f + 1) * 500);  // (0.27, 0.5) -> (635, 750)
glVertex2f((0.25f + 1) * 500, (0.45f + 1) * 500); // (0.25, 0.45) -> (625, 725)
glEnd();

glBegin(GL_POLYGON);
glColor3ub(102, 68, 0);
glVertex2f((-0.25f + 1) * 500, (0.45f + 1) * 500);  // (-0.25, 0.45) -> (375, 725)
glVertex2f((-0.23f + 1) * 500, (0.5f + 1) * 500);  // (-0.23, 0.5) -> (385, 750)
glVertex2f((-0.18f + 1) * 500, (0.61f + 1) * 500); // (-0.18, 0.61) -> (410, 805)
glVertex2f((-0.15f + 1) * 500, (0.65f + 1) * 500); // (-0.15, 0.65) -> (425, 825)
glVertex2f((-0.07f + 1) * 500, (0.69f + 1) * 500); // (-0.07, 0.69) -> (465, 845)
glVertex2f((0.0f + 1) * 500, (0.72f + 1) * 500);   // (0.0, 0.72) -> (500, 860)
glVertex2f((0.07f + 1) * 500, (0.69f + 1) * 500);  // (0.07, 0.69) -> (535, 845)
glVertex2f((0.15f + 1) * 500, (0.65f + 1) * 500);  // (0.15, 0.65) -> (575, 825)
glVertex2f((0.18f + 1) * 500, (0.61f + 1) * 500);  // (0.18, 0.61) -> (590, 805)
glVertex2f((0.23f + 1) * 500, (0.5f + 1) * 500);   // (0.23, 0.5) -> (615, 750)
glVertex2f((0.25f + 1) * 500, (0.45f + 1) * 500);  // (0.25, 0.45) -> (625, 725)
glEnd();








// Palm Trees
glBegin(GL_POLYGON);
glColor3ub(102, 51, 0);
glVertex2f((-0.52f + 1) * 500, (0.45f + 1) * 500); // (-0.52, 0.45) -> (240, 725)
glVertex2f((-0.48f + 1) * 500, (0.45f + 1) * 500); // (-0.48, 0.45) -> (260, 725)
glVertex2f((-0.48f + 1) * 500, (0.62f + 1) * 500); // (-0.48, 0.62) -> (260, 810)
glVertex2f((-0.5f + 1) * 500, (0.64f + 1) * 500);  // (-0.5, 0.64) -> (250, 820)
glVertex2f((-0.52f + 1) * 500, (0.62f + 1) * 500); // (-0.52, 0.62) -> (240, 810)
glEnd();

glBegin(GL_POLYGON);
glColor3ub(34, 139, 34);
glVertex2f((-0.5f + 1) * 500, (0.64f + 1) * 500);  // (-0.5, 0.64) -> (250, 820)
glVertex2f((-0.52f + 1) * 500, (0.62f + 1) * 500); // (-0.52, 0.62) -> (240, 810)
glVertex2f((-0.58f + 1) * 500, (0.6f + 1) * 500);  // (-0.58, 0.6) -> (210, 800)
glVertex2f((-0.55f + 1) * 500, (0.63f + 1) * 500); // (-0.55, 0.63) -> (225, 815)
glVertex2f((-0.58f + 1) * 500, (0.66f + 1) * 500); // (-0.58, 0.66) -> (210, 830)
glVertex2f((-0.52f + 1) * 500, (0.66f + 1) * 500); // (-0.52, 0.66) -> (240, 830)
glVertex2f((-0.52f + 1) * 500, (0.72f + 1) * 500); // (-0.52, 0.72) -> (240, 860)
glVertex2f((-0.5f + 1) * 500, (0.69f + 1) * 500);  // (-0.5, 0.69) -> (250, 845)
glVertex2f((-0.48f + 1) * 500, (0.72f + 1) * 500); // (-0.48, 0.72) -> (260, 860)
glVertex2f((-0.48f + 1) * 500, (0.66f + 1) * 500); // (-0.48, 0.66) -> (260, 830)
glVertex2f((-0.42f + 1) * 500, (0.66f + 1) * 500); // (-0.42, 0.66) -> (290, 830)
glVertex2f((-0.45f + 1) * 500, (0.63f + 1) * 500); // (-0.45, 0.63) -> (275, 815)
glVertex2f((-0.42f + 1) * 500, (0.6f + 1) * 500);  // (-0.42, 0.6) -> (290, 800)
glVertex2f((-0.48f + 1) * 500, (0.62f + 1) * 500); // (-0.48, 0.62) -> (260, 810)
glEnd();

glBegin(GL_POLYGON);
glColor3ub(102, 51, 0);
glVertex2f((0.52f + 1) * 500, (0.45f + 1) * 500); // (0.52, 0.45) -> (760, 725)
glVertex2f((0.48f + 1) * 500, (0.45f + 1) * 500); // (0.48, 0.45) -> (740, 725)
glVertex2f((0.48f + 1) * 500, (0.62f + 1) * 500); // (0.48, 0.62) -> (740, 810)
glVertex2f((0.5f + 1) * 500, (0.64f + 1) * 500);  // (0.5, 0.64) -> (750, 820)
glVertex2f((0.52f + 1) * 500, (0.62f + 1) * 500); // (0.52, 0.62) -> (760, 810)
glEnd();

glBegin(GL_POLYGON);
glColor3ub(34, 139, 34);
glVertex2f((0.5f + 1) * 500, (0.64f + 1) * 500);  // (0.5, 0.64) -> (750, 820)
glVertex2f((0.52f + 1) * 500, (0.62f + 1) * 500); // (0.52, 0.62) -> (760, 810)
glVertex2f((0.58f + 1) * 500, (0.6f + 1) * 500);  // (0.58, 0.6) -> (790, 800)
glVertex2f((0.55f + 1) * 500, (0.63f + 1) * 500); // (0.55, 0.63) -> (775, 815)
glVertex2f((0.58f + 1) * 500, (0.66f + 1) * 500); // (0.58, 0.66) -> (790, 830)
glVertex2f((0.52f + 1) * 500, (0.66f + 1) * 500); // (0.52, 0.66) -> (760, 830)
glVertex2f((0.52f + 1) * 500, (0.72f + 1) * 500); // (0.52, 0.72) -> (760, 860)
glVertex2f((0.5f + 1) * 500, (0.69f + 1) * 500);  // (0.5, 0.69) -> (750, 845)
glVertex2f((0.48f + 1) * 500, (0.72f + 1) * 500); // (0.48, 0.72) -> (740, 860)
glVertex2f((0.48f + 1) * 500, (0.66f + 1) * 500); // (0.48, 0.66) -> (740, 830)
glVertex2f((0.42f + 1) * 500, (0.66f + 1) * 500); // (0.42, 0.66) -> (710, 830)
glVertex2f((0.45f + 1) * 500, (0.63f + 1) * 500); // (0.45, 0.63) -> (725, 815)
glVertex2f((0.42f + 1) * 500, (0.6f + 1) * 500);  // (0.42, 0.6) -> (710, 800)
glVertex2f((0.48f + 1) * 500, (0.62f + 1) * 500); // (0.48, 0.62) -> (740, 810)
glEnd();

// Other polygons (converted similarly)
// ... (apply the same transformation to the remaining polygons)

}


  void hills2N()
{


glBegin(GL_POLYGON);
glColor3ub(30, 20, 5); // Dark brown with a hint of red and very low brightness
glVertex2f(((-0.25f + 1) * 500) - 375, (0.45f + 1) * 500);  // (375 - 375, 725) -> (0, 725)
glVertex2f(((-0.23f + 1) * 500) - 375, (0.5f + 1) * 500);   // (385 - 375, 750) -> (10, 750)
glVertex2f(((-0.18f + 1) * 500) - 375, (0.61f + 1) * 500);  // (410 - 375, 805) -> (35, 805)
glVertex2f(((-0.15f + 1) * 500) - 375, (0.65f + 1) * 500);  // (425 - 375, 825) -> (50, 825)
glVertex2f(((-0.07f + 1) * 500) - 375, (0.69f + 1) * 500);  // (465 - 375, 845) -> (90, 845)
glVertex2f(((0.0f + 1) * 500) - 375, (0.72f + 1) * 500);    // (500 - 375, 860) -> (125, 860)
glVertex2f(((0.07f + 1) * 500) - 375, (0.69f + 1) * 500);   // (535 - 375, 845) -> (160, 845)
glVertex2f(((0.15f + 1) * 500) - 375, (0.65f + 1) * 500);   // (575 - 375, 825) -> (200, 825)
glVertex2f(((0.18f + 1) * 500) - 375, (0.61f + 1) * 500);   // (590 - 375, 805) -> (215, 805)
glVertex2f(((0.23f + 1) * 500) - 375, (0.5f + 1) * 500);    // (615 - 375, 750) -> (240, 750)
glVertex2f(((0.25f + 1) * 500) - 375, (0.45f + 1) * 500);   // (625 - 375, 725) -> (250, 725)
glEnd();



glBegin(GL_POLYGON);
glColor3ub(30, 20, 5); // Dark brown with a hint of red and very low brightness
glVertex2f(375 + ((-0.25f + 1) * 500), (0.45f + 1) * 500);  // (375 + 375, 725) -> (750, 725)
glVertex2f(375 + ((-0.23f + 1) * 500), (0.5f + 1) * 500);   // (375 + 385, 750) -> (760, 750)
glVertex2f(375 + ((-0.18f + 1) * 500), (0.61f + 1) * 500);  // (375 + 410, 805) -> (785, 805)
glVertex2f(375 + ((-0.15f + 1) * 500), (0.65f + 1) * 500);  // (375 + 425, 825) -> (800, 825)
glVertex2f(375 + ((-0.07f + 1) * 500), (0.69f + 1) * 500);  // (375 + 465, 845) -> (840, 845)
glVertex2f(375 + ((0.0f + 1) * 500), (0.72f + 1) * 500);    // (375 + 500, 860) -> (875, 860)
glVertex2f(375 + ((0.07f + 1) * 500), (0.69f + 1) * 500);   // (375 + 535, 845) -> (910, 845)
glVertex2f(375 + ((0.15f + 1) * 500), (0.65f + 1) * 500);   // (375 + 575, 825) -> (950, 825)
glVertex2f(375 + ((0.18f + 1) * 500), (0.61f + 1) * 500);   // (375 + 590, 805) -> (965, 805)
glVertex2f(375 + ((0.23f + 1) * 500), (0.5f + 1) * 500);    // (375 + 615, 750) -> (990, 750)
glVertex2f(375 + ((0.25f + 1) * 500), (0.45f + 1) * 500);   // (375 + 625, 725) -> (1000, 725)
glEnd();




glBegin(GL_POLYGON);
glColor3ub(30, 20, 5); // Dark brown with a hint of red and very low brightness
glVertex2f((-0.5f + 1) * 500, (0.45f + 1) * 500);  // (-0.5, 0.45) -> (250, 725)
glVertex2f((-0.48f + 1) * 500, (0.5f + 1) * 500);  // (-0.48, 0.5) -> (260, 750)
glVertex2f((-0.45f + 1) * 500, (0.56f + 1) * 500); // (-0.45, 0.56) -> (275, 780)
glVertex2f((-0.42f + 1) * 500, (0.6f + 1) * 500);  // (-0.42, 0.6) -> (290, 800)
glVertex2f((-0.37f + 1) * 500, (0.62f + 1) * 500); // (-0.37, 0.62) -> (315, 810)
glVertex2f((-0.32f + 1) * 500, (0.6f + 1) * 500);  // (-0.32, 0.6) -> (340, 800)
glVertex2f((-0.29f + 1) * 500, (0.56f + 1) * 500); // (-0.29, 0.56) -> (355, 780)
glVertex2f((-0.27f + 1) * 500, (0.5f + 1) * 500);  // (-0.27, 0.5) -> (365, 750)
glVertex2f((-0.25f + 1) * 500, (0.45f + 1) * 500); // (-0.25, 0.45) -> (375, 725)
glEnd();

glBegin(GL_POLYGON);
glColor3ub(30, 20, 5); // Dark brown with a hint of red and very low brightness
glVertex2f((0.5f + 1) * 500, (0.45f + 1) * 500);  // (0.5, 0.45) -> (750, 725)
glVertex2f((0.48f + 1) * 500, (0.5f + 1) * 500);  // (0.48, 0.5) -> (740, 750)
glVertex2f((0.45f + 1) * 500, (0.56f + 1) * 500); // (0.45, 0.56) -> (725, 780)
glVertex2f((0.42f + 1) * 500, (0.6f + 1) * 500);  // (0.42, 0.6) -> (710, 800)
glVertex2f((0.37f + 1) * 500, (0.62f + 1) * 500); // (0.37, 0.62) -> (685, 810)
glVertex2f((0.32f + 1) * 500, (0.6f + 1) * 500);  // (0.32, 0.6) -> (660, 800)
glVertex2f((0.29f + 1) * 500, (0.56f + 1) * 500); // (0.29, 0.56) -> (645, 780)
glVertex2f((0.27f + 1) * 500, (0.5f + 1) * 500);  // (0.27, 0.5) -> (635, 750)
glVertex2f((0.25f + 1) * 500, (0.45f + 1) * 500); // (0.25, 0.45) -> (625, 725)
glEnd();

glBegin(GL_POLYGON);
glColor3ub(30, 20, 5); // Dark brown with a hint of red and very low brightness
glVertex2f((-0.25f + 1) * 500, (0.45f + 1) * 500);  // (-0.25, 0.45) -> (375, 725)
glVertex2f((-0.23f + 1) * 500, (0.5f + 1) * 500);  // (-0.23, 0.5) -> (385, 750)
glVertex2f((-0.18f + 1) * 500, (0.61f + 1) * 500); // (-0.18, 0.61) -> (410, 805)
glVertex2f((-0.15f + 1) * 500, (0.65f + 1) * 500); // (-0.15, 0.65) -> (425, 825)
glVertex2f((-0.07f + 1) * 500, (0.69f + 1) * 500); // (-0.07, 0.69) -> (465, 845)
glVertex2f((0.0f + 1) * 500, (0.72f + 1) * 500);   // (0.0, 0.72) -> (500, 860)
glVertex2f((0.07f + 1) * 500, (0.69f + 1) * 500);  // (0.07, 0.69) -> (535, 845)
glVertex2f((0.15f + 1) * 500, (0.65f + 1) * 500);  // (0.15, 0.65) -> (575, 825)
glVertex2f((0.18f + 1) * 500, (0.61f + 1) * 500);  // (0.18, 0.61) -> (590, 805)
glVertex2f((0.23f + 1) * 500, (0.5f + 1) * 500);   // (0.23, 0.5) -> (615, 750)
glVertex2f((0.25f + 1) * 500, (0.45f + 1) * 500);  // (0.25, 0.45) -> (625, 725)
glEnd();








// Palm Trees
glBegin(GL_POLYGON);
glColor3ub(60, 34, 0); // Dark brown shadow
glVertex2f((-0.52f + 1) * 500, (0.45f + 1) * 500); // (-0.52, 0.45) -> (240, 725)
glVertex2f((-0.48f + 1) * 500, (0.45f + 1) * 500); // (-0.48, 0.45) -> (260, 725)
glVertex2f((-0.48f + 1) * 500, (0.62f + 1) * 500); // (-0.48, 0.62) -> (260, 810)
glVertex2f((-0.5f + 1) * 500, (0.64f + 1) * 500);  // (-0.5, 0.64) -> (250, 820)
glVertex2f((-0.52f + 1) * 500, (0.62f + 1) * 500); // (-0.52, 0.62) -> (240, 810)
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0, 64, 32); // Dark green with a hint of gray
glVertex2f((-0.5f + 1) * 500, (0.64f + 1) * 500);  // (-0.5, 0.64) -> (250, 820)
glVertex2f((-0.52f + 1) * 500, (0.62f + 1) * 500); // (-0.52, 0.62) -> (240, 810)
glVertex2f((-0.58f + 1) * 500, (0.6f + 1) * 500);  // (-0.58, 0.6) -> (210, 800)
glVertex2f((-0.55f + 1) * 500, (0.63f + 1) * 500); // (-0.55, 0.63) -> (225, 815)
glVertex2f((-0.58f + 1) * 500, (0.66f + 1) * 500); // (-0.58, 0.66) -> (210, 830)
glVertex2f((-0.52f + 1) * 500, (0.66f + 1) * 500); // (-0.52, 0.66) -> (240, 830)
glVertex2f((-0.52f + 1) * 500, (0.72f + 1) * 500); // (-0.52, 0.72) -> (240, 860)
glVertex2f((-0.5f + 1) * 500, (0.69f + 1) * 500);  // (-0.5, 0.69) -> (250, 845)
glVertex2f((-0.48f + 1) * 500, (0.72f + 1) * 500); // (-0.48, 0.72) -> (260, 860)
glVertex2f((-0.48f + 1) * 500, (0.66f + 1) * 500); // (-0.48, 0.66) -> (260, 830)
glVertex2f((-0.42f + 1) * 500, (0.66f + 1) * 500); // (-0.42, 0.66) -> (290, 830)
glVertex2f((-0.45f + 1) * 500, (0.63f + 1) * 500); // (-0.45, 0.63) -> (275, 815)
glVertex2f((-0.42f + 1) * 500, (0.6f + 1) * 500);  // (-0.42, 0.6) -> (290, 800)
glVertex2f((-0.48f + 1) * 500, (0.62f + 1) * 500); // (-0.48, 0.62) -> (260, 810)
glEnd();

glBegin(GL_POLYGON);
glColor3ub(60, 34, 0); // Dark brown shadow
glVertex2f((0.52f + 1) * 500, (0.45f + 1) * 500); // (0.52, 0.45) -> (760, 725)
glVertex2f((0.48f + 1) * 500, (0.45f + 1) * 500); // (0.48, 0.45) -> (740, 725)
glVertex2f((0.48f + 1) * 500, (0.62f + 1) * 500); // (0.48, 0.62) -> (740, 810)
glVertex2f((0.5f + 1) * 500, (0.64f + 1) * 500);  // (0.5, 0.64) -> (750, 820)
glVertex2f((0.52f + 1) * 500, (0.62f + 1) * 500); // (0.52, 0.62) -> (760, 810)
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0, 64, 32); // Dark green with a hint of gray
glVertex2f((0.5f + 1) * 500, (0.64f + 1) * 500);  // (0.5, 0.64) -> (750, 820)
glVertex2f((0.52f + 1) * 500, (0.62f + 1) * 500); // (0.52, 0.62) -> (760, 810)
glVertex2f((0.58f + 1) * 500, (0.6f + 1) * 500);  // (0.58, 0.6) -> (790, 800)
glVertex2f((0.55f + 1) * 500, (0.63f + 1) * 500); // (0.55, 0.63) -> (775, 815)
glVertex2f((0.58f + 1) * 500, (0.66f + 1) * 500); // (0.58, 0.66) -> (790, 830)
glVertex2f((0.52f + 1) * 500, (0.66f + 1) * 500); // (0.52, 0.66) -> (760, 830)
glVertex2f((0.52f + 1) * 500, (0.72f + 1) * 500); // (0.52, 0.72) -> (760, 860)
glVertex2f((0.5f + 1) * 500, (0.69f + 1) * 500);  // (0.5, 0.69) -> (750, 845)
glVertex2f((0.48f + 1) * 500, (0.72f + 1) * 500); // (0.48, 0.72) -> (740, 860)
glVertex2f((0.48f + 1) * 500, (0.66f + 1) * 500); // (0.48, 0.66) -> (740, 830)
glVertex2f((0.42f + 1) * 500, (0.66f + 1) * 500); // (0.42, 0.66) -> (710, 830)
glVertex2f((0.45f + 1) * 500, (0.63f + 1) * 500); // (0.45, 0.63) -> (725, 815)
glVertex2f((0.42f + 1) * 500, (0.6f + 1) * 500);  // (0.42, 0.6) -> (710, 800)
glVertex2f((0.48f + 1) * 500, (0.62f + 1) * 500); // (0.48, 0.62) -> (740, 810)
glEnd();

// Other polygons (converted similarly)
// ... (apply the same transformation to the remaining polygons)

}

void backgroundtree2()
{
    glBegin(GL_POLYGON);
    glColor3ub(125, 85, 0);
    glVertex2f((1.30f + 1) * 500, (0.45f + 1) * 500); // (1.30, 0.45) -> (1150, 725)
    glVertex2f((1.18f + 1) * 500, (0.5f + 1) * 500);  // (1.18, 0.5) -> (1090, 750)
    glVertex2f((1.03f + 1) * 500, (0.56f + 1) * 500); // (1.03, 0.56) -> (1015, 780)
    glVertex2f((0.9f + 1) * 500, (0.6f + 1) * 500);   // (0.9, 0.6) -> (950, 800)
    glVertex2f((0.82f + 1) * 500, (0.64f + 1) * 500); // (0.82, 0.64) -> (910, 820)
    glVertex2f((0.75f + 1) * 500, (0.67f + 1) * 500); // (0.75, 0.67) -> (875, 835)
    glVertex2f((0.78f + 1) * 500, (0.64f + 1) * 500); // (0.78, 0.64) -> (890, 820)
    glVertex2f((0.7f + 1) * 500, (0.6f + 1) * 500);   // (0.7, 0.6) -> (850, 800)
    glVertex2f((0.67f + 1) * 500, (0.56f + 1) * 500); // (0.67, 0.56) -> (835, 780)
    glVertex2f((0.62f + 1) * 500, (0.5f + 1) * 500);  // (0.62, 0.5) -> (810, 750)
    glVertex2f((0.6f + 1) * 500, (0.45f + 1) * 500);  // (0.6, 0.45) -> (800, 725)
    glVertex2f((1.0f + 1) * 500, (0.45f + 1) * 500);  // (1.0, 0.45) -> (1000, 725)
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(125, 85, 0);
    glVertex2f((-0.70f + 1) * 500, (0.45f + 1) * 500); // (-0.70, 0.45) -> (150, 725)
    glVertex2f((-0.64f + 1) * 500, (0.6f + 1) * 500);  // (-0.64, 0.6) -> (180, 800)
    glVertex2f((-0.60f + 1) * 500, (0.66f + 1) * 500); // (-0.60, 0.66) -> (200, 830)
    glVertex2f((-0.56f + 1) * 500, (0.7f + 1) * 500);  // (-0.56, 0.7) -> (220, 850)
    glVertex2f((-0.52f + 1) * 500, (0.8f + 1) * 500);  // (-0.52, 0.8) -> (240, 900)
    glVertex2f((-0.47f + 1) * 500, (0.7f + 1) * 500);  // (-0.47, 0.7) -> (265, 850)
    glVertex2f((-0.42f + 1) * 500, (0.66f + 1) * 500); // (-0.42, 0.66) -> (290, 830)
    glVertex2f((-0.37f + 1) * 500, (0.6f + 1) * 500);  // (-0.37, 0.6) -> (315, 800)
    glVertex2f((-0.35f + 1) * 500, (0.45f + 1) * 500); // (-0.35, 0.45) -> (325, 725)
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(125, 85, 0);
    glVertex2f((0.66f + 1) * 500, (0.45f + 1) * 500); // (0.66, 0.45) -> (830, 725)
    glVertex2f((0.60f + 1) * 500, (0.65f + 1) * 500); // (0.60, 0.65) -> (800, 825)
    glVertex2f((0.54f + 1) * 500, (0.71f + 1) * 500); // (0.54, 0.71) -> (770, 855)
    glVertex2f((0.48f + 1) * 500, (0.75f + 1) * 500); // (0.48, 0.75) -> (740, 875)
    glVertex2f((0.44f + 1) * 500, (0.77f + 1) * 500); // (0.44, 0.77) -> (720, 885)
    glVertex2f((0.38f + 1) * 500, (0.75f + 1) * 500); // (0.38, 0.75) -> (690, 875)
    glVertex2f((0.34f + 1) * 500, (0.71f + 1) * 500); // (0.34, 0.71) -> (670, 855)
    glVertex2f((0.30f + 1) * 500, (0.65f + 1) * 500); // (0.30, 0.65) -> (650, 825)
    glVertex2f((0.25f + 1) * 500, (0.45f + 1) * 500); // (0.25, 0.45) -> (625, 725)
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(125, 85, 0);
    glVertex2f((-0.35f + 1) * 500, (0.45f + 1) * 500); // (-0.35, 0.45) -> (325, 725)
    glVertex2f((-0.33f + 1) * 500, (0.6f + 1) * 500);  // (-0.33, 0.6) -> (335, 800)
    glVertex2f((-0.28f + 1) * 500, (0.66f + 1) * 500); // (-0.28, 0.66) -> (360, 830)
    glVertex2f((-0.25f + 1) * 500, (0.66f + 1) * 500); // (-0.25, 0.66) -> (375, 830)
    glVertex2f((-0.17f + 1) * 500, (0.74f + 1) * 500); // (-0.17, 0.74) -> (415, 870)
    glVertex2f((-0.10f + 1) * 500, (0.77f + 1) * 500); // (-0.10, 0.77) -> (450, 885)
    glVertex2f((0.17f + 1) * 500, (0.74f + 1) * 500);  // (0.17, 0.74) -> (585, 870)
    glVertex2f((0.25f + 1) * 500, (0.7f + 1) * 500);   // (0.25, 0.7) -> (625, 850)
    glVertex2f((0.28f + 1) * 500, (0.6f + 1) * 500);   // (0.28, 0.6) -> (640, 800)
    glVertex2f((0.33f + 1) * 500, (0.6f + 1) * 500);   // (0.33, 0.6) -> (665, 800)
    glVertex2f((0.35f + 1) * 500, (0.45f + 1) * 500);  // (0.35, 0.45) -> (675, 725)
    glEnd();
}

void backgroundtree2N()
{
    glBegin(GL_POLYGON);
   //glColor3ub(50, 35, 0); // Dark brown shadow
   glColor3ub(60, 45, 10); // Darker brown with a slight hint of red


    glVertex2f((1.30f + 1) * 500, (0.45f + 1) * 500); // (1.30, 0.45) -> (1150, 725)
    glVertex2f((1.18f + 1) * 500, (0.5f + 1) * 500);  // (1.18, 0.5) -> (1090, 750)
    glVertex2f((1.03f + 1) * 500, (0.56f + 1) * 500); // (1.03, 0.56) -> (1015, 780)
    glVertex2f((0.9f + 1) * 500, (0.6f + 1) * 500);   // (0.9, 0.6) -> (950, 800)
    glVertex2f((0.82f + 1) * 500, (0.64f + 1) * 500); // (0.82, 0.64) -> (910, 820)
    glVertex2f((0.75f + 1) * 500, (0.67f + 1) * 500); // (0.75, 0.67) -> (875, 835)
    glVertex2f((0.78f + 1) * 500, (0.64f + 1) * 500); // (0.78, 0.64) -> (890, 820)
    glVertex2f((0.7f + 1) * 500, (0.6f + 1) * 500);   // (0.7, 0.6) -> (850, 800)
    glVertex2f((0.67f + 1) * 500, (0.56f + 1) * 500); // (0.67, 0.56) -> (835, 780)
    glVertex2f((0.62f + 1) * 500, (0.5f + 1) * 500);  // (0.62, 0.5) -> (810, 750)
    glVertex2f((0.6f + 1) * 500, (0.45f + 1) * 500);  // (0.6, 0.45) -> (800, 725)
    glVertex2f((1.0f + 1) * 500, (0.45f + 1) * 500);  // (1.0, 0.45) -> (1000, 725)
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(60, 45, 10); // Darker brown with a slight hint of red

    glVertex2f((-0.70f + 1) * 500, (0.45f + 1) * 500); // (-0.70, 0.45) -> (150, 725)
    glVertex2f((-0.64f + 1) * 500, (0.6f + 1) * 500);  // (-0.64, 0.6) -> (180, 800)
    glVertex2f((-0.60f + 1) * 500, (0.66f + 1) * 500); // (-0.60, 0.66) -> (200, 830)
    glVertex2f((-0.56f + 1) * 500, (0.7f + 1) * 500);  // (-0.56, 0.7) -> (220, 850)
    glVertex2f((-0.52f + 1) * 500, (0.8f + 1) * 500);  // (-0.52, 0.8) -> (240, 900)
    glVertex2f((-0.47f + 1) * 500, (0.7f + 1) * 500);  // (-0.47, 0.7) -> (265, 850)
    glVertex2f((-0.42f + 1) * 500, (0.66f + 1) * 500); // (-0.42, 0.66) -> (290, 830)
    glVertex2f((-0.37f + 1) * 500, (0.6f + 1) * 500);  // (-0.37, 0.6) -> (315, 800)
    glVertex2f((-0.35f + 1) * 500, (0.45f + 1) * 500); // (-0.35, 0.45) -> (325, 725)
    glEnd();

    glBegin(GL_POLYGON);
   glColor3ub(60, 45, 10); // Darker brown with a slight hint of red
    glVertex2f((0.66f + 1) * 500, (0.45f + 1) * 500); // (0.66, 0.45) -> (830, 725)
    glVertex2f((0.60f + 1) * 500, (0.65f + 1) * 500); // (0.60, 0.65) -> (800, 825)
    glVertex2f((0.54f + 1) * 500, (0.71f + 1) * 500); // (0.54, 0.71) -> (770, 855)
    glVertex2f((0.48f + 1) * 500, (0.75f + 1) * 500); // (0.48, 0.75) -> (740, 875)
    glVertex2f((0.44f + 1) * 500, (0.77f + 1) * 500); // (0.44, 0.77) -> (720, 885)
    glVertex2f((0.38f + 1) * 500, (0.75f + 1) * 500); // (0.38, 0.75) -> (690, 875)
    glVertex2f((0.34f + 1) * 500, (0.71f + 1) * 500); // (0.34, 0.71) -> (670, 855)
    glVertex2f((0.30f + 1) * 500, (0.65f + 1) * 500); // (0.30, 0.65) -> (650, 825)
    glVertex2f((0.25f + 1) * 500, (0.45f + 1) * 500); // (0.25, 0.45) -> (625, 725)
    glEnd();

    glBegin(GL_POLYGON);
   glColor3ub(60, 45, 10); // Darker brown with a slight hint of red
    glVertex2f((-0.35f + 1) * 500, (0.45f + 1) * 500); // (-0.35, 0.45) -> (325, 725)
    glVertex2f((-0.33f + 1) * 500, (0.6f + 1) * 500);  // (-0.33, 0.6) -> (335, 800)
    glVertex2f((-0.28f + 1) * 500, (0.66f + 1) * 500); // (-0.28, 0.66) -> (360, 830)
    glVertex2f((-0.25f + 1) * 500, (0.66f + 1) * 500); // (-0.25, 0.66) -> (375, 830)
    glVertex2f((-0.17f + 1) * 500, (0.74f + 1) * 500); // (-0.17, 0.74) -> (415, 870)
    glVertex2f((-0.10f + 1) * 500, (0.77f + 1) * 500); // (-0.10, 0.77) -> (450, 885)
    glVertex2f((0.17f + 1) * 500, (0.74f + 1) * 500);  // (0.17, 0.74) -> (585, 870)
    glVertex2f((0.25f + 1) * 500, (0.7f + 1) * 500);   // (0.25, 0.7) -> (625, 850)
    glVertex2f((0.28f + 1) * 500, (0.6f + 1) * 500);   // (0.28, 0.6) -> (640, 800)
    glVertex2f((0.33f + 1) * 500, (0.6f + 1) * 500);   // (0.33, 0.6) -> (665, 800)
    glVertex2f((0.35f + 1) * 500, (0.45f + 1) * 500);  // (0.35, 0.45) -> (675, 725)
    glEnd();
}



void bird()
{
    int i;

// bird 1
GLfloat mm = (0.182f + 1) * 500 - 475;
GLfloat nn = (0.801f + 1) * 500 - 175;
GLfloat radiusmm = 0.01f * 1000 / 2;
int triangleAmount = 20;
GLfloat twicePi = 2.0f * PI;

glBegin(GL_TRIANGLE_FAN);
glColor3ub(225, 225, 208);
glVertex2f(mm, nn);
for(i = 0; i <= triangleAmount; i++)
{
    glVertex2f(
        mm + (radiusmm * cos(i * twicePi / triangleAmount)),
        nn + (radiusmm * sin(i * twicePi / triangleAmount))
    );
}
glEnd();

glBegin(GL_POLYGON);
glColor3ub(225, 225, 208);
glVertex2f((0.1f + 1) * 500 - 475, (0.8f + 1) * 500 - 175);
glVertex2f((0.11f + 1) * 500 - 475, (0.79f + 1) * 500 - 175);
glVertex2f((0.12f + 1) * 500 - 475, (0.78f + 1) * 500 - 175);
glVertex2f((0.16f + 1) * 500 - 475, (0.77f + 1) * 500 - 175);
glVertex2f((0.19f + 1) * 500 - 475, (0.79f + 1) * 500 - 175);
glVertex2f((0.201f + 1) * 500 - 475, (0.8f + 1) * 500 - 175);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(217, 217, 217);
glVertex2f((0.175f + 1) * 500 - 475, (0.8f + 1) * 500 - 175);
glVertex2f((0.15f + 1) * 500 - 475, (0.8f + 1) * 500 - 175);
glVertex2f((0.14f + 1) * 500 - 475, (0.84f + 1) * 500 - 175);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(242, 242, 242);
glVertex2f((0.175f + 1) * 500 - 475, (0.8f + 1) * 500 - 175);
glVertex2f((0.144f + 1) * 500 - 475, (0.8f + 1) * 500 - 175);
glVertex2f((0.12f + 1) * 500 - 475, (0.83f + 1) * 500 - 175);
glEnd();





// bird 2
// bird 2
GLfloat mm1= (0.182f + 1) * 500 + 50 - 475;
GLfloat nn1= (0.801f + 1) * 500 - 175;
GLfloat radiusmm1 = 0.01f * 1000 / 2;
int triangleAmount1 = 20;
GLfloat twicePi1 = 2.0f * PI;

glBegin(GL_TRIANGLE_FAN);
glColor3ub(225, 225, 208);
glVertex2f(mm1, nn1);
for(i = 0; i <= triangleAmount1; i++)
{
    glVertex2f(
        mm1 + (radiusmm1 * cos(i *  twicePi1 / triangleAmount1)),
        nn1 + (radiusmm1 * sin(i * twicePi1 / triangleAmount1))
    );
}
glEnd();

glBegin(GL_POLYGON);
glColor3ub(225, 225, 208);
glVertex2f((0.1f + 1) * 500 + 50 - 475, (0.8f + 1) * 500 - 175);
glVertex2f((0.11f + 1) * 500 + 50 - 475, (0.79f + 1) * 500 - 175);
glVertex2f((0.12f + 1) * 500 + 50 - 475, (0.78f + 1) * 500 - 175);
glVertex2f((0.16f + 1) * 500 + 50 - 475, (0.77f + 1) * 500 - 175);
glVertex2f((0.19f + 1) * 500 + 50 - 475, (0.79f + 1) * 500 - 175);
glVertex2f((0.201f + 1) * 500 + 50 - 475, (0.8f + 1) * 500 - 175);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(217, 217, 217);
glVertex2f((0.175f + 1) * 500 + 50 - 475, (0.8f + 1) * 500 - 175);
glVertex2f((0.15f + 1) * 500 + 50 - 475, (0.8f + 1) * 500 - 175);
glVertex2f((0.14f + 1) * 500 + 50 - 475, (0.84f + 1) * 500 - 175);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(242, 242, 242);
glVertex2f((0.175f + 1) * 500 + 50 - 475, (0.8f + 1) * 500 - 175);
glVertex2f((0.144f + 1) * 500 + 50 - 475, (0.8f + 1) * 500 - 175);
glVertex2f((0.12f + 1) * 500 + 50 - 475, (0.83f + 1) * 500 - 175);
glEnd();



// bird 3
GLfloat mm2 = (0.182f + 1) * 500 + 50 - 25 - 475;
GLfloat nn2 = (0.801f + 1) * 500 - 50 - 175;
GLfloat radiusmm2 = 0.01f * 1000 / 2;
int triangleAmount2 = 20;
GLfloat twicePi2 = 2.0f * PI;

glBegin(GL_TRIANGLE_FAN);
glColor3ub(225, 225, 208);
glVertex2f(mm2, nn2);
for(i = 0; i <= triangleAmount2; i++)
{
    glVertex2f(
        mm2 + (radiusmm2 * cos(i * twicePi2 / triangleAmount2)),
        nn2 + (radiusmm2 * sin(i * twicePi2 / triangleAmount2))
    );
}
glEnd();

glBegin(GL_POLYGON);
glColor3ub(225, 225, 208);
glVertex2f((0.1f + 1) * 500 + 50 - 25 - 475, (0.8f + 1) * 500 - 50 - 175);
glVertex2f((0.11f + 1) * 500 + 50 - 25 - 475, (0.79f + 1) * 500 - 50 - 175);
glVertex2f((0.12f + 1) * 500 + 50 - 25 - 475, (0.78f + 1) * 500 - 50 - 175);
glVertex2f((0.16f + 1) * 500 + 50 - 25 - 475, (0.77f + 1) * 500 - 50 - 175);
glVertex2f((0.19f + 1) * 500 + 50 - 25 - 475, (0.79f + 1) * 500 - 50 - 175);
glVertex2f((0.201f + 1) * 500 + 50 - 25 - 475, (0.8f + 1) * 500 - 50 - 175);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(217, 217, 217);
glVertex2f((0.175f + 1) * 500 + 50 - 25 - 475, (0.8f + 1) * 500 - 50 - 175);
glVertex2f((0.15f + 1) * 500 + 50 - 25 - 475, (0.8f + 1) * 500 - 50 - 175);
glVertex2f((0.14f + 1) * 500 + 50 - 25 - 475, (0.84f + 1) * 500 - 50 - 175);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(242, 242, 242);
glVertex2f((0.175f + 1) * 500 + 50 - 25 - 475, (0.8f + 1) * 500 - 50 - 175);
glVertex2f((0.144f + 1) * 500 + 50 - 25 - 475, (0.8f + 1) * 500 - 50 - 175);
glVertex2f((0.12f + 1) * 500 + 50 - 25 - 475, (0.83f + 1) * 500 - 50 - 175);
glEnd();




}



void birdN()
{
    int i;

// bird 1
GLfloat mm = (0.182f + 1) * 500 - 475;
GLfloat nn = (0.801f + 1) * 500 - 175;
GLfloat radiusmm = 0.01f * 1000 / 2;
int triangleAmount = 20;
GLfloat twicePi = 2.0f * PI;

glBegin(GL_TRIANGLE_FAN);
glColor3ub(120, 120, 110); // Dark Warm Gray
glVertex2f(mm, nn);
for(i = 0; i <= triangleAmount; i++)
{
    glVertex2f(
        mm + (radiusmm * cos(i * twicePi / triangleAmount)),
        nn + (radiusmm * sin(i * twicePi / triangleAmount))
    );
}
glEnd();

glBegin(GL_POLYGON);
glColor3ub(120, 120, 110); // Dark Warm Gray
glVertex2f((0.1f + 1) * 500 - 475, (0.8f + 1) * 500 - 175);
glVertex2f((0.11f + 1) * 500 - 475, (0.79f + 1) * 500 - 175);
glVertex2f((0.12f + 1) * 500 - 475, (0.78f + 1) * 500 - 175);
glVertex2f((0.16f + 1) * 500 - 475, (0.77f + 1) * 500 - 175);
glVertex2f((0.19f + 1) * 500 - 475, (0.79f + 1) * 500 - 175);
glVertex2f((0.201f + 1) * 500 - 475, (0.8f + 1) * 500 - 175);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(115, 115, 110); // Medium Dark Gray
glVertex2f((0.175f + 1) * 500 - 475, (0.8f + 1) * 500 - 175);
glVertex2f((0.15f + 1) * 500 - 475, (0.8f + 1) * 500 - 175);
glVertex2f((0.14f + 1) * 500 - 475, (0.84f + 1) * 500 - 175);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(180, 180, 180); // Soft Dark Gray
glVertex2f((0.175f + 1) * 500 - 475, (0.8f + 1) * 500 - 175);
glVertex2f((0.144f + 1) * 500 - 475, (0.8f + 1) * 500 - 175);
glVertex2f((0.12f + 1) * 500 - 475, (0.83f + 1) * 500 - 175);
glEnd();





// bird 2
// bird 2
GLfloat mm1= (0.182f + 1) * 500 + 50 - 475;
GLfloat nn1= (0.801f + 1) * 500 - 175;
GLfloat radiusmm1 = 0.01f * 1000 / 2;
int triangleAmount1 = 20;
GLfloat twicePi1 = 2.0f * PI;

glBegin(GL_TRIANGLE_FAN);
glColor3ub(120, 120, 110); // Dark Warm Gray
glVertex2f(mm1, nn1);
for(i = 0; i <= triangleAmount1; i++)
{
    glVertex2f(
        mm1 + (radiusmm1 * cos(i *  twicePi1 / triangleAmount1)),
        nn1 + (radiusmm1 * sin(i * twicePi1 / triangleAmount1))
    );
}
glEnd();

glBegin(GL_POLYGON);
glColor3ub(120, 120, 110); // Dark Warm Gray
glVertex2f((0.1f + 1) * 500 + 50 - 475, (0.8f + 1) * 500 - 175);
glVertex2f((0.11f + 1) * 500 + 50 - 475, (0.79f + 1) * 500 - 175);
glVertex2f((0.12f + 1) * 500 + 50 - 475, (0.78f + 1) * 500 - 175);
glVertex2f((0.16f + 1) * 500 + 50 - 475, (0.77f + 1) * 500 - 175);
glVertex2f((0.19f + 1) * 500 + 50 - 475, (0.79f + 1) * 500 - 175);
glVertex2f((0.201f + 1) * 500 + 50 - 475, (0.8f + 1) * 500 - 175);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(115, 115, 110); // Medium Dark Gray
glVertex2f((0.175f + 1) * 500 + 50 - 475, (0.8f + 1) * 500 - 175);
glVertex2f((0.15f + 1) * 500 + 50 - 475, (0.8f + 1) * 500 - 175);
glVertex2f((0.14f + 1) * 500 + 50 - 475, (0.84f + 1) * 500 - 175);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(180, 180, 180); // Soft Dark Gray
glVertex2f((0.175f + 1) * 500 + 50 - 475, (0.8f + 1) * 500 - 175);
glVertex2f((0.144f + 1) * 500 + 50 - 475, (0.8f + 1) * 500 - 175);
glVertex2f((0.12f + 1) * 500 + 50 - 475, (0.83f + 1) * 500 - 175);
glEnd();



// bird 3
GLfloat mm2 = (0.182f + 1) * 500 + 50 - 25 - 475;
GLfloat nn2 = (0.801f + 1) * 500 - 50 - 175;
GLfloat radiusmm2 = 0.01f * 1000 / 2;
int triangleAmount2 = 20;
GLfloat twicePi2 = 2.0f * PI;

glBegin(GL_TRIANGLE_FAN);
glColor3ub(120, 120, 110); // Dark Warm Gray
glVertex2f(mm2, nn2);
for(i = 0; i <= triangleAmount2; i++)
{
    glVertex2f(
        mm2 + (radiusmm2 * cos(i * twicePi2 / triangleAmount2)),
        nn2 + (radiusmm2 * sin(i * twicePi2 / triangleAmount2))
    );
}
glEnd();

glBegin(GL_POLYGON);
glColor3ub(120, 120, 110); // Dark Warm Gray
glVertex2f((0.1f + 1) * 500 + 50 - 25 - 475, (0.8f + 1) * 500 - 50 - 175);
glVertex2f((0.11f + 1) * 500 + 50 - 25 - 475, (0.79f + 1) * 500 - 50 - 175);
glVertex2f((0.12f + 1) * 500 + 50 - 25 - 475, (0.78f + 1) * 500 - 50 - 175);
glVertex2f((0.16f + 1) * 500 + 50 - 25 - 475, (0.77f + 1) * 500 - 50 - 175);
glVertex2f((0.19f + 1) * 500 + 50 - 25 - 475, (0.79f + 1) * 500 - 50 - 175);
glVertex2f((0.201f + 1) * 500 + 50 - 25 - 475, (0.8f + 1) * 500 - 50 - 175);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(115, 115, 110); // Medium Dark Gray
glVertex2f((0.175f + 1) * 500 + 50 - 25 - 475, (0.8f + 1) * 500 - 50 - 175);
glVertex2f((0.15f + 1) * 500 + 50 - 25 - 475, (0.8f + 1) * 500 - 50 - 175);
glVertex2f((0.14f + 1) * 500 + 50 - 25 - 475, (0.84f + 1) * 500 - 50 - 175);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(180, 180, 180); // Soft Dark Gray
glVertex2f((0.175f + 1) * 500 + 50 - 25 - 475, (0.8f + 1) * 500 - 50 - 175);
glVertex2f((0.144f + 1) * 500 + 50 - 25 - 475, (0.8f + 1) * 500 - 50 - 175);
glVertex2f((0.12f + 1) * 500 + 50 - 25 - 475, (0.83f + 1) * 500 - 50 - 175);
glEnd();




}



void road1()
{
glColor3f(0.0f, 0.6f, 0.6f);  // Turquoise glacial water
    glBegin(GL_POLYGON);
    glVertex2d(0, 0);     // +100 to y
    glVertex2d(1000, 0);  // +100 to y
    glVertex2d(1000, 240);  // +100 to y
    glVertex2d(0, 240);     // +100 to y
    glEnd();

    // car road
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2d(0, 100);     // +100 to y
    glVertex2d(1000, 100);  // +100 to y
    glVertex2d(1000, 210);  // +100 to y
    glVertex2d(0, 210);     // +100 to y
    glEnd();

    glColor3ub(105, 105, 105);
    glBegin(GL_POLYGON);
    glVertex2d(0, 100);     // +100 to y
    glVertex2d(1000, 100);  // +100 to y
    glVertex2d(1000, 200);  // +100 to y
    glVertex2d(0, 200);     // +100 to y
    glEnd();

    // White road markings
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2d(30, 140);   // +100 to y
    glVertex2d(100, 140);  // +100 to y
    glVertex2d(100, 160);  // +100 to y
    glVertex2d(30, 160);   // +100 to y
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2d(130, 140);  // +100 to y
    glVertex2d(200, 140);  // +100 to y
    glVertex2d(200, 160);  // +100 to y
    glVertex2d(130, 160);  // +100 to y
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2d(230, 140);  // +100 to y
    glVertex2d(300, 140);  // +100 to y
    glVertex2d(300, 160);  // +100 to y
    glVertex2d(230, 160);  // +100 to y
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2d(330, 140);  // +100 to y
    glVertex2d(400, 140);  // +100 to y
    glVertex2d(400, 160);  // +100 to y
    glVertex2d(330, 160);  // +100 to y
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2d(430, 140);  // +100 to y
    glVertex2d(500, 140);  // +100 to y
    glVertex2d(500, 160);  // +100 to y
    glVertex2d(430, 160);  // +100 to y
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2d(530, 140);  // +100 to y
    glVertex2d(600, 140);  // +100 to y
    glVertex2d(600, 160);  // +100 to y
    glVertex2d(530, 160);  // +100 to y
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2d(630, 140);  // +100 to y
    glVertex2d(700, 140);  // +100 to y
    glVertex2d(700, 160);  // +100 to y
    glVertex2d(630, 160);  // +100 to y
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2d(730, 140);  // +100 to y
    glVertex2d(800, 140);  // +100 to y
    glVertex2d(800, 160);  // +100 to y
    glVertex2d(730, 160);  // +100 to y
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2d(830, 140);  // +100 to y
    glVertex2d(900, 140);  // +100 to y
    glVertex2d(900, 160);  // +100 to y
    glVertex2d(830, 160);  // +100 to y
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2d(930, 140);  // +100 to y
    glVertex2d(1000, 140); // +100 to y
    glVertex2d(1000, 160); // +100 to y
    glVertex2d(930, 160);  // +100 to y
    glEnd();
}


void road1N()
{
glColor3f(0.0f, 0.2f, 0.2f); // Deep Dark Teal
  // Turquoise glacial water
    glBegin(GL_POLYGON);
    glVertex2d(0, 0);     // +100 to y
    glVertex2d(1000, 0);  // +100 to y
    glVertex2d(1000, 240);  // +100 to y
    glVertex2d(0, 240);     // +100 to y
    glEnd();

    // car road
glColor3ub(100, 100, 100); // Dark Gray
    glBegin(GL_POLYGON);
    glVertex2d(0, 100);     // +100 to y
    glVertex2d(1000, 100);  // +100 to y
    glVertex2d(1000, 210);  // +100 to y
    glVertex2d(0, 210);     // +100 to y
    glEnd();

glColor3ub(60, 60, 60); // Dark Gray
    glBegin(GL_POLYGON);
    glVertex2d(0, 100);     // +100 to y
    glVertex2d(1000, 100);  // +100 to y
    glVertex2d(1000, 200);  // +100 to y
    glVertex2d(0, 200);     // +100 to y
    glEnd();

    // White road markings
glColor3ub(100, 100, 100); // Dark Gray
    glBegin(GL_POLYGON);
    glVertex2d(30, 140);   // +100 to y
    glVertex2d(100, 140);  // +100 to y
    glVertex2d(100, 160);  // +100 to y
    glVertex2d(30, 160);   // +100 to y
    glEnd();

glColor3ub(100, 100, 100); // Dark Gray
    glBegin(GL_POLYGON);
    glVertex2d(130, 140);  // +100 to y
    glVertex2d(200, 140);  // +100 to y
    glVertex2d(200, 160);  // +100 to y
    glVertex2d(130, 160);  // +100 to y
    glEnd();

glColor3ub(100, 100, 100); // Dark Gray
    glBegin(GL_POLYGON);
    glVertex2d(230, 140);  // +100 to y
    glVertex2d(300, 140);  // +100 to y
    glVertex2d(300, 160);  // +100 to y
    glVertex2d(230, 160);  // +100 to y
    glEnd();

glColor3ub(100, 100, 100); // Dark Gray
    glBegin(GL_POLYGON);
    glVertex2d(330, 140);  // +100 to y
    glVertex2d(400, 140);  // +100 to y
    glVertex2d(400, 160);  // +100 to y
    glVertex2d(330, 160);  // +100 to y
    glEnd();

glColor3ub(100, 100, 100); // Dark Gray
    glBegin(GL_POLYGON);
    glVertex2d(430, 140);  // +100 to y
    glVertex2d(500, 140);  // +100 to y
    glVertex2d(500, 160);  // +100 to y
    glVertex2d(430, 160);  // +100 to y
    glEnd();

glColor3ub(100, 100, 100); // Dark Gray
    glBegin(GL_POLYGON);
    glVertex2d(530, 140);  // +100 to y
    glVertex2d(600, 140);  // +100 to y
    glVertex2d(600, 160);  // +100 to y
    glVertex2d(530, 160);  // +100 to y
    glEnd();

glColor3ub(100, 100, 100); // Dark Gray
    glBegin(GL_POLYGON);
    glVertex2d(630, 140);  // +100 to y
    glVertex2d(700, 140);  // +100 to y
    glVertex2d(700, 160);  // +100 to y
    glVertex2d(630, 160);  // +100 to y
    glEnd();

glColor3ub(100, 100, 100); // Dark Gray
    glBegin(GL_POLYGON);
    glVertex2d(730, 140);  // +100 to y
    glVertex2d(800, 140);  // +100 to y
    glVertex2d(800, 160);  // +100 to y
    glVertex2d(730, 160);  // +100 to y
    glEnd();

glColor3ub(100, 100, 100); // Dark Gray
    glBegin(GL_POLYGON);
    glVertex2d(830, 140);  // +100 to y
    glVertex2d(900, 140);  // +100 to y
    glVertex2d(900, 160);  // +100 to y
    glVertex2d(830, 160);  // +100 to y
    glEnd();

glColor3ub(100, 100, 100); // Dark Gray
    glBegin(GL_POLYGON);
    glVertex2d(930, 140);  // +100 to y
    glVertex2d(1000, 140); // +100 to y
    glVertex2d(1000, 160); // +100 to y
    glVertex2d(930, 160);  // +100 to y
    glEnd();
}




void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{
    glBegin(GL_POLYGON);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.1416 / 180;
        float x = rx * cos(angle);
        float y = ry * sin(angle);
        glVertex2f((x + cx), (y + cy));
    }
    glEnd();
}


void treeDouble()
{
    // back tree
    glColor3ub(139, 69, 19);
    glBegin(GL_POLYGON);
    glVertex2d(75 * 2, 180 * 2);  // (150, 360)
    glVertex2d(85 * 2, 180 * 2);  // (170, 360)
    glVertex2d(85 * 2, 350 * 2);  // (170, 700)
    glVertex2d(75 * 2, 350 * 2);  // (150, 700)
    glEnd();

    glColor3ub(0, 128, 0);

    circle(30 * 2, 40 * 2, 85 * 2, 370 * 2);
    circle(20 * 2, 30 * 2, 90 * 2, 340 * 2);
    circle(20 * 2, 30 * 2, 65 * 2, 395 * 2);

    // forward tree
    glColor3ub(0, 100, 0);
    circle(40 * 2, 50 * 2, 45 * 2, 360 * 2);
    glColor3ub(0, 100, 0);
    circle(30 * 2, 30 * 2, 60 * 2, 330 * 2);
    circle(20 * 2, 30 * 2, 30 * 2, 300 * 2);
    circle(20 * 2, 30 * 2, 60 * 2, 300 * 2);

    glColor3ub(139, 69, 19);
    glBegin(GL_POLYGON);
    glVertex2d(40 * 2, 180 * 2);   // (80, 360)
    glVertex2d(50 * 2, 180 * 2);   // (100, 360)
    glVertex2d(50 * 2, 296 * 2);   // (100, 592)
    glVertex2d(60 * 2, 320 * 2);   // (120, 640)
    glVertex2d(55 * 2, 326 * 2);   // (110, 652)
    glVertex2d(50 * 2, 300 * 2);   // (100, 600)
    glVertex2d(50 * 2, 350 * 2);   // (100, 700)
    glVertex2d(45 * 2, 350 * 2);   // (90, 700)
    glVertex2d(45 * 2, 310 * 2);   // (90, 620)
    glEnd();

    //////////////////////////right side


}



void treeDoubleN()
{
    // back tree
glColor3ub(70, 34, 0); // Dark brown shadow
    glBegin(GL_POLYGON);
    glVertex2d(75 * 2, 180 * 2);  // (150, 360)
    glVertex2d(85 * 2, 180 * 2);  // (170, 360)
    glVertex2d(85 * 2, 350 * 2);  // (170, 700)
    glVertex2d(75 * 2, 350 * 2);  // (150, 700)
    glEnd();

   glColor3ub(0, 48, 0); // Deeper shadow with a more muted green

    circle(30 * 2, 40 * 2, 85 * 2, 370 * 2);
    circle(20 * 2, 30 * 2, 90 * 2, 340 * 2);
    circle(20 * 2, 30 * 2, 65 * 2, 395 * 2);

    // forward tree
  glColor3ub(0, 40, 0); // Even darker green shadow for more depth
    circle(40 * 2, 50 * 2, 45 * 2, 360 * 2);
glColor3ub(0, 40, 0); // Even darker green shadow for more depth
    circle(30 * 2, 30 * 2, 60 * 2, 330 * 2);
    circle(20 * 2, 30 * 2, 30 * 2, 300 * 2);
    circle(20 * 2, 30 * 2, 60 * 2, 300 * 2);

glColor3ub(70, 34, 0); // Dark brown shadow
    glBegin(GL_POLYGON);
    glVertex2d(40 * 2, 180 * 2);   // (80, 360)
    glVertex2d(50 * 2, 180 * 2);   // (100, 360)
    glVertex2d(50 * 2, 296 * 2);   // (100, 592)
    glVertex2d(60 * 2, 320 * 2);   // (120, 640)
    glVertex2d(55 * 2, 326 * 2);   // (110, 652)
    glVertex2d(50 * 2, 300 * 2);   // (100, 600)
    glVertex2d(50 * 2, 350 * 2);   // (100, 700)
    glVertex2d(45 * 2, 350 * 2);   // (90, 700)
    glVertex2d(45 * 2, 310 * 2);   // (90, 620)
    glEnd();

    //////////////////////////right side


}

void treeDouble2()
{
// Back tree
glColor3ub(139, 69, 19);
glBegin(GL_POLYGON);
glVertex2d(((75 * 2 + 700 + 80) * 0.85) + 150, ((180 * 2) * 0.85) + 50);  // Adjusted y-coordinate
glVertex2d(((85 * 2 + 700 + 80) * 0.85) + 150, ((180 * 2) * 0.85) + 50);  // Adjusted y-coordinate
glVertex2d(((85 * 2 + 700 + 80) * 0.85) + 150, ((350 * 2) * 0.85) + 50);  // Adjusted y-coordinate
glVertex2d(((75 * 2 + 700 + 80) * 0.85) + 150, ((350 * 2) * 0.85) + 50);  // Adjusted y-coordinate
glEnd();

glColor3ub(0, 128, 0);
circle(30 * 2 * 0.85, 40 * 2 * 0.85, ((85 * 2 + 700 + 80) * 0.85) + 150, ((370 * 2) * 0.85) + 50);  // Adjusted y-coordinate
circle(20 * 2 * 0.85, 30 * 2 * 0.85, ((90 * 2 + 700 + 80) * 0.85) + 150, ((340 * 2) * 0.85) + 50);  // Adjusted y-coordinate
circle(20 * 2 * 0.85, 30 * 2 * 0.85, ((65 * 2 + 700 + 80) * 0.85) + 150, ((395 * 2) * 0.85) + 50);  // Adjusted y-coordinate

// Forward tree
glColor3ub(0, 100, 0);
circle(40 * 2 * 0.85, 50 * 2 * 0.85, ((45 * 2 + 700 + 80) * 0.85) + 150, ((360 * 2) * 0.85) + 50);  // Adjusted y-coordinate
glColor3ub(0, 100, 0);
circle(30 * 2 * 0.85, 30 * 2 * 0.85, ((60 * 2 + 700 + 80) * 0.85) + 150, ((330 * 2) * 0.85) + 50);  // Adjusted y-coordinate
circle(20 * 2 * 0.85, 30 * 2 * 0.85, ((30 * 2 + 700 + 80) * 0.85) + 150, ((300 * 2) * 0.85) + 50);  // Adjusted y-coordinate
circle(20 * 2 * 0.85, 30 * 2 * 0.85, ((60 * 2 + 700 + 80) * 0.85) + 150, ((300 * 2) * 0.85) + 50);  // Adjusted y-coordinate

glColor3ub(139, 69, 19);
glBegin(GL_POLYGON);
glVertex2d(((40 * 2 + 700 + 80) * 0.85) + 150, ((180 * 2) * 0.85) + 50);   // Adjusted y-coordinate
glVertex2d(((50 * 2 + 700 + 80) * 0.85) + 150, ((180 * 2) * 0.85) + 50);   // Adjusted y-coordinate
glVertex2d(((50 * 2 + 700 + 80) * 0.85) + 150, ((296 * 2) * 0.85) + 50);   // Adjusted y-coordinate
glVertex2d(((60 * 2 + 700 + 80) * 0.85) + 150, ((320 * 2) * 0.85) + 50);   // Adjusted y-coordinate
glVertex2d(((55 * 2 + 700 + 80) * 0.85) + 150, ((326 * 2) * 0.85) + 50);   // Adjusted y-coordinate
glVertex2d(((50 * 2 + 700 + 80) * 0.85) + 150, ((300 * 2) * 0.85) + 50);   // Adjusted y-coordinate
glVertex2d(((50 * 2 + 700 + 80) * 0.85) + 150, ((350 * 2) * 0.85) + 50);   // Adjusted y-coordinate
glVertex2d(((45 * 2 + 700 + 80) * 0.85) + 150, ((350 * 2) * 0.85) + 50);   // Adjusted y-coordinate
glVertex2d(((45 * 2 + 700 + 80) * 0.85) + 150, ((310 * 2) * 0.85) + 50);   // Adjusted y-coordinate
glEnd();




}


void treeDouble2N()
{
// Back tree
glColor3ub(70, 34, 0); // Dark brown shadow
glBegin(GL_POLYGON);
glVertex2d(((75 * 2 + 700 + 80) * 0.85) + 150, ((180 * 2) * 0.85) + 50);  // Adjusted y-coordinate
glVertex2d(((85 * 2 + 700 + 80) * 0.85) + 150, ((180 * 2) * 0.85) + 50);  // Adjusted y-coordinate
glVertex2d(((85 * 2 + 700 + 80) * 0.85) + 150, ((350 * 2) * 0.85) + 50);  // Adjusted y-coordinate
glVertex2d(((75 * 2 + 700 + 80) * 0.85) + 150, ((350 * 2) * 0.85) + 50);  // Adjusted y-coordinate
glEnd();

   glColor3ub(0, 48, 0); // Deeper shadow with a more muted green
circle(30 * 2 * 0.85, 40 * 2 * 0.85, ((85 * 2 + 700 + 80) * 0.85) + 150, ((370 * 2) * 0.85) + 50);  // Adjusted y-coordinate
circle(20 * 2 * 0.85, 30 * 2 * 0.85, ((90 * 2 + 700 + 80) * 0.85) + 150, ((340 * 2) * 0.85) + 50);  // Adjusted y-coordinate
circle(20 * 2 * 0.85, 30 * 2 * 0.85, ((65 * 2 + 700 + 80) * 0.85) + 150, ((395 * 2) * 0.85) + 50);  // Adjusted y-coordinate

// Forward tree
glColor3ub(0, 40, 0); // Even darker green shadow for more depth
circle(40 * 2 * 0.85, 50 * 2 * 0.85, ((45 * 2 + 700 + 80) * 0.85) + 150, ((360 * 2) * 0.85) + 50);  // Adjusted y-coordinate
glColor3ub(0, 40, 0); // Even darker green shadow for more depth
circle(30 * 2 * 0.85, 30 * 2 * 0.85, ((60 * 2 + 700 + 80) * 0.85) + 150, ((330 * 2) * 0.85) + 50);  // Adjusted y-coordinate
circle(20 * 2 * 0.85, 30 * 2 * 0.85, ((30 * 2 + 700 + 80) * 0.85) + 150, ((300 * 2) * 0.85) + 50);  // Adjusted y-coordinate
circle(20 * 2 * 0.85, 30 * 2 * 0.85, ((60 * 2 + 700 + 80) * 0.85) + 150, ((300 * 2) * 0.85) + 50);  // Adjusted y-coordinate

glColor3ub(70, 34, 0); // Dark brown shadow
glBegin(GL_POLYGON);
glVertex2d(((40 * 2 + 700 + 80) * 0.85) + 150, ((180 * 2) * 0.85) + 50);   // Adjusted y-coordinate
glVertex2d(((50 * 2 + 700 + 80) * 0.85) + 150, ((180 * 2) * 0.85) + 50);   // Adjusted y-coordinate
glVertex2d(((50 * 2 + 700 + 80) * 0.85) + 150, ((296 * 2) * 0.85) + 50);   // Adjusted y-coordinate
glVertex2d(((60 * 2 + 700 + 80) * 0.85) + 150, ((320 * 2) * 0.85) + 50);   // Adjusted y-coordinate
glVertex2d(((55 * 2 + 700 + 80) * 0.85) + 150, ((326 * 2) * 0.85) + 50);   // Adjusted y-coordinate
glVertex2d(((50 * 2 + 700 + 80) * 0.85) + 150, ((300 * 2) * 0.85) + 50);   // Adjusted y-coordinate
glVertex2d(((50 * 2 + 700 + 80) * 0.85) + 150, ((350 * 2) * 0.85) + 50);   // Adjusted y-coordinate
glVertex2d(((45 * 2 + 700 + 80) * 0.85) + 150, ((350 * 2) * 0.85) + 50);   // Adjusted y-coordinate
glVertex2d(((45 * 2 + 700 + 80) * 0.85) + 150, ((310 * 2) * 0.85) + 50);   // Adjusted y-coordinate
glEnd();




}

void Bushes()
{
// 1st Bushes
// 1st Bushes
// 1st Bushes
glColor3ub(154, 205, 50);
circle(40, 60, 40, 360 * 0.65);  // Reduced the angle size
circle(40, 60, 80, 420 * 0.65);
circle(40, 60, 120, 360 * 0.65);//120,234

// 2nd Bushes
glColor3ub(154, 205, 50);
circle(40, 60, 860, 360 * 0.65);
circle(40, 60, 900, 420 * 0.65);
circle(40, 60, 940, 360 * 0.65);

// 3rd Bushes
glColor3ub(120, 128, 0);
circle(40, 60, 980, 360 * 0.65);
circle(40, 60, 1020, 420 * 0.65);


}

void BushesN()
{
// 1st Bushes
// 1st Bushes
// 1st Bushes
glColor3ub(77, 102, 25); // Dark Olive Green (Darker Shadow of Yellow-Green)
circle(40, 60, 40, 360 * 0.65);  // Reduced the angle size
circle(40, 60, 80, 420 * 0.65);
circle(40, 60, 120, 360 * 0.65);//120,234

// 2nd Bushes
glColor3ub(77, 102, 25); // Dark Olive Green (Darker Shadow of Yellow-Green)
circle(40, 60, 860, 360 * 0.65);
circle(40, 60, 900, 420 * 0.65);
circle(40, 60, 940, 360 * 0.65);

// 3rd Bushes
glColor3ub(40, 45, 0); // Very dark muted green shadow
circle(40, 60, 980, 360 * 0.65);
circle(40, 60, 1020, 420 * 0.65);


}

void flower() {
// Right side flowers
// Right side flowers
glColor3ub(255, 0, 0);
circle(6, 10, 900, 420 - 100);  // Adjusted y-coordinate
circle(6, 10, 910, 410 - 100);  // Adjusted y-coordinate
circle(6, 10, 910, 430 - 100);  // Adjusted y-coordinate
circle(6, 10, 920, 420 - 100);  // Adjusted y-coordinate
glColor3ub(255, 215, 0);
circle(6, 10, 910, 420 - 100);  // Adjusted y-coordinate

glColor3ub(255, 0, 0);
circle(6, 10, 880, 390 - 100);  // Adjusted y-coordinate
circle(6, 10, 880, 370 - 100);  // Adjusted y-coordinate
circle(6, 10, 870, 380 - 100);  // Adjusted y-coordinate
circle(6, 10, 890, 380 - 100);  // Adjusted y-coordinate
glColor3ub(255, 215, 0);
circle(6, 10, 880, 380 - 100);  // Adjusted y-coordinate

glColor3ub(255, 0, 0);
circle(6, 10, 940, 390 - 100);  // Adjusted y-coordinate
circle(6, 10, 940, 370 - 100);  // Adjusted y-coordinate
circle(6, 10, 930, 380 - 100);  // Adjusted y-coordinate
circle(6, 10, 950, 380 - 100);  // Adjusted y-coordinate
glColor3ub(255, 215, 0);
circle(6, 10, 940, 380 - 100);  // Adjusted y-coordinate

// Left side flowers
glColor3ub(255, 0, 0);
circle(6, 10, 60, 410 - 100);   // Adjusted y-coordinate
circle(6, 10, 60, 390 - 100);   // Adjusted y-coordinate
circle(6, 10, 50, 400 - 100);   // Adjusted y-coordinate
circle(6, 10, 70, 400 - 100);   // Adjusted y-coordinate
glColor3ub(255, 215, 0);
circle(6, 10, 60, 400 - 100);   // Adjusted y-coordinate

glColor3ub(255, 215, 0);
circle(6, 10, 20, 430 - 100);   // Adjusted y-coordinate
circle(6, 10, 20, 410 - 100);   // Adjusted y-coordinate
circle(6, 10, 10, 420 - 100);   // Adjusted y-coordinate
circle(6, 10, 30, 420 - 100);   // Adjusted y-coordinate
glColor3ub(255, 0, 0);
circle(6, 10, 20, 420 - 100);
}



void flowerN() {
// Right side flowers
// Right side flowers
glColor3ub(90, 0, 0); // Very Dark Red
circle(6, 10, 900, 420 - 100);  // Adjusted y-coordinate
circle(6, 10, 910, 410 - 100);  // Adjusted y-coordinate
circle(6, 10, 910, 430 - 100);  // Adjusted y-coordinate
circle(6, 10, 920, 420 - 100);  // Adjusted y-coordinate
glColor3ub(102, 86, 0); // Deep Dark Gold
circle(6, 10, 910, 420 - 100);  // Adjusted y-coordinate

glColor3ub(90, 0, 0); // Very Dark Red
circle(6, 10, 880, 390 - 100);  // Adjusted y-coordinate
circle(6, 10, 880, 370 - 100);  // Adjusted y-coordinate
circle(6, 10, 870, 380 - 100);  // Adjusted y-coordinate
circle(6, 10, 890, 380 - 100);  // Adjusted y-coordinate
glColor3ub(102, 86, 0); // Deep Dark Gold
circle(6, 10, 880, 380 - 100);  // Adjusted y-coordinate

glColor3ub(90, 0, 0); // Very Dark Red
circle(6, 10, 940, 390 - 100);  // Adjusted y-coordinate
circle(6, 10, 940, 370 - 100);  // Adjusted y-coordinate
circle(6, 10, 930, 380 - 100);  // Adjusted y-coordinate
circle(6, 10, 950, 380 - 100);  // Adjusted y-coordinate
glColor3ub(102, 86, 0); // Deep Dark Gold
circle(6, 10, 940, 380 - 100);  // Adjusted y-coordinate

// Left side flowers
glColor3ub(90, 0, 0); // Very Dark Red
circle(6, 10, 60, 410 - 100);   // Adjusted y-coordinate
circle(6, 10, 60, 390 - 100);   // Adjusted y-coordinate
circle(6, 10, 50, 400 - 100);   // Adjusted y-coordinate
circle(6, 10, 70, 400 - 100);   // Adjusted y-coordinate
glColor3ub(102, 86, 0); // Deep Dark Gold
circle(6, 10, 60, 400 - 100);   // Adjusted y-coordinate

glColor3ub(102, 86, 0); // Deep Dark Gold
circle(6, 10, 20, 430 - 100);   // Adjusted y-coordinate
circle(6, 10, 20, 410 - 100);   // Adjusted y-coordinate
circle(6, 10, 10, 420 - 100);   // Adjusted y-coordinate
circle(6, 10, 30, 420 - 100);   // Adjusted y-coordinate
glColor3ub(255, 0, 0);
circle(6, 10, 20, 420 - 100);
}





void stars()
{
    glPointSize(2.5);
    glBegin(GL_POINTS);
    glColor3ub(255, 255, 255);

    // Convert each vertex from (-1, 1) to (0, 1000)
    glVertex2f((0.8f + 1) * 500, (0.95f + 1) * 500);
    glVertex2f((0.9f + 1) * 500, (0.9f + 1) * 500);
    glVertex2f((0.95f + 1) * 500, (0.7f + 1) * 500);
    glVertex2f((0.8f + 1) * 500, (0.8f + 1) * 500);
    glVertex2f((0.7f + 1) * 500, (0.9f + 1) * 500);
    glVertex2f((0.6f + 1) * 500, (0.8f + 1) * 500);
    glVertex2f((0.5f + 1) * 500, (0.75f + 1) * 500);
    glVertex2f((0.4f + 1) * 500, (0.9f + 1) * 500);
    glVertex2f((0.3f + 1) * 500, (0.7f + 1) * 500);
    glVertex2f((0.25f + 1) * 500, (0.9f + 1) * 500);
    glVertex2f((0.25f + 1) * 500, (0.7f + 1) * 500);
    glVertex2f((0.1f + 1) * 500, (0.9f + 1) * 500);
    glVertex2f((0.15f + 1) * 500, (0.75f + 1) * 500);
    glVertex2f((0.0f + 1) * 500, (0.8f + 1) * 500);
    glVertex2f((-0.7f + 1) * 500, (0.9f + 1) * 500);
    glVertex2f((-0.8f + 1) * 500, (0.95f + 1) * 500);
    glVertex2f((-0.4f + 1) * 500, (0.8f + 1) * 500);
    glVertex2f((-0.8f + 1) * 500, (0.95f + 1) * 500);
    glVertex2f((-0.9f + 1) * 500, (0.9f + 1) * 500);
    glVertex2f((-0.95f + 1) * 500, (0.7f + 1) * 500);
    glVertex2f((-0.8f + 1) * 500, (0.8f + 1) * 500);
    glVertex2f((-0.7f + 1) * 500, (0.9f + 1) * 500);
    glVertex2f((-0.6f + 1) * 500, (0.8f + 1) * 500);
    glVertex2f((-0.5f + 1) * 500, (0.75f + 1) * 500);
    glVertex2f((-0.4f + 1) * 500, (0.9f + 1) * 500);
    glVertex2f((-0.3f + 1) * 500, (0.7f + 1) * 500);
    glVertex2f((-0.25f + 1) * 500, (0.9f + 1) * 500);
    glVertex2f((-0.25f + 1) * 500, (0.7f + 1) * 500);
    glVertex2f((-0.15f + 1) * 500, (0.75f + 1) * 500);
    glVertex2f((-0.1f + 1) * 500, (0.9f + 1) * 500);

    glEnd();
}


void moon()
{
    int i;
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;

    // Convert coordinates and radius for the first circle (blue part)
    GLfloat xx = ((-0.5f + 1) / 2) * 1000; // x-coordinate mapped to (0, 1000)
    GLfloat yx = ((0.93f + 1) / 2) * 1000; // y-coordinate mapped to (0, 1000)
    GLfloat radiusx = 0.06f * 500;  // Radius scaled

    // Draw the first circle (blue part)
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 51, 204); // Blue color
    glVertex2f(xx, yx); // Center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            xx + (radiusx * cos(i * twicePi / triangleAmount)),
            yx + (radiusx * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    // Convert coordinates and radius for the second circle (white part)
    GLfloat x = ((-0.5f + 1) / 2) * 1000; // x-coordinate mapped to (0, 1000)
    GLfloat y = ((0.9f + 1) / 2) * 1000;  // y-coordinate mapped to (0, 1000)
    GLfloat radius = 0.06f * 500;  // Radius scaled

    // Draw the second circle (white part)
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(242, 242, 242); // White color
    glVertex2f(x, y); // Center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}







void grass3N()
{
    glLineWidth(4);
    glBegin(GL_LINES);
glColor3ub(0, 51, 0); // Darker Green Shadow

    // Convert coordinates for lines and adjust for movement
    glVertex2f((-0.05f + 1) * 500 + 370, (-0.35f + 1) * 500 + 50);
    glVertex2f((0.0f + 1) * 500 + 370, (-0.4f + 1) * 500 + 50);

    glVertex2f((0.05f + 1) * 500 + 370, (-0.35f + 1) * 500 + 50);
    glVertex2f((0.0f + 1) * 500 + 370, (-0.4f + 1) * 500 + 50);

    glVertex2f((0.027f + 1) * 500 + 370, (-0.33f + 1) * 500 + 50);
    glVertex2f((0.0f + 1) * 500 + 370, (-0.4f + 1) * 500 + 50);

    glVertex2f((-0.027f + 1) * 500 + 370, (-0.33f + 1) * 500 + 50);
    glVertex2f((0.0f + 1) * 500 + 370, (-0.4f + 1) * 500 + 50);

    glVertex2f((0.0f + 1) * 500 + 370, (-0.3f + 1) * 500 + 50);
    glVertex2f((0.0f + 1) * 500 + 370, (-0.4f + 1) * 500 + 50);

    glVertex2f((-0.075f + 1) * 500 + 370, (-0.37f + 1) * 500 + 50);
    glVertex2f((0.0f + 1) * 500 + 370, (-0.4f + 1) * 500 + 50);

    glVertex2f((0.0745f + 1) * 500 + 370, (-0.37f + 1) * 500 + 50);
    glVertex2f((0.0f + 1) * 500 + 370, (-0.4f + 1) * 500 + 50);

    glEnd();

    int i;
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;

    // Convert coordinates and radius for the first circle (red) and adjust for movement
    GLfloat e = (-0.05f + 1) * 500 + 370;
    GLfloat f = (-0.35f + 1) * 500 + 50;
    GLfloat radius11 = 0.02f * 500;

    glBegin(GL_TRIANGLE_FAN);
glColor3ub(90, 18, 0); // Muted Dark Red Shadow
    glVertex2f(e, f); // Center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            e + (radius11 * cos(i * twicePi / triangleAmount)),
            f + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    // Convert coordinates and radius for the second circle (purple) and adjust for movement
    GLfloat g = (0.05f + 1) * 500 + 370;
    GLfloat h = (-0.35f + 1) * 500 + 50;

    glBegin(GL_TRIANGLE_FAN);
glColor3ub(30, 20, 40); // Muted Dark Purple Shadow
    glVertex2f(g, h); // Center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            g + (radius11 * cos(i * twicePi / triangleAmount)),
            h + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    // Convert coordinates and radius for the third circle (yellow) and adjust for movement
    GLfloat a1 = (0.0f + 1) * 500 + 370;
    GLfloat b1 = (-0.3f + 1) * 500 + 50;

    glBegin(GL_TRIANGLE_FAN);
glColor3ub(150, 130, 0); // Muted Orange-Yellow Shadow
    glVertex2f(a1, b1); // Center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            a1 + (radius11 * cos(i * twicePi / triangleAmount)),
            b1 + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

void grass4N()
{
    glLineWidth(4);
    glBegin(GL_LINES);
glColor3ub(0, 51, 0); // Darker Green Shadow

    // Convert coordinates for lines and adjust for movement
    glVertex2f((-0.05f + 1) * 500 + 390, (-0.35f + 1) * 500 + 150);
    glVertex2f((0.0f + 1) * 500 + 390, (-0.4f + 1) * 500 + 150);

    glVertex2f((0.05f + 1) * 500 + 390, (-0.35f + 1) * 500 + 150);
    glVertex2f((0.0f + 1) * 500 + 390, (-0.4f + 1) * 500 + 150);

    glVertex2f((0.027f + 1) * 500 + 390, (-0.33f + 1) * 500 + 150);
    glVertex2f((0.0f + 1) * 500 + 390, (-0.4f + 1) * 500 + 150);

    glVertex2f((-0.027f + 1) * 500 + 390, (-0.33f + 1) * 500 + 150);
    glVertex2f((0.0f + 1) * 500 + 390, (-0.4f + 1) * 500 + 150);

    glVertex2f((0.0f + 1) * 500 + 390, (-0.3f + 1) * 500 + 150);
    glVertex2f((0.0f + 1) * 500 + 390, (-0.4f + 1) * 500 + 150);

    glVertex2f((-0.075f + 1) * 500 + 390, (-0.37f + 1) * 500 + 150);
    glVertex2f((0.0f + 1) * 500 + 390, (-0.4f + 1) * 500 + 150);

    glVertex2f((0.0745f + 1) * 500 + 390, (-0.37f + 1) * 500 + 150);
    glVertex2f((0.0f + 1) * 500 + 390, (-0.4f + 1) * 500 + 150);

    glEnd();

    int i;
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;

    // Convert coordinates and radius for the first circle (red) and adjust for movement
    GLfloat e = (-0.05f + 1) * 500 + 390;
    GLfloat f = (-0.35f + 1) * 500 + 150;
    GLfloat radius11 = 0.02f * 500;

    glBegin(GL_TRIANGLE_FAN);
glColor3ub(90, 18, 0); // Muted Dark Red Shadow
    glVertex2f(e, f); // Center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            e + (radius11 * cos(i * twicePi / triangleAmount)),
            f + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    // Convert coordinates and radius for the second circle (purple) and adjust for movement
    GLfloat g = (0.05f + 1) * 500 + 390;
    GLfloat h = (-0.35f + 1) * 500 + 150;

    glBegin(GL_TRIANGLE_FAN);
glColor3ub(30, 20, 40); // Muted Dark Purple Shadow
    glVertex2f(g, h); // Center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            g + (radius11 * cos(i * twicePi / triangleAmount)),
            h + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    // Convert coordinates and radius for the third circle (yellow) and adjust for movement
    GLfloat a1 = (0.0f + 1) * 500 + 390;
    GLfloat b1 = (-0.3f + 1) * 500 + 150;

    glBegin(GL_TRIANGLE_FAN);
glColor3ub(150, 130, 0); // Muted Orange-Yellow Shadow
    glVertex2f(a1, b1); // Center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            a1 + (radius11 * cos(i * twicePi / triangleAmount)),
            b1 + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}



void grass5N()
{
    glLineWidth(4);
    glBegin(GL_LINES);
glColor3ub(0, 51, 0); // Darker Green Shadow

    // Convert coordinates for lines and adjust for movement
    glVertex2f((-0.05f + 1) * 500 + 420, (-0.35f + 1) * 500 + 30);
    glVertex2f((0.0f + 1) * 500 + 420, (-0.4f + 1) * 500 + 30);

    glVertex2f((0.05f + 1) * 500 + 420, (-0.35f + 1) * 500 + 30);
    glVertex2f((0.0f + 1) * 500 + 420, (-0.4f + 1) * 500 + 30);

    glVertex2f((0.027f + 1) * 500 + 420, (-0.33f + 1) * 500 + 30);
    glVertex2f((0.0f + 1) * 500 + 420, (-0.4f + 1) * 500 + 30);

    glVertex2f((-0.027f + 1) * 500 + 420, (-0.33f + 1) * 500 + 30);
    glVertex2f((0.0f + 1) * 500 + 420, (-0.4f + 1) * 500 + 30);

    glVertex2f((0.0f + 1) * 500 + 420, (-0.3f + 1) * 500 + 30);
    glVertex2f((0.0f + 1) * 500 + 420, (-0.4f + 1) * 500 + 30);

    glVertex2f((-0.075f + 1) * 500 + 420, (-0.37f + 1) * 500 + 30);
    glVertex2f((0.0f + 1) * 500 + 420, (-0.4f + 1) * 500 + 30);

    glVertex2f((0.0745f + 1) * 500 + 420, (-0.37f + 1) * 500 + 30);
    glVertex2f((0.0f + 1) * 500 + 420, (-0.4f + 1) * 500 + 30);

    glEnd();

    int i;
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;

    // Convert coordinates and radius for the first circle (red) and adjust for movement
    GLfloat e = (-0.05f + 1) * 500 + 420;
    GLfloat f = (-0.35f + 1) * 500 + 30;
    GLfloat radius11 = 0.02f * 500;

    glBegin(GL_TRIANGLE_FAN);
glColor3ub(90, 18, 0); // Muted Dark Red Shadow
    glVertex2f(e, f); // Center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            e + (radius11 * cos(i * twicePi / triangleAmount)),
            f + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    // Convert coordinates and radius for the second circle (purple) and adjust for movement
    GLfloat g = (0.05f + 1) * 500 + 420;
    GLfloat h = (-0.35f + 1) * 500 + 30;

    glBegin(GL_TRIANGLE_FAN);
glColor3ub(30, 20, 40); // Muted Dark Purple Shadow
    glVertex2f(g, h); // Center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            g + (radius11 * cos(i * twicePi / triangleAmount)),
            h + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    // Convert coordinates and radius for the third circle (yellow) and adjust for movement
    GLfloat a1 = (0.0f + 1) * 500 + 420;
    GLfloat b1 = (-0.3f + 1) * 500 + 30;

    glBegin(GL_TRIANGLE_FAN);
glColor3ub(150, 130, 0); // Muted Orange-Yellow Shadow
    glVertex2f(a1, b1); // Center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            a1 + (radius11 * cos(i * twicePi / triangleAmount)),
            b1 + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}



void grass6N()
{
    glLineWidth(4);
    glBegin(GL_LINES);
glColor3ub(0, 51, 0); // Darker Green Shadow

    // Convert coordinates for lines and adjust for movement
    glVertex2f((-0.05f + 1) * 500 + 390 + 30, (-0.35f + 1) * 500 + 150 + 30);
    glVertex2f((0.0f + 1) * 500 + 390 + 30, (-0.4f + 1) * 500 + 150 + 30);

    glVertex2f((0.05f + 1) * 500 + 390 + 30, (-0.35f + 1) * 500 + 150 + 30);
    glVertex2f((0.0f + 1) * 500 + 390 + 30, (-0.4f + 1) * 500 + 150 + 30);

    glVertex2f((0.027f + 1) * 500 + 390 + 30, (-0.33f + 1) * 500 + 150 + 30);
    glVertex2f((0.0f + 1) * 500 + 390 + 30, (-0.4f + 1) * 500 + 150 + 30);

    glVertex2f((-0.027f + 1) * 500 + 390 + 30, (-0.33f + 1) * 500 + 150 + 30);
    glVertex2f((0.0f + 1) * 500 + 390 + 30, (-0.4f + 1) * 500 + 150 + 30);

    glVertex2f((0.0f + 1) * 500 + 390 + 30, (-0.3f + 1) * 500 + 150 + 30);
    glVertex2f((0.0f + 1) * 500 + 390 + 30, (-0.4f + 1) * 500 + 150 + 30);

    glVertex2f((-0.075f + 1) * 500 + 390 + 30, (-0.37f + 1) * 500 + 150 + 30);
    glVertex2f((0.0f + 1) * 500 + 390 + 30, (-0.4f + 1) * 500 + 150 + 30);

    glVertex2f((0.0745f + 1) * 500 + 390 + 30, (-0.37f + 1) * 500 + 150 + 30);
    glVertex2f((0.0f + 1) * 500 + 390 + 30, (-0.4f + 1) * 500 + 150 + 30);

    glEnd();

    int i;
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;

    // Convert coordinates and radius for the first circle (red) and adjust for movement
    GLfloat e = (-0.05f + 1) * 500 + 390 + 30;
    GLfloat f = (-0.35f + 1) * 500 + 150 + 30;
    GLfloat radius11 = 0.02f * 500;

    glBegin(GL_TRIANGLE_FAN);
glColor3ub(90, 18, 0); // Muted Dark Red Shadow
    glVertex2f(e, f); // Center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            e + (radius11 * cos(i * twicePi / triangleAmount)),
            f + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    // Convert coordinates and radius for the second circle (purple) and adjust for movement
    GLfloat g = (0.05f + 1) * 500 + 390 + 30;
    GLfloat h = (-0.35f + 1) * 500 + 150 + 30;

    glBegin(GL_TRIANGLE_FAN);
glColor3ub(30, 20, 40); // Muted Dark Purple Shadow
    glVertex2f(g, h); // Center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            g + (radius11 * cos(i * twicePi / triangleAmount)),
            h + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    // Convert coordinates and radius for the third circle (yellow) and adjust for movement
    GLfloat a1 = (0.0f + 1) * 500 + 390 + 30;
    GLfloat b1 = (-0.3f + 1) * 500 + 150 + 30;

    glBegin(GL_TRIANGLE_FAN);
glColor3ub(150, 130, 0); // Muted Orange-Yellow Shadow
    glVertex2f(a1, b1); // Center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            a1 + (radius11 * cos(i * twicePi / triangleAmount)),
            b1 + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

void grass8N()
{
    glLineWidth(4);
    glBegin(GL_LINES);
glColor3ub(0, 51, 0); // Darker Green Shadow

    // Adjust coordinates for movement: right by 40 (x-axis) and downward by 40 (y-axis)
    glVertex2f((-0.05f + 1) * 500 + 390 + 30 + 40, (-0.35f + 1) * 500 + 150 + 30 - 40);
    glVertex2f((0.0f + 1) * 500 + 390 + 30 + 40, (-0.4f + 1) * 500 + 150 + 30 - 40);

    glVertex2f((0.05f + 1) * 500 + 390 + 30 + 40, (-0.35f + 1) * 500 + 150 + 30 - 40);
    glVertex2f((0.0f + 1) * 500 + 390 + 30 + 40, (-0.4f + 1) * 500 + 150 + 30 - 40);

    glVertex2f((0.027f + 1) * 500 + 390 + 30 + 40, (-0.33f + 1) * 500 + 150 + 30 - 40);
    glVertex2f((0.0f + 1) * 500 + 390 + 30 + 40, (-0.4f + 1) * 500 + 150 + 30 - 40);

    glVertex2f((-0.027f + 1) * 500 + 390 + 30 + 40, (-0.33f + 1) * 500 + 150 + 30 - 40);
    glVertex2f((0.0f + 1) * 500 + 390 + 30 + 40, (-0.4f + 1) * 500 + 150 + 30 - 40);

    glVertex2f((0.0f + 1) * 500 + 390 + 30 + 40, (-0.3f + 1) * 500 + 150 + 30 - 40);
    glVertex2f((0.0f + 1) * 500 + 390 + 30 + 40, (-0.4f + 1) * 500 + 150 + 30 - 40);

    glVertex2f((-0.075f + 1) * 500 + 390 + 30 + 40, (-0.37f + 1) * 500 + 150 + 30 - 40);
    glVertex2f((0.0f + 1) * 500 + 390 + 30 + 40, (-0.4f + 1) * 500 + 150 + 30 - 40);

    glVertex2f((0.0745f + 1) * 500 + 390 + 30 + 40, (-0.37f + 1) * 500 + 150 + 30 - 40);
    glVertex2f((0.0f + 1) * 500 + 390 + 30 + 40, (-0.4f + 1) * 500 + 150 + 30 - 40);

    glEnd();

    int i;
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;

    // Adjust coordinates for the first circle (red)
    GLfloat e = (-0.05f + 1) * 500 + 390 + 30 + 40;
    GLfloat f = (-0.35f + 1) * 500 + 150 + 30 - 40;
    GLfloat radius11 = 0.02f * 500;

    glBegin(GL_TRIANGLE_FAN);
glColor3ub(90, 18, 0); // Muted Dark Red Shadow
    glVertex2f(e, f); // Center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            e + (radius11 * cos(i * twicePi / triangleAmount)),
            f + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

glColor3ub(30, 20, 40); // Muted Dark Purple Shadow
    GLfloat g = (0.05f + 1) * 500 + 390 + 30 + 40;
    GLfloat h = (-0.35f + 1) * 500 + 150 + 30 - 40;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(79, 58, 118); // Purple color
    glVertex2f(g, h); // Center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            g + (radius11 * cos(i * twicePi / triangleAmount)),
            h + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    // Adjust coordinates for the third circle (yellow)
    GLfloat a1 = (0.0f + 1) * 500 + 390 + 30 + 40;
    GLfloat b1 = (-0.3f + 1) * 500 + 150 + 30 - 40;

    glBegin(GL_TRIANGLE_FAN);
glColor3ub(150, 130, 0); // Muted Orange-Yellow Shadow
    glVertex2f(a1, b1); // Center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            a1 + (radius11 * cos(i * twicePi / triangleAmount)),
            b1 + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}















void grass3()
{
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(0, 102, 0);

    // Convert coordinates for lines and adjust for movement
    glVertex2f((-0.05f + 1) * 500 + 370, (-0.35f + 1) * 500 + 50);
    glVertex2f((0.0f + 1) * 500 + 370, (-0.4f + 1) * 500 + 50);

    glVertex2f((0.05f + 1) * 500 + 370, (-0.35f + 1) * 500 + 50);
    glVertex2f((0.0f + 1) * 500 + 370, (-0.4f + 1) * 500 + 50);

    glVertex2f((0.027f + 1) * 500 + 370, (-0.33f + 1) * 500 + 50);
    glVertex2f((0.0f + 1) * 500 + 370, (-0.4f + 1) * 500 + 50);

    glVertex2f((-0.027f + 1) * 500 + 370, (-0.33f + 1) * 500 + 50);
    glVertex2f((0.0f + 1) * 500 + 370, (-0.4f + 1) * 500 + 50);

    glVertex2f((0.0f + 1) * 500 + 370, (-0.3f + 1) * 500 + 50);
    glVertex2f((0.0f + 1) * 500 + 370, (-0.4f + 1) * 500 + 50);

    glVertex2f((-0.075f + 1) * 500 + 370, (-0.37f + 1) * 500 + 50);
    glVertex2f((0.0f + 1) * 500 + 370, (-0.4f + 1) * 500 + 50);

    glVertex2f((0.0745f + 1) * 500 + 370, (-0.37f + 1) * 500 + 50);
    glVertex2f((0.0f + 1) * 500 + 370, (-0.4f + 1) * 500 + 50);

    glEnd();

    int i;
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;

    // Convert coordinates and radius for the first circle (red) and adjust for movement
    GLfloat e = (-0.05f + 1) * 500 + 370;
    GLfloat f = (-0.35f + 1) * 500 + 50;
    GLfloat radius11 = 0.02f * 500;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 51, 0); // Red color
    glVertex2f(e, f); // Center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            e + (radius11 * cos(i * twicePi / triangleAmount)),
            f + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    // Convert coordinates and radius for the second circle (purple) and adjust for movement
    GLfloat g = (0.05f + 1) * 500 + 370;
    GLfloat h = (-0.35f + 1) * 500 + 50;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(79, 58, 118); // Purple color
    glVertex2f(g, h); // Center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            g + (radius11 * cos(i * twicePi / triangleAmount)),
            h + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    // Convert coordinates and radius for the third circle (yellow) and adjust for movement
    GLfloat a1 = (0.0f + 1) * 500 + 370;
    GLfloat b1 = (-0.3f + 1) * 500 + 50;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 0); // Yellow color
    glVertex2f(a1, b1); // Center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            a1 + (radius11 * cos(i * twicePi / triangleAmount)),
            b1 + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

void grass4()
{
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(0, 102, 0);

    // Convert coordinates for lines and adjust for movement
    glVertex2f((-0.05f + 1) * 500 + 390, (-0.35f + 1) * 500 + 150);
    glVertex2f((0.0f + 1) * 500 + 390, (-0.4f + 1) * 500 + 150);

    glVertex2f((0.05f + 1) * 500 + 390, (-0.35f + 1) * 500 + 150);
    glVertex2f((0.0f + 1) * 500 + 390, (-0.4f + 1) * 500 + 150);

    glVertex2f((0.027f + 1) * 500 + 390, (-0.33f + 1) * 500 + 150);
    glVertex2f((0.0f + 1) * 500 + 390, (-0.4f + 1) * 500 + 150);

    glVertex2f((-0.027f + 1) * 500 + 390, (-0.33f + 1) * 500 + 150);
    glVertex2f((0.0f + 1) * 500 + 390, (-0.4f + 1) * 500 + 150);

    glVertex2f((0.0f + 1) * 500 + 390, (-0.3f + 1) * 500 + 150);
    glVertex2f((0.0f + 1) * 500 + 390, (-0.4f + 1) * 500 + 150);

    glVertex2f((-0.075f + 1) * 500 + 390, (-0.37f + 1) * 500 + 150);
    glVertex2f((0.0f + 1) * 500 + 390, (-0.4f + 1) * 500 + 150);

    glVertex2f((0.0745f + 1) * 500 + 390, (-0.37f + 1) * 500 + 150);
    glVertex2f((0.0f + 1) * 500 + 390, (-0.4f + 1) * 500 + 150);

    glEnd();

    int i;
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;

    // Convert coordinates and radius for the first circle (red) and adjust for movement
    GLfloat e = (-0.05f + 1) * 500 + 390;
    GLfloat f = (-0.35f + 1) * 500 + 150;
    GLfloat radius11 = 0.02f * 500;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 51, 0); // Red color
    glVertex2f(e, f); // Center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            e + (radius11 * cos(i * twicePi / triangleAmount)),
            f + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    // Convert coordinates and radius for the second circle (purple) and adjust for movement
    GLfloat g = (0.05f + 1) * 500 + 390;
    GLfloat h = (-0.35f + 1) * 500 + 150;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(79, 58, 118); // Purple color
    glVertex2f(g, h); // Center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            g + (radius11 * cos(i * twicePi / triangleAmount)),
            h + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    // Convert coordinates and radius for the third circle (yellow) and adjust for movement
    GLfloat a1 = (0.0f + 1) * 500 + 390;
    GLfloat b1 = (-0.3f + 1) * 500 + 150;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 0); // Yellow color
    glVertex2f(a1, b1); // Center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            a1 + (radius11 * cos(i * twicePi / triangleAmount)),
            b1 + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}



void grass5()
{
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(0, 102, 0);

    // Convert coordinates for lines and adjust for movement
    glVertex2f((-0.05f + 1) * 500 + 420, (-0.35f + 1) * 500 + 30);
    glVertex2f((0.0f + 1) * 500 + 420, (-0.4f + 1) * 500 + 30);

    glVertex2f((0.05f + 1) * 500 + 420, (-0.35f + 1) * 500 + 30);
    glVertex2f((0.0f + 1) * 500 + 420, (-0.4f + 1) * 500 + 30);

    glVertex2f((0.027f + 1) * 500 + 420, (-0.33f + 1) * 500 + 30);
    glVertex2f((0.0f + 1) * 500 + 420, (-0.4f + 1) * 500 + 30);

    glVertex2f((-0.027f + 1) * 500 + 420, (-0.33f + 1) * 500 + 30);
    glVertex2f((0.0f + 1) * 500 + 420, (-0.4f + 1) * 500 + 30);

    glVertex2f((0.0f + 1) * 500 + 420, (-0.3f + 1) * 500 + 30);
    glVertex2f((0.0f + 1) * 500 + 420, (-0.4f + 1) * 500 + 30);

    glVertex2f((-0.075f + 1) * 500 + 420, (-0.37f + 1) * 500 + 30);
    glVertex2f((0.0f + 1) * 500 + 420, (-0.4f + 1) * 500 + 30);

    glVertex2f((0.0745f + 1) * 500 + 420, (-0.37f + 1) * 500 + 30);
    glVertex2f((0.0f + 1) * 500 + 420, (-0.4f + 1) * 500 + 30);

    glEnd();

    int i;
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;

    // Convert coordinates and radius for the first circle (red) and adjust for movement
    GLfloat e = (-0.05f + 1) * 500 + 420;
    GLfloat f = (-0.35f + 1) * 500 + 30;
    GLfloat radius11 = 0.02f * 500;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 51, 0); // Red color
    glVertex2f(e, f); // Center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            e + (radius11 * cos(i * twicePi / triangleAmount)),
            f + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    // Convert coordinates and radius for the second circle (purple) and adjust for movement
    GLfloat g = (0.05f + 1) * 500 + 420;
    GLfloat h = (-0.35f + 1) * 500 + 30;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(79, 58, 118); // Purple color
    glVertex2f(g, h); // Center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            g + (radius11 * cos(i * twicePi / triangleAmount)),
            h + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    // Convert coordinates and radius for the third circle (yellow) and adjust for movement
    GLfloat a1 = (0.0f + 1) * 500 + 420;
    GLfloat b1 = (-0.3f + 1) * 500 + 30;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 0); // Yellow color
    glVertex2f(a1, b1); // Center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            a1 + (radius11 * cos(i * twicePi / triangleAmount)),
            b1 + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}



void grass6()
{
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(0, 102, 0);

    // Convert coordinates for lines and adjust for movement
    glVertex2f((-0.05f + 1) * 500 + 390 + 30, (-0.35f + 1) * 500 + 150 + 30);
    glVertex2f((0.0f + 1) * 500 + 390 + 30, (-0.4f + 1) * 500 + 150 + 30);

    glVertex2f((0.05f + 1) * 500 + 390 + 30, (-0.35f + 1) * 500 + 150 + 30);
    glVertex2f((0.0f + 1) * 500 + 390 + 30, (-0.4f + 1) * 500 + 150 + 30);

    glVertex2f((0.027f + 1) * 500 + 390 + 30, (-0.33f + 1) * 500 + 150 + 30);
    glVertex2f((0.0f + 1) * 500 + 390 + 30, (-0.4f + 1) * 500 + 150 + 30);

    glVertex2f((-0.027f + 1) * 500 + 390 + 30, (-0.33f + 1) * 500 + 150 + 30);
    glVertex2f((0.0f + 1) * 500 + 390 + 30, (-0.4f + 1) * 500 + 150 + 30);

    glVertex2f((0.0f + 1) * 500 + 390 + 30, (-0.3f + 1) * 500 + 150 + 30);
    glVertex2f((0.0f + 1) * 500 + 390 + 30, (-0.4f + 1) * 500 + 150 + 30);

    glVertex2f((-0.075f + 1) * 500 + 390 + 30, (-0.37f + 1) * 500 + 150 + 30);
    glVertex2f((0.0f + 1) * 500 + 390 + 30, (-0.4f + 1) * 500 + 150 + 30);

    glVertex2f((0.0745f + 1) * 500 + 390 + 30, (-0.37f + 1) * 500 + 150 + 30);
    glVertex2f((0.0f + 1) * 500 + 390 + 30, (-0.4f + 1) * 500 + 150 + 30);

    glEnd();

    int i;
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;

    // Convert coordinates and radius for the first circle (red) and adjust for movement
    GLfloat e = (-0.05f + 1) * 500 + 390 + 30;
    GLfloat f = (-0.35f + 1) * 500 + 150 + 30;
    GLfloat radius11 = 0.02f * 500;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 51, 0); // Red color
    glVertex2f(e, f); // Center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            e + (radius11 * cos(i * twicePi / triangleAmount)),
            f + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    // Convert coordinates and radius for the second circle (purple) and adjust for movement
    GLfloat g = (0.05f + 1) * 500 + 390 + 30;
    GLfloat h = (-0.35f + 1) * 500 + 150 + 30;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(79, 58, 118); // Purple color
    glVertex2f(g, h); // Center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            g + (radius11 * cos(i * twicePi / triangleAmount)),
            h + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    // Convert coordinates and radius for the third circle (yellow) and adjust for movement
    GLfloat a1 = (0.0f + 1) * 500 + 390 + 30;
    GLfloat b1 = (-0.3f + 1) * 500 + 150 + 30;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 0); // Yellow color
    glVertex2f(a1, b1); // Center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            a1 + (radius11 * cos(i * twicePi / triangleAmount)),
            b1 + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}




void grass8()
{
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(0, 102, 0);

    // Adjust coordinates for movement: right by 40 (x-axis) and downward by 40 (y-axis)
    glVertex2f((-0.05f + 1) * 500 + 390 + 30 + 40, (-0.35f + 1) * 500 + 150 + 30 - 40);
    glVertex2f((0.0f + 1) * 500 + 390 + 30 + 40, (-0.4f + 1) * 500 + 150 + 30 - 40);

    glVertex2f((0.05f + 1) * 500 + 390 + 30 + 40, (-0.35f + 1) * 500 + 150 + 30 - 40);
    glVertex2f((0.0f + 1) * 500 + 390 + 30 + 40, (-0.4f + 1) * 500 + 150 + 30 - 40);

    glVertex2f((0.027f + 1) * 500 + 390 + 30 + 40, (-0.33f + 1) * 500 + 150 + 30 - 40);
    glVertex2f((0.0f + 1) * 500 + 390 + 30 + 40, (-0.4f + 1) * 500 + 150 + 30 - 40);

    glVertex2f((-0.027f + 1) * 500 + 390 + 30 + 40, (-0.33f + 1) * 500 + 150 + 30 - 40);
    glVertex2f((0.0f + 1) * 500 + 390 + 30 + 40, (-0.4f + 1) * 500 + 150 + 30 - 40);

    glVertex2f((0.0f + 1) * 500 + 390 + 30 + 40, (-0.3f + 1) * 500 + 150 + 30 - 40);
    glVertex2f((0.0f + 1) * 500 + 390 + 30 + 40, (-0.4f + 1) * 500 + 150 + 30 - 40);

    glVertex2f((-0.075f + 1) * 500 + 390 + 30 + 40, (-0.37f + 1) * 500 + 150 + 30 - 40);
    glVertex2f((0.0f + 1) * 500 + 390 + 30 + 40, (-0.4f + 1) * 500 + 150 + 30 - 40);

    glVertex2f((0.0745f + 1) * 500 + 390 + 30 + 40, (-0.37f + 1) * 500 + 150 + 30 - 40);
    glVertex2f((0.0f + 1) * 500 + 390 + 30 + 40, (-0.4f + 1) * 500 + 150 + 30 - 40);

    glEnd();

    int i;
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;

    // Adjust coordinates for the first circle (red)
    GLfloat e = (-0.05f + 1) * 500 + 390 + 30 + 40;
    GLfloat f = (-0.35f + 1) * 500 + 150 + 30 - 40;
    GLfloat radius11 = 0.02f * 500;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 51, 0); // Red color
    glVertex2f(e, f); // Center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            e + (radius11 * cos(i * twicePi / triangleAmount)),
            f + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    // Adjust coordinates for the second circle (purple)
    GLfloat g = (0.05f + 1) * 500 + 390 + 30 + 40;
    GLfloat h = (-0.35f + 1) * 500 + 150 + 30 - 40;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(79, 58, 118); // Purple color
    glVertex2f(g, h); // Center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            g + (radius11 * cos(i * twicePi / triangleAmount)),
            h + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    // Adjust coordinates for the third circle (yellow)
    GLfloat a1 = (0.0f + 1) * 500 + 390 + 30 + 40;
    GLfloat b1 = (-0.3f + 1) * 500 + 150 + 30 - 40;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 0); // Yellow color
    glVertex2f(a1, b1); // Center of circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            a1 + (radius11 * cos(i * twicePi / triangleAmount)),
            b1 + (radius11 * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}













void roadLight()
{
    // Scale factor for increasing size by 15%
    float scale = 1.15;

    // Move upward by 120 units
    float moveUp = 120;

    // Black pole (scaled and moved upward)
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2d(80 * scale, (50 * scale) + moveUp);
    glVertex2d(85 * scale, (50 * scale) + moveUp);
    glVertex2d(85 * scale, (180 * scale) + moveUp);
    glVertex2d(80 * scale, (180 * scale) + moveUp);
    glEnd();

    // Black horizontal bar (scaled and moved upward)
    glBegin(GL_POLYGON);
    glVertex2d(65 * scale, (150 * scale) + moveUp);
    glVertex2d(100 * scale, (150 * scale) + moveUp);
    glVertex2d(100 * scale, (155 * scale) + moveUp);
    glVertex2d(65 * scale, (155 * scale) + moveUp);
    glEnd();

    // White light (scaled and moved upward)
    glColor3ub(255, 255, 255);
    circle(10 * scale, 15 * scale, 83 * scale, (180 * scale) + moveUp);
}



void roadLight3()
{
    // Scale factor for increasing size by 15%
    float scale = 1.15;

    // Move upward by 120 units
    float moveUp = 120;

    // Move right by 400 + 400 units (along x-axis)
    float moveRight = 400 + 400; // Now moving 800 units to the right

    // Black pole (scaled and moved upward)
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2d((80 * scale) + moveRight, (50 * scale) + moveUp);
    glVertex2d((85 * scale) + moveRight, (50 * scale) + moveUp);
    glVertex2d((85 * scale) + moveRight, (180 * scale) + moveUp);
    glVertex2d((80 * scale) + moveRight, (180 * scale) + moveUp);
    glEnd();

    // Black horizontal bar (scaled and moved upward)
    glBegin(GL_POLYGON);
    glVertex2d((65 * scale) + moveRight, (150 * scale) + moveUp);
    glVertex2d((100 * scale) + moveRight, (150 * scale) + moveUp);
    glVertex2d((100 * scale) + moveRight, (155 * scale) + moveUp);
    glVertex2d((65 * scale) + moveRight, (155 * scale) + moveUp);
    glEnd();

    // White light (scaled and moved upward)
    glColor3ub(255, 255, 255);
    circle(10 * scale, 15 * scale, (83 * scale) + moveRight, (180 * scale) + moveUp);
}


void roadLightN()
{
    // Scale factor for increasing size by 15%
    float scale = 1.15;

    // Move upward by 120 units
    float moveUp = 120;

    // Black pole (scaled and moved upward)
glColor3ub(10, 10, 10); // Very dark gray shadow
    glBegin(GL_POLYGON);
    glVertex2d(80 * scale, (50 * scale) + moveUp);
    glVertex2d(85 * scale, (50 * scale) + moveUp);
    glVertex2d(85 * scale, (180 * scale) + moveUp);
    glVertex2d(80 * scale, (180 * scale) + moveUp);
    glEnd();

    // Black horizontal bar (scaled and moved upward)
    glBegin(GL_POLYGON);
    glVertex2d(65 * scale, (150 * scale) + moveUp);
    glVertex2d(100 * scale, (150 * scale) + moveUp);
    glVertex2d(100 * scale, (155 * scale) + moveUp);
    glVertex2d(65 * scale, (155 * scale) + moveUp);
    glEnd();

    // White light (scaled and moved upward)
glColor3f(0.8f, 0.7f, 0.2f); // Soft yellow light
    circle(10 * scale, 15 * scale, 83 * scale, (180 * scale) + moveUp);
}




void roadLight3N()
{
    // Scale factor for increasing size by 15%
    float scale = 1.15;

    // Move upward by 120 units
    float moveUp = 120;

    // Move right by 400 + 400 units (along x-axis)
    float moveRight = 400 + 400; // Now moving 800 units to the right

    // Black pole (scaled and moved upward)
glColor3ub(10, 10, 10); // Very dark gray shadow
    glBegin(GL_POLYGON);
    glVertex2d((80 * scale) + moveRight, (50 * scale) + moveUp);
    glVertex2d((85 * scale) + moveRight, (50 * scale) + moveUp);
    glVertex2d((85 * scale) + moveRight, (180 * scale) + moveUp);
    glVertex2d((80 * scale) + moveRight, (180 * scale) + moveUp);
    glEnd();

    // Black horizontal bar (scaled and moved upward)
    glBegin(GL_POLYGON);
    glVertex2d((65 * scale) + moveRight, (150 * scale) + moveUp);
    glVertex2d((100 * scale) + moveRight, (150 * scale) + moveUp);
    glVertex2d((100 * scale) + moveRight, (155 * scale) + moveUp);
    glVertex2d((65 * scale) + moveRight, (155 * scale) + moveUp);
    glEnd();

    // White light (scaled and moved upward)
glColor3f(0.8f, 0.7f, 0.2f); // Soft yellow light
    circle(10 * scale, 15 * scale, (83 * scale) + moveRight, (180 * scale) + moveUp);
}

void displayDay() {
    //glClearColor(0.5f, 0.5f, 0.5f, 0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)


     sky();
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////sun/circle/////////////////////////////
   glPushMatrix();
    glTranslatef(480.0f, sunPosition, 0.0f);
glColor3f(1.0f, 0.84f, 0.0f);  // Gold (#FFD700)

    drawSun1(0.0f, 0.0f, 35.0f); // last er ta radius
       // drawCircle(sunPosition, 850.0f, 50.0f);

    glutSolidSphere(50.0f, 50, 50); // Sun as a solid sphere
    glPopMatrix();

   // backgroundtree ();


  ////////////////////////////////////////////cloud///////////////////////////

      river1();
      hillsCropland();

       glPushMatrix();
    glTranslatef(boatPosition1, 0.0f, 0.0f); // Move the boat along the x-axis

    boat();

   glPopMatrix();


    //cropland
      cropland();
          backgroundtree2();//hills background -2
          hills2(); //hills front-1


   //  tree2(); //right side ittle tree
  //  tree(); //big tree with birds --left side
      grass3();
    grass4();
    grass5();
     grass6();
     grass8();
    treeDouble();
    treeDouble2();
             Bushes();
     flower();

//    road();






 //drawCycle(position, angle);

    // Set color for airplane
   glColor3f(0.0f, 0.0f, 1.0f);
    drawPlane();
    updateplane();



//??????????????????????????????????????????????????????????????????????//cyCle finish??????????????????????????????????????????
//      hut();
      //tree();

          // drawGrass();
    // grass1();

       // grass2();
              //  grass3();
                   // backgroundtree();




     hut();
     hut2();
    // house1();


        roadLight();
    roadLight3();
     road1();

    glPushMatrix();
    glTranslatef(batPosition,0.0f, 0.0f);
     batMobile();
     glPopMatrix();

          glPushMatrix();
    glTranslatef(birdPosition, 0.0f, 0.0f); // Move the boat along the x-axis
        bird();
       glPopMatrix();



    glPushMatrix();
    glTranslatef(cloudPosition1,0.0f, 0.0f);
    cloud1D();
    cloud2D();
    cloud3D();
    glPopMatrix();
   // glutSwapBuffers();// Render now
}



void displayNight() {
    //glClearColor(0.5f, 0.5f, 0.5f, 0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

       river1N();

            glPushMatrix();
    glTranslatef(boatPosition1, 0.0f, 0.0f); // Move the boat along the x-axis

    boatN();

   glPopMatrix();

     sky1();
     stars();
     moon();

     /* glPushMatrix();
    glTranslatef(480.0f, sunPosition, 0.0f);
glColor3f(1.0f, 0.84f, 0.0f);  // Gold (#FFD700)

    drawSun(0.0f, 0.0f, 35.0f); // last er ta radius
       // drawCircle(sunPosition, 850.0f, 50.0f);

    glutSolidSphere(50.0f, 50, 50); // Sun as a solid sphere
    glPopMatrix(); */

   // backgroundtree ();


  ////////////////////////////////////////////cloud///////////////////////////







     hillsCroplandN();

    //cropland
      croplandN();
          backgroundtree2N();//hills background -2
          hills2N(); //hills front-1


   //  tree2(); //right side ittle tree
  //  tree(); //big tree with birds --left side

   // grass1N();
  //  grass2N();
    grass3N();
    grass4N();
    grass5N();
     grass6N();
   //  grass7N();
   grass8N();
    treeDoubleN();
    treeDouble2N();
             BushesN();
     flowerN();

//    road();






 //drawCycle(position, angle);

    // Set color for airplane
  /* glColor3f(0.0f, 0.0f, 1.0f);
    drawPlane();
    updateplane();*/





          // drawGrass();
    // grass1();

       // grass2();
              //  grass3();
                   // backgroundtree();




     hutN();
     hut2N();
    // house1();
        roadLightN();
    roadLight3N();
     road1N();
    glPushMatrix();
    glTranslatef(batPosition,0.0f, 0.0f);
     batMobile();
     glPopMatrix();

     birdN();

         glPushMatrix();
    glTranslatef(cloudPosition1,0.0f, 0.0f);
    cloud1N();
    cloud2N();
    cloud3N();
    glPopMatrix();
  // grass1N();

}







//boat////////////////
void updateBoat1(int value) {
    if(boatMoving1){
    boatPosition1 -= 3.0f; // Move the boat 1 unit to the right
    if (boatPosition1 <-350.0f) {
        boatPosition1 = 1000.0f; // Reset position when out of bounds
    }
    }
    glutPostRedisplay(); // Redisplay with updated position
    glutTimerFunc(25, updateBoat1, 0); // Call `update` every ~16ms (~60fps)
}

//cycle.............................................

void updateCycle(int value) {
    // Move the cycle to the left (decrease position)
    position -= 5.0f; // Change the position (speed)

    if (position < -400) {
        position = 1000.0f; // Reset position to the right side of the screen
    }

    angle += 5.0f; // Rotate wheels

    glutPostRedisplay();
    glutTimerFunc(25, updateCycle, 0); // Call update every 16ms (~60fps)
}



//sun//////////////////
void updateSun1(int value) {
    if (sunMoving) {
        sunPosition += 1.0f; // Move the sun
        if (sunPosition > 1050.0f) {
            sunPosition = 800.0f; // Reset position when out of bounds
        }
        batPosition+=3.0f;
        if( batPosition > 1235.0f)
        {
            batPosition=-235;
        }
        birdPosition +=3.0f;
        if(birdPosition>1030)
        {
            birdPosition=80.0f;
        }

        glutPostRedisplay(); // Redisplay with updated position
    }
    glutTimerFunc(25, updateSun1, 0); // Call `updateSun` every 25ms
}
//Areful
GLfloat boatPosition = 800.0f;
GLboolean boatMoving=true;
void skyday()
{
glBegin(GL_POLYGON);

glColor3f(0.8f, 0.9f, 1.0f);



glVertex2f(1000,1000);
glVertex2f(1000,750);
glVertex2f(0,750);

glVertex2f(0,1000);
glEnd();
}
void updateClouds1(int value) {
    if(cloudMoving1)
    {


    cloudPosition1 +=1.0f;
    if(cloudPosition1 > 1000)
    {
      cloudPosition1=0;
    }
}
   // position2 += speed2;
	glutPostRedisplay();
	glutTimerFunc(20, updateClouds1, 0);

}

void drawRoad() {
glBegin(GL_POLYGON);
glColor3ub(50, 50, 50);
glVertex2f(0, 350);
glVertex2f(1000, 350);
glVertex2f(1000, 250);
glVertex2f(0, 250);
glEnd();
}


void drawWater() {
glBegin(GL_POLYGON);
glColor3f(0.2f, 0.5f, 1.0f);
glVertex2f(0, 0);
glVertex2f(1000, 0);
glVertex2f(1000, 250);
glVertex2f(0, 250);
glEnd();
}

GLfloat cloudPosition = 0.0;
bool cloudMoving = true;


void updateClouds(int value) {
    if (cloudMoving) {
        cloudPosition += 2.0f; //
        if (cloudPosition > 1000.0f) {
            cloudPosition = 0.0f;
        }
        glutPostRedisplay();
    }
    glutTimerFunc(25, updateClouds, 0);
}

void cloud1()
{
    int i;
    GLfloat x = (0.5f + 1.0f) * 500.0f; GLfloat y = (0.86f + 1.0f) * 500.0f; GLfloat radius = 50.0f / 2.0f;
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(x, y);
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                x + (radius * cos(i * twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();

    GLfloat a = (0.55f + 1.0f) * 500.0f; GLfloat b = (0.83f + 1.0f) * 500.0f;
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0, 1.0, 1.0); // white
        glVertex2f(a, b); // center of circle
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                a + (radius * cos(i * twicePi / triangleAmount)),
                b + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();

    GLfloat c = (0.45f + 1.0f) * 500.0f; GLfloat d = (0.83f + 1.0f) * 500.0f;
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(c, d);
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                c + (radius * cos(i * twicePi / triangleAmount)),
                d + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();

    GLfloat e = (0.52f + 1.0f) * 500.0f; GLfloat f = (0.8f + 1.0f) * 500.0f;
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0, 1.0, 1.0); // white
        glVertex2f(e, f); // center of circle
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                e + (radius * cos(i * twicePi / triangleAmount)),
                f + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();

    GLfloat g = (0.6f + 1.0f) * 500.0f; GLfloat h = (0.82f + 1.0f) * 500.0f;
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0, 1.0, 1.0); // white
        glVertex2f(g, h); // center of circle
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                g + (radius * cos(i * twicePi / triangleAmount)),
                h + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();
}

void cloud2()
{
  int i;
    GLfloat x = (-0.5f + 1.0f) * 500.0f; GLfloat y = (0.86f + 1.0f) * 500.0f; GLfloat radius = 50.0f / 2.0f; // Scale radius to one-third
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0, 1.0, 1.0); // white
        glVertex2f(x, y); // center of circle
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                x + (radius * cos(i * twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();

    GLfloat a = (-0.55f + 1.0f) * 500.0f; GLfloat b = (0.83f + 1.0f) * 500.0f;
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0, 1.0, 1.0); // white
        glVertex2f(a, b); // center of circle
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                a + (radius * cos(i * twicePi / triangleAmount)),
                b + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();

    GLfloat c = (-0.45f + 1.0f) * 500.0f; GLfloat d = (0.83f + 1.0f) * 500.0f;
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0, 1.0, 1.0); // white
        glVertex2f(c, d); // center of circle
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                c + (radius * cos(i * twicePi / triangleAmount)),
                d + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();

    GLfloat e = (-0.52f + 1.0f) * 500.0f; GLfloat f = (0.8f + 1.0f) * 500.0f;
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0, 1.0, 1.0); // white
        glVertex2f(e, f); // center of circle
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                e + (radius * cos(i * twicePi / triangleAmount)),
                f + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();

    GLfloat g = (-0.6f + 1.0f) * 500.0f; GLfloat h = (0.82f + 1.0f) * 500.0f;
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0, 1.0, 1.0); // white
        glVertex2f(g, h); // center of circle
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                g + (radius * cos(i * twicePi / triangleAmount)),
                h + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();
}

void cloud3()
{
    int i;
    GLfloat x = (0.0f + 1.0f) * 500.0f; GLfloat y = (0.86f + 1.0f) * 500.0f; GLfloat radius = 50.0f / 2.0f;
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0, 1.0, 1.0); // white
        glVertex2f(x, y); // center of circle
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                x + (radius * cos(i * twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();

    GLfloat a = (0.05f + 1.0f) * 500.0f; GLfloat b = (0.83f + 1.0f) * 500.0f;
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0, 1.0, 1.0); // white
        glVertex2f(a, b); // center of circle
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                a + (radius * cos(i * twicePi / triangleAmount)),
                b + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();

    GLfloat c = (-0.05f + 1.0f) * 500.0f; GLfloat d = (0.83f + 1.0f) * 500.0f;
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0, 1.0, 1.0); // white
        glVertex2f(c, d); // center of circle
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                c + (radius * cos(i * twicePi / triangleAmount)),
                d + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();

    GLfloat e = (0.02f + 1.0f) * 500.0f; GLfloat f = (0.8f + 1.0f) * 500.0f;
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0, 1.0, 1.0); // white
        glVertex2f(e, f); // center of circle
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                e + (radius * cos(i * twicePi / triangleAmount)),
                f + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();

    GLfloat g = (0.1f + 1.0f) * 500.0f; GLfloat h = (0.82f + 1.0f) * 500.0f;
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0, 1.0, 1.0); // white
        glVertex2f(g, h); // center of circle
        for (i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                g + (radius * cos(i * twicePi / triangleAmount)),
                h + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();
}

void backgroundtree1()
{

    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(200.0f, 750.0f);
    glVertex2f(240.0f, 750.0f);
    glVertex2f(240.0f, 867.0f);
    glVertex2f(220.0f, 885.0f);
    glVertex2f(200.0f, 867.0f);
    glEnd();

   /* glBegin(GL_POLYGON);
    glColor3ub(34, 139, 34);
    glVertex2f(220.0f, 885.0f);
    glVertex2f(200.0f, 867.0f);
    glVertex2f(140.0f, 857.0f);
    glVertex2f(170.0f, 875.0f);
    glVertex2f(140.0f, 893.0f);
    glVertex2f(200.0f, 893.0f);
    glVertex2f(200.0f, 949.0f);
    glVertex2f(220.0f, 925.0f);
    glVertex2f(240.0f, 949.0f);
    glVertex2f(240.0f, 893.0f);
    glVertex2f(300.0f, 893.0f);
    glVertex2f(270.0f, 875.0f);
    glVertex2f(300.0f, 857.0f);
    glVertex2f(240.0f, 867.0f);
    glEnd();
*/
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(800.0f, 750.0f);
    glVertex2f(760.0f, 750.0f);
    glVertex2f(760.0f, 867.0f);
    glVertex2f(780.0f, 885.0f);
    glVertex2f(800.0f, 867.0f);
    glEnd();

   /* glBegin(GL_POLYGON);
    glColor3ub(34, 139, 34);
    glVertex2f(780.0f, 885.0f);
    glVertex2f(800.0f, 867.0f);
    glVertex2f(860.0f, 857.0f);
    glVertex2f(830.0f, 875.0f);
    glVertex2f(860.0f, 893.0f);
    glVertex2f(800.0f, 893.0f);
    glVertex2f(800.0f, 949.0f);
    glVertex2f(780.0f, 925.0f);
    glVertex2f(760.0f, 949.0f);
    glVertex2f(760.0f, 893.0f);
    glVertex2f(700.0f, 893.0f);
    glVertex2f(730.0f, 875.0f);
    glVertex2f(700.0f, 857.0f);
    glVertex2f(760.0f, 867.0f);
    glEnd();
*/
    // trees and foliage
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(0.0f, 750.0f);
    glVertex2f(20.0f, 785.0f);
    glVertex2f(70.0f, 822.0f);
    glVertex2f(100.0f, 850.0f);
    glVertex2f(180.0f, 885.0f);
    glVertex2f(250.0f, 906.0f);
    glVertex2f(320.0f, 885.0f);
    glVertex2f(400.0f, 850.0f);
    glVertex2f(430.0f, 822.0f);
    glVertex2f(480.0f, 785.0f);
    glVertex2f(500.0f, 750.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(1000.0f, 750.0f);
    glVertex2f(980.0f, 785.0f);
    glVertex2f(930.0f, 822.0f);
    glVertex2f(900.0f, 850.0f);
    glVertex2f(820.0f, 885.0f);
    glVertex2f(750.0f, 906.0f);
    glVertex2f(680.0f, 885.0f);
    glVertex2f(600.0f, 850.0f);
    glVertex2f(570.0f, 822.0f);
    glVertex2f(520.0f, 785.0f);
    glVertex2f(500.0f, 750.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
    glVertex2f(250.0f, 750.0f);
    glVertex2f(270.0f, 785.0f);
    glVertex2f(300.0f, 822.0f);
    glVertex2f(330.0f, 850.0f);
    glVertex2f(380.0f, 875.0f);
    glVertex2f(430.0f, 850.0f);
    glVertex2f(460.0f, 822.0f);
    glVertex2f(480.0f, 785.0f);
    glVertex2f(500.0f, 750.0f);
    glEnd();
}

   void hills()
   {
         glBegin(GL_TRIANGLES); //hills-1
glColor3f(0.0f, 0.39f, 0.0f); // Dark Green
    glVertex2f(0,750);//top right
    glVertex2f(250,750);//bottom right

    glVertex2f(125,900);//angle

        glVertex2f(125,900);//angle
        glEnd();

            glBegin(GL_POLYGON); //hills-2
glColor3f(0.0f, 0.39f, 0.0f); // Dark Green

     glVertex2f(250,750);//bottom  left
    glVertex2f(230,770);//top left
     glVertex2f(375,900);//angle
    glVertex2f(500,750);//bottom right

        glEnd();

                    glBegin(GL_POLYGON); //hills-3
glColor3f(0.0f, 0.39f, 0.0f); // Dark Green

      glVertex2f(500,750);//bottom left
    glVertex2f(480,770);//top left
    glVertex2f(625,900);//angle
    glVertex2f(750,750);//bottom right

        glEnd();


                            glBegin(GL_POLYGON); //hills-4
glColor3f(0.0f, 0.39f, 0.0f); // Dark Green

       glVertex2f(750,750);//bottom left
    glVertex2f(730,770);//top left
    glVertex2f(875,900);//angle
      glVertex2f(1000,750);//bottom right


        glEnd();

        /////////////////////////////////////




        // Hill-1 (Fully Rounded)
glBegin(GL_POLYGON);
glColor3f(0.0f, 0.39f, 0.0f); // Dark Green
glVertex2f(0, 750);       // Bottom left
glVertex2f(50, 770);      // Lower curve point
glVertex2f(100, 800);     // Mid-lower curve point
glVertex2f(125, 850);     // Peak
glVertex2f(150, 800);     // Mid-upper curve point
glVertex2f(200, 770);     // Upper curve point
glVertex2f(250, 750);     // Bottom right
glEnd();

// Hill-5 (Mud Layer inside Hill-1 with Rounded Shape)
glBegin(GL_POLYGON);
glColor3f(0.55f, 0.27f, 0.07f); // Brown (Mud color)
glVertex2f(10, 750);      // Bottom left
glVertex2f(60, 770);      // Lower curve point
glVertex2f(90, 790);      // Mid-lower curve point
glVertex2f(115, 840);     // Peak
glVertex2f(140, 790);     // Mid-upper curve point
glVertex2f(180, 770);     // Upper curve point
glVertex2f(240, 750);     // Bottom right
glEnd();

// Hill-2 (Fully Rounded)
glBegin(GL_POLYGON);
glColor3f(0.0f, 0.39f, 0.0f); // Dark Green
glVertex2f(250, 750);     // Bottom left
glVertex2f(290, 780);     // Lower curve point
glVertex2f(330, 820);     // Mid-lower curve point
glVertex2f(375, 850);     // Peak
glVertex2f(420, 820);     // Mid-upper curve point
glVertex2f(460, 780);     // Upper curve point
glVertex2f(500, 750);     // Bottom right
glEnd();

// Hill-6 (Mud Layer inside Hill-2 with Rounded Shape)
glBegin(GL_POLYGON);
glColor3f(0.55f, 0.27f, 0.07f); // Brown (Mud color)
glVertex2f(260, 750);     // Bottom left
glVertex2f(300, 780);     // Lower curve point
glVertex2f(340, 810);     // Mid-lower curve point
glVertex2f(375, 840);     // Peak
glVertex2f(410, 810);     // Mid-upper curve point
glVertex2f(450, 780);     // Upper curve point
glVertex2f(490, 750);     // Bottom right
glEnd();

// Hill-3 (Fully Rounded)
glBegin(GL_POLYGON);
glColor3f(0.0f, 0.39f, 0.0f); // Dark Green
glVertex2f(500, 750);     // Bottom left
glVertex2f(540, 780);     // Lower curve point
glVertex2f(580, 820);     // Mid-lower curve point
glVertex2f(625, 850);     // Peak
glVertex2f(670, 820);     // Mid-upper curve point
glVertex2f(710, 780);     // Upper curve point
glVertex2f(750, 750);     // Bottom right
glEnd();

// Hill-7 (Mud Layer inside Hill-3 with Rounded Shape)
glBegin(GL_POLYGON);
glColor3f(0.55f, 0.27f, 0.07f); // Brown (Mud color)
glVertex2f(510, 750);     // Bottom left
glVertex2f(550, 780);     // Lower curve point
glVertex2f(590, 810);     // Mid-lower curve point
glVertex2f(625, 840);     // Peak
glVertex2f(660, 810);     // Mid-upper curve point
glVertex2f(700, 780);     // Upper curve point
glVertex2f(740, 750);     // Bottom right
glEnd();

// Hill-4 (Fully Rounded)
glBegin(GL_POLYGON);
glColor3f(0.0f, 0.39f, 0.0f); // Dark Green
glVertex2f(750, 750);     // Bottom left
glVertex2f(790, 780);     // Lower curve point
glVertex2f(830, 820);     // Mid-lower curve point
glVertex2f(875, 850);     // Peak
glVertex2f(920, 820);     // Mid-upper curve point
glVertex2f(960, 780);     // Upper curve point
glVertex2f(1000, 750);    // Bottom right
glEnd();

// Hill-8 (Mud Layer inside Hill-4 with Rounded Shape)
glBegin(GL_POLYGON);
glColor3f(0.55f, 0.27f, 0.07f); // Brown (Mud color)
glVertex2f(760, 750);     // Bottom left
glVertex2f(800, 780);     // Lower curve point
glVertex2f(840, 810);     // Mid-lower curve point
glVertex2f(875, 840);     // Peak
glVertex2f(910, 810);     // Mid-upper curve point
glVertex2f(950, 780);     // Upper curve point
glVertex2f(990, 750);     // Bottom right
glEnd();







   }

   void tree_12(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{
    glBegin(GL_POLYGON);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.1416 / 180;
        float x = rx * cos(angle);
        float y = ry * sin(angle);
        glVertex2f((x + cx), (y + cy));
    }
    glEnd();
}

void tree1()
{
    // Tree trunk (moved 50 units to the right)
    glColor3ub(139, 69, 19);
    glBegin(GL_POLYGON);
    glVertex2d(900, 400); // Original 850 -> 900
    glVertex2d(920, 400); // Original 870 -> 920
    glVertex2d(920, 550); // Original 870 -> 920
    glVertex2d(900, 550); // Original 850 -> 900
    glEnd();

    // Tree leaves (moved 50 units to the right)
    glColor3ub(0, 128, 0);
    tree_12(30, 40, 885, 570); // Original 835 -> 885

    glColor3ub(0, 128, 0);
    tree_12(30, 40, 935, 570); // Original 885 -> 935

    glColor3ub(0, 128, 0);
    tree_12(25, 30, 895, 620); // Original 845 -> 895

    glColor3ub(0, 128, 0);
    tree_12(30, 30, 920, 620); // Original 870 -> 920

    glColor3ub(0, 128, 0);
    tree_12(25, 30, 905, 650); // Original 855 -> 905
}



void tree_22(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{
    glBegin(GL_POLYGON);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.1416 / 180;
        float x = rx * cos(angle);
        float y = ry * sin(angle);
        glVertex2f((x + cx), (y + cy));
    }
    glEnd();
}
// tree 2
void tree22()
{

    glColor3ub(139, 69, 19);
    glBegin(GL_POLYGON);
    glVertex2d(100, 520);
    glVertex2d(120, 520);
    glVertex2d(120, 670);
    glVertex2d(100, 670);
    glEnd();

    glColor3ub(0, 128, 0);
    tree_2(30, 40, 85, 690);
    glColor3ub(0, 128, 0);
    tree_2(30, 40, 135, 690);
    glColor3ub(0, 128, 0);
    tree_2(25, 30, 95, 740);
    glColor3ub(0, 128, 0);
    tree_2(30, 30, 120, 740);
    glColor3ub(0, 128, 0);
    tree_2(25, 30, 105, 770);
}


//house

void house()
{
    glColor3ub(25, 25, 112);
    glBegin(GL_POLYGON);
    glVertex2d(70, 540);
    glVertex2d(340, 540);
    glVertex2d(290, 640);
    glVertex2d(120, 640);
    glEnd();

    glColor3ub(173, 216, 230);
    glBegin(GL_POLYGON);
    glVertex2d(90, 540);
    glVertex2d(170, 540);
    glVertex2d(120, 610);
    glEnd();

    glColor3ub(255, 222, 173);
    glBegin(GL_POLYGON);
    glVertex2d(90, 400);
    glVertex2d(170, 400);
    glVertex2d(170, 540);
    glVertex2d(90, 540);
    glEnd();

    glColor3ub(222, 184, 135);
    glBegin(GL_POLYGON);
    glVertex2d(170, 400);
    glVertex2d(320, 400);
    glVertex2d(320, 540);
    glVertex2d(170, 540);
    glEnd();

    glColor3ub(160, 82, 45);
    glBegin(GL_POLYGON);
    glVertex2d(90, 400);
    glVertex2d(320, 400);
    glVertex2d(320, 380);
    glVertex2d(90, 380);
    glEnd();

    // 1st house door and window
    glColor3ub(160, 82, 45);
    glBegin(GL_POLYGON);
    glVertex2d(220, 400);
    glVertex2d(260, 400);
    glVertex2d(260, 490);
    glVertex2d(220, 490);
    glEnd();

    glColor3ub(255, 215, 0);
    glBegin(GL_POLYGON);
    glVertex2d(110, 500);
    glVertex2d(140, 500);
    glVertex2d(140, 450);
    glVertex2d(110, 450);
    glEnd();
}

//house2

  void house2()
{

    glColor3ub(25, 25, 112);
    glBegin(GL_POLYGON);
    glVertex2d(150, 540);
    glVertex2d(420, 540);
    glVertex2d(370, 640);
    glVertex2d(200, 640);
    glEnd();


    glColor3ub(173, 216, 230);
    glBegin(GL_POLYGON);
    glVertex2d(170, 540);
    glVertex2d(250, 540);
    glVertex2d(200, 610);
    glEnd();


    glColor3ub(211, 211, 211);
    glBegin(GL_POLYGON);
    glVertex2d(170, 400);
    glVertex2d(250, 400);
    glVertex2d(250, 540);
    glVertex2d(170, 540);
    glEnd();


    glColor3ub(169, 169, 169);
    glBegin(GL_POLYGON);
    glVertex2d(250, 400);
    glVertex2d(400, 400);
    glVertex2d(400, 540);
    glVertex2d(250, 540);
    glEnd();


    glColor3ub(139, 69, 19);
    glBegin(GL_POLYGON);
    glVertex2d(170, 400);    // Scaled from (10, 150) + 100 (y) - 150 (x) + 100 (right)
    glVertex2d(400, 400);   // Scaled from (125, 150) + 100 (y) - 150 (x) + 100 (right)
    glVertex2d(400, 380);   // Scaled from (125, 140) + 100 (y) - 150 (x) + 100 (right)
    glVertex2d(170, 380);    // Scaled from (10, 140) + 100 (y) - 150 (x) + 100 (right)
    glEnd();

    // Door (changed to a red color)
    glColor3ub(178, 34, 34); // Red
    glBegin(GL_POLYGON);
    glVertex2d(300, 400);   // Scaled from (75, 150) + 100 (y) - 150 (x) + 100 (right)
    glVertex2d(340, 400);   // Scaled from (95, 150) + 100 (y) - 150 (x) + 100 (right)
    glVertex2d(340, 490);   // Scaled from (95, 195) + 100 (y) - 150 (x) + 100 (right)
    glVertex2d(300, 490);   // Scaled from (75, 195) + 100 (y) - 150 (x) + 100 (right)
    glEnd();

    // Window (changed to a yellow color)
    glColor3ub(255, 215, 0); // Gold/yellow
    glBegin(GL_POLYGON);
    glVertex2d(190, 500);    // Scaled from (20, 200) + 100 (y) - 150 (x) + 100 (right)
    glVertex2d(220, 500);   // Scaled from (35, 200) + 100 (y) - 150 (x) + 100 (right)
    glVertex2d(220, 450);   // Scaled from (35, 175) + 100 (y) - 150 (x) + 100 (right)
    glVertex2d(190, 450);    // Scaled from (20, 175) + 100 (y) - 150 (x) + 100 (right)
    glEnd();
}


//house 3

void house3()
{

    float scale = 0.7;


    float shiftY = 160;


    glColor3f(0.4f, 0.2f, 0.1f);

    glBegin(GL_TRIANGLES);

    glVertex2i((80 * 3.333 * 0.65 * 0.9 * scale) + 250 + 30 + 50, ((125 * 3.333 * 0.65 * 0.9 * scale) + 250) + 30 + shiftY);  // Adjusted y-coordinate
    glVertex2i((162 * 3.333 * 0.65 * 0.9 * scale) + 250 + 30 + 50, ((220 * 3.333 * 0.65 * 0.9 * scale) + 250) + 30 + shiftY); // Top vertex remains the same
    glVertex2i((245 * 3.333 * 0.65 * 0.9 * scale) + 250 + 30 + 50, ((125 * 3.333 * 0.65 * 0.9 * scale) + 250) + 30 + shiftY); // Adjusted y-coordinate

    glEnd();

    // Main Body (Rectangle)
    glColor3f(1.0, 1.0, 1.0);

    glBegin(GL_POLYGON);

    glVertex2i((100 * 3.333 * 0.65 * 0.9 * scale) + 250 + 30 + 50, ((50 * 3.333 * 0.65 * 0.9 * scale) + 250) + 30 + shiftY);   // Bottom-left
    glVertex2i((225 * 3.333 * 0.65 * 0.9 * scale) + 250 + 30 + 50, ((50 * 3.333 * 0.65 * 0.9 * scale) + 250) + 30 + shiftY);   // Bottom-right
    glVertex2i((225 * 3.333 * 0.65 * 0.9 * scale) + 250 + 30 + 50, ((125 * 3.333 * 0.65 * 0.9 * scale) + 250) + 30 + shiftY);  // Top-right
    glVertex2i((100 * 3.333 * 0.65 * 0.9 * scale) + 250 + 30 + 50, ((125 * 3.333 * 0.65 * 0.9 * scale) + 250) + 30 + shiftY);  // Top-left

    glEnd();

    // rectangles (Windows and Door)
    glColor3f(1.0, 1.0, 0.0);

    glBegin(GL_POLYGON);

    glVertex2i((150 * 3.333 * 0.65 * 0.9 * scale) + 250 + 30 + 50, ((50 * 3.333 * 0.65 * 0.9 * scale) + 250) + 30 + shiftY);   // Door
    glVertex2i((175 * 3.333 * 0.65 * 0.9 * scale) + 250 + 30 + 50, ((50 * 3.333 * 0.65 * 0.9 * scale) + 250) + 30 + shiftY);
    glVertex2i((175 * 3.333 * 0.65 * 0.9 * scale) + 250 + 30 + 50, ((125 * 3.333 * 0.65 * 0.9 * scale) + 250) + 30 + shiftY);
    glVertex2i((150 * 3.333 * 0.65 * 0.9 * scale) + 250 + 30 + 50, ((125 * 3.333 * 0.65 * 0.9 * scale) + 250) + 30 + shiftY);

    glEnd();

    glColor3f(1.0, 0.0, 0.0);

    glBegin(GL_POLYGON);

    glVertex2i((115 * 3.333 * 0.65 * 0.9 * scale) + 250 + 30 + 50, ((90 * 3.333 * 0.65 * 0.9 * scale) + 250) + 30 + shiftY);   // Window 1
    glVertex2i((140 * 3.333 * 0.65 * 0.9 * scale) + 250 + 30 + 50, ((90 * 3.333 * 0.65 * 0.9 * scale) + 250) + 30 + shiftY);
    glVertex2i((140 * 3.333 * 0.65 * 0.9 * scale) + 250 + 30 + 50, ((125 * 3.333 * 0.65 * 0.9 * scale) + 250) + 30 + shiftY);
    glVertex2i((115 * 3.333 * 0.65 * 0.9 * scale) + 250 + 30 + 50, ((125 * 3.333 * 0.65 * 0.9 * scale) + 250) + 30 + shiftY);

    glEnd();

    glColor3f(1.0, 0.0, 0.0);

    glBegin(GL_POLYGON);

    glVertex2i((185 * 3.333 * 0.65 * 0.9 * scale) + 250 + 30 + 50, ((90 * 3.333 * 0.65 * 0.9 * scale) + 250) + 30 + shiftY);   // Window 2
    glVertex2i((210 * 3.333 * 0.65 * 0.9 * scale) + 250 + 30 + 50, ((90 * 3.333 * 0.65 * 0.9 * scale) + 250) + 30 + shiftY);
    glVertex2i((210 * 3.333 * 0.65 * 0.9 * scale) + 250 + 30 + 50, ((125 * 3.333 * 0.65 * 0.9 * scale) + 250) + 30 + shiftY);
    glVertex2i((185 * 3.333 * 0.65 * 0.9 * scale) + 250 + 30 + 50, ((125 * 3.333 * 0.65 * 0.9 * scale) + 250) + 30 + shiftY);

    glEnd();
}

void wall()
{
    glBegin(GL_POLYGON);
        glColor3ub(204, 51, 0); // Dark Orange
        glVertex2f((((450 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((525 + 50) + 30 + 20) * 0.72);
        glVertex2f((((450 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((425 + 50) + 30 + 20) * 0.72);
        glVertex2f((((475 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((412.5 + 50) + 30 + 20) * 0.72);
        glVertex2f((((500 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((405 + 50) + 30 + 20) * 0.72);
        glVertex2f((((600 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((405 + 50) + 30 + 20) * 0.72);
        glVertex2f((((625 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((412.5 + 50) + 30 + 20) * 0.72);
        glVertex2f((((650 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((425 + 50) + 30 + 20) * 0.72);
        glVertex2f((((650 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((525 + 50) + 30 + 20) * 0.72);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(255, 102, 51); // Light Orange
        glVertex2f((((450 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((525 + 50) + 30 + 20) * 0.72);
        glVertex2f((((475 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((512.5 + 50) + 30 + 20) * 0.72);
        glVertex2f((((500 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((510 + 50) + 30 + 20) * 0.72);
        glVertex2f((((600 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((510 + 50) + 30 + 20) * 0.72);
        glVertex2f((((625 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((512.5 + 50) + 30 + 20) * 0.72);
        glVertex2f((((650 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((525 + 50) + 30 + 20) * 0.72);
        glVertex2f((((625 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((535 + 50) + 30 + 20) * 0.72);
        glVertex2f((((600 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((537.5 + 50) + 30 + 20) * 0.72);
        glVertex2f((((500 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((537.5 + 50) + 30 + 20) * 0.72);
        glVertex2f((((475 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((535 + 50) + 30 + 20) * 0.72);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
        glColor3ub(204, 51, 0); // Dark Orange
        glVertex2f((((450 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((525 + 50) + 30 + 20) * 0.72); // Adjusted y-coordinate
        glVertex2f((((475 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((535 + 50) + 30 + 20) * 0.72); // Adjusted y-coordinate
        glVertex2f((((475 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((535 + 50) + 30 + 20) * 0.72); // Adjusted y-coordinate
        glVertex2f((((500 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((537.5 + 50) + 30 + 20) * 0.72); // Adjusted y-coordinate
        glVertex2f((((500 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((537.5 + 50) + 30 + 20) * 0.72); // Adjusted y-coordinate
        glVertex2f((((600 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((537.5 + 50) + 30 + 20) * 0.72); // Adjusted y-coordinate
        glVertex2f((((600 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((537.5 + 50) + 30 + 20) * 0.72); // Adjusted y-coordinate
        glVertex2f((((625 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((535 + 50) + 30 + 20) * 0.72); // Adjusted y-coordinate
        glVertex2f((((625 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((535 + 50) + 30 + 20) * 0.72); // Adjusted y-coordinate
        glVertex2f((((650 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((525 + 50) + 30 + 20) * 0.72); // Adjusted y-coordinate
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(194, 194, 163); // Beige
        glVertex2f((((655 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((485 + 50) + 30 + 20) * 0.72); // Adjusted y-coordinate
        glVertex2f((((665 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((450 + 50) + 30 + 20) * 0.72); // Adjusted y-coordinate
        glVertex2f((((690 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((450 + 50) + 30 + 20) * 0.72); // Adjusted y-coordinate
        glVertex2f((((700 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((485 + 50) + 30 + 20) * 0.72); // Adjusted y-coordinate
        glVertex2f((((690 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((490 + 50) + 30 + 20) * 0.72); // Adjusted y-coordinate
        glVertex2f((((665 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((490 + 50) + 30 + 20) * 0.72); // Adjusted y-coordinate
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(38, 154, 214); // Blue
        glVertex2f((((657.5 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((485 + 50) + 30 + 20) * 0.72); // Adjusted y-coordinate
        glVertex2f((((666 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((480 + 50) + 30 + 20) * 0.72); // Adjusted y-coordinate
        glVertex2f((((686 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((480 + 50) + 30 + 20) * 0.72); // Adjusted y-coordinate
        glVertex2f((((697.5 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((485 + 50) + 30 + 20) * 0.72); // Adjusted y-coordinate
        glVertex2f((((686 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((487.5 + 50) + 30 + 20) * 0.72); // Adjusted y-coordinate
        glVertex2f((((666 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((487.5 + 50) + 30 + 20) * 0.72); // Adjusted y-coordinate
    glEnd();
}



// fence

void fence()
{
    glLineWidth(4);
    glBegin(GL_LINES);

    // Define the offsets
    float yOffset = 200.0f / 1000.0f;
    float xOffset = 65.0f / 1000.0f;

    glColor3ub(255, 255, 102);
    glVertex2f(((1.0f + 1) / 2) * 1000 - xOffset * 1000, ((-0.4f + 1) / 2) * 1000 + yOffset * 1000);
    glVertex2f(((0.6f + 1) / 2) * 1000 - xOffset * 1000, ((-0.4f + 1) / 2) * 1000 + yOffset * 1000);

    glColor3ub(255, 255, 102);
    glVertex2f(((1.0f + 1) / 2) * 1000 - xOffset * 1000, ((-0.35f + 1) / 2) * 1000 + yOffset * 1000);
    glVertex2f(((0.6f + 1) / 2) * 1000 - xOffset * 1000, ((-0.35f + 1) / 2) * 1000 + yOffset * 1000);

    glColor3ub(255, 255, 102);
    glVertex2f(((1.0f + 1) / 2) * 1000 - xOffset * 1000, ((-0.3f + 1) / 2) * 1000 + yOffset * 1000);
    glVertex2f(((0.6f + 1) / 2) * 1000 - xOffset * 1000, ((-0.3f + 1) / 2) * 1000 + yOffset * 1000);

    glColor3ub(255, 255, 102);
    glVertex2f(((1.0f + 1) / 2) * 1000 - xOffset * 1000, ((-0.25f + 1) / 2) * 1000 + yOffset * 1000);
    glVertex2f(((0.6f + 1) / 2) * 1000 - xOffset * 1000, ((-0.25f + 1) / 2) * 1000 + yOffset * 1000);

    glColor3ub(255, 255, 102);
    glVertex2f(((1.0f + 1) / 2) * 1000 - xOffset * 1000, ((-0.2f + 1) / 2) * 1000 + yOffset * 1000);
    glVertex2f(((0.6f + 1) / 2) * 1000 - xOffset * 1000, ((-0.2f + 1) / 2) * 1000 + yOffset * 1000);

    glColor3ub(255, 255, 102);
    glVertex2f(((0.95f + 1) / 2) * 1000 - xOffset * 1000, ((-0.17f + 1) / 2) * 1000 + yOffset * 1000);
    glVertex2f(((0.95f + 1) / 2) * 1000 - xOffset * 1000, ((-0.42f + 1) / 2) * 1000 + yOffset * 1000);

    glColor3ub(255, 255, 102);
    glVertex2f(((0.9f + 1) / 2) * 1000 - xOffset * 1000, ((-0.17f + 1) / 2) * 1000 + yOffset * 1000);
    glVertex2f(((0.9f + 1) / 2) * 1000 - xOffset * 1000, ((-0.42f + 1) / 2) * 1000 + yOffset * 1000);

    glColor3ub(255, 255, 102);
    glVertex2f(((0.85f + 1) / 2) * 1000 - xOffset * 1000, ((-0.17f + 1) / 2) * 1000 + yOffset * 1000);
    glVertex2f(((0.85f + 1) / 2) * 1000 - xOffset * 1000, ((-0.42f + 1) / 2) * 1000 + yOffset * 1000);

    glColor3ub(255, 255, 102);
    glVertex2f(((0.8f + 1) / 2) * 1000 - xOffset * 1000, ((-0.17f + 1) / 2) * 1000 + yOffset * 1000);
    glVertex2f(((0.8f + 1) / 2) * 1000 - xOffset * 1000, ((-0.42f + 1) / 2) * 1000 + yOffset * 1000);

    glColor3ub(255, 255, 102);
    glVertex2f(((0.75f + 1) / 2) * 1000 - xOffset * 1000, ((-0.17f + 1) / 2) * 1000 + yOffset * 1000);
    glVertex2f(((0.75f + 1) / 2) * 1000 - xOffset * 1000, ((-0.42f + 1) / 2) * 1000 + yOffset * 1000);

    glColor3ub(255, 255, 102);
    glVertex2f(((0.7f + 1) / 2) * 1000 - xOffset * 1000, ((-0.17f + 1) / 2) * 1000 + yOffset * 1000);
    glVertex2f(((0.7f + 1) / 2) * 1000 - xOffset * 1000, ((-0.42f + 1) / 2) * 1000 + yOffset * 1000);

    glColor3ub(255, 255, 102);
    glVertex2f(((0.65f + 1) / 2) * 1000 - xOffset * 1000, ((-0.17f + 1) / 2) * 1000 + yOffset * 1000);
    glVertex2f(((0.65f + 1) / 2) * 1000 - xOffset * 1000, ((-0.42f + 1) / 2) * 1000 + yOffset * 1000);

    glEnd();
}
//boat


void boat2()
{
glColor3ub(0, 0, 0);
glBegin(GL_POLYGON);
glVertex2d(650, 140);
glVertex2d(800, 140);
glVertex2d(850, 200);
glVertex2d(600, 200);
glEnd();

glColor3ub(205, 133, 63);
glBegin(GL_POLYGON);
glVertex2d(650, 200);  // Scaled from (325, 250) and moved down by 300
glVertex2d(800, 200);  // Scaled from (400, 250) and moved down by 300
glVertex2d(780, 260);  // Scaled from (390, 280) and moved down by 300
glVertex2d(670, 260);  // Scaled from (335, 280) and moved down by 300
glEnd();

glColor3ub(160, 82, 45);
glBegin(GL_POLYGON);
glVertex2d(720, 260);  // Scaled from (360, 280) and moved down by 300
glVertex2d(740, 260);  // Scaled from (370, 280) and moved down by 300
glVertex2d(740, 320);  // Scaled from (370, 310) and moved down by 300
glVertex2d(720, 320);  // Scaled from (360, 310) and moved down by 300
glEnd();

glColor3ub(128, 0, 128);
glBegin(GL_POLYGON);
glVertex2d(670, 280);  // Scaled from (335, 290) and moved down by 300
glVertex2d(780, 280);  // Scaled from (390, 290) and moved down by 300
glVertex2d(780, 450);  // Scaled from (390, 375) and moved down by 300
glVertex2d(670, 450);  // Scaled from (335, 375) and moved down by 300
glEnd();
}



//sun

void sun()
{
    glColor3ub(255, 255, 0);
    circle(30, 40, 500, 850);
}


float  tx = 10, bx = 10, rx = 10, sx = 10, hx = 0;


void car() {
    glPushMatrix();
    glTranslatef(tx, 220, 0); // Translate the car along the x-axis

    // Scale the car coordinates by 2 to fit the new orthographic projection
    glScalef(2.0, 2.0, 1.0);

    // Car body (lower part)
    glColor3ub(255, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2d(410, 40);
    glVertex2d(490, 40);
    glVertex2d(485, 70);
    glVertex2d(410, 70);
    glEnd();

    // Car body (upper part)
    glColor3ub(255, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2d(420, 70);
    glVertex2d(475, 70);
    glVertex2d(465, 100);
    glVertex2d(430, 100);
    glEnd();

    // Car window (left)
    glColor3ub(220, 220, 220);
    glBegin(GL_POLYGON);
    glVertex2d(425, 70);
    glVertex2d(445, 70);
    glVertex2d(445, 90);
    glVertex2d(430, 90);
    glEnd();

    // Car window (right)
    glColor3ub(220, 220, 220);
    glBegin(GL_POLYGON);
    glVertex2d(450, 70);
    glVertex2d(470, 70);
    glVertex2d(465, 90);
    glVertex2d(450, 90);
    glEnd();

    // Car wheels
    glColor3ub(0, 0, 0);
    circle(10, 14, 435, 40); // Left wheel
    circle(10, 14, 465, 40); // Right wheel

    glColor3ub(245, 245, 245);
    circle(6, 10, 435, 40); // Left wheel inner circle
    circle(6, 10, 465, 40); // Right wheel inner circle

    glPopMatrix();

    // Update the car's position
    tx +=2; // Increase the translation speed to match the new scale
    if (tx > 0)
        tx = -1200; // Reset the car's position when it goes off-screen
}

void truck() {
    glPushMatrix();
    glTranslatef(bx, 200, 0);
glColor3ub(0, 0, 139);
    glBegin(GL_POLYGON);
    glVertex2d(900, 80);  // 450 * 2 = 900, 40 * 2 = 80
    glVertex2d(1010, 80); // 505 * 2 = 1010, 40 * 2 = 80
    glVertex2d(1010, 220); // 505 * 2 = 1010, 110 * 2 = 220
    glVertex2d(900, 220);  // 450 * 2 = 900, 110 * 2 = 220
    glEnd();

    glColor3ub(220, 20, 60);
    glBegin(GL_POLYGON);
    glVertex2d(1010, 80);  // 505 * 2 = 1010, 40 * 2 = 80
    glVertex2d(1070, 80);  // 535 * 2 = 1070, 40 * 2 = 80
    glVertex2d(1070, 140); // 535 * 2 = 1070, 70 * 2 = 140
    glVertex2d(1010, 140); // 505 * 2 = 1010, 70 * 2 = 140
    glEnd();

    glColor3ub(220, 20, 60);
    glBegin(GL_POLYGON);
    glVertex2d(1010, 140); // 505 * 2 = 1010, 70 * 2 = 140
    glVertex2d(1050, 140); // 525 * 2 = 1050, 70 * 2 = 140
    glVertex2d(1030, 180); // 515 * 2 = 1030, 90 * 2 = 180
    glVertex2d(1010, 180); // 505 * 2 = 1010, 90 * 2 = 180
    glEnd();

    // window
    glColor3ub(220, 220, 220);
    glBegin(GL_POLYGON);
    glVertex2d(1010, 140); // 505 * 2 = 1010, 70 * 2 = 140
    glVertex2d(1040, 140); // 520 * 2 = 1040, 70 * 2 = 140
    glVertex2d(1030, 170); // 515 * 2 = 1030, 85 * 2 = 170
    glVertex2d(1010, 170); // 505 * 2 = 1010, 85 * 2 = 170
    glEnd();

    // wheels
    glColor3ub(0, 0, 0);
    circle(20, 28, 920, 80);  // 460 * 2 = 920, 40 * 2 = 80
    circle(20, 28, 1020, 80); // 510 * 2 = 1020, 40 * 2 = 80

    glColor3ub(245, 245, 245);
    circle(12, 20, 920, 80);  // 460 * 2 = 920, 40 * 2 = 80
    circle(12, 20, 1020, 80); // 510 * 2 = 1020, 40 * 2 = 80

    glPopMatrix();
    bx += 1.3;
    if (bx > 0)

        bx = -1220;  // -510 * 2 = -1020
}



void displayDay1() {
//glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

// Draw background elements
drawWater(); // Draw water body
drawRoad(); // Draw road
//drawTrees(); // Draw trees
skyday();

       glBegin(GL_POLYGON);
glColor3f(0.15f, 0.6f, 0.15f); // A deeper, darker green for denser vegetation
    glVertex2f(1000,750);//top right
    glVertex2f(1000,350);//bottom right
    glVertex2f(0,350);//bottom left
    //glVertex2f(700,200);//angle
    glVertex2f(0,750);//top left
    glEnd();

//drawCar(); // Draw car
//drawBoat(); // Draw boat

    glPushMatrix();
    glTranslatef(cloudPosition,0.0f, 0.0f);
    cloud1();
    cloud2();
    //cloud3();

    glPopMatrix();
        sun();

     backgroundtree1();
    //hills();
    fence();
    tree1();
    tree22();
    house();

    house2();
    house3();
    wall();

    car();
    truck();


           glPushMatrix();
    glTranslatef(boatPosition, 0.0f, 0.0f); // Move the boat along the x-axis

     boat2();

   glPopMatrix();






//glutSwapBuffers(); // Render now
}

void housenight()
{
    // Darker roof
    glColor3ub(12, 12, 56);
    glBegin(GL_POLYGON);
    glVertex2d(70, 540);
    glVertex2d(340, 540);
    glVertex2d(290, 640);
    glVertex2d(120, 640);
    glEnd();

    glColor3ub(86, 108, 115);
    glBegin(GL_POLYGON);
    glVertex2d(90, 540);
    glVertex2d(170, 540);
    glVertex2d(120, 610);
    glEnd();


    glColor3ub(139, 69, 19);
    glBegin(GL_POLYGON);
    glVertex2d(90, 400);
    glVertex2d(170, 400);
    glVertex2d(170, 540);
    glVertex2d(90, 540);
    glEnd();


    glColor3ub(139, 69, 19);
    glBegin(GL_POLYGON);
    glVertex2d(170, 400);
    glVertex2d(320, 400);
    glVertex2d(320, 540);
    glVertex2d(170, 540);
    glEnd();

    // Darker base
    glColor3ub(101, 67, 33);
    glBegin(GL_POLYGON);
    glVertex2d(90, 400);
    glVertex2d(320, 400);
    glVertex2d(320, 380);
    glVertex2d(90, 380);
    glEnd();


    glColor3ub(255, 215, 0);
    glBegin(GL_POLYGON);
    glVertex2d(220, 400);
    glVertex2d(260, 400);
    glVertex2d(260, 490);
    glVertex2d(220, 490);
    glEnd();


    glColor3ub(255, 215, 0);
    glBegin(GL_POLYGON);
    glVertex2d(110, 500);
    glVertex2d(140, 500);
    glVertex2d(140, 450);
    glVertex2d(110, 450);
    glEnd();
}
void house2night()
{
    glColor3ub(0, 0, 50);
    glBegin(GL_POLYGON);
    glVertex2d(150, 540);
    glVertex2d(420, 540);
    glVertex2d(370, 640);
    glVertex2d(200, 640);
    glEnd();


    glColor3ub(0, 0, 70);
    glBegin(GL_POLYGON);
    glVertex2d(170, 540);    // Scaled from (10, 220) + 100 (y) - 150 (x) + 100 (right)
    glVertex2d(250, 540);   // Scaled from (50, 220) + 100 (y) - 150 (x) + 100 (right)
    glVertex2d(200, 610);   // Scaled from (25, 255) + 100 (y) - 150 (x) + 100 (right)
    glEnd();

    // Left wall (changed to a darker gray for night mode)
    glColor3ub(50, 50, 50); // Dark gray
    glBegin(GL_POLYGON);
    glVertex2d(170, 400);    // Scaled from (10, 150) + 100 (y) - 150 (x) + 100 (right)
    glVertex2d(250, 400);   // Scaled from (50, 150) + 100 (y) - 150 (x) + 100 (right)
    glVertex2d(250, 540);   // Scaled from (50, 220) + 100 (y) - 150 (x) + 100 (right)
    glVertex2d(170, 540);    // Scaled from (10, 220) + 100 (y) - 150 (x) + 100 (right)
    glEnd();

    // Right wall (changed to a darker gray for night mode)
    glColor3ub(40, 40, 40); // Darker gray
    glBegin(GL_POLYGON);
    glVertex2d(250, 400);   // Scaled from (50, 150) + 100 (y) - 150 (x) + 100 (right)
    glVertex2d(400, 400);   // Scaled from (125, 150) + 100 (y) - 150 (x) + 100 (right)
    glVertex2d(400, 540);   // Scaled from (125, 220) + 100 (y) - 150 (x) + 100 (right)
    glVertex2d(250, 540);   // Scaled from (50, 220) + 100 (y) - 150 (x) + 100 (right)
    glEnd();

    // Base of the house (changed to a darker brown for night mode)
    glColor3ub(69, 34, 0); // Dark brown
    glBegin(GL_POLYGON);
    glVertex2d(170, 400);    // Scaled from (10, 150) + 100 (y) - 150 (x) + 100 (right)
    glVertex2d(400, 400);   // Scaled from (125, 150) + 100 (y) - 150 (x) + 100 (right)
    glVertex2d(400, 380);   // Scaled from (125, 140) + 100 (y) - 150 (x) + 100 (right)
    glVertex2d(170, 380);    // Scaled from (10, 140) + 100 (y) - 150 (x) + 100 (right)
    glEnd();

    // Door (changed to a golden color)
     glColor3f(0.5f, 0.3f, 0.2f); // Soil color
    glBegin(GL_POLYGON);
    glVertex2d(300, 400);   // Scaled from (75, 150) + 100 (y) - 150 (x) + 100 (right)
    glVertex2d(340, 400);   // Scaled from (95, 150) + 100 (y) - 150 (x) + 100 (right)
    glVertex2d(340, 490);   // Scaled from (95, 195) + 100 (y) - 150 (x) + 100 (right)
    glVertex2d(300, 490);   // Scaled from (75, 195) + 100 (y) - 150 (x) + 100 (right)
    glEnd();

    // Window (changed to a golden color)
    glColor3ub(255, 215, 0); // Golden
    glBegin(GL_POLYGON);
    glVertex2d(190, 500);    // Scaled from (20, 200) + 100 (y) - 150 (x) + 100 (right)
    glVertex2d(220, 500);   // Scaled from (35, 200) + 100 (y) - 150 (x) + 100 (right)
    glVertex2d(220, 450);   // Scaled from (35, 175) + 100 (y) - 150 (x) + 100 (right)
    glVertex2d(190, 450);    // Scaled from (20, 175) + 100 (y) - 150 (x) + 100 (right)
    glEnd();
}


void house3night()
{
    float scale = 0.7;
    float shiftY = 160;

    // Roof (Triangle)
    glColor3f(0.2f, 0.1f, 0.05f); // Darker brown for night mode

    glBegin(GL_TRIANGLES);

    glVertex2i((80 * 3.333 * 0.65 * 0.9 * scale) + 250 + 30 + 50, ((125 * 3.333 * 0.65 * 0.9 * scale) + 250) + 30 + shiftY);  // Adjusted y-coordinate
    glVertex2i((162 * 3.333 * 0.65 * 0.9 * scale) + 250 + 30 + 50, ((220 * 3.333 * 0.65 * 0.9 * scale) + 250) + 30 + shiftY); // Top vertex remains the same
    glVertex2i((245 * 3.333 * 0.65 * 0.9 * scale) + 250 + 30 + 50, ((125 * 3.333 * 0.65 * 0.9 * scale) + 250) + 30 + shiftY); // Adjusted y-coordinate

    glEnd();

    // Main Body (Rectangle)
    glColor3f(0.3f, 0.3f, 0.3f); // Dark gray for night mode

    glBegin(GL_POLYGON);

    glVertex2i((100 * 3.333 * 0.65 * 0.9 * scale) + 250 + 30 + 50, ((50 * 3.333 * 0.65 * 0.9 * scale) + 250) + 30 + shiftY);   // Bottom-left
    glVertex2i((225 * 3.333 * 0.65 * 0.9 * scale) + 250 + 30 + 50, ((50 * 3.333 * 0.65 * 0.9 * scale) + 250) + 30 + shiftY);   // Bottom-right
    glVertex2i((225 * 3.333 * 0.65 * 0.9 * scale) + 250 + 30 + 50, ((125 * 3.333 * 0.65 * 0.9 * scale) + 250) + 30 + shiftY);  // Top-right
    glVertex2i((100 * 3.333 * 0.65 * 0.9 * scale) + 250 + 30 + 50, ((125 * 3.333 * 0.65 * 0.9 * scale) + 250) + 30 + shiftY);  // Top-left

    glEnd();

    // Door (Soil color)
    glColor3f(0.5f, 0.3f, 0.2f); // Soil color

    glBegin(GL_POLYGON);

    glVertex2i((150 * 3.333 * 0.65 * 0.9 * scale) + 250 + 30 + 50, ((50 * 3.333 * 0.65 * 0.9 * scale) + 250) + 30 + shiftY);   // Door
    glVertex2i((175 * 3.333 * 0.65 * 0.9 * scale) + 250 + 30 + 50, ((50 * 3.333 * 0.65 * 0.9 * scale) + 250) + 30 + shiftY);
    glVertex2i((175 * 3.333 * 0.65 * 0.9 * scale) + 250 + 30 + 50, ((125 * 3.333 * 0.65 * 0.9 * scale) + 250) + 30 + shiftY);
    glVertex2i((150 * 3.333 * 0.65 * 0.9 * scale) + 250 + 30 + 50, ((125 * 3.333 * 0.65 * 0.9 * scale) + 250) + 30 + shiftY);

    glEnd();

    // Window 1 (Golden color)
    glColor3f(1.0f, 0.84f, 0.0f); // Golden color

    glBegin(GL_POLYGON);

    glVertex2i((115 * 3.333 * 0.65 * 0.9 * scale) + 250 + 30 + 50, ((90 * 3.333 * 0.65 * 0.9 * scale) + 250) + 30 + shiftY);   // Window 1
    glVertex2i((140 * 3.333 * 0.65 * 0.9 * scale) + 250 + 30 + 50, ((90 * 3.333 * 0.65 * 0.9 * scale) + 250) + 30 + shiftY);
    glVertex2i((140 * 3.333 * 0.65 * 0.9 * scale) + 250 + 30 + 50, ((125 * 3.333 * 0.65 * 0.9 * scale) + 250) + 30 + shiftY);
    glVertex2i((115 * 3.333 * 0.65 * 0.9 * scale) + 250 + 30 + 50, ((125 * 3.333 * 0.65 * 0.9 * scale) + 250) + 30 + shiftY);

    glEnd();

    // Window 2 (Golden color)
    glColor3f(1.0f, 0.84f, 0.0f); // Golden color

    glBegin(GL_POLYGON);

    glVertex2i((185 * 3.333 * 0.65 * 0.9 * scale) + 250 + 30 + 50, ((90 * 3.333 * 0.65 * 0.9 * scale) + 250) + 30 + shiftY);   // Window 2
    glVertex2i((210 * 3.333 * 0.65 * 0.9 * scale) + 250 + 30 + 50, ((90 * 3.333 * 0.65 * 0.9 * scale) + 250) + 30 + shiftY);
    glVertex2i((210 * 3.333 * 0.65 * 0.9 * scale) + 250 + 30 + 50, ((125 * 3.333 * 0.65 * 0.9 * scale) + 250) + 30 + shiftY);
    glVertex2i((185 * 3.333 * 0.65 * 0.9 * scale) + 250 + 30 + 50, ((125 * 3.333 * 0.65 * 0.9 * scale) + 250) + 30 + shiftY);

    glEnd();
}


void fencenight()
{
    glLineWidth(4);
    glBegin(GL_LINES);

    // Define the offsets
    float yOffset = 200.0f / 1000.0f;
    float xOffset = 65.0f / 1000.0f;

    // Use a darker color (e.g., light gray or blue)
    glColor3ub(100, 100, 100); // Dark gray for night mode
    glVertex2f(((1.0f + 1) / 2) * 1000 - xOffset * 1000, ((-0.4f + 1) / 2) * 1000 + yOffset * 1000);
    glVertex2f(((0.6f + 1) / 2) * 1000 - xOffset * 1000, ((-0.4f + 1) / 2) * 1000 + yOffset * 1000);

    glColor3ub(100, 100, 100); // Dark gray
    glVertex2f(((1.0f + 1) / 2) * 1000 - xOffset * 1000, ((-0.35f + 1) / 2) * 1000 + yOffset * 1000);
    glVertex2f(((0.6f + 1) / 2) * 1000 - xOffset * 1000, ((-0.35f + 1) / 2) * 1000 + yOffset * 1000);

    glColor3ub(100, 100, 100); // Dark gray
    glVertex2f(((1.0f + 1) / 2) * 1000 - xOffset * 1000, ((-0.3f + 1) / 2) * 1000 + yOffset * 1000);
    glVertex2f(((0.6f + 1) / 2) * 1000 - xOffset * 1000, ((-0.3f + 1) / 2) * 1000 + yOffset * 1000);

    glColor3ub(100, 100, 100); // Dark gray
    glVertex2f(((1.0f + 1) / 2) * 1000 - xOffset * 1000, ((-0.25f + 1) / 2) * 1000 + yOffset * 1000);
    glVertex2f(((0.6f + 1) / 2) * 1000 - xOffset * 1000, ((-0.25f + 1) / 2) * 1000 + yOffset * 1000);

    glColor3ub(100, 100, 100); // Dark gray
    glVertex2f(((1.0f + 1) / 2) * 1000 - xOffset * 1000, ((-0.2f + 1) / 2) * 1000 + yOffset * 1000);
    glVertex2f(((0.6f + 1) / 2) * 1000 - xOffset * 1000, ((-0.2f + 1) / 2) * 1000 + yOffset * 1000);

    glColor3ub(100, 100, 100); // Dark gray
    glVertex2f(((0.95f + 1) / 2) * 1000 - xOffset * 1000, ((-0.17f + 1) / 2) * 1000 + yOffset * 1000);
    glVertex2f(((0.95f + 1) / 2) * 1000 - xOffset * 1000, ((-0.42f + 1) / 2) * 1000 + yOffset * 1000);

    glColor3ub(100, 100, 100); // Dark gray
    glVertex2f(((0.9f + 1) / 2) * 1000 - xOffset * 1000, ((-0.17f + 1) / 2) * 1000 + yOffset * 1000);
    glVertex2f(((0.9f + 1) / 2) * 1000 - xOffset * 1000, ((-0.42f + 1) / 2) * 1000 + yOffset * 1000);

    glColor3ub(100, 100, 100); // Dark gray
    glVertex2f(((0.85f + 1) / 2) * 1000 - xOffset * 1000, ((-0.17f + 1) / 2) * 1000 + yOffset * 1000);
    glVertex2f(((0.85f + 1) / 2) * 1000 - xOffset * 1000, ((-0.42f + 1) / 2) * 1000 + yOffset * 1000);

    glColor3ub(100, 100, 100); // Dark gray
    glVertex2f(((0.8f + 1) / 2) * 1000 - xOffset * 1000, ((-0.17f + 1) / 2) * 1000 + yOffset * 1000);
    glVertex2f(((0.8f + 1) / 2) * 1000 - xOffset * 1000, ((-0.42f + 1) / 2) * 1000 + yOffset * 1000);

    glColor3ub(100, 100, 100); // Dark gray
    glVertex2f(((0.75f + 1) / 2) * 1000 - xOffset * 1000, ((-0.17f + 1) / 2) * 1000 + yOffset * 1000);
    glVertex2f(((0.75f + 1) / 2) * 1000 - xOffset * 1000, ((-0.42f + 1) / 2) * 1000 + yOffset * 1000);

    glColor3ub(100, 100, 100); // Dark gray
    glVertex2f(((0.7f + 1) / 2) * 1000 - xOffset * 1000, ((-0.17f + 1) / 2) * 1000 + yOffset * 1000);
    glVertex2f(((0.7f + 1) / 2) * 1000 - xOffset * 1000, ((-0.42f + 1) / 2) * 1000 + yOffset * 1000);

    glColor3ub(100, 100, 100); // Dark gray
    glVertex2f(((0.65f + 1) / 2) * 1000 - xOffset * 1000, ((-0.17f + 1) / 2) * 1000 + yOffset * 1000);
    glVertex2f(((0.65f + 1) / 2) * 1000 - xOffset * 1000, ((-0.42f + 1) / 2) * 1000 + yOffset * 1000);

    glEnd();
}

void tree1night()
{
    // Tree trunk (moved 50 units to the right)
    glColor3ub(69, 34, 9); // Darker brown for the trunk
    glBegin(GL_POLYGON);
    glVertex2d(900, 400); // Original 850 -> 900
    glVertex2d(920, 400); // Original 870 -> 920
    glVertex2d(920, 550); // Original 870 -> 920
    glVertex2d(900, 550); // Original 850 -> 900
    glEnd();

    // Tree leaves (moved 50 units to the right)
    glColor3ub(0, 64, 0); // Darker green for the leaves
    tree_1(30, 40, 885, 570); // Original 835 -> 885

    glColor3ub(0, 64, 0); // Darker green for the leaves
    tree_1(30, 40, 935, 570); // Original 885 -> 935

    glColor3ub(0, 64, 0); // Darker green for the leaves
    tree_1(25, 30, 895, 620); // Original 845 -> 895

    glColor3ub(0, 64, 0); // Darker green for the leaves
    tree_1(30, 30, 920, 620); // Original 870 -> 920

    glColor3ub(0, 64, 0); // Darker green for the leaves
    tree_1(25, 30, 905, 650); // Original 855 -> 905
}
  void tree2night()
{
    // Darker brown for the tree trunk
    glColor3ub(101, 67, 33); // Dark brown color
    glBegin(GL_POLYGON);
    glVertex2d(100, 520);
    glVertex2d(120, 520);
    glVertex2d(120, 670);
    glVertex2d(100, 670);
    glEnd();

    // Darker green for the leaves
    glColor3ub(0, 50, 0); // Dark green color
    tree_2(30, 40, 85, 690);
    glColor3ub(0, 50, 0);
    tree_2(30, 40, 135, 690);
    glColor3ub(0, 50, 0);
    tree_2(25, 30, 95, 740);
    glColor3ub(0, 50, 0);
    tree_2(30, 30, 120, 740);
    glColor3ub(0, 50, 0);
    tree_2(25, 30, 105, 770);
}
   void wallnight()
{
    glBegin(GL_POLYGON);
        glColor3ub(102, 25, 0);
        glVertex2f((((450 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((525 + 50) + 30 + 20) * 0.72);
        glVertex2f((((450 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((425 + 50) + 30 + 20) * 0.72);
        glVertex2f((((475 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((412.5 + 50) + 30 + 20) * 0.72);
        glVertex2f((((500 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((405 + 50) + 30 + 20) * 0.72);
        glVertex2f((((600 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((405 + 50) + 30 + 20) * 0.72);
        glVertex2f((((625 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((412.5 + 50) + 30 + 20) * 0.72);
        glVertex2f((((650 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((425 + 50) + 30 + 20) * 0.72);
        glVertex2f((((650 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((525 + 50) + 30 + 20) * 0.72);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(255, 128, 77);
        glVertex2f((((450 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((525 + 50) + 30 + 20) * 0.72);
        glVertex2f((((475 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((512.5 + 50) + 30 + 20) * 0.72);
        glVertex2f((((500 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((510 + 50) + 30 + 20) * 0.72);
        glVertex2f((((600 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((510 + 50) + 30 + 20) * 0.72);
        glVertex2f((((625 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((512.5 + 50) + 30 + 20) * 0.72);
        glVertex2f((((650 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((525 + 50) + 30 + 20) * 0.72);
        glVertex2f((((625 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((535 + 50) + 30 + 20) * 0.72);
        glVertex2f((((600 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((537.5 + 50) + 30 + 20) * 0.72);
        glVertex2f((((500 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((537.5 + 50) + 30 + 20) * 0.72);
        glVertex2f((((475 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((535 + 50) + 30 + 20) * 0.72);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
        glColor3ub(102, 25, 0);
        glVertex2f((((450 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((525 + 50) + 30 + 20) * 0.72);
        glVertex2f((((475 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((535 + 50) + 30 + 20) * 0.72);
        glVertex2f((((475 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((535 + 50) + 30 + 20) * 0.72);
        glVertex2f((((500 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((537.5 + 50) + 30 + 20) * 0.72);
        glVertex2f((((500 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((537.5 + 50) + 30 + 20) * 0.72);
        glVertex2f((((600 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((537.5 + 50) + 30 + 20) * 0.72);
        glVertex2f((((600 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((537.5 + 50) + 30 + 20) * 0.72);
        glVertex2f((((625 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((535 + 50) + 30 + 20) * 0.72);
        glVertex2f((((625 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((535 + 50) + 30 + 20) * 0.72);
        glVertex2f((((650 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((525 + 50) + 30 + 20) * 0.72);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(77, 77, 51);
        glVertex2f((((655 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((485 + 50) + 30 + 20) * 0.72);
        glVertex2f((((665 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((450 + 50) + 30 + 20) * 0.72);
        glVertex2f((((690 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((450 + 50) + 30 + 20) * 0.72);
        glVertex2f((((700 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((485 + 50) + 30 + 20) * 0.72);
        glVertex2f((((690 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((490 + 50) + 30 + 20) * 0.72);
        glVertex2f((((665 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((490 + 50) + 30 + 20) * 0.72);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(0, 77, 128); // Dark Blue for a night sky vibe
        glVertex2f((((657.5 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((485 + 50) + 30 + 20) * 0.72);
        glVertex2f((((666 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((480 + 50) + 30 + 20) * 0.72);
        glVertex2f((((686 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((480 + 50) + 30 + 20) * 0.72);
        glVertex2f((((697.5 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((485 + 50) + 30 + 20) * 0.72);
        glVertex2f((((686 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((487.5 + 50) + 30 + 20) * 0.72);
        glVertex2f((((666 + 50 + 50 + 100 + 100) + 150) + 100) * 0.72, ((487.5 + 50) + 30 + 20) * 0.72);
    glEnd();
}



void backgroundtreenight()
{
    // Tree trunks in dark brown
    glBegin(GL_POLYGON);
    glColor3ub(51, 25, 0);  // Darker brown
    glVertex2f(200.0f, 750.0f);
    glVertex2f(240.0f, 750.0f);
    glVertex2f(240.0f, 867.0f);
    glVertex2f(220.0f, 885.0f);
    glVertex2f(200.0f, 867.0f);
    glEnd();

    // Foliage in dark green with a slight bluish tint
    /*glBegin(GL_POLYGON);
    glColor3ub(51, 25, 0);  // Dark green
    glVertex2f(220.0f, 885.0f);
    glVertex2f(200.0f, 867.0f);
    glVertex2f(140.0f, 857.0f);
    glVertex2f(170.0f, 875.0f);
    glVertex2f(140.0f, 893.0f);
    glVertex2f(200.0f, 893.0f);
    glVertex2f(200.0f, 949.0f);
    glVertex2f(220.0f, 925.0f);
    glVertex2f(240.0f, 949.0f);
    glVertex2f(240.0f, 893.0f);
    glVertex2f(300.0f, 893.0f);
    glVertex2f(270.0f, 875.0f);
    glVertex2f(300.0f, 857.0f);
    glVertex2f(240.0f, 867.0f);
    glEnd();
*/
    // Tree trunks in dark brown on the right
    glBegin(GL_POLYGON);
    glColor3ub(51, 25, 0);  // Darker brown
    glVertex2f(800.0f, 750.0f);
    glVertex2f(760.0f, 750.0f);
    glVertex2f(760.0f, 867.0f);
    glVertex2f(780.0f, 885.0f);
    glVertex2f(800.0f, 867.0f);
    glEnd();

    // Foliage in dark green with a slight bluish tint
    /*
    glBegin(GL_POLYGON);
    glColor3ub(51, 25, 0);  // Dark green
    glVertex2f(780.0f, 885.0f);
    glVertex2f(800.0f, 867.0f);
    glVertex2f(860.0f, 857.0f);
    glVertex2f(830.0f, 875.0f);
    glVertex2f(860.0f, 893.0f);
    glVertex2f(800.0f, 893.0f);
    glVertex2f(800.0f, 949.0f);
    glVertex2f(780.0f, 925.0f);
    glVertex2f(760.0f, 949.0f);
    glVertex2f(760.0f, 893.0f);
    glVertex2f(700.0f, 893.0f);
    glVertex2f(730.0f, 875.0f);
    glVertex2f(700.0f, 857.0f);
    glVertex2f(760.0f, 867.0f);
    glEnd();
*/
    // Left tree in dark brown trunk
    glBegin(GL_POLYGON);
    glColor3ub(51, 25, 0);  // Darker brown
    glVertex2f(0.0f, 750.0f);
    glVertex2f(20.0f, 785.0f);
    glVertex2f(70.0f, 822.0f);
    glVertex2f(100.0f, 850.0f);
    glVertex2f(180.0f, 885.0f);
    glVertex2f(250.0f, 906.0f);
    glVertex2f(320.0f, 885.0f);
    glVertex2f(400.0f, 850.0f);
    glVertex2f(430.0f, 822.0f);
    glVertex2f(480.0f, 785.0f);
    glVertex2f(500.0f, 750.0f);
    glEnd();

    // Foliage in dark green with a slight bluish tint
    glBegin(GL_POLYGON);
    glColor3ub(51, 25, 0);  // Dark green
    glVertex2f(1000.0f, 750.0f);
    glVertex2f(980.0f, 785.0f);
    glVertex2f(930.0f, 822.0f);
    glVertex2f(900.0f, 850.0f);
    glVertex2f(820.0f, 885.0f);
    glVertex2f(750.0f, 906.0f);
    glVertex2f(680.0f, 885.0f);
    glVertex2f(600.0f, 850.0f);
    glVertex2f(570.0f, 822.0f);
    glVertex2f(520.0f, 785.0f);
    glVertex2f(500.0f, 750.0f);
    glEnd();

    // Another left tree with darker colors
    glBegin(GL_POLYGON);
    glColor3ub(51, 25, 0);  // Darker brown
    glVertex2f(250.0f, 750.0f);
    glVertex2f(270.0f, 785.0f);
    glVertex2f(300.0f, 822.0f);
    glVertex2f(330.0f, 850.0f);
    glVertex2f(380.0f, 875.0f);
    glVertex2f(430.0f, 850.0f);
    glVertex2f(460.0f, 822.0f);
    glVertex2f(480.0f, 785.0f);
    glVertex2f(500.0f, 750.0f);
    glEnd();

    // Foliage in dark green with a slight bluish tint
    glBegin(GL_POLYGON);
    glColor3ub(51, 25, 0);  // Dark green
    glVertex2f(250.0f, 750.0f);
    glVertex2f(270.0f, 785.0f);
    glVertex2f(300.0f, 822.0f);
    glVertex2f(330.0f, 850.0f);
    glVertex2f(380.0f, 875.0f);
    glVertex2f(430.0f, 850.0f);
    glVertex2f(460.0f, 822.0f);
    glVertex2f(480.0f, 785.0f);
    glVertex2f(500.0f, 750.0f);
    glEnd();
}


void carnight() {
    glPushMatrix();
    glTranslatef(tx, 220, 0); // Translate the car along the x-axis

    // Scale the car coordinates by 2 to fit the new orthographic projection
    glScalef(2.0, 2.0, 1.0);

    // Car body (lower part) - Darker red for night mode
    glColor3ub(150, 0, 0); // Dark red
    glBegin(GL_POLYGON);
    glVertex2d(410, 40);
    glVertex2d(490, 40);
    glVertex2d(485, 70);
    glVertex2d(410, 70);
    glEnd();

    // Car body (upper part) - Darker red for night mode
    glColor3ub(150, 0, 0); // Dark red
    glBegin(GL_POLYGON);
    glVertex2d(420, 70);
    glVertex2d(475, 70);
    glVertex2d(465, 100);
    glVertex2d(430, 100);
    glEnd();

    // Car window (left) - Dark gray for night mode
    glColor3ub(100, 100, 100); // Dark gray
    glBegin(GL_POLYGON);
    glVertex2d(425, 70);
    glVertex2d(445, 70);
    glVertex2d(445, 90);
    glVertex2d(430, 90);
    glEnd();

    // Car window (right) - Dark gray for night mode
    glColor3ub(100, 100, 100); // Dark gray
    glBegin(GL_POLYGON);
    glVertex2d(450, 70);
    glVertex2d(470, 70);
    glVertex2d(465, 90);
    glVertex2d(450, 90);
    glEnd();

    // Car wheels - Darker for night mode
    glColor3ub(30, 30, 30); // Very dark gray
    circle(10, 14, 435, 40); // Left wheel
    circle(10, 14, 465, 40); // Right wheel

    // Wheel inner circles - Slightly lighter for contrast
    glColor3ub(80, 80, 80); // Dark gray
    circle(6, 10, 435, 40); // Left wheel inner circle
    circle(6, 10, 465, 40); // Right wheel inner circle

    // Add headlights for night mode
    glColor3ub(255, 255, 200); // Light yellow for headlights
    glBegin(GL_POLYGON);
    glVertex2d(490, 60);
    glVertex2d(500, 60);
    glVertex2d(500, 80);
    glVertex2d(490, 80);
    glEnd();

    glPopMatrix();

    // Update the car's position
    tx += 1.8; // Increase the translation speed to match the new scale
    if (tx > 0)
        tx = -1000; // Reset the car's position when it goes off-screen
}


void trucknight() {
    glPushMatrix();
    glTranslatef(bx, 200, 0);

    // Darker shade for the truck body
    glColor3ub(0, 0, 50);  // Dark blue
    glBegin(GL_POLYGON);
    glVertex2d(900, 80);
    glVertex2d(1010, 80);
    glVertex2d(1010, 220);
    glVertex2d(900, 220);
    glEnd();

    // Darker shade for the truck cabin
    glColor3ub(100, 0, 0);  // Dark red
    glBegin(GL_POLYGON);
    glVertex2d(1010, 80);
    glVertex2d(1070, 80);
    glVertex2d(1070, 140);
    glVertex2d(1010, 140);
    glEnd();

    // Darker shade for the truck cabin roof
    glColor3ub(100, 0, 0);  // Dark red
    glBegin(GL_POLYGON);
    glVertex2d(1010, 140);
    glVertex2d(1050, 140);
    glVertex2d(1030, 180);
    glVertex2d(1010, 180);
    glEnd();

    // Darker shade for the window
    glColor3ub(50, 50, 50);  // Dark gray
    glBegin(GL_POLYGON);
    glVertex2d(1010, 140);
    glVertex2d(1040, 140);
    glVertex2d(1030, 170);
    glVertex2d(1010, 170);
    glEnd();

    // Darker shade for the wheels
    glColor3ub(20, 20, 20);  // Very dark gray
    circle(20, 28, 920, 80);
    circle(20, 28, 1020, 80);

    // Darker shade for the wheel hubs
    glColor3ub(100, 100, 100);  // Dark gray
    circle(12, 20, 920, 80);
    circle(12, 20, 1020, 80);

    glPopMatrix();
    bx += .9;
    if (bx > 0)
        bx = -1020;
}

void updateBoat(int value) {
    if(boatMoving){
    boatPosition -= 3.0f; // Move the boat 1 unit to the right
    if (boatPosition <-900) {
        boatPosition = 900.0f; // Reset position when out of bounds
    }
    }
    glutPostRedisplay(); // Redisplay with updated position
    glutTimerFunc(25, updateBoat, 0); // Call update every ~16ms (~60fps)
}

void drawWaternight() {
    glBegin(GL_POLYGON);
    glColor3f(0.1f, 0.1f, 0.3f);  // Darker blue color for night mode
    glVertex2f(0, 0);
    glVertex2f(1000, 0);
    glVertex2f(1000, 250);
    glVertex2f(0, 250);
    glEnd();
}

void boat2night()
{
    // Darker base of the boat
    glColor3ub(20, 20, 20); // Almost black
    glBegin(GL_POLYGON);
    glVertex2d(650, 140);
    glVertex2d(800, 140);
    glVertex2d(850, 200);
    glVertex2d(600, 200);
    glEnd();

    // Darker brown for the deck
    glColor3ub(102, 67, 31); // Dark brown
    glBegin(GL_POLYGON);
    glVertex2d(650, 200);  // Scaled from (325, 250) and moved down by 300
    glVertex2d(800, 200);  // Scaled from (400, 250) and moved down by 300
    glVertex2d(780, 260);  // Scaled from (390, 280) and moved down by 300
    glVertex2d(670, 260);  // Scaled from (335, 280) and moved down by 300
    glEnd();

    // Darker brown for the mast
    glColor3ub(80, 41, 22); // Darker brown
    glBegin(GL_POLYGON);
    glVertex2d(720, 260);
    glVertex2d(740, 260);
    glVertex2d(740, 320);
    glVertex2d(720, 320);
    glEnd();


    glColor3ub(64, 0, 64);
    glBegin(GL_POLYGON);
    glVertex2d(670, 280);
    glVertex2d(780, 280);
    glVertex2d(780, 450);
    glVertex2d(670, 450);
    glEnd();
}
void sky2()
  {
        glBegin(GL_POLYGON);

   glColor3f(0.02f, 0.05f, 0.1f);



    glVertex2f(1000,1000);
    glVertex2f(1000,750);
    glVertex2f(0,750);

    glVertex2f(0,1000);
    glEnd();
  }

  void stars2()
{
    glPointSize(0.5);
    glBegin(GL_POINTS);
    glColor3ub(255, 255, 255);


    glVertex2f((0.8f + 1) * 500, (0.95f + 1) * 500);
    glVertex2f((0.9f + 1) * 500, (0.9f + 1) * 500);
    glVertex2f((0.95f + 1) * 500, (0.7f + 1) * 500);
    glVertex2f((0.8f + 1) * 500, (0.8f + 1) * 500);
    glVertex2f((0.7f + 1) * 500, (0.9f + 1) * 500);
    glVertex2f((0.6f + 1) * 500, (0.8f + 1) * 500);
    glVertex2f((0.5f + 1) * 500, (0.75f + 1) * 500);
    glVertex2f((0.4f + 1) * 500, (0.9f + 1) * 500);
    glVertex2f((0.3f + 1) * 500, (0.7f + 1) * 500);
    glVertex2f((0.25f + 1) * 500, (0.9f + 1) * 500);
    glVertex2f((0.25f + 1) * 500, (0.7f + 1) * 500);
    glVertex2f((0.1f + 1) * 500, (0.9f + 1) * 500);
    glVertex2f((0.15f + 1) * 500, (0.75f + 1) * 500);
    glVertex2f((0.0f + 1) * 500, (0.8f + 1) * 500);
    glVertex2f((-0.7f + 1) * 500, (0.9f + 1) * 500);
    glVertex2f((-0.8f + 1) * 500, (0.95f + 1) * 500);
    glVertex2f((-0.4f + 1) * 500, (0.8f + 1) * 500);
    glVertex2f((-0.8f + 1) * 500, (0.95f + 1) * 500);
    glVertex2f((-0.9f + 1) * 500, (0.9f + 1) * 500);
    glVertex2f((-0.95f + 1) * 500, (0.7f + 1) * 500);
    glVertex2f((-0.8f + 1) * 500, (0.8f + 1) * 500);

    glVertex2f((-0.1f + 1) * 500, (0.9f + 1) * 500);

    glEnd();
}


void moon2()
{
    glColor3f(1.0f, 1.0f, 1.0f);
    circle(30, 40, 500, 930);
}
void displayNight2()
{

    glClear(GL_COLOR_BUFFER_BIT);


drawWater();
drawRoad();

    sky2();
    glBegin(GL_POLYGON);
    glColor3f(0.05f, 0.2f, 0.05f);
    glVertex2f(1000,750);
    glVertex2f(1000,350);
    glVertex2f(0,350);
    glVertex2f(0,750);
    glEnd();


    stars();
    moon2();
    backgroundtreenight();
    drawWaternight();

    tree2night();
    housenight();
    house2night();
    house3night();
    fencenight();
    tree1night();
    wallnight();
    carnight();
    trucknight();

           glPushMatrix();
    glTranslatef(boatPosition, 0.0f, 0.0f);

     boat2night();

   glPopMatrix();

}
//Najmus
void drawDawnScene() {

    glClear(GL_COLOR_BUFFER_BIT);


    //Sky
    glColor3f(0.803f, 0.717f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(0, 0);
    glVertex2f(1000, 0);
    glVertex2f(1000, 1000);
    glVertex2f(0, 1000);
    glEnd();

    glPushMatrix();
    glTranslatef(0.0, sunY, 0.0f);
    // sun
    glColor3f(0.956f, 0.89f, 0.896f);
    drawCircle(830.f, 0.0f, 33.0f);
    glPopMatrix();

    // left cloud
    glPushMatrix();
    glTranslatef(cloud1X, 0.0f, 0.0f);
    glColor3f(0.956f, 0.8f, 0.976f);
    drawCircle(290.0f, 850.0f, 25.0f);
    drawCircle(250.0f, 850.0f, 35.0f);
    drawCircle(210.0f, 850.0f, 25.0f);
    glPopMatrix();


    //right cloud
    glPushMatrix();
    glTranslatef(cloud2X, 0.0f, 0.0f);
    glColor3f(0.956f, 0.8f, 0.976f);
    drawCircle(500.0f, 750.0f, 30.0f);
    drawCircle(550.0f, 750.0f, 45.0f);
    drawCircle(600.0f, 750.0f, 30.0f);
    glPopMatrix();


    // buildings
        //Building Far left
        glColor3f(0.657f, 0.563f, 0.9f);
        drawRectangle(0.0f, 0.0f, 100.0f, 600.0f);

        //Building far 2nd left
        glColor3f(0.657f, 0.563f, 0.9f);
        drawRectangle(100.0f, 0.0f, 100.0f, 650.0f);
        //3rd
        glColor3f(0.657f, 0.563f, 0.9f);
        drawRectangle(200.0f, 0.0f, 100.0f, 780.0f);
        glColor3f(0.657f, 0.563f, 0.9f);
        drawRectangle(300.0f, 0.0f, 100.0f, 650.0f);

        //4th
        glColor3f(0.657f, 0.563f, 0.9f);
        drawRectangle(500.0f, 0.0f, 200.0f, 580.0f);
        glColor3f(0.657f, 0.563f, 0.9f);
        drawRectangle(500.0f, 0.0f, 100.0f, 650.0f);

        //5th
        glColor3f(0.657f, 0.563f, 0.9f);
        drawRectangle(750.0f, 0.0f, 100.0f, 450.0f);
        glColor3f(0.657f, 0.563f, 0.9f);
        drawRectangle(800.0f, 0.0f, 100.0f, 650.0f);




        //building above
        glColor3f(0.988f, 0.72f, 0.921f);
        glBegin(GL_QUADS);
        glVertex2f(20, 750);
        glVertex2f(40, 700);
        glVertex2f(100, 700);
        glVertex2f(75, 750);
        glEnd();
        //First building on the left
        glColor3f(0.70f, 0.69f, 0.98f);
        drawRectangle(40.0f, 0.0f, 60.0f, 700.0f);
        //Shadow
        glColor3f(0.647f, 0.627f, 0.945f);
        glBegin(GL_QUADS);
        glVertex2f(40, 700);
        glVertex2f(100, 500);
        glVertex2f(100, 0);
        glVertex2f(40, 0);
        glEnd();


        //building left
        glColor3f(0.4f, 0.39f, 0.76f);
        glBegin(GL_QUADS);
        glVertex2f(40, 700);
        glVertex2f(20, 750);
        glVertex2f(20, 0);
        glVertex2f(40, 0);
        glEnd();

        //Windows
        glColor3f(0.842f, 0.839f, 0.960f);
        drawRectangle(50.0f,620.0f,10.0f,60.0f);

        glColor3f(0.4f, 0.39f, 0.76f);
        drawRectangle(65.0f,620.0f,10.0f,60.0f);

        glColor3f(0.842f, 0.839f, 0.960f);
        drawRectangle(80.0f,620.0f,10.0f,60.0f);

        //2nd row
        glColor3f(0.4f, 0.39f, 0.76f);
        drawRectangle(50.0f,540.0f,10.0f,60.0f);

        glColor3f(0.842f, 0.839f, 0.960f);
        drawRectangle(65.0f,540.0f,10.0f,60.0f);

        glColor3f(0.4f, 0.39f, 0.76f);
        drawRectangle(80.0f,540.0f,10.0f,60.0f);

        //3rd row
        glColor3f(0.842f, 0.839f, 0.960f);
        drawRectangle(50.0f,460.0f,10.0f,60.0f);

        glColor3f(0.4f, 0.39f, 0.76f);
        drawRectangle(65.0f,460.0f,10.0f,60.0f);

        glColor3f(0.842f, 0.839f, 0.960f);
        drawRectangle(80.0f,460.0f,10.0f,60.0f);



    //2nd building right side
    glColor3f(0.27f, 0.262f, 0.549f);
    drawRectangle(200.0f, 0.0f, 60.0f, 880.0f);

        //Windows
        glColor3f(0.482f, 0.482f, 0.866f);
        drawRectangle(200.0f,840.0f,50.0f,16.0f);

        glColor3f(0.298f, 0.282f, 0.584f);
        drawRectangle(200.0f,800.0f,50.0f,16.0f);

        glColor3f(0.482f, 0.482f, 0.866f);
        drawRectangle(200.0f,760.0f,50.0f,16.0f);

        glColor3f(0.298f, 0.282f, 0.584f);
        drawRectangle(200.0f,720.0f,50.0f,16.0f);

        glColor3f(0.482f, 0.482f, 0.866f);
        drawRectangle(200.0f,680.0f,50.0f,16.0f);

        glColor3f(0.298f, 0.282f, 0.584f);
        drawRectangle(200.0f,640.0f,50.0f,16.0f);

        glColor3f(0.482f, 0.482f, 0.866f);
        drawRectangle(200.0f,600.0f,50.0f,16.0f);

        glColor3f(0.298f, 0.282f, 0.584f);
        drawRectangle(200.0f,560.0f,50.0f,16.0f);

        glColor3f(0.482f, 0.482f, 0.866f);
        drawRectangle(200.0f,520.0f,50.0f,16.0f);

        glColor3f(0.298f, 0.282f, 0.584f);
        drawRectangle(200.0f,480.0f,50.0f,16.0f);

    //2nd Building
    glColor3f(0.4f, 0.39f, 0.76f);
    drawRectangle(120.0f, 0.0f, 80.0f, 900.0f);
    //Windows
        glColor3f(0.482f, 0.482f, 0.866f);
        drawRectangle(125.0f,860.0f,70.0f,20.0f);

        glColor3f(0.298f, 0.282f, 0.584f);
        drawRectangle(125.0f,820.0f,70.0f,20.0f);

        glColor3f(0.482f, 0.482f, 0.866f);
        drawRectangle(125.0f,780.0f,70.0f,20.0f);

        glColor3f(0.298f, 0.282f, 0.584f);
        drawRectangle(125.0f,740.0f,70.0f,20.0f);

        glColor3f(0.482f, 0.482f, 0.866f);
        drawRectangle(125.0f,700.0f,70.0f,20.0f);

        glColor3f(0.298f, 0.282f, 0.584f);
        drawRectangle(125.0f,660.0f,70.0f,20.0f);

        glColor3f(0.482f, 0.482f, 0.866f);
        drawRectangle(125.0f,620.0f,70.0f,20.0f);

        glColor3f(0.298f, 0.282f, 0.584f);
        drawRectangle(125.0f,580.0f,70.0f,20.0f);

        glColor3f(0.482f, 0.482f, 0.866f);
        drawRectangle(125.0f,540.0f,70.0f,20.0f);

        glColor3f(0.298f, 0.282f, 0.584f);
        drawRectangle(125.0f,500.0f,70.0f,20.0f);

        glColor3f(0.482f, 0.482f, 0.866f);
        drawRectangle(125.0f,460.0f,70.0f,20.0f);
    //5th building
        //building upper
        glColor3f(0.674f, 0.506f, 0.929f);
        glBegin(GL_QUADS);
        glVertex2f(630, 860);
        glVertex2f(640, 865);
        glVertex2f(760, 865);
        glVertex2f(750, 860);
        glEnd();

        //building Right
        glColor3f(0.348f, 0.209f, 0.579f);
        glBegin(GL_QUADS);
        glVertex2f(750, 860);
        glVertex2f(760, 865);
        glVertex2f(760, 0);
        glVertex2f(750, 0);
        glEnd();
        //main body
        glColor3f(0.298f, 0.267f, 0.609f);
        drawRectangle(630.0f, 0.0f, 120.0f, 860.0f);
        //shadow
        glColor3f(0.337f, 0.318f, 0.663f);
        glBegin(GL_TRIANGLES);
        glVertex2f(630, 860);
        glVertex2f(750, 860);
        glVertex2f(750, 400);
        glEnd();

        //Windows
        //1st row
        glColor3f(0.463f, 0.427f, 0.847f);
        drawRectangle(640.0f, 810.0f, 100.0f, 30.0f);
        //lines
        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(670, 810);
        glVertex2f(670, 840);
        glEnd();

        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(710, 810);
        glVertex2f(710, 840);
        glEnd();

        //2nd row
        glColor3f(0.463f, 0.427f, 0.847f);
        drawRectangle(640.0f, 760.0f, 100.0f, 30.0f);
        //lines
        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(670, 760);
        glVertex2f(670, 790);
        glEnd();

        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(710, 760);
        glVertex2f(710, 790);
        glEnd();

        //3rd row
        glColor3f(0.463f, 0.427f, 0.847f);
        drawRectangle(640.0f, 710.0f, 100.0f, 30.0f);
        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(670, 710);
        glVertex2f(670, 740);
        glEnd();

        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(710, 710);
        glVertex2f(710, 740);
        glEnd();
        //4th row
        glColor3f(0.463f, 0.427f, 0.847f);
        drawRectangle(640.0f, 660.0f, 100.0f, 30.0f);
        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(670, 660);
        glVertex2f(670, 690);
        glEnd();

        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(710, 660);
        glVertex2f(710, 690);
        glEnd();
        //5th row
        glColor3f(0.463f, 0.427f, 0.847f);
        drawRectangle(640.0f, 610.0f, 100.0f, 30.0f);
        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(670, 610);
        glVertex2f(670, 640);
        glEnd();

        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(710, 610);
        glVertex2f(710, 640);
        glEnd();
        //6th row
        glColor3f(0.463f, 0.427f, 0.847f);
        drawRectangle(640.0f, 560.0f, 100.0f, 30.0f);
        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(670, 560);
        glVertex2f(670, 590);
        glEnd();

        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(710, 560);
        glVertex2f(710, 590);
        glEnd();
        //7th row
        glColor3f(0.463f, 0.427f, 0.847f);
        drawRectangle(640.0f, 510.0f, 100.0f, 30.0f);
        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(670, 510);
        glVertex2f(670, 540);
        glEnd();

        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(710, 510);
        glVertex2f(710, 540);
        glEnd();
        //8th row
        glColor3f(0.463f, 0.427f, 0.847f);
        drawRectangle(640.0f, 460.0f, 100.0f, 30.0f);
        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(670, 460);
        glVertex2f(670, 490);
        glEnd();

        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(710, 460);
        glVertex2f(710, 490);
        glEnd();
        //9th row
        glColor3f(0.463f, 0.427f, 0.847f);
        drawRectangle(640.0f, 410.0f, 100.0f, 30.0f);
        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(670, 410);
        glVertex2f(670, 440);
        glEnd();

        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(710, 410);
        glVertex2f(710, 440);
        glEnd();
        //10th row
        glColor3f(0.463f, 0.427f, 0.847f);
        drawRectangle(640.0f, 360.0f, 100.0f, 30.0f);
        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(670, 360);
        glVertex2f(670, 390);
        glEnd();


        //11th row
        glColor3f(0.463f, 0.427f, 0.847f);
        drawRectangle(640.0f, 310.0f, 100.0f, 30.0f);
        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(670, 310);
        glVertex2f(670, 340);
        glEnd();

        //12th row
        glColor3f(0.463f, 0.427f, 0.847f);
        drawRectangle(640.0f, 260.0f, 100.0f, 30.0f);
        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(670, 260);
        glVertex2f(670, 290);
        glEnd();

        //13 th row
        glColor3f(0.463f, 0.427f, 0.847f);
        drawRectangle(640.0f, 210.0f, 100.0f, 30.0f);
        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(670, 210);
        glVertex2f(670, 240);
        glEnd();

        //14 th row
        glColor3f(0.463f, 0.427f, 0.847f);
        drawRectangle(640.0f, 160.0f, 100.0f, 30.0f);
        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(670, 160);
        glVertex2f(670, 190);
        glEnd();


    //4th building
        //left block upper
        glColor3f(0.674f, 0.506f, 0.929f);
        glBegin(GL_QUADS);
        glVertex2f(370, 700);
        glVertex2f(380, 720);
        glVertex2f(520, 720);
        glVertex2f(510, 700);
        glEnd();
        //Left block right
        glColor3f(0.553f, 0.361f, 0.851f);
        glBegin(GL_QUADS);
        glVertex2f(510, 700);
        glVertex2f(520, 720);
        glVertex2f(520, 500);
        glVertex2f(510, 500);
        glEnd();
        //left Block
        glColor3f(0.529f, 0.443f, 0.937f);
        drawRectangle(370.0f, 0.0f, 140.0f, 700.0f);



        //right block upper
        glColor3f(0.674f, 0.506f, 0.929f);
        glBegin(GL_QUADS);
        glVertex2f(510, 500);
        glVertex2f(520, 520);
        glVertex2f(650, 520);
        glVertex2f(640, 500);
        glEnd();
        //Right block right
        glColor3f(0.553f, 0.361f, 0.851f);
        glBegin(GL_QUADS);
        glVertex2f(640, 500);
        glVertex2f(650, 520);
        glVertex2f(650, 0);
        glVertex2f(640, 0);
        glEnd();
        //Right block
        glColor3f(0.529f, 0.443f, 0.937f);
        drawRectangle(510.0f, 0.0f, 130.0f, 500.0f);
        //Shadow
        glColor3f(0.502f, 0.419f, 0.886f);
        glBegin(GL_QUADS);
        glVertex2f(370, 700);
        glVertex2f(370, 0);
        glVertex2f(640, 0);
        glVertex2f(640,270);
        glEnd();

        //Left Block windows
        glColor3f(0.643f, 0.631f, 0.925f);
        drawRectangle(380.0f, 630.0f, 15.0f, 45.0f);

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(410.0f, 630.0f, 15.0f, 45.0f);

        glColor3f(0.643f, 0.631f, 0.925f);
        drawRectangle(455.0f, 630.0f, 15.0f, 45.0f);

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(485.0f, 630.0f, 15.0f, 45.0f);

        //2nd Row
        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(380.0f, 550.0f, 15.0f, 45.0f);

       glColor3f(0.643f, 0.631f, 0.925f);
        drawRectangle(410.0f, 550.0f, 15.0f, 45.0f);

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(455.0f, 550.0f, 15.0f, 45.0f);

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(485.0f, 550.0f, 15.0f, 45.0f);

        //3rd Row


       glColor3f(0.643f, 0.631f, 0.925f);
        drawRectangle(410.0f, 470.0f, 15.0f, 45.0f);

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(455.0f, 470.0f, 15.0f, 45.0f);

        glColor3f(0.643f, 0.631f, 0.925f);
        drawRectangle(485.0f, 470.0f, 15.0f, 45.0f);

        //4th row

        glColor3f(0.643f, 0.631f, 0.925f);
        drawRectangle(410.0f, 390.0f, 15.0f, 45.0f);

        glColor3f(0.643f, 0.631f, 0.925f);
        drawRectangle(455.0f, 390.0f, 15.0f, 45.0f);

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(485.0f, 390.0f, 15.0f, 45.0f);



        //5th row
        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(410.0f, 310.0f, 15.0f, 45.0f);

        glColor3f(0.643f, 0.631f, 0.925f);
        drawRectangle(455.0f, 310.0f, 15.0f, 45.0f);

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(485.0f, 310.0f, 15.0f, 45.0f);

        //6th row
        glColor3f(0.643f, 0.631f, 0.925f);
        drawRectangle(410.0f, 230.0f, 15.0f, 45.0f);

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(455.0f, 230.0f, 15.0f, 45.0f);

        glColor3f(0.643f, 0.631f, 0.925f);
        drawRectangle(485.0f, 230.0f, 15.0f, 45.0f);

        //7th row

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(410.0f, 150.0f, 15.0f, 45.0f);

        glColor3f(0.643f, 0.631f, 0.925f);
        drawRectangle(455.0f, 150.0f, 15.0f, 45.0f);

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(485.0f, 150.0f, 15.0f, 45.0f);

        //8th row
        glColor3f(0.643f, 0.631f, 0.925f);
        drawRectangle(410.0f, 70.0f, 15.0f, 45.0f);

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(455.0f, 70.0f, 15.0f, 45.0f);

        glColor3f(0.643f, 0.631f, 0.925f);
        drawRectangle(485.0f, 70.0f, 15.0f, 45.0f);

        //final row
        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(410.0f, -10.0f, 15.0f, 45.0f);

        glColor3f(0.643f, 0.631f, 0.925f);
        drawRectangle(455.0f, -10.0f, 15.0f, 45.0f);

        glColor3f(0.643f, 0.631f, 0.925f);
        drawRectangle(485.0f, -10.0f, 15.0f, 45.0f);
        //Right block window

        //1st row
        glColor3f(0.643f, 0.631f, 0.925f);
        drawRectangle(520.0f, 390.0f, 15.0f, 45.0f);

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(550.0f, 390.0f, 15.0f, 45.0f);

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(580.0f, 390.0f, 15.0f, 45.0f);

        glColor3f(0.643f, 0.631f, 0.925f);
        drawRectangle(610.0f, 390.0f, 15.0f, 45.0f);

        //2nd row
        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(520.0f, 310.0f, 15.0f, 45.0f);

        glColor3f(0.643f, 0.631f, 0.925f);
        drawRectangle(550.0f, 310.0f, 15.0f, 45.0f);

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(580.0f, 310.0f, 15.0f, 45.0f);

        glColor3f(0.643f, 0.631f, 0.925f);
        drawRectangle(610.0f, 310.0f, 15.0f, 45.0f);

        //3rd row
        glColor3f(0.643f, 0.631f, 0.925f);
        drawRectangle(520.0f, 230.0f, 15.0f, 45.0f);

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(550.0f, 230.0f, 15.0f, 45.0f);

        glColor3f(0.643f, 0.631f, 0.925f);
        drawRectangle(580.0f, 230.0f, 15.0f, 45.0f);

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(610.0f, 230.0f, 15.0f, 45.0f);

        //4th row
        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(520.0f, 150.0f, 15.0f, 45.0f);

        glColor3f(0.643f, 0.631f, 0.925f);
        drawRectangle(550.0f, 150.0f, 15.0f, 45.0f);

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(580.0f, 150.0f, 15.0f, 45.0f);

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(610.0f, 150.0f, 15.0f, 45.0f);

        //5th row
        glColor3f(0.643f, 0.631f, 0.925f);
        drawRectangle(520.0f, 70.0f, 15.0f, 45.0f);

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(550.0f, 70.0f, 15.0f, 45.0f);

        glColor3f(0.643f, 0.631f, 0.925f);
        drawRectangle(580.0f, 70.0f, 15.0f, 45.0f);

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(610.0f, 70.0f, 15.0f, 45.0f);

        //final row
        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(520.0f, -10.0f, 15.0f, 45.0f);

        glColor3f(0.643f, 0.631f, 0.925f);
        drawRectangle(550.0f, -10.0f, 15.0f, 45.0f);

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(580.0f, -10.0f, 15.0f, 45.0f);

        glColor3f(0.643f, 0.631f, 0.925f);
        drawRectangle(610.0f, -10.0f, 15.0f, 45.0f);




    //3rd Building
    //main body
        glColor3f(0.647f, 0.631f, 0.941f);
        drawRectangle(240.0f, 0.0f, 140.0f, 575.0f);
        //Shadow
        glColor3f(0.717f, 0.701f, 1.0f);
        glBegin(GL_TRIANGLES);
        glVertex2f(270, 575);
        glVertex2f(380, 575);
        glVertex2f(380, 400);
        glEnd();

        //Right Side
        glColor3f(0.612f, 0.537f, 1.0f);
        glBegin(GL_QUADS);
        glVertex2f(380, 575);
        glVertex2f(400, 590);
        glVertex2f(400, 0);
        glVertex2f(380, 0);
        glEnd();
        //Upper
        glColor3f(0.988f, 0.72f, 0.921f);
        glBegin(GL_QUADS);
        glVertex2f(380, 575);
        glVertex2f(400, 590);
        glVertex2f(260, 590);
        glVertex2f(240, 575);
        glEnd();

        //Windows
        //1st row
        glColor3f(0.831f, 0.831f, 0.992f);
        drawRectangle(250,500,15,40);
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(275,500,15,40);
        glColor3f(0.831f, 0.831f, 0.992f);
        drawRectangle(300,500,15,40);
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(325,500,15,40);
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(350,500,15,40);

        //2nd row
        glColor3f(0.831f, 0.831f, 0.992f);
        drawRectangle(250,450,15,40);
        glColor3f(0.831f, 0.831f, 0.992f);
        drawRectangle(275,450,15,40);
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(300,450,15,40);
        glColor3f(0.831f, 0.831f, 0.992f);
        drawRectangle(325,450,15,40);
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(350,450,15,40);


        //3rd row
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(250,400,15,40);
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(275,400,15,40);
        glColor3f(0.831f, 0.831f, 0.992f);
        drawRectangle(300,400,15,40);
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(325,400,15,40);
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(350,400,15,40);

        //4th row
        drawRectangle(250,350,15,40);
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(275,350,15,40);
        glColor3f(0.831f, 0.831f, 0.992f);
        drawRectangle(300,350,15,40);
        glColor3f(0.831f, 0.831f, 0.992f);
        drawRectangle(325,350,15,40);
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(350,350,15,40);

        //5th row
        drawRectangle(250,300,15,40);
        glColor3f(0.831f, 0.831f, 0.992f);
        drawRectangle(275,300,15,40);
        drawRectangle(300,300,15,40);
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(325,300,15,40);
        drawRectangle(350,300,15,40);

        //6th row
        drawRectangle(250,250,15,40);
        glColor3f(0.831f, 0.831f, 0.992f);
        drawRectangle(275,250,15,40);
        drawRectangle(300,250,15,40);
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(325,250,15,40);
        glColor3f(0.831f, 0.831f, 0.992f);
        drawRectangle(350,250,15,40);

        //7th row
        drawRectangle(250,200,15,40);
        drawRectangle(275,200,15,40);
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(300,200,15,40);
        drawRectangle(325,200,15,40);
        glColor3f(0.831f, 0.831f, 0.992f);
        drawRectangle(350,200,15,40);

        //8th row
        drawRectangle(250,150,15,40);
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(275,150,15,40);
        glColor3f(0.831f, 0.831f, 0.992f);
        drawRectangle(300,150,15,40);
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(325,150,15,40);
        glColor3f(0.831f, 0.831f, 0.992f);
        drawRectangle(350,150,15,40);

        //9th row
        drawRectangle(250,100,15,40);
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(275,100,15,40);
        drawRectangle(300,100,15,40);
        drawRectangle(325,100,15,40);
        glColor3f(0.831f, 0.831f, 0.992f);
        drawRectangle(350,100,15,40);

        //10th row
        drawRectangle(250,50,15,40);
        drawRectangle(275,50,15,40);
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(300,50,15,40);
        drawRectangle(325,50,15,40);
        glColor3f(0.831f, 0.831f, 0.992f);
        drawRectangle(350,50,15,40);

        //final row
        drawRectangle(250,0,15,40);
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(275,0,15,40);
        drawRectangle(300,0,15,40);
        drawRectangle(325,0,15,40);
        glColor3f(0.831f, 0.831f, 0.992f);
        drawRectangle(350,0,15,40);
    //First building Below
        //Upper Pillar
        glColor3f(0.76f, 0.75f, 0.992f);
        drawRectangle(0.0f, 418.0f, 245.0f, 50.0f);
        //Main Bulding
        glColor3f(0.76f, 0.75f, 0.992f);
        drawRectangle(0.0f, 0.0f, 230.0f, 418.0f);

        //Shadow
        glColor3f(0.607f, 0.584f, 0.914f);
        glBegin(GL_QUADS);
        glVertex2f(230, 418);
        glVertex2f(230, 410);
        glVertex2f(220, 410);
        glVertex2f(75, 418);
        glEnd();

        //Windows
        glColor3f(0.439f, 0.411f, 0.788f);
        drawRectangle(0,0,205,50);
        //Lines
        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(150, 0);
        glVertex2f(150, 50);
        glEnd();

        glColor3f(0.439f, 0.411f, 0.788f);
        drawRectangle(0,80,205,50);

        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(20, 80);
        glVertex2f(20, 130);
        glEnd();

        glColor3f(0.439f, 0.411f, 0.788f);
        drawRectangle(0,160,205,50);

        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(150, 160);
        glVertex2f(150, 210);
        glEnd();

        glColor3f(0.541f, 0.498f, 0.968f);
        drawRectangle(0,240,205,50);
        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(100, 240);
        glVertex2f(100, 290);
        glEnd();

        glColor3f(0.541f, 0.498f, 0.968f);
        drawRectangle(0,320,205,50);

        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(150, 320);
        glVertex2f(150, 370);
        glEnd();


    //7th Building Tower
        //Main Body
        glColor3f(0.498f, 0.409f, 0.886f);
        drawRectangle(870.0f, 0.0f, 120.0f, 750.0f);
        //shadow
        glColor3f(0.529f, 0.439f, 0.941f);
        glBegin(GL_TRIANGLES);
        glVertex2f(890, 750);
        glVertex2f(990, 750);
        glVertex2f(990, 500);
        glEnd();

        //Windows1
        glColor3f(0.294f, 0.274f, 0.604f);
        drawRectangle(885.0f, 0.0f, 15.0f, 730.0f);

        //Windows2
        glColor3f(0.294f, 0.274f, 0.604f);
        drawRectangle(910.0f, 0.0f, 15.0f, 730.0f);

        //Windows3
        glColor3f(0.294f, 0.274f, 0.604f);
        drawRectangle(935.0f, 0.0f, 15.0f, 730.0f);

        //Windows
        glColor3f(0.294f, 0.274f, 0.604f);
        drawRectangle(960.0f, 0.0f, 15.0f, 730.0f);

        //Upper railing
        glColor3f(0.294f, 0.274f, 0.604f);
        drawRectangle(880.0f, 750.0f, 100.0f, 20.0f);

        //Upper upper Railing
        glColor3f(0.498f, 0.409f, 0.886f);
        drawRectangle(915.0f, 770.0f, 30.0f, 10.0f);

        //Upper upper Railing
        glColor3f(0.294f, 0.274f, 0.604f);
        drawRectangle(928.0f, 780.0f, 5.0f, 70.0f);

        //Top Triangle
        glBegin(GL_TRIANGLES);
        glColor3f(0.294f, 0.274f, 0.604f);
        glVertex2f(928,850);
        glVertex2f(930.5,860);
        glVertex2f(933,850);
        glEnd();

        //drawRectangle(870.0f, 0.0f, 120.0f, 750.0f);

        //W logo
         glBegin(GL_QUADS);
        glColor3f(0.686f, 0.667f, 0.976f);
        glVertex2f(900,700);
        glVertex2f(920,700);
        glVertex2f(920,690);
        glVertex2f(900,690);
        glEnd();

         glBegin(GL_QUADS);
        glVertex2f(900,700);
        glVertex2f(910,700);
        glVertex2f(910,650);
        glVertex2f(900,650);
        glEnd();

        glBegin(GL_QUADS);
        glVertex2f(900,650);
        glVertex2f(910,650);
        glVertex2f(930,635);
        glVertex2f(930,625);
        glEnd();

        glBegin(GL_QUADS);
        glVertex2f(925,628);
        glVertex2f(925,690);
        glVertex2f(935,690);
        glVertex2f(935,628);
        glEnd();

        glBegin(GL_QUADS);
        glVertex2f(960,650);
        glVertex2f(950,650);
        glVertex2f(930,635);
        glVertex2f(930,625);
        glEnd();

        glBegin(GL_QUADS);
        glVertex2f(960,700);
        glVertex2f(950,700);
        glVertex2f(950,650);
        glVertex2f(960,650);
        glEnd();

        glBegin(GL_QUADS);
        glVertex2f(960,700);
        glVertex2f(940,700);
        glVertex2f(940,690);
        glVertex2f(960,690);
        glEnd();

    //6th Building with glasses
        //left glass
        glColor3f(0.686f, 0.667f, 0.976f);
        drawRectangle(680.0f, 0.0f, 80.0f, 400.0f);
        //Left Glass stripes
        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(706, 0);
        glVertex2f(706, 400);
        glEnd();

        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(735, 0);
        glVertex2f(735, 400);
        glEnd();


        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(680, 350);
        glVertex2f(760, 350);
        glEnd();

        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(680, 300);
        glVertex2f(760, 300);
        glEnd();

        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(680, 250);
        glVertex2f(760, 250);
        glEnd();

        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(680, 200);
        glVertex2f(760, 200);
        glEnd();

        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(680, 150);
        glVertex2f(760, 150);
        glEnd();

        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(680, 100);
        glVertex2f(760, 100);
        glEnd();

        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(680, 50);
        glVertex2f(760, 50);
        glEnd();
        //Striped End

        //Middle Building
        glColor3f(0.333f, 0.298f, 0.761f);
        drawRectangle(760.0f, 0.0f, 90.0f, 360.0f);
        //Middle Building Upper Railing
        glColor3f(0.369f, 0.2f, 0.565f);
        drawRectangle(760.0f, 360.0f, 90.0f, 20.0f);
        //Right glass
        glColor3f(0.686f, 0.667f, 0.976f);
        drawRectangle(850.0f, 0.0f, 80.0f, 400.0f);

        //Right Glass stripes
        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(876, 0);
        glVertex2f(876, 400);
        glEnd();

        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(906, 0);
        glVertex2f(906, 400);
        glEnd();


        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(850, 350);
        glVertex2f(930, 350);
        glEnd();

        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(850, 300);
        glVertex2f(930, 300);
        glEnd();

        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(850, 250);
        glVertex2f(930, 250);
        glEnd();

        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(850, 200);
        glVertex2f(930, 200);
        glEnd();

        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(850, 150);
        glVertex2f(930, 150);
        glEnd();

        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(850, 100);
        glVertex2f(930, 100);
        glEnd();

        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(850, 50);
        glVertex2f(930, 50);
        glEnd();
        //Stripes End

        //Middle Glass Connector
        glColor3f(0.369f, 0.2f, 0.565f);
        drawRectangle(680.0f, 250.0f, 250.0f, 5.0f);


    // Flyover
    //Black
    glColor3f(0.0f, 0.0f, 0.0f);
    drawRectangle(0.0f, 140.0f, 1000.0f, 50.0f);


    //white
    glColor3f(0.96f, 0.835f, 0.917f);
    drawRectangle(0.0f, 155.0f, 1000.0f, 30.0f);

    //Pillar1
    glColor3f(0.96f, 0.835f, 0.917f);
    quad(130,140,215,140,200,100,145,100);

    glColor3f(0.0f, 0.0f, 0.0f);
    quad(135,135,210,135,198,105,147,105);

    //upper ralling
        glLineWidth(10);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(140, 95);
        glVertex2f(205, 95);
        glEnd();
        //left
        glLineWidth(10);
        glColor3f(0.1f, 0.1f, 0.1f);
        glBegin(GL_LINES);
        glVertex2f(140, 95);
        glVertex2f(173, 50);
        glEnd();
        //right
        glLineWidth(10);
        glColor3f(0.1f, 0.1f, 0.1f);
        glBegin(GL_LINES);
        glVertex2f(205, 95);
        glVertex2f(172, 50);
        glEnd();

        glColor3f(0.96f, 0.835f, 0.917f);
        drawRectangle(157,0,30,100);

        //mid ralling
        glLineWidth(10);
        glColor3f(0.1f, 0.1f, 0.1f);
        glBegin(GL_LINES);
        glVertex2f(157, 70);
        glVertex2f(187, 70);
        glEnd();

        //Pillar2
        glColor3f(0.96f, 0.835f, 0.917f);
        quad(380,140,465,140,450,100,395,100);

        glColor3f(0.0f, 0.0f, 0.0f);
        quad(385,135,460,135,448,105,397,105);
    //upper ralling
        glLineWidth(10);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(390, 95);
        glVertex2f(450, 95);
        glEnd();
        //left
        glLineWidth(10);
        glColor3f(0.1f, 0.1f, 0.1f);
        glBegin(GL_LINES);
        glVertex2f(390, 95);
        glVertex2f(423, 50);
        glEnd();
        //right
        glLineWidth(10);
        glColor3f(0.1f, 0.1f, 0.1f);
        glBegin(GL_LINES);
        glVertex2f(451, 95);
        glVertex2f(423, 50);
        glEnd();



    glColor3f(0.96f, 0.835f, 0.917f);
    drawRectangle(407,0,30,100);

    //mid ralling
        glLineWidth(10);
        glColor3f(0.1f, 0.1f, 0.1f);
        glBegin(GL_LINES);
        glVertex2f(407, 70);
        glVertex2f(437, 70);
        glEnd();

    //Pillar3
        glColor3f(0.96f, 0.835f, 0.917f);
        quad(630,140,715,140,700,100,645,100);

        glColor3f(0.0f, 0.0f, 0.0f);
        quad(635,135,710,135,698,105,647,105);
        //upper ralling
        glLineWidth(10);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(640, 95);
        glVertex2f(705, 95);
        glEnd();
        //left
        glLineWidth(10);
        glColor3f(0.1f, 0.1f, 0.1f);
        glBegin(GL_LINES);
        glVertex2f(640, 95);
        glVertex2f(673, 50);
        glEnd();
        //right
        glLineWidth(10);
        glColor3f(0.1f, 0.1f, 0.1f);
        glBegin(GL_LINES);
        glVertex2f(705, 95);
        glVertex2f(672, 50);
        glEnd();


        glColor3f(0.96f, 0.835f, 0.917f);
        drawRectangle(657,0,30,100);

        //mid ralling
        glLineWidth(10);
        glColor3f(0.1f, 0.1f, 0.1f);
        glBegin(GL_LINES);
        glVertex2f(657, 70);
        glVertex2f(687, 70);
        glEnd();

    //Pillar4
        glColor3f(0.96f, 0.835f, 0.917f);
        quad(880,140,965,140,950,100,895,100);

        glColor3f(0.0f, 0.0f, 0.0f);
        quad(885,135,960,135,948,105,897,105);

        //upper ralling
        glLineWidth(10);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(890, 95);
        glVertex2f(955, 95);
        glEnd();
        //left raling
        glLineWidth(10);glColor3f(0.956f, 0.749f, 0.545f);
        glColor3f(0.1f, 0.1f, 0.1f);
        glBegin(GL_LINES);
        glVertex2f(890, 95);
        glVertex2f(922, 50);
        glEnd();
        //right line
        glLineWidth(10);
        glColor3f(0.1f, 0.1f, 0.1f);
        glBegin(GL_LINES);
        glVertex2f(955, 95);
        glVertex2f(922, 50);
        glEnd();

        //lowerpillar
        glColor3f(0.96f, 0.835f, 0.917f);
        drawRectangle(907,0,30,100);
        //mid ralling
        glLineWidth(10);
        glColor3f(0.1f, 0.1f, 0.1f);
        glBegin(GL_LINES);
        glVertex2f(907, 70);
        glVertex2f(937, 70);
        glEnd();
    //Bus

        glPushMatrix();
        glTranslatef(busX, 0.0f, 0.0f);

        //wheels
        //Left White Wheel Circle
        glColor3f(1.0f, 1.0f, 1.0f);
        drawCircle(735.0f, 201.0f, 14.0f);
        //LEft Inner Black Wheel Circle
        glColor3f(0.0f, 0.0f, 0.0f);
        drawCircle(735.0f, 201.0f, 9.0f);
        //Right Black Wheel Circle
        glColor3f(1.0f, 1.0f, 1.0f);
        drawCircle(885.0f, 201.0f, 14.0f);
        //Right Inner White Wheel Circle
        glColor3f(0.0f, 0.0f, 0.0f);
        drawCircle(885.0f, 201.0f, 9.0f);
        //Right Black Wheel Circle
        glColor3f(1.0f, 1.0f, 1.0f);
        drawCircle(915.0f, 201.0f, 14.0f);
        //Right Inner White Wheel Circle
        glColor3f(0.0f, 0.0f, 0.0f);
        drawCircle(915.0f, 201.0f, 9.0f);

        // Bus pink body
        glColor3f(0.956f, 0.749f, 0.545f);
        drawRectangle(700,207,250,103);
        //Upper Bus body
        glColor3f(0.956f, 0.749f, 0.545f);
        glBegin(GL_QUADS);
        glVertex2f(700, 310);
        glVertex2f(705, 317);
        glVertex2f(945, 317);
        glVertex2f(950, 310);
        glEnd();

        //lower body left part
        glColor3f(0.956f, 0.749f, 0.545f);
        glBegin(GL_QUADS);
        glVertex2f(700, 207);
        glVertex2f(700, 195);
        glVertex2f(718, 195);
        glVertex2f(725, 207);
        glEnd();
        //lower body middle part
        glColor3f(0.956f, 0.749f, 0.545f);
        glBegin(GL_QUADS);
        glVertex2f(745, 207);
        glVertex2f(752, 195);
        glVertex2f(865, 195);
        glVertex2f(872, 207);
        glEnd();
        //lower body right part
        glColor3f(0.956f, 0.749f, 0.545f);
        glBegin(GL_QUADS);
        glVertex2f(925, 207);
        glVertex2f(932, 195);
        glVertex2f(950, 195);
        glVertex2f(950, 207);
        glEnd();

        //Left Window
        //Top left part
        glColor3f(0.345f, 0.204f, 0.549f);
        glBegin(GL_QUADS);
        glVertex2f(700, 225);
        glVertex2f(715, 225);
        glVertex2f(715, 310);
        glVertex2f(700, 310);
        glEnd();
        //middle angular part
        glColor3f(0.345f, 0.204f, 0.549f);
        glBegin(GL_QUADS);
        glVertex2f(715, 225);
        glVertex2f(750, 240);
        glVertex2f(750, 310);
        glVertex2f(715, 310);
        glEnd();

        //Middle part
        drawRectangle(700,240,220,70);
        //right part
        glBegin(GL_QUADS);
        glVertex2f(920, 240);
        glVertex2f(950, 270);
        glVertex2f(950, 310);
        glVertex2f(920, 310);
        glEnd();

        //Purple shadow on window
        glColor3f(0.396f, 0.231f, 0.624f);
        glBegin(GL_QUADS);
        glVertex2f(700, 225);
        glVertex2f(715, 225);
        glVertex2f(715, 250);
        glVertex2f(700, 250);
        glEnd();

        //Purple shadow on window
        glColor3f(0.396f, 0.231f, 0.624f);
        glBegin(GL_QUADS);
        glVertex2f(715, 225);
        glVertex2f(750, 240);
        glVertex2f(750, 265);
        glVertex2f(715, 250);
        glEnd();

        //Purple shadow on window
        glColor3f(0.396f, 0.231f, 0.624f);
        glBegin(GL_QUADS);
        glVertex2f(750, 240);
        glVertex2f(920, 240);
        glVertex2f(920, 265);
        glVertex2f(750, 265);
        glEnd();

        //Purple shadow on window
        glColor3f(0.396f, 0.231f, 0.624f);
        glBegin(GL_QUADS);
        glVertex2f(920, 240);
        glVertex2f(950, 270);
        glVertex2f(950, 295);
        glVertex2f(920, 265);
        glEnd();

        //Lines On window
        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(750, 240);
        glVertex2f(750, 310);
        glEnd();

        //Lines On window
        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(800, 240);
        glVertex2f(800, 310);
        glEnd();

        //Lines On window
        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(860, 240);
        glVertex2f(860, 310);
        glEnd();


        //Lines On window
        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(920, 240);
        glVertex2f(920, 310);
        glEnd();

        //Lines On window
        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(750, 300);
        glVertex2f(920, 300);
        glEnd();

        //Stripes On glass
        glLineWidth(1);
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_LINES);
        glVertex2f(740, 270);
        glVertex2f(730, 300);
        glEnd();

        glLineWidth(1);
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_LINES);
        glVertex2f(735, 270);
        glVertex2f(728, 290);
        glEnd();

        //Stripes On glass
        glLineWidth(1);
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_LINES);
        glVertex2f(790, 270);
        glVertex2f(780, 300);
        glEnd();

        glLineWidth(1);
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_LINES);
        glVertex2f(785, 270);
        glVertex2f(778, 290);
        glEnd();

        //Stripes On glass
        glLineWidth(1);
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_LINES);
        glVertex2f(850, 270);
        glVertex2f(840, 300);
        glEnd();

        glLineWidth(1);
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_LINES);
        glVertex2f(845, 270);
        glVertex2f(838, 290);
        glEnd();

        //Stripes On glass
        glLineWidth(1);
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_LINES);
        glVertex2f(915, 270);
        glVertex2f(905, 300);
        glEnd();

        glLineWidth(1);
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_LINES);
        glVertex2f(910, 270);
        glVertex2f(902, 290);
        glEnd();






    glPopMatrix();

    //Birds
     glPushMatrix();
    glTranslatef(birdX, 0.0f, 0.0f);

    drawBird(25,800);
    drawBird(45,820);
    drawBird(65,795);
    drawBird(85,790);
    drawBird(5,785);


    glPopMatrix();
    // car
        glPushMatrix();
        glTranslatef(carX, 0.0f, 0.0f);


        // Car1 pink body
        glColor3f(0.925f, 0.408f, 0.980f);
        glBegin(GL_POLYGON);
        glVertex2f(235, 290);
        glVertex2f(155, 290);
        glVertex2f(145, 260);
        glVertex2f(130, 250);
        glVertex2f(130, 210);
        glVertex2f(235, 210);
        glEnd();

        //bumper
        glColor3f(0.321f, 0.207f, 0.505f);
        drawRectangle(128,205,108,5);

        //Left Window
        glColor3f(0.956f, 0.749f, 0.545f);
        glBegin(GL_QUADS);
        glVertex2f(230, 285);
        glVertex2f(170, 285);
        glVertex2f(170, 250);
        glVertex2f(230, 250);
        glEnd();

        //Yellow Shadow
        glBegin(GL_QUADS);
        glColor3f(0.882f, 0.647f, 0.443f);
        glVertex2f(230, 250);
        glVertex2f(170, 250);
        glVertex2f(170, 260);
        glVertex2f(230, 260);
        glEnd();

        //Right Window
       glColor3f(0.956f, 0.749f, 0.545f);
        glBegin(GL_POLYGON);
        glVertex2f(170, 250);
        glVertex2f(155, 260);
        glVertex2f(145, 260);
        glVertex2f(153, 285);
        glVertex2f(170, 285);
        glEnd();
        //yellow shadow
        glBegin(GL_QUADS);
        glColor3f(0.882f, 0.647f, 0.443f);
        glVertex2f(170, 250);
        glVertex2f(155, 255);
        glVertex2f(155, 265);
        glVertex2f(170, 260);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.882f, 0.647f, 0.443f);
        glVertex2f(155, 255);
        glVertex2f(145, 260);
        glVertex2f(148, 270);
        glVertex2f(155, 265);
        glEnd();

        //Stripes On glass
        glLineWidth(1);
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_LINES);
        glVertex2f(215, 270);
        glVertex2f(218, 260);
        glEnd();

        glLineWidth(1);
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_LINES);
        glVertex2f(210, 275);
        glVertex2f(214, 260);
        glEnd();

         //Stripes On glass
        glLineWidth(1);
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_LINES);
        glVertex2f(170, 270);
        glVertex2f(173, 260);

        glEnd();

        glLineWidth(1);
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_LINES);
        glVertex2f(173, 275);
        glVertex2f(178, 260);
        glEnd();


        //door knob
        glLineWidth(5);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(175, 243);
        glVertex2f(184, 243);
        glEnd();


        //Single line in window
        glLineWidth(3);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(172, 285);
        glVertex2f(172, 250);
        glEnd();

        glLineWidth(3);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(210, 285);
        glVertex2f(210, 250);
        glEnd();

        glLineWidth(2);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(165, 285);
        glVertex2f(160, 253);
        glEnd();
        //door lines
        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(172, 210);
        glVertex2f(172, 250);
        glEnd();

        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(210, 210);
        glVertex2f(210, 250);
        glEnd();



        //wheels
        //Left White Wheel Circle
        glColor3f(1.0f, 1.0f, 1.0f);
        drawCircle(155.0f, 203.0f, 13.0f);
        //LEft Inner Black Wheel Circle
        glColor3f(0.0f, 0.0f, 0.0f);
        drawCircle(155.0f, 203.0f, 8.0f);
        //Right Black Wheel Circle
        glColor3f(1.0f, 1.0f, 1.0f);
        drawCircle(215.0f, 203.0f, 13.0f);
        //Right Inner White Wheel Circle
        glColor3f(0.0f, 0.0f, 0.0f);
        drawCircle(215.0f, 203.0f, 8.0f);

    glPopMatrix();



        //Batmobile
        glPushMatrix();
        glTranslatef(batmobile, 0.0f, 0.0f);
        //body
        glColor3f(0.13f, 0.13f, 0.13f);
        glBegin(GL_POLYGON);
        glVertex2f(60, 200);
        glVertex2f(53, 210);
        glVertex2f(30, 255);
        glVertex2f(35, 260);
        glVertex2f(140, 250);
        glVertex2f(205, 240);
        glVertex2f(210, 233);
        glVertex2f(215, 200);
        glEnd();


        //Head
        glColor3f(0.13f, 0.13f, 0.13f);
        glBegin(GL_POLYGON);
        glVertex2f(62, 250);
        glVertex2f(70, 260);
        glVertex2f(75, 275);
        glVertex2f(130, 266);
        glVertex2f(135, 262);
        glVertex2f(140, 250);
        glEnd();

        //back fang
        glColor3f(0.067f, 0.016f, 0.158f);
        glBegin(GL_POLYGON);
        glVertex2f(30, 255);
        glVertex2f(26, 250);
        glVertex2f(40, 245);
        glVertex2f(30, 240);
        glVertex2f(50, 235);
        glVertex2f(32, 230);
        glVertex2f(60, 225);
        glVertex2f(35, 220);
        glVertex2f(70, 215);
        glVertex2f(38, 210);
        glVertex2f(80, 205);
        glEnd();

        //Shadows
        glColor3f(0.05f, 0.05f, 0.05f);
        glBegin(GL_QUADS);
        glVertex2f(30, 255);
        glVertex2f(60, 200);
        glVertex2f(210, 200);
        glVertex2f(130, 240);
        glEnd();

        //wheels
        //Left White Wheel Circle
        glColor3f(0.0f, 0.0f, 0.0f);
        drawCircle(80.0f, 202.0f, 12.0f);
        //LEft Inner Black Wheel Circle
        glColor3f(0.3f, 0.3f, 0.3f);
        drawCircle(80.0f, 202.0f, 7.0f);
        //Right Black Wheel Circle
        glColor3f(0.0f, 0.0f, 0.0f);
        drawCircle(180.0f, 202.0f, 12.0f);
        //Right Inner White Wheel Circle
        glColor3f(0.3f, 0.3f, 0.3f);
        drawCircle(180.0f, 202.0f, 7.0f);

        //windows
        glColor3f(0.396f, 0.339f, 0.491f);
        glBegin(GL_QUADS);
        glVertex2f(107, 268);
        glVertex2f(133, 263);
        glVertex2f(139, 248);
        glVertex2f(100, 250);
        glEnd();

        //window shadow
        glColor3f(0.296f, 0.239f, 0.391f);
        glBegin(GL_QUADS);
        glVertex2f(103, 258);
        glVertex2f(133, 253);
        glVertex2f(139, 248);
        glVertex2f(100, 250);
        glEnd();

        //windows stripes
        glLineWidth(1);
        glColor3f(0.803f, 0.717f, 1.0f);
        glBegin(GL_LINES);
        glVertex2f(119, 261);
        glVertex2f(125, 259);
        glEnd();

        glLineWidth(1);
        glColor3f(0.803f, 0.717f, 1.0f);
        glBegin(GL_LINES);
        glVertex2f(118, 258);
        glVertex2f(129, 255);
        glEnd();


    glPopMatrix();

    glutSwapBuffers();
}

void drawNightScene() {

    glClear(GL_COLOR_BUFFER_BIT);

    //Sky
    glColor3f(0.4f, 0.4f, 0.6f);
    glBegin(GL_QUADS);
    glVertex2f(0, 0);
    glVertex2f(1000, 0);
    glVertex2f(1000, 1000);
    glVertex2f(0, 1000);
    glEnd();

    // Moon
    glPushMatrix();
    glTranslatef(0.0, sunY, 0.0f);
    glColor3f(0.85f, 0.8f, 0.95f);
    drawCircle(830.0f, 0.0f, 30.0f);
    glColor3f(0.4f, 0.4f, 0.6f);
    drawCircle(836.0f, 10.0f, 30.0f);
    glPopMatrix();

    // sun
    glColor3f(0.956f, 0.89f, 0.896f);
    drawCircle(900.f, 0.0f, 33.0f);


    //batsingal
        if(batsignal)
        {
        //light ray
        glColor3f(0.756f, 0.79f, 0.896f);
        glBegin(GL_TRIANGLES);
        glVertex2f(280, 800);
        glVertex2f(440, 850);
        glVertex2f(700,400);
        glEnd();

        glColor3f(0.956f, 0.89f, 0.896f);
        drawEllipse(350.0f,850.0f,90,90);//yellow light

        glColor3f(0.0f, 0.0f, 0.0f);
        //black signal light
        drawEllipse(350.0f,850.0f,80,60);

        glColor3f(0.956f, 0.89f, 0.896f);
        drawEllipse(350.0f,910.0f,10,7);//head
        //left wing
        drawEllipse(310.0f,890.0f,20,20);//upper
        drawEllipse(330.0f,900.0f,9,20);//ear
        drawEllipse(300.0f,800.0f,10,18);//lower left
        drawEllipse(320.0f,805.0f,15,28);//lower right
        drawEllipse(325.0f,803.0f,20,28);//lower tail
        drawEllipse(342.0f,790.0f,7,25);//bottom tail

        //Right Wing
        drawEllipse(390.0f,890.0f,20,20);//upper
        drawEllipse(370.0f,900.0f,9,20);//ear
        drawEllipse(400.0f,800.0f,10,18);//lower left
        drawEllipse(380.0f,805.0f,15,28);//lower right
        drawEllipse(375.0f,803.0f,20,28);//lower tail
        drawEllipse(357.0f,790.0f,7,25);//bottom tail
        }

    //Plane

         glPushMatrix();
    glTranslatef(planeX, planeY, 0.0f);
        //Back Wing
        glColor3f(0.4f, 0.3f, 0.45f);
        glBegin(GL_QUADS);
        glVertex2f(560, 810);
        glVertex2f(535, 840);
        glVertex2f(525, 843);
        glVertex2f(540, 810);
        glEnd();


        //Plane Body
        glColor3f(0.439f, 0.411f, 0.788f);
        glBegin(GL_POLYGON);
        glVertex2f(463, 800);
        glVertex2f(610, 830);
        glVertex2f(625, 815);
        glVertex2f(627, 810);
        glVertex2f(618, 795);
        glVertex2f(497, 772);
        glVertex2f(480, 785);
        glEnd();

        //shadow
        glColor3f(0.294f, 0.274f, 0.604f);
        glBegin(GL_QUADS);
        glVertex2f(497, 772);
        glVertex2f(482, 783);
        glVertex2f(627, 813);
        glVertex2f(618, 795);
        glEnd();




        //Plane Tail
        glColor3f(0.4f, 0.3f, 0.45f);
        glBegin(GL_POLYGON);
        glVertex2f(473, 800);
        glVertex2f(487, 803);
        glVertex2f(482, 807);
        glVertex2f(477, 807);
        glVertex2f(465, 840);
        glVertex2f(453, 845);
        glVertex2f(463, 800);
        glEnd();

        //Tail Shadow
        glColor3f(0.294f, 0.274f, 0.604f);
        glBegin(GL_POLYGON);
        glVertex2f(469, 807);
        glVertex2f(461, 842);
        glVertex2f(453, 845);
        glVertex2f(463, 800);
        glVertex2f(482, 783);
        glVertex2f(485, 783);
        glEnd();

        //Forward Wing
        glColor3f(0.4f, 0.3f, 0.45f);
        glBegin(GL_POLYGON);
        glVertex2f(565, 798);
        glVertex2f(542, 740);
        glVertex2f(527, 735);
        glVertex2f(542, 785);
        glVertex2f(540, 793);
        glEnd();

        //windows
        glColor3f(0.984f, 0.714f, 0.682f);
        drawCircle(560.0f, 805.0f, 5.0f);

        drawCircle(545.0f, 802.0f, 5.0f);

        drawCircle(530.0f, 799.0f, 5.0f);

        drawCircle(515.0f, 796.0f, 5.0f);

        drawCircle(500.0f, 793.0f, 5.0f);

        drawCircle(575.0f, 808.0f, 5.0f);

        drawCircle(590.0f, 811.0f, 5.0f);

        //Front Window
        glColor3f(0.984f, 0.714f, 0.682f);
        glBegin(GL_QUADS);
        glVertex2f(621, 819);
        glVertex2f(610, 830);
        glVertex2f(603, 829);
        glVertex2f(604, 815);
        glEnd();

    glPopMatrix();

    // left cloud
    glPushMatrix();
    glTranslatef(cloud1X, 0.0f, 0.0f);
    glColor3f(0.8f, 0.75f, 0.9f);
    drawCircle(290.0f, 850.0f, 25.0f);
    drawCircle(250.0f, 850.0f, 35.0f);
    drawCircle(210.0f, 850.0f, 25.0f);
    glPopMatrix();

    //right cloud
    glPushMatrix();
    glTranslatef(cloud2X, 0.0f, 0.0f);
    glColor3f(0.8f, 0.75f, 0.9f);
    drawCircle(500.0f, 750.0f, 30.0f);
    drawCircle(550.0f, 750.0f, 45.0f);
    drawCircle(600.0f, 750.0f, 30.0f);
    glPopMatrix();


    // buildings
        //Building Far left
        glColor3f(0.2f, 0.15f, 0.26f);
        drawRectangle(0.0f, 0.0f, 100.0f, 600.0f);

        //Building far 2nd left
        drawRectangle(100.0f, 0.0f, 100.0f, 650.0f);
        //3rd
        drawRectangle(200.0f, 0.0f, 100.0f, 780.0f);
        drawRectangle(300.0f, 0.0f, 100.0f, 650.0f);

        //4th
        drawRectangle(500.0f, 0.0f, 200.0f, 580.0f);
        drawRectangle(500.0f, 0.0f, 100.0f, 650.0f);

        //5th
        drawRectangle(750.0f, 0.0f, 100.0f, 450.0f);
        drawRectangle(800.0f, 0.0f, 100.0f, 650.0f);




        //building above
        glColor3f(0.4f, 0.3f, 0.45f);
        glBegin(GL_QUADS);
        glVertex2f(20, 750);
        glVertex2f(40, 700);
        glVertex2f(100, 700);
        glVertex2f(75, 750);
        glEnd();
        //First building on the left
        glColor3f(0.25f, 0.2f, 0.4f);
        drawRectangle(40.0f, 0.0f, 60.0f, 700.0f);
        //Shadow
        glColor3f(0.2f, 0.15f, 0.3f);
        glBegin(GL_QUADS);
        glVertex2f(40, 700);
        glVertex2f(100, 500);
        glVertex2f(100, 0);
        glVertex2f(40, 0);
        glEnd();


        //building left
        glColor3f(0.15f, 0.1f, 0.3f);
        glBegin(GL_QUADS);
        glVertex2f(40, 700);
        glVertex2f(20, 750);
        glVertex2f(20, 0);
        glVertex2f(40, 0);
        glEnd();

        //Windows
       glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(50.0f,620.0f,10.0f,60.0f);

        glColor3f(0.4f, 0.39f, 0.76f);
        drawRectangle(65.0f,620.0f,10.0f,60.0f);

        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(80.0f,620.0f,10.0f,60.0f);

        //2nd row
        glColor3f(0.4f, 0.39f, 0.76f);
        drawRectangle(50.0f,540.0f,10.0f,60.0f);

        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(65.0f,540.0f,10.0f,60.0f);

        glColor3f(0.4f, 0.39f, 0.76f);
        drawRectangle(80.0f,540.0f,10.0f,60.0f);

        //3rd row
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(50.0f,460.0f,10.0f,60.0f);

        glColor3f(0.4f, 0.39f, 0.76f);
        drawRectangle(65.0f,460.0f,10.0f,60.0f);

        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(80.0f,460.0f,10.0f,60.0f);



    //2nd building right side
    glColor3f(0.1f, 0.1f, 0.3f);
    drawRectangle(200.0f, 0.0f, 60.0f, 880.0f);

        //Windows
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(200.0f,840.0f,50.0f,16.0f);

        glColor3f(0.298f, 0.282f, 0.584f);
        drawRectangle(200.0f,800.0f,50.0f,16.0f);

        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(200.0f,760.0f,50.0f,16.0f);

        glColor3f(0.298f, 0.282f, 0.584f);
        drawRectangle(200.0f,720.0f,50.0f,16.0f);

        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(200.0f,680.0f,50.0f,16.0f);

        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(200.0f,640.0f,50.0f,16.0f);

        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(200.0f,600.0f,50.0f,16.0f);

        glColor3f(0.298f, 0.282f, 0.584f);
        drawRectangle(200.0f,560.0f,50.0f,16.0f);

        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(200.0f,520.0f,50.0f,16.0f);

       glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(200.0f,480.0f,50.0f,16.0f);

    //2nd Building
    glColor3f(0.15f, 0.1f, 0.3f);
    drawRectangle(120.0f, 0.0f, 80.0f, 900.0f);
    //Windows
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(125.0f,860.0f,70.0f,20.0f);

        glColor3f(0.298f, 0.282f, 0.584f);
        drawRectangle(125.0f,820.0f,70.0f,20.0f);

        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(125.0f,780.0f,70.0f,20.0f);

        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(125.0f,740.0f,70.0f,20.0f);

        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(125.0f,700.0f,70.0f,20.0f);

        glColor3f(0.298f, 0.282f, 0.584f);
        drawRectangle(125.0f,660.0f,70.0f,20.0f);

        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(125.0f,620.0f,70.0f,20.0f);

        glColor3f(0.298f, 0.282f, 0.584f);
        drawRectangle(125.0f,580.0f,70.0f,20.0f);

        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(125.0f,540.0f,70.0f,20.0f);

        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(125.0f,500.0f,70.0f,20.0f);

        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(125.0f,460.0f,70.0f,20.0f);
    //5th building
        //building upper
        glColor3f(0.2f, 0.15f, 0.3f);
        glBegin(GL_QUADS);
        glVertex2f(630, 860);
        glVertex2f(640, 865);
        glVertex2f(760, 865);
        glVertex2f(750, 860);
        glEnd();

        //building Right
        glColor3f(0.1f, 0.05f, 0.2f);
        glBegin(GL_QUADS);
        glVertex2f(750, 860);
        glVertex2f(760, 865);
        glVertex2f(760, 0);
        glVertex2f(750, 0);
        glEnd();
        //main body
        glColor3f(0.1f, 0.1f, 0.3f);
        drawRectangle(630.0f, 0.0f, 120.0f, 860.0f);
        //shadow
        glColor3f(0.1f, 0.1f, 0.3f);
        glBegin(GL_TRIANGLES);
        glVertex2f(630, 860);
        glVertex2f(750, 860);
        glVertex2f(750, 400);
        glEnd();

        //Windows
        //1st row
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(640.0f, 810.0f, 100.0f, 30.0f);
        //lines
        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(670, 810);
        glVertex2f(670, 840);
        glEnd();

        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(710, 810);
        glVertex2f(710, 840);
        glEnd();

        //2nd row
        glColor3f(0.463f, 0.427f, 0.847f);
        drawRectangle(640.0f, 760.0f, 100.0f, 30.0f);
        //lines
        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(670, 760);
        glVertex2f(670, 790);
        glEnd();

        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(710, 760);
        glVertex2f(710, 790);
        glEnd();

        //3rd row
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(640.0f, 710.0f, 100.0f, 30.0f);
        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(670, 710);
        glVertex2f(670, 740);
        glEnd();

        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(710, 710);
        glVertex2f(710, 740);
        glEnd();
        //4th row
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(640.0f, 660.0f, 100.0f, 30.0f);
        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(670, 660);
        glVertex2f(670, 690);
        glEnd();

        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(710, 660);
        glVertex2f(710, 690);
        glEnd();
        //5th row
        glColor3f(0.463f, 0.427f, 0.847f);
        drawRectangle(640.0f, 610.0f, 100.0f, 30.0f);
        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(670, 610);
        glVertex2f(670, 640);
        glEnd();

        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(710, 610);
        glVertex2f(710, 640);
        glEnd();
        //6th row
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(640.0f, 560.0f, 100.0f, 30.0f);
        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(670, 560);
        glVertex2f(670, 590);
        glEnd();

        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(710, 560);
        glVertex2f(710, 590);
        glEnd();
        //7th row
        glColor3f(0.463f, 0.427f, 0.847f);
        drawRectangle(640.0f, 510.0f, 100.0f, 30.0f);
        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(670, 510);
        glVertex2f(670, 540);
        glEnd();

        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(710, 510);
        glVertex2f(710, 540);
        glEnd();
        //8th row
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(640.0f, 460.0f, 100.0f, 30.0f);
        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(670, 460);
        glVertex2f(670, 490);
        glEnd();

        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(710, 460);
        glVertex2f(710, 490);
        glEnd();
        //9th row
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(640.0f, 410.0f, 100.0f, 30.0f);
        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(670, 410);
        glVertex2f(670, 440);
        glEnd();

        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(710, 410);
        glVertex2f(710, 440);
        glEnd();
        //10th row
        glColor3f(0.463f, 0.427f, 0.847f);
        drawRectangle(640.0f, 360.0f, 100.0f, 30.0f);
        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(670, 360);
        glVertex2f(670, 390);
        glEnd();


        //11th row
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(640.0f, 310.0f, 100.0f, 30.0f);
        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(670, 310);
        glVertex2f(670, 340);
        glEnd();

        //12th row
        glColor3f(0.463f, 0.427f, 0.847f);
        drawRectangle(640.0f, 260.0f, 100.0f, 30.0f);
        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(670, 260);
        glVertex2f(670, 290);
        glEnd();

        //13 th row
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(640.0f, 210.0f, 100.0f, 30.0f);
        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(670, 210);
        glVertex2f(670, 240);
        glEnd();

        //14 th row
        glColor3f(0.463f, 0.427f, 0.847f);
        drawRectangle(640.0f, 160.0f, 100.0f, 30.0f);
        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(670, 160);
        glVertex2f(670, 190);
        glEnd();


    //4th building
        //left block upper
        glColor3f(0.2f, 0.15f, 0.3f);
        glBegin(GL_QUADS);
        glVertex2f(370, 700);
        glVertex2f(380, 720);
        glVertex2f(520, 720);
        glVertex2f(510, 700);
        glEnd();
        //Left block right
        glColor3f(0.2f, 0.1f, 0.3f);
        glBegin(GL_QUADS);
        glVertex2f(510, 700);
        glVertex2f(520, 720);
        glVertex2f(520, 500);
        glVertex2f(510, 500);
        glEnd();
        //left Block
        glColor3f(0.15f, 0.1f, 0.3f);
        drawRectangle(370.0f, 0.0f, 140.0f, 700.0f);



        //right block upper
        glColor3f(0.2f, 0.15f, 0.3f);
        glBegin(GL_QUADS);
        glVertex2f(510, 500);
        glVertex2f(520, 520);
        glVertex2f(650, 520);
        glVertex2f(640, 500);
        glEnd();
        //Right block right
        glColor3f(0.2f, 0.1f, 0.3f);
        glBegin(GL_QUADS);
        glVertex2f(640, 500);
        glVertex2f(650, 520);
        glVertex2f(650, 0);
        glVertex2f(640, 0);
        glEnd();
        //Right block
        glColor3f(0.15f, 0.1f, 0.3f);
        drawRectangle(510.0f, 0.0f, 130.0f, 500.0f);
        //Shadow
        glColor3f(0.15f, 0.1f, 0.3f);
        glBegin(GL_QUADS);
        glVertex2f(370, 700);
        glVertex2f(370, 0);
        glVertex2f(640, 0);
        glVertex2f(640,270);
        glEnd();

        //Left Block windows
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(380.0f, 630.0f, 15.0f, 45.0f);

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(410.0f, 630.0f, 15.0f, 45.0f);

        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(455.0f, 630.0f, 15.0f, 45.0f);

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(485.0f, 630.0f, 15.0f, 45.0f);

        //2nd Row
        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(380.0f, 550.0f, 15.0f, 45.0f);

       glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(410.0f, 550.0f, 15.0f, 45.0f);

       glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(455.0f, 550.0f, 15.0f, 45.0f);

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(485.0f, 550.0f, 15.0f, 45.0f);

        //3rd Row


       glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(410.0f, 470.0f, 15.0f, 45.0f);

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(455.0f, 470.0f, 15.0f, 45.0f);

        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(485.0f, 470.0f, 15.0f, 45.0f);

        //4th row

        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(410.0f, 390.0f, 15.0f, 45.0f);

        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(455.0f, 390.0f, 15.0f, 45.0f);

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(485.0f, 390.0f, 15.0f, 45.0f);



        //5th row
        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(410.0f, 310.0f, 15.0f, 45.0f);

        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(455.0f, 310.0f, 15.0f, 45.0f);

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(485.0f, 310.0f, 15.0f, 45.0f);

        //6th row
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(410.0f, 230.0f, 15.0f, 45.0f);

        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(455.0f, 230.0f, 15.0f, 45.0f);

        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(485.0f, 230.0f, 15.0f, 45.0f);

        //7th row

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(410.0f, 150.0f, 15.0f, 45.0f);

        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(455.0f, 150.0f, 15.0f, 45.0f);

        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(485.0f, 150.0f, 15.0f, 45.0f);

        //8th row
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(410.0f, 70.0f, 15.0f, 45.0f);

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(455.0f, 70.0f, 15.0f, 45.0f);

        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(485.0f, 70.0f, 15.0f, 45.0f);

        //final row
        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(410.0f, -10.0f, 15.0f, 45.0f);

        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(455.0f, -10.0f, 15.0f, 45.0f);

       glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(485.0f, -10.0f, 15.0f, 45.0f);
        //Right block window

        //1st row
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(520.0f, 390.0f, 15.0f, 45.0f);

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(550.0f, 390.0f, 15.0f, 45.0f);

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(580.0f, 390.0f, 15.0f, 45.0f);

        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(610.0f, 390.0f, 15.0f, 45.0f);

        //2nd row
        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(520.0f, 310.0f, 15.0f, 45.0f);

        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(550.0f, 310.0f, 15.0f, 45.0f);

        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(580.0f, 310.0f, 15.0f, 45.0f);

        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(610.0f, 310.0f, 15.0f, 45.0f);

        //3rd row
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(520.0f, 230.0f, 15.0f, 45.0f);

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(550.0f, 230.0f, 15.0f, 45.0f);

       glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(580.0f, 230.0f, 15.0f, 45.0f);

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(610.0f, 230.0f, 15.0f, 45.0f);

        //4th row
        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(520.0f, 150.0f, 15.0f, 45.0f);

        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(550.0f, 150.0f, 15.0f, 45.0f);

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(580.0f, 150.0f, 15.0f, 45.0f);

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(610.0f, 150.0f, 15.0f, 45.0f);

        //5th row
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(520.0f, 70.0f, 15.0f, 45.0f);

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(550.0f, 70.0f, 15.0f, 45.0f);

        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(580.0f, 70.0f, 15.0f, 45.0f);

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(610.0f, 70.0f, 15.0f, 45.0f);

        //final row
        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(520.0f, -10.0f, 15.0f, 45.0f);

        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(550.0f, -10.0f, 15.0f, 45.0f);

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(580.0f, -10.0f, 15.0f, 45.0f);

        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(610.0f, -10.0f, 15.0f, 45.0f);




    //3rd Building
    //main body
        glColor3f(0.2f, 0.15f, 0.3f);
        drawRectangle(240.0f, 0.0f, 140.0f, 575.0f);
        //Shadow
        glColor3f(0.2f, 0.15f, 0.35f);
        glBegin(GL_TRIANGLES);
        glVertex2f(270, 575);
        glVertex2f(380, 575);
        glVertex2f(380, 400);
        glEnd();

        //Right Side
        glColor3f(0.15f, 0.15f, 0.3f);
        glBegin(GL_QUADS);
        glVertex2f(380, 575);
        glVertex2f(400, 590);
        glVertex2f(400, 0);
        glVertex2f(380, 0);
        glEnd();
        //Upper
        glColor3f(0.2f, 0.1f, 0.3f);
        glBegin(GL_QUADS);
        glVertex2f(380, 575);
        glVertex2f(400, 590);
        glVertex2f(260, 590);
        glVertex2f(240, 575);
        glEnd();

        //Windows
        //1st row
        glColor3f(0.831f, 0.831f, 0.992f);
        drawRectangle(250,500,15,40);
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(275,500,15,40);
        glColor3f(0.831f, 0.831f, 0.992f);
        drawRectangle(300,500,15,40);
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(325,500,15,40);
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(350,500,15,40);

        //2nd row
        glColor3f(0.831f, 0.831f, 0.992f);
        drawRectangle(250,450,15,40);
        glColor3f(0.831f, 0.831f, 0.992f);
        drawRectangle(275,450,15,40);
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(300,450,15,40);
        glColor3f(0.831f, 0.831f, 0.992f);
        drawRectangle(325,450,15,40);
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(350,450,15,40);


        //3rd row
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(250,400,15,40);
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(275,400,15,40);
        glColor3f(0.831f, 0.831f, 0.992f);
        drawRectangle(300,400,15,40);
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(325,400,15,40);
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(350,400,15,40);

        //4th row
        drawRectangle(250,350,15,40);
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(275,350,15,40);
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(300,350,15,40);
        glColor3f(0.831f, 0.831f, 0.992f);
        drawRectangle(325,350,15,40);
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(350,350,15,40);

        //5th row
        drawRectangle(250,300,15,40);
        glColor3f(0.831f, 0.831f, 0.992f);
        drawRectangle(275,300,15,40);
        drawRectangle(300,300,15,40);
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(325,300,15,40);
        drawRectangle(350,300,15,40);

        //6th row
        drawRectangle(250,250,15,40);
        glColor3f(0.831f, 0.831f, 0.992f);
        drawRectangle(275,250,15,40);
        drawRectangle(300,250,15,40);
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(325,250,15,40);
        glColor3f(0.831f, 0.831f, 0.992f);
        drawRectangle(350,250,15,40);

        //7th row
        drawRectangle(250,200,15,40);
        drawRectangle(275,200,15,40);
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(300,200,15,40);
        drawRectangle(325,200,15,40);
        glColor3f(0.831f, 0.831f, 0.992f);
        drawRectangle(350,200,15,40);

        //8th row
        drawRectangle(250,150,15,40);
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(275,150,15,40);
        glColor3f(0.831f, 0.831f, 0.992f);
        drawRectangle(300,150,15,40);
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(325,150,15,40);
        glColor3f(0.831f, 0.831f, 0.992f);
        drawRectangle(350,150,15,40);

        //9th row
        drawRectangle(250,100,15,40);
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(275,100,15,40);
        drawRectangle(300,100,15,40);
        drawRectangle(325,100,15,40);
        glColor3f(0.831f, 0.831f, 0.992f);
        drawRectangle(350,100,15,40);

        //10th row
        drawRectangle(250,50,15,40);
        drawRectangle(275,50,15,40);
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(300,50,15,40);
        drawRectangle(325,50,15,40);
        glColor3f(0.831f, 0.831f, 0.992f);
        drawRectangle(350,50,15,40);

        //final row
        drawRectangle(250,0,15,40);
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(275,0,15,40);
        drawRectangle(300,0,15,40);
        drawRectangle(325,0,15,40);
        glColor3f(0.831f, 0.831f, 0.992f);
        drawRectangle(350,0,15,40);
    //First building Below
        //Upper Pillar
        glColor3f(0.2f, 0.15f, 0.37f);
        drawRectangle(0.0f, 418.0f, 245.0f, 50.0f);
        //Main Bulding
        glColor3f(0.2f, 0.15f, 0.37f);
        drawRectangle(0.0f, 0.0f, 230.0f, 418.0f);

        //Shadow
        glColor3f(0.2f, 0.15f, 0.3f);
        glBegin(GL_QUADS);
        glVertex2f(230, 418);
        glVertex2f(230, 410);
        glVertex2f(220, 410);
        glVertex2f(75, 418);
        glEnd();

        //Windows
        glColor3f(0.439f, 0.411f, 0.788f);
        drawRectangle(0,0,205,50);
        //Lines
        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(150, 0);
        glVertex2f(150, 50);
        glEnd();

        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(0,80,205,50);

        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(20, 80);
        glVertex2f(20, 130);
        glEnd();

        glColor3f(0.439f, 0.411f, 0.788f);
        drawRectangle(0,160,205,50);

        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(150, 160);
        glVertex2f(150, 210);
        glEnd();

        glColor3f(0.541f, 0.498f, 0.968f);
        drawRectangle(0,240,205,50);
        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(100, 240);
        glVertex2f(100, 290);
        glEnd();

        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(0,320,205,50);

        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(150, 320);
        glVertex2f(150, 370);
        glEnd();


    //7th Building Tower
        //Main Body
        glColor3f(0.1f, 0.1f, 0.2f);
        drawRectangle(870.0f, 0.0f, 120.0f, 750.0f);
        //shadow
        glColor3f(0.1f, 0.1f, 0.3f);
        glBegin(GL_TRIANGLES);
        glVertex2f(890, 750);
        glVertex2f(990, 750);
        glVertex2f(990, 500);
        glEnd();

        //Windows1
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(885.0f, 0.0f, 15.0f, 730.0f);

        //Windows2
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(910.0f, 0.0f, 15.0f, 730.0f);

        //Windows3
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(935.0f, 0.0f, 15.0f, 730.0f);

        //Windows
        glColor3f(0.984f, 0.714f, 0.682f);
        drawRectangle(960.0f, 0.0f, 15.0f, 730.0f);

        //Upper railing
        glColor3f(0.05f, 0.05f, 0.2f);
        drawRectangle(880.0f, 750.0f, 100.0f, 20.0f);

        //Upper upper Railing
        glColor3f(0.1f, 0.1f, 0.2f);
        drawRectangle(915.0f, 770.0f, 30.0f, 10.0f);

        //Upper upper Railing
        glColor3f(0.05f, 0.05f, 0.2f);
        drawRectangle(928.0f, 780.0f, 5.0f, 70.0f);

        //Top Triangle
        glBegin(GL_TRIANGLES);
        glColor3f(0.02f, 0.02f, 0.1f);
        glVertex2f(928,850);
        glVertex2f(930.5,860);
        glVertex2f(933,850);
        glEnd();

          //W logo
         glBegin(GL_QUADS);
       glColor3f(0.956f, 0.89f, 0.896f);
        glVertex2f(900,700);
        glVertex2f(920,700);
        glVertex2f(920,690);
        glVertex2f(900,690);
        glEnd();

         glBegin(GL_QUADS);
        glVertex2f(900,700);
        glVertex2f(910,700);
        glVertex2f(910,650);
        glVertex2f(900,650);
        glEnd();

        glBegin(GL_QUADS);
        glVertex2f(900,650);
        glVertex2f(910,650);
        glVertex2f(930,635);
        glVertex2f(930,625);
        glEnd();

        glBegin(GL_QUADS);
        glVertex2f(925,628);
        glVertex2f(925,690);
        glVertex2f(935,690);
        glVertex2f(935,628);
        glEnd();

        glBegin(GL_QUADS);
        glVertex2f(960,650);
        glVertex2f(950,650);
        glVertex2f(930,635);
        glVertex2f(930,625);
        glEnd();

        glBegin(GL_QUADS);
        glVertex2f(960,700);
        glVertex2f(950,700);
        glVertex2f(950,650);
        glVertex2f(960,650);
        glEnd();

        glBegin(GL_QUADS);
        glVertex2f(960,700);
        glVertex2f(940,700);
        glVertex2f(940,690);
        glVertex2f(960,690);
        glEnd();

    //6th Building with glasses
        //left glass
        glColor3f(0.1f, 0.1f, 0.3f);
        drawRectangle(680.0f, 0.0f, 80.0f, 400.0f);
        //Left Glass stripes
        glColor3f(0.1f, 0.1f, 0.1f);
        glLineWidth(1);

        glBegin(GL_LINES);
        glVertex2f(706, 0);
        glVertex2f(706, 400);
        glEnd();

        glLineWidth(1);

        glBegin(GL_LINES);
        glVertex2f(735, 0);
        glVertex2f(735, 400);
        glEnd();


        glLineWidth(1);

        glBegin(GL_LINES);
        glVertex2f(680, 350);
        glVertex2f(760, 350);
        glEnd();

        glLineWidth(1);

        glBegin(GL_LINES);
        glVertex2f(680, 300);
        glVertex2f(760, 300);
        glEnd();

        glLineWidth(1);

        glBegin(GL_LINES);
        glVertex2f(680, 250);
        glVertex2f(760, 250);
        glEnd();

        glLineWidth(1);

        glBegin(GL_LINES);
        glVertex2f(680, 200);
        glVertex2f(760, 200);
        glEnd();

        glLineWidth(1);

        glBegin(GL_LINES);
        glVertex2f(680, 150);
        glVertex2f(760, 150);
        glEnd();

        glLineWidth(1);

        glBegin(GL_LINES);
        glVertex2f(680, 100);
        glVertex2f(760, 100);
        glEnd();

        glLineWidth(1);

        glBegin(GL_LINES);
        glVertex2f(680, 50);
        glVertex2f(760, 50);
        glEnd();
        //Striped End

        //Middle Building
        glColor3f(0.05f, 0.05f, 0.2f);
        drawRectangle(760.0f, 0.0f, 90.0f, 360.0f);
        //Middle Building Upper Railing
        glColor3f(0.05f, 0.05f, 0.25f);
        drawRectangle(760.0f, 360.0f, 90.0f, 20.0f);
        //Right glass
        glColor3f(0.1f, 0.1f, 0.3f);
        drawRectangle(850.0f, 0.0f, 80.0f, 400.0f);

        //Right Glass stripes
        glColor3f(0.1f, 0.1f, 0.1f);
        glLineWidth(1);
        glBegin(GL_LINES);
        glVertex2f(876, 0);
        glVertex2f(876, 400);
        glEnd();

        glLineWidth(1);
        glBegin(GL_LINES);
        glVertex2f(906, 0);
        glVertex2f(906, 400);
        glEnd();


        glLineWidth(1);
        glBegin(GL_LINES);
        glVertex2f(850, 350);
        glVertex2f(930, 350);
        glEnd();

        glLineWidth(1);
        glBegin(GL_LINES);
        glVertex2f(850, 300);
        glVertex2f(930, 300);
        glEnd();

        glLineWidth(1);
        glBegin(GL_LINES);
        glVertex2f(850, 250);
        glVertex2f(930, 250);
        glEnd();

        glLineWidth(1);
        glBegin(GL_LINES);
        glVertex2f(850, 200);
        glVertex2f(930, 200);
        glEnd();

        glLineWidth(1);
        glBegin(GL_LINES);
        glVertex2f(850, 150);
        glVertex2f(930, 150);
        glEnd();

        glLineWidth(1);
        glBegin(GL_LINES);
        glVertex2f(850, 100);
        glVertex2f(930, 100);
        glEnd();

        glLineWidth(1);
        glBegin(GL_LINES);
        glVertex2f(850, 50);
        glVertex2f(930, 50);
        glEnd();
        //Stripes End

        //Middle Glass Connector
        glColor3f(0.05f, 0.05f, 0.25f);
        drawRectangle(680.0f, 250.0f, 250.0f, 5.0f);


    // Flyover
    //Black
    glColor3f(0.1f, 0.1f, 0.1f);
    drawRectangle(0.0f, 140.0f, 1000.0f, 50.0f);


    //white
    glColor3f(0.3f, 0.2f, 0.4f);
    drawRectangle(0.0f, 155.0f, 1000.0f, 30.0f);

    //Pillar1
    glColor3f(0.3f, 0.2f, 0.4f);
    quad(130,140,215,140,200,100,145,100);

    glColor3f(0.1f, 0.1f, 0.1f);
    quad(135,135,210,135,198,105,147,105);

    //upper ralling
        glLineWidth(10);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(140, 95);
        glVertex2f(205, 95);
        glEnd();
        //left
        glLineWidth(10);
        glColor3f(0.1f, 0.1f, 0.1f);
        glBegin(GL_LINES);
        glVertex2f(140, 95);
        glVertex2f(173, 50);
        glEnd();
        //right
        glLineWidth(10);
        glColor3f(0.1f, 0.1f, 0.1f);
        glBegin(GL_LINES);
        glVertex2f(205, 95);
        glVertex2f(172, 50);
        glEnd();

        glColor3f(0.3f, 0.2f, 0.4f);
        drawRectangle(157,0,30,100);

        //mid ralling
        glLineWidth(10);
        glColor3f(0.1f, 0.1f, 0.1f);
        glBegin(GL_LINES);
        glVertex2f(157, 70);
        glVertex2f(187, 70);
        glEnd();

        //Pillar2
        glColor3f(0.3f, 0.2f, 0.4f);
        quad(380,140,465,140,450,100,395,100);

        glColor3f(0.0f, 0.0f, 0.0f);
        quad(385,135,460,135,448,105,397,105);
    //upper ralling
        glLineWidth(10);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(390, 95);
        glVertex2f(450, 95);
        glEnd();
        //left
        glLineWidth(10);
        glColor3f(0.1f, 0.1f, 0.1f);
        glBegin(GL_LINES);
        glVertex2f(390, 95);
        glVertex2f(423, 50);
        glEnd();
        //right
        glLineWidth(10);
        glColor3f(0.1f, 0.1f, 0.1f);
        glBegin(GL_LINES);
        glVertex2f(451, 95);
        glVertex2f(423, 50);
        glEnd();



    glColor3f(0.3f, 0.2f, 0.4f);
    drawRectangle(407,0,30,100);

    //mid ralling
        glLineWidth(10);
        glColor3f(0.1f, 0.1f, 0.1f);
        glBegin(GL_LINES);
        glVertex2f(407, 70);
        glVertex2f(437, 70);
        glEnd();

    //Pillar3
        glColor3f(0.3f, 0.2f, 0.4f);
        quad(630,140,715,140,700,100,645,100);

        glColor3f(0.1f, 0.1f, 0.1f);
        quad(635,135,710,135,698,105,647,105);
        //upper ralling
        glLineWidth(10);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(640, 95);
        glVertex2f(705, 95);
        glEnd();
        //left
        glLineWidth(10);
        glColor3f(0.1f, 0.1f, 0.1f);
        glBegin(GL_LINES);
        glVertex2f(640, 95);
        glVertex2f(673, 50);
        glEnd();
        //right
        glLineWidth(10);
        glColor3f(0.1f, 0.1f, 0.1f);
        glBegin(GL_LINES);
        glVertex2f(705, 95);
        glVertex2f(672, 50);
        glEnd();


        glColor3f(0.3f, 0.2f, 0.4f);
        drawRectangle(657,0,30,100);

        //mid ralling
        glLineWidth(10);
        glColor3f(0.1f, 0.1f, 0.1f);
        glBegin(GL_LINES);
        glVertex2f(657, 70);
        glVertex2f(687, 70);
        glEnd();

    //Pillar4
        glColor3f(0.3f, 0.2f, 0.4f);
        quad(880,140,965,140,950,100,895,100);

        glColor3f(0.1f, 0.1f, 0.1f);
        quad(885,135,960,135,948,105,897,105);

        //upper ralling
        glLineWidth(10);
        glColor3f(0.1f, 0.1f, 0.1f);
        glBegin(GL_LINES);
        glVertex2f(890, 95);
        glVertex2f(955, 95);
        glEnd();
        //left raling
        glLineWidth(10);
        glColor3f(0.3f, 0.2f, 0.4f);
        glColor3f(0.1f, 0.1f, 0.1f);
        glBegin(GL_LINES);
        glVertex2f(890, 95);
        glVertex2f(922, 50);
        glEnd();
        //right line
        glLineWidth(10);
        glColor3f(0.1f, 0.1f, 0.1f);
        glBegin(GL_LINES);
        glVertex2f(955, 95);
        glVertex2f(922, 50);
        glEnd();

        //lowerpillar
        glColor3f(0.3f, 0.2f, 0.4f);
        drawRectangle(907,0,30,100);
        //mid ralling
        glLineWidth(10);
        glColor3f(0.1f, 0.1f, 0.1f);
        glBegin(GL_LINES);
        glVertex2f(907, 70);
        glVertex2f(937, 70);
        glEnd();




        //Bus

        glPushMatrix();
        glTranslatef(busX, 0.0f, 0.0f);

        //wheels
        //Left White Wheel Circle
        glColor3f(0.6f, 0.6f, 0.7f);
        drawCircle(735.0f, 201.0f, 14.0f);
        //LEft Inner Black Wheel Circle
        glColor3f(0.0f, 0.0f, 0.0f);
        drawCircle(735.0f, 201.0f, 9.0f);
        //Right Black Wheel Circle
       glColor3f(0.6f, 0.6f, 0.7f);
        drawCircle(885.0f, 201.0f, 14.0f);
        //Right Inner White Wheel Circle
        glColor3f(0.0f, 0.0f, 0.0f);
        drawCircle(885.0f, 201.0f, 9.0f);
        //Right Black Wheel Circle
        glColor3f(0.6f, 0.6f, 0.7f);
        drawCircle(915.0f, 201.0f, 14.0f);
        //Right Inner White Wheel Circle
        glColor3f(0.0f, 0.0f, 0.0f);
        drawCircle(915.0f, 201.0f, 9.0f);

        // Bus pink body
        glColor3f(0.3f, 0.25f, 0.2f);
        drawRectangle(700,207,250,103);
        //Upper Bus body
        glColor3f(0.3f, 0.25f, 0.2f);
        glBegin(GL_QUADS);
        glVertex2f(700, 310);
        glVertex2f(705, 317);
        glVertex2f(945, 317);
        glVertex2f(950, 310);
        glEnd();

        //lower body left part
        glColor3f(0.3f, 0.25f, 0.2f);
        glBegin(GL_QUADS);
        glVertex2f(700, 207);
        glVertex2f(700, 195);
        glVertex2f(718, 195);
        glVertex2f(725, 207);
        glEnd();
        //lower body middle part
        glColor3f(0.3f, 0.25f, 0.2f);
        glBegin(GL_QUADS);
        glVertex2f(745, 207);
        glVertex2f(752, 195);
        glVertex2f(865, 195);
        glVertex2f(872, 207);
        glEnd();
        //lower body right part
        glColor3f(0.3f, 0.25f, 0.2f);
        glBegin(GL_QUADS);
        glVertex2f(925, 207);
        glVertex2f(932, 195);
        glVertex2f(950, 195);
        glVertex2f(950, 207);
        glEnd();

        //Left Window
        //Top left part
        glColor3f(0.15f, 0.1f, 0.25f);
        glBegin(GL_QUADS);
        glVertex2f(700, 225);
        glVertex2f(715, 225);
        glVertex2f(715, 310);
        glVertex2f(700, 310);
        glEnd();
        //middle angular part
        glColor3f(0.6f, 0.4f, 0.15f);
        glBegin(GL_QUADS);
        glVertex2f(715, 225);
        glVertex2f(750, 240);
        glVertex2f(750, 310);
        glVertex2f(715, 310);
        glEnd();

        //Middle part
        drawRectangle(700,240,220,70);
        //right part
        glBegin(GL_QUADS);
        glVertex2f(920, 240);
        glVertex2f(950, 270);
        glVertex2f(950, 310);
        glVertex2f(920, 310);
        glEnd();

        //Purple shadow on window
        glColor3f(0.2f, 0.12f, 0.3f);
        glBegin(GL_QUADS);
        glVertex2f(700, 225);
        glVertex2f(715, 225);
        glVertex2f(715, 250);
        glVertex2f(700, 250);
        glEnd();

        //Purple shadow on window
        glColor3f(0.2f, 0.12f, 0.3f);
        glBegin(GL_QUADS);
        glVertex2f(715, 225);
        glVertex2f(750, 240);
        glVertex2f(750, 265);
        glVertex2f(715, 250);
        glEnd();

        //Purple shadow on window
        glColor3f(0.2f, 0.12f, 0.3f);
        glBegin(GL_QUADS);
        glVertex2f(750, 240);
        glVertex2f(920, 240);
        glVertex2f(920, 265);
        glVertex2f(750, 265);
        glEnd();

        //Purple shadow on window
        glColor3f(0.2f, 0.12f, 0.3f);
        glBegin(GL_QUADS);
        glVertex2f(920, 240);
        glVertex2f(950, 270);
        glVertex2f(950, 295);
        glVertex2f(920, 265);
        glEnd();

        //Lines On window
        glLineWidth(1);
        glColor3f(0.1f, 0.1f, 0.1f);
        glBegin(GL_LINES);
        glVertex2f(750, 240);
        glVertex2f(750, 310);
        glEnd();

        //Lines On window
        glLineWidth(1);
        glColor3f(0.1f, 0.1f, 0.1f);
        glBegin(GL_LINES);
        glVertex2f(800, 240);
        glVertex2f(800, 310);
        glEnd();

        //Lines On window
        glLineWidth(1);
        glColor3f(0.1f, 0.1f, 0.1f);
        glBegin(GL_LINES);
        glVertex2f(860, 240);
        glVertex2f(860, 310);
        glEnd();


        //Lines On window
        glLineWidth(1);
        glColor3f(0.1f, 0.1f, 0.1f);
        glBegin(GL_LINES);
        glVertex2f(920, 240);
        glVertex2f(920, 310);
        glEnd();

        //Lines On window
        glLineWidth(1);
        glColor3f(0.1f, 0.1f, 0.1f);
        glBegin(GL_LINES);
        glVertex2f(750, 300);
        glVertex2f(920, 300);
        glEnd();

        //Stripes On glass
        glLineWidth(1);
        glColor3f(0.6f, 0.6f, 0.7f);
        glBegin(GL_LINES);
        glVertex2f(740, 270);
        glVertex2f(730, 300);
        glEnd();

        glLineWidth(1);
         glColor3f(0.6f, 0.6f, 0.7f);
        glBegin(GL_LINES);
        glVertex2f(735, 270);
        glVertex2f(728, 290);
        glEnd();

        //Stripes On glass
        glLineWidth(1);
         glColor3f(0.6f, 0.6f, 0.7f);
        glBegin(GL_LINES);
        glVertex2f(790, 270);
        glVertex2f(780, 300);
        glEnd();

        glLineWidth(1);
         glColor3f(0.6f, 0.6f, 0.7f);
        glBegin(GL_LINES);
        glVertex2f(785, 270);
        glVertex2f(778, 290);
        glEnd();

        //Stripes On glass
        glLineWidth(1);
        glColor3f(0.6f, 0.6f, 0.7f);
        glBegin(GL_LINES);
        glVertex2f(850, 270);
        glVertex2f(840, 300);
        glEnd();

        glLineWidth(1);
        glColor3f(0.6f, 0.6f, 0.7f);
        glBegin(GL_LINES);
        glVertex2f(845, 270);
        glVertex2f(838, 290);
        glEnd();

        //Stripes On glass
        glLineWidth(1);
        glColor3f(0.6f, 0.6f, 0.7f);
        glBegin(GL_LINES);
        glVertex2f(915, 270);
        glVertex2f(905, 300);
        glEnd();

        glLineWidth(1);
        glColor3f(0.6f, 0.6f, 0.7f);
        glBegin(GL_LINES);
        glVertex2f(910, 270);
        glVertex2f(902, 290);
        glEnd();






    glPopMatrix();

    //batmobile


    // car
        glPushMatrix();
        glTranslatef(carX, 0.0f, 0.0f);


        // Car1 pink body
        glColor3f(0.3f, 0.15f, 0.4f);
        glBegin(GL_POLYGON);
        glVertex2f(235, 290);
        glVertex2f(155, 290);
        glVertex2f(145, 260);
        glVertex2f(130, 250);
        glVertex2f(130, 210);
        glVertex2f(235, 210);
        glEnd();


        //bumper
        glColor3f(0.15f, 0.1f, 0.25f);
        drawRectangle(128,205,108,5);

        //Left Window
       glColor3f(0.7f, 0.5f, 0.15f);
        glBegin(GL_QUADS);
        glVertex2f(230, 285);
        glVertex2f(170, 285);
        glVertex2f(170, 250);
        glVertex2f(230, 250);
        glEnd();

        //Yellow Shadow
        glBegin(GL_QUADS);
        glColor3f(0.45f, 0.35f, 0.15f);
        glVertex2f(230, 250);
        glVertex2f(170, 250);
        glVertex2f(170, 260);
        glVertex2f(230, 260);
        glEnd();

        //Right Window
        glColor3f(0.7f, 0.5f, 0.15f);
        glBegin(GL_POLYGON);
        glVertex2f(170, 250);
        glVertex2f(155, 260);
        glVertex2f(145, 260);
        glVertex2f(153, 285);
        glVertex2f(170, 285);
        glEnd();
        //yellow shadow
        glBegin(GL_QUADS);
        glColor3f(0.45f, 0.35f, 0.15f);
        glVertex2f(170, 250);
        glVertex2f(155, 255);
        glVertex2f(155, 265);
        glVertex2f(170, 260);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.45f, 0.35f, 0.15f);
        glVertex2f(155, 255);
        glVertex2f(145, 260);
        glVertex2f(148, 270);
        glVertex2f(155, 265);
        glEnd();

        //Stripes On glass
        glLineWidth(1);
        glColor3f(0.6f, 0.6f, 0.7f);
        glBegin(GL_LINES);
        glVertex2f(215, 270);
        glVertex2f(218, 260);
        glEnd();

        glLineWidth(1);
        glColor3f(0.6f, 0.6f, 0.7f);
        glBegin(GL_LINES);
        glVertex2f(210, 275);
        glVertex2f(214, 260);
        glEnd();

         //Stripes On glass
        glLineWidth(1);
        glColor3f(0.6f, 0.6f, 0.7f);
        glBegin(GL_LINES);
        glVertex2f(170, 270);
        glVertex2f(173, 260);

        glEnd();

        glLineWidth(1);
        glColor3f(0.6f, 0.6f, 0.7f);
        glBegin(GL_LINES);
        glVertex2f(173, 275);
        glVertex2f(178, 260);
        glEnd();


        //door knob
        glLineWidth(5);
        glColor3f(0.1f, 0.1f, 0.1f);
        glBegin(GL_LINES);
        glVertex2f(175, 243);
        glVertex2f(184, 243);
        glEnd();


        //Single line in window
        glLineWidth(3);
        glColor3f(0.1f, 0.1f, 0.1f);
        glBegin(GL_LINES);
        glVertex2f(172, 285);
        glVertex2f(172, 250);
        glEnd();

        glLineWidth(3);
        glColor3f(0.1f, 0.1f, 0.1f);
        glBegin(GL_LINES);
        glVertex2f(210, 285);
        glVertex2f(210, 250);
        glEnd();

        glLineWidth(2);
        glColor3f(0.1f, 0.1f, 0.1f);
        glBegin(GL_LINES);
        glVertex2f(165, 285);
        glVertex2f(160, 253);
        glEnd();
        //door lines
        glLineWidth(1);
        glColor3f(0.1f, 0.1f, 0.1f);
        glBegin(GL_LINES);
        glVertex2f(172, 210);
        glVertex2f(172, 250);
        glEnd();

        glLineWidth(1);
        glColor3f(0.1f, 0.1f, 0.1f);
        glBegin(GL_LINES);
        glVertex2f(210, 210);
        glVertex2f(210, 250);
        glEnd();

        //Front Light
        glBegin(GL_QUADS);
        glColor3f(0.7f, 0.5f, 0.15f);
        glVertex2f(130, 250);
        glVertex2f(130, 243);
        glVertex2f(135, 243);
        glVertex2f(135, 250);
        glEnd();

        //wheels
        //Left White Wheel Circle
        glColor3f(0.6f, 0.6f, 0.7f);
        drawCircle(155.0f, 203.0f, 13.0f);
        //LEft Inner Black Wheel Circle
        glColor3f(0.1f, 0.1f, 0.1f);
        drawCircle(155.0f, 203.0f, 8.0f);
        //Right Black Wheel Circle
        glColor3f(0.6f, 0.6f, 0.7f);
        drawCircle(215.0f, 203.0f, 13.0f);
        //Right Inner White Wheel Circle
        glColor3f(0.1f, 0.1f, 0.1f);
        drawCircle(215.0f, 203.0f, 8.0f);

    glPopMatrix();

    //Batmobile
        glPushMatrix();
        glTranslatef(batmobile, 0.0f, 0.0f);
        //body
        glColor3f(0.09f, 0.09f, 0.2f);
        glBegin(GL_POLYGON);
        glVertex2f(60, 200);
        glVertex2f(53, 210);
        glVertex2f(30, 255);
        glVertex2f(35, 260);
        glVertex2f(140, 250);
        glVertex2f(205, 240);
        glVertex2f(210, 233);
        glVertex2f(215, 200);
        glEnd();


        //Head
        glColor3f(0.09f, 0.09f, 0.2f);
        glBegin(GL_POLYGON);
        glVertex2f(62, 250);
        glVertex2f(70, 260);
        glVertex2f(75, 275);
        glVertex2f(130, 266);
        glVertex2f(135, 262);
        glVertex2f(140, 250);
        glEnd();

        //back fang
        glColor3f(0.06f, 0.06f, 0.12f);
        glBegin(GL_POLYGON);
        glVertex2f(30, 255);
        glVertex2f(26, 250);
        glVertex2f(40, 245);
        glVertex2f(30, 240);
        glVertex2f(50, 235);
        glVertex2f(32, 230);
        glVertex2f(60, 225);
        glVertex2f(35, 220);
        glVertex2f(70, 215);
        glVertex2f(38, 210);
        glVertex2f(80, 205);
        glEnd();

        //Shadows
        glColor3f(0.06f, 0.06f, 0.12f);
        glBegin(GL_QUADS);
        glVertex2f(30, 255);
        glVertex2f(60, 200);
        glVertex2f(210, 200);
        glVertex2f(130, 240);
        glEnd();

        //wheels
        //Left White Wheel Circle
        glColor3f(0.02f, 0.02f, 0.05f);
        drawCircle(80.0f, 202.0f, 12.0f);
        //LEft Inner Black Wheel Circle
        glColor3f(0.28f, 0.28f, 0.35f);
        drawCircle(80.0f, 202.0f, 7.0f);
        //Right Black Wheel Circle
        glColor3f(0.02f, 0.02f, 0.05f);
        drawCircle(180.0f, 202.0f, 12.0f);
        //Right Inner White Wheel Circle
        glColor3f(0.28f, 0.28f, 0.35f);
        drawCircle(180.0f, 202.0f, 7.0f);

        //windows
        glColor3f(0.7f, 0.4f, 1.0f);
        glBegin(GL_QUADS);
        glVertex2f(107, 268);
        glVertex2f(133, 263);
        glVertex2f(139, 248);
        glVertex2f(100, 250);
        glEnd();

        //window shadow
        glColor3f(0.45f, 0.38f, 0.7f);
        glBegin(GL_QUADS);
        glVertex2f(103, 258);
        glVertex2f(133, 253);
        glVertex2f(139, 248);
        glVertex2f(100, 250);
        glEnd();
        //windows stripes
        glLineWidth(1);
        glColor3f(0.45f, 0.38f, 0.7f);
        glBegin(GL_LINES);
        glVertex2f(119, 261);
        glVertex2f(125, 259);
        glEnd();

        glLineWidth(1);
       glColor3f(0.45f, 0.38f, 0.7f);
        glBegin(GL_LINES);
        glVertex2f(118, 258);
        glVertex2f(129, 255);
        glEnd();

        //Front Light
        if(batmobilemoveforware && currentScene==2)
        {
        glColor3f(0.7f, 0.4f, 1.0f);
        glBegin(GL_QUADS);
        glVertex2f(205, 240);
        glVertex2f(210, 233);
        glVertex2f(195,233);
        glVertex2f(195,242);
        glEnd();
        }

        if(batsignal)
        {
        glColor3f(0.7f, 0.4f, 1.0f);
        glBegin(GL_QUADS);
        glVertex2f(205, 240);
        glVertex2f(210, 233);
        glVertex2f(195,233);
        glVertex2f(195,242);
        glEnd();
        }



    glPopMatrix();




    glutSwapBuffers();
}

void display() {
    if(currentScene==1||currentScene==2) {
        if(currentScene==1) {
        drawDawnScene();
        } else if(currentScene==2) {
            drawNightScene();
        }
    }
    //Areful
    if(currentScene==3||currentScene==4)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        if(currentScene==3){
            displayDay1();
        } else if(currentScene==4){
            displayNight2();
        }
        glutSwapBuffers();
    }
    //Shamim
    if(currentScene==5||currentScene==6)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        if(currentScene==5){
            displayDay();
        } else if(currentScene==6){
            displayNight();
        }
        glutSwapBuffers();
    }

}

void handleKeypress(unsigned char key, int x, int y) {

        if (key == '1') {
            batmobile=0.0f;
            currentScene=1;
            glutPostRedisplay();
        }

        if (key == '2') {
            currentScene=3;
            glutPostRedisplay();
        }

        if (key == '3') {
            currentScene=5;
            glutPostRedisplay();
        }

        if (key == '4') {
            currentScene=7;
            glutPostRedisplay();
        }
        if(key==27)
        {
        cout << "Escape key pressed. Exiting..." <<endl;
        exit(0);
        }

    if(currentScene==1||currentScene==2)
    {


        if (key == 'd' || key == 'D') {
            batmobilemoveforware=true;
           batmobile += 15.0f;
            if (batmobile > 1000.0f && !batsignal) {
                currentScene=5;
            }
            glutPostRedisplay();
        }

        if (key == 'a' || key == 'A') {
            batmobilemoveforware=true;
           batmobile -= 7.0f;
            if (batmobile < -200.0f) {
                batmobile = 1000.0f;
            }
            glutPostRedisplay();
        }

         if (key == 'w' || key == 'W') {
            planeMovement=true;
            planeY+=5;
            glutPostRedisplay();
        }
         if (key == 's' || key == 'S') {
            planeMovement=false;
           planeY -=5;
           glutPostRedisplay();
        }

        if (key == 'l' || key == 'L') {
            if(!batsignal&& currentScene==2)
            {
            batsignal=true;

            }
            else{
                batsignal=false;
            }
           glutPostRedisplay();
        }
         if (key == 'r' || key == 'R') {
            batmobile=200.0f;
           glutPostRedisplay();
        }

    }


       //Areful
       if(currentScene==3)
       {
       switch (key) {
        case 'r':
            cloudMoving = true;
            break;
        case 'p':
            cloudMoving = false;
            break;


        case 'R':
            boatMoving = true;
            break;
        case 'P':
            boatMoving = false;
            break;
        }
    }
    //Shamim
    switch (key) {
    case 'S': // Start moving the sun
        sunMoving = true;
        break;
    case 's': // Stop moving the sun
        sunMoving = false;
        break;

    case 'C': // Start moving the CLOUDS
        cloudMoving1 = true;
        break;
    case 'c': // Stop moving the CLOUDS
        cloudMoving1 = false;
        break;

    case 'B': // Start moving the boat
        boatMoving1 = true;
        break;
    case 'b': // Stop moving the boat
        boatMoving1 = false;
        break;
    }
 }


    void handleKeyRelease(unsigned char key, int x, int y) {
        if (key == 'd' || key == 'D') {
            batmobilemoveforware = false;
            glutPostRedisplay();
        }

        if (key == 'a' || key == 'A') {
            batmobilemoveforware = false;
            glutPostRedisplay();
        }
    }

void handleMouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if(currentScene==1)
        {
            sunY=600.0;
            currentScene = 2;
            sunMovement=true;
            glutPostRedisplay();
        }
        else if(currentScene==2){
            sunY=600.0;
            sunMovement=true;
            currentScene = 1;
            glutPostRedisplay();
        }

        else if(currentScene==3)
        {
            currentScene=4;
        }
        else if(currentScene==4)
        {
            currentScene=3;
        }

        else if(currentScene==5)
        {
            currentScene=6;
        }
        else if(currentScene==6)
        {
            currentScene=5;
        }

    }
}

void update(int value) {

    if(batsignal)
    {
        batmobilemoveforware=true;
        batmobileautomove=true;
       batmobile += 15.0f;
        glutPostRedisplay();
    }

    else if (!batsignal && batmobileautomove) {
        if (batmobile > 1000.0f) {
            batmobile = -250.0f;
            batmobile +=5.0f;
            if(batmobile>300.0f){
                batmobileautomove=false;
            }

        }
    }

    if(sunMovement)
    {
        sunY +=5.0f;

        if(sunY>=850.0f){
            sunMovement=false;
        }
    }
    cloud1X -= 5.0f;
    if (cloud1X < -1000.0f) {
        cloud1X = 1010.0f;
    }

    busX -= 5.0f;
    if (busX < -1000.0f) {
        busX = 1100.0f;
    }

    carX -= 5.0f;
    if (carX < -1000.0f) {
        carX = 1100.0f;
    }

    cloud2X -= 5.0f;
    if (cloud2X < -1030.0f) {
        cloud2X = 1010.0f;
    }

    birdX += 4.0f;
    if (birdX > 1000) {
        birdX = -200.0f;
    }

    if (birdWingDirection) {
        birdWingAngle += 2.0f;
        if (birdWingAngle > 10.0f) {
            birdWingDirection = false;
        }
    } else {
        birdWingAngle -= 2.0f;
        if (birdWingAngle < -10.0f) {
            birdWingDirection = true;
        }
    }
    if(planeMovement)
    {
        planeY +=1.0f;
    }
    else{
        planeY -=1.0f;
    }
    planeX += 5.0f;


    if (planeX > 1000 || planeY >1000) {
        planeX = -600.0f;
        planeY = -150.0f;
    }

    glutPostRedisplay();
    glutTimerFunc(10, update, 0);
}

void init(){
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    gluOrtho2D(0, 1000, 0, 1000);
}

int main(int argc, char **argv) {

    cout<<"press Mouse Left Button to change time of scenary(All Scene)"<<endl;
    cout<<"press A/D to Move the batmobile(gotham)"<<endl;
    cout<<"press W/S to Move control the Plane(gotham)"<<endl;
    cout<<"press L to Turn on Batsignal(Gotham)"<<endl;
    cout<<"press r to Reset Car Location (Gotham)"<<endl;
    cout<<"press 1 to shift to Gotham city(any scene)"<<endl;
    cout<<"press 2 to shift to village(Areful)"<<endl;
    cout<<"press p to stop cloud(Areful)"<<endl;
    cout<<"press r to start cloud(Areful)"<<endl;
    cout<<"press P to stop boat(Areful)"<<endl;
    cout<<"press R to start bpat(Areful)"<<endl;
    cout<<"press 3 to shift to village(Shamim)"<<endl;
    cout<<"press s to stop car,bird,sun(shamim)"<<endl;
    cout<<"press S to start car,bird,sun(shamim)"<<endl;
    cout<<"Press b to stop boat(Shamim)"<<endl;
    cout<<"Press B to start boat(Shamim)"<<endl;
    cout<<"Press c to stop cloud(Shamim)"<<endl;
    cout<<"Press C to start cloud(Shamim)"<<endl;
    cout<<"press ESC to exit project"<<endl;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1920, 1080);
    glutCreateWindow("City");
    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeypress);
    glutKeyboardUpFunc(handleKeyRelease);
    glutMouseFunc(handleMouseClick);
    glutTimerFunc(16, updateBoat1, 0);
     glutTimerFunc(25, updateCycle, 0);
    glutTimerFunc(16, update, 0);
    glutTimerFunc(25, updateClouds, 0);
    glutTimerFunc(25, updateSun1, 0); //sun
    glutTimerFunc(25, updateClouds1, 0); //clouds
    glutTimerFunc(16, updateBoat, 0);
    glutFullScreen();
    glutMainLoop();
    return 0;
}
