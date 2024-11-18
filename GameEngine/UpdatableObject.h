#pragma once
#include "GameObject.h"

/**
 * @brief Klasa reprezentuj¹ca obiekt, który mo¿e byæ aktualizowany.
 *
 * Ta klasa jest przeznaczona dla obiektów, które posiadaj¹ funkcjê aktualizacji.
 * Mo¿e byæ u¿ywana jako interfejs dla obiektów, które zmieniaj¹ swoje w³aœciwoœci
 * lub stan w trakcie dzia³ania gry lub programu.
 */
class UpdatableObject
{
    /**
     * @brief Funkcja odpowiedzialna za aktualizacjê obiektu.
     *
     * Ta funkcja powinna byæ zaimplementowana w klasach dziedzicz¹cych, aby
     * okreœliæ, jak obiekt powinien siê zmieniaæ w ka¿dej klatce.
     */
    void update();
};
