#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
using namespace std;

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
        glColor3f(0.15f, 0.1f, 0.25f);
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
       glColor3f(0.4f, 0.3f, 0.2f);
        glBegin(GL_QUADS);
        glVertex2f(230, 285);
        glVertex2f(170, 285);
        glVertex2f(170, 250);
        glVertex2f(230, 250);
        glEnd();

        //Yellow Shadow
        glBegin(GL_QUADS);
        glColor3f(0.35f, 0.25f, 0.15f);
        glVertex2f(230, 250);
        glVertex2f(170, 250);
        glVertex2f(170, 260);
        glVertex2f(230, 260);
        glEnd();

        //Right Window
        glColor3f(0.4f, 0.3f, 0.2f);
        glBegin(GL_POLYGON);
        glVertex2f(170, 250);
        glVertex2f(155, 260);
        glVertex2f(145, 260);
        glVertex2f(153, 285);
        glVertex2f(170, 285);
        glEnd();
        //yellow shadow
        glBegin(GL_QUADS);
        glColor3f(0.35f, 0.25f, 0.15f);
        glVertex2f(170, 250);
        glVertex2f(155, 255);
        glVertex2f(155, 265);
        glVertex2f(170, 260);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.35f, 0.25f, 0.15f);
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
        glColor3f(0.956f, 0.89f, 0.896f);
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
        glColor3f(0.35f, 0.29f, 0.45f);
        glBegin(GL_QUADS);
        glVertex2f(107, 268);
        glVertex2f(133, 263);
        glVertex2f(139, 248);
        glVertex2f(100, 250);
        glEnd();

        //window shadow
        glColor3f(0.26f, 0.21f, 0.36f);
        glBegin(GL_QUADS);
        glVertex2f(103, 258);
        glVertex2f(133, 253);
        glVertex2f(139, 248);
        glVertex2f(100, 250);
        glEnd();
        //windows stripes
        glLineWidth(1);
        glColor3f(0.48f, 0.48f, 0.58f);
        glBegin(GL_LINES);
        glVertex2f(119, 261);
        glVertex2f(125, 259);
        glEnd();

        glLineWidth(1);
       glColor3f(0.48f, 0.48f, 0.58f);
        glBegin(GL_LINES);
        glVertex2f(118, 258);
        glVertex2f(129, 255);
        glEnd();

        //Front Light
        if(batmobilemoveforware && currentScene==2)
        {
        glColor3f(0.956f, 0.89f, 0.896f);
        glBegin(GL_QUADS);
        glVertex2f(205, 240);
        glVertex2f(210, 233);
        glVertex2f(195,233);
        glVertex2f(195,242);
        glEnd();
        }

        if(batsignal)
        {
        glColor3f(0.956f, 0.89f, 0.896f);
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
    if (currentScene==1) {
        drawDawnScene();
    } else if(currentScene==2) {
        drawNightScene();
    }
}

void handleKeypress(unsigned char key, int x, int y) {
    if (key == 'd' || key == 'D') {
        batmobilemoveforware=true;
       batmobile += 15.0f;
        if (batmobile > 1000.0f) {
            batmobile = -200.0f;
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

    if (key == 'l' || key == 'SL') {
        if(!batsignal&& currentScene==2)
        {
        batsignal=true;

        }
        else{
            batsignal=false;
        }
       glutPostRedisplay();
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
    cout<<"press Mouse Left Button to change time of scenary"<<endl;
    cout<<"press A/D to Move the batmobile"<<endl;
    cout<<"press W/S to Move control the Plane"<<endl;
    cout<<"press L to Turn on batsignal"<<endl;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1920, 1080);
    glutCreateWindow("City");
    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeypress);
    glutKeyboardUpFunc(handleKeyRelease);
    glutMouseFunc(handleMouseClick);
    glutTimerFunc(16, update, 0);

    glutMainLoop();
    return 0;
}
