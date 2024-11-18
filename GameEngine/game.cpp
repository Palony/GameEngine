#include "game.h"

/**
 * @brief Sprawdza, czy kt�rykolwiek z wierzcho�k�w prostok�ta koliduje z bitmap�.
 * @param px Pozycja X punktu prostok�ta.
 * @param py Pozycja Y punktu prostok�ta.
 * @param bitmapX Pozycja X bitmapy.
 * @param bitmapY Pozycja Y bitmapy.
 * @param bitmapImage Obiekt sf::Image reprezentuj�cy bitmap�.
 * @return Zwraca true, je�li wierzcho�ek prostok�ta znajduje si� w obr�bie bitmapy, w przeciwnym razie false.
 */
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

/**
 * @brief Sprawdza, czy kt�rykolwiek z wierzcho�k�w tr�jk�ta koliduje z bitmap�.
 * @param triangle Obiekt tr�jk�ta, kt�ry ma by� sprawdzony pod k�tem kolizji.
 * @param bitmap Obiekt gracza (bitmapy), kt�ry mo�e kolidowa� z tr�jk�tem.
 * @param bitmapImage Obiekt sf::Image reprezentuj�cy bitmap�.
 * @return Zwraca true, je�li kt�rykolwiek z wierzcho�k�w tr�jk�ta znajduje si� w obr�bie bitmapy.
 */
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

/**
 * @brief Sprawdza kolizj� mi�dzy ko�em a bitmap� na poziomie pikseli.
 * @param circle Obiekt ko�a, kt�rego punkty b�d� sprawdzane.
 * @param bitmap Obiekt bitmapy (gracza), z kt�r� ko�o mo�e kolidowa�.
 * @param bitmapImage Obiekt sf::Image reprezentuj�cy bitmap�.
 * @return Zwraca true, je�li kt�rykolwiek piksel ko�a koliduje z bitmap�.
 */
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

            // Mo�na doda� kod do sprawdzenia kolizji pikseli tutaj (np. sprawdzenie koloru piksela w bitmapie)
        }
    }

    // Brak kolizji
    return false;
}

/**
 * @brief Sprawdza, czy kt�rykolwiek z wierzcho�k�w prostok�ta koliduje z bitmap�.
 * @param rectangle Obiekt prostok�ta, kt�ry ma by� sprawdzony pod k�tem kolizji.
 * @param bitmap Obiekt gracza (bitmapy), kt�ry mo�e kolidowa� z prostok�tem.
 * @param bitmapImage Obiekt sf::Image reprezentuj�cy bitmap�.
 * @return Zwraca true, je�li kt�rykolwiek z wierzcho�k�w prostok�ta znajduje si� w obr�bie bitmapy.
 */
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
