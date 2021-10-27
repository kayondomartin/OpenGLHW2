#include <iostream>
#include <GL/glut.h>
#define WINDOW_HEIGHT   600
#define WINDOW_WIDTH    800
#define WINDOW_POS_Y    100
#define WINDOW_POS_X    100

int shoulderL = 0;
int elbowL = 0;
int shoulderR = 0;
int elbowR = 0;
bool side = false;
unsigned char leftString[] = "Left Part";
unsigned char rightString[] = "Right Part";
unsigned char* displayString = rightString;
void resize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, ((float)w) / h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void keyboardUp(unsigned char key, int x, int y){
    switch(key) {
        case 's':
            if(side)
                shoulderL = (shoulderL + 5) % 360;
            else
                shoulderR = (shoulderR + 5) % 360;
            glutPostRedisplay();
            break;
        case 'S':
            if(side)
                shoulderL = (shoulderL - 5) % 360;
            else
                shoulderR = (shoulderR - 5) % 360;
            glutPostRedisplay();
            break;
        case 'e':
            if(side)
                elbowL = (elbowL + 5) % 360;
            else
                elbowR = (elbowR + 5) % 360;
            glutPostRedisplay();
            break;
        case 'E':
            if(side)
                elbowL = (elbowL - 5) % 360;
            else
                elbowR = (elbowR - 5) % 360;
            glutPostRedisplay();
            break;
    }
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'l':
            side = true;
            break;
        case 'r':
            side = false;
            break;
        case 27:
            exit(0);
            break;
        default:
            break;
    }
}

void init(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef(0.0, 1.0, 0.0);
        glScalef(0.5,0.5,0.5);
        //glRotatef(0, 1, 0, 1);
        glPushMatrix();
            ///
            glTranslatef(1.0, 0.0, 0.0);
            glRotatef((GLfloat)shoulderR, 0.0, 0.0, 1.0);
            glTranslatef(1.0, 0.0, 0.0);
            glPushMatrix();
                glScalef(2.0, 0.4, 1.0);
                glColor3f(0, 0, 1);
                glutSolidCube(1.0);
                glColor3f(0, 0, 0);
                glutWireCube(1.0);
            glPopMatrix();
            ///
            glTranslatef(1.0, 0.0, 0.0);
            glRotatef((GLfloat)elbowR, 0.0, 0.0, 1.0);
            glTranslatef(1.0, 0.0, 0.0);
            glPushMatrix();
                glScalef(2.0, 0.4, 1.0);
                glColor3f(1, 1, 0);
                glutSolidCube(1.0);
                glColor3f(0, 0, 0);
                glutWireCube(1.0);
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-1.0, 1.0, 0.0);
    glRotatef((GLfloat)0, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
        glScalef(0.5,0.5,0.5);
        glScalef(2.0, 0.4, 1.0);
        glColor3f(1, 0, 0);
        glutSolidCube(1.0);
        glColor3f(0, 0, 0);
        glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-1.0, 1.0, 0.0);
        glScalef(0.5,0.5,0.5);
        glRotatef(-180, 0, 0, 1);
        glPushMatrix();
        ///
            glTranslatef(-1.0, 0.0, 0.0);
            glRotatef(-(GLfloat)shoulderL, 0.0, 0.0, 1.0);
            glTranslatef(1.0, 0.0, 0.0);
            glPushMatrix();
                glScalef(2.0, 0.4, 1.0);
                glColor3f(0, 1, 0);
                glutSolidCube(1.0);
                glColor3f(0, 0, 0);
                glutWireCube(1.0);
            glPopMatrix();
            ///
            glTranslatef(1.0, 0.0, 0.0);
            glRotatef(-(GLfloat)elbowL, 0.0, 0.0, 1.0);
            glTranslatef(1.0, 0.0, 0.0);
            glPushMatrix();
                glScalef(2.0, 0.4, 1.0);
                glColor3f(0, 0, 1);
                glutSolidCube(1.0);
                glColor3f(0, 0, 0);
                glutWireCube(1.0);
            glPopMatrix();
            ///
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(900, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL HW2 Robot Arms");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboardUp);
    glutMainLoop();
    return 0;
}
