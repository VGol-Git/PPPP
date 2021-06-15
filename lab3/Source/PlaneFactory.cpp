#include "PlaneFactory.h"
#include "Plane.h"

Transport* PlaneFactory::create() {

	return new Plane();
}

Transport* PlaneFactory::create(std::tuple<int, int, double> tuple, int dist) {

	return new Plane(tuple, dist);
}

