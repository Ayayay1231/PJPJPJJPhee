#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<iostream>
#include"Player.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 1080), "test rabob eieieeeieiie");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Blue);
    shape.setPosition(sf::Vector2f(400.f,300.f));

    sf::Clock clock;
    Player luffy("sprite/animate.png");
    

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
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            switch (event.type)
            {
            case sf::Event::KeyReleased:
                switch(event.key.code){
                    case sf::Keyboard::Up:
                    menu.MoveUp();
                    break;

                    case sf::Keyboard::Down:
                    menu.MoveDown();
                    break;
                }
                break;
            
            default:
                break;
            }

       // luffy.upate(dt);

             
        }
        luffy.upate(dt);
           
        
        window.clear();
      // window.draw(title);
      //  window.draw(nice);
       // window.draw(move1);
       luffy.draw(window);
       
        
      //  window.draw(s2);
        window.display();

        }

         return 0;
    }
    

