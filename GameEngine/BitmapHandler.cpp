#include "BitmapHandler.h"

// Konstruktor domyœlny
/**
 * @brief Konstruktor klasy BitmapHandler.
 * Inicjalizuje obiekt bez ¿adnych pocz¹tkowych danych.
 */
BitmapHandler::BitmapHandler() = default;

/**
 * @brief Tworzy now¹ pust¹ bitmapê o podanych rozmiarach i kolorze t³a.
 * @param width Szerokoœæ nowej bitmapy.
 * @param height Wysokoœæ nowej bitmapy.
 * @param color Kolor t³a bitmapy.
 * @return Zwraca true, jeœli bitmapa zosta³a pomyœlnie stworzona, false w przeciwnym razie.
 */
bool BitmapHandler::create(float width, float height, sf::Color color) {
    image.create(width, height, color);
    return texture.loadFromImage(image); // Aktualizacja tekstury z nowego obrazu
}

/**
 * @brief Wczytuje bitmapê z pliku.
 * @param filename Œcie¿ka do pliku z bitmap¹.
 * @return Zwraca true, jeœli bitmapa zosta³a pomyœlnie wczytana, false w przeciwnym razie.
 */
bool BitmapHandler::loadFromFile(const std::string& filename) {
    if (image.loadFromFile(filename)) {
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        return true;
    }
    return false;
}

/**
 * @brief Zapisuje bitmapê do pliku.
 * @param filename Œcie¿ka do pliku, w którym bitmapa ma zostaæ zapisana.
 * @return Zwraca true, jeœli zapis do pliku siê powiód³, false w przeciwnym razie.
 */
bool BitmapHandler::saveToFile(const std::string& filename) const {
    return image.saveToFile(filename);
}

/**
 * @brief Usuwa zawartoœæ bitmapy.
 * Czyœci obraz i resetuje teksturê oraz sprite.
 */
void BitmapHandler::clear() {
    image.create(0, 0);
    texture = sf::Texture();
    sprite = sf::Sprite();
}

/**
 * @brief Kopiuje zawartoœæ innej bitmapy do tej bitmapy.
 * Mo¿liwoœæ ograniczenia kopiowania do prostok¹tnego obszaru.
 * @param source Obiekt Ÿród³owy bitmapy, z której ma zostaæ skopiowana zawartoœæ.
 * @param sourceRect Prostok¹tny obszar do skopiowania (jeœli pusty, kopiuje ca³¹ bitmapê).
 */
void BitmapHandler::copyFrom(const BitmapHandler& source, sf::IntRect sourceRect) {
    if (sourceRect == sf::IntRect()) {
        image.copy(source.image, 0, 0);
    }
    else {
        image.copy(source.image, 0, 0, sourceRect);
    }
    texture.loadFromImage(image);
    sprite.setTexture(texture);
}

/**
 * @brief Getter dla sprite'a, który jest u¿ywany do renderowania bitmapy.
 * @return Sta³a referencja do sprite'a.
 */
const sf::Sprite& BitmapHandler::getSprite() const {
    return sprite;
}

/**
 * @brief Getter rozmiaru bitmapy.
 * @return Rozmiar bitmapy jako wektor (szerokoœæ, wysokoœæ).
 */
sf::Vector2u BitmapHandler::getSize() const {
    return image.getSize();
}

/**
 * @brief Ustawia kolor piksela w danej pozycji.
 * @param x Wspó³rzêdna X piksela.
 * @param y Wspó³rzêdna Y piksela.
 * @param color Kolor, który ma zostaæ przypisany do piksela.
 */
void BitmapHandler::setPixel(unsigned int x, unsigned int y, sf::Color color) {
    image.setPixel(x, y, color);
    texture.update(image);
}

/**
 * @brief Getter koloru piksela w danej pozycji.
 * @param x Wspó³rzêdna X piksela.
 * @param y Wspó³rzêdna Y piksela.
 * @return Kolor piksela w danej pozycji.
 */
sf::Color BitmapHandler::getPixel(unsigned int x, unsigned int y) const {
    return image.getPixel(x, y);
}

/**
 * @brief Renderuje bitmapê na ekranie.
 * @param window Okno renderowania, na którym bitmapa jest rysowana.
 */
void BitmapHandler::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

/**
 * @brief Ustawia pozycjê bitmapy na ekranie.
 * @param x Nowa wspó³rzêdna X.
 * @param y Nowa wspó³rzêdna Y.
 */
void BitmapHandler::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

/**
 * @brief Przemieszcza bitmapê w dó³, symuluj¹c efekt spadania.
 * @param speed Prêdkoœæ spadania w jednostkach na klatkê.
 */
void BitmapHandler::fall(float speed) {
    sf::Vector2f position = sprite.getPosition();
    position.y += speed;
    sprite.setPosition(position);
}

/**
 * @brief Zwraca obraz bitmapy.
 * @return Referencja do obiektu sf::Image reprezentuj¹cego bitmapê.
 */
const sf::Image& BitmapHandler::getImage() const {
    return image;
}
