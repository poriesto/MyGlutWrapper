#include "GLWindow.hpp"

void GLWindow::resize(int w, int h)
{}

void GLWindow::initMainwnd(void)
{
	char *ar[] = {"-w", "GLUT_RGB", "GLUT_DEPTH"};
	glutInit(&argc,  ar);
	glutInitDisplayMode(mode);
	glutInitWindowSize(rect.w, rect.h);
	glutInitWindowPosition(initPosx, initPosy);

	main = glutCreateWindow(name.c_str());
	app = this;
	glutDisplayFunc(Render);
	glutKeyboardUpFunc(Keyboard);
}

void GLWindow::setname(std::string name)
{
	this->name = name;
}

void GLWindow::setinitPosition(int x, int y)
{
	initPosx = x; initPosy = y;
}

void GLWindow::setwidthheight(int w, int h)
{
	rect.w = w; rect.h = h;
}

void GLWindow::setwidthheight(Rect rect)
{
	this->rect = rect;
}

Rect GLWindow::getRect(void)
{
	return rect;
}
