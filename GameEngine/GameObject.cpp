#include "GameObject.h"

/**
 * @class GameObject
 * @brief Klasa reprezentuj�ca obiekt gry, kt�ry przechowuje i zarz�dza wsp�rz�dnymi obiektu.
 *
 * Klasa ta umo�liwia ustawianie i pobieranie wsp�rz�dnych obiektu gry.
 * Zapewnia metody do manipulacji pozycj� obiektu w przestrzeni 2D.
 */
void GameObject::setXY(float x, float y)
{
    this->cords.x = x; ///< Ustawia warto�� wsp�rz�dnej X.
    this->cords.y = y; ///< Ustawia warto�� wsp�rz�dnej Y.
}

/**
 * @brief Ustawia wsp�rz�dn� X obiektu.
 * @param x Nowa warto�� wsp�rz�dnej X.
 */
void GameObject::setX(float x)
{
    this->cords.x = x; ///< Ustawia warto�� wsp�rz�dnej X.
}

/**
 * @brief Ustawia wsp�rz�dn� Y obiektu.
 * @param y Nowa warto�� wsp�rz�dnej Y.
 */
void GameObject::setY(float y)
{
    this->cords.y = y; ///< Ustawia warto�� wsp�rz�dnej Y.
}

/**
 * @brief Pobiera wsp�rz�dne obiektu.
 * @return Wsp�rz�dne obiektu w postaci obiektu sf::Vector2f.
 */
sf::Vector2f GameObject::getXY()
{
    return cords; ///< Zwraca wsp�rz�dne obiektu jako sf::Vector2f.
}

/**
 * @brief Pobiera wsp�rz�dn� X obiektu.
 * @return Warto�� wsp�rz�dnej X obiektu.
 */
float GameObject::getX()
{
    return cords.x; ///< Zwraca warto�� wsp�rz�dnej X.
}

/**
 * @brief Pobiera wsp�rz�dn� Y obiektu.
 * @return Warto�� wsp�rz�dnej Y obiektu.
 */
float GameObject::getY()
{
    return cords.y; ///< Zwraca warto�� wsp�rz�dnej Y.
}
