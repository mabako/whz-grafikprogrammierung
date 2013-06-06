#include "StdAfx.h"
#include "openglmaus.h"

CDialog* ex_pDlg; 

COpenGLMaus::COpenGLMaus(void)
{
}

COpenGLMaus::~COpenGLMaus(void)
{
}

// COpenGL-Meldungshandler

bool COpenGLMaus::InitOpenGL(char* text, int x0, int y0, int cx, int cy)
{
	if (COpenGL::InitOpenGL(text, x0, y0, cx, cy))
	{
		m_idiaPick = 0;
		m_iEchoStatus = 0;
		m_iMausStatus = 0;
		m_PdiaLoc.set(0,0);
		m_VdiaMove.set(0,0);
		p_temp1.set(0,0);
		p_temp2.set(0,0);
		m_PRA = p_temp1;  //Re*  Sonst kommt am Anfang bei "Linie" oder Kreis"
		m_PRE = p_temp2;  //Re*  ein diagonales Gummiband
		glEnable(GL_COLOR_LOGIC_OP);
		return true;  // Melde: Alles gut gegangen
	}
	else
		return false;  // Melde: Hier ist was schief gelaufen
}

void COpenGLMaus::setMausStatus(int typ)
{
	m_iMausStatus = typ; m_PBasis.set(0,0); m_iEchoStatus = ECHO_NONE;
	if (m_iMausStatus == PICK) m_idiaPick = 0;
}

void COpenGLMaus::setMausStatus(int typ, CPunkt bp, int echo)
{ m_iMausStatus = typ; m_PBasis = bp; m_iEchoStatus = echo;}

void COpenGLMaus::setMausStatus(int typ, float density)
{ m_iMausStatus = typ; m_fSampleDensity = density; }

int COpenGLMaus::getMausStatus()
{ return m_iMausStatus; }

BEGIN_MESSAGE_MAP(COpenGLMaus, COpenGL)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	ON_WM_MBUTTONDOWN()
	ON_WM_MBUTTONUP()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

void COpenGLMaus::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Fügen Sie hier Ihren Meldungsbehandlungscode ein, und/oder benutzen Sie den Standard.
	const GLuint SIZE = 100;
	glColor3f(1,1,1);	

	switch(m_iMausStatus)
	{
	case LOC:
		getWorldCoord2D( point, &p_temp1);
		break;
	case MOVE:
		getWorldCoord2D( point, &p_temp1);
		//first = 0;
		break;
	case PICK:
		GLfloat x0, x1, y0, y1;
		GLuint selectBuf[SIZE];
		GLint hits;
		GLint viewport[4];
		GLint x,y;
		x = point.x; y = point.y;
		glGetIntegerv (GL_VIEWPORT, viewport);
		glSelectBuffer (SIZE, selectBuf);
		glRenderMode(GL_SELECT);
		glInitNames();
		glPushName(0);
		glMatrixMode (GL_PROJECTION);
		glPushMatrix ();
		glLoadIdentity ();
		// create 5x5 pixel picking region near cursor location
		CRect rect;
		GetClientRect(rect);
		gluPickMatrix ((GLdouble) x, (GLdouble) (rect.bottom - y),
			5.0, 5.0, viewport);
		getWindow(&x0, &x1, &y0, &y1);
		gluOrtho2D (x0, x1, y0, y1);
		m_pGrafik->drawObjects(GL_SELECT);
		glMatrixMode (GL_PROJECTION);
		glPopMatrix();

		hits = glRenderMode (GL_RENDER);
		// Nummer bereitstellen
		i_temp = 0;
		m_idiaPick = 0;
		if (hits > 0)
		{
			GLuint *ptr;
			ptr = (GLuint *) selectBuf;
			ptr+=3;
			i_temp = *ptr;
		}
	}
	COpenGL::OnLButtonDown(nFlags, point);
}

void COpenGLMaus::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Fügen Sie hier Ihren Meldungsbehandlungscode ein, und/oder benutzen Sie den Standard.
	getWorldCoord2D( point, &p_temp2);

	switch(m_iMausStatus)
	{
	case LOC:
		m_PdiaLoc.set(p_temp1.get_x(),p_temp1.get_y());
		m_iMausStatus = NONE;
		m_iEchoStatus = NONE;
		m_PRA.set(0,0);
		m_PRE.set(0,0);
		ex_pDlg->SendMessage(WM_LOC,(WPARAM)this);
		break;
	case MOVE:
		m_PdiaLoc.set(p_temp1.get_x(),p_temp1.get_y());
		m_VdiaMove.set(p_temp1, p_temp2);
		m_iMausStatus = NONE;
		m_iEchoStatus = NONE;
        m_PRA = m_PRE;
		ex_pDlg->SendMessage(WM_VEK,(WPARAM)this);
		break;
	case PICK:
		if (i_temp != 0)
		{
			m_idiaPick = i_temp;
			m_iMausStatus = NONE;
			m_iEchoStatus = NONE;
			ex_pDlg->SendMessage(WM_PICK,(WPARAM)this);
		}
		break;
	}
	COpenGL::OnLButtonUp(nFlags, point);
	Invalidate();  //Re*
}

