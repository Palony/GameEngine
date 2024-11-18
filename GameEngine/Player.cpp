#include "Player.h"

/**
 * @brief Konstruktor klasy Player.
 * Inicjalizuje gracza z wartoœciami domyœlnymi i ³aduje teksturê.
 */
Player::Player() : frameWidth(50), frameHeight(50), currentFrame(0), animationSpeed(100), speed(2.0f) {
    if (!texture.loadFromFile("ruch.png")) {
        throw std::runtime_error("Nie uda³o siê za³adowaæ pliku tekstury!");
    }
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, frameWidth, frameHeight));
}

/**
 * @brief £aduje teksturê z pliku.
 * @param filename Œcie¿ka do pliku tekstury.
 * @return True jeœli tekstura zosta³a za³adowana pomyœlnie, false w przeciwnym razie.
 */
bool Player::loadFromFile(const std::string& filename) {
    return texture.loadFromFile(filename);
}

/**
 * @brief Zwraca obraz tekstury gracza.
 * @return Referencja do obrazu tekstury.
 */
const sf::Image& Player::getImage() const {
    return texture.copyToImage();
}

/**
 * @brief Obs³uguje wejœcie gracza i aktualizuje kierunek ruchu.
 * Ta metoda sprawdza naciœniête klawisze i odpowiednio dostosowuje pozycjê gracza.
 * @param window Okno u¿ywane do przechwytywania wejœcia (nie jest bezpoœrednio u¿ywane, ale w³¹czone dla kontekstu).
 */
void Player::handleInput(const sf::RenderWindow& window) {
    int direction = -1; // Brak ruchu domyœlnie
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        setXY(getX(), getY() - speed);
        direction = 0; // W górê (u¿ywamy 0, poniewa¿ arkusz sprite'ów ma tylko jeden wiersz)
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        setXY(getX(), getY() + speed);
        direction = 0; // W dó³ (u¿ywamy 0, poniewa¿ jest tylko jeden wiersz)
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        setXY(getX() - speed, getY());
        direction = 0; // W lewo (u¿ywamy 0)
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        setXY(getX() + speed, getY());
        direction = 0; // W prawo (u¿ywamy 0)
    }

    if (direction != -1) {
        animate(direction, 6); // 6 klatek w jednym wierszu
    }
    setSpritePosition();
}


void Player::update() {
    
}

/**
 * @brief Rysuje gracza na ekranie.
 * @param window Okno renderowania, na którym gracz jest rysowany.
 */
void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

/**
 * @brief Animuje gracza, zmieniaj¹c klatki animacji.
 * @param direction Kierunek ruchu (np. w lewo, w prawo).
 * @param frameCount Liczba klatek w animacji (np. 6 klatek w jednym wierszu).
 */
void Player::animate(int direction, int frameCount) {
    if (animationClock.getElapsedTime().asMilliseconds() >= animationSpeed) {
        currentFrame = (currentFrame + 1) % frameCount;
        sprite.setTextureRect(sf::IntRect(currentFrame * frameWidth, 0, frameWidth, frameHeight)); // Tylko jeden wiersz
        animationClock.restart();
    }
}

/**
 * @brief Ustawia pozycjê sprite'a na ekranie.
 * Ustawia wspó³rzêdne x i y sprite'a na aktualn¹ pozycjê gracza.
 */
void Player::setSpritePosition() {
    sprite.setPosition(getX(), getY());
}
