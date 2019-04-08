#include "Genetics/Genetics.hpp"

namespace Genetics
{

Physics::Physics()
{
	target_pos = {700, 0};
	reset();
}

void Physics::reset()
{
	mRockets.clear();
	for (int i = 0; i < 100; ++i)
	{
		mRockets.push_back(Rocket::Rocket());

		float yv			 = -(std::rand() % 1000 / 500.0f);
		float av			 = (std::rand() % 1000 / 5000.f);
		mRockets.back().phys = Rocket::Physics(yv, av);
	}

	mClock.restart();
}

float Physics::dist()
{
	return lastAverageDistance;
}

void Physics::update()
{
	for (auto& rocket : mRockets)
	{
		rocket.update();
	}
	if (mClock.getElapsedTime() > sf::seconds(5))
	{
		updateDist();
		std::cout << "Distance: " << dist() << std::endl;
		iter();
		mClock.restart();
	}
}

void Physics::updateDist()
{
	sf::Vector2f target = target_pos;
	auto dist			= [target](Rocket::Rocket& r1) -> float {
		  return std::hypot(
			  std::abs(r1.graphics.getPosition().x - target.x),
			  std::abs(r1.graphics.getPosition().y - target.y));
	};

	lastAverageDistance = 0;
	for (auto& rocket : mRockets)
	{
		lastAverageDistance += dist(rocket);
	}
	lastAverageDistance /= mRockets.size();
}

void Physics::iter()
{
	sf::Vector2f target = target_pos;

	auto dist = [target](Rocket::Rocket& r1) -> float {
		return std::hypot(
			std::abs(r1.graphics.getPosition().x - target.x),
			std::abs(r1.graphics.getPosition().y - target.y));
	};

	std::sort(mRockets.begin(), mRockets.end(), [&dist](Rocket::Rocket& r1, Rocket::Rocket& r2) -> bool {
		return dist(r1) < dist(r2);
	});

	for (int i = 50; i < 100; ++i)
	{
		mRockets[i] = copyRocket(mRockets[i - 50]);
	}
	for (int i = 0; i < 50; ++i)
	{
		mRockets[i] = mutateRocket(mRockets[i]);
	}
}

Rocket::Rocket Physics::copyRocket(Rocket::Rocket& r)
{
	Rocket::Rocket n;
	n.phys = r.phys;
	return n;
}

Rocket::Rocket Physics::mutateRocket(Rocket::Rocket& r)
{
	Rocket::Rocket n;
	float yv = (std::rand() % 100000 / 50000.0f) - 1.0f;
	float av = (std::rand() % 100000 / 500000.f) - 0.1f;
	n.phys   = Rocket::Physics(-(yv - r.phys.getAcceleration()),
							   av + r.phys.getAngularVelocity());
	return n;
}

void Physics::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto& rocket : mRockets)
	{
		target.draw(rocket.graphics, states);
	}
}

}