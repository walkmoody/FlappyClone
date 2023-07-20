#include <iostream>
#include <SDL2/SDL.h>
#include <vector>

using namespace std;

class Borders{
    public:
        void initBorders(SDL_Window*, SDL_Renderer*);
        void createBorders();
        void printBorders();
        int get_rect_count();
    private:
        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;
        int arrSize = 100;
        SDL_Rect *borderArr[100] = {};
        SDL_Rect test;
};
