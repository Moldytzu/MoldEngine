#include "engine.h"

using namespace MoldEngine;

//Engine

Engine::Engine(int Width,int Height) {
    new (&Window) sf::RenderWindow(sf::VideoMode(Width, Height), "MoldEngine");
    
    if(!Font.loadFromFile("gameFiles/engine/font.ttf")) {
        std::cout << "Failed to load font!" << std::endl;
        exit(-1);
    }

    Text.setFont(Font);
    Text.setCharacterSize(24);
    Text.setFillColor(sf::Color::White);
}

void Engine::Run(void(*OnRedraw)(Engine*,float),void(*OnClose)()) {
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

void Engine::DrawText(const char* text) {
    Text.setString(text);
    Text.setPosition(Cursor.X,Cursor.Y);
    sf::Vector2f vector = Text.getPosition();
    Cursor.X = vector.x+Text.getGlobalBounds().width+3;
    Cursor.Y = vector.y;
    Window.draw(Text);
}

void Engine::DrawText(const char* text,Point point) {
    Text.setString(text);
    Text.setPosition(point.X,point.Y);
    Window.draw(Text);
}

void Engine::SetCursorPos(Point point) {
    Cursor = point;
}

bool Engine::isKeyDown(Key key) {
    return sf::Keyboard::isKeyPressed(key);
}

EngineWindow* Engine::GetWindow() {
    return &Window;
}

// Sprite

Sprite::Sprite(const char* texturePath,Point offset,Point size) {
    sf::IntRect rect;
    rect.left = offset.X;
    rect.top = offset.Y;
    rect.height = size.Y;
    rect.width = size.X;
    if(!Texture.loadFromFile(texturePath,rect)) {
        exit(-1);
    }
    Texture.setSmooth(true);
    
    InternalSprite.setTexture(Texture,true);
    InternalSprite.move(0,0);
}

void Sprite::Draw(EngineWindow* window,GlideStyle style) {
    if(style == GlideStyle::Imediate)
        InternalSprite.setPosition(Position.X,Position.Y);
    else
        InternalSprite.move(Position.X,Position.Y);
    window->draw(InternalSprite);
}