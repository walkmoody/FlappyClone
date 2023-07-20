#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include "rects.hpp"

void Rectangle::initRectangle(SDL_Window* window, SDL_Renderer* renderer){
    user.w = 50;
    user.h = 50;
    user.y = 200;
    user.x = 90;
    this->window = window;
    this->renderer = renderer;
    screenSurface = SDL_GetWindowSurface(window);
}

void Rectangle::setRectangleX(){
    user.x = user.x;
}

void Rectangle::setRectangleY(int input){
    user.y = user.y + input;
}

int Rectangle:: getRectangle(){
    return user.y;
    
}

bool Rectangle::loadMedia(){
    bool success = true;

    //Load splash image
    charSprite = SDL_LoadBMP( "sprites/test.bmp" );
    if( charSprite == NULL ){
        printf( "Unable to load image %s! SDL Error: %s\n", "sprites/test.bmp", SDL_GetError() );
        success = false;
    }

    return success;
}

void Rectangle::close(){
    //Deallocate surface
    SDL_FreeSurface(charSprite);
    charSprite = NULL;
}

void Rectangle::printRect(){
    SDL_SetRenderDrawColor(renderer,255,0,0,255); // red border
    //SDL_BlitSurface(screenSurface, &user, charSprite, &user);
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
            if (user.y < 100)
                user.y = 101;
            if (upAccel < 15)
                upAccel++; 
            downAccel = 0;
            }
        else if (!down){
            setRectangleY(4 + downAccel);
            if(user.y > 550)
                user.y = 549;
            if (downAccel < 15){
                downAccel++;
                cout << downAccel << endl;
            }
            upAccel = 0;
            }
            

}
