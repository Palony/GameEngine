#include "Triangle.h"

void Triangle::draw(sf::RenderWindow& window)
{
    primitiveRenderer.drawIncrementalLine(window, x0, y0, x1, y1);
    primitiveRenderer.drawIncrementalLine(window, x1, y1, x2, y2);
    primitiveRenderer.drawIncrementalLine(window, x2, y2, x0, y0);
}
