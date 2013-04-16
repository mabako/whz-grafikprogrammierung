#pragma once


class CKreis :
	public CGeoObject
{
public:
	CKreis(int objektNummer, CPunkt mittelpunkt, float radius);
	CKreis(void);
	~CKreis(void);
	void Zeichnen();
	void Set(int objektnummer, CPunkt mittelpunkt, float radius);
	void Schieben(CVektor v);
	void Drehen(CPunkt basisPunkt, float winkel);

private:
	CPunkt m_MP;
	float m_fRadius;
};
