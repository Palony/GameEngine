#include "LineSegment.h"

/**
 * @brief Ustawia górny punkt odcinka.
 * @param x Wspó³rzêdna X punktu.
 * @param y Wspó³rzêdna Y punktu.
 */
void LineSegment::set_top(float x, float y)
{
    top.setXY(x, y);
}

/**
 * @brief Ustawia dolny punkt odcinka.
 * @param x Wspó³rzêdna X punktu.
 * @param y Wspó³rzêdna Y punktu.
 */
void LineSegment::set_bottom(float x, float y)
{
    bottom.setXY(x, y);
}

/**
 * @brief Pobiera górny punkt odcinka.
 * @return Wspó³rzêdne górnego punktu jako sf::Vector2f.
 */
sf::Vector2f LineSegment::get_top()
{
    return top.getXY();
}

/**
 * @brief Pobiera dolny punkt odcinka.
 * @return Wspó³rzêdne dolnego punktu jako sf::Vector2f.
 */
sf::Vector2f LineSegment::get_bottom()
{
    return bottom.getXY();
}

/**
 * @brief Rysuje liniê reprezentuj¹c¹ odcinek na oknie renderowania.
 * @param window Referencja do okna SFML.
 */
void LineSegment::draw_line(sf::RenderWindow& window)
{
    primitiveRenderer.drawIncrementalLine(window, top.getX(), top.getY(), bottom.getX(), bottom.getY());
}

/**
 * @brief Translacja odcinka o zadany wektor.
 * @param tx Przesuniêcie wzd³u¿ osi X.
 * @param ty Przesuniêcie wzd³u¿ osi Y.
 */
void LineSegment::translation(float tx, float ty)
{
    top.setXY(top.getX() + tx, top.getY() + ty);
    bottom.setXY(bottom.getX() + tx, bottom.getY() + ty);
}

/**
 * @brief Obraca odcinek o zadany k¹t wokó³ punktu (400, 300).
 * @param window Referencja do okna SFML.
 * @param alfa K¹t obrotu w stopniach.
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
 * @brief Obraca odcinek o zadany k¹t wokó³ dowolnego punktu (x0, y0).
 * @param alfa K¹t obrotu w stopniach.
 * @param x0 Wspó³rzêdna X œrodka obrotu.
 * @param y0 Wspó³rzêdna Y œrodka obrotu.
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
 * @brief Skaluje odcinek wzglêdem punktu (400, 300).
 * @param window Referencja do okna SFML.
 * @param k Wspó³czynnik skalowania.
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
 * @brief Skaluje odcinek wzglêdem dowolnego punktu (x0, y0).
 * @param window Referencja do okna SFML.
 * @param k Wspó³czynnik skalowania.
 * @param x0 Wspó³rzêdna X œrodka skalowania.
 * @param y0 Wspó³rzêdna Y œrodka skalowania.
 */
void LineSegment::scalingXY(sf::RenderWindow& window, float k, float x0, float y0)
{
    float x2 = top.getX() * k + (1 - k) * x0;
    float y2 = top.getY() * k + (1 - k) * y0;
    float x1 = bottom.getX() * k + (1 - k) * x0;
    float y1 = bottom.getY() * k + (1 - k) * y0;
    primitiveRenderer.drawIncrementalLine(window, x1, y1, x2, y2);
}
