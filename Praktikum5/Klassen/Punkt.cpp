#include "stdafx.h"

CPunkt::CPunkt() {
}

CPunkt::~CPunkt() {
}

void CPunkt::set(float x, float y) {
	this->x = x;
	this->y = y;
}

float CPunkt::get_x() {
	return x;
}

float CPunkt::get_y() {
	return y;
}

void CPunkt::schieben(CVektor v) {
	// Für die Prüfung hier Matrizenmultiplikation
	x += v.get_dx();
	y += v.get_dy();
}

void CPunkt::drehen(CPunkt basisPunkt, float winkel)
{
	// Verschieben
	//x = x1 + cosq * (basisPunkt.get_x() - x1) - sinq * (y - y1)
	//y = y1 + sinq * (basisPunkt.get_x() - x1) + cosq * (y - y1)

	//schieben(-v);
	//schieben(v);
}
