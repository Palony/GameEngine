#ifndef PLAYER_H
#define PLAYER_H
#include "DrawableObject.h"
#include <SFML/Graphics.hpp>
#include "SpriteObject.h"

class Player : public DrawableObject {
private:
    sf::Sprite sprite;
    sf::Texture texture;
    int frameWidth;
    int frameHeight;
    int currentFrame;
    int animationSpeed; // Milliseconds per frame
    sf::Clock animationClock;
    float speed;

public:
    Player();
    void handleInput(const sf::RenderWindow& window);
    void update();
    void draw(sf::RenderWindow& window);
    void animate(int direction, int frameCount);
    void setSpritePosition();
    bool loadFromFile(const std::string& filename);
    const sf::Image& getImage() const;
};

#endif // PLAYER_H
