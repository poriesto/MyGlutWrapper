#include "test.hpp"
#include <iostream>

void Test::render(void)
{
	std::cout << "Render" << std::endl;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
		for(int i = -rect.w/2; i<=rect.w/2;i+=20)
		{
			glVertex2f(i, -rect.w);
			glVertex2f(i, rect.w);
		}
		for(int i = -rect.h/2; i<=rect.h;i+=20)
		{
			glVertex2f(-rect.h, i);
			glVertex2f(rect.h, i);
		}
	glEnd();
	glFlush();
}

void Test::initGL(void)
{
	std::cout << "Xyu" << std::endl;
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-rect.w/2,rect.w/2, -rect.h/2,rect.h/2, -200.0, 200.0);
	glMatrixMode(GL_MODELVIEW);
	glTranslatef(50.0, -50.0, 0.0);
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
