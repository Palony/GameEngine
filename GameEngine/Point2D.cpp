#include "Point2D.h"

/**
 * @brief Ustawia wspó³rzêdne punktu.
 * @param x Wspó³rzêdna X punktu.
 * @param y Wspó³rzêdna Y punktu.
 */
void Point2D::setXY(float x, float y)
{
    cords.x = x;
    cords.y = y;
}

/**
 * @brief Ustawia wspó³rzêdn¹ X punktu.
 * @param x Wspó³rzêdna X.
 */
void Point2D::setX(float x)
{
    cords.x = x;
}

/**
 * @brief Ustawia wspó³rzêdn¹ Y punktu.
 * @param y Wspó³rzêdna Y.
 */
void Point2D::setY(float y)
{
    cords.y = y;
}

/**
 * @brief Pobiera wspó³rzêdne punktu jako wektor sf::Vector2f.
 * @return Wektor sf::Vector2f zawieraj¹cy wspó³rzêdne punktu.
 */
sf::Vector2f Point2D::getXY()
{
    return cords;
}

/**
 * @brief Pobiera wspó³rzêdn¹ X punktu.
 * @return Wspó³rzêdna X.
 */
float Point2D::getX()
{
    return cords.x;
}

/**
 * @brief Pobiera wspó³rzêdn¹ Y punktu.
 * @return Wspó³rzêdna Y.
 */
float Point2D::getY()
{
    return cords.y;
}

/**
 * @brief Rysuje punkt na podanym oknie renderowania.
 * @param window Referencja do okna SFML, na którym punkt zostanie narysowany.
 */
void Point2D::draw_point(sf::RenderWindow& window)
{
    primitiveRenderer.drawIncrementalLine(window, cords.x, cords.y, cords.x, cords.y);
}

/**
 * @brief Przesuwa punkt o zadany wektor translacji i rysuje go na podanym oknie.
 * @param window Referencja do okna SFML, na którym punkt zostanie narysowany.
 * @param tx Przesuniêcie wzd³u¿ osi X.
 * @param ty Przesuniêcie wzd³u¿ osi Y.
 */
void Point2D::translation(sf::RenderWindow& window, float tx, float ty)
{
    float x2 = cords.x + tx;
    float y2 = cords.y + ty;
    primitiveRenderer.drawIncrementalLine(window, x2, y2, x2, y2);
}

/**
 * @brief Obraca punkt o zadany k¹t wokó³ punktu (400, 300) i rysuje go na podanym oknie.
 * @param window Referencja do okna SFML, na którym punkt zostanie narysowany.
 * @param alfa K¹t obrotu w stopniach.
 */
void Point2D::rotation00(sf::RenderWindow& window, float alfa)
{
    float x0 = 400;
    float y0 = 300;
    alfa = alfa * M_PI / 180.0f;

    float x2 = x0 + (cords.x - x0) * cos(alfa) - (cords.y - y0) * sin(alfa);
    float y2 = y0 + (cords.x - x0) * sin(alfa) + (cords.y - y0) * cos(alfa);
    primitiveRenderer.drawIncrementalLine(window, x2, y2, x2, y2);
}

/**
 * @brief Obraca punkt o zadany k¹t wokó³ dowolnego punktu (x0, y0) i rysuje go na podanym oknie.
 * @param window Referencja do okna SFML, na którym punkt zostanie narysowany.
 * @param alfa K¹t obrotu w stopniach.
 * @param x0 Wspó³rzêdna X œrodka obrotu.
 * @param y0 Wspó³rzêdna Y œrodka obrotu.
 */
void Point2D::rotationXY(sf::RenderWindow& window, float alfa, float x0, float y0)
{
    alfa = alfa * M_PI / 180.0f;

    float x2 = x0 + (cords.x - x0) * cos(alfa) - (cords.y - y0) * sin(alfa);
    float y2 = y0 + (cords.x - x0) * sin(alfa) + (cords.y - y0) * cos(alfa);
    primitiveRenderer.drawIncrementalLine(window, x2, y2, x2, y2);
}

/**
 * @brief Skaluje punkt wzglêdem punktu (400, 300) i rysuje go na podanym oknie.
 * @param window Referencja do okna SFML, na którym punkt zostanie narysowany.
 * @param k Wspó³czynnik skalowania.
 */
void Point2D::scaling00(sf::RenderWindow& window, float k)
{
    float x0 = 400;
    float y0 = 300;

    float x2 = cords.x * k + (1 - k) * x0;
    float y2 = cords.y * k + (1 - k) * y0;
    primitiveRenderer.drawIncrementalLine(window, x2, y2, x2, y2);
}

/**
 * @brief Skaluje punkt wzglêdem dowolnego punktu (x0, y0) i rysuje go na podanym oknie.
 * @param window Referencja do okna SFML, na którym punkt zostanie narysowany.
 * @param k Wspó³czynnik skalowania.
 * @param x0 Wspó³rzêdna X œrodka skalowania.
 * @param y0 Wspó³rzêdna Y œrodka skalowania.
 */
void Point2D::scalingXY(sf::RenderWindow& window, float k, float x0, float y0)
{
    float x2 = cords.x * k + (1 - k) * x0;
    float y2 = cords.y * k + (1 - k) * y0;
    primitiveRenderer.drawIncrementalLine(window, x2, y2, x2, y2);
}
