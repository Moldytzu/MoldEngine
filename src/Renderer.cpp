#include "Engine.h"

using namespace MoldEngine;

//Engine

Renderer::Renderer(int Width,int Height) {
    new (&Window) sf::RenderWindow(sf::VideoMode(Width, Height), "MoldEngine");
    
    if(!Font.loadFromFile("gameFiles/engine/font.ttf")) {
        Logging::Error("Failed to load font!");
        exit(-1);
    }

    Text.setFont(Font);
    Text.setCharacterSize(24);
    Text.setFillColor(sf::Color::White);
}

void Renderer::Run(void(*OnRedraw)(Renderer*,float),void(*OnClose)()) {
    sf::Clock deltaClock;
    float dt = 0;
    while(Window.isOpen()) {
        sf::Event event;
        while (Window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                Window.close();
                OnClose();
            }
        }

        Cursor.Y = 0;
        Cursor.X = 0;
        Window.clear();
        OnRedraw(this,dt);
        Window.display();
        dt = deltaClock.restart().asSeconds();
    }
}

void Renderer::DrawText(const char* text) {
    Text.setString(text);
    Text.setPosition(Cursor.X,Cursor.Y);
    sf::Vector2f vector = Text.getPosition();
    Cursor.X = vector.x+Text.getGlobalBounds().width+3;
    Cursor.Y = vector.y;
    Window.draw(Text);
}

void Renderer::DrawText(const char* text,Point point) {
    Text.setString(text);
    Text.setPosition(point.X,point.Y);
    Window.draw(Text);
}

void Renderer::SetCursorPos(Point point) {
    Cursor = point;
}

bool Renderer::isKeyDown(Key key) {
    return sf::Keyboard::isKeyPressed(key);
}

EngineWindow* Renderer::GetWindow() {
    return &Window;
}