#pragma once
#include "ITransportFactory.h";


class PlaneFactory : public ITransportFactory
{
public:
	Transport* create() override;
	Transport* create(std::tuple<int, int, double>, int dist) override;


};
