#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
using namespace std;

float cloud1X = 100.0f;
float cloud2X = 150.0f;
float carX = 0.0f;

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

void drawRectangle(float x, float y, float width, float height) {
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}

void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity(); // Reset the drawing perspective
    glMatrixMode(GL_MODELVIEW);
    gluOrtho2D(0, 200, 0, 200);

    // ground
    glColor3f(0.1f, 0.6f, 0.1f);
    drawRectangle(0.0f, 0.0f, 200.0f, 60.0f);

    //Street
    glColor3f(0.6f, 0.6f, 0.6f);
    drawRectangle(0.0f, 0.0f, 200.0f, 40.0f);

    //Street Lines
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(15, 20);
    glVertex2f(20, 25);
    glVertex2f(65, 25);
    glVertex2f(60, 20);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(85, 20);
    glVertex2f(90, 25);
    glVertex2f(135, 25);
    glVertex2f(130, 20);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(155, 20);
    glVertex2f(160, 25);
    glVertex2f(205, 25);
    glVertex2f(200, 20);
    glEnd();
    // buildings
    glColor3f(0.6f, 0.6f, 0.6f);
    drawRectangle(90.0f, 60.0f, 30.0f, 60.0f);
    drawRectangle(40.0f, 60.0f, 30.0f, 80.0f);
    drawRectangle(140.0f, 60.0f, 30.0f, 70.0f);

    // windows
    glColor3f(0.8f, 0.8f, 0.0f);
    drawRectangle(95.0f, 80.0f, 10.0f, 10.0f);
    drawRectangle(105.0f, 100.0f, 10.0f, 10.0f);
    drawRectangle(45.0f, 80.0f, 10.0f, 10.0f);
    drawRectangle(55.0f, 120.0f, 10.0f, 10.0f);
    drawRectangle(145.0f, 80.0f, 10.0f, 10.0f);
    drawRectangle(155.0f, 105.0f, 10.0f, 10.0f);

    // sun
    glColor3f(1.0f, 1.0f, 0.0f);
    drawCircle(180.f, 180.0f, 10.0f);

    // left cloud
    glPushMatrix();
    glTranslatef(cloud1X, 0.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(60.0f, 160.0f, 10.0f);
    drawCircle(50.0f, 160.0f, 15.0f);
    drawCircle(40.0f, 160.0f, 10.0f);
    glPopMatrix();

    //right cloud
    glPushMatrix();
    glTranslatef(cloud2X, 0.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(100.0f, 150.0f, 10.0f);
    drawCircle(110.0f, 150.0f, 15.0f);
    drawCircle(120.0f, 150.0f, 10.0f);
    glPopMatrix();

    // car
    glPushMatrix();
    glTranslatef(carX, 0.0f, 0.0f);


    // Car body
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(15, 30);
    glVertex2f(15, 50);
    glVertex2f(30, 65);
    glVertex2f(70, 65);
    glVertex2f(83, 51);
    glVertex2f(110, 50);
    glVertex2f(110, 30);
    glEnd();
    //Left Window
    glColor3f(0.5f, 0.8f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(32, 63);
    glVertex2f(54, 63);
    glVertex2f(55, 50);
    glVertex2f(20, 50);
    glEnd();
    //Single line in window
    glLineWidth(5);
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(32, 63);
    glVertex2f(32, 50);
    glEnd();

    //Right Window
    glColor3f(0.5f, 0.8f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(56, 63);
    glVertex2f(70, 63);
    glVertex2f(80, 50);
    glVertex2f(57, 50);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(30.0f, 33.0f, 8.0f);
    drawCircle(95.0f, 33.0f, 8.0f);

    glPopMatrix();

    glutSwapBuffers();
}

void update(int value) {
    cloud1X -= 1.0f;
    if (cloud1X < -100.0f) {
        cloud1X = 250.0f;
    }

    cloud2X -= 1.0f;
    if (cloud2X < -130.0f) {
        cloud2X = 220.0f;
    }

    carX += 1.0f;
    if (carX > 220.0f) {
        carX = -100.0f;
    }

    glutPostRedisplay(); // Notify GLUT that the display has changed
    glutTimerFunc(10, update, 0); // Notify GLUT to call update again in 10 milliseconds
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("City");

    glClearColor(0.5f, 0.8f, 1.0f, 1.0f); // Set background color (sky blue)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();


    glutDisplayFunc(drawScene);
    glutTimerFunc(20, update, 0); // Add a timer

    glutMainLoop();
    return 0;
}
