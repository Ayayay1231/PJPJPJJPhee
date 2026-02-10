#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<iostream>
#include"Player.h"
#include "Menu.h"
#include"camera.h"
#include"Playercombat.h"
#include"Enemy.h"

enum class State {Preparing,Player_turn,Enemy_turn,Check_win,Finished};


int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "test rabob eieieeeieiie");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Blue);
    shape.setPosition(sf::Vector2f(400.f,300.f));
    PlayerC hero("Hero",100,45,40,3,"sprite/eps1.png");
    hero.sprite.setPosition(200,400);
    Enemy boss("HEE",150,20,5,0,"sprite/eps1.png");
    boss.sprite.setPosition(600 ,400);

    State curentState = State::Player_turn;

    Camera camera;

    sf::Clock clock;
    Player luffy("sprite/animate.png");
    Menu menu(window.getSize().x,window.getSize().y);
    luffy.setScale(5,5);
    sf::Font font;
    font.loadFromFile("CRA.ttf");
    if(!font.loadFromFile("CRA.ttf")){
        printf("Load font fail");
    }

    sf::Text title("HAI HITLER!!!",font,150) ;
    title.setFillColor(sf::Color::Cyan);
    title.setPosition(300,50);


    sf:: RectangleShape s2({150.f,150.f});
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(sf::Vector2f(250.f,250.f));

    sf::Texture eps;
    eps.loadFromFile("eps1.png");
    sf::Texture movements;
    movements.loadFromFile("cannotbre.png");

    sf::Sprite nice;
    nice.setTexture(eps);
    nice.setPosition(100.f,100.f);

    sf::Sprite move1;
    move1.setTexture(movements);
    move1.setPosition(600.f,500.f);

    sf::Music music;
    if(!music.openFromFile("EFN.wav")){
        return -1;

    }
    music.setLoop(true);
    music.setPitch(1.2f);
    music.setVolume(75.f);
    

    //sf::Font font(MinecraftRegular-Bmg3.ttf);

    while (window.isOpen()) {
        sf::Event event;
        float dt =clock.restart().asSeconds();
        while (window.pollEvent(event)) { //Game is working
            if (event.type == sf::Event::Closed)
                window.close();

            if(curentState == State::Player_turn && event.type == sf::Event::KeyPressed){
                hero.isGuarding = false;
                if(event.key.code == sf::Keyboard::Space){
                    boss.takeDamage(hero.atk);
                    std::cout << "hero attacks: " << hero.atk << std::endl;
                    std::cout << "///////////////////////////////////////////" << std::endl;
                    curentState = State::Check_win;
                   // curentState = State::Enemy_turn;
                }else if(event.key.code == sf::Keyboard::F ){
                hero.isGuarding = true;
                curentState = State::Enemy_turn;
            }
            }
        

    if(curentState == State::Check_win){
        if(boss.hp<=0){ 
            boss.hp = 0 ;
            curentState = State::Finished;}
        else curentState = State::Enemy_turn;}
        
    if(curentState == State::Enemy_turn){    

        boss.takeAction(hero);
        if(hero.hp <= 0 ){
            hero.hp = 0;
            curentState = State::Finished;

        }else{
            curentState = State::Player_turn;
        }
    }
    if(curentState == State::Check_win){
        if(boss.hp <= 0){
            boss.hp = 0;
           
            curentState = State::Finished;


        }else{
            curentState = State::Enemy_turn;
        }
    }
          //  window.setView(camera.GetView(window.getSize()));
            
           /* switch (event.type)
            {
            case sf::Event::KeyReleased:
                switch(event.key.code){
                    case sf::Keyboard::Up:
                    menu.MoveUp();
                    break;

                    case sf::Keyboard::Down:
                    menu.MoveDown();
                    break;

                   // case sf::Keyboard::Return:
                 //   switch(menu.getPressItem())
                }
                break;
            
            default:
                break;
            }*/

       // luffy.upate(dt);

             
        }
       // luffy.upate(dt);

           
        
        window.clear();
        if(curentState == State::Finished){
            static bool print = false ;
            if(!print){
            if(hero.hp <= 0){
                std::cout << "you lose" << std::endl;
            }else if(boss.hp <= 0){
                std::cout << "yeyeye" << std::endl;
            }
            print = true;
        }
        }
       /* if(curentState == State::Player_turn){

        }else if(curentState == State::Enemy_turn){
            boss.takeAction(hero);
            curentState = State::Player_turn;
        }*/
        hero.draw(window);
        boss.draw(window);
      
       
        
      //  window.draw(s2);
        window.display();

        }

         return 0;
    }
    

