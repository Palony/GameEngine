#include "Triangle.h"

Triangle::Triangle(float x0, float y0, float x1, float y1, float x2, float y2)
    : x0_init(x0), y0_init(y0), x1_init(x1), y1_init(y1), x2_init(x2), y2_init(y2)
{
    // Inicjalizacja wspó³rzêdnych pocz¹tkowych
    x0 = x0_init;
    y0 = y0_init;
    x1 = x1_init;
    y1 = y1_init;
    x2 = x2_init;
    y2 = y2_init;

    // Inicjalizacja segmentów linii
    side1.set_top(x0, y0);
    side1.set_bottom(x1, y1);

    side2.set_top(x1, y1);
    side2.set_bottom(x2, y2);

    side3.set_top(x2, y2);
    side3.set_bottom(x0, y0);
}

float Triangle::getX0() const {
    return x0;
}

float Triangle::getY0() const {
    return y0;
}

float Triangle::getX1() const {
    return x1;
}

float Triangle::getY1() const {
    return y1;
}

float Triangle::getX2() const {
    return x2;
}

float Triangle::getY2() const {
    return y2;
}

void Triangle::draw(sf::RenderWindow& window)
{
    side1.draw_line(window);
    side2.draw_line(window);
    side3.draw_line(window);
}

void Triangle::fall(sf::RenderWindow& window, float ty)
{
    updatePoints();
    // Translacja
    side1.translation(0, ty);
    side2.translation(0, ty);
    side3.translation(0, ty);

    // Aktualizacja po³o¿enia wierzcho³ków po translacji
    updatePoints();

    // Rotacja
    rotationAngle += 1.0f;
    if (rotationAngle >= 360.0f)
        rotationAngle -= 360.0f;
    updatePoints();

    // Wspó³rzêdne œrodka masy trójk¹ta
    float centerX = (side1.get_top().x + side2.get_top().x + side3.get_top().x) / 3.0f;
    float centerY = (side1.get_top().y + side2.get_top().y + side3.get_top().y) / 3.0f;

    // Rotacja wokó³ œrodka masy
    side1.rotationXY(1.0f, centerX, centerY);
    side2.rotationXY(1.0f, centerX, centerY);
    side3.rotationXY(1.0f, centerX, centerY);

    // Aktualizacja punktów po rotacji
    updatePoints();

    // Sprawdzanie, czy trójk¹t przekroczy³ ekran
    float windowHeight = window.getSize().y;
    float maxY = std::max({
        side1.get_top().y, side1.get_bottom().y,
        side2.get_top().y, side2.get_bottom().y,
        side3.get_top().y, side3.get_bottom().y
        });

    if (maxY > windowHeight)
    {
        resetPosition(); // Jeœli trójk¹t opuœci³ ekran, resetuj pozycjê
        updatePoints();
    }
}

void Triangle::resetPosition()
{
    // Przywrócenie pocz¹tkowej pozycji wierzcho³ków
    side1.set_top(x0_init, y0_init);
    side1.set_bottom(x1_init, y1_init);

    side2.set_top(x1_init, y1_init);
    side2.set_bottom(x2_init, y2_init);

    side3.set_top(x2_init, y2_init);
    side3.set_bottom(x0_init, y0_init);

    // Resetowanie k¹ta obrotu
    rotationAngle = 0.0f;
}

void Triangle::updatePoints()
{
    // Aktualizowanie bie¿¹cych pozycji wierzcho³ków na podstawie pozycji linii
    x0 = side1.get_top().x;
    y0 = side1.get_top().y;

    x1 = side2.get_top().x;
    y1 = side2.get_top().y;

    x2 = side3.get_top().x;
    y2 = side3.get_top().y;
}