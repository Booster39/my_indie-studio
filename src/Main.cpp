/*
** EPITECH PROJECT, 2022
** Main.cpp
** File description:
** main indie
*/

#include "Engine.hpp"

int main(void)
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "Bomberman");
    Engine e;

    e.runGame();
    return 0;
}