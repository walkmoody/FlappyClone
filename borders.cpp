#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include "borders.hpp"

using namespace std;

void Borders::createBorders(){
    test.w = 50;
    test.h = 50;
    test.y = 20;
    test.x = 50;
    borderArr[0] = &test;
    test.w = 100;
    test.h = 200;
    test.y = 300;
    test.x = 400;
    borderArr[1] = &test;
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

void Borders::printBorders(){
    int totalBorder = get_rect_count();
    for (int i = 0; i < totalBorder; i++){
        SDL_SetRenderDrawColor(renderer,255,0,0,255); // red border
        SDL_RenderFillRect(renderer, borderArr[i]);
        SDL_RenderDrawRect(renderer, borderArr[i]);
    }
    
}