#pragma once
#include "Engine.h"

/**
 * @class game
 * @brief Klasa odpowiedzialna za wykrywanie kolizji miêdzy ró¿nymi kszta³tami (trójk¹t, prostok¹t, ko³o) a bitmap¹.
 *
 * Klasa zawiera funkcje sprawdzaj¹ce kolizje dla trzech ró¿nych kszta³tów: trójk¹ta, prostok¹ta i ko³a.
 * Kolizje s¹ sprawdzane na podstawie wspó³rzêdnych wierzcho³ków kszta³tów oraz pikseli bitmapy.
 */
class game
{
    Triangle triangle; ///< Obiekt trójk¹ta, który bêdzie sprawdzany pod k¹tem kolizji.
    Rectangle rectangle; ///< Obiekt prostok¹ta, który bêdzie sprawdzany pod k¹tem kolizji.
    Circle circle; ///< Obiekt ko³a, który bêdzie sprawdzany pod k¹tem kolizji.
    Player bitmap; ///< Obiekt bitmapy (gracza), z któr¹ kszta³ty mog¹ kolidowaæ.

public:
    /**
     * @brief Sprawdza, czy którykolwiek z wierzcho³ków prostok¹ta koliduje z bitmap¹.
     * @param px Pozycja X punktu prostok¹ta.
     * @param py Pozycja Y punktu prostok¹ta.
     * @param bitmapX Pozycja X bitmapy.
     * @param bitmapY Pozycja Y bitmapy.
     * @param bitmapImage Obiekt sf::Image reprezentuj¹cy bitmapê.
     * @return Zwraca true, jeœli wierzcho³ek prostok¹ta znajduje siê w obrêbie bitmapy, w przeciwnym razie false.
     */
    bool checkVertexCollisionWithBitmap(float px, float py, float bitmapX, float bitmapY, const sf::Image& bitmapImage);

    /**
     * @brief Sprawdza, czy którykolwiek z wierzcho³ków trójk¹ta koliduje z bitmap¹.
     * @param triangle Obiekt trójk¹ta, który ma byæ sprawdzony pod k¹tem kolizji.
     * @param bitmap Obiekt gracza (bitmapy), który mo¿e kolidowaæ z trójk¹tem.
     * @param bitmapImage Obiekt sf::Image reprezentuj¹cy bitmapê.
     * @return Zwraca true, jeœli którykolwiek z wierzcho³ków trójk¹ta znajduje siê w obrêbie bitmapy.
     */
    bool checkTriangleCollisionWithBitmap(const Triangle& triangle, Player& bitmap, const sf::Image& bitmapImage);

    /**
     * @brief Sprawdza kolizjê miêdzy ko³em a bitmap¹ na poziomie pikseli.
     * @param circle Obiekt ko³a, którego punkty bêd¹ sprawdzane.
     * @param bitmap Obiekt bitmapy (gracza), z któr¹ ko³o mo¿e kolidowaæ.
     * @param bitmapImage Obiekt sf::Image reprezentuj¹cy bitmapê.
     * @return Zwraca true, jeœli którykolwiek piksel ko³a koliduje z bitmap¹.
     */
    bool checkPixelCollision(const Circle& circle, Player& bitmap, const sf::Image& bitmapImage);

    /**
     * @brief Sprawdza, czy którykolwiek z wierzcho³ków prostok¹ta koliduje z bitmap¹.
     * @param rectangle Obiekt prostok¹ta, który ma byæ sprawdzony pod k¹tem kolizji.
     * @param bitmap Obiekt gracza (bitmapy), który mo¿e kolidowaæ z prostok¹tem.
     * @param bitmapImage Obiekt sf::Image reprezentuj¹cy bitmapê.
     * @return Zwraca true, jeœli którykolwiek z wierzcho³ków prostok¹ta znajduje siê w obrêbie bitmapy.
     */
    bool checkRectangleCollisionWithBitmap(const Rectangle& rectangle, Player& bitmap, const sf::Image& bitmapImage);
};
