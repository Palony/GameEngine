#include "Point2D.h"

/**
 * @brief Ustawia wsp�rz�dne punktu.
 * @param x Wsp�rz�dna X punktu.
 * @param y Wsp�rz�dna Y punktu.
 */
void Point2D::setXY(float x, float y)
{
    cords.x = x;
    cords.y = y;
}

/**
 * @brief Ustawia wsp�rz�dn� X punktu.
 * @param x Wsp�rz�dna X.
 */
void Point2D::setX(float x)
{
    cords.x = x;
}

/**
 * @brief Ustawia wsp�rz�dn� Y punktu.
 * @param y Wsp�rz�dna Y.
 */
void Point2D::setY(float y)
{
    cords.y = y;
}

/**
 * @brief Pobiera wsp�rz�dne punktu jako wektor sf::Vector2f.
 * @return Wektor sf::Vector2f zawieraj�cy wsp�rz�dne punktu.
 */
sf::Vector2f Point2D::getXY()
{
    return cords;
}

/**
 * @brief Pobiera wsp�rz�dn� X punktu.
 * @return Wsp�rz�dna X.
 */
float Point2D::getX()
{
    return cords.x;
}

/**
 * @brief Pobiera wsp�rz�dn� Y punktu.
 * @return Wsp�rz�dna Y.
 */
float Point2D::getY()
{
    return cords.y;
}

/**
 * @brief Rysuje punkt na podanym oknie renderowania.
 * @param window Referencja do okna SFML, na kt�rym punkt zostanie narysowany.
 */
void Point2D::draw_point(sf::RenderWindow& window)
{
    primitiveRenderer.drawIncrementalLine(window, cords.x, cords.y, cords.x, cords.y);
}

/**
 * @brief Przesuwa punkt o zadany wektor translacji i rysuje go na podanym oknie.
 * @param window Referencja do okna SFML, na kt�rym punkt zostanie narysowany.
 * @param tx Przesuni�cie wzd�u� osi X.
 * @param ty Przesuni�cie wzd�u� osi Y.
 */
void Point2D::translation(sf::RenderWindow& window, float tx, float ty)
{
    float x2 = cords.x + tx;
    float y2 = cords.y + ty;
    primitiveRenderer.drawIncrementalLine(window, x2, y2, x2, y2);
}

/**
 * @brief Obraca punkt o zadany k�t wok� punktu (400, 300) i rysuje go na podanym oknie.
 * @param window Referencja do okna SFML, na kt�rym punkt zostanie narysowany.
 * @param alfa K�t obrotu w stopniach.
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
 * @brief Obraca punkt o zadany k�t wok� dowolnego punktu (x0, y0) i rysuje go na podanym oknie.
 * @param window Referencja do okna SFML, na kt�rym punkt zostanie narysowany.
 * @param alfa K�t obrotu w stopniach.
 * @param x0 Wsp�rz�dna X �rodka obrotu.
 * @param y0 Wsp�rz�dna Y �rodka obrotu.
 */
void Point2D::rotationXY(sf::RenderWindow& window, float alfa, float x0, float y0)
{
    alfa = alfa * M_PI / 180.0f;

    float x2 = x0 + (cords.x - x0) * cos(alfa) - (cords.y - y0) * sin(alfa);
    float y2 = y0 + (cords.x - x0) * sin(alfa) + (cords.y - y0) * cos(alfa);
    primitiveRenderer.drawIncrementalLine(window, x2, y2, x2, y2);
}

/**
 * @brief Skaluje punkt wzgl�dem punktu (400, 300) i rysuje go na podanym oknie.
 * @param window Referencja do okna SFML, na kt�rym punkt zostanie narysowany.
 * @param k Wsp�czynnik skalowania.
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
 * @brief Skaluje punkt wzgl�dem dowolnego punktu (x0, y0) i rysuje go na podanym oknie.
 * @param window Referencja do okna SFML, na kt�rym punkt zostanie narysowany.
 * @param k Wsp�czynnik skalowania.
 * @param x0 Wsp�rz�dna X �rodka skalowania.
 * @param y0 Wsp�rz�dna Y �rodka skalowania.
 */
void Point2D::scalingXY(sf::RenderWindow& window, float k, float x0, float y0)
{
    float x2 = cords.x * k + (1 - k) * x0;
    float y2 = cords.y * k + (1 - k) * y0;
    primitiveRenderer.drawIncrementalLine(window, x2, y2, x2, y2);
}
