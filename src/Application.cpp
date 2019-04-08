#include "Application.hpp"

Application::Application()
	: mWindow(sf::VideoMode(700, 700), "GeneticRockets")
{
	mWindow.setFramerateLimit(60);
	std::srand(std::time(NULL));
}

int Application::run()
{
	Genetics::Physics simul;


	//Main app loop.
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
		simul.update();

		//Clear the screen.
		mWindow.clear(sf::Color::Black);

		//Draw to the screen.
		mWindow.draw(simul);

		//Display the drawn items.
		mWindow.display();
	}

	return 0;
}