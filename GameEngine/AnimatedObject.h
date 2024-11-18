#pragma once
#include "BitmapObject.h"

/**
 * @brief Klasa reprezentuj¹ca obiekt z animacj¹.
 * Klasa ta jest dziedziczona przez inne klasy, które implementuj¹ ró¿ne rodzaje animacji.
 * Jest to klasa bazowa, której zadaniem jest zapewnienie interfejsu dla metod animuj¹cych obiekty.
 */
class AnimatedObject : public BitmapObject
{
public:
    /**
     * @brief Metoda odpowiedzialna za animowanie obiektu.
     * W tej metodzie mo¿e byæ zaimplementowana logika odpowiedzialna za zmianê stanu obiektu
     * w trakcie animacji. Jest to metoda wirtualna, która powinna byæ przes³oniêta w klasach pochodnych.
     */
    virtual void animate();
};
