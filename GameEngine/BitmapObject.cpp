#include "BitmapObject.h"

void BitmapObject::draw(sf::RenderWindow& window)
{
	window.draw(this->sprite);
}