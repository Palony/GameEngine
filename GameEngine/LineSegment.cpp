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