void COpenGLMaus::OnMouseMove(UINT nFlags, CPoint point)
{
	CVektor vek;
	//Kreuz also Cursor setzen?
	if (m_iMausStatus != NONE)
	{
		HCURSOR hCursor = NULL;
		HCURSOR hPrevCursor = NULL;
		hCursor = AfxGetApp()->LoadStandardCursor(IDC_CROSS);
		hPrevCursor = SetCursor(hCursor);
	}

	if (m_iEchoStatus != ECHO_NONE && m_iMausStatus == LOC
		&& !(nFlags & MK_LBUTTON) // Nur, wenn Button NICHT gedrückt
		)
	{
		getWorldCoord2D( point, &p_temp2);
		m_PRA = m_PBasis;
		m_PRE = p_temp2;
	}

	if (m_iEchoStatus == ECHO_NONE && m_iMausStatus == SAMPLE
		&& !(nFlags & MK_LBUTTON) // Nur, wenn Button NICHT gedrückt
		)
	{
		getWorldCoord2D( point, &p_temp2);
		vek.set(m_PdiaLoc, p_temp2);
		if (vek.get_Laenge() > this->m_fSampleDensity)
		{
			m_PdiaLoc = p_temp2;
			ex_pDlg->SendMessage(WM_SAMPLE);
		}
	}

	if (nFlags & MK_LBUTTON)  // Button gedrückt?
	{
		switch (m_iMausStatus)
		{	
			case MOVE:
			{
				getWorldCoord2D( point, &p_temp2);
				m_PRA = p_temp1;
				m_PRE = p_temp2;
				break;
			}
		}
	}
	COpenGL::OnMouseMove(nFlags, point);
	Invalidate();
}

void COpenGLMaus::getWorldCoord2D(CPoint ip, CPunkt* wp)
{
	CRect rect;
	GLdouble wx, wy, wz;
	GLint viewport[4];
	GLdouble mvmatrix[16], projmatrix[16];
	GLint realy;  /*  OpenGL y-Koordinate  */
	glGetIntegerv (GL_VIEWPORT, viewport);
	glGetDoublev (GL_MODELVIEW_MATRIX, mvmatrix);
	glGetDoublev (GL_PROJECTION_MATRIX, projmatrix);
	/*viewport[3] ist Hoehe in Fensterkoordinaten */
	//realy = viewport[3] - (GLint) ip.y - 1;
	this->GetClientRect(rect);
	realy = rect.bottom - (GLint) ip.y - 1;
	gluUnProject ((GLdouble) ip.x, (GLdouble) realy, 0.0, 
		mvmatrix, projmatrix, viewport, &wx, &wy, &wz);
	wp->set((float)wx, (float)wy);
}

CPunkt COpenGLMaus::getLoc()
{ 
	return m_PdiaLoc; 
}

CVektor COpenGLMaus::getMove()
{ 
	return m_VdiaMove; 
}

GLuint COpenGLMaus::getPick()
{ 
	return m_idiaPick; 
}


void COpenGLMaus::OnRButtonDown(UINT nFlags, CPoint point)
{
	m_iMausStatus = NONE;
	m_iEchoStatus = ECHO_NONE;
	COpenGL::OnRButtonDown(nFlags, point);
}
void COpenGLMaus::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Fügen Sie hier Ihren Meldungsbehandlungscode ein, und/oder benutzen Sie den Standard.
	Invalidate();  //Re*
	COpenGL::OnRButtonUp(nFlags, point);
}

void COpenGLMaus::OnMButtonDown(UINT nFlags, CPoint point)
{
	m_iMausStatus = NONE;
	m_iEchoStatus = ECHO_NONE;
	COpenGL::OnMButtonDown(nFlags, point);
}

void COpenGLMaus::OnMButtonUp(UINT nFlags, CPoint point)
{
	ex_pDlg->SendMessage(WM_EINGABE);
	COpenGL::OnMButtonUp(nFlags, point);
	Invalidate();
}

void COpenGLMaus::OnPaint()
{
	CFrameWnd::OnPaint();
	CRect rect; int cx,cy;
	// TODO: Fügen Sie hier Ihren Meldungsbehandlungscode ein.
	// OGL-Szene berechnen und zur Darstellung bringen

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

	OnDrawGL();
	// draw Rubberband
	drawRubberband();
	//
	glFinish();
	
	SwapBuffers(wglGetCurrentDC());
    //Invalidate();  //Re* Ohne Kommentar ist Objektinfo wieder "weg"
	bBusy = FALSE;
}

void COpenGLMaus::drawRubberband()
{

	switch (m_iMausStatus)
	{
        case MOVE:
    		glLogicOp(GL_XOR);
	    	glColor3f(1,1,1);
		    glBegin(GL_LINES);
		    glVertex2f(m_PRA.get_x(), m_PRA.get_y());
		    glVertex2f(m_PRE.get_x(), m_PRE.get_y());
    		glEnd();
	    	glLogicOp(GL_COPY);
        break;
	} 
	switch (m_iEchoStatus)
	{
	case ECHO_RUBBER_BAND:
		glLogicOp(GL_XOR);
		glColor3f(1,1,1);
		glBegin(GL_LINES);
		glVertex2f(m_PRA.get_x(), m_PRA.get_y());
		glVertex2f(m_PRE.get_x(), m_PRE.get_y());
		glEnd();
		glLogicOp(GL_COPY);
		break;
	case ECHO_RECT:
		glLogicOp(GL_XOR);
		glColor3f(1,1,1);
		glBegin(GL_LINE_LOOP);
		glVertex2f(m_PRA.get_x(), m_PRA.get_y());
		glVertex2f(m_PRE.get_x(), m_PRA.get_y());
		glVertex2f(m_PRE.get_x(), m_PRE.get_y());
		glVertex2f(m_PRA.get_x(), m_PRE.get_y());
		glEnd();
		glLogicOp(GL_COPY);
		break;
	}
}

