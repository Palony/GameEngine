#pragma once
#include "TransformableObject.h"
#include "DrawableObject.h"

/**
 * @brief Klasa reprezentuj�ca obiekt kszta�tu, dziedzicz�cy po TransformableObject i DrawableObject.
 *
 * Klasa ta stanowi baz� dla obiekt�w, kt�re mog� by� przekszta�cane (np. przesuwane, obracane) i rysowane na ekranie.
 */
class ShapeObject : public TransformableObject, DrawableObject
{
    // Klasa jest pusta, poniewa� nie dodajemy dodatkowych funkcji ani danych.
};
