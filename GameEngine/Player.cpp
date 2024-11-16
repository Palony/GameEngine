#include "Player.h"



void Player::handleInput(const sf::RenderWindow& window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        setY(getY() - speed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        setY(getY() + speed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        setX(getX() - speed);
        sf::Vector2f position = sprite.getPosition();
        position.x -= speed;
        sprite.setPosition(position);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        setX(getX() + speed);
        sf::Vector2f position = sprite.getPosition();
        position.x += speed;
        sprite.setPosition(position);
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        setXY(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    }
}


void Player::update() {

}

void Player::draw(sf::RenderWindow& window) {
    BitmapHandler::draw(window);
}