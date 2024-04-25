#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <cmath>

class particle
{
public:
	time_t spawntime;

	double x_pos, y_pos;
	double x_speed, y_speed;

	particle(double xpos, double y_pos, int dir);
};

