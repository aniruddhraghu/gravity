#include <cstdlib>
#include <iostream>
#include <vector>
#include "vector2d.h"
#include "body.h"
#include "gravity.h"

const double DEFAULT_MASS = 100.0;
using namespace std;

//define vector of bodies here for the first time

vector<Body*> Bodies;

int planet_number = 0;

//Body member functions

Body::Body() : key((planet_number)++)
{
	mass = DEFAULT_MASS;
	//just empty defaults for now...
	position = velocity = acceleration = old_acceleration = vector2d(0, 0);
}

Body::Body(double m, vector2d pos, vector2d vel) :
	key((planet_number)++)
{
	mass = m;
	position = pos;
	velocity = vel;
	//acceleration = old_acceleration = vector2d(1, 1);
}