#include <iostream>
#include "Game.hpp"

#define TITLE "Base Project"
#define WIDTH 1240
#define HEIGHT 840

Game *game = nullptr;
int main(int argc, char* argv[])
{
    game->Init(TITLE, WIDTH, HEIGHT);

/*
    while (game->gameRunning)
    {
        game->Events();
        game->Render();
        game->Update();
    }

    game->Close();
*/
}