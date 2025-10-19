#include "Helicopter.h"

Helicopter::Helicopter(float x, float y, float speed, const sf::Texture& texture) { //Parameterised Constructor 
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
    sprite.setScale(0.3f, 0.3f); 
}

void Helicopter::move(float dx, float dy) {
    sprite.move(dx, dy);
}

void Helicopter::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

sf::FloatRect Helicopter::getBounds() const {
    return sprite.getGlobalBounds();
}

sf::Vector2f Helicopter::getPosition() const {
    return sprite.getPosition();
}
void Helicopter::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}
