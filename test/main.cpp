#include "../src/Engine.h"
#define SpriteSpeed 5

MoldEngine::Sprite sprite("gameFiles/texture.png",{0,0},{32,32});

void OnRedraw(MoldEngine::Renderer* engine,float deltaTime) {
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
	MoldEngine::Renderer renderer(800,600);
	renderer.Run(OnRedraw,OnClose);
	return 0;
}
