#include "game.h"

bool game::checkVertexCollisionWithBitmap(float px, float py, float bitmapX, float bitmapY, const sf::Image& bitmapImage)
{
    // Pobierz wsp�rz�dne wierzcho�k�w prostok�ta
    float x0 = rectangle.getW0();
    float y0 = rectangle.getH0();
    float x1 = rectangle.getW1();
    float y1 = rectangle.getH0();  // (w1, h0)
    float x2 = rectangle.getW1();
    float y2 = rectangle.getH1();  // (w1, h1)
    float x3 = rectangle.getW0();
    float y3 = rectangle.getH1();  // (w0, h1)

    // Sprawdzamy, czy kt�rykolwiek z wierzcho�k�w prostok�ta le�y w obr�bie bitmapy
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

    // Je�li �aden z wierzcho�k�w nie le�y w obr�bie bitmapy
    return false;
}

bool game::checkTriangleCollisionWithBitmap(const Triangle& triangle, Player& bitmap, const sf::Image& bitmapImage)
{
    // Pobieramy pozycje wierzcho�k�w tr�jk�ta
    float x0 = triangle.getX0(); // Funkcje do pobierania pozycji wierzcho�k�w tr�jk�ta
    float y0 = triangle.getY0();

    float x1 = triangle.getX1();
    float y1 = triangle.getY1();

    float x2 = triangle.getX2();
    float y2 = triangle.getY2();

    // Pobieramy pozycj� bitmapy
    float bitmapX = bitmap.getX();
    float bitmapY = bitmap.getY();

    // Sprawdzamy, czy kt�rykolwiek z wierzcho�k�w tr�jk�ta le�y w obr�bie bitmapy
    if (checkVertexCollisionWithBitmap(x0, y0, bitmapX, bitmapY, bitmapImage)) {
        return true;
    }
    if (checkVertexCollisionWithBitmap(x1, y1, bitmapX, bitmapY, bitmapImage)) {
        return true;
    }
    if (checkVertexCollisionWithBitmap(x2, y2, bitmapX, bitmapY, bitmapImage)) {
        return true;
    }

    // Je�li �aden wierzcho�ek nie le�y w bitmapie, zwr�� false
    return false;
}

bool game::checkPixelCollision(const Circle& circle, Player& bitmap, const sf::Image& bitmapImage)
{
    // Pobierz punkty ko�a
    const auto& points = circle.getPoints();

    // Pobierz w�a�ciwo�ci bitmapy
    float bitmapX = bitmap.getX();  // Obiekt bitmap nie jest const
    float bitmapY = bitmap.getY();
    float bitmapWidth = bitmapImage.getSize().x;
    float bitmapHeight = bitmapImage.getSize().y;

    // Iteracja po punktach ko�a
    for (const auto& point : points) {
        // Pozycja punktu ko�a
        float x = point.x;
        float y = point.y;

        // Sprawd�, czy punkt mie�ci si� w granicach bitmapy
        if (x >= bitmapX && x < bitmapX + bitmapWidth &&
            y >= bitmapY && y < bitmapY + bitmapHeight) {
            // Przelicz wsp�rz�dne na lokalny uk�ad bitmapy
            int localX = static_cast<int>(x - bitmapX);
            int localY = static_cast<int>(y - bitmapY);

        }
    }

    // Brak kolizji
    return false;
}

bool game::checkRectangleCollisionWithBitmap(const Rectangle& rectangle, Player& bitmap, const sf::Image& bitmapImage)
{
    // Pobierz wsp�rz�dne wierzcho�k�w prostok�ta
    float x0 = rectangle.getW0();
    float y0 = rectangle.getH0();
    float x1 = rectangle.getW1();
    float y1 = rectangle.getH0();  // (w1, h0)
    float x2 = rectangle.getW1();
    float y2 = rectangle.getH1();  // (w1, h1)
    float x3 = rectangle.getW0();
    float y3 = rectangle.getH1();  // (w0, h1)

    // Pobierz pozycj� bitmapy
    float bitmapX = bitmap.getX();
    float bitmapY = bitmap.getY();

    // Sprawdzamy, czy kt�rykolwiek z wierzcho�k�w prostok�ta le�y w obr�bie bitmapy
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

    // Je�li �aden z wierzcho�k�w nie le�y w obr�bie bitmapy
    return false;
}