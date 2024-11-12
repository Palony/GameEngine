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
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        setX(getX() + speed);
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        setXY(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    }
}


void Player::update() {

}

void Player::draw(sf::RenderWindow& window) {
    sf::CircleShape shape(10); // Przyk³adowy kszta³t reprezentuj¹cy gracza
    shape.setPosition(getX(), getY());
    shape.setFillColor(sf::Color::Green);
    window.draw(shape);
}