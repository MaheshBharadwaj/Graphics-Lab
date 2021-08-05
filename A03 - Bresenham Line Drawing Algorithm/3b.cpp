#include <stdlib.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;

int x0, y0, x1, y1;

void myInit()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.4, 0.4, 0.9);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glPointSize(1);
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void BresenhamLine(int x0, int y0, int x1, int y1)
{
    int x, y, dy, dx, pk;
    dx = x1 - x0;
    dy = y1 - y0;

    x = x0;
    y = y0;

    if (dy < dx)
    {
        pk = (2 * dy) - dx; //p0

        glBegin(GL_POINTS);
        for (x = x0; x < x1; x++)
        {
            if (pk > 0)
            {
                glVertex2d(x, ++y);
                pk = pk + (2 * dy) - (2 * dx);
            }
            else
            {
                glVertex2d(x, y);
                pk = pk + (2 * dy);
            }
        }
        glEnd();
    }
    else
    {
        pk = (2 * dx) - dy;

        glBegin(GL_POINTS);
        for (y = y0; y < y1; y++)
        {
            if (pk > 0)
            {
                glVertex2d(++x, y);
                pk = pk + (2 * dx) - (2 * dy);
            }
            else
            {
                glVertex2d(x, y + 1);
                pk = pk + (2 * dx);
            }
        }
        glEnd();
    }
    glFlush();
}

void alphabet()
{
    BresenhamLine(250, 50, 250, 300);
    BresenhamLine(250, 300, 400, 300);
    BresenhamLine(250, 175, 350, 175);
    BresenhamLine(250, 50, 400, 50);
    // BresenhamLine();
    // BresenhamLine();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Expt 03b - Alphabet with Bresenham");
    glutDisplayFunc(alphabet);
    myInit();
    glutMainLoop();
    return 1;
}
