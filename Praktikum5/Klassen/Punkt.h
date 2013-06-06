#pragma once

class CVektor;

class CPunkt
{
public:
	CPunkt(void);
	~CPunkt(void);
	void set(float, float);
	float get_x();
	float get_y();

	void schieben(CVektor v);
	void drehen(CPunkt basisPunkt, float winkel);
	
private:
	float x, y;
};


	