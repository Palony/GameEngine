#include "Engine.h"
#include "game.h"



PrimitiveRenderer primitiverenderer;


/**
 * @brief Funkcja sprawdzaj¹ca kolizjê pomiêdzy punktem ko³a a bitmap¹.
 *
 * Funkcja iteruje przez punkty ko³a i sprawdza, czy którykolwiek z nich
 * znajduje siê w obrêbie bitmapy, a tak¿e czy odpowiadaj¹cy mu piksel
 * nie jest przezroczysty. Jeœli tak, zwraca true, oznaczaj¹c kolizjê.
 *
 * @param circle Ko³o, którego kolizja jest sprawdzana.
 * @param bitmap Obiekt reprezentuj¹cy bitmapê (np. postaæ gracza).
 * @param bitmapImage Obrazek bitmapy (zawiera dane o pikselach).
 * @return true, jeœli nast¹pi³a kolizja, false w przeciwnym przypadku.
 */

bool checkPixelCollision(const Circle& circle, Player& bitmap, const sf::Image& bitmapImage) {
    // Pobierz punkty ko³a
    const auto& points = circle.getPoints();

    // Pobierz w³aœciwoœci bitmapy
    float bitmapX = bitmap.getX();
    float bitmapY = bitmap.getY();
    float bitmapWidth = bitmapImage.getSize().x;
    float bitmapHeight = bitmapImage.getSize().y;

    // Iteracja po punktach ko³a
    for (const auto& point : points) {
        // Pozycja punktu ko³a
        float x = point.x;
        float y = point.y;

        // SprawdŸ, czy punkt mieœci siê w granicach bitmapy
        if (x >= bitmapX && x < bitmapX + bitmapWidth &&
            y >= bitmapY && y < bitmapY + bitmapHeight) {
            // Przelicz wspó³rzêdne na lokalny uk³ad bitmapy
            int localX = static_cast<int>(x - bitmapX);
            int localY = static_cast<int>(y - bitmapY);

            // Sprawdzamy, czy piksel w tym miejscu nie jest przezroczysty
            sf::Color pixelColor = bitmapImage.getPixel(localX, localY);
            if (pixelColor.a != 0) { // Jeœli kana³ alfa jest ró¿ny od 0, to piksel nie jest przezroczysty
                return true; // Kolizja, poniewa¿ piksel nie jest przezroczysty
            }
        }
    }

    // Brak kolizji
    return false;
}


/**
 * @brief Funkcja sprawdzaj¹ca, czy punkt (px, py) le¿y w obrêbie bitmapy.
 *
 * Sprawdza, czy wspó³rzêdne punktu mieszcz¹ siê w granicach prostok¹tnej bitmapy.
 *
 * @param px Wspó³rzêdna x punktu.
 * @param py Wspó³rzêdna y punktu.
 * @param bitmapX Wspó³rzêdna x lewego górnego rogu bitmapy.
 * @param bitmapY Wspó³rzêdna y lewego górnego rogu bitmapy.
 * @param bitmapImage Obiekt obrazka bitmapy, w którym sprawdzamy kolizjê.
 * @return true, jeœli punkt le¿y w obrêbie bitmapy, false w przeciwnym przypadku.
 */

bool checkVertexCollisionWithBitmap(float px, float py, float bitmapX, float bitmapY, const sf::Image& bitmapImage) {
    // Funkcja sprawdzaj¹ca, czy punkt (px, py) znajduje siê w obrêbie bitmapy
    sf::Vector2u size = bitmapImage.getSize();

    // Sprawdzenie, czy punkt le¿y w obrêbie bitmapy
    return px >= bitmapX && px < bitmapX + size.x && py >= bitmapY && py < bitmapY + size.y;
}

/**
 * @brief Funkcja sprawdzaj¹ca kolizjê trójk¹ta z bitmap¹.
 *
 * Sprawdza, czy którykolwiek z wierzcho³ków trójk¹ta znajduje siê w obrêbie bitmapy.
 *
 * @param triangle Trójk¹t, którego kolizja z bitmap¹ jest sprawdzana.
 * @param bitmap Obiekt reprezentuj¹cy bitmapê (np. postaæ gracza).
 * @param bitmapImage Obrazek bitmapy (zawiera dane o pikselach).
 * @return true, jeœli nast¹pi³a kolizja, false w przeciwnym przypadku.
 */

