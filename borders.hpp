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
        void colors(int &, bool &);
    private:
        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;
        int arrSize = 100;
        SDL_Rect *borderArr[100] = {};
        SDL_Rect test;
        SDL_Rect test2;
        int color1 = 100;
        int color2 = 200;
        int color3 = 100;
        bool color1Up = true;
        bool color2Up = false;
        bool color3Up = true;

};
