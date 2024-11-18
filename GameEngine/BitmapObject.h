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
 * @brief Klasa reprezentuj�ca obiekt bitmapowy, kt�ry mo�e by� rysowany i transformowany.
 * Klasa ta dziedziczy po klasach DrawableObject i TransformableObject, co pozwala na
 * rysowanie obiekt�w na ekranie oraz zastosowanie transformacji (np. przesuni�cia, skalowania, obrotu).
 * Jest to klasa bazowa dla obiekt�w, kt�re maj� graficzn� reprezentacj� i mog� by� rysowane
 * przy u�yciu sf::Sprite.
 */
class BitmapObject : public DrawableObject, TransformableObject
{
protected:
    sf::Sprite sprite; /**< Obiekt sf::Sprite, kt�ry przechowuje obrazek obiektu do wy�wietlenia. */
    sf::RenderWindow window; /**< Okno renderowania, w kt�rym obiekt jest rysowany. */

public:
    /**
     * @brief Konstruktor domy�lny klasy BitmapObject.
     * Inicjalizuje obiekt bez danych pocz�tkowych.
     */
    BitmapObject() {}

    /**
     * @brief Metoda rysuj�ca obiekt bitmapowy na przekazanym oknie.
     * U�ywa obiektu sf::Sprite do renderowania obrazu.
     * @param window Okno renderowania, na kt�rym obiekt bitmapowy ma zosta� narysowany.
     */
    virtual void draw(sf::RenderWindow& window);
};
