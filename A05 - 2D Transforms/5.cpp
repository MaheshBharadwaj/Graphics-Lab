#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <GL/glut.h>
using namespace std;

int pntX1, pntY1, choice = 0, edges;
vector<int> pntX;
vector<int> pntY;
int transX, transY;
double scaleX, scaleY;
double angle, angleRad;
int polyType;

double round(double d)
{
    return floor(d + 0.5);
}

void drawPolygon()
{
    if (polyType == 1)
        glBegin(GL_LINES);
    else
        glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 0.0);
    for (int i = 0; i < edges; i++)
    {
        glVertex2i(pntX[i], pntY[i]);
    }
    glEnd();
}

void drawPolygonTrans(int x, int y)
{
    if (polyType == 1)
        glBegin(GL_LINES);
    else
        glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 1.0);
    for (int i = 0; i < edges; i++)
    {
        glVertex2i(pntX[i] + x, pntY[i] + y);
    }
    glEnd();
}

void drawPolygonScale(double x, double y)
{
    if (polyType == 1)
        glBegin(GL_LINES);
    else
        glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 1.0);
    for (int i = 0; i < edges; i++)
    {
        glVertex2i(round(pntX[i] * x), round(pntY[i] * y));
    }
    glEnd();
}

void drawPolygonRotation(double angleRad)
{
    if (polyType == 1)
        glBegin(GL_LINES);
    else
        glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 1.0);
    for (int i = 0; i < edges; i++)
    {
        glVertex2i(round((pntX[i] * cos(angleRad)) - (pntY[i] * sin(angleRad))), round((pntX[i] * sin(angleRad)) + (pntY[i] * cos(angleRad))));
    }
    glEnd();
}

void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(3.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-640.0, 640.0, -480.0, 480.0);
}

void myDisplay(void)
{
    // Initial Polygon
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    drawPolygon();
    glFlush();
    while (true)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 0.0, 0.0);
        cout << "Enter your choice:\n\n";
        cout << "1. Translation" << endl;
        cout << "2. Scaling" << endl;
        cout << "3. Rotation" << endl;
        cout << "4. Exit" << endl;
        cout << "------------------" << endl;
        cin >> choice;

        if (choice == 4)
        {
            return;
        }

        if (choice == 1)
        {
            cout << "Enter the translation factor for X and Y: ";
            cin >> transX >> transY;
        }
        else if (choice == 2)
        {
            cout << "Enter the scaling factor for X and Y: ";
            cin >> scaleX >> scaleY;
        }
        else if (choice == 3)
        {
            cout << "Enter the angle for rotation: ";
            cin >> angle;
            angleRad = angle * 3.1416 / 180;
        }
        if (choice == 1)
        {
            drawPolygon();
            drawPolygonTrans(transX, transY);
        }
        else if (choice == 2)
        {
            drawPolygon();
            drawPolygonScale(scaleX, scaleY);
        }
        else if (choice == 3)
        {
            drawPolygon();
            drawPolygonRotation(angleRad);
        }
        glFlush();
    }
}

int main(int argc, char **argv)
{
    cout << "Line or Triangle [1/0]: ";
    cin >> polyType;
    switch (polyType)
    {
    case 1:
        edges = 2;
        break;
    case 0:
        edges = 3;
        break;
    default:
        cout << "Invalid!";
        return 1;
    }
    cout << "Enter vertices\n";
    for (int i = 0; i < edges; i++)
    {
        cout << "Enter co-ordinates for vertex  " << i + 1 << "(X, Y): ";
        cin >> pntX1 >> pntY1;
        pntX.push_back(pntX1);
        pntY.push_back(pntY1);
    }
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Basic 2D Transformations");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
}