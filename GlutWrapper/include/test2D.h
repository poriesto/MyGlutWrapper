#ifndef TEST2D_H
#define TEST2D_H

#include "../GLWindow.hpp"
#include <GL/glu.h>
#include <GL/gl.h>
#include <iostream>


class test2D : public GLWindow
{
    public:
        test2D(unsigned int mode);
        virtual ~test2D();
    protected:
		void resize(int w, int h){}
		void initGL(void);
		void createsubwindows(void){}
		void render(void);
		void keyboard(unsigned char key, int x, int y){}
		void mouse(unsigned int button, int state, int x, int y){}
		void motion(int x, int y){}
		void passmotion(int x, int y){}
		void idlefunc(void){}
    private:
};

#endif // TEST2D_H
