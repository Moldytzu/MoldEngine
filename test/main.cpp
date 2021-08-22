#include "../src/engine.h"
#include <iostream>

void OnRedraw() {
	
}

void OnClose() {
	std::cout << "Goodbye!" << std::endl; 
}

int main() {
	MoldEngine engine(800,600);
	engine.Run(OnRedraw,OnClose);
	return 0;
}
