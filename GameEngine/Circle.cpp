#include "Circle.h"
#include <cmath>

/**
 * @brief Klasa reprezentuj�ca okr�g.
 * Klasa ta pozwala na tworzenie okr�g�w, ich rysowanie na ekranie, a tak�e obs�ug� ich ruchu
 * oraz resetowanie pozycji, gdy okr�g opu�ci ekran.
 */
Circle::Circle(float x, float y, float R, sf::Color color)
    : R(R), fillColor(color)
{
    this->setXY(x, y);
    this->speed = 1.0f;

    this->initialX = x;
    this->initialY = y;
}

/**
 * @brief Rysowanie okr�gu na oknie renderowania.
 * Okr�g jest rysowany piksel po pikselu, wype�niaj�c jego wn�trze i rysuj�c kontur.
 * @param window Okno renderowania, na kt�rym okr�g ma zosta� narysowany.
 */
void Circle::draw(sf::RenderWindow& window)
{
    points.clear(); // Czy�� punkty przed narysowaniem ko�a

    // Wype�nianie okr�gu metod� pixel po pixelu
    int minX = static_cast<int>(std::floor(getX() - R));
    int maxX = static_cast<int>(std::ceil(getX() + R));
    int minY = static_cast<int>(std::floor(getY() - R));
    int maxY = static_cast<int>(std::ceil(getY() + R));

    for (int y = minY; y <= maxY; ++y)
    {
        for (int x = minX; x <= maxX; ++x)
        {
            float dx = x - getX();
            float dy = y - getY();
            if (dx * dx + dy * dy <= R * R)
            {
                sf::Vertex pixel(sf::Vector2f(static_cast<float>(x), static_cast<float>(y)), fillColor);
                window.draw(&pixel, 1, sf::Points);
            }
        }
    }

    // Rysuj kontur okr�gu za pomoc� istniej�cej metody drawQuarter
    drawQuarter(1, -1, window);
    drawQuarter(1, 1, window);
    drawQuarter(-1, 1, window);
    drawQuarter(-1, -1, window);
}

/**
 * @brief Rysowanie jednej �wiartki okr�gu.
 * Metoda ta rysuje kontur okr�gu w jednej �wiartce, u�ywaj�c funkcji trygonometrycznych
 * dla obliczenia pozycji punkt�w na obwodzie.
 * @param x_sign Warto�� zmieniaj�ca kierunek rysowania w osi X (1 lub -1).
 * @param y_sign Warto�� zmieniaj�ca kierunek rysowania w osi Y (1 lub -1).
 * @param window Okno renderowania, na kt�rym kontur ma zosta� narysowany.
 */
void Circle::drawQuarter(int x_sign, int y_sign, sf::RenderWindow& window)
{
    const float M_PI = 3.14159265359f; // PI
    float alfa = 0.0f; // K�t
    const float R = getR();
    const float inc = 1.0f / R; // Sta�a, kt�r� inkrementujemy k�t

    while (alfa <= M_PI / 2)
    {
        float x1 = getX() + x_sign * R * cos(alfa);
        float y1 = getY() + y_sign * R * sin(alfa);
        sf::Vector2f pos;
        pos.x = x1;
        pos.y = y1;
        addPoints(pos);

        // Rysuj piksel konturu
        sf::Vertex pixel(sf::Vector2f(std::round(x1), std::round(y1)), sf::Color::Black);
        window.draw(&pixel, 1, sf::Points);

        alfa += inc;
    }
}

/**
 * @brief Zwraca promie� okr�gu.
 * @return Promie� okr�gu.
 */
float Circle::getR()
{
    return R;
}

/**
 * @brief Metoda opadaj�ca okr�gu na ekranie.
 * Okr�g przemieszcza si� w d� ekranu, a je�li opu�ci ekran, jego pozycja zostaje zresetowana.
 * @param window Okno renderowania, w kt�rym okr�g jest wy�wietlany.
 * @param ty Pr�dko�� opadania w osi Y.
 */
void Circle::fall(sf::RenderWindow& window, float ty)
{
    // Aktualizacja pozycji Y
    setY(getY() + ty);

    float windowHeight = window.getSize().y;

    // Je�li okr�g opu�ci� ekran, resetuj pozycj�
    if (getY() - R > windowHeight)
    {
        resetPosition();
    }
}

/**
 * @brief Resetuje pozycj� okr�gu do pocz�tkowego miejsca.
 * Ustawia okr�g na pocz�tkow� pozycj� w g�rnej cz�ci ekranu.
 */
void Circle::resetPosition()
{
    points.clear(); // Czy�ci wektor punkt�w
    setXY(initialX, -R);
}

/**
 * @brief Dodaje punkt do wektora punkt�w okr�gu.
 * @param pos Pozycja punktu do dodania.
 */
void Circle::addPoints(sf::Vector2f pos)
{
    this->points.push_back(pos);
}

/**
 * @brief Zwraca wektor punkt�w, kt�re tworz� okr�g.
 * @return Wektor punkt�w okr�gu.
 */
std::vector<sf::Vector2f> Circle::getPoints() const
{
    return points;
}
