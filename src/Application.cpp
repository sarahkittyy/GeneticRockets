#include "Application.hpp"

Application::Application()
	: mWindow(sf::VideoMode(700, 700), "GeneticRockets")
{
}

int Application::run()
{
	while (mWindow.isOpen())
	{
		//Poll events.
		sf::Event event;
		while (mWindow.pollEvent(event))
		{
			switch (event.type)
			{
			default:
				break;
			case sf::Event::Closed:
				mWindow.close();
				break;
			}
		}

		//Clear the screen.
		mWindow.clear(sf::Color::Black);

		//Draw to the screen.

		//Display the drawn items.
		mWindow.display();
	}

	return 0;
}