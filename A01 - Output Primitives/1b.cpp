#include <GL/glut.h>
void myInit()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(10);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    //EARTH
    glColor3f(0.66f, 0.33f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2d(0, 0);
    glVertex2d(640, 0);
    glVertex2d(640, 170);
    glVertex2d(0, 170);
    glEnd();
    //SKY
    glColor3f(0.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2d(0, 170);
    glVertex2d(640, 170);
    glVertex2d(640, 480);
    glVertex2d(0, 480);
    glEnd();
    //HOUSE BOX
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2d(250, 170);
    glVertex2d(390, 170);
    glVertex2d(390, 250);
    glVertex2d(250, 250);
    glEnd();
    //HOUSE ROOF
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2d(230, 250);
    glVertex2d(410, 250);
    glVertex2d(320, 290);
    glEnd();
    //HOUSE DOOR
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2d(330, 170);
    glVertex2d(360, 170);
    glVertex2d(360, 220);
    glVertex2d(330, 220);
    glEnd();
    //HOUSE WINDOW
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2d(270, 190);
    glVertex2d(300, 190);
    glVertex2d(300, 220);
    glVertex2d(270, 220);
    glEnd();
    glFlush();
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Expt 01-B");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
    return 1;
}