#pragma once
#include "Transport.h"
#include <tuple>

//Used Factory Method

 
 __interface ITransportFactory
{
public:
	virtual Transport* create() = 0;
	virtual Transport* create(std::tuple<int, int, double>, int dist) = 0;
};

