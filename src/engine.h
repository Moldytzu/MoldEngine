#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cstring>

typedef sf::RenderWindow EngineWindow;

namespace MoldEngine {
    struct Point {
        int X;
        int Y;
    };

    class Sprite {
        private:
            sf::Texture Texture;
            sf::Sprite InternalSprite;
            Point Position;
        public:
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
        EngineWindow* GetWindow();
    };
}