#include "LineSegment.h"

/**
 * @brief Ustawia g�rny punkt odcinka.
 * @param x Wsp�rz�dna X punktu.
 * @param y Wsp�rz�dna Y punktu.
 */
void LineSegment::set_top(float x, float y)
{
    top.setXY(x, y);
}

/**
 * @brief Ustawia dolny punkt odcinka.
 * @param x Wsp�rz�dna X punktu.
 * @param y Wsp�rz�dna Y punktu.
 */
void LineSegment::set_bottom(float x, float y)
{
    bottom.setXY(x, y);
}

/**
 * @brief Pobiera g�rny punkt odcinka.
 * @return Wsp�rz�dne g�rnego punktu jako sf::Vector2f.
 */
sf::Vector2f LineSegment::get_top()
{
    return top.getXY();
}

/**
 * @brief Pobiera dolny punkt odcinka.
 * @return Wsp�rz�dne dolnego punktu jako sf::Vector2f.
 */
sf::Vector2f LineSegment::get_bottom()
{
    return bottom.getXY();
}

/**
 * @brief Rysuje lini� reprezentuj�c� odcinek na oknie renderowania.
 * @param window Referencja do okna SFML.
 */
void LineSegment::draw_line(sf::RenderWindow& window)
{
    primitiveRenderer.drawIncrementalLine(window, top.getX(), top.getY(), bottom.getX(), bottom.getY());
}

/**
 * @brief Translacja odcinka o zadany wektor.
 * @param tx Przesuni�cie wzd�u� osi X.
 * @param ty Przesuni�cie wzd�u� osi Y.
 */
void LineSegment::translation(float tx, float ty)
{
    top.setXY(top.getX() + tx, top.getY() + ty);
    bottom.setXY(bottom.getX() + tx, bottom.getY() + ty);
}

/**
 * @brief Obraca odcinek o zadany k�t wok� punktu (400, 300).
 * @param window Referencja do okna SFML.
 * @param alfa K�t obrotu w stopniach.
 */
void LineSegment::rotation00(sf::RenderWindow& window, float alfa)
{
    float x0 = 400;
    float y0 = 300;
    alfa = alfa * M_PI / 180;

    float x2 = x0 + (top.getX() - x0) * cos(alfa) - (top.getY() - y0) * sin(alfa);
    float y2 = y0 + (top.getX() - x0) * sin(alfa) + (top.getY() - y0) * cos(alfa);
    float x1 = x0 + (bottom.getX() - x0) * cos(alfa) - (bottom.getY() - y0) * sin(alfa);
    float y1 = y0 + (bottom.getX() - x0) * sin(alfa) + (bottom.getY() - y0) * cos(alfa);
    primitiveRenderer.drawIncrementalLine(window, x1, y1, x2, y2);
}

/**
 * @brief Obraca odcinek o zadany k�t wok� dowolnego punktu (x0, y0).
 * @param alfa K�t obrotu w stopniach.
 * @param x0 Wsp�rz�dna X �rodka obrotu.
 * @param y0 Wsp�rz�dna Y �rodka obrotu.
 */
void LineSegment::rotationXY(float alfa, float x0, float y0)
{
    alfa = alfa * M_PI / 180.0f;

    float x2 = x0 + (top.getX() - x0) * cos(alfa) - (top.getY() - y0) * sin(alfa);
    float y2 = y0 + (top.getX() - x0) * sin(alfa) + (top.getY() - y0) * cos(alfa);
    float x1 = x0 + (bottom.getX() - x0) * cos(alfa) - (bottom.getY() - y0) * sin(alfa);
    float y1 = y0 + (bottom.getX() - x0) * sin(alfa) + (bottom.getY() - y0) * cos(alfa);

    top.setXY(x2, y2);
    bottom.setXY(x1, y1);
}

/**
 * @brief Skaluje odcinek wzgl�dem punktu (400, 300).
 * @param window Referencja do okna SFML.
 * @param k Wsp�czynnik skalowania.
 */
void LineSegment::scaling00(sf::RenderWindow& window, float k)
{
    float x0 = 400;
    float y0 = 300;

    float x2 = top.getX() * k + (1 - k) * x0;
    float y2 = top.getY() * k + (1 - k) * y0;
    float x1 = bottom.getX() * k + (1 - k) * x0;
    float y1 = bottom.getY() * k + (1 - k) * y0;
    primitiveRenderer.drawIncrementalLine(window, x1, y1, x2, y2);
}

/**
 * @brief Skaluje odcinek wzgl�dem dowolnego punktu (x0, y0).
 * @param window Referencja do okna SFML.
 * @param k Wsp�czynnik skalowania.
 * @param x0 Wsp�rz�dna X �rodka skalowania.
 * @param y0 Wsp�rz�dna Y �rodka skalowania.
 */
void LineSegment::scalingXY(sf::RenderWindow& window, float k, float x0, float y0)
{
    float x2 = top.getX() * k + (1 - k) * x0;
    float y2 = top.getY() * k + (1 - k) * y0;
    float x1 = bottom.getX() * k + (1 - k) * x0;
    float y1 = bottom.getY() * k + (1 - k) * y0;
    primitiveRenderer.drawIncrementalLine(window, x1, y1, x2, y2);
}
