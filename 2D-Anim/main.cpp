#include <iostream>
#include <GL/glut.h>
#include <unistd.h>
#include <cmath>
using namespace std;
#define PI 3.1415
void myInit()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(10);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-320.0, 320.0, -240.0, 240.0);
}
void displayShape(int xCoords[8], int yCoords[8])
{
    glBegin(GL_LINES);
    for (int i = 0; i < 7; i++)
    {
        glVertex2d(xCoords[i], yCoords[i]);
        glVertex2d(xCoords[i + 1], yCoords[i + 1]);
    }
    glVertex2d(xCoords[7], yCoords[7]);
    glVertex2d(xCoords[0], yCoords[0]);
    glEnd();
    glFlush();
}
void rotateShape(int xCoords[8], int yCoords[8], double angle)
{
    double rotationMatrix[3][3] = {{cos(angle), -sin(angle), 0},
                                   {sin(angle), cos(angle), 0},
                                   {0, 0, 1}};
    for (int i = 0; i < 8; i++)
    {
        xCoords[i] = (xCoords[i] * rotationMatrix[0][0]) + (yCoords[i] * rotationMatrix[0][1]);
        yCoords[i] = (xCoords[i] * rotationMatrix[1][0]) + (yCoords[i] * rotationMatrix[1][1]);
    }
}
double degreeToRadians(int degree)
{
    return (PI * (double)degree) / 180;
}
void delay()
{
  usleep(100000);
}
void startAnimation(int originalXCoords[8], int originalYCoords[8], int speed = 1)
{
    int xCoords[8], yCoords[8], angle;
    for (angle = -30; angle <= 30; angle += speed)
    {
        for (int i = 0; i < 8; i++)
        {
            xCoords[i] = originalXCoords[i];
            yCoords[i] = originalYCoords[i];
        }
        rotateShape(xCoords, yCoords, degreeToRadians(angle));
        displayShape(xCoords, yCoords);
        delay();
        glClear(GL_COLOR_BUFFER_BIT);
    }
    for (; angle >= -30; angle -= speed)
    {
        for (int i = 0; i < 8; i++)
        {
            xCoords[i] = originalXCoords[i];
            yCoords[i] = originalYCoords[i];
        }
        rotateShape(xCoords, yCoords, degreeToRadians(angle));
        displayShape(xCoords, yCoords);
        delay();
        glClear(GL_COLOR_BUFFER_BIT);
    }
    startAnimation(originalXCoords, originalYCoords, speed);
}
void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    int xCoords[] = {-10, 10, 10, 30, 30, -30, -30, -10};
    int yCoords[] = {0, 0, -100, -100, -120, -120, -100, -100};
    startAnimation(xCoords, yCoords, 5);
    glFlush();
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Pendulum");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
    return 1;
}