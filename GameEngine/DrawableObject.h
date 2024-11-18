#pragma once
#include "GameObject.h"

/**
 * @brief Klasa bazowa dla obiekt�w, kt�re mog� by� rysowane.
 * Klasa ta dziedziczy po klasie `GameObject` i reprezentuje obiekty, kt�re mog� by� wy�wietlane
 * na ekranie w kontek�cie gry. Mo�e by� rozszerzana przez klasy, kt�re implementuj� specyficzn�
 * logik� rysowania.
 */
class DrawableObject : public GameObject
{
};
