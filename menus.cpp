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
    bool looping = true;
    bool quit = false;
    while (looping){
        while (SDL_PollEvent( &windowEvent) != 0){
            if(windowEvent.type == SDL_QUIT ){
                quit = true;
                looping = false;
            }
            SDL_Keycode key = windowEvent.key.keysym.sym;
            if (key == SDLK_SPACE){
                return "game";
                cout << "quit" << endl;
            }
        }
            SDL_RenderClear(renderer);
            SDL_SetRenderDrawColor (renderer, 123,120,200,255);
            SDL_RenderPresent(renderer);
            SDL_Delay(1000/FPS);      
    
        }
    if (quit == true)
        return "quit";
    return "game";
}

string Menus::game_screen(){
    Game mainGame;
    mainGame.gameInit(window, renderer, windowEvent);
    mainGame.gameLoop();
    return "quit";
}

string Menus::instructions(){
    return "quit";
}

string Menus::game_over(){
    return "quit";
}

string Menus::good_bye(){
    return "quit";
}