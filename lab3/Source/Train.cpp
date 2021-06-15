#include "Train.h"

Train::Train(std::tuple<int, int, double> tuple, int dist) : Transport(tuple, dist) {}

Train::Train()
{
	this->price = 200;
	this->speed = 100;
	this->volume = 500;
	this->distance = 0;

}