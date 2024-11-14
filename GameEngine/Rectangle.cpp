#include "Rectangle.h"

void Rectangle::draw(sf::RenderWindow& window)
{
    primitiveRenderer.drawIncrementalLine(window, w0, h0, w1, h0);
    primitiveRenderer.drawIncrementalLine(window, w1, h0, w1, h1);
    primitiveRenderer.drawIncrementalLine(window, w1, h1, w0, h1);
    primitiveRenderer.drawIncrementalLine(window, w0, h1, w0, h0);
}
