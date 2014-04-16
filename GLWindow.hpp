#include <GL/glut.h>
#include <string>

struct Rect
{
	int w, h;
};
class GLWindow;
static GLWindow *app;

class GLWindow
{
	protected:
		Rect rect;
		int subwindows, initPosx, initPosy, main, argc;
		unsigned int mode;
		std::string name;
		void initMainwnd(void);
		void resize(int w, int h);
		void updateGL(void) { glutPostRedisplay();};
		
		//this methods must be implimented]
		virtual void initGL(void){};
		virtual void createsubwindows(void){};
		virtual void render(void){};
		virtual void keyboard(unsigned char key, int x, int y){};
		virtual void mouse(int button, int state, int x, int y){};
		virtual void motion(void){};
		virtual void idlefunc(void){};
		
		//dont touch this methods
	private:
		static void Render(void){
			app->render();
		};
		/*static void Mice(int button, int state, int x, int y){app->mouse();};
		static void Idle() {app->idlefunc();};*/
		static void Keyboard(unsigned char key, int x, int y) {app->keyboard(key, x, y);};
		/*static void Motion(void) {app->motion();};
		static void Resise(int w, int h) {app->resize();};*/
	public:
		//seters
		void setname(std::string name);
		void setinitPosition(int x, int y);
		void setwidthheight(int w, int h);
		void setwidthheight(Rect rect);
		//geters
		std::string getName(void);
		Rect getRect(void);
		//show the window
		void show(void){
			initMainwnd();
			initGL();
			glutMainLoop();
		};
};
