#include "Engine.h"

using namespace MoldEngine;

void Camera::setZoom(float level) {
    GlobalViewport.zoom(level);
    GlobalWindow.setView(GlobalViewport);
}

void Camera::setOffset(Point offset) {
    GlobalViewport.setCenter((float)GlobalWindow.getSize().x/2+offset.X,(float)GlobalWindow.getSize().y/2+offset.Y);
    GlobalWindow.setView(GlobalViewport);
}

void Camera::setRotation(float rotation) {
    GlobalViewport.setRotation(rotation);
    GlobalWindow.setView(GlobalViewport);
}