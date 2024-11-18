#include "Rectangle.h"
#include <algorithm>
#include <cmath>

/**
 * @brief Konstruktor klasy Rectangle.
 * @param w0 Pocz¹tkowa wspó³rzêdna x lewego górnego rogu.
 * @param h0 Pocz¹tkowa wspó³rzêdna y lewego górnego rogu.
 * @param w1 Pocz¹tkowa wspó³rzêdna x prawego dolnego rogu.
 * @param h1 Pocz¹tkowa wspó³rzêdna y prawego dolnego rogu.
 * @param color Kolor wype³nienia prostok¹ta.
 */
Rectangle::Rectangle(float w0, float h0, float w1, float h1, sf::Color color)
    : w0_init(w0), h0_init(h0), w1_init(w1), h1_init(h1), fillColor(color)
{
    // Inicjalizacja wspó³rzêdnych pocz¹tkowych
    w0 = w0_init;
    h0 = h0_init;
    w1 = w1_init;
    h1 = h1_init;

    // Inicjalizacja boków prostok¹ta
    side1.set_top(w0, h0);
    side1.set_bottom(w1, h0);

    side2.set_top(w1, h0);
    side2.set_bottom(w1, h1);

    side3.set_top(w1, h1);
    side3.set_bottom(w0, h1);

    side4.set_top(w0, h1);
    side4.set_bottom(w0, h0);
}

/**
 * @brief Rysuje prostok¹t w oknie SFML.
 * @param window Okno, w którym prostok¹t zostanie narysowany.
 */
void Rectangle::draw(sf::RenderWindow& window)
{
    // Upewniamy siê, ¿e wspó³rzêdne s¹ uporz¹dkowane
    float w0 = this->w0;
    float h0 = this->h0;
    float w1 = this->w1;
    float h1 = this->h1;

    if (w0 > w1) std::swap(w0, w1);
    if (h0 > h1) std::swap(h0, h1);

    // Wype³nianie prostok¹ta
    for (float y = h0; y <= h1; ++y)
    {
        for (float x = w0; x <= w1; ++x)
        {
            sf::Vertex pixel(sf::Vector2f(x, y), fillColor);
            window.draw(&pixel, 1, sf::Points);
        }
    }

    // Opcjonalnie rysowanie boków prostok¹ta
    side1.draw_line(window);
    side2.draw_line(window);
    side3.draw_line(window);
    side4.draw_line(window);
}

/**
 * @brief Powoduje "opadanie" prostok¹ta w dó³ o okreœlon¹ wartoœæ przesuniêcia.
 * @param window Okno SFML do rysowania.
 * @param ty Przesuniêcie w osi y.
 */
void Rectangle::fall(sf::RenderWindow& window, float ty)
{
    // Translacja prostok¹ta
    side1.translation(0, ty);
    side2.translation(0, ty);
    side3.translation(0, ty);
    side4.translation(0, ty);

    updatePoints(); // Aktualizacja wspó³rzêdnych po rotacji

    // Sprawdzanie, czy prostok¹t przekroczy³ ekran
    float windowHeight = window.getSize().y;
    float maxY = std::max({
        side1.get_top().y, side1.get_bottom().y,
        side2.get_top().y, side2.get_bottom().y,
        side3.get_top().y, side3.get_bottom().y,
        side4.get_top().y, side4.get_bottom().y
        });

    if (maxY > windowHeight)
    {
        resetPosition(); // Jeœli prostok¹t wyszed³ poza ekran, resetuj pozycjê
        updatePoints();
    }
}

/**
 * @brief Resetuje pozycjê prostok¹ta do wartoœci pocz¹tkowych.
 */
void Rectangle::resetPosition()
{
    // Przywracanie pocz¹tkowej pozycji
    side1.set_top(w0_init, h0_init);
    side1.set_bottom(w1_init, h0_init);

    side2.set_top(w1_init, h0_init);
    side2.set_bottom(w1_init, h1_init);

    side3.set_top(w1_init, h1_init);
    side3.set_bottom(w0_init, h1_init);

    side4.set_top(w0_init, h1_init);
    side4.set_bottom(w0_init, h0_init);

    // Resetowanie k¹ta obrotu
    rotationAngle = 0.0f;
    updatePoints();
}

/**
 * @brief Aktualizuje bie¿¹ce wspó³rzêdne prostok¹ta na podstawie pozycji boków.
 */
void Rectangle::updatePoints()
{
    // Aktualizowanie bie¿¹cych wspó³rzêdnych na podstawie pozycji boków
    w0 = side1.get_top().x;
    h0 = side1.get_top().y;

    w1 = side2.get_top().x;
    h1 = side2.get_bottom().y; // Poprawka, aby h1 by³o poprawne
}

/**
 * @brief Zwraca wspó³rzêdn¹ x lewego górnego rogu prostok¹ta.
 * @return Wspó³rzêdna x lewego górnego rogu.
 */
float Rectangle::getW0() const
{
    return w0;
}

/**
 * @brief Zwraca wspó³rzêdn¹ y lewego górnego rogu prostok¹ta.
 * @return Wspó³rzêdna y lewego górnego rogu.
 */
float Rectangle::getH0() const
{
    return h0;
}

/**
 * @brief Zwraca wspó³rzêdn¹ x prawego dolnego rogu prostok¹ta.
 * @return Wspó³rzêdna x prawego dolnego rogu.
 */
float Rectangle::getW1() const
{
    return w1;
}

/**
 * @brief Zwraca wspó³rzêdn¹ y prawego dolnego rogu prostok¹ta.
 * @return Wspó³rzêdna y prawego dolnego rogu.
 */
float Rectangle::getH1() const
{
    return h1;
}
