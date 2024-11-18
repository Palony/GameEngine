#include "Elipse.h"

/**
 * @brief Rysowanie elipsy na ekranie.
 * Metoda ta rysuje ca³¹ elipsê, dziel¹c j¹ na cztery æwiartki, które s¹ rysowane za pomoc¹
 * funkcji `drawQuarter`. Elipsa jest wyœwietlana na ekranie w postaci punktów.
 * @param window Okno renderowania, na którym elipsa ma zostaæ narysowana.
 */
void Elipse::draw(sf::RenderWindow& window)
{
    drawQuarter(1, -1, window);
    drawQuarter(1, 1, window);
    drawQuarter(-1, 1, window);
    drawQuarter(-1, -1, window);
}

/**
 * @brief Rysowanie jednej æwiartki elipsy.
 * Metoda ta rysuje kontur elipsy w jednej æwiartce, u¿ywaj¹c funkcji trygonometrycznych
 * dla obliczenia pozycji punktów na obwodzie elipsy.
 * @param x_sign Wartoœæ zmieniaj¹ca kierunek rysowania w osi X (1 lub -1).
 * @param y_sign Wartoœæ zmieniaj¹ca kierunek rysowania w osi Y (1 lub -1).
 * @param window Okno renderowania, na którym kontur ma zostaæ narysowany.
 */
void Elipse::drawQuarter(int x_sign, int y_sign, sf::RenderWindow& window)
{
    const float M_PI = 3.14159265359f; ///< Sta³a PI.
    float alfa = 0.0f; ///< K¹t.
    float inc; ///< Inkrement dla k¹ta.

    float x0 = getX(); ///< Pozycja X œrodka elipsy.
    float y0 = getY(); ///< Pozycja Y œrodka elipsy.
    float R1 = getR1(); ///< Wiêkszy promieñ elipsy (w poziomie).
    float R2 = getR2(); ///< Mniejszy promieñ elipsy (w pionie).

    // Ustawienie inkrementacji dla wiêkszego promienia.
    if (R1 > R2) {
        inc = 1.0f / R1;
    }
    else {
        inc = 1.0f / R2;
    }

    while (alfa <= M_PI / 2)
    {
        float x = x0 + x_sign * R1 * cos(alfa); ///< Obliczenie wspó³rzêdnej X punktu na obwodzie.
        float y = y0 + y_sign * R2 * sin(alfa); ///< Obliczenie wspó³rzêdnej Y punktu na obwodzie.

        sf::Vertex pixel(sf::Vector2f(std::round(x), std::round(y)), sf::Color::White); ///< Tworzenie punktu do narysowania.
        window.draw(&pixel, 1, sf::Points); ///< Rysowanie punktu na ekranie.

        alfa += inc; ///< Zwiêkszanie k¹ta.
    }
}

/**
 * @brief Zwraca pierwszy promieñ elipsy (promieñ w poziomie).
 * @return Pierwszy promieñ elipsy.
 */
float Elipse::getR1()
{
    return this->R1;
}

/**
 * @brief Zwraca drugi promieñ elipsy (promieñ w pionie).
 * @return Drugi promieñ elipsy.
 */
float Elipse::getR2()
{
    return this->R2;
}
