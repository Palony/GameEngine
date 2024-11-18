#include "Engine.h"
#include "game.h"



PrimitiveRenderer primitiverenderer;




bool checkPixelCollision(const Circle& circle, Player& bitmap, const sf::Image& bitmapImage) {
    // Pobierz punkty ko�a
    const auto& points = circle.getPoints();

    // Pobierz w�a�ciwo�ci bitmapy
    float bitmapX = bitmap.getX();
    float bitmapY = bitmap.getY();
    float bitmapWidth = bitmapImage.getSize().x;
    float bitmapHeight = bitmapImage.getSize().y;

    // Iteracja po punktach ko�a
    for (const auto& point : points) {
        // Pozycja punktu ko�a
        float x = point.x;
        float y = point.y;

        // Sprawd�, czy punkt mie�ci si� w granicach bitmapy
        if (x >= bitmapX && x < bitmapX + bitmapWidth &&
            y >= bitmapY && y < bitmapY + bitmapHeight) {
            // Przelicz wsp�rz�dne na lokalny uk�ad bitmapy
            int localX = static_cast<int>(x - bitmapX);
            int localY = static_cast<int>(y - bitmapY);

            // Sprawdzamy, czy piksel w tym miejscu nie jest przezroczysty
            sf::Color pixelColor = bitmapImage.getPixel(localX, localY);
            if (pixelColor.a != 0) { // Je�li kana� alfa jest r�ny od 0, to piksel nie jest przezroczysty
                return true; // Kolizja, poniewa� piksel nie jest przezroczysty
            }
        }
    }

    // Brak kolizji
    return false;
}



bool checkVertexCollisionWithBitmap(float px, float py, float bitmapX, float bitmapY, const sf::Image& bitmapImage) {
    // Funkcja sprawdzaj�ca, czy punkt (px, py) znajduje si� w obr�bie bitmapy
    sf::Vector2u size = bitmapImage.getSize();

    // Sprawdzenie, czy punkt le�y w obr�bie bitmapy
    return px >= bitmapX && px < bitmapX + size.x && py >= bitmapY && py < bitmapY + size.y;
}

bool checkTriangleCollisionWithBitmap(const Triangle& triangle, Player& bitmap, const sf::Image& bitmapImage) {
    // Pobieramy pozycje wierzcho�k�w tr�jk�ta
    float x0 = triangle.getX0(); // Funkcje do pobierania pozycji wierzcho�k�w tr�jk�ta
    float y0 = triangle.getY0();

    float x1 = triangle.getX1();
    float y1 = triangle.getY1();

    float x2 = triangle.getX2();
    float y2 = triangle.getY2();

    // Pobieramy pozycj� bitmapy
    float bitmapX = bitmap.getX();
    float bitmapY = bitmap.getY();

    // Sprawdzamy, czy kt�rykolwiek z wierzcho�k�w tr�jk�ta le�y w obr�bie bitmapy
    if (checkVertexCollisionWithBitmap(x0, y0, bitmapX, bitmapY, bitmapImage)) {
        return true;
    }
    if (checkVertexCollisionWithBitmap(x1, y1, bitmapX, bitmapY, bitmapImage)) {
        return true;
    }
    if (checkVertexCollisionWithBitmap(x2, y2, bitmapX, bitmapY, bitmapImage)) {
        return true;
    }

    // Je�li �aden wierzcho�ek nie le�y w bitmapie, zwr�� false
    return false;
}


