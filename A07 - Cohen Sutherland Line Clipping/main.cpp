#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <GL/glut.h>
using namespace std;
float a1, b1, a2, b2;
float xwmin, ywmin, xwmax, ywmax;
void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10.0, 630.0, -10.0, 470.0);
}

int regioncode(float x, float y)
{
    int code = 0;
    if (y > ywmax)
        code = 8;
    if (y < ywmin)
        code = 4;
    if (x > xwmax)
        code += 2;
    if (x < xwmin)
        code += 1;
    return code;
}
void cohensutherland()
{
    int c1 = regioncode(a1, b1);
    int c2 = regioncode(a2, b2);
    float m = (b1-b1)/(a2-a1);
    if ((c1 | c2) > 0)
    {
        if ((c1 & c2) > 0)
            exit(0);
        float ai = a1, bi = b1;
        int c = c1;
        if (c == 0)
        {
            ai = a2;
            bi = b2;
            c = c2;
        }
        float a, b;
        if ((c & 8) > 0)
        {
            b = ywmax;
            a = ai + (1.0 / m) * (ywmax - bi);
        }
        else if ((c & 4) > 0)
        {
            b = ywmin;
            a = ai + (1.0 / m) * (ywmin - bi);
        }
        else if ((c & 2) > 0)
        {
            a = xwmax;
            b = bi + m*(xwmax + ai);
        }
        else if ((c & 1) > 0)
        {
            a = xwmin;
            b = bi + m*(xwmin - ai);
        }
        if (c == c1)
        {
            a1 = a;
            b1 = b;
            c1 = regioncode(a1, b1);
        }
        if (c == c2)
        {
            a2 = a;
            b2 = b;
            c2 = regioncode(a2, b2);
        }
    }
}
void disp()
{
    glColor3f(0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    glVertex2d(a1, b1);
    glVertex2d(a2, b2);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2d(xwmin, ywmin);
    glVertex2d(xwmin, ywmax);
    glVertex2d(xwmax, ywmax);
    glVertex2d(xwmax, ywmin);
    glEnd();
    glFlush();
}
void clipline(unsigned char key, int x, int y)
{
    if (key =='c' )
    {
        cohensutherland();
        glColor3f(0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_LINES);
        glVertex2d(a1, b1);
        glVertex2d(a2, b2);
        glEnd();
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2d(xwmin, ywmin);
        glVertex2d(xwmin, ywmax);
        glVertex2d(xwmax, ywmax);
        glVertex2d(xwmax, ywmin);
        glEnd();
        glFlush();
    }
}
int main(int argc, char **argv)
{
    cout <<"Lines"<< endl;
    cout <<"Line 1(a1, b1) : " ;
    cin >> a1 >> b1;
    cout <<"Line 2(a2, b2) : " ;
    cin >> a2 >> b2;
    cout <<"Window"<< endl;
    cout <<"XWmin : " ;
    cin >> xwmin;
    cout <<"YWmin : " ;
    cin >> ywmin;
    cout <<"XWmax : " ;
    cin >> xwmax;
    cout <<"YWmax : " ;
    cin >> ywmax;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow( "Cohen Sutherland Line clipping" );
    glutDisplayFunc(disp);
    glutKeyboardFunc(clipline);
    myInit();
    glutMainLoop();
    return 0;
}