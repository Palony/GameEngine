#ifndef PLAYER_H
#define PLAYER_H

#include "BitmapHandler.h"
#include <SFML/Graphics.hpp>

class Player : public BitmapHandler {
public:
    Player() {
        speed = 5.f;
    };

    virtual void handleInput(const sf::RenderWindow& window);
    void update();
    virtual void draw(sf::RenderWindow& window);

protected:
    float speed;
};

#endif // PLAYER_H