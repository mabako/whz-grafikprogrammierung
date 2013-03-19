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

protected:
	int m_iObjNr;
};
