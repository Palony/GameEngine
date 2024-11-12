#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include <SFML/Graphics.hpp>

class Player : public GameObject {
public:
    Player() {
        setXY(400.f, 300.f);
        speed = 5.f;
    };

    virtual void handleInput(const sf::RenderWindow& window);
    void update();
    void draw(sf::RenderWindow& window);

protected:
    float speed;
};

#endif // PLAYER_H