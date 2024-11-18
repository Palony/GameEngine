#pragma once
#include "DrawableObject.h"
#include "TransformableObject.h"

/**
 * @brief Klasa reprezentuj�ca elips�.
 * Klasa ta umo�liwia tworzenie elipsy o zadanych promieniach, rysowanie jej na ekranie oraz
 * obliczanie jej parametr�w. Dziedziczy po klasach `DrawableObject` i `TransformableObject`.
 */
class Elipse : public DrawableObject, TransformableObject
{
private:
    float R1; ///< Pierwszy promie� elipsy (promie� w poziomie).
    float R2; ///< Drugi promie� elipsy (promie� w pionie).
    sf::RenderWindow window; ///< Okno renderowania, u�ywane do rysowania elipsy.

public:
    /**
     * @brief Konstruktor klasy Elipse.
     * Inicjalizuje elips� z danymi promieniami i pozycj�.
     * @param x Pozycja X �rodka elipsy.
     * @param y Pozycja Y �rodka elipsy.
     * @param R1 Pierwszy promie� elipsy (promie� w poziomie).
     * @param R2 Drugi promie� elipsy (promie� w pionie).
     */
    Elipse(float x, float y, float R1, float R2) {
        this->setXY(x, y);
        this->R1 = R1;
        this->R2 = R2;
    }

    /**
     * @brief Rysowanie elipsy na ekranie.
     * Elipsa jest rysowana przez wywo�anie funkcji `drawQuarter` dla czterech �wiartek.
     * @param window Okno renderowania, na kt�rym elipsa ma zosta� narysowana.
     */
    void draw(sf::RenderWindow& window);

    /**
     * @brief Rysowanie jednej �wiartki elipsy.
     * Rysuje kontur elipsy w jednej z �wiartek (okre�lonej przez zmienne `x_sign` i `y_sign`).
     * @param x_sign Kierunek rysowania w osi X (1 lub -1).
     * @param y_sign Kierunek rysowania w osi Y (1 lub -1).
     * @param window Okno renderowania, na kt�rym kontur ma zosta� narysowany.
     */
    void drawQuarter(int x_sign, int y_sign, sf::RenderWindow& window);

    /**
     * @brief Zwraca pierwszy promie� elipsy (promie� w poziomie).
     * @return Pierwszy promie� elipsy.
     */
    float getR1();

    /**
     * @brief Zwraca drugi promie� elipsy (promie� w pionie).
     * @return Drugi promie� elipsy.
     */
    float getR2();
};
