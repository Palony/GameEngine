#pragma once
#include "TransformableObject.h"
#include "DrawableObject.h"
#include <SFML/Graphics.hpp>

/**
 * @class ShapeObject
 * @brief Klasa reprezentuj�ca obiekt graficzny, kt�ry mo�e by� zar�wno rysowany, jak i transformowany.
 *
 * Klasa ta dziedziczy po klasach TransformableObject i DrawableObject, co oznacza, �e obiekt mo�e by�
 * poddawany operacjom transformacji (takim jak translacja, rotacja, skalowanie) oraz rysowany na ekranie.
 * Jest to klasa bazowa dla innych obiekt�w, kt�re b�d� posiada�y zar�wno transformacje, jak i mo�liwo��
 * rysowania.
 */
class ShapeObject : public TransformableObject, DrawableObject
{

};
