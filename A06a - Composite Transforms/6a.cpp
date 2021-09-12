#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <GL/glut.h>
using namespace std;

int pntX1, pntY1, choice = 0, edges;
vector<int> pntX;
vector<int> pntY;
int transX, transY;
int xf, yf;
double sx, sy;
double shear;
double angle, angleRad;
double res[3][1] = {0};
double res33[3][3] = {{0}};
int axis;
double const  REFLECTION_MATRIX[4][3][3] = {{{-1, 0, 0}, {0, -1, 0}, {0, 0, 1}}, {{1, 0, 0}, {0, -1, 0}, {0, 0, 1}}, {{-1, 0, 0}, {0, 1, 0}, {0, 0, 1}}, {{0, 1, 0}, {1, 0, 0}, {0, 0, 1}}};

double round(double d)
{
    return floor(d + 0.5);
}
void mutliplyMatrices31(const double tr[3][3], const double pt[3][1]){
    memset(res, 0, 3 * 1 * sizeof(double));

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 1; j++)
            for(int k = 0; k < 3; k++)
                res[i][j] += tr[i][k] * pt[k][j];

}
void mutliplyMatrices33(const double tr[3][3], const double pt[3][3]){
    memset(res33, 0, 3 * 3 * sizeof(double));

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            for(int k = 0; k < 3; k++)
                res33[i][j] += tr[i][k] * pt[k][j];

}
void drawPolygon()
{
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    for (int i = 0; i < 4; i++)
    {
        glVertex2i(pntX[i], pntY[i]);
    }
    glEnd();
}
void drawPolygonRotationScaling(){
    double rotMat[3][3] = {{cos(angleRad), -sin(angleRad), xf * (1 - cos(angleRad)) + yf * sin(angleRad)}, {sin(angleRad), cos(angleRad), yf * (1 - cos(angleRad)) - xf * sin(angleRad)}, {0.0, 0.0, 1.0}};

    double scalMat[3][3] = {{sx, 0 ,xf * (1-sx)}, {0, sy, yf * (1-sy)}, {0, 0, 1}};

    
    mutliplyMatrices33(rotMat, scalMat);
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 1.0);
    for(int i = 0; i < 4; i++){
        double pts[3][1] = {{pntX[i]}, {pntY[i]}, {1}};
        mutliplyMatrices31(res33, pts);
        glVertex2i((int)res[0][0], (int)res[1][0]);
    }
    glEnd();
}

void drawReflectionShearing(){
    if (axis == 1){
        double shear_matrix [3][3] = {{1, shear, 0}, {0, 1, 0}, {0, 0, 1}};
         mutliplyMatrices33(REFLECTION_MATRIX[axis], shear_matrix);
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 1.0);
    for(int i = 0; i < 4; i++){
        double pts[3][1] = {{pntX[i]}, {pntY[i]}, {1}};
        mutliplyMatrices31(res33, pts);
        glVertex2i((int)res[0][0], (int)res[1][0]);
    }
    glEnd();
    }
    else{
        double shear_matrix [3][3] = {{1, 0, 0}, {shear, 1, 0}, {0, 0, 1}};
 mutliplyMatrices33(REFLECTION_MATRIX[axis], shear_matrix);
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 1.0);
    for(int i = 0; i < 4; i++){
        double pts[3][1] = {{pntX[i]}, {pntY[i]}, {1}};
        mutliplyMatrices31(res33, pts);
        glVertex2i((int)res[0][0], (int)res[1][0]);
    }
    glEnd();
    }
   


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
        cout << "1. Rotation and scaling of an object Input" << endl;
        cout << "2. Reflection and shearing of an object Input" << endl;
        cout << "3. Exit" << endl;
        cout << "------------------" << endl;
        cin >> choice;

        if (choice == 3)
        {
            return;
        }

        if (choice == 1)
        {
            cout << "Enter the angle for rotation: ";
            cin >> angle;
            angleRad = angle * 3.1416 / 180;
            cout << "Enter the fixed point: ";
            cin >> xf >> yf;
            cout << "Enter the scaling factor [sx, sy]: ";
            cin >> sx >> sy;
        }
        else if (choice == 2)
        {
            cout << "Enter the axis for reflection [1 - X Axis, 2 - Y Axis, 3 - X=Y Line]: ";
            cin >> axis;
            cout << "Enter the shearing factor: ";
            cin >> shear;
        }
        
        if (choice == 1)
        {
            drawPolygon();
            drawPolygonRotationScaling();
        }
        else if (choice == 2)
        {
            drawPolygon();
            drawReflectionShearing();
        }
        glFlush();
    }
}

int main(int argc, char **argv)
{
    
    cout << "Enter vertices\n";
    for (int i = 0; i < 4; i++)
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
    glutCreateWindow("Composite 2D Transformations");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
}