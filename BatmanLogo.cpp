#include <GL/gl.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h


void display() {

    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

    //Center Black Box
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(30, 270);
    glVertex2f(1020, 270);
    glVertex2f(1020, 480);
    glVertex2f(30, 480);
    glEnd();

    //Black box Ladder above
    for(int x=30;x<=240;x=x+30)
        {
        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        int x1=30+x;
        int y1=450+x;
        int x2=1020-x;
        int y2=480+x;
        glVertex2f(x1, y1);
        glVertex2f(x2, y1);
        glVertex2f(x2, y2);
        glVertex2f(x1, y2);
        glEnd();
        }

    //Black Box Ladder Below
    for(int x=30;x<=240;x=x+30)
        {
        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        int x1=30+x;
        int y1=310-x;
        int x2=1020-x;
        int y2=270-x;
        glVertex2f(x1, y1);
        glVertex2f(x2, y1);
        glVertex2f(x2, y2);
        glVertex2f(x1, y2);
        glEnd();
        }

    //Single Yellow Box LEft
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(60, 270);
    glVertex2f(60, 480);
    glVertex2f(90, 480);
    glVertex2f(90, 270);
    glEnd();

    //Single Yellow Box Right
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(990, 270);
    glVertex2f(990, 480);
    glVertex2f(960, 480);
    glVertex2f(960, 270);
    glEnd();

    //Yellow Ladder LEft Below
    int y_decrease_left_yellow=60;
    for(int x=30;x<=210;x=x+30)
        {
            glBegin(GL_QUADS);
            glColor3f(1.0f, 1.0f, 0.0f);
            int x1=60+x;
            int y1=360-y_decrease_left_yellow;
            int x2=90+x;
            int y2=300-y_decrease_left_yellow;
            glVertex2f(x1, y1);
            glVertex2f(x2, y1);
            glVertex2f(x2, y2);
            glVertex2f(x1, y2);
            glEnd();
            y_decrease_left_yellow=y_decrease_left_yellow+30;
        }

        //Yellow Ladder Right Below
        int y_decrease_right_yellow=60;
        for(int x=30;x<=210;x=x+30)
        {
            glBegin(GL_QUADS);
            glColor3f(1.0f, 1.0f, 0.0f);
            int x1=990-x;
            int y1=360-y_decrease_right_yellow;
            int x2=960-x;
            int y2=300-y_decrease_right_yellow;
            glVertex2f(x1, y1);
            glVertex2f(x2, y1);
            glVertex2f(x2, y2);
            glVertex2f(x1, y2);
            glEnd();
            y_decrease_right_yellow=y_decrease_right_yellow+30;
        }

        //Yellow Ladder Right Upper
        int y_increase_right_yellow=60;
        for(int x=30;x<=210;x=x+30)
        {
            glBegin(GL_QUADS);
            glColor3f(1.0f, 1.0f, 0.0f);
            int x1=60+x;
            int y1=450+y_increase_right_yellow;
            int x2=90+x;
            int y2=390+y_increase_right_yellow;
            glVertex2f(x1, y1);
            glVertex2f(x2, y1);
            glVertex2f(x2, y2);
            glVertex2f(x1, y2);
            glEnd();
            y_increase_right_yellow=y_increase_right_yellow+30;
        }

        //Yellow Ladder Left Upper
        int y_increase_left_yellow=60;
        for(int x=30;x<=210;x=x+30)
        {
            glBegin(GL_QUADS);
            glColor3f(1.0f, 1.0f, 0.0f);
            int x1=990-x;
            int y1=450+y_increase_left_yellow;
            int x2=960-x;
            int y2=390+y_increase_left_yellow;
            glVertex2f(x1, y1);
            glVertex2f(x2, y1);
            glVertex2f(x2, y2);
            glVertex2f(x1, y2);
            glEnd();
            y_increase_left_yellow=y_increase_left_yellow+30;
        }




        for(int x=30;x<=60;x=x+30)
        {
            glBegin(GL_QUADS);
            glColor3f(1.0f, 1.0f, 0.0f);
            int x1=420+x;
            int y1=690-x;
            int x2=630-x;
            int y2=720-x;
            glVertex2f(x1, y1);
            glVertex2f(x2, y1);
            glVertex2f(x2, y2);
            glVertex2f(x1, y2);
        }
    //Left Ear
        //Yellow Box left Above
        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(270,690 );
        glVertex2f(270,630 );
        glVertex2f(450,630 );
        glVertex2f(450,690 );
        glEnd();

        //left ear box mid point
        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(360,630 );
        glVertex2f(360,480 );
        glVertex2f(420,480 );
        glVertex2f(420,630 );
        glEnd();

        //top left box ear
        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(330,600 );
        glVertex2f(330,510 );
        glVertex2f(360,510 );
        glVertex2f(360,600 );
        glEnd();

        //top right box ear
        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(420,630 );
        glVertex2f(420,510 );
        glVertex2f(450,510 );
        glVertex2f(450,630 );
        glEnd();
       //Right ear
        //Yellow Box right Above
        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(780,690 );
        glVertex2f(780,630 );
        glVertex2f(600,630 );
        glVertex2f(600,690 );
        glEnd();

        //right ear box mid point
        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(630,630 );
        glVertex2f(630,480 );
        glVertex2f(690,480 );
        glVertex2f(690,630 );
        glEnd();

        //top right box ear
        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(690,600 );
        glVertex2f(690,510 );
        glVertex2f(720,510 );
        glVertex2f(720,600 );
        glEnd();

        //top left box ear
        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(600,630 );
        glVertex2f(600,510 );
        glVertex2f(630,510 );
        glVertex2f(630,630 );
        glEnd();
    //Left Bottom
    //bottom yellow strip
        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(270,60 );
        glVertex2f(270,90 );
        glVertex2f(780,90 );
        glVertex2f(780,60 );
        glEnd();
        //bottom dot left
        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(300,90 );
        glVertex2f(300,120 );
        glVertex2f(330,120 );
        glVertex2f(330,90 );
        glEnd();
        //bottom dot right
        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(750,90 );
        glVertex2f(750,120 );
        glVertex2f(720,120 );
        glVertex2f(720,90 );
        glEnd();

        //bottom left tail
        //bottom box
        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(360,90 );
        glVertex2f(360,150 );
        glVertex2f(480,150 );
        glVertex2f(480,90 );
        glEnd();

        //one step above box
        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(390,150 );
        glVertex2f(390,180 );
        glVertex2f(480,180 );
        glVertex2f(480,150 );
        glEnd();

        //top most box
        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(420,180 );
        glVertex2f(420,210 );
        glVertex2f(450,210 );
        glVertex2f(450,180 );
        glEnd();

        //bottom tail single box right
        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(480,90 );
        glVertex2f(480,120 );
        glVertex2f(510,120 );
        glVertex2f(510,90 );
        glEnd();

        //bottom Right Tail
        //bottom box
        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(690,90 );
        glVertex2f(690,150 );
        glVertex2f(570,150 );
        glVertex2f(570,90 );
        glEnd();

        //one step above box
        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(660,150 );
        glVertex2f(660,180 );
        glVertex2f(570,180 );
        glVertex2f(570,150 );
        glEnd();

        //top most box
        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(630,180 );
        glVertex2f(630,210 );
        glVertex2f(600,210 );
        glVertex2f(600,180 );
        glEnd();

        //bottom tail single box left
        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(570,90 );
        glVertex2f(570,120 );
        glVertex2f(540,120 );
        glVertex2f(540,90 );
        glEnd();

    //Lines Horizontal
    for(int x=0;x<=750;x+=30)
        {
        glLineWidth(1);
        glBegin(GL_LINES);
        glColor3f(1.0f, 0.3f, 0.5f);
        glVertex2f(0,x);
        glVertex2f(1050,x);
        glEnd();
        }

    //Lines Vertical
    for(int x=0;x<=1020;x+=30)
        {
        glLineWidth(2);
        glBegin(GL_LINES);
        glColor3f(1.0f, 0.3f, 0.5f);
        glVertex2f(x,0);
        glVertex2f(x,750);
        glEnd();
        }


    glFlush(); // Render now
}

void init() {
    glClearColor(1, 1, 1, 0.0);//last er ta opacity
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,1050,0,750);
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 500); // Set the window's initial width & height
    glutInitWindowPosition(500, 100);  // Set the window's initial position according to the monitor
    glutCreateWindow("batmanlogo"); // Create a window with the given title
    init();
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop(); // Enter the event-processing loop
    return 0;
}
