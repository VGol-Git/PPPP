#pragma once
#include "Transport.h"

class  Plane : public Transport
{
public:
	Plane();
	Plane(std::tuple<int, int, double>, int);
};
