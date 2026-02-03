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
    player.setTextureRect(sf::IntRect(0,5,40,48));
    player.scale(3,3);
    movespd = 600.f;
}

    void upate(float time) {
    bool isMoving = false;

    // เช็คทิศทาง
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { player.move(0, -1.f); isMoving = true; }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { player.move(0, 1.f);  isMoving = true; }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { player.move(-1.f, 0); isMoving = true; }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
         player.move(-1.f, 0);  
         isMoving = true; 
        // player.setRotation(180);
        }

    // ถ้ามีการกดปุ่มเดิน ให้เล่น Animation
    if (isMoving) {
        ttltime += time;
        if (ttltime >= 0.11f) {
            ttltime = 0;
            currenttime = (currenttime + 1) % 6; // วนลูป 6 เฟรม
            
            int newX = 4 + (currenttime * 40); // 40 คือระยะห่างระหว่างเฟรม (ต้องกะให้ตรงกับรูป)
            
            // *** จุดที่แก้: ต้องใช้ setTextureRect และครอบด้วย sf::IntRect ***
            player.setTextureRect(sf::IntRect(newX, 56, 40, 48));
        }
    } else {
        // ถ้าไม่เดิน ให้กลับไปเฟรมยืนนิ่ง (เฟรม 0)
        ttltime += time;
        if(ttltime >=0.2f){
            ttltime = 0;

            currenttime = (currenttime + 1) % 7; // วนลูป 6 เฟรม
            
            int newX = 0 + (currenttime * 40); // 40 คือระยะห่างระหว่างเฟรม (ต้องกะให้ตรงกับรูป)
            
            // *** จุดที่แก้: ต้องใช้ setTextureRect และครอบด้วย sf::IntRect ***
            player.setTextureRect(sf::IntRect(newX, 5, 40, 45));
        }
    }
}
    void draw(sf::RenderWindow& window){
        window.draw(player);
    }
    
};


