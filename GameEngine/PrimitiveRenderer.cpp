#include "PrimitiveRenderer.h"
using namespace std;

/**
 * @brief Rysuje linię przy użyciu algorytmu przyrostowego.
 * @param window Okno renderowania SFML.
 * @param x0 Początkowa współrzędna X.
 * @param y0 Początkowa współrzędna Y.
 * @param x1 Końcowa współrzędna X.
 * @param y1 Końcowa współrzędna Y.
 */
void PrimitiveRenderer::drawIncrementalLine(sf::RenderWindow& window, float x0, float y0, float x1, float y1)
{
    
    float dx = x1 - x0;
    float dy = y1 - y0;

    
    if (dx == 0)  
    {
        if (y0 > y1) std::swap(y0, y1);  
        for (float y = y0; y <= y1; ++y)
        {
            sf::Vertex pixel(sf::Vector2f(x0, y), sf::Color::White);  
            window.draw(&pixel, 1, sf::Points);
        }
        return;  
    }

    
    if (dy == 0) 
    {
        if (x0 > x1) std::swap(x0, x1);  
        for (float x = x0; x <= x1; ++x)
        {
            sf::Vertex pixel(sf::Vector2f(x, y0), sf::Color::White);  
            window.draw(&pixel, 1, sf::Points);
        }
        return;  
    }

   
    float m = dy / dx;

    
    if (x0 > x1)
    {
        std::swap(x0, x1);
        std::swap(y0, y1);
        dx = x1 - x0;
        dy = y1 - y0;
        m = dy / dx;
    }

    
    float y = y0;

    
    for (float x = x0; x <= x1; ++x)
    {
        sf::Vertex pixel(sf::Vector2f(x, std::round(y)), sf::Color::White);  
        window.draw(&pixel, 1, sf::Points);
        y += m;  
    }
}
/**
 * @brief Rysuje prostokąt w oknie SFML.
 * @param window Okno renderowania SFML.
 * @param w0 Współrzędna X lewego górnego rogu.
 * @param w1 Współrzędna X prawego dolnego rogu.
 * @param h0 Współrzędna Y lewego górnego rogu.
 * @param h1 Współrzędna Y prawego dolnego rogu.
 */
void PrimitiveRenderer::drawRectangle(sf::RenderWindow& window, float w0, float w1, float h0, float h1)
{
    fillRectangle(window, w0, w1, h0, h1);

    // Opcjonalnie rysuj kontur prostokąta
    drawIncrementalLine(window, w0, h0, w1, h0);
    drawIncrementalLine(window, w1, h0, w1, h1);
    drawIncrementalLine(window, w1, h1, w0, h1);
    drawIncrementalLine(window, w0, h1, w0, h0);
}
/**
 * @brief Wypełnia prostokąt w oknie SFML.
 * @param window Okno renderowania SFML.
 * @param w0 Współrzędna X lewego górnego rogu.
 * @param w1 Współrzędna X prawego dolnego rogu.
 * @param h0 Współrzędna Y lewego górnego rogu.
 * @param h1 Współrzędna Y prawego dolnego rogu.
 */
void PrimitiveRenderer::fillRectangle(sf::RenderWindow& window, float w0, float w1, float h0, float h1)
{
    // Upewniamy się, że współrzędne są uporządkowane
    if (w0 > w1) std::swap(w0, w1);
    if (h0 > h1) std::swap(h0, h1);

    for (int y = static_cast<int>(h0); y <= static_cast<int>(h1); ++y)
    {
        for (int x = static_cast<int>(w0); x <= static_cast<int>(w1); ++x)
        {
            sf::Vertex pixel(sf::Vector2f(static_cast<float>(x), static_cast<float>(y)), sf::Color::White);
            window.draw(&pixel, 1, sf::Points);
        }
    }
}
/**
 * @brief Rysuje trójkąt w oknie SFML.
 * @param window Okno renderowania SFML.
 * @param x0 Współrzędna X pierwszego wierzchołka.
 * @param y0 Współrzędna Y pierwszego wierzchołka.
 * @param x1 Współrzędna X drugiego wierzchołka.
 * @param y1 Współrzędna Y drugiego wierzchołka.
 * @param x2 Współrzędna X trzeciego wierzchołka.
 * @param y2 Współrzędna Y trzeciego wierzchołka.
 */
