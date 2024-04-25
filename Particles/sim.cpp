#include "sim.h"


sim::sim(double x, double y)
{
	this->xspawn = x;
	this->yspawn = y;
	particleVector.reserve(1000);
}
void sim::displaysim()
{
	for (int i = 0; i < SIMSIZE; i++)
	{
		for (int j = 0; j < SIMSIZE; j++)
		{
			switch (simArr[i][j])
			{
			case 0:
				std::cout << ' ';
					break;
			case 1:
			case 2:
			case 3:
				std::cout << '.';
				break;
			case 4:
			case 5:
				std::cout << ':';
				break;
			case 6:
			case 7:
				std::cout << '>';
			case 8:
			case 9:
				std::cout << '*';
					break;
			case 10:
			default:
				std::cout << '#';
				break;
			}
		}
		std::cout << '\n';
	}
}
void sim::add_particle(int dir, int num)
{
	for (int i = 0; i < num; i++)
	{
		particleVector.push_back(particle(xspawn, yspawn, dir));
	}
}
void sim::update_particle_positions()
{
	for (auto iter = particleVector.begin(); iter != particleVector.end(); iter++)
	{
		double tempX = iter->x_pos + iter->x_speed;
		double tempY = iter->y_pos + iter->y_speed;
		if (tempX <= SIMSIZE && tempX >= 0 && tempY <= SIMSIZE && tempY >= 0)
		{
			iter->x_pos = tempX;
			iter->y_pos = tempY;
		}
	}
}
void sim::clear_old_particles()
{
	auto currentTime = time(nullptr);
	for (auto iter = particleVector.begin(); iter != particleVector.end();)
	{
		if (difftime(time(nullptr), iter->spawntime) > 1)
		{
			iter = particleVector.erase(iter);
		}
		else {
			++iter;
		}
	}
}

void sim::update_simArr()
{
	for (auto iter = particleVector.begin(); iter != particleVector.end(); iter++)
	{
		int yIndex = std::floor(iter->y_pos);
		int xIndex = std::floor(iter->x_pos);
		simArr[yIndex][xIndex]++;
	}

}
void sim::clear_simArr()
{
	for (int i = 0; i < SIMSIZE; i++)
	{
		for (int j = 0; j < SIMSIZE; j++)
		{
			simArr[i][j] = 0;
		}
	}
}