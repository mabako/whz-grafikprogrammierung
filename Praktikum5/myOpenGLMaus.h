#pragma once
#include "OpenGL/openglMaus.h"

class myOpenGL :
	public COpenGLMaus
{
public:
	myOpenGL(void);
	~myOpenGL(void);	

protected:
	void OnSizeGL(int cx, int cy);
	void OnDrawGL();
};
