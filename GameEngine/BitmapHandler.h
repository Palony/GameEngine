#include <SFML/Graphics.hpp>
#include <string>
#include "BitmapObject.h"


class BitmapHandler:public BitmapObject {
private:
    sf::Image image;        
    sf::Texture texture;        

public:
   
    BitmapHandler();

 
    bool create(float width,float height, sf::Color color = sf::Color::Transparent);  
    bool loadFromFile(const std::string& filename);   
    bool saveToFile(const std::string& filename) const;   
    void clear();    
    void copyFrom(const BitmapHandler& source, sf::IntRect sourceRect = sf::IntRect());    
    const sf::Sprite& getSprite() const;    
    sf::Vector2u getSize() const;    
    void setPixel(unsigned int x, unsigned int y, sf::Color color);   
    sf::Color getPixel(unsigned int x, unsigned int y) const; 
    void draw(sf::RenderWindow& window) override;
    void setPosition(float x, float y);
    void fall(float speed);
    void Bitmapmoveleft(float speed);
};


