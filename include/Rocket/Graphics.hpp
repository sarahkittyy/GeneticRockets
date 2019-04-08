#pragma once

#include <SFML/Graphics.hpp>

#include <cmath>

#include "Rocket/Physics.hpp"

namespace Rocket
{

/**
 * @brief Renders a rocket, updated per-frame with 
 * a y velocity & an angular velocity.
 * 
 */
class Graphics : public sf::Drawable
{
public:
	Graphics();

	void update(Physics phys);

	sf::Vector2f getPosition();

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::RectangleShape mRect;

	float mXV, mYV;
};

}