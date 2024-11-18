#include "Engine.h"

/**
 * @brief Klasa odpowiedzialna za zarządzanie silnikiem gry.
 * Ta klasa zajmuje się inicjalizacją okna gry, obsługą zdarzeń, rysowaniem obiektów oraz zamknięciem gry.
 */
const bool Engine::running()
{
    return this->window->isOpen(); ///< Sprawdza, czy okno gry jest otwarte.
}

/**
 * @brief Inicjalizacja zmiennych używanych w silniku gry.
 * Metoda ta jest pusta w tej wersji, ale może być użyta do przyszłej konfiguracji zmiennych.
 */
void Engine::initializeVariables()
{
}

/**
 * @brief Inicjalizuje okno gry.
 * Ustawia wymiary okna, jego tytuł oraz limit klatek na sekundę.
 */
void Engine::initWindow()
{
    this->videoMode.height = 600; ///< Wysokość okna.
    this->videoMode.width = 800;  ///< Szerokość okna.
    this->window = new sf::RenderWindow(this->videoMode, "Matrix 0.5", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60); ///< Ustawia limit klatek na 60.
}

/**
 * @brief Aktualizacja stanu gry.
 * Metoda ta obsługuje różne akcje w grze, takie jak obsługa myszy i zdarzeń.
 */
void Engine::update()
{
    handlingMouse(); ///< Obsługuje zdarzenia myszy.
    polEvents();     ///< Obsługuje zdarzenia związane z klawiaturą i innymi wejściami.
}

/**
 * @brief Renderowanie zawartości gry.
 * Wyświetla zawartość okna, tj. rysuje wszystkie obiekty na ekranie.
 */
void Engine::render()
{
    this->window->display(); ///< Wyświetla zawartość okna.
}

/**
 * @brief Czyszczenie ekranu.
 * Czyści okno gry przed narysowaniem nowej klatki.
 */
void Engine::clear()
{
    this->window->clear(sf::Color::Black); ///< Ustawia tło na czarne przed narysowaniem kolejnej klatki.
}

/**
 * @brief Obsługuje kliknięcia myszy.
 * Sprawdza, czy lewy przycisk myszy jest wciśnięty i wyświetla pozycję kursora.
 */
void Engine::handlingMouse()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) ///< Sprawdza, czy lewy przycisk myszy jest wciśnięty.
    {
        mousePos = sf::Mouse::getPosition(*window); ///< Pobiera pozycję myszy względem okna.
        std::cout << "Mouse X: " << mousePos.x << std::endl; ///< Wyświetla współrzędną X kursora.
        std::cout << "Mouse Y: " << mousePos.y << std::endl; ///< Wyświetla współrzędną Y kursora.
    }
}

/**
 * @brief Obsługuje zdarzenia związane z klawiaturą i innymi wejściami.
 * Sprawdza, czy użytkownik wcisnął określone klawisze.
 */
void Engine::polEvents()
{
    while (window->pollEvent(event)) ///< Przechodzi przez wszystkie zdarzenia.
    {
        if (event.type == sf::Event::Closed) ///< Jeśli okno zostało zamknięte.
        {
            window->close(); ///< Zamknięcie okna.
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) ///< Sprawdza, czy wciśnięto klawisz "A".
        {
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) ///< Sprawdza, czy wciśnięto klawisz "W".
        {
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) ///< Sprawdza, czy wciśnięto klawisz "S".
        {
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) ///< Sprawdza, czy wciśnięto klawisz "D".
        {
        }
    }
}

/**
 * @brief Obsługuje czas w grze.
 * Metoda ta ustawia czas na bazie zegara.
 */
void Engine::time()
{
    time1 = clock.restart(); ///< Restartuje zegar i zapisuje czas.
}

/**
 * @brief Zamyka silnik gry.
 * Zamyka okno gry i wyświetla komunikat o zakończeniu pracy silnika.
 */
void Engine::closeEngine()
{
    this->window->close();  ///< Zamknięcie okna gry.
    std::cout << "Silnik zostal zamkniety" << std::endl; ///< Komunikat o zamknięciu silnika.
}
