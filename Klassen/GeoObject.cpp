#include "stdafx.h"

extern CServer gs;

CGeoObject::CGeoObject() {
}

CGeoObject::~CGeoObject() {
}

int CGeoObject::getObjNr() {
	return m_iObjNr;
}

void CGeoObject::LoescheGrafik() {
	gs.gdel_seg(m_iObjNr);
}
