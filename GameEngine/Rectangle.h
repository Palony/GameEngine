#pragma once
#include "DrawableObject.h"
#include "TransformableObject.h"
#include "PrimitiveRenderer.h"
#include "LineSegment.h"
#include <SFML/Graphics.hpp> 

/**
 * @brief Klasa reprezentuj¹ca prostok¹t, dziedzicz¹ca po DrawableObject i TransformableObject.
 */
class Rectangle : public DrawableObject, TransformableObject
{
private:
    LineSegment side1; ///< Bok 1 prostok¹ta
    LineSegment side2; ///< Bok 2 prostok¹ta
    LineSegment side3; ///< Bok 3 prostok¹ta
    LineSegment side4; ///< Bok 4 prostok¹ta

    float w0_init, h0_init, w1_init, h1_init; ///< Wspó³rzêdne pocz¹tkowe prostok¹ta
    float w0, h0, w1, h1; ///< Aktualne wspó³rzêdne prostok¹ta
    float rotationAngle = 0.0f; ///< Aktualny k¹t obrotu prostok¹ta
    sf::Color fillColor; ///< Kolor wype³nienia prostok¹ta

public:
    /**
     * @brief Konstruktor klasy Rectangle.
     * @param w0 Pocz¹tkowa wspó³rzêdna x lewego górnego rogu.
     * @param h0 Pocz¹tkowa wspó³rzêdna y lewego górnego rogu.
     * @param w1 Pocz¹tkowa wspó³rzêdna x prawego dolnego rogu.
     * @param h1 Pocz¹tkowa wspó³rzêdna y prawego dolnego rogu.
     * @param color Kolor wype³nienia prostok¹ta. Domyœlnie bia³y.
     */
    Rectangle(float w0, float h0, float w1, float h1, sf::Color color = sf::Color::White);

    /**
     * @brief Rysuje prostok¹t w podanym oknie SFML.
     * @param window Okno, w którym prostok¹t zostanie narysowany.
     */
    void draw(sf::RenderWindow& window);

    /**
     * @brief Powoduje "opadanie" prostok¹ta w dó³ o podan¹ wartoœæ przesuniêcia.
     * @param window Okno SFML, w którym prostok¹t jest rysowany.
     * @param ty Wartoœæ przesuniêcia w osi y.
     */
    void fall(sf::RenderWindow& window, float ty);

    /**
     * @brief Resetuje pozycjê prostok¹ta do wartoœci pocz¹tkowych.
     */
    void resetPosition();

    /**
     * @brief Aktualizuje bie¿¹ce wspó³rzêdne prostok¹ta na podstawie jego boków.
     */
    void updatePoints();

    /**
     * @brief Zwraca wspó³rzêdn¹ x lewego górnego rogu prostok¹ta.
     * @return Wspó³rzêdna x lewego górnego rogu.
     */
    float getW0() const;

    /**
     * @brief Zwraca wspó³rzêdn¹ y lewego górnego rogu prostok¹ta.
     * @return Wspó³rzêdna y lewego górnego rogu.
     */
    float getH0() const;

    /**
     * @brief Zwraca wspó³rzêdn¹ x prawego dolnego rogu prostok¹ta.
     * @return Wspó³rzêdna x prawego dolnego rogu.
     */
    float getW1() const;

    /**
     * @brief Zwraca wspó³rzêdn¹ y prawego dolnego rogu prostok¹ta.
     * @return Wspó³rzêdna y prawego dolnego rogu.
     */
    float getH1() const;
};
