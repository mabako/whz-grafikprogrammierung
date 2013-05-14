#pragma once

class CGrafik 
{
private:
	float xmin;
	float xmax;
	float ymin;
	float ymax;

public:
	CGrafik(void);
	virtual ~CGrafik(void);
	virtual void Init();
	virtual void Draw();
	void GetModellRaum(float&, float&, float&, float&);
};
