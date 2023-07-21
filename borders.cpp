#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include <cstdlib>
#include "borders.hpp"

using namespace std;

void Borders::createBorders(){
    top.w = 1080;
    top.h = 100;
    top.y = 0;
    top.x = 0;
    borderArr[0] = &top;
    bottom.w = 1080;
    bottom.h = 180;
    bottom.y = 600;
    bottom.x = 0;
    borderArr[1] = &bottom;
    obst1top.w = 100;
    obst1top.y = 0;
    obst1bottom.w = 100;
    obst1bottom.h = 1000;
    obst2top.w = 100;
    obst2top.y = 0;
    obst2bottom.w = 100;
    obst2bottom.h = 1000;
    obst3top.w = 100;
    obst3top.y = 0;
    obst3bottom.w = 100;
    obst3bottom.h = 1000;
}

void Borders::initBorders(SDL_Window* window, SDL_Renderer* renderer){
    this->window = window;
    this->renderer = renderer;
    randNum = random();
    randNum2 = random();
    randNum3 = random();
    createBorders();
}

int Borders::get_rect_count(){
    int i;
    for (i = 0; i < arrSize; i++){
        if (borderArr[i] == NULL)
            break;
    }
    return i;
}

void Borders::colors(int &color, bool &colorUp){
    if(color == 100)
        colorUp = true;
    if (color == 200)
        colorUp = false;
    if (colorUp)
        color++;
    if (!colorUp)
        color--;

}
int Borders::random(){
    int low = 0, high = 170, newNum;
    newNum = (rand() % (low - high)) + low;
    return newNum;
}

void Borders::createObstacles(){
    if (obstTime1 < 1180){ // fix
        obst1top.h = 200 + randNum; // calculates where the obst will be placed
        obst1top.x = 1080 - obstTime1;
        borderArr[2] = &obst1top;

        obst1bottom.y = 375 + randNum;
        obst1bottom.x = 1080 - obstTime1;
        borderArr[3] = &obst1bottom;
    }   
    if (obstTime1 < 1680){ // fix
        obst2top.h = 200 + randNum2; // calculates where the obst will be placed
        obst2top.x = 1580 - obstTime1;
        borderArr[4] = &obst2top;
    
        obst2bottom.y = 375 + randNum2;
        obst2bottom.x = 1580 - obstTime1;
        borderArr[5] = &obst2bottom;
    }
    else if(obstTime3 > 1680){
        obstTime1 = 0;
        randNum2 = random();
        randNum = random();
        reset = true;
     }
    if (obstTime3 < 2180){ // fix
        obst3top.h = 200 + randNum3; // calculates where the obst will be placed
        obst3top.x = 2080 - obstTime3;
        borderArr[6] = &obst3top;

        obst3bottom.y = 375 + randNum3;
        obst3bottom.x = 2080 - obstTime3;
        borderArr[7] = &obst3bottom;
    }
    else{
        obstTime3 = 0;
        randNum3 = random();
    }    
}

void Borders::printBorders(){
    int totalBorder = get_rect_count();
    
    createObstacles();
    for (int i = 0; i < totalBorder; i++){
        SDL_SetRenderDrawColor(renderer,color1,color2,color3,255); 
        SDL_RenderFillRect(renderer, borderArr[i]);
        SDL_RenderDrawRect(renderer, borderArr[i]);
    }
    colors(color1, color1Up);
    colors(color2, color2Up);
    colors(color3, color3Up);
    obstTime1+= 3;
    obstTime2+= 3;
    obstTime3+= 3;
}