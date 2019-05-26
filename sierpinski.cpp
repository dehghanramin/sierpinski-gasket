#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

struct GLPoint
{
    GLint x, y;
};

void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 1280.0, 0.0, 960.0);
}

void drawDot(const GLPoint& point)
{
    glBegin(GL_POINTS);
        glVertex2i(point.x, point.y);
    glEnd();
}

void renderSierpinski(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    GLPoint T[3] = {{10, 10}, {640, 955}, {1280, 10}};

    int index = rand() % 3;
    GLPoint point = T[index];
    drawDot(point);
    for (size_t i = 0; i < 10000000; ++i)
    {
        index = rand() % 3;
        point.x = (point.x + T[index].x) / 2;
        point.y = (point.y + T[index].y) / 2;
        drawDot(point);
    }
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1280, 960);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Sierpinski Gasket");
    glutDisplayFunc(renderSierpinski);
    myInit();
    glutMainLoop();
}