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
