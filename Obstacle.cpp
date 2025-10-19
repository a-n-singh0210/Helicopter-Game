#include "Obstacle.h"

float Obstacle::lastObstacleX = 0; 


Obstacle::Obstacle(float x, float y, float speed, const sf::Texture& texture)
    : speed(speed), passed(false) {
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
    sprite.setScale(0.1f, 0.3f);
}

void Obstacle::update(float deltaTime) {
    sprite.move(-speed * deltaTime, 0); // Move left

    // Check if obstacle moved off-screen
    if (sprite.getPosition().x < -sprite.getGlobalBounds().width) {
        // Reset with a new random position, ensure spacing between obstacles
        resetPosition(800.f, sprite.getPosition().y);
    }
}


void Obstacle::draw(sf::RenderWindow& window) const { // Marked as const
    window.draw(sprite);
}

sf::FloatRect Obstacle::getBounds() const {
    return sprite.getGlobalBounds();
}

sf::Vector2f Obstacle::getPosition() const {
    return sprite.getPosition();
}
void Obstacle::resetPosition(float x, float y) {
    float newY = static_cast<float>(rand() % (400 - 100) + 100); // Random height between 100 and 400

    // Ensure obstacles are spaced horizontally
    float spacing = 300.0f;  // Set a fixed spacing for all obstacles

    // Move this obstacle to the right of the last one
    sprite.setPosition(lastObstacleX + spacing, newY);
    
    // If this is the first obstacle or lastObstacleX is 0, reset accordingly
    if (lastObstacleX == 0) {
        sprite.setPosition(x, newY); // Reset to the given x position if first
    }

    // Update lastObstacleX for the next obstacle
    lastObstacleX = sprite.getPosition().x;

    passed = false; // Reset passed status
}


void Obstacle::resetLastObstacleX() {
    lastObstacleX = 0; 
}


bool Obstacle::isPassed() const {
    return passed;
}

void Obstacle::markPassed() {
    passed = true;
}