bool checkRectangleCollisionWithBitmap(const Rectangle& rectangle, Player& bitmap, const sf::Image& bitmapImage) {
    // Pobierz wsp�rz�dne wierzcho�k�w prostok�ta
    float x0 = rectangle.getW0();
    float y0 = rectangle.getH0();
    float x1 = rectangle.getW1();
    float y1 = rectangle.getH0();  // (w1, h0)
    float x2 = rectangle.getW1();
    float y2 = rectangle.getH1();  // (w1, h1)
    float x3 = rectangle.getW0();
    float y3 = rectangle.getH1();  // (w0, h1)

    // Pobierz pozycj� bitmapy
    float bitmapX = bitmap.getX();
    float bitmapY = bitmap.getY();

    // Sprawdzamy, czy kt�rykolwiek z wierzcho�k�w prostok�ta le�y w obr�bie bitmapy
    if (checkVertexCollisionWithBitmap(x0, y0, bitmapX, bitmapY, bitmapImage)) {
        return true;
    }
    if (checkVertexCollisionWithBitmap(x1, y1, bitmapX, bitmapY, bitmapImage)) {
        return true;
    }
    if (checkVertexCollisionWithBitmap(x2, y2, bitmapX, bitmapY, bitmapImage)) {
        return true;
    }
    if (checkVertexCollisionWithBitmap(x3, y3, bitmapX, bitmapY, bitmapImage)) {
        return true;
    }

    // Je�li �aden z wierzcho�k�w nie le�y w obr�bie bitmapy
    return false;
}




int main() {
    Engine engine;
    Player player;
    Triangle triangle(450, -200, 450, -100, 500, -100, sf::Color::Cyan);
    Triangle triangle2(350, -50, 350, 0, 400, 0,sf::Color::Red);
    Triangle triangle3(250, 150, 250, 0, 300, 0, sf::Color::Magenta);

    




    Circle circle(775.0f, 0, 15.0f);
    Circle circle2(550.0f, -50, 15.0f);
    Circle circle3(450.0f, -250, 15.0f);
    Circle circle4(300.0f, -400, 15.0f);
    Circle circle5(200.0f, 0, 15.0f);
    Circle circle6(50.0f, -200, 15.0f);

    Rectangle rectangle(600, 0, 650.0f, -50.0f, sf::Color::Blue);
    Rectangle rectangle2(750.0f, 0, 720, -100.0f, sf::Color::Green);

    Player bitmap;
   // bitmap.setXY(400.f, 500.0f);
  //  bitmap.setPosition(400.f, 500.0f);


    if (!player.loadFromFile("ruch.png")) {
        std::cerr << "Nie mozna wczytac pliku bitmapy!" << std::endl;
       return -1;
    }

    //komenatrz

    // Inicjalizacja silnika
    engine.initializeVariables();
    engine.initWindow();
    engine.time();


   // if (!bitmap.loadFromFile("sprite_sheet.png")) {
    //    std::cerr << "Nie mozna wczytac pliku bitmapy!" << std::endl;
   //     return -1;
  //  }

    // G��wna p�tla gry
    while (engine.running()) {
        engine.update();

        // Czyszczenie
        engine.window->clear();

        // Rysowanie r�nych obiekt�w
      


    
        triangle.fall(*engine.window, 1.0f);
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


        if (checkPixelCollision(circle, bitmap, bitmap.getImage())) {
            exit(0);
        }

        if (checkPixelCollision(circle2, bitmap, bitmap.getImage())) {
            exit(0);
        }

        if (checkPixelCollision(circle2, bitmap, bitmap.getImage())) {
            exit(0);
        }

        if (checkPixelCollision(circle3, bitmap, bitmap.getImage())) {
            exit(0);
        }

        if (checkPixelCollision(circle4, bitmap, bitmap.getImage())) {
            exit(0);
        }

        if (checkPixelCollision(circle5, bitmap, bitmap.getImage())) {
            exit(0);
        }

        if (checkPixelCollision(circle6, bitmap, bitmap.getImage())) {
            exit(0);
        }



  
        if (checkTriangleCollisionWithBitmap(triangle, bitmap, bitmap.getImage())) {
            exit(0);
        }
        if (checkTriangleCollisionWithBitmap(triangle2, bitmap, bitmap.getImage())) {
            exit(0);
        }
        if (checkTriangleCollisionWithBitmap(triangle3, bitmap, bitmap.getImage())) {
            exit(0);
        }

        if (checkRectangleCollisionWithBitmap(rectangle, bitmap, bitmap.getImage())) {
            exit(0);
        }

        if (checkRectangleCollisionWithBitmap(rectangle2, bitmap, bitmap.getImage())) {
            exit(0);
        }




        bitmap.handleInput(*engine.window);
        bitmap.draw(*engine.window);


        player.handleInput(*engine.window);
        player.draw(*engine.window);

        // Wy�wietlanie
        engine.window->display();
    }

    return 0;
}
