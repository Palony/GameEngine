#pragma once
#include "Point2D.h"
#include <cmath>

/**
 * @brief Klasa reprezentuj�ca odcinek, dziedziczy po Point2D.
 */
class LineSegment : public Point2D
{
#define M_PI 3.14159265358979323846

    Point2D top; ///< G�rny punkt odcinka.
    Point2D bottom; ///< Dolny punkt odcinka.
    PrimitiveRenderer primitiveRenderer; ///< Obiekt do rysowania prymityw�w.

public:
    /**
     * @brief Ustawia g�rny punkt odcinka.
     * @param x Wsp�rz�dna X g�rnego punktu.
     * @param y Wsp�rz�dna Y g�rnego punktu.
     */
    void set_top(float x, float y);

    /**
     * @brief Ustawia dolny punkt odcinka.
     * @param x Wsp�rz�dna X dolnego punktu.
     * @param y Wsp�rz�dna Y dolnego punktu.
     */
    void set_bottom(float x, float y);

    /**
     * @brief Pobiera wsp�rz�dne g�rnego punktu odcinka.
     * @return Wektor sf::Vector2f zawieraj�cy wsp�rz�dne g�rnego punktu.
     */
    sf::Vector2f get_top();

    /**
     * @brief Pobiera wsp�rz�dne dolnego punktu odcinka.
     * @return Wektor sf::Vector2f zawieraj�cy wsp�rz�dne dolnego punktu.
     */
    sf::Vector2f get_bottom();

    /**
     * @brief Rysuje odcinek na podanym oknie renderowania.
     * @param window Referencja do okna SFML, na kt�rym odcinek zostanie narysowany.
     */
    void draw_line(sf::RenderWindow& window);

    /**
     * @brief Przesuwa odcinek o zadany wektor translacji.
     * @param tx Przesuni�cie wzd�u� osi X.
     * @param ty Przesuni�cie wzd�u� osi Y.
     */
    void translation(float tx, float ty);

    /**
     * @brief Obraca odcinek o zadany k�t wok� punktu (400, 300).
     * @param window Referencja do okna SFML, na kt�rym odcinek jest rysowany.
     * @param alfa K�t obrotu w stopniach.
     */
    void rotation00(sf::RenderWindow& window, float alfa);

    /**
     * @brief Obraca odcinek o zadany k�t wok� dowolnego punktu (x0, y0).
     * @param alfa K�t obrotu w stopniach.
     * @param x0 Wsp�rz�dna X �rodka obrotu.
     * @param y0 Wsp�rz�dna Y �rodka obrotu.
     */
    void rotationXY(float alfa, float x0, float y0);

    /**
     * @brief Skaluje odcinek wzgl�dem punktu (400, 300).
     * @param window Referencja do okna SFML, na kt�rym odcinek jest rysowany.
     * @param k Wsp�czynnik skalowania.
     */
    void scaling00(sf::RenderWindow& window, float k);

    /**
     * @brief Skaluje odcinek wzgl�dem dowolnego punktu (x0, y0).
     * @param window Referencja do okna SFML, na kt�rym odcinek jest rysowany.
     * @param k Wsp�czynnik skalowania.
     * @param x0 Wsp�rz�dna X �rodka skalowania.
     * @param y0 Wsp�rz�dna Y �rodka skalowania.
     */
    void scalingXY(sf::RenderWindow& window, float k, float x0, float y0);
};
