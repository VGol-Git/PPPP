#pragma once
#include "Transport.h"

class  Car : public Transport
{
public:
	Car();
	Car(std::tuple<int, int, double>, int);
};
Car::Car()
{
	this->price = 100;
	this->speed = 60;
	this->volume = 50;
	this->distance = 0;
}