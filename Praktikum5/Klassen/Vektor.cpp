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

void CVektor::set(CPunkt a, CPunkt b)
{
	dx = b.get_x() - a.get_x();
	dy = b.get_y() - a.get_y();
}

float CVektor::get_dx() {
	return dx;
}

float CVektor::get_dy() {
	return dy;
}

float CVektor::get_Laenge() {
	return sqrt(dx*dx + dy*dy);
}

CVektor CVektor::operator-() {
	CVektor v;
	v.set(-dx, -dy);
	return v;
}
