#ifndef GRAVITY_H
#define GRAVITY_H

#include "body.h"

const float TIMESTEP = 0.01;
const double BIG_G = 1;

class Gravity
{
private:
	static void update_acceleration(void);
	static void update_position(void);
	static void update_velocity(void);
public:
	static void update(void);
};

#endif //GRAVITY_H

