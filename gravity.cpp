#include <cstdlib>
#include <iostream>
#include "body.h"
#include "gravity.h"

using namespace std;


//finds a(t+dt)
void Gravity::update_acceleration(void)
{
	for (vector<Body*>::iterator m = Bodies.begin(); m != Bodies.end(); ++m)
	{
		//Find the key of the body that we are to update
		int key = (*m)->get_key();

		vector2d temp_accel;

		//Calculate the force exerted on this (*m) by all the others.
		for (vector<Body*>::iterator it = Bodies.begin(); it != Bodies.end(); ++it)
		{
			//cout << "key is " << ((*it)->get_key()) << endl;
			if (((*it)->get_key()) == key)
			{	//we don't calculate the self-gravitational force.
				continue;
			}
			else
			{
				//construct the acceleration vector for this pair of bodies.
				vector2d pos_diff = (*it)->position - (*m)->position;
				vector2d normalized = pos_diff.norm();
				double magnitude = pos_diff.abs2();
				if (magnitude == 0)
				{
					cout << "problem- same position vector" << endl;
					system("PAUSE");
				}
				//temp_accel needed to calculate the next velocity.
				temp_accel += ((*it)->get_mass() * BIG_G * 1/magnitude * normalized);
			}
		}
		//store the old acceleration as we will need it to calculate the new velocity.
		(*m)->old_acceleration = (*m)->acceleration;

		//store the new acceleration we just calculated.
		(*m)->acceleration = temp_accel;
	}
}

//finds x(t+dt)
void Gravity::update_position(void)
{
	//code to find the position: x(t+dt) = x(t) + v(t)dt + 1/2 a(t) * dt^2. Store this 
	for (vector<Body*>::iterator m = Bodies.begin(); m != Bodies.end(); ++m)
	{
		(*m)->position += (*m)->velocity * TIMESTEP +
			0.5 * (*m)->acceleration * TIMESTEP * TIMESTEP;
	}
}

void Gravity::update_velocity(void)
{
	//code to find the new velocity. 
	//Needs to call update_acceleration to find the acceleration at t+dt
	//use this to calculate velocity:
	// v(t+dt) = v(t) + 1/2 * dt * (a(t) + a(t+dt))
	for (vector<Body*>::iterator m = Bodies.begin(); m != Bodies.end(); ++m)
	{
		(*m)->velocity += 0.5 * TIMESTEP *
			((*m)->acceleration + (*m)->old_acceleration);
	}
}

void Gravity::update(void)
{
	//(*m)->position has  x(t)
	//(*m)->velocity has  v(t)
	//(*m)->acceleration has a(t)

	update_position();
	update_acceleration();
	update_velocity();
}


