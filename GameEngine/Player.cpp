#include "Player.h"

Player::Player() : frameWidth(50), frameHeight(50), currentFrame(0), animationSpeed(100), speed(2.0f) {
    if (!texture.loadFromFile("sprite_sheet2.png")) {
        throw std::runtime_error("Failed to load texture file!");
    }
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, frameWidth, frameHeight));
}

bool Player::loadFromFile(const std::string& filename) {
    return texture.loadFromFile(filename);
}

const sf::Image& Player::getImage() const {
    return texture.copyToImage();
}

void Player::handleInput(const sf::RenderWindow& window) {
    int direction = -1; // No movement by default
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        setXY(getX(), getY() - speed);
        direction = 0; // Up (use 0 if the sprite sheet is single-row)
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        setXY(getX(), getY() + speed);
        direction = 0; // Down (use 0 as there is only one row)
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        setXY(getX() - speed, getY());
        direction = 0; // Left (use 0)
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        setXY(getX() + speed, getY());
        direction = 0; // Right (use 0)
    }

    if (direction != -1) {
        animate(direction, 6); // 6 frames for the single row
    }
    setSpritePosition();
}

void Player::update() {
    // Update logic (if needed)
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Player::animate(int direction, int frameCount) {
    if (animationClock.getElapsedTime().asMilliseconds() >= animationSpeed) {
        currentFrame = (currentFrame + 1) % frameCount;
        sprite.setTextureRect(sf::IntRect(currentFrame * frameWidth, 0, frameWidth, frameHeight)); // Only one row
        animationClock.restart();
    }
}

void Player::setSpritePosition() {
    sprite.setPosition(getX(), getY());
}
