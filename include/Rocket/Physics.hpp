#pragma once

namespace Rocket
{

/**
 * @brief Stores a rocket's physics state.
 * This includes y & angular velocities.
 * 
 */
class Physics
{
public:
	Physics();
	Physics(float ya, float av);

	void setAcceleration(float newAccel);
	float getAcceleration();

	void setAngularVelocity(float newVel);
	float getAngularVelocity();

private:
	float mAV;
	float mYA;
};

}