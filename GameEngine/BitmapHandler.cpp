#include "BitmapHandler.h"

// Konstruktor domy�lny
/**
 * @brief Konstruktor klasy BitmapHandler.
 * Inicjalizuje obiekt bez �adnych pocz�tkowych danych.
 */
BitmapHandler::BitmapHandler() = default;

/**
 * @brief Tworzy now� pust� bitmap� o podanych rozmiarach i kolorze t�a.
 * @param width Szeroko�� nowej bitmapy.
 * @param height Wysoko�� nowej bitmapy.
 * @param color Kolor t�a bitmapy.
 * @return Zwraca true, je�li bitmapa zosta�a pomy�lnie stworzona, false w przeciwnym razie.
 */
bool BitmapHandler::create(float width, float height, sf::Color color) {
    image.create(width, height, color);
    return texture.loadFromImage(image); // Aktualizacja tekstury z nowego obrazu
}

/**
 * @brief Wczytuje bitmap� z pliku.
 * @param filename �cie�ka do pliku z bitmap�.
 * @return Zwraca true, je�li bitmapa zosta�a pomy�lnie wczytana, false w przeciwnym razie.
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
 * @brief Zapisuje bitmap� do pliku.
 * @param filename �cie�ka do pliku, w kt�rym bitmapa ma zosta� zapisana.
 * @return Zwraca true, je�li zapis do pliku si� powi�d�, false w przeciwnym razie.
 */
bool BitmapHandler::saveToFile(const std::string& filename) const {
    return image.saveToFile(filename);
}

/**
 * @brief Usuwa zawarto�� bitmapy.
 * Czy�ci obraz i resetuje tekstur� oraz sprite.
 */
void BitmapHandler::clear() {
    image.create(0, 0);
    texture = sf::Texture();
    sprite = sf::Sprite();
}

/**
 * @brief Kopiuje zawarto�� innej bitmapy do tej bitmapy.
 * Mo�liwo�� ograniczenia kopiowania do prostok�tnego obszaru.
 * @param source Obiekt �r�d�owy bitmapy, z kt�rej ma zosta� skopiowana zawarto��.
 * @param sourceRect Prostok�tny obszar do skopiowania (je�li pusty, kopiuje ca�� bitmap�).
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
 * @brief Getter dla sprite'a, kt�ry jest u�ywany do renderowania bitmapy.
 * @return Sta�a referencja do sprite'a.
 */
const sf::Sprite& BitmapHandler::getSprite() const {
    return sprite;
}

/**
 * @brief Getter rozmiaru bitmapy.
 * @return Rozmiar bitmapy jako wektor (szeroko��, wysoko��).
 */
sf::Vector2u BitmapHandler::getSize() const {
    return image.getSize();
}

/**
 * @brief Ustawia kolor piksela w danej pozycji.
 * @param x Wsp�rz�dna X piksela.
 * @param y Wsp�rz�dna Y piksela.
 * @param color Kolor, kt�ry ma zosta� przypisany do piksela.
 */
void BitmapHandler::setPixel(unsigned int x, unsigned int y, sf::Color color) {
    image.setPixel(x, y, color);
    texture.update(image);
}

/**
 * @brief Getter koloru piksela w danej pozycji.
 * @param x Wsp�rz�dna X piksela.
 * @param y Wsp�rz�dna Y piksela.
 * @return Kolor piksela w danej pozycji.
 */
sf::Color BitmapHandler::getPixel(unsigned int x, unsigned int y) const {
    return image.getPixel(x, y);
}

/**
 * @brief Renderuje bitmap� na ekranie.
 * @param window Okno renderowania, na kt�rym bitmapa jest rysowana.
 */
void BitmapHandler::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

/**
 * @brief Ustawia pozycj� bitmapy na ekranie.
 * @param x Nowa wsp�rz�dna X.
 * @param y Nowa wsp�rz�dna Y.
 */
void BitmapHandler::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

/**
 * @brief Przemieszcza bitmap� w d�, symuluj�c efekt spadania.
 * @param speed Pr�dko�� spadania w jednostkach na klatk�.
 */
void BitmapHandler::fall(float speed) {
    sf::Vector2f position = sprite.getPosition();
    position.y += speed;
    sprite.setPosition(position);
}

/**
 * @brief Zwraca obraz bitmapy.
 * @return Referencja do obiektu sf::Image reprezentuj�cego bitmap�.
 */
const sf::Image& BitmapHandler::getImage() const {
    return image;
}
