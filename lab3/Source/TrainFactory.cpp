#include "TrainFactory.h"
#include "Train.h"

Transport* TrainFactory::create() {

	return new Train();
}

Transport* TrainFactory::create(std::tuple<int, int, double> tuple, int dist) {

	return new Train(tuple, dist);
}

