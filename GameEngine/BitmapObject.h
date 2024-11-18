#pragma once
#include "DrawableObject.h"
#include "TransformableObject.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "GameObject.h"

/**
 * @brief Klasa reprezentuj¹ca obiekt bitmapowy, który mo¿e byæ rysowany i transformowany.
 * Klasa ta dziedziczy po klasach DrawableObject i TransformableObject, co pozwala na
 * rysowanie obiektów na ekranie oraz zastosowanie transformacji (np. przesuniêcia, skalowania, obrotu).
 * Jest to klasa bazowa dla obiektów, które maj¹ graficzn¹ reprezentacjê i mog¹ byæ rysowane
 * przy u¿yciu sf::Sprite.
 */
class BitmapObject : public DrawableObject, TransformableObject
{
protected:
    sf::Sprite sprite; /**< Obiekt sf::Sprite, który przechowuje obrazek obiektu do wyœwietlenia. */
    sf::RenderWindow window; /**< Okno renderowania, w którym obiekt jest rysowany. */

public:
    /**
     * @brief Konstruktor domyœlny klasy BitmapObject.
     * Inicjalizuje obiekt bez danych pocz¹tkowych.
     */
    BitmapObject() {}

    /**
     * @brief Metoda rysuj¹ca obiekt bitmapowy na przekazanym oknie.
     * U¿ywa obiektu sf::Sprite do renderowania obrazu.
     * @param window Okno renderowania, na którym obiekt bitmapowy ma zostaæ narysowany.
     */
    virtual void draw(sf::RenderWindow& window);
};
