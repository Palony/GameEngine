#include "Circle.h"
#include <cmath>

/**
 * @brief Klasa reprezentuj¹ca okr¹g.
 * Klasa ta pozwala na tworzenie okrêgów, ich rysowanie na ekranie, a tak¿e obs³ugê ich ruchu
 * oraz resetowanie pozycji, gdy okr¹g opuœci ekran.
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
 * @brief Rysowanie okrêgu na oknie renderowania.
 * Okr¹g jest rysowany piksel po pikselu, wype³niaj¹c jego wnêtrze i rysuj¹c kontur.
 * @param window Okno renderowania, na którym okr¹g ma zostaæ narysowany.
 */
void Circle::draw(sf::RenderWindow& window)
{
    points.clear(); // Czyœæ punkty przed narysowaniem ko³a

    // Wype³nianie okrêgu metod¹ pixel po pixelu
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

    // Rysuj kontur okrêgu za pomoc¹ istniej¹cej metody drawQuarter
    drawQuarter(1, -1, window);
    drawQuarter(1, 1, window);
    drawQuarter(-1, 1, window);
    drawQuarter(-1, -1, window);
}

/**
 * @brief Rysowanie jednej æwiartki okrêgu.
 * Metoda ta rysuje kontur okrêgu w jednej æwiartce, u¿ywaj¹c funkcji trygonometrycznych
 * dla obliczenia pozycji punktów na obwodzie.
 * @param x_sign Wartoœæ zmieniaj¹ca kierunek rysowania w osi X (1 lub -1).
 * @param y_sign Wartoœæ zmieniaj¹ca kierunek rysowania w osi Y (1 lub -1).
 * @param window Okno renderowania, na którym kontur ma zostaæ narysowany.
 */
void Circle::drawQuarter(int x_sign, int y_sign, sf::RenderWindow& window)
{
    const float M_PI = 3.14159265359f; // PI
    float alfa = 0.0f; // K¹t
    const float R = getR();
    const float inc = 1.0f / R; // Sta³a, któr¹ inkrementujemy k¹t

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
 * @brief Zwraca promieñ okrêgu.
 * @return Promieñ okrêgu.
 */
float Circle::getR()
{
    return R;
}

/**
 * @brief Metoda opadaj¹ca okrêgu na ekranie.
 * Okr¹g przemieszcza siê w dó³ ekranu, a jeœli opuœci ekran, jego pozycja zostaje zresetowana.
 * @param window Okno renderowania, w którym okr¹g jest wyœwietlany.
 * @param ty Prêdkoœæ opadania w osi Y.
 */
void Circle::fall(sf::RenderWindow& window, float ty)
{
    // Aktualizacja pozycji Y
    setY(getY() + ty);

    float windowHeight = window.getSize().y;

    // Jeœli okr¹g opuœci³ ekran, resetuj pozycjê
    if (getY() - R > windowHeight)
    {
        resetPosition();
    }
}

/**
 * @brief Resetuje pozycjê okrêgu do pocz¹tkowego miejsca.
 * Ustawia okr¹g na pocz¹tkow¹ pozycjê w górnej czêœci ekranu.
 */
void Circle::resetPosition()
{
    points.clear(); // Czyœci wektor punktów
    setXY(initialX, -R);
}

/**
 * @brief Dodaje punkt do wektora punktów okrêgu.
 * @param pos Pozycja punktu do dodania.
 */
void Circle::addPoints(sf::Vector2f pos)
{
    this->points.push_back(pos);
}

/**
 * @brief Zwraca wektor punktów, które tworz¹ okr¹g.
 * @return Wektor punktów okrêgu.
 */
std::vector<sf::Vector2f> Circle::getPoints() const
{
    return points;
}
