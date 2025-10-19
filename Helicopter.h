#ifndef HELICOPTER_H
#define HELICOPTER_H

#include <SFML/Graphics.hpp>

class Helicopter {
public:
    Helicopter(float x, float y, float speed, const sf::Texture& texture);

    void move(float dx, float dy);
    void draw(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;
    sf::Vector2f getPosition() const;
    void setPosition(float x, float y);


private:
    sf::Sprite sprite;//visuals of helicopter 
    sf::Texture texture;
};

#endif // HELICOPTER_H
