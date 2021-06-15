#include "IStrategy.h"
#include "CarFactory.h"
#include "CarFactory.cpp"
#include "Plane.h"
#include "PlaneFactory.h"
#include "TrainFactory.h"
class Strategy5 : public IStrategy
{

	CarFactory carFactory;
	TrainFactory trainFactory;
	PlaneFactory planeFactory;
public:
	Track createTrack(int* path, int volume) override
	{
		Transport* car1 = carFactory.create();
		for (auto it = table.begin(); it != table.end(); it++)
		{
			if ((*it).first.find(points[path[0]]))
			{
				car1 = carFactory.create(tableCost[(*it).second * 3 + 2], matrixDist[path[0]][path[1]]);
			}
		}

		Transport* train1 = trainFactory.create();
		Transport* plane1 = planeFactory.create();
		for (auto it = table.begin(); it != table.end(); it++)
		{
			if ((*it).first.find(points[path[1]]) && points[path[1]].find("TS"))
			{
				train1 = trainFactory.create(tableCost[(*it).second * 3 + 1], matrixDist[path[1]][path[2]]);
			}
			if ((*it).first.find(points[path[1]]) && points[path[1]].find("AP"))
			{
				plane1 = planeFactory.create(tableCost[(*it).second * 3], matrixDist[path[1]][path[2]]);
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

		for (auto it = table.begin(); it != table.end(); it++)
		{
			if ((*it).first.find(points[path[3]]) && points[path[3]].find("AP"))
			{
				plane1 = planeFactory.create(tableCost[(*it).second * 3], matrixDist[path[3]][path[4]]);
			}
			if ((*it).first.find(points[path[3]]) && points[path[3]].find("TS"))
			{
				train1 = trainFactory.create(tableCost[(*it).second * 3 + 1], matrixDist[path[3]][path[4]]);
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

		Track track = Track((Car*)car1, (Car*)car2, (Car*)car3, (Train*)train1, (Plane*)plane1, volume);
		return track;

	}
};
