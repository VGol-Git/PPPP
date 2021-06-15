#pragma once
#include "IStrategy.h"
#include "CarFactory.h"
#include "CarFactory.cpp"
#include "Plane.h"
#include "PlaneFactory.h"
#include "TrainFactory.h"
class Strategy7: public IStrategy
{
	CarFactory carFactory;
	TrainFactory trainFactory;
	PlaneFactory planeFactory;
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

		Transport* train1 = trainFactory.create();
		for (auto it = table.begin(); it != table.end(); it++)
		{
			if ((*it).first.find(points[path[1]]))
			{
				train1 = trainFactory.create(tableCost[(*it).second * 3 + 1], matrixDist[path[1]][path[2]]);
			}
		}

		Transport* car2 = carFactory.create();
		for (auto it = table.begin(); it != table.end(); it++)
		{
			if ((*it).first.find(points[path[2]]))
			{
				car2 = carFactory.create(tableCost[(*it).second * 3 + 2], matrixDist[path[2]][path[3]]);
			}
		}

		Transport* plane1 = planeFactory.create();
		for (auto it = table.begin(); it != table.end(); it++)
		{
			if ((*it).first.find(points[path[3]]))
			{
				plane1 = planeFactory.create(tableCost[(*it).second * 3], matrixDist[path[3]][path[4]]);
			}
		}

		Transport* car3 = carFactory.create();
		for (auto it = table.begin(); it != table.end(); it++)
		{
			if ((*it).first.find(points[path[4]]))
			{
				car3 = carFactory.create(tableCost[(*it).second * 3 + 2], matrixDist[path[4]][path[5]]);
			}
		}

		Transport* train2 = trainFactory.create();
		for (auto it = table.begin(); it != table.end(); it++)
		{
			if ((*it).first.find(points[path[5]]))
			{
				train2 = trainFactory.create(tableCost[(*it).second * 3 + 1], matrixDist[path[5]][path[6]]);
			}
		}

		Transport* car4 = carFactory.create();
		for (auto it = table.begin(); it != table.end(); it++)
		{
			if ((*it).first.find(points[path[6]]))
			{
				car4 = carFactory.create(tableCost[(*it).second * 3 + 2], matrixDist[path[6]][path[7]]);
			}
		}

		Track track = Track((Car*)car1, (Car*)car2, (Car*)car3, (Car*)car4, (Train*)train1, (Train*)train2, (Plane*)plane1, volume);
		return track;
	}
};
