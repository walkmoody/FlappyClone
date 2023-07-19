#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include "rects.hpp"

void Rectangle::initRectangle(){
    user.w = 50;
    user.h = 50;
    user.y = 0;
    user.x = 40;
}

void Rectangle::setRectangleX(){
    user.x = user.x ;

}

void Rectangle::setRectangleY(int input){
    user.y = user.y + input;

}

int Rectangle:: getRectangle(){
    return user.x;
    
}

void Rectangle::printRect(SDL_Renderer* renderer){
    SDL_SetRenderDrawColor(renderer,255,0,0,255);
    SDL_RenderDrawRect(renderer, &user);

}

void Rectangle::rectInput(SDL_Event &windowEvent, bool &quit){
    while (SDL_PollEvent( &windowEvent) != 0){
            if( windowEvent.type == SDL_QUIT )
                quit = true;
            SDL_Keycode key = windowEvent.key.keysym.sym;                
            if (key == SDLK_SPACE)
                down = true;
            if (windowEvent.type == SDL_KEYUP)
                down = false;
            
        }
        if (down){
            setRectangleY(-7);
            count = 0;
        }
        else if (!down){
            if(user.y < 600){
            setRectangleY(1 + count);
            if (count < 5)
                count++; 
            }
        }

}