void PrimitiveRenderer::drawTriangle(sf::RenderWindow& window, float x0, float y0, float x1, float y1, float x2, float y2)
{
    fillTriangle(window, x0, y0, x1, y1, x2, y2);

    // Opcjonalnie rysuj kontur trójkąta
    drawIncrementalLine(window, x0, y0, x1, y1);
    drawIncrementalLine(window, x1, y1, x2, y2);
    drawIncrementalLine(window, x2, y2, x0, y0);
}
/**
 * @brief Wypełnia trójkąt w oknie SFML.
 * @param window Okno renderowania SFML.
 * @param x0 Współrzędna X pierwszego wierzchołka.
 * @param y0 Współrzędna Y pierwszego wierzchołka.
 * @param x1 Współrzędna X drugiego wierzchołka.
 * @param y1 Współrzędna Y drugiego wierzchołka.
 * @param x2 Współrzędna X trzeciego wierzchołka.
 * @param y2 Współrzędna Y trzeciego wierzchołka.
 */
void PrimitiveRenderer::fillTriangle(sf::RenderWindow& window, float x0, float y0, float x1, float y1, float x2, float y2)
{
    // Znajdź prostokąt otaczający trójkąt
    int minX = static_cast<int>(std::floor(std::min({ x0, x1, x2 })));
    int maxX = static_cast<int>(std::ceil(std::max({ x0, x1, x2 })));
    int minY = static_cast<int>(std::floor(std::min({ y0, y1, y2 })));
    int maxY = static_cast<int>(std::ceil(std::max({ y0, y1, y2 })));

    // Iteruj po pikselach w prostokącie otaczającym
    for (int y = minY; y <= maxY; ++y)
    {
        for (int x = minX; x <= maxX; ++x)
        {
            // Sprawdź, czy punkt (x, y) leży wewnątrz trójkąta
            float denominator = ((y1 - y2) * (x0 - x2) + (x2 - x1) * (y0 - y2));

            if (denominator == 0)
                continue; // Unikaj dzielenia przez zero

            float alpha = ((y1 - y2) * (x - x2) + (x2 - x1) * (y - y2)) / denominator;
            float beta = ((y2 - y0) * (x - x2) + (x0 - x2) * (y - y2)) / denominator;
            float gamma = 1.0f - alpha - beta;

            if (alpha >= 0 && beta >= 0 && gamma >= 0)
            {
                sf::Vertex pixel(sf::Vector2f(static_cast<float>(x), static_cast<float>(y)), sf::Color::White);
                window.draw(&pixel, 1, sf::Points);
            }
        }
    }
}
/**
 * @brief Rysuje okrąg w oknie SFML.
 * @param window Okno renderowania SFML.
 * @param x0 Współrzędna X środka okręgu.
 * @param y0 Współrzędna Y środka okręgu.
 * @param R Promień okręgu.
 */
void PrimitiveRenderer::drawCircle(sf::RenderWindow& window, float x0, float y0, float R)
{
    fillCircle(window, x0, y0, R);

    // Opcjonalnie rysuj kontur okręgu
    drawQuarter(window, x0, y0, R, 1, -1);
    drawQuarter(window, x0, y0, R, 1, 1);
    drawQuarter(window, x0, y0, R, -1, 1);
    drawQuarter(window, x0, y0, R, -1, -1);
}
/**
 * @brief Wypełnia okrąg w oknie SFML.
 * @param window Okno renderowania SFML.
 * @param x0 Współrzędna X środka okręgu.
 * @param y0 Współrzędna Y środka okręgu.
 * @param R Promień okręgu.
 */
void PrimitiveRenderer::fillCircle(sf::RenderWindow& window, float x0, float y0, float R)
{
    int minX = static_cast<int>(std::floor(x0 - R));
    int maxX = static_cast<int>(std::ceil(x0 + R));
    int minY = static_cast<int>(std::floor(y0 - R));
    int maxY = static_cast<int>(std::ceil(y0 + R));

    for (int y = minY; y <= maxY; ++y)
    {
        for (int x = minX; x <= maxX; ++x)
        {
            float dx = x - x0;
            float dy = y - y0;
            if (dx * dx + dy * dy <= R * R)
            {
                sf::Vertex pixel(sf::Vector2f(static_cast<float>(x), static_cast<float>(y)), sf::Color::White);
                window.draw(&pixel, 1, sf::Points);
            }
        }
    }
}
/**
 * @brief Rysuje elipsę w oknie SFML.
 * @param window Okno renderowania SFML.
 * @param x0 Współrzędna X środka elipsy.
 * @param y0 Współrzędna Y środka elipsy.
 * @param R1 Promień poziomy elipsy.
 * @param R2 Promień pionowy elipsy.
 */
