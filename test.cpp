#include "test.hpp"
#include <iostream>

void Test::render(void)
{
	std::cout << "Render" << std::endl;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    glRotatef(yRot, 0.0f, 1.0f, 0.0f);
    glRotatef(zRot, 0.0f, 0.0f, 1.0f);
    glTranslatef(xTra, yTra, zTra);
    glScalef(nSca, nSca, nSca);

	GLUquadric *cylinder = gluNewQuadric();
    glPushMatrix ( );
		glTranslatef(0, 0, 1);
		gluQuadricDrawStyle (cylinder, GLU_LINE);
		gluCylinder(cylinder, baseRad, topRad, cyheight, slices, stacks);
    glPopMatrix ( );
    glFlush ( );
}

void Test::initGL(void)
{
	std::cout << "Xyu" << std::endl;
	xRot = -45; yRot = 0; zTra = 0; nSca = 0.2; xTra = 0;
	obj = gluNewQuadric(); baseRad = 1.0; topRad = 1.0;
	slices = 25; stacks = 25;
	cyheight = 20;

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	glClearColor(0.0, 0.0, 0.0, 0.0);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
}

void Test::keyboard(unsigned char key, int x, int y)
{
	std::cout << "Keyboard" << std::endl;
	switch(key)
	{
		case 'q':
			exit(0);
			break;
		case 's':
			move_back();
			break;
		case 'a':
			move_left();
			break;
		case 'd':
			move_right();
			break;
		case 'w':
			move_forward();
			break;
	}
	updateGL();
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
