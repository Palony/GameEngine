#pragma once
#include "BitmapObject.h"

/**
 * @brief Klasa reprezentuj�ca obiekt z animacj�.
 * Klasa ta jest dziedziczona przez inne klasy, kt�re implementuj� r�ne rodzaje animacji.
 * Jest to klasa bazowa, kt�rej zadaniem jest zapewnienie interfejsu dla metod animuj�cych obiekty.
 */
class AnimatedObject : public BitmapObject
{
public:
    /**
     * @brief Metoda odpowiedzialna za animowanie obiektu.
     * W tej metodzie mo�e by� zaimplementowana logika odpowiedzialna za zmian� stanu obiektu
     * w trakcie animacji. Jest to metoda wirtualna, kt�ra powinna by� przes�oni�ta w klasach pochodnych.
     */
    virtual void animate();
};
