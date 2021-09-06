#include "Engine.h"

using namespace MoldEngine;

bool Input::isKeyDown(Key key) {
    return sf::Keyboard::isKeyPressed(key);
}

Input::MouseState Input::getMouseState() {
    Input::MouseState mouseState;
    if(WindowFocus) {
        sf::Vector2f mousePos = GlobalWindow.mapPixelToCoords(sf::Mouse::getPosition(GlobalWindow));
        mouseState.position = {mousePos.x,mousePos.y};
        mouseState.LMB = sf::Mouse::isButtonPressed(sf::Mouse::Left);
        mouseState.RMB = sf::Mouse::isButtonPressed(sf::Mouse::Right);
    }
    return mouseState;
}