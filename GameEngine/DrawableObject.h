#pragma once
#include "GameObject.h"

/**
 * @brief Klasa bazowa dla obiektów, które mog¹ byæ rysowane.
 * Klasa ta dziedziczy po klasie `GameObject` i reprezentuje obiekty, które mog¹ byæ wyœwietlane
 * na ekranie w kontekœcie gry. Mo¿e byæ rozszerzana przez klasy, które implementuj¹ specyficzn¹
 * logikê rysowania.
 */
class DrawableObject : public GameObject
{
};
