#pragma once
#include "IStrategy.h"
#include "CarFactory.h"
#include "CarFactory.cpp"
#include "Plane.h"
#include "PlaneFactory.h"
#include "TrainFactory.h"
class Strategy1 : public IStrategy
{
	CarFactory carFactory;
public:
	Track createTrack(int* path, int volume) override {
		Transport* car1 = carFactory.create();
		for (auto it = table.begin(); it != table.end(); it++)
		{
			if ((*it).first.find(points[path[0]]))
			{
				car1 = carFactory.create(tableCost[(*it).second * 3 + 2], matrixDist[path[0]][path[1]]);
			}
		}
		Track track = Track((Car*)car1, volume);
		return track;
	}
};