void PrimitiveRenderer::drawElipse(sf::RenderWindow& window, float x0, float y0, float R1, float R2)
{
    fillElipse(window, x0, y0, R1, R2);

    
    drawQuarterElipse(window, x0, y0, R1, R2, 1, -1);
    drawQuarterElipse(window, x0, y0, R1, R2, 1, 1);
    drawQuarterElipse(window, x0, y0, R1, R2, -1, 1);
    drawQuarterElipse(window, x0, y0, R1, R2, -1, -1);
}
/**
 * @brief Wypełnia elipsę w oknie SFML.
 * @param window Okno renderowania SFML.
 * @param x0 Współrzędna X środka elipsy.
 * @param y0 Współrzędna Y środka elipsy.
 * @param R1 Promień poziomy elipsy.
 * @param R2 Promień pionowy elipsy.
 */
void PrimitiveRenderer::fillElipse(sf::RenderWindow& window, float x0, float y0, float R1, float R2)
{
    int minX = static_cast<int>(std::floor(x0 - R1));
    int maxX = static_cast<int>(std::ceil(x0 + R1));
    int minY = static_cast<int>(std::floor(y0 - R2));
    int maxY = static_cast<int>(std::ceil(y0 + R2));

    for (int y = minY; y <= maxY; ++y)
    {
        for (int x = minX; x <= maxX; ++x)
        {
            float dx = x - x0;
            float dy = y - y0;
            if ((dx * dx) / (R1 * R1) + (dy * dy) / (R2 * R2) <= 1.0f)
            {
                sf::Vertex pixel(sf::Vector2f(static_cast<float>(x), static_cast<float>(y)), sf::Color::White);
                window.draw(&pixel, 1, sf::Points);
            }
        }
    }
}
/**
 * @brief Rysuje ćwiartkę okręgu w oknie SFML.
 * @param window Okno renderowania SFML.
 * @param x0 Współrzędna X środka okręgu.
 * @param y0 Współrzędna Y środka okręgu.
 * @param R Promień okręgu.
 * @param x_sign Znak określający, w którą stronę rysować w osi X.
 * @param y_sign Znak określający, w którą stronę rysować w osi Y.
 */
void PrimitiveRenderer::drawQuarter(sf::RenderWindow& window, float x0, float y0, float R, int x_sign, int y_sign)
{
    const float M_PI = 3.14159265359f; // PI
    float alfa = 0.0f; // kąt
    const float inc = 1.0f / R; // stała, którą inkrementujemy kąt

    while (alfa <= M_PI / 2)
    {
        float x = x0 + x_sign * R * cos(alfa);
        float y = y0 + y_sign * R * sin(alfa);

        sf::Vertex pixel(sf::Vector2f(std::round(x), std::round(y)), sf::Color::Black);
        window.draw(&pixel, 1, sf::Points);

        alfa += inc;
    }
}
/**
 * @brief Rysuje ćwiartkę elipsy w oknie SFML.
 * @param window Okno renderowania SFML.
 * @param x0 Współrzędna X środka elipsy.
 * @param y0 Współrzędna Y środka elipsy.
 * @param R1 Promień poziomy elipsy.
 * @param R2 Promień pionowy elipsy.
 * @param x_sign Znak określający, w którą stronę rysować w osi X.
 * @param y_sign Znak określający, w którą stronę rysować w osi Y.
 */
void PrimitiveRenderer::drawQuarterElipse(sf::RenderWindow& window, float x0, float y0, float R1, float R2, int x_sign, int y_sign)
{
    const float M_PI = 3.14159265359f; // PI
    float alfa = 0.0f; // kąt
    float inc = 1.0f / std::max(R1, R2);

    while (alfa <= M_PI / 2)
    {
        float x = x0 + x_sign * R1 * cos(alfa);
        float y = y0 + y_sign * R2 * sin(alfa);

        sf::Vertex pixel(sf::Vector2f(std::round(x), std::round(y)), sf::Color::Black);
        window.draw(&pixel, 1, sf::Points);

        alfa += inc;
    }
}






