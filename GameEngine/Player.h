#ifndef PLAYER_H
#define PLAYER_H

#include "DrawableObject.h"
#include <SFML/Graphics.hpp>
#include "SpriteObject.h"

/**
 * @brief Klasa reprezentuj�ca gracza, dziedzicz�ca po klasie DrawableObject.
 * Klasa odpowiedzialna za obs�ug� rysowania, animacji oraz wej�cia gracza.
 */
class Player : public DrawableObject {
private:
    sf::Sprite sprite; /**< Obiekt sprite reprezentuj�cy posta� gracza. */
    sf::Texture texture; /**< Tekstura u�ywana do renderowania sprite'a. */
    int frameWidth; /**< Szeroko�� pojedynczej klatki animacji. */
    int frameHeight; /**< Wysoko�� pojedynczej klatki animacji. */
    int currentFrame; /**< Indeks aktualnej klatki animacji. */
    int animationSpeed; /**< Pr�dko�� animacji w milisekundach na klatk�. */
    sf::Clock animationClock; /**< Zegar do �ledzenia czasu mi�dzy klatkami animacji. */
    float speed; /**< Pr�dko�� poruszania si� gracza. */

public:
    /**
     * @brief Konstruktor klasy Player.
     * Inicjalizuje gracza z warto�ciami domy�lnymi i �aduje tekstur�.
     */
    Player();

    /**
     * @brief Obs�uguje wej�cie gracza, zmieniaj�c pozycj� na podstawie naci�ni�tych klawiszy.
     * @param window Okno renderowania (u�ywane do obs�ugi wej�cia, chocia� nie jest bezpo�rednio wykorzystywane w tej metodzie).
     */
    void handleInput(const sf::RenderWindow& window);

    /**
     * @brief Metoda do aktualizacji stanu gracza (mo�e by� wykorzystana do dodatkowej logiki).
     */
    void update();

    /**
     * @brief Rysuje gracza na ekranie.
     * @param window Okno renderowania, na kt�rym gracz jest rysowany.
     */
    void draw(sf::RenderWindow& window);

    /**
     * @brief Animuje gracza, zmieniaj�c klatki animacji.
     * @param direction Kierunek ruchu (np. w lewo, w prawo).
     * @param frameCount Liczba klatek w animacji (np. 6 klatek w jednym wierszu).
     */
    void animate(int direction, int frameCount);

    /**
     * @brief Ustawia pozycj� sprite'a na ekranie.
     * Ustawia wsp�rz�dne x i y sprite'a na aktualn� pozycj� gracza.
     */
    void setSpritePosition();

    /**
     * @brief �aduje tekstur� gracza z pliku.
     * @param filename �cie�ka do pliku tekstury.
     * @return True je�li tekstura zosta�a za�adowana pomy�lnie, false w przeciwnym razie.
     */
    bool loadFromFile(const std::string& filename);

    /**
     * @brief Zwraca obraz tekstury gracza.
     * @return Referencja do obrazu tekstury.
     */
    const sf::Image& getImage() const;
};

#endif // PLAYER_H
