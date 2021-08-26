#pragma once

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include <windows.h> 

#define COLOR_BLACK      0
#define COLOR_DARK_BLUE  1
#define COLOR_DARK_GREEN 2
#define COLOR_LIGHT_BLUE 3
#define COLOR_DARK_RED   4
#define COLOR_MAGENTA    5
#define COLOR_ORANGE     6
#define COLOR_LIGHT_gray 7
#define COLOR_GRAY       8
#define COLOR_BLUE       9
#define COLOR_GREEN     10
#define COLOR_CYAN      11
#define COLOR_RED       12
#define COLOR_PINK      13
#define COLOR_YELLOW    14
#define COLOR_WHITE     15

inline static void InsertColor(int color) {
    static const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, color);
}

#else
#include <iostream>
#define COLOR_BLACK      "30"
#define COLOR_DARK_BLUE  "34"
#define COLOR_DARK_GREEN "32"
#define COLOR_LIGHT_BLUE "36"
#define COLOR_DARK_RED   "31"
#define COLOR_MAGENTA    "35"
#define COLOR_ORANGE     "33"
#define COLOR_LIGHT_gray "37"
#define COLOR_GRAY       "90"
#define COLOR_BLUE       "94"
#define COLOR_GREEN      "92"
#define COLOR_CYAN       "96"
#define COLOR_RED        "91"
#define COLOR_PINK       "95"
#define COLOR_YELLOW     "93"
#define COLOR_WHITE      "97"

inline static void InsertColor(const char* color) {
    std::cout << "\033[" << color << 'm';
} 

#endif

