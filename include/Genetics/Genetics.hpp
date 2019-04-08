#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>
#include <numeric>

#include "Rocket/Rocket.hpp"

namespace Genetics
{

/**
 * @brief Runs genetic iteration algorithm
 * on rocket physics.
 * 
 */
class Physics : public sf::Drawable
{
public:
	Physics();

	void reset();

	void update();

	void iter();

	float dist();

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	Rocket::Rocket copyRocket(Rocket::Rocket& r);

	Rocket::Rocket mutateRocket(Rocket::Rocket& r);

	std::vector<Rocket::Rocket> mRockets;

	sf::Vector2f target_pos;

	sf::Clock mClock;

	void updateDist();

	float lastAverageDistance = 0;
};

}