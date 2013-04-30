#include "stdafx.h"

CVektor::CVektor()
{
	set(0, 0);
}

CVektor::~CVektor()
{
}

void CVektor::set(float dx, float dy)
{
	this->dx = dx;
	this->dy = dy;
}

float CVektor::get_dx() {
	return dx;
}

float CVektor::get_dy() {
	return dy;
}

CVektor CVektor::operator-() {
	CVektor v;
	v.set(-dx, -dy);
	return v;
}
