#pragma once

/**
 * @class TransformableObject
 * @brief Klasa bazowa dla obiekt�w, kt�re mog� by� transformowane (przesuwane, obracane, skalowane).
 *
 * Klasa ta definiuje interfejs dla obiekt�w, kt�re mog� by� transformowane. Metody `translate()`,
 * `rotate()` i `scale()` s� deklaracjami wirtualnymi, kt�re nale�y zaimplementowa� w klasach pochodnych.
 */
class TransformableObject
{
    /**
     * @brief Przesuni�cie obiektu.
     *
     * Metoda wirtualna, kt�ra b�dzie odpowiedzialna za przesuni�cie obiektu o zadany wektor.
     * Funkcja powinna zosta� zaimplementowana w klasach pochodnych.
     */
    virtual void translate();

    /**
     * @brief Obr�t obiektu.
     *
     * Metoda wirtualna odpowiedzialna za obr�t obiektu o zadany k�t. Implementacja
     * powinna pozwala� na obr�t obiektu wok� wybranego punktu (np. �rodka).
     */
    virtual void rotate();

    /**
     * @brief Skalowanie obiektu.
     *
     * Metoda wirtualna, kt�ra b�dzie odpowiedzialna za zmian� rozmiaru obiektu.
     * Implementacja powinna umo�liwi� skalowanie obiektu w zale�no�ci od wsp�czynnika.
     */
    virtual void scale();
};
