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

void PrimitiveRenderer::drawTriangle(sf::RenderWindow& window, float x0, float y0, float x1, float y1, float x2, float y2)
{
    drawIncrementalLine(window, x0, y0, x1, y1);
    drawIncrementalLine(window, x1, y1, x2, y2);
    drawIncrementalLine(window, x2, y2, x0, y0);

}

void PrimitiveRenderer::drawRectangle(sf::RenderWindow& window, float w0, float w1, float h0, float h1)
{
    drawIncrementalLine(window, w0, h0, w1, h0);
    drawIncrementalLine(window, w1, h0, w1, h1);
    drawIncrementalLine(window, w1, h1, w0, h1);
    drawIncrementalLine(window, w0, h1, w0, h0);
}

void PrimitiveRenderer::drawPolygon(sf::RenderWindow& window, int angles) {
    if (angles < 3) {
       cerr << "Wielokat musi miec co najmniej 3 katy" <<endl;
        return;
    }


    int* arrayX = new int[angles];
    int* arrayY = new int[angles];
   

    arrayX[0] = 50;
    arrayX[1] = 100;
    arrayX[2] = 150;
    arrayX[3] = 100;
    arrayX[4] = 50;

    arrayY[0] = 100;
    arrayY[1] = 100;
    arrayY[2] = 75;
    arrayY[3] = 50;
    arrayY[4] = 50;


    for (int i = 0; i < angles - 1; ++i) {
        drawIncrementalLine(window, arrayX[i], arrayY[i], arrayX[i + 1], arrayY[i + 1]);
    }

    drawIncrementalLine(window, arrayX[angles - 1], arrayY[angles - 1], arrayX[0], arrayY[0]);

   
    delete[] arrayX;
    delete[] arrayY;
}






