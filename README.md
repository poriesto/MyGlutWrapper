special class C++ for glut
Please dont touch GLWindow class only extend him
You must implement the following methods:
		virtual void initGL(void){};
		virtual void createsubwindows(void){};
		virtual void render(void){};
		virtual void keyboard(unsigned char key, int x, int y){};
		virtual void mouse(int button, int state, int x, int y){};
		virtual void motion(void){};
		virtual void idlefunc(void){};
Exmaple for use this class implemented in test.hpp and test.hpp;
