special class C++ for glut
Please dont touch GLWindow class only extend him
You must implement the following methods
		virtual void resize(int w, int h) = 0;
		virtual void initGL(void){};
		virtual void createsubwindows(void) = 0;
		virtual void render(void){};
		virtual void keyboard(unsigned char key, int x, int y){};
		virtual void mouse(int button, int state, int x, int y){};
		virtual void motion(int x, int y) = 0;
		virtual void passmotion(int x, int y) = 0;
		virtual void idlefunc(void) = 0;
In main class in any situation dont touch all private methods. This special methods needs for 
abuse C - like pointers for class methods.
Exmaple for use this class implemented in test.hpp and test.hpp;
