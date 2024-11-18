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
 * @brief Klasa odpowiedzialna za zarz�dzanie silnikiem gry.
 * Klasa ta jest odpowiedzialna za tworzenie okna, obs�ug� zdarze�, zarz�dzanie czasem gry oraz renderowanie zawarto�ci.
 */
class Engine
{
public:

    sf::RenderWindow* window; ///< Wska�nik na okno gry.
    sf::VideoMode videoMode;  ///< Rozmiar okna gry.
    sf::Vector2i mousePos;    ///< Pozycja myszy na ekranie.
    sf::Event event;          ///< Obiekt do obs�ugi zdarze�.
    sf::Clock clock;          ///< Zegar gry.
    sf::Time time1;           ///< Zmienna przechowuj�ca czas gry.

    /**
     * @brief Sprawdza, czy okno gry jest otwarte.
     * @return true, je�li okno jest otwarte; false w przeciwnym razie.
     */
    const bool running();

public:

    /**
     * @brief Inicjalizuje zmienne u�ywane w silniku gry.
     * Metoda ta mo�e zosta� rozszerzona o dodatkowe zmienne, je�li zajdzie taka potrzeba.
     */
    void initializeVariables();

    /**
     * @brief Inicjalizuje okno gry.
     * Ustawia wymiary okna, tytu� okna oraz limit klatek na sekund�.
     */
    void initWindow();

    /**
     * @brief Aktualizuje stan gry.
     * Metoda ta obs�uguje r�ne akcje w grze, takie jak obs�uga myszy i zdarze�.
     */
    void update();

    /**
     * @brief Renderuje zawarto�� gry.
     * Metoda ta jest odpowiedzialna za wy�wietlanie wszystkich obiekt�w na ekranie.
     */
    void render();

    /**
     * @brief Czy�ci ekran przed nast�pnym rysowaniem.
     * Metoda ta ustawia t�o na czarne i przygotowuje okno do narysowania nowej klatki.
     */
    void clear();

    /**
     * @brief Obs�uguje klikni�cia myszy.
     * Sprawdza, czy lewy przycisk myszy jest wci�ni�ty i wy�wietla pozycj� kursora.
     */
    void handlingMouse();

    /**
     * @brief Obs�uguje zdarzenia zwi�zane z klawiatur�.
     * Sprawdza, czy u�ytkownik wcisn�� okre�lone klawisze i wykonuje odpowiednie akcje.
     */
    void polEvents();

    /**
     * @brief Obs�uguje czas w grze.
     * Metoda ta ustawia czas na bazie zegara.
     */
    void time();

    /**
     * @brief Zamyka silnik gry.
     * Zamyka okno gry i wy�wietla komunikat o zako�czeniu pracy silnika.
     */
    void closeEngine();
};
