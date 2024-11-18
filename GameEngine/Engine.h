#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <time.h>
#include <iostream>
#include "PrimitiveRenderer.h"
#include "Point2D.h"
#include "LineSegment.h"
#include "Circle.h"
#include "Elipse.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Player.h"
#include "BitmapHandler.h"

#pragma once

/**
 * @brief Klasa odpowiedzialna za zarz¹dzanie silnikiem gry.
 * Klasa ta jest odpowiedzialna za tworzenie okna, obs³ugê zdarzeñ, zarz¹dzanie czasem gry oraz renderowanie zawartoœci.
 */
class Engine
{
public:

    sf::RenderWindow* window; ///< WskaŸnik na okno gry.
    sf::VideoMode videoMode;  ///< Rozmiar okna gry.
    sf::Vector2i mousePos;    ///< Pozycja myszy na ekranie.
    sf::Event event;          ///< Obiekt do obs³ugi zdarzeñ.
    sf::Clock clock;          ///< Zegar gry.
    sf::Time time1;           ///< Zmienna przechowuj¹ca czas gry.

    /**
     * @brief Sprawdza, czy okno gry jest otwarte.
     * @return true, jeœli okno jest otwarte; false w przeciwnym razie.
     */
    const bool running();

public:

    /**
     * @brief Inicjalizuje zmienne u¿ywane w silniku gry.
     * Metoda ta mo¿e zostaæ rozszerzona o dodatkowe zmienne, jeœli zajdzie taka potrzeba.
     */
    void initializeVariables();

    /**
     * @brief Inicjalizuje okno gry.
     * Ustawia wymiary okna, tytu³ okna oraz limit klatek na sekundê.
     */
    void initWindow();

    /**
     * @brief Aktualizuje stan gry.
     * Metoda ta obs³uguje ró¿ne akcje w grze, takie jak obs³uga myszy i zdarzeñ.
     */
    void update();

    /**
     * @brief Renderuje zawartoœæ gry.
     * Metoda ta jest odpowiedzialna za wyœwietlanie wszystkich obiektów na ekranie.
     */
    void render();

    /**
     * @brief Czyœci ekran przed nastêpnym rysowaniem.
     * Metoda ta ustawia t³o na czarne i przygotowuje okno do narysowania nowej klatki.
     */
    void clear();

    /**
     * @brief Obs³uguje klikniêcia myszy.
     * Sprawdza, czy lewy przycisk myszy jest wciœniêty i wyœwietla pozycjê kursora.
     */
    void handlingMouse();

    /**
     * @brief Obs³uguje zdarzenia zwi¹zane z klawiatur¹.
     * Sprawdza, czy u¿ytkownik wcisn¹³ okreœlone klawisze i wykonuje odpowiednie akcje.
     */
    void polEvents();

    /**
     * @brief Obs³uguje czas w grze.
     * Metoda ta ustawia czas na bazie zegara.
     */
    void time();

    /**
     * @brief Zamyka silnik gry.
     * Zamyka okno gry i wyœwietla komunikat o zakoñczeniu pracy silnika.
     */
    void closeEngine();
};
