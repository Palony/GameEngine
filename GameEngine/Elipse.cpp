#include "Elipse.h"

/**
 * @brief Rysowanie elipsy na ekranie.
 * Metoda ta rysuje ca�� elips�, dziel�c j� na cztery �wiartki, kt�re s� rysowane za pomoc�
 * funkcji `drawQuarter`. Elipsa jest wy�wietlana na ekranie w postaci punkt�w.
 * @param window Okno renderowania, na kt�rym elipsa ma zosta� narysowana.
 */
void Elipse::draw(sf::RenderWindow& window)
{
    drawQuarter(1, -1, window);
    drawQuarter(1, 1, window);
    drawQuarter(-1, 1, window);
    drawQuarter(-1, -1, window);
}

/**
 * @brief Rysowanie jednej �wiartki elipsy.
 * Metoda ta rysuje kontur elipsy w jednej �wiartce, u�ywaj�c funkcji trygonometrycznych
 * dla obliczenia pozycji punkt�w na obwodzie elipsy.
 * @param x_sign Warto�� zmieniaj�ca kierunek rysowania w osi X (1 lub -1).
 * @param y_sign Warto�� zmieniaj�ca kierunek rysowania w osi Y (1 lub -1).
 * @param window Okno renderowania, na kt�rym kontur ma zosta� narysowany.
 */
void Elipse::drawQuarter(int x_sign, int y_sign, sf::RenderWindow& window)
{
    const float M_PI = 3.14159265359f; ///< Sta�a PI.
    float alfa = 0.0f; ///< K�t.
    float inc; ///< Inkrement dla k�ta.

    float x0 = getX(); ///< Pozycja X �rodka elipsy.
    float y0 = getY(); ///< Pozycja Y �rodka elipsy.
    float R1 = getR1(); ///< Wi�kszy promie� elipsy (w poziomie).
    float R2 = getR2(); ///< Mniejszy promie� elipsy (w pionie).

    // Ustawienie inkrementacji dla wi�kszego promienia.
    if (R1 > R2) {
        inc = 1.0f / R1;
    }
    else {
        inc = 1.0f / R2;
    }

    while (alfa <= M_PI / 2)
    {
        float x = x0 + x_sign * R1 * cos(alfa); ///< Obliczenie wsp�rz�dnej X punktu na obwodzie.
        float y = y0 + y_sign * R2 * sin(alfa); ///< Obliczenie wsp�rz�dnej Y punktu na obwodzie.

        sf::Vertex pixel(sf::Vector2f(std::round(x), std::round(y)), sf::Color::White); ///< Tworzenie punktu do narysowania.
        window.draw(&pixel, 1, sf::Points); ///< Rysowanie punktu na ekranie.

        alfa += inc; ///< Zwi�kszanie k�ta.
    }
}

/**
 * @brief Zwraca pierwszy promie� elipsy (promie� w poziomie).
 * @return Pierwszy promie� elipsy.
 */
float Elipse::getR1()
{
    return this->R1;
}

/**
 * @brief Zwraca drugi promie� elipsy (promie� w pionie).
 * @return Drugi promie� elipsy.
 */
float Elipse::getR2()
{
    return this->R2;
}
