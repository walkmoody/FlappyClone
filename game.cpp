#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include "game.hpp"
#include "rects.hpp"

void Game::gameInit(SDL_Window* window, SDL_Renderer* renderer, SDL_Event &windowEvent){
    this->window = window;
    this->renderer = renderer;
    this->windowEvent = windowEvent;

}


void Game::gameLoop(){
    bool quit = false;
    Rectangle rect;
    rect.initRectangle();

    while (!quit){
            rect.rectInput(windowEvent, quit);
            SDL_RenderClear(renderer);
            rect.setRectangleX();

            rect.printRect(renderer);
            
            SDL_SetRenderDrawColor (renderer, 123,100,100,255);
            SDL_RenderPresent( renderer );
            SDL_Delay(1000/FPS);      
    
            }
}