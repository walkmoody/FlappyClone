#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include "borders.hpp"

void Borders::createBorders(){
    border[0].h = 20;
    border[0].w = 700;
    border[0].y = 20;
    border[0].x = 0;
}

void Borders::initBorders(SDL_Window* window, SDL_Renderer* renderer){
    this->window = window;
    this->renderer = renderer;
    createBorders();
}

void Borders::printBorders(){
    for(int i = 0; i < border.size(); i++){
        SDL_SetRenderDrawColor(renderer,255,0,0,255); // red border
        SDL_RenderDrawRect(renderer, &border[i]);
    }
}