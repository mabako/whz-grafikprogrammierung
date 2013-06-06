#include "stdafx.h"

#ifdef GKS
extern CServer gs;
#endif

CKreis::CKreis(void) {

}

CKreis::CKreis(int objektnummer, CPunkt mittelpunkt, float radius) {
	Set(objektnummer, mittelpunkt, radius);
}

CKreis::~CKreis() {
}

void CKreis::Zeichnen() {
#ifdef GKS
	gs.gcreate_seg(m_iObjNr);

	Gpoint_list kreis;
	// Mittelpunkt, Peripheriepunkt
	Gpoint punkte[2] = {{m_MP.get_x(), m_MP.get_y()}, {m_MP.get_x() + m_fRadius, m_MP.get_y()}};
	kreis.num_points = 2;
	kreis.points = punkte;
	gs.gx_circle(&kreis);

	gs.gclose_seg();
#else
	GLUquadricObj *kreis;
	kreis = gluNewQuadric();
	gluQuadricDrawStyle(kreis, GLU_SILHOUETTE);
	glNewList(m_iObjNr, GL_COMPILE);
		glPushMatrix();
			glTranslatef(m_MP.get_x(), m_MP.get_y(), 0);
			gluDisk(kreis, 0, m_fRadius, 100,1);
		glPopMatrix();   
	glEndList();	
#endif
}

void CKreis::Set(int objektnummer, CPunkt mittelpunkt, float radius) {
	m_iObjNr = objektnummer;
	m_MP = mittelpunkt;
	m_fRadius = radius;
}

void CKreis::Schieben(CVektor v) {
	m_MP.schieben(v);
}

void CKreis::Drehen(CPunkt basisPunkt, float winkel)
{
	m_MP.drehen(basisPunkt, winkel);
}

