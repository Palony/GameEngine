#pragma once
#include "DrawableObject.h"
#include "TransformableObject.h"
#include "PrimitiveRenderer.h"
#include "LineSegment.h"
#include <SFML/Graphics.hpp> 

/**
 * @brief Klasa reprezentuj�ca prostok�t, dziedzicz�ca po DrawableObject i TransformableObject.
 */
class Rectangle : public DrawableObject, TransformableObject
{
private:
    LineSegment side1; ///< Bok 1 prostok�ta
    LineSegment side2; ///< Bok 2 prostok�ta
    LineSegment side3; ///< Bok 3 prostok�ta
    LineSegment side4; ///< Bok 4 prostok�ta

    float w0_init, h0_init, w1_init, h1_init; ///< Wsp�rz�dne pocz�tkowe prostok�ta
    float w0, h0, w1, h1; ///< Aktualne wsp�rz�dne prostok�ta
    float rotationAngle = 0.0f; ///< Aktualny k�t obrotu prostok�ta
    sf::Color fillColor; ///< Kolor wype�nienia prostok�ta

public:
    /**
     * @brief Konstruktor klasy Rectangle.
     * @param w0 Pocz�tkowa wsp�rz�dna x lewego g�rnego rogu.
     * @param h0 Pocz�tkowa wsp�rz�dna y lewego g�rnego rogu.
     * @param w1 Pocz�tkowa wsp�rz�dna x prawego dolnego rogu.
     * @param h1 Pocz�tkowa wsp�rz�dna y prawego dolnego rogu.
     * @param color Kolor wype�nienia prostok�ta. Domy�lnie bia�y.
     */
    Rectangle(float w0, float h0, float w1, float h1, sf::Color color = sf::Color::White);

    /**
     * @brief Rysuje prostok�t w podanym oknie SFML.
     * @param window Okno, w kt�rym prostok�t zostanie narysowany.
     */
    void draw(sf::RenderWindow& window);

    /**
     * @brief Powoduje "opadanie" prostok�ta w d� o podan� warto�� przesuni�cia.
     * @param window Okno SFML, w kt�rym prostok�t jest rysowany.
     * @param ty Warto�� przesuni�cia w osi y.
     */
    void fall(sf::RenderWindow& window, float ty);

    /**
     * @brief Resetuje pozycj� prostok�ta do warto�ci pocz�tkowych.
     */
    void resetPosition();

    /**
     * @brief Aktualizuje bie��ce wsp�rz�dne prostok�ta na podstawie jego bok�w.
     */
    void updatePoints();

    /**
     * @brief Zwraca wsp�rz�dn� x lewego g�rnego rogu prostok�ta.
     * @return Wsp�rz�dna x lewego g�rnego rogu.
     */
    float getW0() const;

    /**
     * @brief Zwraca wsp�rz�dn� y lewego g�rnego rogu prostok�ta.
     * @return Wsp�rz�dna y lewego g�rnego rogu.
     */
    float getH0() const;

    /**
     * @brief Zwraca wsp�rz�dn� x prawego dolnego rogu prostok�ta.
     * @return Wsp�rz�dna x prawego dolnego rogu.
     */
    float getW1() const;

    /**
     * @brief Zwraca wsp�rz�dn� y prawego dolnego rogu prostok�ta.
     * @return Wsp�rz�dna y prawego dolnego rogu.
     */
    float getH1() const;
};
