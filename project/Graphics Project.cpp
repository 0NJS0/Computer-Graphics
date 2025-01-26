#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
using namespace std;

float cloud1X = 500.0f;
float cloud2X = 750.0f;
float carX = 0.0f;
float busX= 0.0f;

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
    glClearColor(0.803f, 0.717f, 1.0f, 1.0f);
    gluOrtho2D(0, 1000, 0, 1000);


    //Sky Ray
    glColor3f(0.780f, 0.694f, 0.976f);
    glBegin(GL_QUADS);
    glVertex2f(800, 1000);
    glVertex2f(995, 1000);
    glVertex2f(450, 0);
    glVertex2f(200, 0);
    glEnd();

    //Sky Dark Ray
    glColor3f(0.757f, 0.663f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(995, 1000);
    glVertex2f(1000, 1000);
    glVertex2f(1000, 0);
    glVertex2f(450, 0);
    glEnd();

    // sun
    glColor3f(0.956f, 0.9f, 0.976f);
    drawCircle(950.f, 950.0f, 30.0f);

    // left cloud
    glPushMatrix();
    glTranslatef(cloud1X, 0.0f, 0.0f);
    glColor3f(0.956f, 0.8f, 0.976f);
    drawCircle(290.0f, 800.0f, 25.0f);
    drawCircle(250.0f, 800.0f, 35.0f);
    drawCircle(210.0f, 800.0f, 25.0f);
    glPopMatrix();


    // buildings
        //Building Far left
        glColor3f(0.373f, 0.341f, 0.729f);
        drawRectangle(0.0f, 0.0f, 100.0f, 600.0f);

        //Building far 2nd left
        glColor3f(0.373f, 0.341f, 0.729f);
        drawRectangle(100.0f, 0.0f, 100.0f, 650.0f);
        //3rd
        glColor3f(0.373f, 0.341f, 0.729f);
        drawRectangle(200.0f, 0.0f, 100.0f, 780.0f);
        glColor3f(0.373f, 0.341f, 0.729f);
        drawRectangle(300.0f, 0.0f, 100.0f, 650.0f);

        //4th
        glColor3f(0.373f, 0.341f, 0.729f);
        drawRectangle(500.0f, 0.0f, 200.0f, 580.0f);
        glColor3f(0.373f, 0.341f, 0.729f);
        drawRectangle(500.0f, 0.0f, 100.0f, 650.0f);

        //5th
        glColor3f(0.373f, 0.341f, 0.729f);
        drawRectangle(750.0f, 0.0f, 100.0f, 450.0f);
        glColor3f(0.373f, 0.341f, 0.729f);
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
        glColor3f(0.348f, 0.209f, 0.579f);
        glBegin(GL_QUADS);
        glVertex2f(630, 860);
        glVertex2f(640, 870);
        glVertex2f(760, 870);
        glVertex2f(760, 0);
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
        glColor3f(0.553f, 0.361f, 0.851f);
        glBegin(GL_QUADS);
        glVertex2f(370, 700);
        glVertex2f(380, 720);
        glVertex2f(520, 720);
        glVertex2f(520, 0);
        glEnd();
        //left Block
        glColor3f(0.529f, 0.443f, 0.937f);
        drawRectangle(370.0f, 0.0f, 140.0f, 700.0f);



        //right block upper
        glColor3f(0.553f, 0.361f, 0.851f);
        glBegin(GL_QUADS);
        glVertex2f(510, 500);
        glVertex2f(520, 520);
        glVertex2f(660, 520);
        glVertex2f(660, 0);
        glEnd();
        //Right block
        glColor3f(0.529f, 0.443f, 0.937f);
        drawRectangle(510.0f, 0.0f, 140.0f, 500.0f);
        //Shadow
        glColor3f(0.502f, 0.419f, 0.886f);
        glBegin(GL_QUADS);
        glVertex2f(370, 700);
        glVertex2f(370, 0);
        glVertex2f(650, 0);
        glVertex2f(650,270);
        glEnd();

        //Left Block windows
        glColor3f(0.643f, 0.631f, 0.925f);
        drawRectangle(380.0f, 630.0f, 15.0f, 45.0f);

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(410.0f, 630.0f, 15.0f, 45.0f);

        glColor3f(0.643f, 0.631f, 0.925f);
        drawRectangle(460.0f, 630.0f, 15.0f, 45.0f);

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(490.0f, 630.0f, 15.0f, 45.0f);

        //2nd Row
        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(380.0f, 550.0f, 15.0f, 45.0f);

       glColor3f(0.643f, 0.631f, 0.925f);
        drawRectangle(410.0f, 550.0f, 15.0f, 45.0f);

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(460.0f, 550.0f, 15.0f, 45.0f);

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(490.0f, 550.0f, 15.0f, 45.0f);

        //3rd Row


       glColor3f(0.643f, 0.631f, 0.925f);
        drawRectangle(410.0f, 470.0f, 15.0f, 45.0f);

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(460.0f, 470.0f, 15.0f, 45.0f);

        glColor3f(0.643f, 0.631f, 0.925f);
        drawRectangle(490.0f, 470.0f, 15.0f, 45.0f);

        //4th row

        glColor3f(0.643f, 0.631f, 0.925f);
        drawRectangle(410.0f, 390.0f, 15.0f, 45.0f);

        glColor3f(0.643f, 0.631f, 0.925f);
        drawRectangle(460.0f, 390.0f, 15.0f, 45.0f);

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(490.0f, 390.0f, 15.0f, 45.0f);



        //5th row
        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(410.0f, 310.0f, 15.0f, 45.0f);

        glColor3f(0.643f, 0.631f, 0.925f);
        drawRectangle(460.0f, 310.0f, 15.0f, 45.0f);

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(490.0f, 310.0f, 15.0f, 45.0f);

        //6th row
        glColor3f(0.643f, 0.631f, 0.925f);
        drawRectangle(410.0f, 230.0f, 15.0f, 45.0f);

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(460.0f, 230.0f, 15.0f, 45.0f);

        glColor3f(0.643f, 0.631f, 0.925f);
        drawRectangle(490.0f, 230.0f, 15.0f, 45.0f);

        //7th row

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(410.0f, 150.0f, 15.0f, 45.0f);

        glColor3f(0.643f, 0.631f, 0.925f);
        drawRectangle(460.0f, 150.0f, 15.0f, 45.0f);

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(490.0f, 150.0f, 15.0f, 45.0f);

        //8th row
        glColor3f(0.643f, 0.631f, 0.925f);
        drawRectangle(410.0f, 70.0f, 15.0f, 45.0f);

        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(460.0f, 70.0f, 15.0f, 45.0f);

        glColor3f(0.643f, 0.631f, 0.925f);
        drawRectangle(490.0f, 70.0f, 15.0f, 45.0f);

        //final row
        glColor3f(0.341f, 0.196f, 0.573f);
        drawRectangle(410.0f, -10.0f, 15.0f, 45.0f);

        glColor3f(0.643f, 0.631f, 0.925f);
        drawRectangle(460.0f, -10.0f, 15.0f, 45.0f);

        glColor3f(0.643f, 0.631f, 0.925f);
        drawRectangle(490.0f, -10.0f, 15.0f, 45.0f);
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
        glColor3f(0.988f, 0.72f, 0.921f);
        glBegin(GL_QUADS);
        glVertex2f(380, 575);
        glVertex2f(400, 580);
        glVertex2f(400, 0);
        glVertex2f(380, 0);
        glEnd();
        //Upper
        glColor3f(0.988f, 0.72f, 0.921f);
        glBegin(GL_QUADS);
        glVertex2f(380, 575);
        glVertex2f(400, 580);
        glVertex2f(250, 580);
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


    //right cloud
    glPushMatrix();
    glTranslatef(cloud2X, 0.0f, 0.0f);
    glColor3f(0.956f, 0.8f, 0.976f);
    drawCircle(500.0f, 750.0f, 30.0f);
    drawCircle(550.0f, 750.0f, 45.0f);
    drawCircle(600.0f, 750.0f, 30.0f);
    glPopMatrix();

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

        //Yellow Shadow
        glBegin(GL_QUADS);
        glColor3f(0.882f, 0.647f, 0.443f);
        glVertex2f(80, 250);
        glVertex2f(140, 250);
        glVertex2f(140, 260);
        glVertex2f(80, 260);
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
        //yellow shadow
        glBegin(GL_QUADS);
        glColor3f(0.882f, 0.647f, 0.443f);
        glVertex2f(140, 250);
        glVertex2f(155, 255);
        glVertex2f(155, 265);
        glVertex2f(140, 260);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.882f, 0.647f, 0.443f);
        glVertex2f(155, 255);
        glVertex2f(165, 260);
        glVertex2f(162, 270);
        glVertex2f(155, 265);
        glEnd();

        //Stripes On glass
        glLineWidth(1);
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_LINES);
        glVertex2f(97, 270);
        glVertex2f(100, 260);
        glEnd();

        glLineWidth(1);
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_LINES);
        glVertex2f(100, 275);
        glVertex2f(105, 260);
        glEnd();

         //Stripes On glass
        glLineWidth(1);
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_LINES);
        glVertex2f(130, 270);
        glVertex2f(133, 260);

        glEnd();

        glLineWidth(1);
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_LINES);
        glVertex2f(133, 275);
        glVertex2f(138, 260);
        glEnd();


        //door knob
        glLineWidth(5);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(113, 243);
        glVertex2f(122, 243);
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
        //door lines
        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(110, 210);
        glVertex2f(110, 250);
        glEnd();

        glLineWidth(1);
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(140, 210);
        glVertex2f(140, 250);
        glEnd();



        //wheels
        //Left White Wheel Circle
        glColor3f(1.0f, 1.0f, 1.0f);
        drawCircle(96.0f, 203.0f, 13.0f);
        //LEft Inner Black Wheel Circle
        glColor3f(0.0f, 0.0f, 0.0f);
        drawCircle(96.0f, 203.0f, 8.0f);
        //Right Black Wheel Circle
        glColor3f(1.0f, 1.0f, 1.0f);
        drawCircle(160.0f, 203.0f, 13.0f);
        //Right Inner White Wheel Circle
        glColor3f(0.0f, 0.0f, 0.0f);
        drawCircle(160.0f, 203.0f, 8.0f);

    glPopMatrix();




    glutSwapBuffers();
}


void handleKeypress(unsigned char key, int x, int y) {
    if (key == 'd' || key == 'D') {
       carX += 10.0f;
        if (carX > 1000.0f) {
            carX = -200.0f;
        }
        glutPostRedisplay();
    }

    if (key == 'a' || key == 'A') {
       carX -= 7.0f;
        if (carX < -200.0f) {
            carX = 1000.0f;
        }
        glutPostRedisplay();
    }
}

void update(int value) {
    cloud1X -= 5.0f;
    if (cloud1X < -1000.0f) {
        cloud1X = 1010.0f;
    }

    busX -= 5.0f;
    if (busX < -1000.0f) {
        busX = 300.0f;
    }

    cloud2X -= 5.0f;
    if (cloud2X < -1030.0f) {
        cloud2X = 1010.0f;
    }

    glutPostRedisplay(); // Notify GLUT that the display has changed
    glutTimerFunc(20, update, 0); // Notify GLUT to call update again in 10 milliseconds
}



int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1920, 1080);
    glutCreateWindow("City");

    glutDisplayFunc(drawScene);
    glutKeyboardFunc(handleKeypress);
    glutTimerFunc(20, update, 0);

    glutMainLoop();
    return 0;
}
