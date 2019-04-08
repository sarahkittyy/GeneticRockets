#include "Rocket/Graphics.hpp"

namespace Rocket
{

Graphics::Graphics()
{
	//Init the rectangle.
	mRect.setFillColor(sf::Color::White);
	mRect.setSize({8, 50});
	mRect.setOrigin({mRect.getLocalBounds().width / 2.0f, mRect.getLocalBounds().height / 2.0f});
	mRect.setPosition({0, 700 - mRect.getGlobalBounds().height});
	mXV = mYV = 0;
}

void Graphics::update(Physics phys)
{
	//Update and then get the angle of the rocket.
	mRect.rotate(phys.getAngularVelocity());
	float angle = mRect.getRotation();

	//Get the x and y components of the velocity.
	float xa = phys.getAcceleration() * std::sin((angle)*M_PI / 180.f);
	float ya = phys.getAcceleration() * std::cos((angle)*M_PI / 180.f);

	mXV += xa / 60.f;
	mYV += ya / 60.f;
	//mYV += 9.8f / 60.f;

	//Move the rocket.
	mRect.move(-mXV, mYV);
}

sf::Vector2f Graphics::getPosition()
{
	return mRect.getPosition();
}

void Graphics::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mRect, states);
}

}