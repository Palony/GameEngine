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
 * @brief Klasa bazowa reprezentuj¹ca obiekt gry z podstawowymi operacjami na wspó³rzêdnych.
 *
 * Klasa ta przechowuje wspó³rzêdne obiektu i zapewnia metody do ich ustawiania oraz odczytu.
 */
class GameObject
{
    sf::Vector2f cords; ///< Wspó³rzêdne obiektu w przestrzeni 2D.

public:
    /**
     * @brief Ustawia wspó³rzêdne X i Y obiektu.
     * @param x Nowa wartoœæ wspó³rzêdnej X.
     * @param y Nowa wartoœæ wspó³rzêdnej Y.
     */
    virtual void setXY(float x, float y);

    /**
     * @brief Ustawia wspó³rzêdn¹ X obiektu.
     * @param x Nowa wartoœæ wspó³rzêdnej X.
     */
    virtual void setX(float x);

    /**
     * @brief Ustawia wspó³rzêdn¹ Y obiektu.
     * @param y Nowa wartoœæ wspó³rzêdnej Y.
     */
    virtual void setY(float y);

    /**
     * @brief Pobiera wspó³rzêdne obiektu.
     * @return Wspó³rzêdne obiektu jako sf::Vector2f.
     */
    virtual sf::Vector2f getXY();

    /**
     * @brief Pobiera wspó³rzêdn¹ X obiektu.
     * @return Wartoœæ wspó³rzêdnej X.
     */
    virtual float getX();

    /**
     * @brief Pobiera wspó³rzêdn¹ Y obiektu.
     * @return Wartoœæ wspó³rzêdnej Y.
     */
    virtual float getY();
};
