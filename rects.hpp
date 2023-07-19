#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
//#include "rects.cpp"

using namespace std;

class Rectangle{
    public:
        void rectInput(SDL_Event &windowEvent, bool &quit);
        void initRectangle();
        void setRectangleX();
        void setRectangleY(int);
        int getRectangle();
        void printRect(SDL_Renderer* renderer);
    private:
        SDL_Rect user;
        bool down = false;
};

/*
Rectangle::Rectangle(){
    rect.w = 40;
    rect.h = 40;
    rect.y = 0;
    rect.x = 0;
}

void Rectangle::setRectangleX(){
    rect.x = rect.x + 1;

}

void Rectangle::setRectangleY(){
    rect.y = rect.y + 1;

}

int Rectangle:: getRectangle(){
    return rect.x;
    
}

void Rectangle::printRect(SDL_Renderer* renderer){
    SDL_SetRenderDrawColor(renderer,255,0,0,255);
    SDL_RenderDrawRect(renderer, &rect);
}
*/