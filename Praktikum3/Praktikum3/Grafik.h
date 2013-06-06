#pragma once

class CGrafik 
{
private:

public:
	float m_fDx;
	float m_fDy;

	CGrafik(void);
	virtual ~CGrafik(void);
	virtual void Init();
	virtual void Draw();
};
