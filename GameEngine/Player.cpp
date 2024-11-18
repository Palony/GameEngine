#include "Player.h"

/**
 * @brief Konstruktor klasy Player.
 * Inicjalizuje gracza z warto�ciami domy�lnymi i �aduje tekstur�.
 */
Player::Player() : frameWidth(50), frameHeight(50), currentFrame(0), animationSpeed(100), speed(2.0f) {
    if (!texture.loadFromFile("ruch.png")) {
        throw std::runtime_error("Nie uda�o si� za�adowa� pliku tekstury!");
    }
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, frameWidth, frameHeight));
}

/**
 * @brief �aduje tekstur� z pliku.
 * @param filename �cie�ka do pliku tekstury.
 * @return True je�li tekstura zosta�a za�adowana pomy�lnie, false w przeciwnym razie.
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
 * @brief Obs�uguje wej�cie gracza i aktualizuje kierunek ruchu.
 * Ta metoda sprawdza naci�ni�te klawisze i odpowiednio dostosowuje pozycj� gracza.
 * @param window Okno u�ywane do przechwytywania wej�cia (nie jest bezpo�rednio u�ywane, ale w��czone dla kontekstu).
 */
void Player::handleInput(const sf::RenderWindow& window) {
    int direction = -1; // Brak ruchu domy�lnie
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        setXY(getX(), getY() - speed);
        direction = 0; // W g�r� (u�ywamy 0, poniewa� arkusz sprite'�w ma tylko jeden wiersz)
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        setXY(getX(), getY() + speed);
        direction = 0; // W d� (u�ywamy 0, poniewa� jest tylko jeden wiersz)
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        setXY(getX() - speed, getY());
        direction = 0; // W lewo (u�ywamy 0)
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        setXY(getX() + speed, getY());
        direction = 0; // W prawo (u�ywamy 0)
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
 * @param window Okno renderowania, na kt�rym gracz jest rysowany.
 */
void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

/**
 * @brief Animuje gracza, zmieniaj�c klatki animacji.
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
 * @brief Ustawia pozycj� sprite'a na ekranie.
 * Ustawia wsp�rz�dne x i y sprite'a na aktualn� pozycj� gracza.
 */
void Player::setSpritePosition() {
    sprite.setPosition(getX(), getY());
}
