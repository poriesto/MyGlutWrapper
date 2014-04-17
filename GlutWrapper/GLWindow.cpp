#include "GLWindow.hpp"

void GLWindow::initMainwnd(void)
{
    char *ar[] = {"-w", "GLUT_RGB", "GLUT_DEPTH"};
    app = this;

    glutInit(&argc,  ar);
    glutInitDisplayMode(mode);
    glutInitWindowSize(rect.w, rect.h);
    glutInitWindowPosition(initPosx, initPosy);
    main = glutCreateWindow(name.c_str());
    glutDisplayFunc(Render);
    glutKeyboardFunc(Keyboard);
    glutVisibilityFunc(Visible);
    glutMouseFunc(Mice);
    glutMotionFunc(Motion);
    glutPassiveMotionFunc(PassiveMotion);
}
