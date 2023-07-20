#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include "menus.hpp"
#include "game.hpp"

using namespace std;

void Menus::menusInit(SDL_Window* window, SDL_Renderer* renderer, SDL_Event &windowEvent){
    this->window = window;
    this->renderer = renderer;
    this->windowEvent = windowEvent;

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

string Menus::game_screen(){
    Game mainGame;
    mainGame.gameInit(window, renderer, windowEvent);
    mainGame.gameLoop();
    return "quit";
}

string Menus::instructions(){

}

string Menus::game_over(){

}

string Menus::good_bye(){

}