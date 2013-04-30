#pragma once

class CVektor
{
public:
	CVektor();
	~CVektor();
	void set(float dx, float dy);
	void set(CPunkt a, CPunkt b);

	float get_dx();
	float get_dy();

	CVektor operator-();
private:
	float dx;
	float dy;
};
