#include "GLWindow.hpp"
#include <GL/glu.h>
#include <GL/gl.h>
#include <iostream>

class Test : public GLWindow
{
public:
    Test(int subwindows, unsigned int mode)
    {
        this->subwindows = subwindows;
        this->mode = mode;
    }
    Test()
    {
        subwindows = 0;
        mode = GLUT_RGBA | GLUT_SINGLE;
    }
    ~Test(void) {}
private:
    GLfloat xRot, yRot, zRot;
    GLfloat xTra, yTra, zTra;
    GLfloat nSca;
    GLfloat baseRad, topRad, cyheight;
    GLint stacks, slices;

    void move(int dir);
    void rotate(int dir);
    void scale(int scale);
protected:
    inline void resize(int w, int h);
    inline void initGL(void);
    inline void createsubwindows(void) {}
    inline void render(void);
    inline void keyboard(unsigned char key, int x, int y);
    inline void mouse(unsigned int button, int state, int x, int y) {}
    inline void motion(int x, int y) {}
    inline void passmotion(int x, int y) {}
    inline void idlefunc(void) {}
};
