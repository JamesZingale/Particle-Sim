#include "particle.h"


particle::particle(double xpos, double ypos, int dir)
{
	spawntime = time(nullptr); // set spawn time

	this->x_pos = xpos;
	this->y_pos = ypos;

	//seed random number generation
	std::random_device rd;
	std::default_random_engine gen(rd());
	//create normal distribution object
	std::normal_distribution<double> NormDis(0, 1.2);

	// move to bottom as else if (dir == -1) // random dir
	switch (dir)
	{
	case 1: // up
		this->x_speed = NormDis(gen);
		this->y_speed = std::abs(NormDis(gen));
		break;
	case 2: // right
		this->x_speed = std::abs(NormDis(gen));
		this->y_speed = NormDis(gen);
		break;
	case 3: //down
		this->x_speed = NormDis(gen);
		this->y_speed = 0 - std::abs(NormDis(gen));
	case 4: //left
		this->x_speed = 0 - std::abs(NormDis(gen));
		this->y_speed = NormDis(gen);
	default:
		this->x_speed = NormDis(gen);
		this->y_speed = NormDis(gen);
		break;
	}
}

