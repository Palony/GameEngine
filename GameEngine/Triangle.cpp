#include "Triangle.h"




void Triangle::draw(sf::RenderWindow& window)
{
    side1.draw_line(window);
    side2.draw_line(window);
    side3.draw_line(window);
}
void Triangle::fall(sf::RenderWindow& window, float ty)
{
  
    side1.translation(0, ty);
    side2.translation(0, ty);
    side3.translation(0, ty);

    
    rotationAngle += 1.0f; 

    
    if (rotationAngle >= 360.0f)
        rotationAngle -= 360.0f;

    
    float x0 = (side1.get_top().x + side2.get_top().x + side3.get_top().x) / 3.0f;
    float y0 = (side1.get_top().y + side2.get_top().y + side3.get_top().y) / 3.0f;

   
    side1.rotationXY(1.0f, x0, y0); 
    side2.rotationXY(1.0f, x0, y0);
    side3.rotationXY(1.0f, x0, y0);

   
    float windowHeight = window.getSize().y;

   
    float maxY = std::max({
        side1.get_top().y, side1.get_bottom().y,
        side2.get_top().y, side2.get_bottom().y,
        side3.get_top().y, side3.get_bottom().y
        });

 
    if (maxY > windowHeight)
    {
        resetPosition();
    }
}
void Triangle::resetPosition()
{
    side1.set_top(x0_init, y0_init);
    side1.set_bottom(x1_init, y1_init);

    side2.set_top(x1_init, y1_init);
    side2.set_bottom(x2_init, y2_init);

    side3.set_top(x2_init, y2_init);
    side3.set_bottom(x0_init, y0_init);

 
    rotationAngle = 0.0f;
}