#pragma once
#include "DrawableObject.h"
#include "TransformableObject.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "GameObject.h"


class BitmapObject :public DrawableObject, TransformableObject
{
	sf::Sprite sprite;
	sf::RenderWindow window;
	void draw(sf::RenderWindow& window);
};