bool checkTriangleCollisionWithBitmap(const Triangle& triangle, Player& bitmap, const sf::Image& bitmapImage) {
    // Pobieramy pozycje wierzcho³ków trójk¹ta
    float x0 = triangle.getX0(); // Funkcje do pobierania pozycji wierzcho³ków trójk¹ta
    float y0 = triangle.getY0();

    float x1 = triangle.getX1();
    float y1 = triangle.getY1();

    float x2 = triangle.getX2();
    float y2 = triangle.getY2();

    // Pobieramy pozycjê bitmapy
    float bitmapX = bitmap.getX();
    float bitmapY = bitmap.getY();

    // Sprawdzamy, czy którykolwiek z wierzcho³ków trójk¹ta le¿y w obrêbie bitmapy
    if (checkVertexCollisionWithBitmap(x0, y0, bitmapX, bitmapY, bitmapImage)) {
        return true;
    }
    if (checkVertexCollisionWithBitmap(x1, y1, bitmapX, bitmapY, bitmapImage)) {
        return true;
    }
    if (checkVertexCollisionWithBitmap(x2, y2, bitmapX, bitmapY, bitmapImage)) {
        return true;
    }

    // Jeœli ¿aden wierzcho³ek nie le¿y w bitmapie, zwróæ false
    return false;
}

/**
 * @brief Funkcja sprawdzaj¹ca kolizjê prostok¹ta z bitmap¹.
 *
 * Sprawdza, czy którykolwiek z wierzcho³ków prostok¹ta le¿y w obrêbie bitmapy.
 *
 * @param rectangle Prostok¹t, którego kolizja z bitmap¹ jest sprawdzana.
 * @param bitmap Obiekt reprezentuj¹cy bitmapê (np. postaæ gracza).
 * @param bitmapImage Obrazek bitmapy (zawiera dane o pikselach).
 * @return true, jeœli nast¹pi³a kolizja, false w przeciwnym przypadku.
 */

bool checkRectangleCollisionWithBitmap(const Rectangle& rectangle, Player& bitmap, const sf::Image& bitmapImage) {
    // Pobierz wspó³rzêdne wierzcho³ków prostok¹ta
    float x0 = rectangle.getW0();
    float y0 = rectangle.getH0();
    float x1 = rectangle.getW1();
    float y1 = rectangle.getH0();  // (w1, h0)
    float x2 = rectangle.getW1();
    float y2 = rectangle.getH1();  // (w1, h1)
    float x3 = rectangle.getW0();
    float y3 = rectangle.getH1();  // (w0, h1)

    // Pobierz pozycjê bitmapy
    float bitmapX = bitmap.getX();
    float bitmapY = bitmap.getY();

    // Sprawdzamy, czy którykolwiek z wierzcho³ków prostok¹ta le¿y w obrêbie bitmapy
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

    // Jeœli ¿aden z wierzcho³ków nie le¿y w obrêbie bitmapy
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
    bitmap.setXY(400.f, 500.0f);
  //  bitmap.setPosition(400.f, 500.0f);


    //if (!player.loadFromFile("ruch.png")) {
     //   std::cerr << "Nie mozna wczytac pliku bitmapy!" << std::endl;
    //   return -1;
   // }

    //komenatrz

    // Inicjalizacja silnika
    engine.initializeVariables();
    engine.initWindow();
    engine.time();


   // if (!bitmap.loadFromFile("sprite_sheet.png")) {
    //    std::cerr << "Nie mozna wczytac pliku bitmapy!" << std::endl;
   //     return -1;
  //  }

    // G³ówna pêtla gry
    while (engine.running()) {
        engine.update();

        // Czyszczenie
        engine.window->clear();

        // Rysowanie ró¿nych obiektów
      


    // Rysowanie trójk¹tów
        triangle.fall(*engine.window, 1.0f);
        triangle.draw(*engine.window);
        triangle2.fall(*engine.window, 1.0f);
        triangle2.draw(*engine.window);
        triangle3.fall(*engine.window, 1.0f);
        triangle3.draw(*engine.window);

        // Rysowanie prostok¹tów
        rectangle.fall(*engine.window, 1.0f);
        rectangle.draw(*engine.window);
        rectangle2.fall(*engine.window, 1.0f);
        rectangle2.draw(*engine.window);
        // Rysowanie kó³
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

        // Sprawdzanie kolizji z okrêgami (jeœli kolizja, koñczymy grê)
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


        // Sprawdzanie kolizji z trójk¹tami (jeœli kolizja, koñczymy grê)
  
        if (checkTriangleCollisionWithBitmap(triangle, bitmap, bitmap.getImage())) {
            engine.closeEngine();
        }
        if (checkTriangleCollisionWithBitmap(triangle2, bitmap, bitmap.getImage())) {
            engine.closeEngine();
        }
        if (checkTriangleCollisionWithBitmap(triangle3, bitmap, bitmap.getImage())) {
            engine.closeEngine();
        }
        // Sprawdzanie kolizji z prostok¹tami (jeœli kolizja, koñczymy grê)
        if (checkRectangleCollisionWithBitmap(rectangle, bitmap, bitmap.getImage())) {
            exit(0);
        }

        if (checkRectangleCollisionWithBitmap(rectangle2, bitmap, bitmap.getImage())) {
            exit(0);
        }



        // Obs³uga wejœcia od gracza
        bitmap.handleInput(*engine.window);
        // Rysowanie bitmapy gracza
        bitmap.draw(*engine.window);


      //  player.handleInput(*engine.window);
      //  player.draw(*engine.window);

        // Wyœwietlanie
        engine.window->display();
    }

    return 0;
}
