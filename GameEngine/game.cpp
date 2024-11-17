#include "game.h"

bool game::checkVertexCollisionWithBitmap(float px, float py, float bitmapX, float bitmapY, const sf::Image& bitmapImage)
{
    // Pobierz wspó³rzêdne wierzcho³ków prostok¹ta
    float x0 = rectangle.getW0();
    float y0 = rectangle.getH0();
    float x1 = rectangle.getW1();
    float y1 = rectangle.getH0();  // (w1, h0)
    float x2 = rectangle.getW1();
    float y2 = rectangle.getH1();  // (w1, h1)
    float x3 = rectangle.getW0();
    float y3 = rectangle.getH1();  // (w0, h1)

    // Sprawdzamy, czy którykolwiek z wierzcho³ków prostok¹ta le¿y w obrêbie bitmapy
    if (checkVertexCollisionWithBitmap(x0, y0, bitmapX, bitmapY, bitmapImage)) {
        return true;
    }
    if (checkVertexCollisionWithBitmap(x1, y1, bitmapX, bitmapY, bitmapImage)) {
        return true;
    }
    if (checkVertexCollisionWithBitmap(x2, y2, bitmapX, bitmapY, bitmapImage)) {
        return true;
    }
    if (checkVertexCollisionWithBitmap(x3, y3, bitmapX, bitmapY, bitmapImage)) {
        return true;
    }

    // Jeœli ¿aden z wierzcho³ków nie le¿y w obrêbie bitmapy
    return false;
}

bool game::checkTriangleCollisionWithBitmap(const Triangle& triangle, Player& bitmap, const sf::Image& bitmapImage)
{
    // Pobieramy pozycje wierzcho³ków trójk¹ta
    float x0 = triangle.getX0(); // Funkcje do pobierania pozycji wierzcho³ków trójk¹ta
    float y0 = triangle.getY0();

    float x1 = triangle.getX1();
    float y1 = triangle.getY1();

    float x2 = triangle.getX2();
    float y2 = triangle.getY2();

    // Pobieramy pozycjê bitmapy
    float bitmapX = bitmap.getX();
    float bitmapY = bitmap.getY();

    // Sprawdzamy, czy którykolwiek z wierzcho³ków trójk¹ta le¿y w obrêbie bitmapy
    if (checkVertexCollisionWithBitmap(x0, y0, bitmapX, bitmapY, bitmapImage)) {
        return true;
    }
    if (checkVertexCollisionWithBitmap(x1, y1, bitmapX, bitmapY, bitmapImage)) {
        return true;
    }
    if (checkVertexCollisionWithBitmap(x2, y2, bitmapX, bitmapY, bitmapImage)) {
        return true;
    }

    // Jeœli ¿aden wierzcho³ek nie le¿y w bitmapie, zwróæ false
    return false;
}

bool game::checkPixelCollision(const Circle& circle, Player& bitmap, const sf::Image& bitmapImage)
{
    // Pobierz punkty ko³a
    const auto& points = circle.getPoints();

    // Pobierz w³aœciwoœci bitmapy
    float bitmapX = bitmap.getX();  // Obiekt bitmap nie jest const
    float bitmapY = bitmap.getY();
    float bitmapWidth = bitmapImage.getSize().x;
    float bitmapHeight = bitmapImage.getSize().y;

    // Iteracja po punktach ko³a
    for (const auto& point : points) {
        // Pozycja punktu ko³a
        float x = point.x;
        float y = point.y;

        // SprawdŸ, czy punkt mieœci siê w granicach bitmapy
        if (x >= bitmapX && x < bitmapX + bitmapWidth &&
            y >= bitmapY && y < bitmapY + bitmapHeight) {
            // Przelicz wspó³rzêdne na lokalny uk³ad bitmapy
            int localX = static_cast<int>(x - bitmapX);
            int localY = static_cast<int>(y - bitmapY);

        }
    }

    // Brak kolizji
    return false;
}

bool game::checkRectangleCollisionWithBitmap(const Rectangle& rectangle, Player& bitmap, const sf::Image& bitmapImage)
{
    // Pobierz wspó³rzêdne wierzcho³ków prostok¹ta
    float x0 = rectangle.getW0();
    float y0 = rectangle.getH0();
    float x1 = rectangle.getW1();
    float y1 = rectangle.getH0();  // (w1, h0)
    float x2 = rectangle.getW1();
    float y2 = rectangle.getH1();  // (w1, h1)
    float x3 = rectangle.getW0();
    float y3 = rectangle.getH1();  // (w0, h1)

    // Pobierz pozycjê bitmapy
    float bitmapX = bitmap.getX();
    float bitmapY = bitmap.getY();

    // Sprawdzamy, czy którykolwiek z wierzcho³ków prostok¹ta le¿y w obrêbie bitmapy
    if (checkVertexCollisionWithBitmap(x0, y0, bitmapX, bitmapY, bitmapImage)) {
        return true;
    }
    if (checkVertexCollisionWithBitmap(x1, y1, bitmapX, bitmapY, bitmapImage)) {
        return true;
    }
    if (checkVertexCollisionWithBitmap(x2, y2, bitmapX, bitmapY, bitmapImage)) {
        return true;
    }
    if (checkVertexCollisionWithBitmap(x3, y3, bitmapX, bitmapY, bitmapImage)) {
        return true;
    }

    // Jeœli ¿aden z wierzcho³ków nie le¿y w obrêbie bitmapy
    return false;
}