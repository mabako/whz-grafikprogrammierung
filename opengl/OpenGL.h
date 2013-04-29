
#pragma once

// COpenGL-Rahmen

class COpenGL : public CFrameWnd
{
// Dieser Teil ist "Black Box"
	DECLARE_DYNCREATE(COpenGL)
public:
	COpenGL();           // Dynamische Erstellung verwendet geschützten Konstruktor
	virtual ~COpenGL();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
protected:
	DECLARE_MESSAGE_MAP()
	CDC* m_pcdc;
	HGLRC m_hglrc;
	bool SetRenderingContext(void);

// Dieser Teil wird vom Programmierer aktiv verwendet
public:
	bool InitOpenGL(char*, int x_left, int x_right, int y_top, int y_bottom);
	void setGrafik(CGrafik*);
	void setWindow(GLfloat x_min, GLfloat x_max, GLfloat y_min, GLfloat y_max);
	void getWindow(GLfloat* x_min, GLfloat* x_max, GLfloat* y_min, GLfloat* y_max);
	void drawWindow();
	void fillWindow();
	GLfloat getRatio();
	void setBackGround(GLfloat, GLfloat, GLfloat);
	void shareContext(COpenGL& opengl);
	// Zum Überschreiben in myOpenGL
	virtual void OnSizeGL(int cx, int cy);
	virtual void OnDrawGL();

protected:	
	GLfloat m_fbgRed, m_fbgGreen, m_fbgBlue; // Hintergrundfarbe
	GLfloat m_fxmin, m_fxmax, m_fymin, m_fymax;  // Windowgrenzen
	CGrafik* m_pGrafik; // Zeiger auf die Grafik
};


