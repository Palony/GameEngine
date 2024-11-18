#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <stack>

/**
 * @class PrimitiveRenderer
 * @brief Klasa odpowiedzialna za rysowanie i wypełnianie prymitywnych kształtów w oknie SFML.
 */
class PrimitiveRenderer
{
public:
    /**
     * @brief Rysuje linię przy użyciu algorytmu inkrementacyjnego.
     * @param window Okno, w którym linia zostanie narysowana.
     * @param x0 Początkowa współrzędna x.
     * @param y0 Początkowa współrzędna y.
     * @param x1 Końcowa współrzędna x.
     * @param y1 Końcowa współrzędna y.
     */
    void drawIncrementalLine(sf::RenderWindow& window, float x0, float y0, float x1, float y1);

    /**
     * @brief Rysuje okrąg o zadanym promieniu.
     * @param window Okno, w którym okrąg zostanie narysowany.
     * @param x0 Środkowa współrzędna x okręgu.
     * @param y0 Środkowa współrzędna y okręgu.
     * @param R Promień okręgu.
     */
    void drawCircle(sf::RenderWindow& window, float x0, float y0, float R);

    /**
     * @brief Rysuje elipsę o zadanych półosiach.
     * @param window Okno, w którym elipsa zostanie narysowana.
     * @param x0 Środkowa współrzędna x elipsy.
     * @param y0 Środkowa współrzędna y elipsy.
     * @param R1 Długość półosi poziomej.
     * @param R2 Długość półosi pionowej.
     */
    void drawElipse(sf::RenderWindow& window, float x0, float y0, float R1, float R2);

    /**
     * @brief Rysuje ćwiartkę okręgu.
     * @param window Okno, w którym ćwiartka zostanie narysowana.
     * @param x0 Środkowa współrzędna x okręgu.
     * @param y0 Środkowa współrzędna y okręgu.
     * @param R Promień okręgu.
     * @param x_sign Znak współrzędnej x dla kierunku rysowania.
     * @param y_sign Znak współrzędnej y dla kierunku rysowania.
     */
    void drawQuarter(sf::RenderWindow& window, float x0, float y0, float R, int x_sign, int y_sign);

    /**
     * @brief Rysuje ćwiartkę elipsy.
     * @param window Okno, w którym ćwiartka elipsy zostanie narysowana.
     * @param x0 Środkowa współrzędna x elipsy.
     * @param y0 Środkowa współrzędna y elipsy.
     * @param R1 Długość półosi poziomej.
     * @param R2 Długość półosi pionowej.
     * @param x_sign Znak współrzędnej x dla kierunku rysowania.
     * @param y_sign Znak współrzędnej y dla kierunku rysowania.
     */
    void drawQuarterElipse(sf::RenderWindow& window, float x0, float y0, float R1, float R2, int x_sign, int y_sign);

    /**
     * @brief Rysuje trójkąt i opcjonalnie jego kontur.
     * @param window Okno, w którym trójkąt zostanie narysowany.
     * @param x0 Współrzędna x pierwszego wierzchołka.
     * @param y0 Współrzędna y pierwszego wierzchołka.
     * @param x1 Współrzędna x drugiego wierzchołka.
     * @param y1 Współrzędna y drugiego wierzchołka.
     * @param x2 Współrzędna x trzeciego wierzchołka.
     * @param y2 Współrzędna y trzeciego wierzchołka.
     */
    void drawTriangle(sf::RenderWindow& window, float x0, float y0, float x1, float y1, float x2, float y2);

    /**
     * @brief Rysuje prostokąt i opcjonalnie jego kontur.
     * @param window Okno, w którym prostokąt zostanie narysowany.
     * @param w0 Współrzędna x lewego górnego rogu.
     * @param w1 Współrzędna x prawego dolnego rogu.
     * @param h0 Współrzędna y lewego górnego rogu.
     * @param h1 Współrzędna y prawego dolnego rogu.
     */
    void drawRectangle(sf::RenderWindow& window, float w0, float w1, float h0, float h1);


  

private:
    /**
     * @brief Wypełnia prostokąt pikselami.
     * @param window Okno, w którym prostokąt zostanie wypełniony.
     * @param w0 Współrzędna x lewego górnego rogu.
     * @param w1 Współrzędna x prawego dolnego rogu.
     * @param h0 Współrzędna y lewego górnego rogu.
     * @param h1 Współrzędna y prawego dolnego rogu.
     */
    void fillRectangle(sf::RenderWindow& window, float w0, float w1, float h0, float h1);

    /**
     * @brief Wypełnia trójkąt pikselami za pomocą współrzędnych barycentrycznych.
     * @param window Okno, w którym trójkąt zostanie wypełniony.
     * @param x0 Współrzędna x pierwszego wierzchołka.
     * @param y0 Współrzędna y pierwszego wierzchołka.
     * @param x1 Współrzędna x drugiego wierzchołka.
     * @param y1 Współrzędna y drugiego wierzchołka.
     * @param x2 Współrzędna x trzeciego wierzchołka.
     * @param y2 Współrzędna y trzeciego wierzchołka.
     */
    void fillTriangle(sf::RenderWindow& window, float x0, float y0, float x1, float y1, float x2, float y2);

    /**
     * @brief Wypełnia okrąg pikselami.
     * @param window Okno, w którym okrąg zostanie wypełniony.
     * @param x0 Środkowa współrzędna x okręgu.
     * @param y0 Środkowa współrzędna y okręgu.
     * @param R Promień okręgu.
     */
    void fillCircle(sf::RenderWindow& window, float x0, float y0, float R);

    /**
     * @brief Wypełnia elipsę pikselami.
     * @param window Okno, w którym elipsa zostanie wypełniona.
     * @param x0 Środkowa współrzędna x elipsy.
     * @param y0 Środkowa współrzędna y elipsy.
     * @param R1 Długość półosi poziomej.
     * @param R2 Długość półosi pionowej.
     */
    void fillElipse(sf::RenderWindow& window, float x0, float y0, float R1, float R2);
};
