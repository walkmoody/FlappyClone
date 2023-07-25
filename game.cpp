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
    count = 0;

}

std::string Game::gameLoop(){
    bool quit = false;
    bool gameOver = false;
    string borderOut = "";

    Borders border;
    border.initBorders(window, renderer, windowEvent);


    while (!quit){
            SDL_RenderClear(renderer);
            if (borderOut == "")
                borderOut = border.printBorders();
            if(borderOut == "quit")
                return "quit";
            if(borderOut == "gameOver")
                gameOver = true;

            SDL_SetRenderDrawColor(renderer, 10, 10, 10,255); // window background
            if (gameOver == false || count == 0 )
                SDL_RenderPresent(renderer);
            if (gameOver == true)
                count++;
            if (count == 100){
                quit = true;
                border.closeRect();
            }
            
            SDL_Delay(1000/FPS);      
            }
    return "menu";
}
