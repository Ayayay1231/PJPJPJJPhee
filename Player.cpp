#include<iostream>
#include<SFML/Graphics.hpp>
#include<stdio.h>

class Player{
    private:
    sf::Sprite player;
    sf::Texture texter;
    float movespd,ttltime = 0;
    int currenttime = 0;


    public:
    
    Player(std::string file){
        //texter.loadFromFile("sprite\animate.png");
       if(!texter.loadFromFile(file)){
        std::cout << "cannot load "<< file <<std::endl;

    }
    player.setTexture(texter);
    player.setTextureRect(sf::IntRect(4,56,36,48));
    movespd = 300.f;
}

    void upate(float time) {
    bool isMoving = false;

    // เช็คทิศทาง
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { player.move(0, -movespd * time); isMoving = true; }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { player.move(0, movespd * time);  isMoving = true; }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { player.move(-movespd * time, 0); isMoving = true; }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { player.move(movespd * time, 0);  isMoving = true; }

    // ถ้ามีการกดปุ่มเดิน ให้เล่น Animation
    if (isMoving) {
        ttltime += time;
        if (ttltime >= 0.1f) {
            ttltime = 0;
            currenttime = (currenttime + 1) % 6; // วนลูป 6 เฟรม
            
            int newX = 4 + (currenttime * 40); // 40 คือระยะห่างระหว่างเฟรม (ต้องกะให้ตรงกับรูป)
            
            // *** จุดที่แก้: ต้องใช้ setTextureRect และครอบด้วย sf::IntRect ***
            player.setTextureRect(sf::IntRect(newX, 56, 36, 48));
        }
    } else {
        // ถ้าไม่เดิน ให้กลับไปเฟรมยืนนิ่ง (เฟรม 0)
        currenttime = 0;
        player.setTextureRect(sf::IntRect(4, 56, 36, 48));
    }
}
    void draw(sf::RenderWindow& window){
        window.draw(player);
    }
    
};


