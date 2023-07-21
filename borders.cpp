#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include <cstdlib>
#include "borders.hpp"
//#include "rects.hpp"

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

void Borders::initBorders(SDL_Window* window, SDL_Renderer* renderer, Rectangle &rect){
    this->window = window;
    this->renderer = renderer;
    this->rect = rect;
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

string Borders::objRand(){
    int obRand = rand() % 2;
    if (obRand == 1)
        return "ob1";
    else   
        return "ob2";
}
bool Borders::checkCollision(SDL_Rect a, SDL_Rect* b, int i)
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = a.x;
    cout << a.x << " ";
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    //Calculate the sides of rect B // hard coded due to funky array behaviour
    leftB = b[i].x;
    cout << b[i- 2].x << endl;
    rightB = b[i].x + 100;
    topB = b[i].y;
    bottomB = b[i].y + b[i].h;

    if( bottomA <= topB ){
        return true;
    }

    if( topA >= bottomB ){
        return true;
    }

    if( rightA <= leftB ){
        return true;
    }

    if( leftA >= rightB ){
        return true;
    }

    //If none of the sides from A are outside B
    return false;
}


void Borders::type1collision(int i){
    
    SDL_Rect tempRect = rect.getRect();
    bool collide = checkCollision(tempRect, borderArr[i], i);
    SDL_SetRenderDrawColor(renderer, color2, color3 , color1,255); 
    SDL_RenderFillRect(renderer, borderArr[i]);
    SDL_RenderDrawRect(renderer, borderArr[i]);


}
bool Borders::type2collision(int i){

    SDL_Rect tempRect = rect.getRect();
    bool collide = checkCollision(tempRect, borderArr[i], i);
    
    SDL_SetRenderDrawColor(renderer,color1, color3, color2,255); 
    SDL_RenderFillRect(renderer, borderArr[i]);
    SDL_RenderDrawRect(renderer, borderArr[i]);
    return false;
}

void Borders::createObstacles(){
    if (obstTime1 < 1180){ // fix
        obst1top.h = 200 + randNum; // calculates where the obst will be placed
        obst1top.x = 1080 - obstTime1;
        cout << "2 " << obst1top.x << " ";
        borderArr[2] = &obst1top;

        obst1bottom.y = 375 + randNum;
        obst1bottom.x = 1080 - obstTime1;
        cout << "3 " << obst1bottom.x << " ";
        borderArr[3] = &obst1bottom;
    }   
    if (obstTime1 < 1681){ // fix
        obst2top.h = 200 + randNum2; // calculates where the obst will be placed
        obst2top.x = 1580 - obstTime1;
        cout << "4 " << obst2top.x << " ";
        borderArr[4] = &obst2top;
    
        obst2bottom.y = 375 + randNum2;
        obst2bottom.x = 1580 - obstTime1;
        cout << "5 " << obst2bottom.x << " ";
        borderArr[5] = &obst2bottom;
    }
    else if(obstTime3 > 1680){
        obstTime1 = 0;
        randNum2 = random();
        randNum = random();
        obType[0] = objRand();
        obType[1] = objRand();
     }
    if (obstTime3 < 2180){ // fix
        obst3top.h = 200 + randNum3; // calculates where the obst will be placed
        obst3top.x = 2080 - obstTime3;
        cout << "6 " << obst3top.x << " ";
        borderArr[6] = &obst3top;

        obst3bottom.y = 375 + randNum3;
        obst3bottom.x = 2080 - obstTime3;
        cout << "7 " << obst3bottom.x << " ";
        borderArr[7] = &obst3bottom;
    }
    else{
        obstTime3 = 0;
        randNum3 = random();
        obType[2] = objRand();
    }    
}

bool Borders::printBorders(){
    int totalBorder = get_rect_count();
    bool gameCont = false;
    createObstacles();
    for (int i = 2; i < totalBorder; i++){
        cout << i << " ";
            if(obType[(i-2)/2] == "ob1")
                type1collision(i);
            else
                gameCont = type2collision(i);
        }
    for(int i = 0; i < 2; i++){
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
    return gameCont;
}