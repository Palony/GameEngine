#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>

class BitmapHandler
{
public:
	sf::Image image;
	sf::Image background;


	int  bitmapLoad(sf::RenderWindow& window);
	void bitmapDelete();
	void bitmapRead();
	void bitmapWrite();
	void bitmapCopy();
};

