#pragma once
#include "TransformableObject.h"
#include "DrawableObject.h"
#include <SFML/Graphics.hpp>

/**
 * @class ShapeObject
 * @brief Klasa reprezentuj¹ca obiekt graficzny, który mo¿e byæ zarówno rysowany, jak i transformowany.
 *
 * Klasa ta dziedziczy po klasach TransformableObject i DrawableObject, co oznacza, ¿e obiekt mo¿e byæ
 * poddawany operacjom transformacji (takim jak translacja, rotacja, skalowanie) oraz rysowany na ekranie.
 * Jest to klasa bazowa dla innych obiektów, które bêd¹ posiada³y zarówno transformacje, jak i mo¿liwoœæ
 * rysowania.
 */
class ShapeObject : public TransformableObject, DrawableObject
{

};
