#include "engine.h"

MoldEngine::MoldEngine(int Width,int Height) {
    new (&Window) sf::RenderWindow(sf::VideoMode(Width, Height), "MoldEngine");
}

void MoldEngine::Run(void(*OnRedraw)(),void(*OnClose)()) {
    while(Window.isOpen()) {
        sf::Event event;
        while (Window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                Window.close();
                OnClose();
            }
        }
    
        Window.clear();
        OnRedraw();
        Window.display();
    }
}