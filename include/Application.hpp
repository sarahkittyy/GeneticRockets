#pragma once

#include <SFML/Graphics.hpp>

/**
 * @brief Main app class.
 * 
 */
class Application
{
public:
	/**
	 * @brief Init app components
	 * 
	 */
	Application();

	/**
	 * @brief Equivalent to main()
	 * 
	 * @return int The exit code of the program.
	 */
	int run();

private:
	/**
	 * @brief Window to draw to.
	 * 
	 */
	sf::RenderWindow mWindow;
};