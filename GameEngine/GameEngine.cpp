//#include "Engine.h"


/*

int main() {
    Engine engine;
    PrimitiveRenderer primitiverenderer;
    Point2D point;
    LineSegment line;
    BitmapHandler bitmap;
    Player player;


    
   

    engine.initializeVariables();
    engine.initWindow();
    engine.time();
    if(!bitmap.loadFromFile("steve.png")) {
        std::cerr << "Nie mozna wczytac pliku bitmapy!" << std::endl;
        return -1;
    }

    
    while (engine.running())
    {
        player.handleInput(*engine.window); // Obsługa wejścia dla gracza
        player.update(); // Aktualizacja logiki gracza
     
        engine.update();

        // Czyszczenie
        engine.window->clear();

        //Rysowanie  linii
        line.set_top(250, 150);
        line.set_bottom(250, 450);
        line.draw_line(*engine.window);

        // Rysowanie prymitywów
        primitiverenderer.drawTriangle(*engine.window,550, 100, 550,50,500,50);
        primitiverenderer.drawRectangle(*engine.window, 600,700,100,50); //(wsp. szerokosci1, wsp. szerokosci2, wsp. wysokosci 1, wsp wysokosci2)
        primitiverenderer.drawPolygon(*engine.window, 5);
            
       
        // Rysowanie punktu
        point.setXY(425.f, 325.f);
        point.draw_point(*engine.window);

        // przesuniecia
        point.translation(*engine.window, 0, -100);
        line.translation(*engine.window, 300, 0);

        //rotacja
        point.rotation00(*engine.window, 90);
        point.rotationXY(*engine.window, 90, 300, 300);
        line.rotation00(*engine.window, 120);
        line.rotationXY(*engine.window, 60, 450, 300);

        //skalowanie
          point.scaling00(*engine.window, 0.5);
          point.scalingXY(*engine.window, 0.5,200,300);
          line.scaling00(*engine.window, 0.5);
          line.scalingXY(*engine.window, 0.5, 100, 300);

          //bitmapy
          
          bitmap.draw(*engine.window);

          //player
          player.draw(*engine.window);


        //Rysowanie okręgu za pomocą funkcji wykorzysującej 4 krotną symetrię 
        primitiverenderer.drawCircle(*engine.window, 400.0f, 300.0f, 50.f);
        //Rysowanie elipsy za pomocą funkcji wykorzysującej 4 krotną symetrię 
        primitiverenderer.drawElipse(*engine.window, 400.0f, 300.0f, 100.f, 150.f);

        // Rysowanie
        engine.window->display();
    }

    return 0;
}

*/
