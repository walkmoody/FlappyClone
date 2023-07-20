#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include "borders.hpp"

using namespace std;

void Borders::createBorders(){
    test.w = 1080;
    test.h = 100;
    test.y = 0;
    test.x = 0;
    borderArr[0] = &test;
    test2.w = 1080;
    test2.h = 180;
    test2.y = 600;
    test2.x = 0;
    borderArr[1] = &test2;
}

void Borders::initBorders(SDL_Window* window, SDL_Renderer* renderer){
    this->window = window;
    this->renderer = renderer;
    createBorders();
}

int Borders::get_rect_count(){
    int i;
    for (i = 0; i < arrSize; i++){
        if (borderArr[i] == NULL)
            break;
    }
    return i;
}
void Borders::colors(int &color, bool &colorUp){
    if(color == 100)
        colorUp = true;
    if (color == 200)
        colorUp = false;
    if (colorUp)
        color++;
    if (!colorUp)
        color--;

}
void Borders::printBorders(){
    int totalBorder = get_rect_count();
    for (int i = 0; i < totalBorder; i++){
        SDL_SetRenderDrawColor(renderer,color1,color2,color3,255); // red border
        SDL_RenderFillRect(renderer, borderArr[i]);
        SDL_RenderDrawRect(renderer, borderArr[i]);
    }
    colors(color1, color1Up);
    colors(color2, color2Up);
    colors(color3, color3Up);
}