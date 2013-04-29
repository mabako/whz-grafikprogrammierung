#pragma once
#include "opengl.h"

class myOpenGL :
	public COpenGL
{
public:
	myOpenGL(void);
	~myOpenGL(void);	

protected:
	void OnSizeGL(int cx, int cy);
	void OnDrawGL();
};
