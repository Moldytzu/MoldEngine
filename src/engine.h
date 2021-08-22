#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cstring>

typedef sf::RenderWindow EngineWindow;
typedef sf::Keyboard::Key Key;

namespace MoldEngine {
    struct Point {
        float X;
        float Y;
    };

    class Sprite {
        private:
            sf::Texture Texture;
            sf::Sprite InternalSprite;
        public:
            Point Position;
            Sprite(const char* texturePath,Point offset,Point size);
            void Draw(EngineWindow* window);
    };

    class Engine {
    private:
        sf::Font Font;
        sf::Text Text;
        Point Cursor;
        EngineWindow Window;
    public:
        Engine(int Width, int Height);
        void Run(void(*OnRedraw)(Engine*,float),void(*OnClose)());
        void DrawText(const char* text);
        void DrawText(const char* text,Point point);
        void SetCursorPos(Point point);
        bool isKeyDown(Key key);
        EngineWindow* GetWindow();
    };
}