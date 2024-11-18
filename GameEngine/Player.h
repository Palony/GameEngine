#ifndef PLAYER_H
#define PLAYER_H

#include "DrawableObject.h"
#include <SFML/Graphics.hpp>
#include "SpriteObject.h"

/**
 * @brief Klasa reprezentuj¹ca gracza, dziedzicz¹ca po klasie DrawableObject.
 * Klasa odpowiedzialna za obs³ugê rysowania, animacji oraz wejœcia gracza.
 */
class Player : public DrawableObject {
private:
    sf::Sprite sprite; /**< Obiekt sprite reprezentuj¹cy postaæ gracza. */
    sf::Texture texture; /**< Tekstura u¿ywana do renderowania sprite'a. */
    int frameWidth; /**< Szerokoœæ pojedynczej klatki animacji. */
    int frameHeight; /**< Wysokoœæ pojedynczej klatki animacji. */
    int currentFrame; /**< Indeks aktualnej klatki animacji. */
    int animationSpeed; /**< Prêdkoœæ animacji w milisekundach na klatkê. */
    sf::Clock animationClock; /**< Zegar do œledzenia czasu miêdzy klatkami animacji. */
    float speed; /**< Prêdkoœæ poruszania siê gracza. */

public:
    /**
     * @brief Konstruktor klasy Player.
     * Inicjalizuje gracza z wartoœciami domyœlnymi i ³aduje teksturê.
     */
    Player();

    /**
     * @brief Obs³uguje wejœcie gracza, zmieniaj¹c pozycjê na podstawie naciœniêtych klawiszy.
     * @param window Okno renderowania (u¿ywane do obs³ugi wejœcia, chocia¿ nie jest bezpoœrednio wykorzystywane w tej metodzie).
     */
    void handleInput(const sf::RenderWindow& window);

    /**
     * @brief Metoda do aktualizacji stanu gracza (mo¿e byæ wykorzystana do dodatkowej logiki).
     */
    void update();

    /**
     * @brief Rysuje gracza na ekranie.
     * @param window Okno renderowania, na którym gracz jest rysowany.
     */
    void draw(sf::RenderWindow& window);

    /**
     * @brief Animuje gracza, zmieniaj¹c klatki animacji.
     * @param direction Kierunek ruchu (np. w lewo, w prawo).
     * @param frameCount Liczba klatek w animacji (np. 6 klatek w jednym wierszu).
     */
    void animate(int direction, int frameCount);

    /**
     * @brief Ustawia pozycjê sprite'a na ekranie.
     * Ustawia wspó³rzêdne x i y sprite'a na aktualn¹ pozycjê gracza.
     */
    void setSpritePosition();

    /**
     * @brief £aduje teksturê gracza z pliku.
     * @param filename Œcie¿ka do pliku tekstury.
     * @return True jeœli tekstura zosta³a za³adowana pomyœlnie, false w przeciwnym razie.
     */
    bool loadFromFile(const std::string& filename);

    /**
     * @brief Zwraca obraz tekstury gracza.
     * @return Referencja do obrazu tekstury.
     */
    const sf::Image& getImage() const;
};

#endif // PLAYER_H
