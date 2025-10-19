#include "LoginPage.h"
LoginPage::LoginPage(const sf::Font& font, int windowWidth, int windowHeight) {
    // Load the background texture
    if (!backgroundTexture.loadFromFile("/Users/aarushinishantsingh/Desktop/C++/HelicopterGame/assets/login_bg.png")) {
        // Handle error if the texture fails to load
    }

    // Set the background sprite
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(0, 0); // Position the background at (0, 0)
    backgroundSprite.setScale(static_cast<float>(windowWidth) / backgroundTexture.getSize().x,
                              static_cast<float>(windowHeight) / backgroundTexture.getSize().y);

    // Set up the Start button
    startText.setFont(font);
    startText.setString("Start");
    startText.setCharacterSize(40);
    startText.setFillColor(sf::Color::White);
    startText.setPosition(windowWidth / 2 - 50, windowHeight / 2 - 100);

    // Set up the Quit button
    quitText.setFont(font);
    quitText.setString("Quit");
    quitText.setCharacterSize(40);
    quitText.setFillColor(sf::Color::White);
    quitText.setPosition(windowWidth / 2 - 50, windowHeight / 2);

    //  invisible rectangles for button hit detection
    startButton.setSize(sf::Vector2f(150, 50));
    startButton.setPosition(windowWidth / 2 - 75, windowHeight / 2 - 120);

    quitButton.setSize(sf::Vector2f(150, 50));
    quitButton.setPosition(windowWidth / 2 - 75, windowHeight / 2 + 10);
}

void LoginPage::draw(sf::RenderWindow& window) {
    window.draw(backgroundSprite); // Draw the background first
    window.draw(startText);
    window.draw(quitText);
}

bool LoginPage::isStartClicked(const sf::Vector2i& mousePos) {
    return startButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
}

bool LoginPage::isQuitClicked(const sf::Vector2i& mousePos) {
    return quitButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
}

void LoginPage::handleInput(sf::RenderWindow& window, bool& gameStarted, bool& quitGame) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            quitGame = true;
        }

        if (event.type == sf::Event::MouseButtonPressed) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);

            if (isStartClicked(mousePos)) {
                gameStarted = true;
            } else if (isQuitClicked(mousePos)) {
                quitGame = true;
            }
        }
    }
}
