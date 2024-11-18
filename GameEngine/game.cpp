#include "game.h"

/**
 * @brief Sprawdza, czy którykolwiek z wierzcho³ków prostok¹ta koliduje z bitmap¹.
 * @param px Pozycja X punktu prostok¹ta.
 * @param py Pozycja Y punktu prostok¹ta.
 * @param bitmapX Pozycja X bitmapy.
 * @param bitmapY Pozycja Y bitmapy.
 * @param bitmapImage Obiekt sf::Image reprezentuj¹cy bitmapê.
 * @return Zwraca true, jeœli wierzcho³ek prostok¹ta znajduje siê w obrêbie bitmapy, w przeciwnym razie false.
 */
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

/**
 * @brief Sprawdza, czy którykolwiek z wierzcho³ków trójk¹ta koliduje z bitmap¹.
 * @param triangle Obiekt trójk¹ta, który ma byæ sprawdzony pod k¹tem kolizji.
 * @param bitmap Obiekt gracza (bitmapy), który mo¿e kolidowaæ z trójk¹tem.
 * @param bitmapImage Obiekt sf::Image reprezentuj¹cy bitmapê.
 * @return Zwraca true, jeœli którykolwiek z wierzcho³ków trójk¹ta znajduje siê w obrêbie bitmapy.
 */
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

/**
 * @brief Sprawdza kolizjê miêdzy ko³em a bitmap¹ na poziomie pikseli.
 * @param circle Obiekt ko³a, którego punkty bêd¹ sprawdzane.
 * @param bitmap Obiekt bitmapy (gracza), z któr¹ ko³o mo¿e kolidowaæ.
 * @param bitmapImage Obiekt sf::Image reprezentuj¹cy bitmapê.
 * @return Zwraca true, jeœli którykolwiek piksel ko³a koliduje z bitmap¹.
 */
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

            // Mo¿na dodaæ kod do sprawdzenia kolizji pikseli tutaj (np. sprawdzenie koloru piksela w bitmapie)
        }
    }

    // Brak kolizji
    return false;
}

/**
 * @brief Sprawdza, czy którykolwiek z wierzcho³ków prostok¹ta koliduje z bitmap¹.
 * @param rectangle Obiekt prostok¹ta, który ma byæ sprawdzony pod k¹tem kolizji.
 * @param bitmap Obiekt gracza (bitmapy), który mo¿e kolidowaæ z prostok¹tem.
 * @param bitmapImage Obiekt sf::Image reprezentuj¹cy bitmapê.
 * @return Zwraca true, jeœli którykolwiek z wierzcho³ków prostok¹ta znajduje siê w obrêbie bitmapy.
 */
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
