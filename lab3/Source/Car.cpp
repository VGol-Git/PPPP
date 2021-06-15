#include "Car.h"

Car::Car(std::tuple<int, int, double> tuple, int dist) : Transport(tuple, dist) {}

Car::Car()
{
	this->price = 100;
	this->speed = 60;
	this->volume = 50;
	this->distance = 0;
}