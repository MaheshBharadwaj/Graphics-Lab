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
void myDisplayPt()
{
    glClear(GL_COLOR_BUFFER_BIT);
    //Point
    glBegin(GL_POINTS);
    glVertex2d(150, 100);
    glEnd();
    //Line
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex2d(100, 15);
    glVertex2d(10, 145);
    glEnd();
    //LINE_STRIP
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_STRIP);
    glVertex3f(350, 350, 0.0);
    glVertex3f(375, 375, 0.0);
    glVertex3f(520, 420, 0.0);
    glVertex3f(550, 450, 0.0);
    glEnd();
    //LINE_LOOP
    glColor3f(.2f, .2f, .2f);
    glBegin(GL_LINE_LOOP);
    glVertex2d(100, 50);
    glVertex2d(200, 125);
    glVertex2d(300, 170);
    glEnd();
    //TRIANGLE
    glColor3f(.2f, 0.0f, .6f);
    glBegin(GL_TRIANGLES);
    glVertex2d(200, 150);
    glVertex2d(250, 225);
    glVertex2d(350, 270);
    glEnd();
    //TRIANGLE_STRIP
    glColor3f(.6f, 0.0f, .2f);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2d(250, 150);
    glVertex2d(300, 225);
    glVertex2d(400, 230);
    glVertex2d(430, 275);
    glEnd();
    //TRIANGLE_FAN
    glColor3f(.6f, 0.6f, .2f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(450, 150);
    glVertex2d(500, 225);
    glVertex2d(520, 230);
    glVertex2d(540, 230);
    glVertex2d(600, 270);
    glEnd();
    //QUADS
    glColor3f(.3f, 0.7f, .4f);
    glBegin(GL_QUADS);
    glVertex2d(10, 350);
    glVertex2d(60, 350);
    glVertex2d(60, 400);
    glVertex2d(10, 400);
    glEnd();
    //QUAD_STRIP
    glColor3f(.8f, 0.4f, .8f);
    glBegin(GL_QUADS);
    glVertex2d(80, 350);
    glVertex2d(90, 350);
    glVertex2d(100, 350);
    glVertex2d(100, 400);
    glVertex2d(90, 400);
    glVertex2d(80, 400);
    glEnd();
    //POLYGON
    glColor3f(.8f, 0.8f, .3f);
    glBegin(GL_POLYGON);
    glVertex2f(250, 300);
    glVertex2f(270, 400);
    glVertex2f(300, 400);
    glVertex2f(250, 250);
    glEnd();
    glFlush();
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Expt 01");
    glutDisplayFunc(myDisplayPt);
    myInit();
    glutMainLoop();
    return 1;
}