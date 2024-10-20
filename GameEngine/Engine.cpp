#include "Engine.h"


const bool Engine::running()
{
	return this->window->isOpen();
}

void Engine::initializeVariables()
{
}

void Engine::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->window = new sf::RenderWindow(this->videoMode, "okienko", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}

void Engine::update()
{
	handlingMouse();
	polEvents();
}

void Engine::handlingMouse()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		mousePos = sf::Mouse::getPosition(*window);
		std::cout << "Mouse X: " << mousePos.x << std::endl;
		std::cout << "Mouse Y: " << mousePos.y << std::endl;
	}
}

void Engine::polEvents()
{
	while (window->pollEvent(event))
	{
		if (event.type = sf::Event::Closed)
		{
			window->close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			std::cout << "A: " << std::endl;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			std::cout << "W: " << std::endl;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			std::cout << "S: " << std::endl;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			std::cout << "D: " << std::endl;
			std::cout << "Time: " << time1.asSeconds() << std::endl;
		}
	}
}

void Engine::time()
{
	time1 = clock.restart();

}