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
            cout << quit << endl;
            rect.printRect(renderer);
            
            SDL_SetRenderDrawColor (renderer, 255,255,255,255);
            SDL_RenderPresent( renderer );
            SDL_Delay(1000/FPS);      
    
            }
    if (quit){
        SDL_DestroyRenderer(renderer);    
        SDL_DestroyWindow (window);
        SDL_Quit();
        //return EXIT_SUCCESS;
    }
}