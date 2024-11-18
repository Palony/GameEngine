#include "PrimitiveRenderer.h"
using namespace std;


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

void PrimitiveRenderer::drawRectangle(sf::RenderWindow& window, float w0, float w1, float h0, float h1)
{
    fillRectangle(window, w0, w1, h0, h1);

    // Opcjonalnie rysuj kontur prostokąta
    drawIncrementalLine(window, w0, h0, w1, h0);
    drawIncrementalLine(window, w1, h0, w1, h1);
    drawIncrementalLine(window, w1, h1, w0, h1);
    drawIncrementalLine(window, w0, h1, w0, h0);
}

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

void PrimitiveRenderer::drawTriangle(sf::RenderWindow& window, float x0, float y0, float x1, float y1, float x2, float y2)
{
    fillTriangle(window, x0, y0, x1, y1, x2, y2);

    // Opcjonalnie rysuj kontur trójkąta
    drawIncrementalLine(window, x0, y0, x1, y1);
    drawIncrementalLine(window, x1, y1, x2, y2);
    drawIncrementalLine(window, x2, y2, x0, y0);
}

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

void PrimitiveRenderer::drawCircle(sf::RenderWindow& window, float x0, float y0, float R)
{
    fillCircle(window, x0, y0, R);

    // Opcjonalnie rysuj kontur okręgu
    drawQuarter(window, x0, y0, R, 1, -1);
    drawQuarter(window, x0, y0, R, 1, 1);
    drawQuarter(window, x0, y0, R, -1, 1);
    drawQuarter(window, x0, y0, R, -1, -1);
}

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

void PrimitiveRenderer::drawElipse(sf::RenderWindow& window, float x0, float y0, float R1, float R2)
{
    fillElipse(window, x0, y0, R1, R2);

    
    drawQuarterElipse(window, x0, y0, R1, R2, 1, -1);
    drawQuarterElipse(window, x0, y0, R1, R2, 1, 1);
    drawQuarterElipse(window, x0, y0, R1, R2, -1, 1);
    drawQuarterElipse(window, x0, y0, R1, R2, -1, -1);
}

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
/*

void PrimitiveRenderer::borderFill(sf::RenderWindow& window, int x, int y, sf::Color fillColor, sf::Color boundaryColor)
{
    // Tworzymy teksturę i obraz do przechwycenia zawartości okna
    sf::Texture texture;
    texture.create(window.getSize().x, window.getSize().y);
    texture.update(window);
    sf::Image image = texture.copyToImage();

    std::stack<sf::Vector2i> pixelStack;
    pixelStack.push(sf::Vector2i(x, y));

    while (!pixelStack.empty())
    {
        sf::Vector2i p = pixelStack.top();
        pixelStack.pop();

        if (p.x < 0 || p.y < 0 || p.x >= static_cast<int>(image.getSize().x) || p.y >= static_cast<int>(image.getSize().y))
            continue;

        sf::Color currentColor = image.getPixel(p.x, p.y);
        if (currentColor != boundaryColor && currentColor != fillColor)
        {
            image.setPixel(p.x, p.y, fillColor);

            pixelStack.push(sf::Vector2i(p.x + 1, p.y));
            pixelStack.push(sf::Vector2i(p.x - 1, p.y));
            pixelStack.push(sf::Vector2i(p.x, p.y + 1));
            pixelStack.push(sf::Vector2i(p.x, p.y - 1));
        }
    }

    // Rysujemy zaktualizowany obraz na oknie
    sf::Texture updatedTexture;
    updatedTexture.loadFromImage(image);
    sf::Sprite sprite(updatedTexture);
    window.draw(sprite);
}

void PrimitiveRenderer::floodFill(sf::RenderWindow& window, int x, int y, sf::Color fillColor, sf::Color backgroundColor)
{
    // Tworzymy teksturę i obraz do przechwycenia zawartości okna
    sf::Texture texture;
    texture.create(window.getSize().x, window.getSize().y);
    texture.update(window);
    sf::Image image = texture.copyToImage();

    std::stack<sf::Vector2i> pixelStack;
    pixelStack.push(sf::Vector2i(x, y));

    while (!pixelStack.empty())
    {
        sf::Vector2i p = pixelStack.top();
        pixelStack.pop();

        if (p.x < 0 || p.y < 0 || p.x >= static_cast<int>(image.getSize().x) || p.y >= static_cast<int>(image.getSize().y))
            continue;

        sf::Color currentColor = image.getPixel(p.x, p.y);
        if (currentColor == backgroundColor && currentColor != fillColor)
        {
            image.setPixel(p.x, p.y, fillColor);

            pixelStack.push(sf::Vector2i(p.x + 1, p.y));
            pixelStack.push(sf::Vector2i(p.x - 1, p.y));
            pixelStack.push(sf::Vector2i(p.x, p.y + 1));
            pixelStack.push(sf::Vector2i(p.x, p.y - 1));
        }
    }

    // Rysujemy zaktualizowany obraz na oknie
    sf::Texture updatedTexture;
    updatedTexture.loadFromImage(image);
    sf::Sprite sprite(updatedTexture);
    window.draw(sprite);
}

void PrimitiveRenderer::testFillRectangle(sf::RenderWindow& window, float w0, float w1, float h0, float h1, sf::Color fillColor, sf::Color boundaryColor)
{
    // Rysujemy kontur prostokąta
    sf::Color originalColor = sf::Color::Black; // Zakładamy czarny kolor granicy
    drawRectangle(window, w0, w1, h0, h1);

    // Aktualizujemy okno, aby upewnić się, że prostokąt jest narysowany
    window.display();

    // Wykonujemy wypełnienie graniczne
    int seedX = static_cast<int>((w0 + w1) / 2);
    int seedY = static_cast<int>((h0 + h1) / 2);
    borderFill(window, seedX, seedY, fillColor, boundaryColor);
}
*/






