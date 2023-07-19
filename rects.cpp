#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include "rects.hpp"

void Rectangle::initRectangle(){
    rect.w = 100;
    rect.h = 100;
    rect.y = 0;
    rect.x = 0;
}

void Rectangle::setRectangleX(){
    rect.x = rect.x ;

}

void Rectangle::setRectangleY(int input){
    rect.y = rect.y + input;

}

int Rectangle:: getRectangle(){
    return rect.x;
    
}

void Rectangle::printRect(SDL_Renderer* renderer){
    SDL_SetRenderDrawColor(renderer,255,0,0,255);
    SDL_RenderDrawRect(renderer, &rect);

}

