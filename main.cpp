#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
//#include "rects.h"

const int WIDTH = 720;
const int HEIGHT = 560;
const int FPS = 60;

//g++ -I src/include -L src/lib -o main main.cpp -lmingw32 -lSDL2main -lSDL2

int main( int argc, char *argv[]){

    SDL_Window* window = nullptr; //SDL_CreateWindow("new Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI) ; // change window name here, CHANGE STARTING POS HERE
    SDL_Renderer* renderer = nullptr;
    SDL_Surface* image = nullptr;

    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer);

    SDL_SetRenderDrawColor(renderer, 0,0,0,255); //backgroujd color
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 100,100,100,255);
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

    SDL_Rect rect3;
    rect3.w = 100;
    rect3.h = 100;
    rect3.y = 600;
    rect3.x = 400;


    SDL_Rect intersection;

    SDL_IntersectRect(&rect, &rect2, &intersection); //Basic Collision detection
    /*
    std::vector<SDL_Rect> rv; //SDL_Point does not work
    for(int i =0; i < 100; i++){
        //rv.emplace_back(rand()% WIDTH, rand() %HEIGHT);
        rv.emplace_back(rand()% WIDTH, rand() % HEIGHT, 10, 10);
    }
    SDL_RenderDrawRects(renderer, rv.data(), rv.size());
    */

    SDL_RenderDrawRect(renderer, &rect);
    SDL_RenderDrawRect(renderer, &rect2);
    SDL_RenderDrawRect(renderer, &rect3);
    SDL_SetRenderDrawColor(renderer,255,0,0,255);
    SDL_RenderFillRect(renderer, &intersection);

    SDL_SetRenderDrawColor (renderer, 255,255,255,255);
    SDL_RenderDrawPoint(renderer, WIDTH/2, HEIGHT/2);

    //Rectangle Width, Height, X Pos, Y Pos
    

    SDL_RenderPresent(renderer);
    
    SDL_Delay(50);
    if (NULL == window) {
        std::cout << "Could not create Window: " << SDL_GetError() << std::endl;
        return 1;
    }
    int count = 0;
    SDL_Event windowEvent;
    bool quit = false;
    while (!quit){
        while (SDL_PollEvent( &windowEvent) != 0){
            if( windowEvent.type == SDL_QUIT )
                {
                    quit = true;
                }
            }
        SDL_Event event;
        SDL_RenderClear( renderer );
        rect.y = count++;
        rect.x = count++;
        rect.w -= 1;
        rect.h = 100;
        //SDL_RenderCopy( renderer, NULL, NULL, NULL );
        SDL_SetRenderDrawColor(renderer,255,0,0,255);
        SDL_RenderDrawRect(renderer, &rect);
        
        SDL_SetRenderDrawColor (renderer, 255,255,255,255);
        SDL_RenderPresent( renderer );
        //SDL_RenderDrawPoint(renderer, WIDTH/2, HEIGHT/2);     
        SDL_Delay(1000/FPS);       
        }

    SDL_DestroyWindow (window);
    SDL_Quit();
    return EXIT_SUCCESS;
}