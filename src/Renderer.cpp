#include "Engine.h"

using namespace MoldEngine;

//Renderer

Renderer::Renderer(int Width,int Height,int antialiasingLevel) {
    Logging::Info("Starting MoldEngine");
    if(!Font.loadFromMemory(Data::getFileFromData("engine/font.ttf"),Data::getFileSize("engine/font.ttf"))) {
        Logging::Error("Failed to load font!");
        exit(-1);
    }

    Text.setFont(Font);
    Text.setCharacterSize(24);
    Text.setFillColor(sf::Color::White);

    if(antialiasingLevel < 0 || antialiasingLevel > 4) {
        Logging::Error("Antialiasing level is too high or too low!");
        exit(-1);
    }

    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antialiasingLevel = antialiasingLevel;
    settings.majorVersion = 2;
    settings.minorVersion = 1;

    new (&GlobalWindow) sf::RenderWindow(sf::VideoMode(Width, Height), "MoldEngine", sf::Style::Default, settings);

    GlobalWindow.setFramerateLimit(120);
    GlobalWindow.setMouseCursorVisible(false);
    GlobalWindow.setKeyRepeatEnabled(true);

    GlobalViewport = GlobalWindow.getDefaultView();

    WindowFocus = true;
    CurrentColor = COLOR_WHITE;
    Logging::Info("MoldEngine by Moldytzu");
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
    Text.setFillColor({CurrentColor.R,CurrentColor.G,CurrentColor.B,255});
    Text.setPosition(Cursor.X,Cursor.Y);
    sf::Vector2f vector = Text.getPosition();
    Cursor.X = vector.x+Text.getGlobalBounds().width+3;
    Cursor.Y = vector.y;
    GlobalWindow.draw(Text);
}

void Renderer::DrawText(const char* text,Point point) {
    Text.setString(text);
    Text.setFillColor({CurrentColor.R,CurrentColor.G,CurrentColor.B,255});
    Text.setPosition(point.X,point.Y);
    GlobalWindow.draw(Text);
}