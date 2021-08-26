#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cstring>
#include "Colors.h"

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
            enum GlideStyle {
                Imediate = 0,
                Smooth = 1,
            };

            Point Position;
            Sprite(const char* texturePath,Point offset,Point size);
            void Draw(EngineWindow* window,GlideStyle style);
    };

    class Renderer {
    private:
        sf::Font Font;
        sf::Text Text;
        Point Cursor;
        EngineWindow Window;
    public:
        Renderer(int Width, int Height);
        void Run(void(*OnRedraw)(Renderer*,float),void(*OnClose)());
        void DrawText(const char* text);
        void DrawText(const char* text,Point point);
        void SetCursorPos(Point point);
        bool isKeyDown(Key key);
        EngineWindow* GetWindow();
    };

    namespace Logging {
        void Info(const char* message);
        void Warn(const char* message);
        void Error(const char* message);
    };
}