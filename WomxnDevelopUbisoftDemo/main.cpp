#include <stdafx.h>

#include <Game/GameDemo.h>

#include <Game/Character/Companion.h>

#include <iostream>

int main()
{
    GameDemo game{};

    sf::Music music;
    if (music.openFromFile("Assets/sound/pallet_town.wav"))
    {
        music.setVolume(5.f);
        //music.setLoop(true);
        music.play();
    }
    game.RunGameLoop();

    return EXIT_SUCCESS;
}