#include <GL/glut.h>
#include <iostream>
using namespace std;

#define LINES 8
double x_arr[2 * LINES], y_arr[2 * LINES];
void myInit()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    gluOrtho2D(-100, 100, -100, 100);
}

void displayLine(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    double dy, dx, step, x, y, k, Xin, Yin;

    for (int i = 0; i < 2 * LINES; i += 2)
    {
        double x1 = x_arr[i], x2 = x_arr[i + 1], y1 = y_arr[i], y2 = y_arr[i + 1];
        dx = x2 - x1;
        dy = y2 - y1;

        if (abs(dx) > abs(dy))
            step = abs(dx);
        else
            step = abs(dy);

        Xin = dx / step;
        Yin = dy / step;

        x = x1;
        y = y1;

        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_POINTS);
        glVertex2f(x, y);

        for (k = 1; k <= step; k++)
        {
            x = x + Xin;
            y = y + Yin;

            glVertex2i((int)x, (int)y);
        }
    }
    glEnd();
    glFlush();
}

int main(int argc, char *argv[])
{
    for (int i = 0; i < 2 * LINES; i += 2)
    {
        cout << "Enter (x0, y0), (x1, y1) for line " << (i + 1) << " :";
        cin >> x_arr[i] >> y_arr[i] >> x_arr[i + 1] >> y_arr[i + 1];
    }
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Expt 02a-Line Drawing");
    glutDisplayFunc(displayLine);
    myInit();
    glutMainLoop();

    return 1;
}