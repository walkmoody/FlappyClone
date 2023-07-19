#include <iostream>
#include <SDL2/SDL.h>
#include <vector>

using namespace std;

class Game{
    public:
        void gameLoop();
        void gameInit(SDL_Window* window, SDL_Renderer* renderer);
    private:
        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;
        const int FPS = 60;

};

