#include <stdlib.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;

void myInit()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.9, 0.1, 0.1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glPointSize(2);
    gluOrtho2D(-250.0, 250.0, -250.0, 250.0);
}

void plotAll(int x, int y, int xc, int yc)
{
    glVertex2d(x + xc, y + yc);
    glVertex2d(x + xc, -y + yc);
    glVertex2d(-x + xc, y + yc);
    glVertex2d(-x + xc, -y + yc);

    glVertex2d(y + xc, x + yc);
    glVertex2d(y + xc, -x + yc);
    glVertex2d(-y + xc, x + yc);
    glVertex2d(-y + xc, -x + yc);
}

void circle(int xc, int yc, int r)
{
    int x = r, y = 0, pk = 1 - r;
    glBegin(GL_POINTS);
    plotAll(x, y, xc, yc);
    while (x > y)
    {
        y++;

        if (pk < 0)
        {
            pk += (2 * y) + 1;
        }
        else
        {
            x--;
            pk += (2 * y) - (2 * x) + 1;
        }
        plotAll(x, y, xc, yc);
    }
    glEnd();
    glFlush();
}

void button()
{
    glClear(GL_COLOR_BUFFER_BIT);
    circle(0, 0, 100);
    circle(0, 0, 110);
    circle(40, 40, 10);
    circle(40, -40, 10);
    circle(-40, 40, 10);
    circle(-40, -40, 10);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Expt 04b - Design using Circles");
    glutDisplayFunc(button);
    myInit();
    glutMainLoop();
    return 1;
}
