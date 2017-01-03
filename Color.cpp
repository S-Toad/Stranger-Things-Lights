// 
// 
// 

#include "Color.h"

Color::Color(int r, int g, int b) {
	this->R = r;
	this->G = g;
	this->B = b;
}

Color::Color() {
  this->R = 0;
  this->G = 0;
  this->B = 0;
}

Color::~Color() { }
