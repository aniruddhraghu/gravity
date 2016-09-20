#ifndef BODY_H
#define BODY_H

#include <cstdlib>
#include <iostream>
#include "vector2d.h"
#include <vector>

using namespace std;

extern int planet_number;


class Body
{
private:
	const int key;
	double mass;
public:
	Body(); //default constructor
	Body(double mass, vector2d pos, vector2d vel);
	inline int get_key(void) { return key; }
	inline double get_mass(void) { return mass; };
	vector2d position;
	vector2d velocity;
	vector2d old_acceleration;
	vector2d acceleration;
};


extern vector <Body*> Bodies;

#endif //BODY_H
