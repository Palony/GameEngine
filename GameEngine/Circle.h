#pragma once
#include "DrawableObject.h"
#include "TransformableObject.h"
#include <SFML/Graphics.hpp>
#include <vector>

/**
 * @brief Klasa reprezentuj¹ca okr¹g.
 * Klasa ta pozwala na tworzenie okrêgów, ich rysowanie na ekranie, a tak¿e obs³ugê ich ruchu,
 * resetowanie pozycji, gdy okr¹g opuœci ekran, oraz zarz¹dzanie punktami okrêgu.
 */
class Circle : public DrawableObject, TransformableObject
{
private:
    float R; ///< Promieñ okrêgu.
    float speed; ///< Prêdkoœæ ruchu okrêgu.
    float initialX, initialY; ///< Pocz¹tkowe pozycje okrêgu.
    std::vector<sf::Vector2f> points; ///< Wektor zawieraj¹cy punkty tworz¹ce okr¹g.
    sf::Color fillColor; ///< Kolor wype³nienia okrêgu.

public:
    /**
     * @brief Konstruktor okrêgu.
     * Inicjalizuje okr¹g na podstawie pozycji (x, y), promienia R oraz koloru wype³nienia.
     * @param x Pozycja X œrodka okrêgu.
     * @param y Pozycja Y œrodka okrêgu.
     * @param R Promieñ okrêgu.
     * @param color Kolor wype³nienia okrêgu (domyœlnie bia³y).
     */
    Circle(float x, float y, float R, sf::Color color = sf::Color::White);

    /**
     * @brief Rysowanie okrêgu na oknie renderowania.
     * Okr¹g jest rysowany piksel po pikselu, wype³niaj¹c jego wnêtrze i rysuj¹c kontur.
     * @param window Okno renderowania, na którym okr¹g ma zostaæ narysowany.
     */
    void draw(sf::RenderWindow& window);

    /**
     * @brief Rysowanie jednej æwiartki okrêgu.
     * Metoda ta rysuje kontur okrêgu w jednej æwiartce, u¿ywaj¹c funkcji trygonometrycznych
     * dla obliczenia pozycji punktów na obwodzie.
     * @param x_sign Wartoœæ zmieniaj¹ca kierunek rysowania w osi X (1 lub -1).
     * @param y_sign Wartoœæ zmieniaj¹ca kierunek rysowania w osi Y (1 lub -1).
     * @param window Okno renderowania, na którym kontur ma zostaæ narysowany.
     */
    void drawQuarter(int x_sign, int y_sign, sf::RenderWindow& window);

    /**
     * @brief Zwraca promieñ okrêgu.
     * @return Promieñ okrêgu.
     */
    float getR();

    /**
     * @brief Metoda opadaj¹ca okrêgu na ekranie.
     * Okr¹g przemieszcza siê w dó³ ekranu, a jeœli opuœci ekran, jego pozycja zostaje zresetowana.
     * @param window Okno renderowania, w którym okr¹g jest wyœwietlany.
     * @param ty Prêdkoœæ opadania w osi Y.
     */
    void fall(sf::RenderWindow& window, float ty);

    /**
     * @brief Resetuje pozycjê okrêgu do pocz¹tkowego miejsca.
     * Ustawia okr¹g na pocz¹tkow¹ pozycjê w górnej czêœci ekranu.
     */
    void resetPosition();

    /**
     * @brief Dodaje punkt do wektora punktów okrêgu.
     * @param pos Pozycja punktu do dodania.
     */
    void addPoints(sf::Vector2f pos);

    /**
     * @brief Zwraca wektor punktów, które tworz¹ okr¹g.
     * @return Wektor punktów okrêgu.
     */
    std::vector<sf::Vector2f> getPoints() const;
};
