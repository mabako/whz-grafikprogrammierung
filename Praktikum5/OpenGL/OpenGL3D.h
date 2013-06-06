#pragma once
#include "opengl.h"

class COpenGL3D :
	public COpenGL
{
public:
	COpenGL3D(void);
	~COpenGL3D(void);
	
	void lookAt(const CPunkt3D&, const CPunkt3D&, const CVektor3D&);
	void ortho(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
	void frustum(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
	void perspective(GLfloat, GLfloat, GLfloat, GLfloat);
	
protected:
	bool m_bOrtho, m_bFrustum, m_bPerspective;
	GLfloat m_fleft, m_fright, m_fbottom, m_ftop, m_fnear, m_ffar;
	GLfloat m_fangle, m_faspect;
	CPunkt3D m_Pposition, m_Ptarget;
	CVektor3D m_VviewingUp;	
};
