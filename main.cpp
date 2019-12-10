#include<iostream>
#include <windows.h>
#include<mmsystem.h>
#include <GL/glut.h>
#include<math.h>
#include <bits/stdc++.h>
using namespace std;
void callback(int value);
float posX = 30, posY=250;
float bulletX = posX, bulletY = posY;
double posx=0.0;
int health=100;

int countt=0;
double pointx=0;
double planex=0;
double planey=0;

double bulx=75;
double buly=208;



int up = 0, down=0, moveRight = 0, moveLeft = 0;

float deltaX = 10;

int  score=0;
bool isStart=false;
double speed=0;
int forExit=false;
int cloudCenterX=200, cloudCenterY=200;



void cloudDraw()
{
    ////1st cloud

    int cloudCenterX=135, cloudCenterY=380;
    glColor3f(1.0,1.0,1.0);
     glBegin(GL_POLYGON);
     glVertex2f(cloudCenterX, cloudCenterY-5);
     glVertex2f(cloudCenterX-20, cloudCenterY);
       for(int i=0; i<360; i++){
       double  angle = i * 3.1416 / 180.0;
        glVertex2f(20*cos(angle)+cloudCenterX,20*sin(angle)+cloudCenterY);
    }
    glVertex2f(cloudCenterX+20, cloudCenterY);
    glVertex2f(cloudCenterX+20, cloudCenterY-5);



     glBegin(GL_POLYGON);
     cloudCenterX=155, cloudCenterY=400;
     glVertex2f(cloudCenterX, cloudCenterY-5);
     glVertex2f(cloudCenterX-20, cloudCenterY);
       for(int i=0; i<360; i++){
       double  angle = i * 3.1416 / 180.0;
        glVertex2f(20*cos(angle)+cloudCenterX,20*sin(angle)+cloudCenterY);
    }
     glVertex2f(cloudCenterX+20, cloudCenterY);
    glVertex2f(cloudCenterX+20, cloudCenterY-5);



     glBegin(GL_POLYGON);
     cloudCenterX=175, cloudCenterY=385;
     glVertex2f(cloudCenterX, cloudCenterY-5);
     glVertex2f(cloudCenterX-20, cloudCenterY);
       for(int i=0; i<360; i++){
       double  angle = i * 3.1416 / 180.0;
        glVertex2f(20*cos(angle)+cloudCenterX,20*sin(angle)+cloudCenterY);
    }
     glVertex2f(cloudCenterX+20, cloudCenterY);
    glVertex2f(cloudCenterX+20, cloudCenterY-5);


     glEnd();




////2nd cloud
      glColor3f(1.0,1.0,1.0);
     glBegin(GL_POLYGON);
     cloudCenterX=435, cloudCenterY=330;
     glVertex2f(cloudCenterX, cloudCenterY-5);
     glVertex2f(cloudCenterX-20, cloudCenterY);
       for(int i=0; i<360; i++){
       double  angle = i * 3.1416 / 180.0;
        glVertex2f(20*cos(angle)+cloudCenterX,20*sin(angle)+cloudCenterY);
    }
    glVertex2f(cloudCenterX+20, cloudCenterY);
    glVertex2f(cloudCenterX+20, cloudCenterY-5);



     glBegin(GL_POLYGON);
     cloudCenterX=455, cloudCenterY=350;
     glVertex2f(cloudCenterX, cloudCenterY-5);
     glVertex2f(cloudCenterX-20, cloudCenterY);
       for(int i=0; i<360; i++){
       double  angle = i * 3.1416 / 180.0;
        glVertex2f(20*cos(angle)+cloudCenterX,20*sin(angle)+cloudCenterY);
    }
     glVertex2f(cloudCenterX+20, cloudCenterY);
     glVertex2f(cloudCenterX+20, cloudCenterY-5);



     glBegin(GL_POLYGON);
     cloudCenterX=475, cloudCenterY=335;
     glVertex2f(cloudCenterX, cloudCenterY-5);
     glVertex2f(cloudCenterX-20, cloudCenterY);
       for(int i=0; i<360; i++){
       double  angle = i * 3.1416 / 180.0;
        glVertex2f(20*cos(angle)+cloudCenterX,20*sin(angle)+cloudCenterY);
    }
     glVertex2f(cloudCenterX+20, cloudCenterY);
     glVertex2f(cloudCenterX+20, cloudCenterY-5);

     glEnd();


}

