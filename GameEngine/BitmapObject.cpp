#include "BitmapObject.h"

/**
 * @brief Klasa reprezentuj�ca obiekt bitmapowy, kt�ry mo�e by� rysowany na ekranie.
 * Klasa bazowa, kt�rej celem jest zapewnienie podstawowej funkcji rysowania bitmapy
 * przy u�yciu sf::Sprite.
 */
void BitmapObject::draw(sf::RenderWindow& window)
{
    // Rysowanie sprite'a na oknie renderowania
    window.draw(this->sprite);
}
