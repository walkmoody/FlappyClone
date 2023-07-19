#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include "rects.hpp"
#include "menus.hpp"
#include "game.hpp"

const int WIDTH = 1080;
const int HEIGHT = 720;
const int FPS = 60; 


//g++ -I src/include -L src/lib -o main main.cpp -lmingw32 -lSDL2main -lSDL2

int main( int argc, char *argv[]){
    SDL_Window* window = nullptr; //SDL_CreateWindow("new Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI) ; // change window name here, CHANGE STARTING POS HERE
    SDL_Renderer* renderer = nullptr;
    SDL_Surface* image = nullptr;
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer);
    SDL_SetWindowTitle(window, "FUN GAME"); // Change title here

    SDL_RenderPresent( renderer );
    if (NULL == window) {
        std::cout << "Could not create Window: " << SDL_GetError() << std::endl;
        return 1;
    }

    Menus mainMenu;
    mainMenu.menusInit(window, renderer);
    string screen = mainMenu.splash();
    Game mainGame;
    mainGame.gameInit(window, renderer);
    mainGame.gameLoop();
    

    SDL_DestroyRenderer(renderer);    
    SDL_DestroyWindow (window);
    SDL_Quit();
    return EXIT_SUCCESS;
}