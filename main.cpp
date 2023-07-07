#include <iostream>
#include <SDL2/SDL.h>

const int WIDTH = 1080;
const int HEIGHT = 720;

int main( int argc, char *argv[]){

    SDL_Init( SDL_INIT_EVERYTHING);

    SDL_Window *window = SDL_CreateWindow("new Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI) ; // change window name here, CHANGE STARTING POS HERE
    SDL_Surface *image = NULL;

    if (NULL == window) {
        std::cout << "Could not create Window: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Event windowEvent;
    while (true){
        if (SDL_PollEvent( &windowEvent)){
            if (SDL_QUIT == windowEvent.type){
                break;
            }
        }
    }

    SDL_DestroyWindow (window);
    SDL_Quit();
    return EXIT_SUCCESS;
}