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
    glBegin(GL_POINTS);
    glVertex2d(150, 100);
    glVertex2d(100, 230);
    glVertex2d(170, 130);
    glVertex2d(300, 350);
    glEnd();
    glFlush();
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("First Exercise");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
    return 1;
}