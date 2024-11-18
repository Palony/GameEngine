#include "BitmapObject.h"

/**
 * @brief Klasa reprezentuj¹ca obiekt bitmapowy, który mo¿e byæ rysowany na ekranie.
 * Klasa bazowa, której celem jest zapewnienie podstawowej funkcji rysowania bitmapy
 * przy u¿yciu sf::Sprite.
 */
void BitmapObject::draw(sf::RenderWindow& window)
{
    // Rysowanie sprite'a na oknie renderowania
    window.draw(this->sprite);
}
