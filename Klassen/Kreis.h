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

private:
	CPunkt m_MP;
	float m_fRadius;
};