class enemyPLane
{
public:
       double     enemyplanex=650;
         double   enemyplaney=100;
public:
    void enemyplane()
    {
    //glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
            glVertex2f(enemyplanex,enemyplaney);
            glVertex2f(enemyplanex+20,enemyplaney);
            glVertex2f(enemyplanex+20,enemyplaney+20);
            glVertex2f(enemyplanex,enemyplaney+20);

    glEnd();
    }
    void collision()
    {
        if(enemyplanex<=0)
        {
            enemyplanex=750;
            enemyplaney+=5;
            health-=2;

        }

        if((bulx>=enemyplanex && bulx<=enemyplanex+20)&&(buly>=enemyplaney && buly<=enemyplaney+20)||(bulx+5>=enemyplanex && bulx+5<=enemyplanex+20)&&(buly+5>=enemyplaney && buly+5<=enemyplaney+20))
        {

            sndPlaySound("Explosion.wav",SND_ASYNC);
            enemyplanex=750;
            enemyplaney=100;
            enemyplaney+=5;
            score++;
            bulx=planex+80;
            buly=planey+208;
            countt=0;
            cout<<"score is: "<<score<<"\t";
            cout<<"Health is: "<<health<<endl;


        }
        if((enemyplanex<=planex+120 && enemyplaney>=planey+170)&&(enemyplanex<=planex+120 && enemyplaney<=planey+250)||(enemyplanex+20<=planex+120 && enemyplaney+20>=planey+170)&&(enemyplanex+20<=planex+120 && enemyplaney+20<=planey+250))
        {
            sndPlaySound("Plane.wav",SND_ASYNC);
            enemyplanex=750;
            enemyplaney=100;
            enemyplaney+=5;
            health-=20;
            cout<<"Health is: "<<health<<endl;

        }

    }
};


