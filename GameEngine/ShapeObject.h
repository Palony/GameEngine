#pragma once
#include "TransformableObject.h"
#include "DrawableObject.h"

/**
 * @brief Klasa reprezentuj¹ca obiekt kszta³tu, dziedzicz¹cy po TransformableObject i DrawableObject.
 *
 * Klasa ta stanowi bazê dla obiektów, które mog¹ byæ przekszta³cane (np. przesuwane, obracane) i rysowane na ekranie.
 */
class ShapeObject : public TransformableObject, DrawableObject
{
    // Klasa jest pusta, poniewa¿ nie dodajemy dodatkowych funkcji ani danych.
};
