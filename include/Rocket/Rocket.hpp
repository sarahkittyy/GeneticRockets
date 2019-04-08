#pragma once

#include "Rocket/Graphics.hpp"
#include "Rocket/Physics.hpp"

namespace Rocket
{

struct Rocket
{
	Physics phys;
	Graphics graphics;

	void update();
};

}