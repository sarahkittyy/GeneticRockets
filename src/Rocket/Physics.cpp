#include "Rocket/Physics.hpp"

namespace Rocket
{

Physics::Physics()
{
	mYA = mAV = 0;
}

Physics::Physics(float ya, float av)
{
	mAV = av;
	mYA = ya;
}

void Physics::setAcceleration(float newVel)
{
	mYA = newVel;
}

float Physics::getAcceleration()
{
	return mYA;
}

void Physics::setAngularVelocity(float newVel)
{
	mAV = newVel;
}

float Physics::getAngularVelocity()
{
	return mAV;
}

}