#pragma once

/**
 * @class TransformableObject
 * @brief Klasa bazowa dla obiektów, które mog¹ byæ transformowane (przesuwane, obracane, skalowane).
 *
 * Klasa ta definiuje interfejs dla obiektów, które mog¹ byæ transformowane. Metody `translate()`,
 * `rotate()` i `scale()` s¹ deklaracjami wirtualnymi, które nale¿y zaimplementowaæ w klasach pochodnych.
 */
class TransformableObject
{
    /**
     * @brief Przesuniêcie obiektu.
     *
     * Metoda wirtualna, która bêdzie odpowiedzialna za przesuniêcie obiektu o zadany wektor.
     * Funkcja powinna zostaæ zaimplementowana w klasach pochodnych.
     */
    virtual void translate();

    /**
     * @brief Obrót obiektu.
     *
     * Metoda wirtualna odpowiedzialna za obrót obiektu o zadany k¹t. Implementacja
     * powinna pozwalaæ na obrót obiektu wokó³ wybranego punktu (np. œrodka).
     */
    virtual void rotate();

    /**
     * @brief Skalowanie obiektu.
     *
     * Metoda wirtualna, która bêdzie odpowiedzialna za zmianê rozmiaru obiektu.
     * Implementacja powinna umo¿liwiæ skalowanie obiektu w zale¿noœci od wspó³czynnika.
     */
    virtual void scale();
};
