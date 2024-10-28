#include "PrimitiveRenderer.h"

void PrimitiveRenderer::init(sf::RenderWindow& window)
{
    //trójkąt
    vertex.position = sf::Vector2f(10.f, 50.f);
    vertex.color = sf::Color::Red;
    vertex.texCoords = sf::Vector2f(100.f, 100.f);


    sf::VertexArray triangle(sf::Triangles, 3);


    triangle[0].position = sf::Vector2f(10.f, 10.f);
    triangle[1].position = sf::Vector2f(100.f, 10.f);
    triangle[2].position = sf::Vector2f(200.f, 200.f);

    triangle[0].color = sf::Color::Red;
    triangle[1].color = sf::Color::Blue;
    triangle[2].color = sf::Color::Green;
    window.draw(triangle);

    //okrąg
    sf::CircleShape shape(50);
    shape.setPosition(500.f, 100.f);
    shape.setFillColor(sf::Color(250, 0, 50));
    window.draw(shape);
    //prostokąt
    sf::RectangleShape rectangle(sf::Vector2f(120, 50));
    rectangle.setSize(sf::Vector2f(100, 200));
    rectangle.setPosition(300.f, 100.f);
    rectangle.setFillColor(sf::Color(250, 0, 50));
    window.draw(rectangle);
    //wielokąt
    sf::CircleShape octagon(50, 8);
    octagon.setPosition(600.f, 350.f);
    octagon.setFillColor(sf::Color(0, 124, 22));
    window.draw(octagon);
    
    //odcinek SFML

    sf::VertexArray lines(sf::Lines, 2);
    lines[0].position = sf::Vector2f(650.f, 450.f);
    lines[1].position = sf::Vector2f(700.f, 500.f);
    lines[0].color = sf::Color::White;
    lines[1].color = sf::Color::White;

    window.draw(lines);


   
}
// odcinek algorytmem przyrostowym
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

void PrimitiveRenderer::drawCircle(sf::RenderWindow& window, float x0, float y0, float R)
{
    drawQuarter(window, x0, y0, R, 1, -1);   
    drawQuarter(window, x0, y0, R, 1, 1);  
    drawQuarter(window, x0, y0, R, -1, 1); 
    drawQuarter(window, x0, y0, R, -1, -1);  
}

void PrimitiveRenderer::drawElipse(sf::RenderWindow& window, float x0, float y0, float R1, float R2)
{
    drawQuarterElipse(window, x0, y0, R1,R2, 1, -1);
    drawQuarterElipse(window, x0, y0, R1,R2, 1, 1);
    drawQuarterElipse(window, x0, y0, R1,R2, -1, 1);
    drawQuarterElipse(window, x0, y0, R1,R2, -1, -1);
}

void PrimitiveRenderer::drawQuarter(sf::RenderWindow& window, float x0, float y0, float R, int x_sign, int y_sign)
{
    const float M_PI = 3.14159265359f; // PI
    float alfa = 0.0f; // kat
    const float inc = 1.0f / R; //stala którą inkrementujemy kąt

    while (alfa <= M_PI / 2)
    {
        float x = x0 + x_sign * R * cos(alfa);  
        float y = y0 + y_sign * R * sin(alfa);

        sf::Vertex pixel(sf::Vector2f(std::round(x), std::round(y)), sf::Color::White);
        window.draw(&pixel, 1, sf::Points);

        alfa += inc;
    }
}

void PrimitiveRenderer::drawQuarterElipse(sf::RenderWindow& window, float x0, float y0, float R1, float R2, int x_sign, int y_sign)
{
    const float M_PI = 3.14159265359f; // PI
    float alfa = 0.0f; // kat 
    float inc;

    //Ustawienie inc dla większego promienia
    if (R1 > R2) {
        inc = 1.0f / R1;
    }
    else {
        inc = 1.0f / R2;
    }

    while (alfa <= M_PI / 2)
    {
        float x = x0 + x_sign * R1 * cos(alfa);
        float y = y0 + y_sign * R2 * sin(alfa);

        sf::Vertex pixel(sf::Vector2f(std::round(x), std::round(y)), sf::Color::White);
        window.draw(&pixel, 1, sf::Points);

        alfa += inc;
    }
}




