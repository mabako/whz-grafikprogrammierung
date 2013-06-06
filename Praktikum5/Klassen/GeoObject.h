#pragma once
#include "afx.h"

class CGeoObject :
	public CObject
{
public:
	CGeoObject(void);
	~CGeoObject(void);
	int getObjNr();
	virtual void Zeichnen() = 0;
	void LoescheGrafik();
	virtual void Schieben(CVektor v) = 0;
	virtual void Drehen(CPunkt basisPunkt, float winkel) = 0;

protected:
	int m_iObjNr;
};
