#include "Game.hpp"
#include "Logger.hpp"

void Game::Init(const char* title, int width, int height)
{
    int initialized = SDL_Init(SDL_INIT_VIDEO);
    if (initialized != 0)
    {
        Logger::Error("SDL Initialization Failed");
    }

    int flags = SDL_WINDOW_SHOWN;
    this->window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
    if (!this->window)
    {
        Logger::Error("Window Creation Failed");
    }

    int rendererFlags = SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED;
    this->renderer = SDL_CreateRenderer(this->window, -1, rendererFlags);

    if (!this->renderer)
    {
        Logger::Error("Renderer Creation Failed");
    }

    this->gameRunning = true;
    Logger::Debug("SDL Started Successfully");
}

void Game::Render()
{
    SDL_RenderClear(this->renderer);
    SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);
    SDL_RenderPresent(this->renderer);
}

void Game::Update()
{

}

void Game::Events()
{
    SDL_Event event;
    
    while (SDL_PollEvent(&event) != 0)
    {
        switch (event.type)
        {
            case SDL_QUIT:
                this->gameRunning = false;
            case SDL_KEYDOWN:
            {
                if (event.type == SDLK_ESCAPE)
                {
                    this->gameRunning = false;
                }
            }
        }
    }
}

void Game::Close()
{
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);

    this->window = nullptr;
    this->renderer = nullptr;

    Logger::Debug("SDL Ended Successfully");
}