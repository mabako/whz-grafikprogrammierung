#include "StdAfx.h"
#include "opengl3d.h"

COpenGL3D::COpenGL3D(void)
{
	m_bFrustum = FALSE;
	m_bOrtho = TRUE;
	m_bPerspective = FALSE;
	m_Pposition.set(0,0,0);
	m_Ptarget.set(0,0,-1);
	m_VviewingUp.set(0,1,0);
	m_fleft = m_fbottom = m_fnear = -1;
	m_fright = m_ftop = m_ffar = 1;
	m_fangle = 30; m_faspect = 1;
	m_fbgRed = m_fbgGreen = m_fbgBlue = 0.3;
}

COpenGL3D::~COpenGL3D(void)
{
}



void COpenGL3D::lookAt(const CPunkt3D& position, const CPunkt3D& target, const CVektor3D& viewingUp)
{
	m_Pposition = position;
	m_Ptarget = target;
	m_VviewingUp = viewingUp;
}

void COpenGL3D::ortho(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat nah, GLfloat fern)
{
	m_bFrustum = FALSE;
	m_bOrtho = TRUE;
	m_bPerspective = FALSE;
	m_fleft = left; m_fright = right;
	m_fbottom = bottom; m_ftop = top;
	m_fnear = nah; m_ffar = fern;
}

void COpenGL3D::frustum(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat nah, GLfloat fern)
{
	m_bFrustum = TRUE;
	m_bOrtho = FALSE;
	m_bPerspective = FALSE;
	m_fleft = left; m_fright = right;
	m_fbottom = bottom; m_ftop = top;
	m_fnear = nah; m_ffar = fern;
}

void COpenGL3D::perspective(GLfloat angle, GLfloat aspect, GLfloat nah, GLfloat fern)
{
	m_bFrustum = FALSE;
	m_bOrtho = FALSE;
	m_bPerspective = TRUE;
	m_fangle = angle; m_faspect = aspect;
	m_fnear = nah; m_ffar = fern;
}

