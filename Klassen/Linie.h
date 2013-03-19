#pragma once


class CLinie :
	public CGeoObject
{
public:
	CLinie(int objektNummer, CPunkt anfang, CPunkt ende);
	CLinie(void);
	~CLinie(void);
	void Zeichnen();
	void Set(int objektnummer, CPunkt anfang, CPunkt ende);

private:
	CPunkt m_AP, m_EP;
};
