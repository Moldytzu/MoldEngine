#pragma once

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include <windows.h> 

#define COLOR_BLACK_CONSOLE      0
#define COLOR_DARK_BLUE_CONSOLE  1
#define COLOR_DARK_GREEN_CONSOLE 2
#define COLOR_LIGHT_BLUE_CONSOLE 3
#define COLOR_DARK_RED_CONSOLE   4
#define COLOR_MAGENTA_CONSOLE    5
#define COLOR_ORANGE_CONSOLE     6
#define COLOR_LIGHT_GRAY_CONSOLE 7
#define COLOR_GRAY_CONSOLE       8
#define COLOR_BLUE_CONSOLE       9
#define COLOR_GREEN_CONSOLE     10
#define COLOR_CYAN_CONSOLE      11
#define COLOR_RED_CONSOLE       12
#define COLOR_PINK_CONSOLE      13
#define COLOR_YELLOW_CONSOLE    14
#define COLOR_WHITE_CONSOLE     15

inline static void InsertColor(int color) {
    static const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, color);
}

#else
#include <iostream>
#define COLOR_BLACK_CONSOLE      "30"
#define COLOR_DARK_BLUE_CONSOLE  "34"
#define COLOR_DARK_GREEN_CONSOLE "32"
#define COLOR_LIGHT_BLUE_CONSOLE "36"
#define COLOR_DARK_RED_CONSOLE   "31"
#define COLOR_MAGENTA_CONSOLE    "35"
#define COLOR_ORANGE_CONSOLE     "33"
#define COLOR_LIGHT_GRAY_CONSOLE "37"
#define COLOR_GRAY_CONSOLE       "90"
#define COLOR_BLUE_CONSOLE       "94"
#define COLOR_GREEN_CONSOLE      "92"
#define COLOR_CYAN_CONSOLE       "96"
#define COLOR_RED_CONSOLE        "91"
#define COLOR_PINK_CONSOLE       "95"
#define COLOR_YELLOW_CONSOLE     "93"
#define COLOR_WHITE_CONSOLE      "97"

inline static void InsertColor(const char* color) {
    std::cout << "\033[" << color << 'm';
} 

#endif

#define COLOR_BLACK      {0,0,0}
#define COLOR_DARK_BLUE  {0,0,150}
#define COLOR_DARK_GREEN {0,150,0}
#define COLOR_DARK_RED   {150,0,0}
#define COLOR_ORANGE     {255,145,0}
#define COLOR_LIGHT_GRAY {200,200,200}
#define COLOR_GRAY       {120,120,120}
#define COLOR_BLUE       {0,0,255}
#define COLOR_GREEN      {0,255,0}
#define COLOR_CYAN       {0,255,255}
#define COLOR_RED        {255,0,0}
#define COLOR_PINK       {255,0,255}
#define COLOR_YELLOW     {255,255,0}
#define COLOR_WHITE      {255,255,255}