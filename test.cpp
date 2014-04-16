#include "test.hpp"
#include <iostream>

void Test::render(void)
{
	std::cout << "Render" << std::endl;
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

void Test::initGL(void)
{
	std::cout << "Xyu" << std::endl;
	glClearColor(0.8, 1.0, 0.6, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-200.0,200.0, -200.0,200.0, -5.0,5.0);
}

int main(void)
{
	std::string name = "wnd";
	std::string argv = "GLUT_RGB -w GLUT_RGBA";
	unsigned int mode = GLUT_RGBA | GLUT_SINGLE;
	Test* tst = new Test(0, mode);

	tst->setname(name);
	tst->setinitPosition(10, 10);
	tst->setwidthheight(640, 480);
	tst->show();
	return 0;
}
