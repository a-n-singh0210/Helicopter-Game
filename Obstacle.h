#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <SFML/Graphics.hpp>

class Obstacle {
public:
    Obstacle(float x, float y, float speed, const sf::Texture& texture);

    void update(float deltaTime);
    void draw(sf::RenderWindow& window)const;//marked const 
    sf::FloatRect getBounds() const;
    sf::Vector2f getPosition() const;
    void resetPosition(float x, float y);
    bool isPassed() const;
    void markPassed();
    static void resetLastObstacleX();

private:
    sf::Sprite sprite;
    float speed;
    bool passed; // To track if obstacle has been passed
    static float lastObstacleX;
};

#endif // OBSTACLE_H
