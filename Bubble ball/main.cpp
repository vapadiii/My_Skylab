#define _CRT_SECURE_NO_WARNINGS 1
#include <SFML/Graphics.hpp>
#include <stdio.h>
//#include <time.h>
//#include <string.h>
#include <iostream>
#include "Menu.h"

//using namespace sf;

/*
void login() {

    RenderWindow app(VideoMode(400, 400), "Login");
    char m;
    char name[30];
    //char pass[8];
    printf("Username : ");
    scanf(" %s", name);
}

void game() {
    srand(time(0));

    RenderWindow app(VideoMode(520, 450), "Bubble ball");
    app.setFramerateLimit(60);

    Texture t1, t2, t3, t4;
    t1.loadFromFile("images/block01.png");
    t2.loadFromFile("images/black_background.jpg");
    t3.loadFromFile("images/ball.png");
    t4.loadFromFile("images/paddle.png");

    Sprite sBackground(t2), sBall(t3), sPaddle(t4);
    sPaddle.setPosition(300, 440);

    Sprite block[1000];

    int n = 0;

    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
        {
            block[n].setTexture(t1);
            block[n].setPosition(i * 43, j * 20);
            n++;
        }

    float dx = 6, dy = 5;
    float x = 300, y = 300;

    while (app.isOpen())
    {
        Event e;
        while (app.pollEvent(e))
        {
            if (e.type == Event::Closed)
                app.close();
        }

        x += dx;
        for (int i = 0; i < n; i++)
            if (FloatRect(x + 3, y + 3, 6, 6).intersects(block[i].getGlobalBounds()))
            {
                block[i].setPosition(-100, 0); dx = -dx;
            }

        y += dy;
        for (int i = 0; i < n; i++)
            if (FloatRect(x + 3, y + 3, 6, 6).intersects(block[i].getGlobalBounds()))
            {
                block[i].setPosition(-100, 0); dy = -dy;
            }

        if (x < 0 || x>520)  dx = -dx;
        if (y < 0 || y>450)  dy = -dy;

        if (Keyboard::isKeyPressed(Keyboard::Right)) sPaddle.move(6, 0);
        if (Keyboard::isKeyPressed(Keyboard::Left)) sPaddle.move(-6, 0);

        if (FloatRect(x, y, 12, 12).intersects(sPaddle.getGlobalBounds())) dy = -(rand() % 5 + 2);

        sBall.setPosition(x, y);

        app.clear();
        app.draw(sBackground);
        app.draw(sBall);
        app.draw(sPaddle);

        for (int i = 0; i < n; i++)
            app.draw(block[i]);

        app.display();
    }
}
*/

int main() 
{
    
    sf::RenderWindow window(sf::VideoMode(1080, 720), "Bubble ball");

    Menu menu(window.getSize().x, window.getSize().y);

    sf::Texture texture;
    if (!texture.loadFromFile("playPage.JPG")) {
        //handle error
    }
    sf::Sprite background;
    background.setTexture(texture);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::KeyReleased:
                switch (event.key.code) {
                case sf::Keyboard::Up:
                    menu.MoveUp();
                    break;

                case sf::Keyboard::Down:
                    menu.MoveDown();
                    break;

                case sf::Keyboard::Return:
                    switch (menu.GetPressedItem())
                    {
                    case 0 :
                        std::cout << "Play has been pressed" << std::endl;
                        //go to state
                        break;

                    case 1 :
                        std::cout << "LeaderBoard has been pressed" << std::endl;
                        //go to state
                        break;

                    case 2:
                        window.close();
                        break;
                    }
                    break;

                }

                break;

            case sf::Event::Closed:
                window.close();
                break;
            }
        }
        window.clear();
        window.draw(background); //draw Background Play Page
        menu.draw(window);
        window.display();
    }
    
    //game();

    return 0;
}