void background()
{
    glColor3f(0.0,0.9,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(1000,0);
    glVertex2f(1000,600/3);
    glVertex2f(0,600/3);
    glEnd();

    glColor3f(0.53,0.81,0.92);
    glBegin(GL_POLYGON);
    glVertex2f(0,600/3);
    glVertex2f(1000,600/3);
    glVertex2f(1000,600);
    glVertex2f(0,600);
    glEnd();
}



void bullet()
{
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
            glVertex2f(bulx,buly);
            glVertex2f(bulx+5,buly);
            glVertex2f(bulx+5,buly+5);
            glVertex2f(bulx,buly+5);

    glEnd();

}

void Plane(){


    glColor3f(0.3,0.3,0.3);
    glBegin(GL_POLYGON);
            glVertex2f(planex+50,planey+200);
            glVertex2f(planex+100,planey+200);
            glVertex2f(planex+120,planey+210);
            glVertex2f(planex+100,planey+220);
            glVertex2f(planex+50,planey+220);
    glEnd();

    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
            glVertex2f(planex+50,planey+206);
            glVertex2f(planex+40,planey+210);
            glVertex2f(planex+50,planey+214);
    glEnd();

    glColor3f(0.3,0.3,0.3);
    glBegin(GL_POLYGON);
            glVertex2f(planex+50,planey+232);
            glVertex2f(planex+50,planey+188);
            glVertex2f(planex+54,planey+181);
            glVertex2f(planex+62,planey+200);
            glVertex2f(planex+62,planey+220);
            glVertex2f(planex+54,planey+239);
    glEnd();


    glColor3f(0.3,0.3,0.3);
    glBegin(GL_POLYGON);
            glVertex2f(planex+72,planey+200);
            glVertex2f(planex+56,planey+175);
            glVertex2f(planex+62,planey+170);
            glVertex2f(planex+95,planey+200);

    glEnd();

    glColor3f(0.3,0.3,0.3);
    glBegin(GL_POLYGON);
            glVertex2f(planex+72,planey+220);
            glVertex2f(planex+56,planey+245);
            glVertex2f(planex+62,planey+250);
            glVertex2f(planex+95,planey+220);

    glEnd();


}



void myInit (void)
{
    glClearColor(1,1,1,1);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);

}
enemyPLane e1,e2,e3,e4,e5,e6,e7,e8,e9,e10;
void myDisplay(void)
{
    if(health<=0)
    {
        callback(1);
        exit(0);
    }

    glClear (GL_COLOR_BUFFER_BIT);
    glPointSize(4.0);
    glColor3f(1.0f, 1.0f, 1.0f);
    background();
        glPushMatrix();
        glTranslatef(posx,0.0, 0.0);
        cloudDraw();
        glPopMatrix();
        if(posx>=520)
        {
            cloudDraw();
            posx=0.0;
        }
    posx+=0.05;
    bullet();


    bulx+=3;
    countt++;
    if(countt==200)
    {
        bullet();
        bulx=planex+80;
        buly=planey+208;
        countt=0;
    }
   Plane();
   if(planex<=-50)
   {
       planex=-50;
   }
   if(planex>=490)
   {
       planex=490;
   }
   if(planey>=260)
   {
       planey=260;
   }
   if(planey<=-200)
   {
       planey=-200;
   }
 glColor3f(0.0f, 0.0f, 1.0f);
   e1.enemyplane();
   e1.enemyplanex-=(speed+0.04);
   e1.collision();

   e2.enemyplaney=100;
   e2.enemyplane();
   e2.enemyplanex-=(speed+0.09);
   e2.collision();

   e3.enemyplaney=150;
   e3.enemyplane();
   e3.enemyplanex-=(speed+0.02);
   e3.collision();


   e4.enemyplaney=200;
   e4.enemyplane();
   e4.enemyplanex-=(speed+0.06);
   e4.collision();


   e5.enemyplaney=250;
   e5.enemyplane();
   e5.enemyplanex-=(speed+0.01);
   e5.collision();


   e6.enemyplaney=310;
   e6.enemyplane();
   e6.enemyplanex-=(speed+0.02);
   e6.collision();


   e7.enemyplaney=350;
   e7.enemyplane();
   e7.enemyplanex-=(speed+0.03);
   e7.collision();

   e8.enemyplaney=400;
   e8.enemyplane();
   e8.enemyplanex-=(speed+0.04);
   e8.collision();


   e9.enemyplaney=450;
   e9.enemyplane();
   e9.enemyplanex-=(speed+0.05);
   e9.collision();


   e10.enemyplaney=280;
   e10.enemyplane();
   e10.enemyplanex-=(speed+0.07);
   e10.collision();


    speed+=0.00001;


    glFlush();
   // buttonFunction();
    glutPostRedisplay();


}

void keyListener(int key,int, int){
    switch(key){
        case GLUT_KEY_UP: planey+=10;break;
        case GLUT_KEY_DOWN: planey-=10; break;
        //case GLUT_KEY_LEFT: planex-=10; break;
        //case GLUT_KEY_RIGHT: planex+=10; break;

    }
}

void keyboard(unsigned char key,int x,int y)
{
    if(key==27)
    {
        callback(1);
        exit(0);
    }
}

void callback(int value) {
  switch (value) {
    case 1 :
        cout<<"\t\t\t\t Game Over"<<endl;
        cout<<"\t\t\t Your Total score is: "<<score<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
       break;
}
}

int main(int argc, char** argv)
{
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1600, 800);
    glutInitWindowPosition (0, 0);
    glutCreateWindow ("Airplane shooting");
    myInit ();
    glutDisplayFunc(myDisplay);
    glutSpecialFunc(keyListener);
    glutKeyboardFunc(keyboard);

    //glutTimerFunc(15000, callback, 1);


    glutMainLoop();
}
