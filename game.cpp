#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include "game.hpp"

void Game::gameInit(SDL_Window* window, SDL_Renderer* renderer){
    this->window = window;
    this->renderer = renderer;

}


void Game::gameLoop(){
    SDL_Event windowEvent;
    bool quit = false;
    Rectangle rect;
    rect.initRectangle();

    while (!quit){
            rect.rectInput(windowEvent, quit);
            SDL_RenderClear(renderer);
            rect.setRectangleX();
        
            rect.printRect(renderer);
            
            SDL_SetRenderDrawColor (renderer, 255,255,255,255);
            SDL_RenderPresent( renderer );
            SDL_Delay(1000/FPS);      
    
            }
}