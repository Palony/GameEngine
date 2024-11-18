#pragma once
#include "GameObject.h"

/**
 * @brief Klasa reprezentuj�ca obiekt, kt�ry mo�e by� aktualizowany.
 *
 * Ta klasa jest przeznaczona dla obiekt�w, kt�re posiadaj� funkcj� aktualizacji.
 * Mo�e by� u�ywana jako interfejs dla obiekt�w, kt�re zmieniaj� swoje w�a�ciwo�ci
 * lub stan w trakcie dzia�ania gry lub programu.
 */
class UpdatableObject
{
    /**
     * @brief Funkcja odpowiedzialna za aktualizacj� obiektu.
     *
     * Ta funkcja powinna by� zaimplementowana w klasach dziedzicz�cych, aby
     * okre�li�, jak obiekt powinien si� zmienia� w ka�dej klatce.
     */
    void update();
};
