#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
//#include "rects.cpp"

using namespace std;

class Rectangle{
    public:
        void rectInput(SDL_Event &, bool &);
        void initRectangle(SDL_Window* , SDL_Renderer* );
        void setRectangleX();
        void setRectangleY(int);
        int getRectangle();
        void printRect();
        bool loadMedia();
        void close();
    private:
        SDL_Rect user;
        bool down = false;
        int downAccel = 0;
        int upAccel = 0;
        SDL_Surface* screenSurface = nullptr;
        SDL_Surface* charSprite = nullptr;
        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;
};