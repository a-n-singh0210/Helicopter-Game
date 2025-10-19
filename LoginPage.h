// LoginPage.h
#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <SFML/Graphics.hpp>

class LoginPage {
public:
    LoginPage(const sf::Font& font, int windowWidth, int windowHeight);
    void draw(sf::RenderWindow& window);
    bool isStartClicked(const sf::Vector2i& mousePos);
    bool isQuitClicked(const sf::Vector2i& mousePos);
    void handleInput(sf::RenderWindow& window, bool& gameStarted, bool& quitGame);

private:
    sf::RectangleShape startButton; 
    sf::RectangleShape quitButton;  
    sf::Text startText;             
    sf::Text quitText;              
    

    
    sf::Texture backgroundTexture; // To hold the background texture
    sf::Sprite backgroundSprite; 
};

#endif // LOGINPAGE_H
