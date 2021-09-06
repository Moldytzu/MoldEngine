#include "Engine.h"

using namespace MoldEngine;

Sprite::Sprite(const char* texturePath,Point offset,Point size) {
    sf::IntRect rect;
    rect.left = offset.X;
    rect.top = offset.Y;
    rect.height = size.Y;
    rect.width = size.X;
    //loadFromMemory(Data::getFileFromData("engine/font.ttf"),Data::getFileSize("engine/font.ttf"))
    //if(!Texture.loadFromFile(texturePath,rect)) {
    if(!Texture.loadFromMemory(Data::getFileFromData(texturePath),Data::getFileSize(texturePath),rect)) {
        exit(-1);
    }
    Texture.setSmooth(true);
    
    InternalSprite.setTexture(Texture,true);
    InternalSprite.move(0,0);
}

void Sprite::Draw(GlideStyle style) {
    if(style == GlideStyle::Imediate)
        InternalSprite.setPosition(Position.X,Position.Y);
    else
        InternalSprite.move(Position.X,Position.Y);
    GlobalWindow.draw(InternalSprite);
}