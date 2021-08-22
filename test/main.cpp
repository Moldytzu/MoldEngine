#include "../src/engine.h"

MoldEngine::Sprite sprite("gameFiles/texture.png",{0,0},{32,32});

void OnRedraw(MoldEngine::Engine* engine,float deltaTime) {
	engine->DrawText("Hello!",{100,100});
	sprite.Draw(engine->GetWindow());
}

void OnClose() {
	std::cout << "Goodbye!" << std::endl; 
}

int main() {
	MoldEngine::Engine engine(800,600);
	engine.Run(OnRedraw,OnClose);
	return 0;
}
