#include "Rectangle.h"
#include <algorithm>
#include <cmath>

/**
 * @brief Konstruktor klasy Rectangle.
 * @param w0 Pocz�tkowa wsp�rz�dna x lewego g�rnego rogu.
 * @param h0 Pocz�tkowa wsp�rz�dna y lewego g�rnego rogu.
 * @param w1 Pocz�tkowa wsp�rz�dna x prawego dolnego rogu.
 * @param h1 Pocz�tkowa wsp�rz�dna y prawego dolnego rogu.
 * @param color Kolor wype�nienia prostok�ta.
 */
Rectangle::Rectangle(float w0, float h0, float w1, float h1, sf::Color color)
    : w0_init(w0), h0_init(h0), w1_init(w1), h1_init(h1), fillColor(color)
{
    // Inicjalizacja wsp�rz�dnych pocz�tkowych
    w0 = w0_init;
    h0 = h0_init;
    w1 = w1_init;
    h1 = h1_init;

    // Inicjalizacja bok�w prostok�ta
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
 * @brief Rysuje prostok�t w oknie SFML.
 * @param window Okno, w kt�rym prostok�t zostanie narysowany.
 */
void Rectangle::draw(sf::RenderWindow& window)
{
    // Upewniamy si�, �e wsp�rz�dne s� uporz�dkowane
    float w0 = this->w0;
    float h0 = this->h0;
    float w1 = this->w1;
    float h1 = this->h1;

    if (w0 > w1) std::swap(w0, w1);
    if (h0 > h1) std::swap(h0, h1);

    // Wype�nianie prostok�ta
    for (float y = h0; y <= h1; ++y)
    {
        for (float x = w0; x <= w1; ++x)
        {
            sf::Vertex pixel(sf::Vector2f(x, y), fillColor);
            window.draw(&pixel, 1, sf::Points);
        }
    }

    // Opcjonalnie rysowanie bok�w prostok�ta
    side1.draw_line(window);
    side2.draw_line(window);
    side3.draw_line(window);
    side4.draw_line(window);
}

/**
 * @brief Powoduje "opadanie" prostok�ta w d� o okre�lon� warto�� przesuni�cia.
 * @param window Okno SFML do rysowania.
 * @param ty Przesuni�cie w osi y.
 */
void Rectangle::fall(sf::RenderWindow& window, float ty)
{
    // Translacja prostok�ta
    side1.translation(0, ty);
    side2.translation(0, ty);
    side3.translation(0, ty);
    side4.translation(0, ty);

    updatePoints(); // Aktualizacja wsp�rz�dnych po rotacji

    // Sprawdzanie, czy prostok�t przekroczy� ekran
    float windowHeight = window.getSize().y;
    float maxY = std::max({
        side1.get_top().y, side1.get_bottom().y,
        side2.get_top().y, side2.get_bottom().y,
        side3.get_top().y, side3.get_bottom().y,
        side4.get_top().y, side4.get_bottom().y
        });

    if (maxY > windowHeight)
    {
        resetPosition(); // Je�li prostok�t wyszed� poza ekran, resetuj pozycj�
        updatePoints();
    }
}

/**
 * @brief Resetuje pozycj� prostok�ta do warto�ci pocz�tkowych.
 */
void Rectangle::resetPosition()
{
    // Przywracanie pocz�tkowej pozycji
    side1.set_top(w0_init, h0_init);
    side1.set_bottom(w1_init, h0_init);

    side2.set_top(w1_init, h0_init);
    side2.set_bottom(w1_init, h1_init);

    side3.set_top(w1_init, h1_init);
    side3.set_bottom(w0_init, h1_init);

    side4.set_top(w0_init, h1_init);
    side4.set_bottom(w0_init, h0_init);

    // Resetowanie k�ta obrotu
    rotationAngle = 0.0f;
    updatePoints();
}

/**
 * @brief Aktualizuje bie��ce wsp�rz�dne prostok�ta na podstawie pozycji bok�w.
 */
void Rectangle::updatePoints()
{
    // Aktualizowanie bie��cych wsp�rz�dnych na podstawie pozycji bok�w
    w0 = side1.get_top().x;
    h0 = side1.get_top().y;

    w1 = side2.get_top().x;
    h1 = side2.get_bottom().y; // Poprawka, aby h1 by�o poprawne
}

/**
 * @brief Zwraca wsp�rz�dn� x lewego g�rnego rogu prostok�ta.
 * @return Wsp�rz�dna x lewego g�rnego rogu.
 */
float Rectangle::getW0() const
{
    return w0;
}

/**
 * @brief Zwraca wsp�rz�dn� y lewego g�rnego rogu prostok�ta.
 * @return Wsp�rz�dna y lewego g�rnego rogu.
 */
float Rectangle::getH0() const
{
    return h0;
}

/**
 * @brief Zwraca wsp�rz�dn� x prawego dolnego rogu prostok�ta.
 * @return Wsp�rz�dna x prawego dolnego rogu.
 */
float Rectangle::getW1() const
{
    return w1;
}

/**
 * @brief Zwraca wsp�rz�dn� y prawego dolnego rogu prostok�ta.
 * @return Wsp�rz�dna y prawego dolnego rogu.
 */
float Rectangle::getH1() const
{
    return h1;
}
