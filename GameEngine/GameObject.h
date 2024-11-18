#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <vector>
#include <iostream>

/**
 * @class GameObject
 * @brief Klasa bazowa reprezentuj�ca obiekt gry z podstawowymi operacjami na wsp�rz�dnych.
 *
 * Klasa ta przechowuje wsp�rz�dne obiektu i zapewnia metody do ich ustawiania oraz odczytu.
 */
class GameObject
{
    sf::Vector2f cords; ///< Wsp�rz�dne obiektu w przestrzeni 2D.

public:
    /**
     * @brief Ustawia wsp�rz�dne X i Y obiektu.
     * @param x Nowa warto�� wsp�rz�dnej X.
     * @param y Nowa warto�� wsp�rz�dnej Y.
     */
    virtual void setXY(float x, float y);

    /**
     * @brief Ustawia wsp�rz�dn� X obiektu.
     * @param x Nowa warto�� wsp�rz�dnej X.
     */
    virtual void setX(float x);

    /**
     * @brief Ustawia wsp�rz�dn� Y obiektu.
     * @param y Nowa warto�� wsp�rz�dnej Y.
     */
    virtual void setY(float y);

    /**
     * @brief Pobiera wsp�rz�dne obiektu.
     * @return Wsp�rz�dne obiektu jako sf::Vector2f.
     */
    virtual sf::Vector2f getXY();

    /**
     * @brief Pobiera wsp�rz�dn� X obiektu.
     * @return Warto�� wsp�rz�dnej X.
     */
    virtual float getX();

    /**
     * @brief Pobiera wsp�rz�dn� Y obiektu.
     * @return Warto�� wsp�rz�dnej Y.
     */
    virtual float getY();
};
