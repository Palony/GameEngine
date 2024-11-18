#pragma once
#include "Engine.h"

/**
 * @class game
 * @brief Klasa odpowiedzialna za wykrywanie kolizji mi�dzy r�nymi kszta�tami (tr�jk�t, prostok�t, ko�o) a bitmap�.
 *
 * Klasa zawiera funkcje sprawdzaj�ce kolizje dla trzech r�nych kszta�t�w: tr�jk�ta, prostok�ta i ko�a.
 * Kolizje s� sprawdzane na podstawie wsp�rz�dnych wierzcho�k�w kszta�t�w oraz pikseli bitmapy.
 */
class game
{
    Triangle triangle; ///< Obiekt tr�jk�ta, kt�ry b�dzie sprawdzany pod k�tem kolizji.
    Rectangle rectangle; ///< Obiekt prostok�ta, kt�ry b�dzie sprawdzany pod k�tem kolizji.
    Circle circle; ///< Obiekt ko�a, kt�ry b�dzie sprawdzany pod k�tem kolizji.
    Player bitmap; ///< Obiekt bitmapy (gracza), z kt�r� kszta�ty mog� kolidowa�.

public:
    /**
     * @brief Sprawdza, czy kt�rykolwiek z wierzcho�k�w prostok�ta koliduje z bitmap�.
     * @param px Pozycja X punktu prostok�ta.
     * @param py Pozycja Y punktu prostok�ta.
     * @param bitmapX Pozycja X bitmapy.
     * @param bitmapY Pozycja Y bitmapy.
     * @param bitmapImage Obiekt sf::Image reprezentuj�cy bitmap�.
     * @return Zwraca true, je�li wierzcho�ek prostok�ta znajduje si� w obr�bie bitmapy, w przeciwnym razie false.
     */
    bool checkVertexCollisionWithBitmap(float px, float py, float bitmapX, float bitmapY, const sf::Image& bitmapImage);

    /**
     * @brief Sprawdza, czy kt�rykolwiek z wierzcho�k�w tr�jk�ta koliduje z bitmap�.
     * @param triangle Obiekt tr�jk�ta, kt�ry ma by� sprawdzony pod k�tem kolizji.
     * @param bitmap Obiekt gracza (bitmapy), kt�ry mo�e kolidowa� z tr�jk�tem.
     * @param bitmapImage Obiekt sf::Image reprezentuj�cy bitmap�.
     * @return Zwraca true, je�li kt�rykolwiek z wierzcho�k�w tr�jk�ta znajduje si� w obr�bie bitmapy.
     */
    bool checkTriangleCollisionWithBitmap(const Triangle& triangle, Player& bitmap, const sf::Image& bitmapImage);

    /**
     * @brief Sprawdza kolizj� mi�dzy ko�em a bitmap� na poziomie pikseli.
     * @param circle Obiekt ko�a, kt�rego punkty b�d� sprawdzane.
     * @param bitmap Obiekt bitmapy (gracza), z kt�r� ko�o mo�e kolidowa�.
     * @param bitmapImage Obiekt sf::Image reprezentuj�cy bitmap�.
     * @return Zwraca true, je�li kt�rykolwiek piksel ko�a koliduje z bitmap�.
     */
    bool checkPixelCollision(const Circle& circle, Player& bitmap, const sf::Image& bitmapImage);

    /**
     * @brief Sprawdza, czy kt�rykolwiek z wierzcho�k�w prostok�ta koliduje z bitmap�.
     * @param rectangle Obiekt prostok�ta, kt�ry ma by� sprawdzony pod k�tem kolizji.
     * @param bitmap Obiekt gracza (bitmapy), kt�ry mo�e kolidowa� z prostok�tem.
     * @param bitmapImage Obiekt sf::Image reprezentuj�cy bitmap�.
     * @return Zwraca true, je�li kt�rykolwiek z wierzcho�k�w prostok�ta znajduje si� w obr�bie bitmapy.
     */
    bool checkRectangleCollisionWithBitmap(const Rectangle& rectangle, Player& bitmap, const sf::Image& bitmapImage);
};
