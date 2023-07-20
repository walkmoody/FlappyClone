#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include "rects.hpp"

void Rectangle::initRectangle(){
    user.w = 50;
    user.h = 50;
    user.y = 200;
    user.x = 90;
}

void Rectangle::setRectangleX(){
    user.x = user.x;

}

void Rectangle::setRectangleY(int input){
    if (user.y > 50)
        user.y = user.y + input;
    else 
        user.y = 51;
    
}

int Rectangle:: getRectangle(){
    return user.y;
    
}

void Rectangle::printRect(SDL_Renderer* renderer){
    SDL_SetRenderDrawColor(renderer,255,0,0,255); // red border
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
            setRectangleY(-2 -upAccel);
             if (upAccel < 12)
                upAccel++; 
            downAccel = 0;
            }

        else if (!down){
            if(user.y < 600)
                setRectangleY(2 + downAccel);
                if (downAccel < 12)
                    downAccel++;
            upAccel = 0;
            }
            

}
