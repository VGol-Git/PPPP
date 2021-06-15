#pragma once
#include "ITransportFactory.h";

class CarFactory : public ITransportFactory
{
	// ������������ ����� ITransportFactory
public:
	Transport* create() override;
	Transport* create(std::tuple<int, int, double>, int dist) override;


};