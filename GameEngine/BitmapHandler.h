#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "BitmapObject.h"

/**
 * @brief Klasa BitmapHandler odpowiedzialna za zarz�dzanie obrazami i teksturami bitmapowymi.
 * Klasa ta pozwala na tworzenie, modyfikowanie, wczytywanie, zapisywanie oraz rysowanie bitmap.
 * Dzia�a na obiektach typu sf::Image i sf::Texture, kt�re s� wykorzystywane do renderowania bitmapy.
 */
class BitmapHandler : public BitmapObject {
private:
    sf::Image image; /**< Obiekt sf::Image przechowuj�cy dane bitmapy. */
    sf::Texture texture; /**< Obiekt sf::Texture s�u��cy do renderowania obrazu. */

public:
    /**
     * @brief Konstruktor domy�lny klasy BitmapHandler.
     * Inicjalizuje obiekt bez �adnych danych pocz�tkowych.
     */
    BitmapHandler();

    /**
     * @brief Tworzy now� pust� bitmap� o zadanych rozmiarach i kolorze t�a.
     * @param width Szeroko�� bitmapy.
     * @param height Wysoko�� bitmapy.
     * @param color Kolor t�a bitmapy (domy�lnie przezroczysty).
     * @return Zwraca true, je�li bitmapa zosta�a pomy�lnie stworzona, false w przeciwnym razie.
     */
    bool create(float width, float height, sf::Color color = sf::Color::Transparent);

    /**
     * @brief Wczytuje bitmap� z pliku.
     * @param filename �cie�ka do pliku z bitmap�.
     * @return Zwraca true, je�li bitmapa zosta�a pomy�lnie wczytana, false w przeciwnym razie.
     */
    bool loadFromFile(const std::string& filename);

    /**
     * @brief Zapisuje bitmap� do pliku.
     * @param filename �cie�ka do pliku, w kt�rym bitmapa ma zosta� zapisana.
     * @return Zwraca true, je�li zapis do pliku si� powi�d�, false w przeciwnym razie.
     */
    bool saveToFile(const std::string& filename) const;

    /**
     * @brief Usuwa zawarto�� bitmapy, resetuj�c obraz i tekstur�.
     */
    void clear();

    /**
     * @brief Kopiuje zawarto�� innej bitmapy do tej bitmapy.
     * Mo�liwo�� ograniczenia kopiowania do prostok�tnego obszaru.
     * @param source Obiekt �r�d�owy bitmapy, z kt�rej ma zosta� skopiowana zawarto��.
     * @param sourceRect Prostok�tny obszar do skopiowania (je�li pusty, kopiuje ca�� bitmap�).
     */
    void copyFrom(const BitmapHandler& source, sf::IntRect sourceRect = sf::IntRect());

    /**
     * @brief Getter dla sprite'a, kt�ry jest u�ywany do renderowania bitmapy.
     * @return Sta�a referencja do sprite'a.
     */
    const sf::Sprite& getSprite() const;

    /**
     * @brief Getter rozmiaru bitmapy.
     * @return Rozmiar bitmapy jako wektor (szeroko��, wysoko��).
     */
    sf::Vector2u getSize() const;

    /**
     * @brief Ustawia kolor piksela w danej pozycji.
     * @param x Wsp�rz�dna X piksela.
     * @param y Wsp�rz�dna Y piksela.
     * @param color Kolor, kt�ry ma zosta� przypisany do piksela.
     */
    void setPixel(unsigned int x, unsigned int y, sf::Color color);

    /**
     * @brief Getter koloru piksela w danej pozycji.
     * @param x Wsp�rz�dna X piksela.
     * @param y Wsp�rz�dna Y piksela.
     * @return Kolor piksela w danej pozycji.
     */
    sf::Color getPixel(unsigned int x, unsigned int y) const;

    /**
     * @brief Renderuje bitmap� na ekranie.
     * @param window Okno renderowania, na kt�rym bitmapa jest rysowana.
     */
    void draw(sf::RenderWindow& window) override;

    /**
     * @brief Ustawia pozycj� bitmapy na ekranie.
     * @param x Nowa wsp�rz�dna X.
     * @param y Nowa wsp�rz�dna Y.
     */
    void setPosition(float x, float y);

    /**
     * @brief Przemieszcza bitmap� w d�, symuluj�c efekt spadania.
     * @param speed Pr�dko�� spadania w jednostkach na klatk�.
     */
    void fall(float speed);

    /**
     * @brief Zwraca obraz bitmapy.
     * @return Referencja do obiektu sf::Image reprezentuj�cego bitmap�.
     */
    const sf::Image& getImage() const;
};

