#include <conio.h>
#include <Windows.h>
#include "sim.h"

int main()
{
	bool procede = 1;
	sim simOBJ(15, 30);
	while (procede)
	{
		simOBJ.clear_old_particles();
		simOBJ.add_particle(3, 50);
		simOBJ.update_particle_positions();
		simOBJ.update_simArr();
		simOBJ.displaysim();
		simOBJ.clear_simArr();
		Sleep(100);
		system("cls");
		Sleep(100);
		
		if (_kbhit())
		{
			procede = 0;
		}

	}
}


