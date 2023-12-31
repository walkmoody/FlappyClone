#include <iostream>
#include <SDL2/SDL.h>
//#include <SDL2/SDL_ttf.h>
#include <vector>
#include "menus.hpp"
#include "game.hpp"

using namespace std;

void Menus::menusInit(SDL_Window* window, SDL_Renderer* renderer, SDL_Event &windowEvent, SDL_Surface* screenSurface, TTF_Font* Sans){
    this->window = window;
    this->renderer = renderer;
    this->windowEvent = windowEvent;
    this->screenSurface = screenSurface;
    this->Sans = Sans;
}
bool Menus::init(){
    bool success = true;
    return success;
}
bool Menus::loadMedia(){
    bool success = true;
    viewport = { 0, 0, 1080, 720 };
    SDL_Surface *image_surface = SDL_LoadBMP("sprites/test.bmp");
    texture = SDL_CreateTextureFromSurface(renderer, image_surface);
    SDL_FreeSurface(image_surface);
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, "put your text here", Black); // CHANGE MESSAGE
    Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
    SDL_FreeSurface(surfaceMessage);
    surfaceMessage = nullptr;
    Message_rect.x = 100;  //controls the rect's x coordinate 
    Message_rect.y = 100; // controls the rect's y coordinte
    Message_rect.w = 100; // controls the width of the rect
    Message_rect.h = 100;

    //Load splash image
    test = SDL_LoadBMP( "sprites/test.bmp" );
    if( test == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "sprites/test.bmp", SDL_GetError() );
        success = false;
    }

    return success;
}
void Menus::close(){
    //Deallocate surface
    SDL_FreeSurface(screenSurface);

    screenSurface = NULL;
    SDL_FreeSurface(test);

    test = NULL;
}

string Menus::splash(){
    //SDL_RenderSetViewport(renderer, &viewport);
    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, nullptr, nullptr);
    
    SDL_RenderPresent(renderer);
    SDL_Delay(1000/FPS);      

    //SDL_SetRenderDrawColor (renderer, 255,255,255,255);
    //SDL_RenderPresent(renderer);
    SDL_Delay(1000);
    return "menu";
    }

string Menus::mainMenu(){
    bool looping = true;
    bool quit = false;
    
    loadMedia();
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
            //SDL_BlitSurface( test, NULL, screenSurface, NULL );
            //SDL_SetRenderDrawColor (renderer, 123,120,200,255);
            //SDL_RenderPresent(renderer);
            //SDL_UpdateWindowSurface( window );
            

            SDL_RenderClear(renderer);
            
            SDL_SetRenderDrawColor(renderer, 2, 0, 3, 255);
           
            SDL_RenderCopy(renderer, texture, nullptr, nullptr);
            SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
            //SDL_RenderSetViewport(renderer, &viewport);
            SDL_RenderCopy(renderer, Message, NULL, &Message_rect);
            SDL_RenderFillRect(renderer, &Message_rect);
            SDL_SetRenderDrawColor(renderer, 255, 0, 3, 255);
            SDL_RenderPresent(renderer);
            SDL_Delay(1000/FPS);      
    
        }
    close();
    SDL_DestroyTexture(Message);
    if (quit == true)
        return "quit";
    return "game";
}

string Menus::game_screen(){
    Game mainGame;
    mainGame.gameInit(window, renderer, windowEvent);
    return mainGame.gameLoop();
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