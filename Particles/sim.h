#pragma once
#include "particle.h"
#include <vector>

const int SIMSIZE = 30;

class sim
{
public:
	sim(double x, double y);
	double xspawn, yspawn;
	std::vector<particle> particleVector;
	int simArr[SIMSIZE][SIMSIZE]{ 0 };

	void add_particle(int dir, int num);
	void displaysim();
	void update_particle_positions();
	void update_simArr();
	void clear_simArr();
	void clear_old_particles();
};

