#include "LineSegment.h"

void LineSegment::set_top(float x, float y)
{
    top.setXY(x, y);
}

void LineSegment::set_bottom(float x, float y)
{
    bottom.setXY(x, y);
}


sf::Vector2f LineSegment::get_top()
{
    return top.getXY();
}

sf::Vector2f LineSegment::get_bottom()
{
    return bottom.getXY();
}

void LineSegment::draw_line(sf::RenderWindow& window)
{
    primitiveRenderer.drawIncrementalLine(window, top.getX(), top.getY(), bottom.getX(), bottom.getY());
}

void LineSegment::translation(float tx, float ty)
{
    top.setXY(top.getX() + tx, top.getY() + ty);
    bottom.setXY(bottom.getX() + tx, bottom.getY() + ty);
   
}

void LineSegment::rotation00(sf::RenderWindow& window, float alfa)
{
    float x0 = 400;
    float y0 = 300;
    alfa = alfa * M_PI / 180;


    float x2 = x0 + (top.getX() - x0) * cos(alfa) - (top.getY() - y0) * sin(alfa);
    float y2 = y0 + (top.getX() - x0) * sin(alfa) + (top.getY() - y0) * cos(alfa);
    float x1 = x0 + (bottom.getX() - x0) * cos(alfa) - (bottom.getY() - y0) * sin(alfa);
    float y1 = y0 + (bottom.getX() - x0) * sin(alfa) + (bottom.getY() - y0) * cos(alfa);
    primitiveRenderer.drawIncrementalLine(window, x1, y1, x2, y2);

}

void LineSegment::rotationXY(float alfa, float x0, float y0)
{
    alfa = alfa * M_PI / 180.0f;

    float x2 = x0 + (top.getX() - x0) * cos(alfa) - (top.getY() - y0) * sin(alfa);
    float y2 = y0 + (top.getX() - x0) * sin(alfa) + (top.getY() - y0) * cos(alfa);
    float x1 = x0 + (bottom.getX() - x0) * cos(alfa) - (bottom.getY() - y0) * sin(alfa);
    float y1 = y0 + (bottom.getX() - x0) * sin(alfa) + (bottom.getY() - y0) * cos(alfa);

   
    top.setXY(x2, y2);
    bottom.setXY(x1, y1);
}


void LineSegment::scaling00(sf::RenderWindow& window, float k)
{
    float x0 = 400;
    float y0 = 300;




    float x2 = top.getX() * k + (1 - k) * x0;
    float y2 = top.getY() * k + (1 - k) * y0;
    float x1 = bottom.getX()* k + (1 - k) * x0;
    float y1 = bottom.getY() * k + (1 - k) * y0;
    primitiveRenderer.drawIncrementalLine(window, x1, y1, x2, y2);

}

void LineSegment::scalingXY(sf::RenderWindow& window, float k, float x0, float y0)
{
    float x2 = top.getX() * k + (1 - k) * x0;
    float y2 = top.getY() * k + (1 - k) * y0;
    float x1 = bottom.getX() * k + (1 - k) * x0;
    float y1 = bottom.getY() * k + (1 - k) * y0;
    primitiveRenderer.drawIncrementalLine(window, x1, y1, x2, y2);

}

