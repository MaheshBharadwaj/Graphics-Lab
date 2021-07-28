/* simple.c second version */
/* This program draws a white rectangle on a black background.*/
#include <GL/glut.h> /* glut.h includes gl.h and glu.h*/
void display()
{
    /* clear window */
    glClear(GL_COLOR_BUFFER_BIT);
    /* draw unit square polygon */
    glBegin(GL_POLYGON);
    glVertex2f(-0.5, -0.5);
    glVertex2f(-0.5, 0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(0.5, -0.5);
    glEnd();
    /* flush GL buffers */
    glFlush();
}
void init() // initialize colors
{
    /* set clear color to black */
    glClearColor(0.0, 0.0, 0.0, 0.0);
    /* set fill color to white */
    glColor3f(1.0, 1.0, 1.0);
}
int main(int argc, char **argv)
{
    /* Initialize mode and open a window in upper left corner of/* screen */
    /* Window title is name of program (arg[0]) */
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500); // Set window Size
    glutInitWindowPosition(0, 0); //Set Window Position
    glutCreateWindow("simple");   //Create Window and Set title
    glutDisplayFunc(display);     //Call the Displaying function
    init();                       //Initialize Drawing Colors
    glutMainLoop();               //Keep displaying until program is closed.
}