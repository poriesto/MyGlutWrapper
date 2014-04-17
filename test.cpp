#include "test.hpp"

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
		glTranslatef(0, 0, 0);
		gluQuadricDrawStyle (cylinder, GLU_LINE);
		gluCylinder(cylinder, baseRad, topRad, cyheight, slices, stacks);
    glPopMatrix ( );
    glFlush ( );
}

void Test::initGL(void)
{
	std::cout << "initGL" << std::endl;
	xRot = -45; yRot = 0; zTra = 0; nSca = 0.2; xTra = 0;
	obj = gluNewQuadric(); baseRad = 1.0; topRad = 1.0;
	slices = 25; stacks = 25;
	cyheight = 5;

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	glClearColor(0.0, 0.0, 0.0, 0.0);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glLoadIdentity();
	GLfloat ratio = (GLfloat)rect.h/rect.w;
	if(rect.w >= rect.h) glOrtho(-1.0/ratio, 1.0/ratio, -1.0, 1.0, -10.0, 1.0);
	else glOrtho(-1.0, 1.0, -1.0*ratio, 1.0*ratio, -10.0, 1.0);
	glViewport(0, 0, rect.w, rect.h);
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
			move(2);
			break;
		case 'a':
			move(3);
			break;
		case 'd':
			move(4);
			break;
		case 'w':
			move(1);
			break;
		case 'i':
			rotate(1);
			break;
		case 'k':
			rotate(2);
			break;
		case 'j':
			rotate(3);
			break;
		case 'l':
			rotate(4);
			break;
		case 't':
			scale(2);
			break;
		case 'y':
			scale(1);
			break;
	}
}

void Test::resize(int w, int h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	GLfloat ratio = (GLfloat)h/w;
	if(w >= h) glOrtho(-1.0/ratio, 1.0/ratio, -1.0, 1.0, -10.0, 1.0);
	else glOrtho(-1.0, 1.0, -1.0*ratio, 1.0*ratio, -10.0, 1.0);
	glViewport(0, 0, w, h);
	rect.w = w; rect.h = h;
}

void Test::rotate(int dir)
{
	switch(dir)
	{
		case 1:
			//up rotate
			xRot += 1.0;
			break;
		case 2:
			//down rotate;
			xRot -= 1.0f;
			break;
		case 3:
			//left
			zRot += 1.0;
			break;
		case 4:
			//right
			zRot -= 1.0;
			break;
	}
}

void Test::move(int dir)
{
	switch(dir)
	{
		case 1:
			yTra += 0.05;
			break;
		case 2:
			yTra -= 0.05;
			break;
		case 3:
			xTra -= 0.05;
			break;
		case 4:
			xTra += 0.05;
			break;
	}
}

void Test::scale(int scale)
{
	switch(scale)
	{
		case 1:
			nSca = nSca*1.1;
			break;
		case 2:
			nSca = nSca/1.1;
			break;
	}
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
