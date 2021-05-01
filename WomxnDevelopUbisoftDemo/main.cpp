#include <stdafx.h>

#include <Game/GameReborn.h>

#include <Game/Character/Companion.h>

#include <iostream>

int main()
{
    GameReborn game{};

    game.RunGameLoop();

    return EXIT_SUCCESS;
}