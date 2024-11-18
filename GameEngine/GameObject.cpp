#include "GameObject.h"

/**
 * @class GameObject
 * @brief Klasa reprezentuj¹ca obiekt gry, który przechowuje i zarz¹dza wspó³rzêdnymi obiektu.
 *
 * Klasa ta umo¿liwia ustawianie i pobieranie wspó³rzêdnych obiektu gry.
 * Zapewnia metody do manipulacji pozycj¹ obiektu w przestrzeni 2D.
 */
void GameObject::setXY(float x, float y)
{
    this->cords.x = x; ///< Ustawia wartoœæ wspó³rzêdnej X.
    this->cords.y = y; ///< Ustawia wartoœæ wspó³rzêdnej Y.
}

/**
 * @brief Ustawia wspó³rzêdn¹ X obiektu.
 * @param x Nowa wartoœæ wspó³rzêdnej X.
 */
void GameObject::setX(float x)
{
    this->cords.x = x; ///< Ustawia wartoœæ wspó³rzêdnej X.
}

/**
 * @brief Ustawia wspó³rzêdn¹ Y obiektu.
 * @param y Nowa wartoœæ wspó³rzêdnej Y.
 */
void GameObject::setY(float y)
{
    this->cords.y = y; ///< Ustawia wartoœæ wspó³rzêdnej Y.
}

/**
 * @brief Pobiera wspó³rzêdne obiektu.
 * @return Wspó³rzêdne obiektu w postaci obiektu sf::Vector2f.
 */
sf::Vector2f GameObject::getXY()
{
    return cords; ///< Zwraca wspó³rzêdne obiektu jako sf::Vector2f.
}

/**
 * @brief Pobiera wspó³rzêdn¹ X obiektu.
 * @return Wartoœæ wspó³rzêdnej X obiektu.
 */
float GameObject::getX()
{
    return cords.x; ///< Zwraca wartoœæ wspó³rzêdnej X.
}

/**
 * @brief Pobiera wspó³rzêdn¹ Y obiektu.
 * @return Wartoœæ wspó³rzêdnej Y obiektu.
 */
float GameObject::getY()
{
    return cords.y; ///< Zwraca wartoœæ wspó³rzêdnej Y.
}
