#include "Plane.h"

Plane::Plane(std::tuple<int, int, double> tuple, int dist) : Transport(tuple, dist) {}

Plane::Plane()
{
	this->price = 500;
	this->speed = 300;
	this->volume = 100;
	this->distance = 0;
}