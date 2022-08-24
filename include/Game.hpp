#pragma once

#include <SDL2/SDL.h>

class Game
{
public:
    void Init(const char* title, int width, int height);
    void Update();
    void Render();
    void Events();
    void Close();
    
    bool gameRunning;

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};