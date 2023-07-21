#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include "game.hpp"
//#include "rects.hpp"
#include "borders.hpp"

void Game::gameInit(SDL_Window* window, SDL_Renderer* renderer, SDL_Event &windowEvent){
    this->window = window;
    this->renderer = renderer;
    this->windowEvent = windowEvent;

}

void Game::gameLoop(){
    bool quit = false;
    Rectangle rect;
    rect.initRectangle(window,renderer);
    rect.load_surface();
    Borders border;
    border.initBorders(window, renderer, rect);


    while (!quit){
            SDL_RenderClear(renderer);
            rect.rectInput(windowEvent, quit);
            rect.setRectangleX();
            
            quit = border.printBorders();
            rect.printRect();
            

            SDL_SetRenderDrawColor(renderer, 10, 10, 10,255);

            SDL_RenderPresent(renderer);
            SDL_Delay(1000/FPS);      
            }
    rect.close();
}