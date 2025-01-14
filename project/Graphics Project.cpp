#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
using namespace std;

float cloud1X = 500.0f;
float cloud2X = 750.0f;
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

void drawScene() {


    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity(); // Reset the drawing perspective
    glMatrixMode(GL_MODELVIEW);
    glClearColor(0.80f, 0.717f, 1.0f, 1.0f);
    gluOrtho2D(0, 1000, 0, 1000);

    // sun
    glColor3f(0.956f, 0.9f, 0.976f);
    drawCircle(950.f, 950.0f, 30.0f);

    // left cloud
    glPushMatrix();
    glTranslatef(cloud1X, 0.0f, 0.0f);
    glColor3f(0.956f, 0.8f, 0.976f);
    drawCircle(300.0f, 800.0f, 50.0f);
    drawCircle(250.0f, 800.0f, 75.0f);
    drawCircle(200.0f, 800.0f, 50.0f);
    glPopMatrix();

    //right cloud
    glPushMatrix();
    glTranslatef(cloud2X, 0.0f, 0.0f);
    glColor3f(0.956f, 0.8f, 0.976f);
    drawCircle(500.0f, 750.0f, 50.0f);
    drawCircle(550.0f, 750.0f, 75.0f);
    drawCircle(600.0f, 750.0f, 50.0f);
    glPopMatrix();


    // buildings


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


    //3rd Building
    glColor3f(0.721f, 0.698f, 1.0f);
    drawRectangle(240.0f, 0.0f, 140.0f, 575.0f);

    //First bulding Below
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



    // Flyover
    //Black
    glColor3f(0.0f, 0.0f, 0.0f);
    drawRectangle(0.0f, 140.0f, 1000.0f, 50.0f);


    //white
    glColor3f(0.96f, 0.835f, 0.917f);
    drawRectangle(0.0f, 145.0f, 1000.0f, 40.0f);

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
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(140, 95);
        glVertex2f(173, 50);
        glEnd();
        //right
        glLineWidth(10);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(205, 95);
        glVertex2f(172, 50);
        glEnd();

    glColor3f(0.96f, 0.835f, 0.917f);
    drawRectangle(157,0,30,100);

        //mid ralling
        glLineWidth(10);
        glColor3f(0.0f, 0.0f, 0.0f);
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
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(390, 95);
        glVertex2f(423, 50);
        glEnd();
        //right
        glLineWidth(10);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(451, 95);
        glVertex2f(423, 50);
        glEnd();



    glColor3f(0.96f, 0.835f, 0.917f);
    drawRectangle(407,0,30,100);

    //mid ralling
        glLineWidth(10);
        glColor3f(0.0f, 0.0f, 0.0f);
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
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(640, 95);
        glVertex2f(673, 50);
        glEnd();
        //right
        glLineWidth(10);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(705, 95);
        glVertex2f(672, 50);
        glEnd();


        glColor3f(0.96f, 0.835f, 0.917f);
        drawRectangle(657,0,30,100);

        //mid ralling
        glLineWidth(10);
        glColor3f(0.0f, 0.0f, 0.0f);
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
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(890, 95);
        glVertex2f(922, 50);
        glEnd();
        //right line
        glLineWidth(10);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(955, 95);
        glVertex2f(922, 50);
        glEnd();

        //lowerpillar
        glColor3f(0.96f, 0.835f, 0.917f);
        drawRectangle(907,0,30,100);
        //mid ralling
        glLineWidth(10);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(907, 70);
        glVertex2f(937, 70);
        glEnd();








    // car
    glPushMatrix();
    glTranslatef(carX, 0.0f, 0.0f);


    // Car1 pink body
    glColor3f(1.0f, 0.482f, 0.98f);
    glBegin(GL_POLYGON);
    glVertex2f(75, 290);
    glVertex2f(155, 290);
    glVertex2f(165, 260);
    glVertex2f(180, 250);
    glVertex2f(180, 210);
    glVertex2f(75, 210);
    glEnd();

    //bumper
    glColor3f(0.321f, 0.207f, 0.505f);
    drawRectangle(73,205,108,5);

    //Left Window
    glColor3f(0.956f, 0.749f, 0.545f);
    glBegin(GL_QUADS);
    glVertex2f(80, 285);
    glVertex2f(140, 285);
    glVertex2f(140, 250);
    glVertex2f(80, 250);
    glEnd();

    //Right Window
    glColor3f(0.956f, 0.749f, 0.545f);
    glBegin(GL_POLYGON);
    glVertex2f(140, 250);
    glVertex2f(155, 260);
    glVertex2f(165, 260);
    glVertex2f(157, 285);
    glVertex2f(140, 285);
    glEnd();

    //Single line in window
    glLineWidth(3);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(110, 285);
    glVertex2f(110, 250);
    glEnd();

    glLineWidth(3);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(140, 285);
    glVertex2f(140, 250);
    glEnd();

    glLineWidth(2);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(150, 285);
    glVertex2f(155, 256);
    glEnd();



    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(100.0f, 205.0f, 15.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(100.0f, 205.0f, 10.0f);

    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(160.0f, 205.0f, 15.0f);

    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(160.0f, 205.0f, 10.0f);

    glPopMatrix();

    glutSwapBuffers();
}

void update(int value) {
    cloud1X -= 5.0f;
    if (cloud1X < -1000.0f) {
        cloud1X = 1010.0f;
    }

    cloud2X -= 5.0f;
    if (cloud2X < -1030.0f) {
        cloud2X = 1010.0f;
    }

    carX += 5.0f;
    if (carX > 1020.0f) {
        carX = -1010.0f;
    }

    glutPostRedisplay(); // Notify GLUT that the display has changed
    glutTimerFunc(10, update, 0); // Notify GLUT to call update again in 10 milliseconds
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1920, 1000);
    glutCreateWindow("City");
    glutDisplayFunc(drawScene);
    glutTimerFunc(20, update, 0); // Add a timer
    glutMainLoop();
    return 0;
}
