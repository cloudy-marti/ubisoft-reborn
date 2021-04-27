#include <stdafx.h>

#include <Game/GameReborn.h>

#include <Game/Character/Companion.h>

#include <iostream>

int main()
{
    GameReborn game{};

    sf::Music music;
    if (music.openFromFile("Assets/sound/pallet_town.wav"))
    {
        music.setVolume(5.f);
        music.play();
    }
    game.RunGameLoop();

    return EXIT_SUCCESS;
}