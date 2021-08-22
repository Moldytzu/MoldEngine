#include "../src/engine.h"
#define SpriteSpeed 5

MoldEngine::Sprite sprite("gameFiles/texture.png",{0,0},{32,32});

void OnRedraw(MoldEngine::Engine* engine,float deltaTime) {
	engine->DrawText("Hello!",{100,100});
	sprite.Draw(engine->GetWindow(),MoldEngine::Sprite::GlideStyle::Smooth);
	if(engine->isKeyDown(Key::A))
		sprite.Position.X -= SpriteSpeed*deltaTime;
	if(engine->isKeyDown(Key::D))
		sprite.Position.X += SpriteSpeed*deltaTime;
	if(engine->isKeyDown(Key::W))
		sprite.Position.Y -= SpriteSpeed*deltaTime;
	if(engine->isKeyDown(Key::S))
		sprite.Position.Y += SpriteSpeed*deltaTime;
}

void OnClose() {
	std::cout << "Goodbye!" << std::endl; 
}

int main() {
	MoldEngine::Engine engine(800,600);
	engine.Run(OnRedraw,OnClose);
	return 0;
}
