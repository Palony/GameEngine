#include "Engine.h"
#include "PrimitiveRenderer.h"
#include "Point2D.h"
#include "LineSegment.h"



int main() {
    Engine engine;
    PrimitiveRenderer primitiverenderer;
    Point2D point;
    LineSegment line;

    engine.initializeVariables();
    engine.initWindow();
    engine.time();

    while (engine.running())
    {
        engine.update();

        // Czyszczenie
        engine.window->clear();

        // Rysowanie linii za pomocą algorytmu przyrostowego
        primitiverenderer.drawIncrementalLine(*engine.window, 700.f, 500.f, 750.f, 550.f);

        // Rysowanie drugiej linii
        line.set_top(325.f, 360);
        line.set_bottom(466.f, 367.f);
        line.draw_line(*engine.window);

        // Rysowanie prymitywów
        primitiverenderer.init(*engine.window);

        // Rysowanie punktu
        point.setXY(500.f, 500.f);
        point.draw_point(*engine.window);

        //Rysowanie okręgu za pomocą funkcji wykorzysującej 4 krotną symetrię 

        primitiverenderer.drawCircle(*engine.window, 400.0f, 400.0f,15.f);
        //Rysowanie elipsy za pomocą funkcji wykorzysującej 4 krotną symetrię 
        primitiverenderer.drawElipse(*engine.window, 400.0f, 300.0f, 100.f,100.f);

        // Rysowanie
        engine.window->display();
    }

    return 0;
}