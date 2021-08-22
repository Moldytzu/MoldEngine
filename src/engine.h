#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class MoldEngine {
private:
    sf::RenderWindow Window;
public:
    MoldEngine(int Width, int Height);
    void Run(void(*OnRedraw)(),void(*OnClose)());
};