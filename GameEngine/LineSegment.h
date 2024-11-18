#pragma once
#include "Point2D.h"
#include <cmath>

/**
 * @brief Klasa reprezentuj¹ca odcinek, dziedziczy po Point2D.
 */
class LineSegment : public Point2D
{
#define M_PI 3.14159265358979323846

    Point2D top; ///< Górny punkt odcinka.
    Point2D bottom; ///< Dolny punkt odcinka.
    PrimitiveRenderer primitiveRenderer; ///< Obiekt do rysowania prymitywów.

public:
    /**
     * @brief Ustawia górny punkt odcinka.
     * @param x Wspó³rzêdna X górnego punktu.
     * @param y Wspó³rzêdna Y górnego punktu.
     */
    void set_top(float x, float y);

    /**
     * @brief Ustawia dolny punkt odcinka.
     * @param x Wspó³rzêdna X dolnego punktu.
     * @param y Wspó³rzêdna Y dolnego punktu.
     */
    void set_bottom(float x, float y);

    /**
     * @brief Pobiera wspó³rzêdne górnego punktu odcinka.
     * @return Wektor sf::Vector2f zawieraj¹cy wspó³rzêdne górnego punktu.
     */
    sf::Vector2f get_top();

    /**
     * @brief Pobiera wspó³rzêdne dolnego punktu odcinka.
     * @return Wektor sf::Vector2f zawieraj¹cy wspó³rzêdne dolnego punktu.
     */
    sf::Vector2f get_bottom();

    /**
     * @brief Rysuje odcinek na podanym oknie renderowania.
     * @param window Referencja do okna SFML, na którym odcinek zostanie narysowany.
     */
    void draw_line(sf::RenderWindow& window);

    /**
     * @brief Przesuwa odcinek o zadany wektor translacji.
     * @param tx Przesuniêcie wzd³u¿ osi X.
     * @param ty Przesuniêcie wzd³u¿ osi Y.
     */
    void translation(float tx, float ty);

    /**
     * @brief Obraca odcinek o zadany k¹t wokó³ punktu (400, 300).
     * @param window Referencja do okna SFML, na którym odcinek jest rysowany.
     * @param alfa K¹t obrotu w stopniach.
     */
    void rotation00(sf::RenderWindow& window, float alfa);

    /**
     * @brief Obraca odcinek o zadany k¹t wokó³ dowolnego punktu (x0, y0).
     * @param alfa K¹t obrotu w stopniach.
     * @param x0 Wspó³rzêdna X œrodka obrotu.
     * @param y0 Wspó³rzêdna Y œrodka obrotu.
     */
    void rotationXY(float alfa, float x0, float y0);

    /**
     * @brief Skaluje odcinek wzglêdem punktu (400, 300).
     * @param window Referencja do okna SFML, na którym odcinek jest rysowany.
     * @param k Wspó³czynnik skalowania.
     */
    void scaling00(sf::RenderWindow& window, float k);

    /**
     * @brief Skaluje odcinek wzglêdem dowolnego punktu (x0, y0).
     * @param window Referencja do okna SFML, na którym odcinek jest rysowany.
     * @param k Wspó³czynnik skalowania.
     * @param x0 Wspó³rzêdna X œrodka skalowania.
     * @param y0 Wspó³rzêdna Y œrodka skalowania.
     */
    void scalingXY(sf::RenderWindow& window, float k, float x0, float y0);
};
