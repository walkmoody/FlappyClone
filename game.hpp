#include <iostream>
#include <SDL2/SDL.h>
#include <vector>

using namespace std;

class Game{
    public:
        void gameLoop();
        void gameInit(SDL_Window* , SDL_Renderer* , SDL_Event &);
    private:
        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;
        SDL_Event windowEvent;
        int count;
        const int FPS = 60;
};

