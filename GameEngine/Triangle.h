#pragma once
#include "DrawableObject.h"
#include "TransformableObject.h"
#include "PrimitiveRenderer.h"
#include "LineSegment.h"
#include <SFML/Graphics.hpp>
#include <vector>

/**
 * @brief Klasa reprezentuj¹ca trójk¹t, który jest obiektem rysowanym i transformowalnym.
 *
 * Klasa umo¿liwia rysowanie trójk¹ta na ekranie, jego translacjê, rotacjê oraz resetowanie pozycji.
 * Trójk¹t jest reprezentowany przez trzy boki (segmenty linii), które s¹ obiektami klasy `LineSegment`.
 */
class Triangle : public DrawableObject, TransformableObject
{
private:
    LineSegment side1; ///< Pierwszy bok trójk¹ta
    LineSegment side2; ///< Drugi bok trójk¹ta
    LineSegment side3; ///< Trzeci bok trójk¹ta

    float rotationAngle = 0.0f; ///< K¹t obrotu trójk¹ta w stopniach

    // Wspó³rzêdne pocz¹tkowe wierzcho³ków trójk¹ta
    float x0_init, y0_init, x1_init, y1_init, x2_init, y2_init;

    // Wspó³rzêdne aktualne wierzcho³ków trójk¹ta
    float x0, y0, x1, y1, x2, y2;

    sf::Color fillColor; ///< Kolor wype³nienia trójk¹ta

public:
    /**
     * @brief Konstruktor klasy Triangle.
     *
     * Inicjalizuje trójk¹t z okreœlonymi wspó³rzêdnymi wierzcho³ków oraz kolorem wype³nienia.
     * @param x0 Wspó³rzêdna X pierwszego wierzcho³ka.
     * @param y0 Wspó³rzêdna Y pierwszego wierzcho³ka.
     * @param x1 Wspó³rzêdna X drugiego wierzcho³ka.
     * @param y1 Wspó³rzêdna Y drugiego wierzcho³ka.
     * @param x2 Wspó³rzêdna X trzeciego wierzcho³ka.
     * @param y2 Wspó³rzêdna Y trzeciego wierzcho³ka.
     * @param color Kolor wype³nienia trójk¹ta (domyœlnie bia³y).
     */
    Triangle(float x0, float y0, float x1, float y1, float x2, float y2, sf::Color color = sf::Color::White);

    // Gettery dla wspó³rzêdnych pocz¹tkowych wierzcho³ków trójk¹ta
    /**
     * @brief Zwraca wspó³rzêdn¹ X pierwszego wierzcho³ka trójk¹ta.
     * @return Wspó³rzêdna X pierwszego wierzcho³ka.
     */
    float getX0() const;

    /**
     * @brief Zwraca wspó³rzêdn¹ Y pierwszego wierzcho³ka trójk¹ta.
     * @return Wspó³rzêdna Y pierwszego wierzcho³ka.
     */
    float getY0() const;

    /**
     * @brief Zwraca wspó³rzêdn¹ X drugiego wierzcho³ka trójk¹ta.
     * @return Wspó³rzêdna X drugiego wierzcho³ka.
     */
    float getX1() const;

    /**
     * @brief Zwraca wspó³rzêdn¹ Y drugiego wierzcho³ka trójk¹ta.
     * @return Wspó³rzêdna Y drugiego wierzcho³ka.
     */
    float getY1() const;

    /**
     * @brief Zwraca wspó³rzêdn¹ X trzeciego wierzcho³ka trójk¹ta.
     * @return Wspó³rzêdna X trzeciego wierzcho³ka.
     */
    float getX2() const;

    /**
     * @brief Zwraca wspó³rzêdn¹ Y trzeciego wierzcho³ka trójk¹ta.
     * @return Wspó³rzêdna Y trzeciego wierzcho³ka.
     */
    float getY2() const;

    /**
     * @brief Rysuje trójk¹t na oknie renderowania.
     *
     * Rysuje trójk¹t poprzez znalezienie prostok¹ta otaczaj¹cego trójk¹t
     * i sprawdzanie, które punkty w tym prostok¹cie znajduj¹ siê wewn¹trz trójk¹ta.
     * Dodatkowo, opcjonalnie rysuje boki trójk¹ta.
     * @param window Okno renderowania SFML, w którym trójk¹t zostanie narysowany.
     */
    void draw(sf::RenderWindow& window);

    /**
     * @brief Translacja trójk¹ta w osi Y (przemieszczenie).
     *
     * Przesuwa trójk¹t o zadan¹ wartoœæ w osi Y oraz obraca go wokó³ œrodka masy.
     * Jeœli trójk¹t przekroczy doln¹ krawêdŸ ekranu, jego pozycja zostaje zresetowana.
     * @param window Okno renderowania SFML, w którym trójk¹t jest wyœwietlany.
     * @param ty Wartoœæ przesuniêcia w osi Y.
     */
    void fall(sf::RenderWindow& window, float ty);

    /**
     * @brief Resetuje pozycjê trójk¹ta do jego pocz¹tkowych wspó³rzêdnych.
     *
     * Przywraca trójk¹t do pozycji zdefiniowanej przez pocz¹tkowe wspó³rzêdne
     * wierzcho³ków oraz resetuje k¹t obrotu.
     */
    void resetPosition();

    /**
     * @brief Aktualizuje bie¿¹ce wspó³rzêdne wierzcho³ków na podstawie pozycji linii.
     *
     * Funkcja ta aktualizuje wspó³rzêdne wierzcho³ków trójk¹ta, odwo³uj¹c siê
     * do po³o¿enia jego boków (segmentów linii).
     */
    void updatePoints();
};
