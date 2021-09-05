#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cstring>
#include "Colors.h"

typedef sf::RenderWindow EngineWindow;
typedef sf::Keyboard::Key Key;

namespace MoldEngine {

    inline bool WindowFocus = false; //Is the window in focus?

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
                Imediate = 0, //Move by position
                Smooth = 1, //Move by offset
            };

            Point Position; //Current position
            Sprite(const char* texturePath,Point offset,Point size); //Define texture, offset in texture, size to get from the texture
            void Draw(EngineWindow* window,GlideStyle style); //Draw the sprite on the window
    };

    class Renderer {
    private:
        sf::Font Font;
        sf::Text Text;
        Point Cursor;
        EngineWindow Window;
    public:
        Renderer(int Width, int Height);
        void Run(void(*OnRedraw)(Renderer*,float),void(*OnClose)()); //Run the game
        void DrawText(const char* text); //Draw text onto the screen at the cursor position
        void DrawText(const char* text,Point point); //Draw text at a position onto the screen
        void SetCursorPos(Point point); //Set the cursor position
        EngineWindow* GetWindow(); //Get the window
    };

    namespace Input {
        struct MouseState {
            Point position; //Cursor position
            bool LMB; //Left mouse button
            bool RMB; //Right mouse button
        };

        bool isKeyDown(Key key); //Check if key is down
        MouseState getMouseState(EngineWindow* window); //Get mouse state on the window
    };

    namespace Logging {
        void Info(const char* message); //Log information
        void Warn(const char* message); //Log warning
        void Error(const char* message); //Low error
    };

    namespace Tools {
        const char* toString(int num); //Convert an integer to a C-string
        const char* toString(float num); //Convert a floating point number to a C-string
    };
}