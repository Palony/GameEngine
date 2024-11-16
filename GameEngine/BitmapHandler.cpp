#include "BitmapHandler.h"

// Konstruktor domyœlny
BitmapHandler::BitmapHandler() = default;

// Metoda tworz¹ca now¹ pust¹ bitmapê o podanych rozmiarach i kolorze
bool BitmapHandler::create(float width, float height, sf::Color color) {
    image.create(width, height, color);
    return texture.loadFromImage(image); // Aktualizacja tekstury z nowego obrazu
}

// Metoda do wczytywania bitmapy z pliku
bool BitmapHandler::loadFromFile(const std::string& filename) {
    if (image.loadFromFile(filename)) {
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.setPosition(50, 0); // Ustawienie domyœlnej pozycji na (0, 0)
        return true;
    }
    return false;
}

// Metoda do zapisywania bitmapy do pliku
bool BitmapHandler::saveToFile(const std::string& filename) const {
    return image.saveToFile(filename);
}

// Usuwanie zawartoœci bitmapy
void BitmapHandler::clear() {
    image.create(0, 0);        
    texture = sf::Texture();    
    sprite = sf::Sprite();      
}

// Metoda do kopiowania zawartoœci innej bitmapy (z opcjonalnym ograniczeniem do prostok¹tnego obszaru)
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

// Getter dla sprite'a do renderowania
const sf::Sprite& BitmapHandler::getSprite() const {
   return sprite;
}

// Getter dla rozmiaru bitmapy
sf::Vector2u BitmapHandler::getSize() const {
    return image.getSize();
}

// Setter koloru piksela
void BitmapHandler::setPixel(unsigned int x, unsigned int y, sf::Color color) {
    image.setPixel(x, y, color);
    texture.update(image); 
}

// Getter koloru piksela
sf::Color BitmapHandler::getPixel(unsigned int x, unsigned int y) const {
    return image.getPixel(x, y);
}

// Renderowanie bitmapy 
void BitmapHandler::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}
void BitmapHandler::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}
void BitmapHandler::fall(float speed) {
    
    sf::Vector2f position = sprite.getPosition();
    position.y += speed;
    sprite.setPosition(position);
}

void BitmapHandler::Bitmapmoveleft(float speed)
{
    sf::Vector2f position = sprite.getPosition();
    position.y += speed;
    sprite.setPosition(position);
}
