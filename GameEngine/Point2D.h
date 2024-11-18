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
 * @brief Klasa reprezentuj�ca punkt w przestrzeni 2D, z podstawowymi operacjami transformacji i rysowania.
 */
class Point2D
{
private:
#define M_PI 3.14159265358979323846
    PrimitiveRenderer primitiveRenderer; ///< Obiekt do rysowania prymitywnych kszta�t�w.

protected:
    sf::Vector2f cords; ///< Wsp�rz�dne punktu.

public:
    /**
     * @brief Ustawia wsp�rz�dne punktu.
     * @param x Wsp�rz�dna X punktu.
     * @param y Wsp�rz�dna Y punktu.
     */
    virtual void setXY(float x, float y);

    /**
     * @brief Ustawia wsp�rz�dn� X punktu.
     * @param x Wsp�rz�dna X.
     */
    void setX(float x);

    /**
     * @brief Ustawia wsp�rz�dn� Y punktu.
     * @param y Wsp�rz�dna Y.
     */
    void setY(float y);

    /**
     * @brief Pobiera wsp�rz�dne punktu jako obiekt sf::Vector2f.
     * @return Wektor sf::Vector2f z wsp�rz�dnymi punktu.
     */
    virtual sf::Vector2f getXY();

    /**
     * @brief Pobiera wsp�rz�dn� X punktu.
     * @return Wsp�rz�dna X punktu.
     */
    virtual float getX();

    /**
     * @brief Pobiera wsp�rz�dn� Y punktu.
     * @return Wsp�rz�dna Y punktu.
     */
    virtual float getY();

    /**
     * @brief Rysuje punkt na podanym oknie renderowania.
     * @param window Referencja do okna SFML.
     */
    virtual void draw_point(sf::RenderWindow& window);

    /**
     * @brief Przesuwa punkt o zadane przesuni�cie i rysuje go na oknie.
     * @param window Referencja do okna SFML.
     * @param tx Przesuni�cie wzd�u� osi X.
     * @param ty Przesuni�cie wzd�u� osi Y.
     */
    virtual void translation(sf::RenderWindow& window, float tx, float ty);

    /**
     * @brief Obraca punkt o zadany k�t wok� punktu (400, 300) i rysuje go.
     * @param window Referencja do okna SFML.
     * @param alfa K�t obrotu w stopniach.
     */
    void rotation00(sf::RenderWindow& window, float alfa);

    /**
     * @brief Obraca punkt o zadany k�t wok� dowolnego punktu (x0, y0) i rysuje go.
     * @param window Referencja do okna SFML.
     * @param alfa K�t obrotu w stopniach.
     * @param x0 Wsp�rz�dna X �rodka obrotu.
     * @param y0 Wsp�rz�dna Y �rodka obrotu.
     */
    void rotationXY(sf::RenderWindow& window, float alfa, float x0, float y0);

    /**
     * @brief Skaluje punkt wzgl�dem punktu (400, 300) i rysuje go.
     * @param window Referencja do okna SFML.
     * @param k Wsp�czynnik skalowania.
     */
    void scaling00(sf::RenderWindow& window, float k);

    /**
     * @brief Skaluje punkt wzgl�dem dowolnego punktu (x0, y0) i rysuje go.
     * @param window Referencja do okna SFML.
     * @param k Wsp�czynnik skalowania.
     * @param x0 Wsp�rz�dna X �rodka skalowania.
     * @param y0 Wsp�rz�dna Y �rodka skalowania.
     */
    void scalingXY(sf::RenderWindow& window, float k, float x0, float y0);
};
