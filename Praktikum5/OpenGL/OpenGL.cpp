// OpenGL.cpp : Implementierungsdatei
//

#include "stdafx.h"
#include "OpenGL.h"

// COpenGL

IMPLEMENT_DYNCREATE(COpenGL, CFrameWnd)

COpenGL::COpenGL()
{
	m_fbgRed = 1; m_fbgGreen = 1; m_fbgBlue = 1;
	m_fxmin = -50;
	m_fxmax = 50;
	m_fymin = -50;
	m_fymax = 50;
	m_pGrafik = NULL;
}

COpenGL::~COpenGL()
{
	// Hier beendet das OpenGL-Objekt sein Leben
	// Aktuellen Render Context holen
	HGLRC hglrc = wglGetCurrentContext();
	// Aktuellen Render Context deaktivieren
	wglMakeCurrent(NULL, NULL);
	// Render Context endgültig löschen
	wglDeleteContext(hglrc);
}


BEGIN_MESSAGE_MAP(COpenGL, CFrameWnd)
	ON_WM_PAINT()
	ON_WM_SIZE()	
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// COpenGL-Meldungshandler

bool COpenGL::InitOpenGL(char* text, int x_left, int x_right, int y_top, int y_bottom)

{
// Initialisierung von OpenGL
// 1. OpenGL-Fenster als Typ "Child" definieren
	if (Create(
		NULL,
		(LPCTSTR)text,
		WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_SIZEBOX   ,
		CRect(x_left,y_top,x_right,y_bottom),
		NULL,
		NULL,
		NULL, 
		NULL))
	{ // Create war erfolgreich,
		// 2. Rendering-Context initialisieren
		if (!SetRenderingContext())   // RC-DC Verbindung setzen
			return false;   // Melde: Fehler -> Abbruch
		// 3. Fenster anzeigen
		ShowWindow(SW_SHOWNOACTIVATE);
		// 4. hier weitere Initialisierungen ...
		
		return TRUE;  // Melde: Alles gut gegangen
	}
	
	return false;  // Melde: Hier ist was schief gelaufen
}

bool COpenGL::SetRenderingContext(void)
{
// In dieser Funktion wird der Render-Kontext RC mit dem
// Device-Kontext DC des OpenGL-Fensters verbunden
	PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR),
			1,
			PFD_DRAW_TO_WINDOW
			| PFD_DRAW_TO_BITMAP
			| PFD_SUPPORT_OPENGL
			| PFD_DOUBLEBUFFER   ,
			PFD_TYPE_RGBA,
			32,
			0,0,0,0,0,0,
			0,0,
			0,0,0,0,0,
			16,
			0,
			0,
			0,
			0,
			0,
			0,
			0
	};
	m_pcdc = GetDC();   // Lokalen Zeiger auf eigenen DC
	HDC hdc = m_pcdc->m_hDC; // Lokalen Handle auf eigenen DC
	int iPixelFormat = ChoosePixelFormat(hdc, &pfd); // Pixelformat auswählen
	SetPixelFormat(    // Pixelformat setzen
		hdc,           // Handle auf DeviceContext
		iPixelFormat,  // Pixelformat mitteilen
		&pfd);         // Zeiger auf Struktur

	
	m_hglrc =      // Render Context für OGL erzeugen
		wglCreateContext(hdc);  // über DC-Handle
	if (m_hglrc == NULL) return false;  // Fehler -> Abbruch
	if (!wglMakeCurrent(  // akt. RC-DC Verbindung setzen
		m_pcdc->GetSafeHdc(), m_hglrc))  return false;  // Fehler -> Abbruch
	return true;  // Alles OK, keine Fehler!
}



void COpenGL::OnPaint()
{
	CFrameWnd::OnPaint();
	CRect rect; int cx,cy;
	
	// prepare a semaphore
	static BOOL 	bBusy = FALSE;
	// use the semaphore to enter this critic section
	if(bBusy) return;
	bBusy = TRUE;

	// specify the target DeviceContext of the subsequent OGL calls
	wglMakeCurrent(m_pcdc->GetSafeHdc(), m_hglrc);
	
	this->GetClientRect(rect);
	cx = rect.right - rect.left;
	cy = rect.bottom - rect.top;
	OnSizeGL(cx,cy);
	
	// call the virtual drawing procedure (to be overridden by user)
	
	OnDrawGL();
	SwapBuffers(wglGetCurrentDC());
	

	bBusy = FALSE;
	// free the target DeviceContext (window)
    //***************wglMakeCurrent(NULL,NULL);
		
	// CFrameWnd::OnPaint() soll zum Zeichnen von Meldungen nicht aufgerufen werden.
}

void COpenGL::OnSize(UINT nType, int cx, int cy)
{
	CFrameWnd::OnSize(nType, cx, cy);

	// TODO: Fügen Sie hier Ihren Meldungsbehandlungscode ein.
	OnSizeGL(cx, cy);
}

void COpenGL::OnSizeGL(int cx, int cy)
{
	// virtual
} 

void COpenGL::OnDrawGL()
{
	// virtual
} 

BOOL COpenGL::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Fügen Sie hier Ihren Meldungsbehandlungscode ein, und/oder benutzen Sie den Standard.
	return true;
	//return CFrameWnd::OnEraseBkgnd(pDC);
}

void COpenGL::setGrafik(CGrafik* grafik)
{  m_pGrafik = grafik;  }

void COpenGL::setWindow(GLfloat xmin, GLfloat xmax, GLfloat ymin, GLfloat ymax)
{
	m_fxmin = xmin;
	m_fxmax = xmax;
	m_fymin = ymin;
	m_fymax = ymax;
}

void COpenGL::getWindow(GLfloat* xmin, GLfloat* xmax, GLfloat* ymin, GLfloat* ymax)
{
	*xmin = m_fxmin;
	*xmax = m_fxmax;
	*ymin = m_fymin;
	*ymax = m_fymax;
}

void COpenGL::drawWindow()
{
	glLineWidth(5);
	glColor3f(1-m_fbgRed,1-m_fbgGreen,1-m_fbgBlue);
	glBegin(GL_LINE_LOOP);
		glVertex2f(m_fxmin,m_fymin);
		glVertex2f(m_fxmax,m_fymin);
		glVertex2f(m_fxmax,m_fymax);
		glVertex2f(m_fxmin,m_fymax);
	glEnd();
	glLineWidth(1);	
}

void COpenGL::fillWindow()
{
	glLineWidth(5);
	glColor3f(0.273,0.273,0.273);
	// 0.273 macht es unwahrscheinlich, dass die Hintergrundfarbe genau (0.5,0.5,0.5) ist.
	// In diesem Fall würde man das Gummiband nicht sehen!!!
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glBegin(GL_QUADS);
		glVertex2f(m_fxmin,m_fymin);
		glVertex2f(m_fxmax,m_fymin);
		glVertex2f(m_fxmax,m_fymax);
		glVertex2f(m_fxmin,m_fymax);
	glEnd();
	glLineWidth(1);	
}


GLfloat COpenGL::getRatio()
{
return (m_fxmax - m_fxmin) / (m_fymax - m_fymin);
	
}

void COpenGL::setBackGround(GLfloat bgRed, GLfloat bgGreen, GLfloat bgBlue)
{
	m_fbgRed   = bgRed;
	m_fbgGreen = bgGreen;
	m_fbgBlue  = bgBlue;
}

void COpenGL::shareContext(COpenGL& opengl)
{
	wglShareLists(m_hglrc,opengl.m_hglrc);
}
