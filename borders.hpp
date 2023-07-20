#include <iostream>
#include <SDL2/SDL.h>
#include <vector>

using namespace std;

class Borders{
    public:
        void initBorders(SDL_Window*, SDL_Renderer*);
        void createBorders();
        void printBorders();
    private:
        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;
        vector<SDL_Rect> border;
};