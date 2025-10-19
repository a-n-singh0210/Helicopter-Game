
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector> 
#include <iostream>
#include "Helicopter.h"
#include "Obstacle.h"
#include "LoginPage.h"  // Include the login page

const int windowWidth = 800;
const int windowHeight = 600;

enum GameState { LOGIN, PLAYING, GAME_OVER };  // Track game state

int main() {
    // Create the window
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Helicopter Game");

    // Load background texture
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("/Users/aarushinishantsingh/Desktop/C++/HelicopterGame/assets/background.png")) {
        std::cerr << "Error loading background texture!" << std::endl;
        return -1;
    }

    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(static_cast<float>(windowWidth) / backgroundTexture.getSize().x,
                               static_cast<float>(windowHeight) / backgroundTexture.getSize().y);  // Scale to fit window

    // Load textures
    sf::Texture helicopterTexture;
    if (!helicopterTexture.loadFromFile("/Users/aarushinishantsingh/Desktop/C++/HelicopterGame/assets/helicopter.png")) {
        std::cerr << "Error loading helicopter texture!" << std::endl;
        return -1;
    }

    sf::Texture obstacleTexture;
    if (!obstacleTexture.loadFromFile("/Users/aarushinishantsingh/Desktop/C++/HelicopterGame/assets/obstacle.png")) {
        std::cerr << "Error loading obstacle texture!" << std::endl;
        return -1;
    }

    // Load font for UI elements
    sf::Font font;
    if (!font.loadFromFile("/Users/aarushinishantsingh/Desktop/C++/HelicopterGame/assets/font.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
        return -1;
    }

    // Create login page
    LoginPage loginPage(font, windowWidth, windowHeight);

    // Create helicopter
    Helicopter helicopter(100, windowHeight / 2, 200.f, helicopterTexture);

    // Create obstacles
    std::vector<Obstacle> obstacles; //We're using dyanamic arrays - STL - Collection of items store karne ke liye.
    for (int i = 0; i < 5; ++i) {
        float yPos = static_cast<float>(rand() % (windowHeight - 50));  //Random positions for obstacles 
        obstacles.emplace_back(windowWidth + (i * 200), yPos, 100.f, obstacleTexture); // Adjust position
    }

    // Score management
    int score = 0;
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10, 10);

    // Game Over text
    sf::Text gameOverText;
gameOverText.setFont(font);
gameOverText.setCharacterSize(48);
gameOverText.setFillColor(sf::Color::Red);
gameOverText.setString("Game Over");

// Center the text
sf::FloatRect textRect = gameOverText.getLocalBounds(); // Get the bounds of the text
gameOverText.setOrigin(textRect.width / 2, textRect.height / 2); // Set the origin to the center
gameOverText.setPosition(windowWidth / 2, windowHeight / 2); // Position it in the center of the window


    bool gameOver = false;
    GameState gameState = LOGIN;  // Set initial

    // Initialize the clock for delta time
    sf::Clock clock;

    // Timer for obstacle delay
    float obstacleDelay = 1.0f; // Delay before obstacles start appearing
    float elapsedGameTime = 0.0f; // Time spent in PLAYING state

    // Game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Handle login page interactions
            if (gameState == LOGIN) {
                if (event.type == sf::Event::MouseButtonPressed) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (loginPage.isStartClicked(mousePos)) {
                        gameState = PLAYING;  // Start the game
                        // Reset game state
                        score = 0;
                        gameOver = false;
                        helicopter.setPosition(100, windowHeight / 2); // Reset helicopter position
                        for (auto& obstacle : obstacles) {
                            obstacle.resetPosition(windowWidth + (rand() % 100), static_cast<float>(rand() % (windowHeight - 50)));
                        }
                        elapsedGameTime = 0.0f; // Reset the game timer
                    } else if (loginPage.isQuitClicked(mousePos)) {
                        window.close();  // Quit the game
                    }
                }
            }
        }

        window.clear();

        // Handle different game states
        if (gameState == LOGIN) {
            // Draw the login page
            loginPage.draw(window);
        } else if (gameState == PLAYING && !gameOver) {
            // Update elapsed game time
            float deltaTime = clock.restart().asSeconds();  // Fixed clock initialization
            elapsedGameTime += deltaTime; // Increment elapsed time

            // Update helicopter movement
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                helicopter.move(0, -200 * deltaTime);  // Move up
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                helicopter.move(0, 200 * deltaTime);  // Move down
            }

            // Update obstacles only if the delay time has passed
            if (elapsedGameTime > obstacleDelay) {
                for (auto& obstacle : obstacles) {
                    obstacle.update(deltaTime);
                    if (obstacle.getPosition().x < -obstacle.getBounds().width) {
                        // Reset obstacle
                        obstacle.resetPosition(windowWidth + rand() % 100, static_cast<float>(rand() % (windowHeight - 50)));
                    }

                    // Check collision
                    if (helicopter.getBounds().intersects(obstacle.getBounds())) {
                        gameOver = true;  // Set game over if there is a collision
                        gameState = GAME_OVER;  // Change game state to GAME_OVER
                        break;
                    }

                    // Increase score
                    if (obstacle.getPosition().x < helicopter.getPosition().x && !obstacle.isPassed()) {
                        score++;
                        obstacle.markPassed();
                    }
                }
            }

            // Update score text
            scoreText.setString("Score: " + std::to_string(score));

            // Draw game elements
            window.draw(backgroundSprite);
            helicopter.draw(window);
            for (const auto& obstacle : obstacles) {
                obstacle.draw(window);
            }

            window.draw(scoreText);
        } else if (gameState == GAME_OVER) {
            // Draw Game Over text
            window.draw(gameOverText);
            // Wait for user input to return to the login screen
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                gameState = LOGIN; // Reset to login state
                Obstacle::resetLastObstacleX();
            }
        }

        window.display();
    }

    return 0;
}

