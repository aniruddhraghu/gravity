#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include "gravity.h"
#include "body.h"
#include <cstdlib>

using namespace std;

void grav()
{
	//Read in data for the different objects
	cout << "Enter number of bodies" << endl;
	int number_of_bodies;
	cin >> number_of_bodies;
	cout << "For each body enter mass, initial x/y pos, and initial x/y vel" << endl;
	for (int i = 0; i < number_of_bodies; ++i)
	{
		cout << "body num " << i << endl;
		double mass, xpos, ypos, xvel, yvel;
		cin >> xpos >> ypos >> xvel >> yvel >> mass;
		Bodies.push_back(new Body(mass, vector2d(xpos, ypos), vector2d(xvel, yvel)));
	}
	double time = 0;
	while (time < 10)
	{
		time += TIMESTEP;
		Gravity::update();
		//get the positions for the deviation check
		vector2d posA = Bodies[0]->position;
		vector2d posB = Bodies[1]->position;
		vector2d posC = Bodies[2]->position;
		double deviation = ((posC - posA) * (posB - posA))
			/ (((posC - posA).abs())*((posB - posA).abs()));
		if ((1 - fabs(deviation)) < (1 - cos(0.01)))
			cout << "Bodies are aligned at time " << time << endl;
	}
}


int main(int argc, char* argv[])
{
    grav();
	return 0;
}


