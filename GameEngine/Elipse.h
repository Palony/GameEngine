#pragma once
#include "DrawableObject.h"
#include "TransformableObject.h"

/**
 * @brief Klasa reprezentuj¹ca elipsê.
 * Klasa ta umo¿liwia tworzenie elipsy o zadanych promieniach, rysowanie jej na ekranie oraz
 * obliczanie jej parametrów. Dziedziczy po klasach `DrawableObject` i `TransformableObject`.
 */
class Elipse : public DrawableObject, TransformableObject
{
private:
    float R1; ///< Pierwszy promieñ elipsy (promieñ w poziomie).
    float R2; ///< Drugi promieñ elipsy (promieñ w pionie).
    sf::RenderWindow window; ///< Okno renderowania, u¿ywane do rysowania elipsy.

public:
    /**
     * @brief Konstruktor klasy Elipse.
     * Inicjalizuje elipsê z danymi promieniami i pozycj¹.
     * @param x Pozycja X œrodka elipsy.
     * @param y Pozycja Y œrodka elipsy.
     * @param R1 Pierwszy promieñ elipsy (promieñ w poziomie).
     * @param R2 Drugi promieñ elipsy (promieñ w pionie).
     */
    Elipse(float x, float y, float R1, float R2) {
        this->setXY(x, y);
        this->R1 = R1;
        this->R2 = R2;
    }

    /**
     * @brief Rysowanie elipsy na ekranie.
     * Elipsa jest rysowana przez wywo³anie funkcji `drawQuarter` dla czterech æwiartek.
     * @param window Okno renderowania, na którym elipsa ma zostaæ narysowana.
     */
    void draw(sf::RenderWindow& window);

    /**
     * @brief Rysowanie jednej æwiartki elipsy.
     * Rysuje kontur elipsy w jednej z æwiartek (okreœlonej przez zmienne `x_sign` i `y_sign`).
     * @param x_sign Kierunek rysowania w osi X (1 lub -1).
     * @param y_sign Kierunek rysowania w osi Y (1 lub -1).
     * @param window Okno renderowania, na którym kontur ma zostaæ narysowany.
     */
    void drawQuarter(int x_sign, int y_sign, sf::RenderWindow& window);

    /**
     * @brief Zwraca pierwszy promieñ elipsy (promieñ w poziomie).
     * @return Pierwszy promieñ elipsy.
     */
    float getR1();

    /**
     * @brief Zwraca drugi promieñ elipsy (promieñ w pionie).
     * @return Drugi promieñ elipsy.
     */
    float getR2();
};
