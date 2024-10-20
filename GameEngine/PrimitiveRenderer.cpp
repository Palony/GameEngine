#include "PrimitiveRenderer.h"

void PrimitiveRenderer::init(sf::RenderWindow& window)
{
    //trójk¹t
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

    //okr¹g
    sf::CircleShape shape(50);
    shape.setPosition(500.f, 100.f);
    shape.setFillColor(sf::Color(250, 0, 50));
    window.draw(shape);
    //prostok¹t
    sf::RectangleShape rectangle(sf::Vector2f(120, 50));
    rectangle.setSize(sf::Vector2f(100, 200));
    rectangle.setPosition(300.f, 100.f);
    rectangle.setFillColor(sf::Color(250, 0, 50));
    window.draw(rectangle);
    //wielok¹t
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
    float m = dy / dx;

    // punkt 0
    float y = y0;


    for (float x = x0; x <= x1; ++x)
    {

        sf::Vertex pixel(sf::Vector2f(x, std::round(y)), sf::Color::White);
        window.draw(&pixel, 1, sf::Points);


        y += m;
    }
}
