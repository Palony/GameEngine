#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include "PrimitiveRenderer.h"
#include <cmath>

/**
 * @class Point2D
 * @brief Klasa reprezentuj¹ca punkt w przestrzeni 2D, z podstawowymi operacjami transformacji i rysowania.
 */
class Point2D
{
private:
#define M_PI 3.14159265358979323846
    PrimitiveRenderer primitiveRenderer; ///< Obiekt do rysowania prymitywnych kszta³tów.

protected:
    sf::Vector2f cords; ///< Wspó³rzêdne punktu.

public:
    /**
     * @brief Ustawia wspó³rzêdne punktu.
     * @param x Wspó³rzêdna X punktu.
     * @param y Wspó³rzêdna Y punktu.
     */
    virtual void setXY(float x, float y);

    /**
     * @brief Ustawia wspó³rzêdn¹ X punktu.
     * @param x Wspó³rzêdna X.
     */
    void setX(float x);

    /**
     * @brief Ustawia wspó³rzêdn¹ Y punktu.
     * @param y Wspó³rzêdna Y.
     */
    void setY(float y);

    /**
     * @brief Pobiera wspó³rzêdne punktu jako obiekt sf::Vector2f.
     * @return Wektor sf::Vector2f z wspó³rzêdnymi punktu.
     */
    virtual sf::Vector2f getXY();

    /**
     * @brief Pobiera wspó³rzêdn¹ X punktu.
     * @return Wspó³rzêdna X punktu.
     */
    virtual float getX();

    /**
     * @brief Pobiera wspó³rzêdn¹ Y punktu.
     * @return Wspó³rzêdna Y punktu.
     */
    virtual float getY();

    /**
     * @brief Rysuje punkt na podanym oknie renderowania.
     * @param window Referencja do okna SFML.
     */
    virtual void draw_point(sf::RenderWindow& window);

    /**
     * @brief Przesuwa punkt o zadane przesuniêcie i rysuje go na oknie.
     * @param window Referencja do okna SFML.
     * @param tx Przesuniêcie wzd³u¿ osi X.
     * @param ty Przesuniêcie wzd³u¿ osi Y.
     */
    virtual void translation(sf::RenderWindow& window, float tx, float ty);

    /**
     * @brief Obraca punkt o zadany k¹t wokó³ punktu (400, 300) i rysuje go.
     * @param window Referencja do okna SFML.
     * @param alfa K¹t obrotu w stopniach.
     */
    void rotation00(sf::RenderWindow& window, float alfa);

    /**
     * @brief Obraca punkt o zadany k¹t wokó³ dowolnego punktu (x0, y0) i rysuje go.
     * @param window Referencja do okna SFML.
     * @param alfa K¹t obrotu w stopniach.
     * @param x0 Wspó³rzêdna X œrodka obrotu.
     * @param y0 Wspó³rzêdna Y œrodka obrotu.
     */
    void rotationXY(sf::RenderWindow& window, float alfa, float x0, float y0);

    /**
     * @brief Skaluje punkt wzglêdem punktu (400, 300) i rysuje go.
     * @param window Referencja do okna SFML.
     * @param k Wspó³czynnik skalowania.
     */
    void scaling00(sf::RenderWindow& window, float k);

    /**
     * @brief Skaluje punkt wzglêdem dowolnego punktu (x0, y0) i rysuje go.
     * @param window Referencja do okna SFML.
     * @param k Wspó³czynnik skalowania.
     * @param x0 Wspó³rzêdna X œrodka skalowania.
     * @param y0 Wspó³rzêdna Y œrodka skalowania.
     */
    void scalingXY(sf::RenderWindow& window, float k, float x0, float y0);
};
