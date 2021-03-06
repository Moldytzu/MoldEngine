#include "Engine.h"
#include <iostream>
#include <ctime>

using namespace MoldEngine;

void Logging::Info(const char* message) {
    std::time_t time = std::time(0);
    std::tm* timeNow = std::localtime(&time);
    InsertColor(COLOR_GREEN_CONSOLE);
    std::cout << '[' << timeNow->tm_hour << ":" << timeNow->tm_min << ":" << timeNow->tm_sec << "] " << message << std::endl;
}

void Logging::Warn(const char* message) {
    std::time_t time = std::time(0);
    std::tm* timeNow = std::localtime(&time);
    InsertColor(COLOR_YELLOW_CONSOLE);
    std::cout << '[' << timeNow->tm_hour << ":" << timeNow->tm_min << ":" << timeNow->tm_sec << "] " << message << std::endl;
}

void Logging::Error(const char* message) {
    std::time_t time = std::time(0);
    std::tm* timeNow = std::localtime(&time);
    InsertColor(COLOR_RED_CONSOLE);
    std::cout << '[' << timeNow->tm_hour << ":" << timeNow->tm_min << ":" << timeNow->tm_sec << "] " << message << std::endl;
}