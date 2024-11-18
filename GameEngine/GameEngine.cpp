#include "Engine.h"

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
    if (!bitmap.loadFromFile("steve.png")) {
        std::cerr << "Nie mozna wczytac pliku bitmapy!" << std::endl;
        return -1;
    }


    while (engine.running())
    {

        engine.update();

        // Czyszczenie
        engine.clear();

        //Rysowanie  linii
        */
        /*
        line.set_top(250, 150);
        line.set_bottom(250, 450);
        

        //Skalowanie lini
        line.draw_line(*engine.window);
        line.scaling00(*engine.window, 2);
        Point2D scalePoint; // Punkt XY na podstawie którego skalujemy linię
        scalePoint.setXY(400.0f, 350.0f);
        scalePoint.draw_point(*engine.window);
        line.scalingXY(*engine.window, 2, 400.0f, 350.0f);
        */


        // Rysowanie prymitywów za pomocą klasy primitiverenderer
        /*
        primitiverenderer.drawTriangle(*engine.window,550, 100, 550,50,500,50);
        primitiverenderer.drawRectangle(*engine.window, 600,700,100,50); //(wsp. szerokosci1, wsp. szerokosci2, wsp. wysokosci 1, wsp wysokosci2)
        primitiverenderer.drawCircle(*engine.window, 400.0f, 450.0f, 60.f);
        primitiverenderer.drawElipse(*engine.window, 400.0f, 300.0f, 120.f,60.f);
        */


        //Rotacja punktu

        /*
        point.setXY(500.f, 400.f);
        point.rotation00(*engine.window, 180.0f);
        point.rotationXY(*engine.window, 180, 500, 300);
        point.draw_point(*engine.window);
        */


        // przesuniecia punktu
        /*
        point.setXY(200, 300);
        Point2D testPoint; // punkt o który 
        testPoint.setXY(200, 300);
        testPoint.draw_point(*engine.window);
        point.translation(*engine.window, 0, -100); //przesuwa do góry o 100 pikseli
        */

        //skalowanie względem XY
        /*
        point.setXY(100, 300);
        point.draw_point(*engine.window);
        point.scalingXY(*engine.window, 0.5,200,300);
        */

        
        //Skalowanie punktu względem 00

        /*
        point.setXY(100, 300);
        point.draw_point(*engine.window);
        point.scaling00(*engine.window, 0.5);
        */


        /*Wstawianie bitmapy
        bitmap.setPosition(400, 300);
        bitmap.draw(*engine.window);
        //bitmap.clear(); //usuwa bitmape
        */

/*
        engine.render();
    }

    return 0;
}
*/


