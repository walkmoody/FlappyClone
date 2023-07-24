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
bool Borders::checkCollision(SDL_Rect a, int i){
    //The sides of the rectangles
    bool collideTest = false;
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;
    int tempX, tempY, tempH;
    if (i == 2){  //TODO SHORTEN THIS DOWN;
        tempX = obst1top.x;
        tempH = obst1top.h;
        tempY = 0;
    }
    else if (i == 3){
        tempX = obst1bottom.x; // hard coded due to funky array behaviour
        tempH = 700;
        tempY = obst1bottom.y;
    }
    else if (i == 4){
        tempX = obst2top.x;
        tempH = obst2top.h;
        tempY = 0;
    }
    else if (i == 5){
        tempX = obst2bottom.x; 
        tempH = 700;
        tempY = obst2bottom.y;
    }
    else if (i == 6){
        tempX = obst3top.x;
        tempH = obst3top.h;
        tempY = 0;
    }
    else if (i == 7){
        tempX = obst3bottom.x; 
        tempH = 700;
        tempY = obst3bottom.y;
    }
 
    //Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    //Calculate the sides of rect B 
    leftB = tempX;
    rightB = tempX + 100;
    topB = tempY;
    bottomB = tempY + tempH;
    if(!(leftA > rightB || rightA < leftB || topA > bottomB || bottomA < topB)){
        collideTest = true;
    }
    /*if( bottomA <= topB ){
        cout << "test1";
        collideTest = false;
    }

    if( topA >= bottomB ){
        cout << "test2";
        collideTest = false;
    }

    if( rightA <= leftB ){
        cout << "test3";
        collideTest = false;
    }

    if( leftA >= rightB ){
        cout << "test4";
        collideTest = false;
    }
    */

    //If none of the sides from A are outside B
    return collideTest;
}


void Borders::type1collision(int i){
    
    SDL_Rect tempRect = rect.getRect();
    bool collide = checkCollision(tempRect, i);
    SDL_SetRenderDrawColor(renderer, color2, color3 , color1,255); 
    SDL_RenderFillRect(renderer, borderArr[i]);
    SDL_RenderDrawRect(renderer, borderArr[i]);
    cout << collide << "TYPE 1" << endl;


}
bool Borders::type2collision(int i){

    SDL_Rect tempRect = rect.getRect();
    bool collide = checkCollision(rect.getRect(), i);
    cout << collide << "collide" << endl;
    SDL_SetRenderDrawColor(renderer,color1, color3, color2,255); 
    SDL_RenderFillRect(renderer, borderArr[i]);
    SDL_RenderDrawRect(renderer, borderArr[i]);
    return collide;
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
    if (obstTime1 < 1681){ // fix
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
        obType[0] = objRand();
        obType[1] = objRand();
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
        obType[2] = objRand();
    }    
}

bool Borders::printBorders(){
    int totalBorder = get_rect_count();
    createObstacles();
    for (int i = 2; i < totalBorder; i++){
        if (gameCont == true)
            break;
        if(obType[(i-2)/2] == "ob1")
            type1collision(i);
        else
            gameCont = type2collision(i);
        if (gameCont == true)
            break;    
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