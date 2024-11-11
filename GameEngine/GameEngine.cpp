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

   
    bool firstIteration = true;

    while (engine.running())
    {
     
        engine.update();

        // Czyszczenie
        engine.window->clear();

        // Rysowanie linii za pomocą algorytmu przyrostowego
        primitiverenderer.drawIncrementalLine(*engine.window, 700.f, 500.f, 750.f, 550.f);

        // Rysowanie drugiej linii
        line.set_top(300.f, 300);
        line.set_bottom(500, 500);
        line.draw_line(*engine.window);

        // Rysowanie prymitywów
        primitiverenderer.drawTriangle(*engine.window,550, 100, 550,50,500,50);
        primitiverenderer.drawRectangle(*engine.window, 600,700,100,50); //(wsp. szerokosci1, wsp. szerokosci2, wsp. wysokosci 1, wsp wysokosci2)
        primitiverenderer.drawPolygon(*engine.window, 5);
            
        
     
        

        // Rysowanie punktu
        point.setXY(400.f, 300.f);
        point.draw_point(*engine.window);

        // przesuniecia
        point.translation(*engine.window, 200, 100);
        line.translation(*engine.window, 200, 100);

        //rotacja
        point.rotation00(*engine.window, 90);
        point.rotationXY(*engine.window, 90, 300, 300);
        line.rotation00(*engine.window, 90);
        line.rotationXY(*engine.window, 90, 500, 500);

        //skalowanie
        point.scaling00(*engine.window, 0.5);
        point.scalingXY(*engine.window, 0.5,600,300);
        line.scaling00(*engine.window, 0.5);
        line.scalingXY(*engine.window, 0.5, 600, 300);

        //Rysowanie okręgu za pomocą funkcji wykorzysującej 4 krotną symetrię 
        primitiverenderer.drawCircle(*engine.window, 400.0f, 400.0f, 15.f);
        //Rysowanie elipsy za pomocą funkcji wykorzysującej 4 krotną symetrię 
        primitiverenderer.drawElipse(*engine.window, 400.0f, 300.0f, 100.f, 100.f);

        // Rysowanie
        engine.window->display();
    }

    return 0;
}