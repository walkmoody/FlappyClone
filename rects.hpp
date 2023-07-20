#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
//#include "rects.cpp"

using namespace std;

class Rectangle{
    public:
        void rectInput(SDL_Event &, bool &);
        void initRectangle();
        void setRectangleX();
        void setRectangleY(int);
        int getRectangle();
        void printRect(SDL_Renderer*);
    private:
        SDL_Rect user;
        bool down = false;
        int count = 0;
};