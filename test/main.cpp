#include "../src/Engine.h"
#define SpriteSpeed 5

MoldEngine::Sprite sprite("gameFiles/texture.png",{0,0},{32,32});

void OnRedraw(MoldEngine::Renderer* engine,float deltaTime) {
	engine->DrawText("Hello!");
	sprite.Draw(engine->GetWindow(),MoldEngine::Sprite::GlideStyle::Smooth);
	MoldEngine::Input::MouseState mouseState = MoldEngine::Input::getMouseState(engine->GetWindow());
	if(MoldEngine::Input::isKeyDown(Key::A))
		sprite.Position.X -= SpriteSpeed*deltaTime;
	if(MoldEngine::Input::isKeyDown(Key::D))
		sprite.Position.X += SpriteSpeed*deltaTime;
	if(MoldEngine::Input::isKeyDown(Key::W))
		sprite.Position.Y -= SpriteSpeed*deltaTime;
	if(MoldEngine::Input::isKeyDown(Key::S))
		sprite.Position.Y += SpriteSpeed*deltaTime;
	if(mouseState.LMB)
		engine->DrawText("LMB",mouseState.position);
	else if(mouseState.RMB)
		engine->DrawText("RMB",mouseState.position);
}

void OnClose() {
	MoldEngine::Logging::Info("Bye!");
}

int main() {
	MoldEngine::Renderer renderer(800,600);
	renderer.Run(OnRedraw,OnClose);
	return 0;
}
