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

        // Clear the window
        engine.window->clear();

        // Rysowanie linii za pomocą algorytmu przyrostowego
        primitiverenderer.drawIncrementalLine(*engine.window, 700.f, 500.f, 750.f, 550.f);

        // Rysowanie drugiej linii
        line.set_top(500.f, 400.f);
        line.set_bottom(650.f, 350.f);
        line.draw_line(*engine.window);

        // Rysowanie prymitywów
        primitiverenderer.init(*engine.window);

        // Rysowanie punktu
        point.setXY(500.f, 500.f);
        point.draw_point(*engine.window);

        // Display the contents
        engine.window->display();
    }

    return 0;
}