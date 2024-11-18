#pragma once
#include "DrawableObject.h"
#include "TransformableObject.h"
#include "PrimitiveRenderer.h"
#include "LineSegment.h"
#include <SFML/Graphics.hpp>
#include <vector>

/**
 * @brief Klasa reprezentuj�ca tr�jk�t, kt�ry jest obiektem rysowanym i transformowalnym.
 *
 * Klasa umo�liwia rysowanie tr�jk�ta na ekranie, jego translacj�, rotacj� oraz resetowanie pozycji.
 * Tr�jk�t jest reprezentowany przez trzy boki (segmenty linii), kt�re s� obiektami klasy `LineSegment`.
 */
class Triangle : public DrawableObject, TransformableObject
{
private:
    LineSegment side1; ///< Pierwszy bok tr�jk�ta
    LineSegment side2; ///< Drugi bok tr�jk�ta
    LineSegment side3; ///< Trzeci bok tr�jk�ta

    float rotationAngle = 0.0f; ///< K�t obrotu tr�jk�ta w stopniach

    // Wsp�rz�dne pocz�tkowe wierzcho�k�w tr�jk�ta
    float x0_init, y0_init, x1_init, y1_init, x2_init, y2_init;

    // Wsp�rz�dne aktualne wierzcho�k�w tr�jk�ta
    float x0, y0, x1, y1, x2, y2;

    sf::Color fillColor; ///< Kolor wype�nienia tr�jk�ta

public:
    /**
     * @brief Konstruktor klasy Triangle.
     *
     * Inicjalizuje tr�jk�t z okre�lonymi wsp�rz�dnymi wierzcho�k�w oraz kolorem wype�nienia.
     * @param x0 Wsp�rz�dna X pierwszego wierzcho�ka.
     * @param y0 Wsp�rz�dna Y pierwszego wierzcho�ka.
     * @param x1 Wsp�rz�dna X drugiego wierzcho�ka.
     * @param y1 Wsp�rz�dna Y drugiego wierzcho�ka.
     * @param x2 Wsp�rz�dna X trzeciego wierzcho�ka.
     * @param y2 Wsp�rz�dna Y trzeciego wierzcho�ka.
     * @param color Kolor wype�nienia tr�jk�ta (domy�lnie bia�y).
     */
    Triangle(float x0, float y0, float x1, float y1, float x2, float y2, sf::Color color = sf::Color::White);

    // Gettery dla wsp�rz�dnych pocz�tkowych wierzcho�k�w tr�jk�ta
    /**
     * @brief Zwraca wsp�rz�dn� X pierwszego wierzcho�ka tr�jk�ta.
     * @return Wsp�rz�dna X pierwszego wierzcho�ka.
     */
    float getX0() const;

    /**
     * @brief Zwraca wsp�rz�dn� Y pierwszego wierzcho�ka tr�jk�ta.
     * @return Wsp�rz�dna Y pierwszego wierzcho�ka.
     */
    float getY0() const;

    /**
     * @brief Zwraca wsp�rz�dn� X drugiego wierzcho�ka tr�jk�ta.
     * @return Wsp�rz�dna X drugiego wierzcho�ka.
     */
    float getX1() const;

    /**
     * @brief Zwraca wsp�rz�dn� Y drugiego wierzcho�ka tr�jk�ta.
     * @return Wsp�rz�dna Y drugiego wierzcho�ka.
     */
    float getY1() const;

    /**
     * @brief Zwraca wsp�rz�dn� X trzeciego wierzcho�ka tr�jk�ta.
     * @return Wsp�rz�dna X trzeciego wierzcho�ka.
     */
    float getX2() const;

    /**
     * @brief Zwraca wsp�rz�dn� Y trzeciego wierzcho�ka tr�jk�ta.
     * @return Wsp�rz�dna Y trzeciego wierzcho�ka.
     */
    float getY2() const;

    /**
     * @brief Rysuje tr�jk�t na oknie renderowania.
     *
     * Rysuje tr�jk�t poprzez znalezienie prostok�ta otaczaj�cego tr�jk�t
     * i sprawdzanie, kt�re punkty w tym prostok�cie znajduj� si� wewn�trz tr�jk�ta.
     * Dodatkowo, opcjonalnie rysuje boki tr�jk�ta.
     * @param window Okno renderowania SFML, w kt�rym tr�jk�t zostanie narysowany.
     */
    void draw(sf::RenderWindow& window);

    /**
     * @brief Translacja tr�jk�ta w osi Y (przemieszczenie).
     *
     * Przesuwa tr�jk�t o zadan� warto�� w osi Y oraz obraca go wok� �rodka masy.
     * Je�li tr�jk�t przekroczy doln� kraw�d� ekranu, jego pozycja zostaje zresetowana.
     * @param window Okno renderowania SFML, w kt�rym tr�jk�t jest wy�wietlany.
     * @param ty Warto�� przesuni�cia w osi Y.
     */
    void fall(sf::RenderWindow& window, float ty);

    /**
     * @brief Resetuje pozycj� tr�jk�ta do jego pocz�tkowych wsp�rz�dnych.
     *
     * Przywraca tr�jk�t do pozycji zdefiniowanej przez pocz�tkowe wsp�rz�dne
     * wierzcho�k�w oraz resetuje k�t obrotu.
     */
    void resetPosition();

    /**
     * @brief Aktualizuje bie��ce wsp�rz�dne wierzcho�k�w na podstawie pozycji linii.
     *
     * Funkcja ta aktualizuje wsp�rz�dne wierzcho�k�w tr�jk�ta, odwo�uj�c si�
     * do po�o�enia jego bok�w (segment�w linii).
     */
    void updatePoints();
};
