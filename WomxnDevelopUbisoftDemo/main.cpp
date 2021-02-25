#include <stdafx.h>

#include <Game/GameDemo.h>

#include <iostream>

int main()
{
    GameDemo game{};
    game.addWall(100, 600, 100, 200);

    std::cout << "wall added" << std::endl;

    sf::Music music;
    if (music.openFromFile("Assets/pallet_town.wav"))
    {
        music.setVolume(5.f);
        //music.setLoop(true);
        music.play();
    }
    game.RunGameLoop();

    return EXIT_SUCCESS;
}