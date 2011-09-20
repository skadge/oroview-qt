#include <QtGui>
#include <QtOpenGL>

#include <math.h>

#include "glwidget.h"
#include "src/oroview/oroview.h"

#ifndef GL_MULTISAMPLE
#define GL_MULTISAMPLE  0x809D
#endif

using namespace std;

//! [0]
GLWidget::GLWidget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{

    oroview = NULL;
}
//! [0]

//! [1]
GLWidget::~GLWidget()
{
}
//! [1]

//! [2]
QSize GLWidget::minimumSizeHint() const
{
    return QSize(50, 50);
}
//! [2]

//! [3]
QSize GLWidget::sizeHint() const
//! [3] //! [4]
{
    return QSize(400, 400);
}
//! [4]

static void qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360 * 16)
        angle -= 360 * 16;
}

/*
void GLWidget::setXRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != xRot) {
        xRot = angle;
        emit xRotationChanged(angle);
        updateGL();
    }
}
*/

//! [6]
void GLWidget::initializeGL()
{
    vec3f background = vec3f(0.1, 0.1, 0.1);

    //qglClearColor(qtPurple.dark());

    try {
        oroview = new OroView();

        oroview->setBackground(background);

    } catch(ResourceException& exception) {
        throw OroViewException(string("failed to load resource ") + exception.what());
    }

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_MULTISAMPLE);
    static GLfloat lightPosition[4] = { 0.5, 5.0, 7.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}

//! [6]

//! [7]
void GLWidget::paintGL()
{
    //oroview->update();
    //oroview->logic();
    //oroview->draw();
}


void GLWidget::resizeGL(int width, int height)
{
    int side = qMin(width, height);
    glViewport((width - side) / 2, (height - side) / 2, side, side);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
#ifdef QT_OPENGL_ES_1
    glOrthof(-0.5, +0.5, -0.5, +0.5, 4.0, 15.0);
#else
    glOrtho(-0.5, +0.5, -0.5, +0.5, 4.0, 15.0);
#endif
    glMatrixMode(GL_MODELVIEW);
}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
    //lastPos = event->pos();
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    //int dx = event->x() - lastPos.x();
    //int dy = event->y() - lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
        //setXRotation(xRot + 8 * dy);
        //setYRotation(yRot + 8 * dx);
    } else if (event->buttons() & Qt::RightButton) {
        //setXRotation(xRot + 8 * dy);
        //setZRotation(zRot + 8 * dx);
    }
    //lastPos = event->pos();
}

