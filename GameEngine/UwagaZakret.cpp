#include "Engine.h"




int main() {
    Engine engine;

    engine.initializeVariables();
    engine.initWindow();
    engine.time();

    while (engine.running())
    {

        engine.update();

        // Czyszczenie
        engine.window->clear();



        // Rysowanie
        engine.window->display();
    }

    return 0;
}
