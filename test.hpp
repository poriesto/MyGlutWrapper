#include "GLWindow.hpp"
#include <GL/glu.h>
#include <GL/gl.h>

class Test : public GLWindow
{
	public:
		Test(int subwindows, unsigned int mode)
		{
			this->subwindows = subwindows; this->mode = mode;
		};
		~Test(void){};
	private:
		GLfloat xRot, yRot, zRot;
    	GLfloat xTra, yTra, zTra;
    	GLfloat xSca, ySca, zSca, nSca;
		GLUquadricObj* obj;
		GLdouble baseRad, topRad, cyheight;
		GLint stacks, slices;

		void move_forward(void)
		{ yTra += 0.05; };
		void move_back(void)
		{ yTra -= 0.05; };
		void move_left(void)
		{ xTra -= 0.05; };
		void move_right(void)
		{ xTra += 0.05; };
	protected:
		void initGL(void);
		void createsubwindows(void){};
		void keyboard(unsigned char key, int x, int y);
		void mouse(unsigned int button, int state, int x, int y){};
		void render(void);
		void motion(void){};
		void idlefunc(void){};
};
