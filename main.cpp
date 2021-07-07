#include <windows.h>
#include <GL/glut.h>
#include <cmath>
#define PI 3.1416

void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
GLfloat angle = 0.0f;
GLfloat tr_x = 0;
GLfloat tr_y = 0;
void quad1()
{
    glColor3f (1.0, 1.0, 1.0);
GLfloat angle, raioX=0.5f, raioY=0.5f;
GLfloat circle_points = 100;
GLfloat circle_angle = PI / 2.0f;
glBegin(GL_LINES);
for (int i = 0; i <= circle_points; i++) {
    GLfloat current_angle = circle_angle*i/circle_points;
    glVertex2f(0.0+cos(current_angle)*raioX, 0.0+sin(current_angle)*raioY);
}
glEnd();
glBegin(GL_LINE_STRIP);
glColor3f(1.0f,0.0f,0.0f);
        glVertex2d(0.0f, 0.5f);
        glVertex2d( 0.0f, 0.0f);

        glColor3f(1.0f,1.0f,1.0f);
        glVertex2d(0.0f, 0.0f);
        glVertex2d( 0.5f, 0.0f);
glEnd();

}
void quad2()
{
    glColor3f (1.0, 1.0, 1.0);
GLfloat angle, raioX=0.5f, raioY=-0.5f;
GLfloat circle_points = 100;
GLfloat circle_angle = PI / 2.0f;

glBegin(GL_LINES);
for (int i = 0; i <= circle_points; i++) {
    GLfloat current_angle = circle_angle*i/circle_points;
    glVertex2f(0.0+cos(current_angle)*raioX, -0.01+sin(current_angle)*raioY);
}
glEnd();

glBegin(GL_LINE_STRIP);
glColor3f(1.0f,1.0f,1.0f);
        glVertex2d(0.0f, -0.5f);
        glVertex2d( 0.0f, 0.0f);

        glColor3f(1.0f,1.0f,1.0f);
        glVertex2d(0.0f, 0.0f);
        glVertex2d( 0.5f, 0.0f);
glEnd();
}

void quad3()
{
    glColor3f (1.0, 1.0, 1.0);
GLfloat angle, raioX=-0.5f, raioY=0.5f;
GLfloat circle_points = 100;
GLfloat circle_angle = PI / 2.0f;

glBegin(GL_LINES);
for (int i = 0; i <= circle_points; i++) {
    GLfloat current_angle = circle_angle*i/circle_points;
    glVertex2f(0.01+cos(current_angle)*raioX, 0.0+sin(current_angle)*raioY);
}
glEnd();
glBegin(GL_LINE_STRIP);
glColor3f(1.0f,1.0f,1.0f);
        glVertex2d(0.0f, -0.5f);
        glVertex2d(0.0f, 0.0f);

        glColor3f(1.0f,1.0f,1.0f);
        glVertex2d(0.0f, 0.0f);
        glVertex2d(-0.5f, 0.0f);
glEnd();
}
void quad4()
{
    glColor3f (1.0, 1.0, 1.0);
GLfloat angle, raioX=-0.5f, raioY=-0.5f;
GLfloat circle_points = 100;
GLfloat circle_angle = PI / 2.0f;

glBegin(GL_LINES);
for (int i = 0; i <= circle_points; i++) {
    GLfloat current_angle = circle_angle*i/circle_points;
    glVertex2f(0.01+cos(current_angle)*raioX,-0.01+sin(current_angle)*raioY);
}
glEnd();

glBegin(GL_LINE_STRIP);
glColor3f(1.0f,1.0f,1.0f);
        glVertex2d(0.0f, -0.5f);
        glVertex2d(0.0f, 0.0f);

        glColor3f(1.0f,1.0f,1.0f);
        glVertex2d(0.0f, 0.0f);
        glVertex2d(-0.5f, 0.0f);
glEnd();
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(tr_x,tr_y,0);
    glRotatef(angle,0,0,1);

    quad1();
    quad2();
    quad3();
    quad4();
    glFlush();
}

void reshape(GLsizei width, GLsizei height) {

    if (height == 0) height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;


    glViewport(0, 0, width, height);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (width >= height) {

        gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
    } else {

        gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
    }
}

void keyboard(unsigned char key, int x, int y) {
    float d = 1;
    switch (key) {
        case '1':
            angle += d;
            break;
        case '2':
            angle -= d;
            break;
        case 27:
            exit(0);
            break;
    }
    glutPostRedisplay();
}


void specialKeys(int key, int x, int y) {
    float v = 0.02;
    switch (key) {
    case GLUT_KEY_UP:
        tr_y += v;
        break;
    case GLUT_KEY_DOWN:
        tr_y -= v;
        break;
    case GLUT_KEY_LEFT:
        tr_x -= v;
        break;
    case GLUT_KEY_RIGHT:
        tr_x += v;
        break;
    }
    glutPostRedisplay();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 640);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Key Input");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);
    initGL();
    glutMainLoop();
    return 0;
}
