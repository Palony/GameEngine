#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "BitmapObject.h"

/**
 * @brief Klasa BitmapHandler odpowiedzialna za zarz¹dzanie obrazami i teksturami bitmapowymi.
 * Klasa ta pozwala na tworzenie, modyfikowanie, wczytywanie, zapisywanie oraz rysowanie bitmap.
 * Dzia³a na obiektach typu sf::Image i sf::Texture, które s¹ wykorzystywane do renderowania bitmapy.
 */
class BitmapHandler : public BitmapObject {
private:
    sf::Image image; /**< Obiekt sf::Image przechowuj¹cy dane bitmapy. */
    sf::Texture texture; /**< Obiekt sf::Texture s³u¿¹cy do renderowania obrazu. */

public:
    /**
     * @brief Konstruktor domyœlny klasy BitmapHandler.
     * Inicjalizuje obiekt bez ¿adnych danych pocz¹tkowych.
     */
    BitmapHandler();

    /**
     * @brief Tworzy now¹ pust¹ bitmapê o zadanych rozmiarach i kolorze t³a.
     * @param width Szerokoœæ bitmapy.
     * @param height Wysokoœæ bitmapy.
     * @param color Kolor t³a bitmapy (domyœlnie przezroczysty).
     * @return Zwraca true, jeœli bitmapa zosta³a pomyœlnie stworzona, false w przeciwnym razie.
     */
    bool create(float width, float height, sf::Color color = sf::Color::Transparent);

    /**
     * @brief Wczytuje bitmapê z pliku.
     * @param filename Œcie¿ka do pliku z bitmap¹.
     * @return Zwraca true, jeœli bitmapa zosta³a pomyœlnie wczytana, false w przeciwnym razie.
     */
    bool loadFromFile(const std::string& filename);

    /**
     * @brief Zapisuje bitmapê do pliku.
     * @param filename Œcie¿ka do pliku, w którym bitmapa ma zostaæ zapisana.
     * @return Zwraca true, jeœli zapis do pliku siê powiód³, false w przeciwnym razie.
     */
    bool saveToFile(const std::string& filename) const;

    /**
     * @brief Usuwa zawartoœæ bitmapy, resetuj¹c obraz i teksturê.
     */
    void clear();

    /**
     * @brief Kopiuje zawartoœæ innej bitmapy do tej bitmapy.
     * Mo¿liwoœæ ograniczenia kopiowania do prostok¹tnego obszaru.
     * @param source Obiekt Ÿród³owy bitmapy, z której ma zostaæ skopiowana zawartoœæ.
     * @param sourceRect Prostok¹tny obszar do skopiowania (jeœli pusty, kopiuje ca³¹ bitmapê).
     */
    void copyFrom(const BitmapHandler& source, sf::IntRect sourceRect = sf::IntRect());

    /**
     * @brief Getter dla sprite'a, który jest u¿ywany do renderowania bitmapy.
     * @return Sta³a referencja do sprite'a.
     */
    const sf::Sprite& getSprite() const;

    /**
     * @brief Getter rozmiaru bitmapy.
     * @return Rozmiar bitmapy jako wektor (szerokoœæ, wysokoœæ).
     */
    sf::Vector2u getSize() const;

    /**
     * @brief Ustawia kolor piksela w danej pozycji.
     * @param x Wspó³rzêdna X piksela.
     * @param y Wspó³rzêdna Y piksela.
     * @param color Kolor, który ma zostaæ przypisany do piksela.
     */
    void setPixel(unsigned int x, unsigned int y, sf::Color color);

    /**
     * @brief Getter koloru piksela w danej pozycji.
     * @param x Wspó³rzêdna X piksela.
     * @param y Wspó³rzêdna Y piksela.
     * @return Kolor piksela w danej pozycji.
     */
    sf::Color getPixel(unsigned int x, unsigned int y) const;

    /**
     * @brief Renderuje bitmapê na ekranie.
     * @param window Okno renderowania, na którym bitmapa jest rysowana.
     */
    void draw(sf::RenderWindow& window) override;

    /**
     * @brief Ustawia pozycjê bitmapy na ekranie.
     * @param x Nowa wspó³rzêdna X.
     * @param y Nowa wspó³rzêdna Y.
     */
    void setPosition(float x, float y);

    /**
     * @brief Przemieszcza bitmapê w dó³, symuluj¹c efekt spadania.
     * @param speed Prêdkoœæ spadania w jednostkach na klatkê.
     */
    void fall(float speed);

    /**
     * @brief Zwraca obraz bitmapy.
     * @return Referencja do obiektu sf::Image reprezentuj¹cego bitmapê.
     */
    const sf::Image& getImage() const;
};

