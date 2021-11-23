#define _CRT_SECURE_NO_WARNINGS 1
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <SFML/Audio.hpp>

#include "Menu.h"
#include "Monster.h"
#include "Desktop.h"
#include "Score.h"
#include "Bullet.h"
#include "GameOver.h"
#include "Leaderboard.h"
#include "Player.h"
#include "Heart.h"
#include "Enemy.h"
#include "Gift.h"
#include "GameSound.h"

#define SHOW_MENU 1
#define PLAY_GAME 2
#define LEADER_BOARD 3
#define EXIT 4
#define GAME_OVER 9

using namespace std;
using namespace sf;

#define ENEMY_MAX 50
#define BULLET_MAX 100

void game() {
    srand(time(0));
    sf::RenderWindow window(sf::VideoMode(1152, 800), "SKYLAB");
    
    //
    sf::Clock clock;
    sf::Clock clock2;
    //sf::Clock clockBonus;
    clock.restart();
    clock2.restart();

    //clockBonus.restart();
    int state = SHOW_MENU;
    bool startGame = false;
    bool shoot = false;
    int n = 0;
    int enemyNo = 0;
    int point = 0;

    //int pointBonus = 0;
    int count = 0;
    //int heart = 3;
    /*
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("sound1.wav")) {
        
    }

    sf::Sound sound;
    sound.setBuffer(buffer);
    */

    //..Music
    sf::Music music;
    if (!music.openFromFile("music2.ogg")) {
        //
    }
    music.play();
    music.setLoop(true);

    

    Player player(window.getSize().x, window.getSize().y);
    Heart heart(window.getSize().x, window.getSize().y);
    Bullet bullets[BULLET_MAX];

    Desktop desktop(window.getSize().x, window.getSize().y);
    Menu menu(window.getSize().x, window.getSize().y);
    Leaderboard leaderboard(window.getSize().x, window.getSize().y);
    GameOver gameOver(window.getSize().x, window.getSize().y);
    GameSound gameSound(0);
    
    Gift gift;
    Score score;

    Enemy enemys[ENEMY_MAX];
    Enemy* abc;
    std::string playerName;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (state == GAME_OVER) {
                if (event.type == sf::Event::TextEntered) {
                    if (event.KeyPressed == sf::Keyboard::BackSpace && playerName.size() != 0) {
                        //playerName.pop_back();
                        //playerName.erase(playerName.size() - 1, 1);
                        //std::cout << "back space" << std::endl;
                    }
                    if (event.text.unicode < 128) {
                        playerName.push_back((char)event.text.unicode);
                        std::cout << playerName << std::endl;
                    }
                    else {
                        if (playerName.size() != 0) {
                            //playerName.pop_back();
                            playerName.erase(playerName.size() - 1, 1);
                            std::cout << playerName << std::endl;
                        }
                    }
                    //gameOver.setPlayerName(playerName);
                }
            }

            if (event.type == Event::KeyPressed)
            {
                //std::cout << "keyboard press" << std::endl;
                switch (event.key.code)
                {

                case sf::Keyboard::BackSpace:
                    std::cout << "back space" << std::endl;
                    /*
                    if (playerName.size() != 0) {
                        //playerName.pop_back();
                        playerName.erase(playerName.size() - 1, 1);
                        std::cout << playerName << std::endl;
                    }
                    */
                    break;

                case sf::Keyboard::Escape:
                    std::cout << "press key up" << std::endl;
                    window.close();
                    // bool alive = !player.isAlive();
                     //player.setAlive(alive);
                    break;

                case sf::Keyboard::Space:
                    std::cout << "space" << std::endl;
                    shoot = true;
                    //shoot = !player.isAlive();
                    //player.setAlive(shoot);
                    break;

                case sf::Keyboard::Down:
                    std::cout << "press key down" << std::endl;
                    menu.MoveDown();
                    break;

                case sf::Keyboard::Up:
                    std::cout << "press key up" << std::endl;
                    menu.MoveUp();
                    break;

                case sf::Keyboard::Enter:
                    //std::cout << menu.GetPressedItem() << std::endl;
                    //menu.GetPressedItem();
                    if (state == SHOW_MENU) {
                        int menuSelect = menu.GetPressedItem();
                        std::cout << menuSelect << std::endl;
                        if (menuSelect == 0) {
                            state = PLAY_GAME;
                            startGame = true;
                        }
                        else if (menuSelect == 1) {
                            state = LEADER_BOARD;
                        }
                        else if (menuSelect == 2) {
                            state = EXIT;
                            window.close();
                        }
                    }
                    else if (state == LEADER_BOARD) {
                        state = SHOW_MENU;
                    }
                    else {
                        if (state == GAME_OVER) {
                            std::cout << "game over" << std::endl;

                            std::cout << playerName << std::endl;
                            leaderboard.saveScore(playerName, point);

                            //menuSelect = -1;
                            state = SHOW_MENU;
                        }
                    }
                    break;
                }
            }

            if (event.type == Event::Closed)
            {
                window.close();
            }
        }
        //hamdle

        //window.clear();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player.moveLeft();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player.moveRight();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            player.moveUp();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            player.moveDown();
        }

        window.clear();

        desktop.draw(window, 1);

        switch (state) {
        case SHOW_MENU:
            menu.draw(window);
            break;

        case LEADER_BOARD:
            leaderboard.draw(window);
            break;

        case GAME_OVER:
            gameOver.draw(window);
            gameOver.setPlayerName(playerName);
            break;

        case PLAY_GAME:

            if (startGame) {

                clock.restart();
                clock2.restart();

                //player
                player.setAlive(true);
                player.setPosition(576, 650);
                playerName = "";
                //heart = 3;
                point = 0;

                //..heart
                heart.initHeart();

                //..gift
                gift.setAlive(false);

                //enemy
                for (int i = 0; i < ENEMY_MAX; i++) {
                    enemys[i].setAlive(false);
                }

                //bullet
                for (int i = 0; i < BULLET_MAX; i++) {
                    bullets[i].setAlive(false);
                }


                startGame = false;
            }

            heart.draw(window);

            sf::Time t2 = clock2.getElapsedTime();
            float  numt2 = t2.asSeconds();
            if (numt2 > 10) {

                if (gift.isAlive() == false) {
                    gift.setPosition(rand() % window.getSize().x - 100, 0);
                    gift.setAlive(true);
                }
               
                numt2 = 0;
                clock2.restart();
            }
            
            if (gift.isAlive()) {
                gift.draw(window);
                gift.move();

                if (player.collisionNew(gift.sprite)) {
                    gift.setAlive(false);
                    point += 10;
                    gameSound.play(2);
                }

                if (gift.sprite.getPosition().y >= window.getSize().y) {

                    std::cout << "gift over screen" << std::endl;
                    gift.setAlive(false);

                }
            }

            sf::Time t1 = clock.getElapsedTime();
            //std::cout << t1.asSeconds() << std::endl;
            float  num = t1.asSeconds();

            if (num > 0.2) {

                if (enemys[enemyNo].isAlive() == false) {
                    enemys[enemyNo].setPosition(rand() % window.getSize().x - 100, 0);
                    enemys[enemyNo].setAlive(true);
                }
                enemyNo++;
                if (enemyNo >= ENEMY_MAX) enemyNo = 0;

                for (int i = 0; i < ENEMY_MAX; i++) {
                    if (enemys[i].isAlive()) {
                    }
                    else {
                        std::cout << t1.asSeconds() << std::endl;
                        //enemys[i].setPosition(rand() % window.getSize().x - 100, 0);
                        //enemys[i].setAlive(true);
                    }

                }

                num = 0;
                clock.restart();
            }

            score.draw(window, point);

            for (int i = 0; i < ENEMY_MAX; i++) {
                if (enemys[i].isAlive()) {
                    enemys[i].draw(window);

                    //enemys[enemyNo].setPosition(rand() % window.getSize().x - 100, 0);
                   //int nMove = rand() % 1000;
                    //enemys[i].setDirection(nMove);

                    int nMove = i%5;
                    enemys[i].move(nMove);

                    if (enemys[i].sprite.getPosition().y >= window.getSize().y) {

                        std::cout << "over screen" << std::endl;
                        enemys[i].setAlive(false);

                        //enemys[i].setPosition(rand() % window.getSize().x - 100, 0);
                        //enemys[i].setAlive(true);
                    }
                }
            }

            if (player.isAlive()) {
                std::cout << "playing" << std::endl;
                //player.setPosition(540, 550);
                player.draw(window);
                for (int i = 0; i < n; i++) {
                    if (bullets[i].isAlive()) {
                        bullets[i].draw(window);
                        bullets[i].sprite.move(0.0, -5);

                        for (int k = 0; k < ENEMY_MAX; k++) {
                            if (enemys[k].isAlive()) {
                                if (enemys[k].collision(bullets[i].sprite)) {
                                    enemys[k].setAlive(false);
                                    bullets[i].setAlive(false);
                                    point++;
                                    //sound.play();
                                    gameSound.play(1);
                                }
                            }

                        }
                    }
                }
                for (int k = 0; k < ENEMY_MAX; k++) {
                    if (enemys[k].isAlive()) {
                        if (player.collisionNew(enemys[k].sprite)) {
                            if (player.isBonusTime()) {
                                enemys[k].setAlive(false);
                                point++;
                            }
                            else {
                                std::cout << "playing die" << std::endl;
                                if (!player.isBonusTime()) {
                                    heart.decrease();
                                    if (heart.getHeart() == 0) {
                                        player.setAlive(false);
                                        player.setPosition(576, 650);
                                        state = GAME_OVER;

                                        gameSound.play(3);
                                    }
                                    /*
                                    heart--;
                                    if (heart <= 0) {
                                        player.setAlive(false);
                                        player.setPosition(576, 650);
                                        state = GAME_OVER;
                                    }
                                    */
                                }
                                enemys[k].setAlive(false);
                            }
                        }
                    }

                }


                if (shoot) {
                    if (player.isBonusTime()) {
                        bullets[n].setPosition(player.getPosition().x + 100, player.getPosition().y - 10);
                    }
                    else {
                        bullets[n].setPosition(player.getPosition().x + 30, player.getPosition().y - 10);
                        bullets[n].setAlive(true);
                        n++;
                        if (n >= 100) n = 0;
                        shoot = false;
                    }
                }
            }

            break;
        }   
        window.display();
    }
}

int main() {
    
    /*
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("sound1.wav")) {
        return -1;
    }

    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.play();
    

    
    sf::Music music;
    if (!music.openFromFile("music1.ogg")) {
        //
    }
    music.play();
    music.setLoop(true);
    */
    

    game();
    return 0;
}
