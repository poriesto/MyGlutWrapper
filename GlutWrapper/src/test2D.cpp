#include "test2D.h"

test2D::test2D(unsigned int mode)
{
    //ctor
    this->mode = mode;
}

test2D::~test2D()
{
    //dtor
}

void test2D::initGL(void)
{

}

void test2D::render(void)
{
}
/*
int main(void)
{
    test2D* test = new test2D(GLUT_RGBA | GLUT_DOUBLE);
    test->setname("Test2D");
    test->setinitPosition(10, 10);
    test->setwidthheight(640, 480);
    test->show();
    return 0;
}
*/
