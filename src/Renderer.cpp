#include "Engine.h"

using namespace MoldEngine;

//Renderer

Renderer::Renderer(int Width,int Height) {
    new (&GlobalWindow) sf::RenderWindow(sf::VideoMode(Width, Height), "MoldEngine");
    
    if(!Font.loadFromFile("gameFiles/engine/font.ttf")) {
        Logging::Error("Failed to load font!");
        exit(-1);
    }

    Text.setFont(Font);
    Text.setCharacterSize(24);
    Text.setFillColor(sf::Color::White);
    GlobalWindow.setFramerateLimit(1024);
    GlobalWindow.setMouseCursorVisible(false);
    GlobalWindow.setKeyRepeatEnabled(true);
    WindowFocus = true;
}

void Renderer::Run(void(*OnRedraw)(Renderer*,float),void(*OnClose)()) {
    sf::Clock deltaClock;
    float dt = 0;
    while(GlobalWindow.isOpen()) {
        sf::Event event;
        while (GlobalWindow.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                GlobalWindow.close();
                OnClose();
                break;
            case sf::Event::GainedFocus:
                WindowFocus = true;
                break;
            case sf::Event::LostFocus:
                WindowFocus = false;
                break;
            default:
                break;
            }
        }

        Cursor.Y = 0;
        Cursor.X = 0;
        GlobalWindow.clear();
        OnRedraw(this,dt);
        GlobalWindow.display();
        sf::String title = "MoldEngine : ";
        sf::String title2 = Tools::toString((int)(1000/(dt*1000)));
        sf::String title3 = " FPS";
        GlobalWindow.setTitle(title+title2+title3);
        dt = deltaClock.restart().asSeconds();
    }
}

void Renderer::DrawText(const char* text) {
    Text.setString(text);
    Text.setPosition(Cursor.X,Cursor.Y);
    sf::Vector2f vector = Text.getPosition();
    Cursor.X = vector.x+Text.getGlobalBounds().width+3;
    Cursor.Y = vector.y;
    GlobalWindow.draw(Text);
}

void Renderer::DrawText(const char* text,Point point) {
    Text.setString(text);
    Text.setPosition(point.X,point.Y);
    GlobalWindow.draw(Text);
}

void Renderer::SetCursorPos(Point point) {
    Cursor = point;
}