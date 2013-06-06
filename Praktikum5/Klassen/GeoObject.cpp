#include "stdafx.h"

#ifdef GKS
extern CServer gs;
#endif

CGeoObject::CGeoObject() {
}

CGeoObject::~CGeoObject() {
}

int CGeoObject::getObjNr() {
	return m_iObjNr;
}

void CGeoObject::LoescheGrafik() {
#ifdef GKS
	gs.gdel_seg(m_iObjNr);
#else
	glDeleteLists(m_iObjNr, 1);
#endif
}
