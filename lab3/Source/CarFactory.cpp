#include "CarFactory.h";
#include "Car.h";



Transport* CarFactory::create() {

	return new Car();
}

Transport* CarFactory::create(std::tuple<int, int, double> tuple, int dist) {

	return new Car(tuple, dist);
}

