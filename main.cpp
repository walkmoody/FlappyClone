#include <iostream>
#include <SDL2/SDL.h>
#include <vector>

const int WIDTH = 1080;
const int HEIGHT = 720;

int main( int argc, char *argv[]){

    SDL_Window* window = nullptr; //SDL_CreateWindow("new Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI) ; // change window name here, CHANGE STARTING POS HERE
    SDL_Renderer* renderer = nullptr;
    SDL_Surface* image = nullptr;

    SDL_Init( SDL_INIT_EVERYTHING);

    SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer);

    SDL_SetRenderDrawColor(renderer, 0,0,0,255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255,255,255,255);
    SDL_Rect rect;
    rect.w = 100;
    rect.h = 100;
    rect.y = 0;
    rect.x = 0;

    SDL_Rect rect2;
    rect2.w = 100;
    rect2.h = 100;
    rect2.y = 50;
    rect2.x = 50;

    SDL_Rect intersection;

    SDL_IntersectRect(&rect, &rect2, &intersection); //Basic Collision detection

    std::vector<SDL_Rect> rv; //SDL_Point does not work
    for(int i =0; i < 100; i++){
        //rv.emplace_back(rand()% WIDTH, rand() %HEIGHT);
        rv.push_back(SDL_Rect(rand()% WIDTH, rand() % HEIGHT, 10, 10));
    }
    SDL_RenderDrawRects(renderer, rv.data(), rv.size());


    SDL_RenderDrawRect(renderer, &rect);
    SDL_RenderDrawRect(renderer, &rect2);
    SDL_SetRenderDrawColor(renderer,255,0,0,255);
    SDL_RenderFillRect(renderer, &intersection);

    SDL_SetRenderDrawColor (renderer, 255,255,255,255);
    //SDL_RenderSetScale(renderer, 2, 2);
    SDL_RenderDrawPoint(renderer, WIDTH/2, HEIGHT/2);

    //Rectangle Width, Height, X Pos, Y Pos
    

    SDL_RenderPresent(renderer);
    //SDL_Delay(10000);
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