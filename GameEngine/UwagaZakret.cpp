#include "Engine.h"


PrimitiveRenderer primitiverenderer;


int main() {
    Engine engine;

    Triangle triangle(450, -200, 450, -100, 500, -100);
    Triangle triangle2(350, -50, 350, 0, 400, 0);
    Triangle triangle3(250, 150, 250, 0, 300, 0);
   

    Circle circle(750.0f, 0, 15.0f); 
    Circle circle2(600.0f, -50, 15.0f);
    Circle circle3(450.0f, -250, 15.0f);
    Circle circle4(300.0f, -400, 15.0f);
    Circle circle5(200.0f, 0, 15.0f);
    Circle circle6(50.0f, -200, 15.0f);

    Rectangle rectangle(600,0, 650.0f, -50.0f);
    Rectangle rectangle2(750.0f, 0, 720, -100.0f);

    BitmapHandler bitmap;

    // Inicjalizacja silnika
    engine.initializeVariables();
    engine.initWindow();
    engine.time();

    if (!bitmap.loadFromFile("steve.png")) {
        std::cerr << "Nie mozna wczytac pliku bitmapy!" << std::endl;
        return -1;
    }

    // G³ówna pêtla gry
    while (engine.running()) {
        engine.update();

        // Czyszczenie
        engine.window->clear();

        // Rysowanie ró¿nych obiektów
        triangle.fall(*engine.window,1.0f);
        triangle.draw(*engine.window);
        triangle2.fall(*engine.window, 1.0f);
        triangle2.draw(*engine.window);
        triangle3.fall(*engine.window, 1.0f);
        triangle3.draw(*engine.window);

        rectangle.fall(*engine.window, 1.0f);
        rectangle.draw(*engine.window);
        rectangle2.fall(*engine.window, 1.0f);
        rectangle2.draw(*engine.window);

        circle.fall(*engine.window, 1.0f);
        circle.draw(*engine.window); 
        circle2.fall(*engine.window, 1.0f);
        circle2.draw(*engine.window);
        circle3.fall(*engine.window, 1.0f);
        circle3.draw(*engine.window);
        circle4.fall(*engine.window, 1.0f);
        circle4.draw(*engine.window);
        circle5.fall(*engine.window, 1.0f);
        circle5.draw(*engine.window);
        circle6.fall(*engine.window, 1.0f);
        circle6.draw(*engine.window);

        //bitmap.fall(5);
        bitmap.draw(*engine.window);
        
       
        
        // Wyœwietlanie
        engine.window->display();
    }

    return 0;
}
