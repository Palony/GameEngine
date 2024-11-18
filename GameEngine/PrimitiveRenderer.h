#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <stack>

class PrimitiveRenderer
{
public:
    void drawIncrementalLine(sf::RenderWindow& window, float x0, float y0, float x1, float y1);
    void drawCircle(sf::RenderWindow& window, float x0, float y0, float R);
    void drawElipse(sf::RenderWindow& window, float x0, float y0, float R1, float R2);
    void drawQuarter(sf::RenderWindow& window, float x0, float y0, float R, int x_sign, int y_sign);
    void drawQuarterElipse(sf::RenderWindow& window, float x0, float y0, float R1, float R2, int x_sign, int y_sign);
    void drawTriangle(sf::RenderWindow& window, float x0, float y0, float x1, float y1, float x2, float y2);
    void drawRectangle(sf::RenderWindow& window, float w0, float w1, float h0, float h1);

  //  void borderFill(sf::RenderWindow& window, int x, int y, sf::Color fillColor, sf::Color boundaryColor);
  //  void floodFill(sf::RenderWindow& window, int x, int y, sf::Color fillColor, sf::Color backgroundColor);
   // void testFillRectangle(sf::RenderWindow& window, float w0, float w1, float h0, float h1, sf::Color fillColor, sf::Color boundaryColor);

private:
    void fillRectangle(sf::RenderWindow& window, float w0, float w1, float h0, float h1);
    void fillTriangle(sf::RenderWindow& window, float x0, float y0, float x1, float y1, float x2, float y2);
    void fillCircle(sf::RenderWindow& window, float x0, float y0, float R);
    void fillElipse(sf::RenderWindow& window, float x0, float y0, float R1, float R2);
};
