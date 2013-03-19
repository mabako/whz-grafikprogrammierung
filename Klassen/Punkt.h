#pragma once

class CPunkt
{
public:
	CPunkt(void);
	~CPunkt(void);
	void set(float, float);
	float get_x();
	float get_y();
	
private:
	float x, y;
};


	