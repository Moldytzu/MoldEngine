#include "../src/Engine.h"
#define SpriteSpeed 5

MoldEngine::Sprite sprite("texture.png",{0,0},{32,32});

void OnRedraw(MoldEngine::Renderer* renderer,float deltaTime) {
	renderer->CurrentColor = COLOR_YELLOW;
	renderer->DrawText("Hello!");
	sprite.Draw(MoldEngine::Sprite::GlideStyle::Smooth);
	MoldEngine::Input::MouseState mouseState = MoldEngine::Input::getMouseState();
	if(MoldEngine::Input::isKeyDown(Key::A))
		sprite.Position.X -= SpriteSpeed*deltaTime;
	if(MoldEngine::Input::isKeyDown(Key::D))
		sprite.Position.X += SpriteSpeed*deltaTime;
	if(MoldEngine::Input::isKeyDown(Key::W))
		sprite.Position.Y -= SpriteSpeed*deltaTime;
	if(MoldEngine::Input::isKeyDown(Key::S))
		sprite.Position.Y += SpriteSpeed*deltaTime;
	if(mouseState.LMB) {
		renderer->CurrentColor = COLOR_RED;
		renderer->DrawText("LMB",mouseState.position);
	} else if(mouseState.RMB) {
		renderer->CurrentColor = COLOR_GREEN;
		renderer->DrawText("RMB",mouseState.position);
	}	
}

void OnClose() {
	MoldEngine::Logging::Info("Bye!");
}

int main() {
	MoldEngine::Renderer renderer(800,600,0);
	renderer.Run(OnRedraw,OnClose);
	return 0;
}
