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
    charSprite = load_surface();
}

void Rectangle::setRectangleX(){
    user.x = user.x;
}

void Rectangle::setRectangleY(int input){
    user.y = user.y + input;
}

void Rectangle::right(){
    user.x = user.x + userFSpeed;
        if (user.x > 1080) // width of screen
        user.x = user.x - userFSpeed;
}
void Rectangle::left(){
    user.x = user.x - userBSpeed;
    if (user.x < 0) // width of screen
        user.x = user.x + userBSpeed;
}

int Rectangle:: getRectangle(){
    return user.y;
    
}

SDL_Surface *Rectangle::load_surface(){
    //Load splash image
    SDL_Surface *image_surface = SDL_LoadBMP( "sprites/test.bmp" );
    if(!image_surface){
        printf( "Unable to load image %s! SDL Error: %s\n", "sprites/test.bmp", SDL_GetError() );
        return 0;
    }

    return image_surface;
}


void Rectangle::close(){
    //Deallocate surface
    SDL_FreeSurface(charSprite);
    charSprite = NULL;
}

void Rectangle::printRect(){
    SDL_SetRenderDrawColor(renderer,255,0,0,255); // red border
    //SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0, 0, 0));
    //SDL_BlitSurface(charSprite, NULL, screenSurface, &user);

    //SDL_BlitSurface(screenSurface, &user, charSprite, &user);
    SDL_RenderFillRect(renderer, &user);
    SDL_RenderDrawRect(renderer, &user);

}

void Rectangle::rectInput(SDL_Event &windowEvent, bool &quit){
    while (SDL_PollEvent( &windowEvent) != 0){
        switch(windowEvent.type){
            case SDL_KEYDOWN:
                switch(windowEvent.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        quit = true;
                        break;
                    case SDLK_SPACE:
                        down = true;
                        break;
                    case SDLK_d:
                        rightPress = true;
                        break;
                    case SDLK_a:
                        leftPress = true;
                        break;
                    case SDLK_RIGHT:
                        rightPress = true;
                        break;
                    case SDLK_LEFT:
                        leftPress = true;
                        break;
                    default:
                        break;
            }
            break;
        case SDL_KEYUP:
            switch(windowEvent.key.keysym.sym){
                case SDLK_SPACE:
                    down = false;
                    break;
                case SDLK_d:
                    rightPress = false;
                    break;
                case SDLK_a:
                    leftPress = false;
                    break;
                case SDLK_RIGHT:
                    rightPress = false;
                    break;
                case SDLK_LEFT:
                    leftPress = false;
                    break;
                default:
                    break;
                    
            }
            break;
        case SDL_QUIT:
            quit = true;
            break;
        default:
            break;
        }
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
            if (downAccel < 15)
                downAccel++;
            upAccel = 0;
            }
        if(rightPress){
            right();
        }
        if(leftPress){
            left();
        }
        
}
