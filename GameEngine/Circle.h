#pragma once
#include "DrawableObject.h"
#include "TransformableObject.h"
#include <SFML/Graphics.hpp>
#include <vector>

/**
 * @brief Klasa reprezentuj�ca okr�g.
 * Klasa ta pozwala na tworzenie okr�g�w, ich rysowanie na ekranie, a tak�e obs�ug� ich ruchu,
 * resetowanie pozycji, gdy okr�g opu�ci ekran, oraz zarz�dzanie punktami okr�gu.
 */
class Circle : public DrawableObject, TransformableObject
{
private:
    float R; ///< Promie� okr�gu.
    float speed; ///< Pr�dko�� ruchu okr�gu.
    float initialX, initialY; ///< Pocz�tkowe pozycje okr�gu.
    std::vector<sf::Vector2f> points; ///< Wektor zawieraj�cy punkty tworz�ce okr�g.
    sf::Color fillColor; ///< Kolor wype�nienia okr�gu.

public:
    /**
     * @brief Konstruktor okr�gu.
     * Inicjalizuje okr�g na podstawie pozycji (x, y), promienia R oraz koloru wype�nienia.
     * @param x Pozycja X �rodka okr�gu.
     * @param y Pozycja Y �rodka okr�gu.
     * @param R Promie� okr�gu.
     * @param color Kolor wype�nienia okr�gu (domy�lnie bia�y).
     */
    Circle(float x, float y, float R, sf::Color color = sf::Color::White);

    /**
     * @brief Rysowanie okr�gu na oknie renderowania.
     * Okr�g jest rysowany piksel po pikselu, wype�niaj�c jego wn�trze i rysuj�c kontur.
     * @param window Okno renderowania, na kt�rym okr�g ma zosta� narysowany.
     */
    void draw(sf::RenderWindow& window);

    /**
     * @brief Rysowanie jednej �wiartki okr�gu.
     * Metoda ta rysuje kontur okr�gu w jednej �wiartce, u�ywaj�c funkcji trygonometrycznych
     * dla obliczenia pozycji punkt�w na obwodzie.
     * @param x_sign Warto�� zmieniaj�ca kierunek rysowania w osi X (1 lub -1).
     * @param y_sign Warto�� zmieniaj�ca kierunek rysowania w osi Y (1 lub -1).
     * @param window Okno renderowania, na kt�rym kontur ma zosta� narysowany.
     */
    void drawQuarter(int x_sign, int y_sign, sf::RenderWindow& window);

    /**
     * @brief Zwraca promie� okr�gu.
     * @return Promie� okr�gu.
     */
    float getR();

    /**
     * @brief Metoda opadaj�ca okr�gu na ekranie.
     * Okr�g przemieszcza si� w d� ekranu, a je�li opu�ci ekran, jego pozycja zostaje zresetowana.
     * @param window Okno renderowania, w kt�rym okr�g jest wy�wietlany.
     * @param ty Pr�dko�� opadania w osi Y.
     */
    void fall(sf::RenderWindow& window, float ty);

    /**
     * @brief Resetuje pozycj� okr�gu do pocz�tkowego miejsca.
     * Ustawia okr�g na pocz�tkow� pozycj� w g�rnej cz�ci ekranu.
     */
    void resetPosition();

    /**
     * @brief Dodaje punkt do wektora punkt�w okr�gu.
     * @param pos Pozycja punktu do dodania.
     */
    void addPoints(sf::Vector2f pos);

    /**
     * @brief Zwraca wektor punkt�w, kt�re tworz� okr�g.
     * @return Wektor punkt�w okr�gu.
     */
    std::vector<sf::Vector2f> getPoints() const;
};
