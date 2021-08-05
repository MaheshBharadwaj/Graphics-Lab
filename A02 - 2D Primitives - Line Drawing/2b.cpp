#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
void myInit()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.4, 0.4, 0.9);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glPointSize(1);
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void DDA(int x0, int y0, int x1, int y1)
{
    float X = x0, Y = y0;
    int dx = x1 - x0;
    int dy = y1 - y0;
    int steps;
    if (abs(dx) > abs(dy))
    {
        steps = abs(dx);
    }
    else
        steps = abs(dy);
    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;
    glBegin(GL_POINTS);
    for (int i = 0; i <= steps; ++i)
    {
        glVertex2d(floor(X), floor(Y));
        X += Xinc;
        Y += Yinc;
    }
    glEnd();
}

void renderPattern()
{
    glClear(GL_COLOR_BUFFER_BIT);
    srand((unsigned)time(NULL));
    int x0, y0, x1, y1, distance;
    for (int i = 0; i < 100; ++i)
    {
        x0 = abs(rand() % 500 + 5);
        y0 = abs(rand() % 500 + 5);
        distance = abs(rand() % 100 + 20);
        x1 = int(distance / sqrt(2)) + x0;
        y1 = int(distance / sqrt(2)) + y0;
        DDA(x0, y0, x1, y1);
    }
    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Expt 02b-Pattern Drawing");
    glutDisplayFunc(renderPattern);
    myInit();
    glutMainLoop();
    return 1;
}