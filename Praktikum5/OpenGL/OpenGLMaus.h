#pragma once
#include "opengl.h"

#define WM_PICK (WM_USER+1)
#define WM_LOC  (WM_USER+2)
#define WM_VEK (WM_USER+3)
#define WM_SAMPLE (WM_USER+4)
#define WM_EINGABE (WM_USER+5)

extern CDialog* ex_pDlg; 


class COpenGLMaus :	public COpenGL
{
public:
	COpenGLMaus(void);
	~COpenGLMaus(void);
	bool InitOpenGL(char*, int, int, int, int);
	void setMausStatus(int status);
	void setMausStatus(int status, CPunkt bp, int echo);
	void setMausStatus(int status, float density);
	int getMausStatus();
	CPunkt getLoc();
	CVektor getMove();
	GLuint getPick();
	void getWorldCoord2D(CPoint ip, CPunkt* wp);

private:
	CPunkt p_temp1, p_temp2;
	CPunkt m_PBasis;
	GLuint i_temp;
	GLuint m_iMausStatus;
	GLuint m_iEchoStatus;
	//GLint first;
	// Steuerung Gummiband
	CPunkt m_PRA, m_PRE;
	// Sample-Auflösung
	GLfloat m_fSampleDensity;
	// Übergabeparameter
	GLuint m_idiaPick;
	CPunkt m_PdiaLoc;
	CVektor m_VdiaMove;
	CPunkt m_PdiaSample;

	void drawRubberband();


	
public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
};

