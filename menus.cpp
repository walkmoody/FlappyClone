#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include "menus.hpp"
using namespace std;

void Menus::menusInit(SDL_Window* window, SDL_Renderer* renderer){
    this->window = window;
    this->renderer = renderer;

}

string Menus::splash(){
    SDL_SetRenderDrawColor (renderer, 255,255,255,255);
    SDL_RenderPresent(renderer);
    SDL_Delay(1000);
    return "menu";
    }

string Menus::mainMenu(){
    SDL_SetRenderDrawColor (renderer, 100,100,100,255);
    SDL_RenderPresent(renderer);
    SDL_Delay(1000);
    return "menu";

}