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

void Borders::initBorders(SDL_Window* window, SDL_Renderer* renderer, SDL_Event &windowEvent){
    this->window = window;
    this->renderer = renderer;
    this->windowEvent = windowEvent;
    rect.initRectangle(window, renderer);
    rect.load_surface();
    randNum = random();
    randNum2 = random();
    randNum3 = random();
    score = 0;
    speed = 0;
    obst1Count = false;
    obst2Count = false;
    obst3Count = false;
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
void Borders::closeRect(){
    rect.close();
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
bool Borders::checkCollision(int i){
    //The sides of the rectangles
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
    leftA = rect.getRectangleX();
    rightA = rect.getRectangleX() + 50;
    topA =  rect.getRectangleY();
    bottomA = rect.getRectangleY()+ 50;

    //cout << leftA << " " << rightA << " " << topA << " " << bottomA << endl;
    //Calculate the sides of rect B 
    leftB = tempX;
    rightB = tempX + 100;
    topB = tempY;
    bottomB = tempY + tempH;
    
    // left A is the left side of the player 

    // right B is the right side of the obsticle // (rightA > leftB && rightB > leftA) && (bottomB > topA)
    if (i % 2 == 0){ // TOP (AKA odd i) // i % 2 == 0 // (((rightA > leftB && !(leftA > rightB)) || (rightB > leftA && !(rightA > leftB))) && (bottomB > topA))
        if((rightA > leftB && !(leftA > rightB)) && (bottomB > topA)){
            cout << leftB << " " << rightB << " " << topB << " " << bottomB << endl;
            collideTest = true;
            cout << "COLLIDED TRUE" << endl;
        }
    }
    else if (i % 2 == 1){
        if((rightA > leftB && !(leftA > rightB)) && (topB < bottomA)){
            collideTest = true;  // make true
        
            //cout << "BOTTOM" << endl;
        }
    }
    return collideTest;
}


bool Borders::type1collision(int i){
    
    bool collide = checkCollision(i);
    SDL_SetRenderDrawColor(renderer, color2, color3 , color1,255); 
    SDL_RenderFillRect(renderer, borderArr[i]);
    SDL_RenderDrawRect(renderer, borderArr[i]);
    return collide;
    

}
bool Borders::type2collision(int i){

    bool collide = checkCollision(i);
    SDL_SetRenderDrawColor(renderer,255, 0, 0,255); 
    SDL_RenderFillRect(renderer, borderArr[i]);
    SDL_RenderDrawRect(renderer, borderArr[i]);
    return collide;
}

void Borders::createObstacles(){
    if (obstTime1 < 1180){ // fix
        obst1top.h = 200 + randNum; // calculates where the obst will be placed
        obst1top.x = 1080 - obstTime1;
        borderArr[2] = &obst1top;
        if (rect.getRectangleX() > obst1top.x + 50 && obst1Count == false){
            score++;
            obst1Count = true;
        }
        obst1bottom.y = 375 + randNum;
        obst1bottom.x = 1080 - obstTime1;
        borderArr[3] = &obst1bottom;
    }   
    if (obstTime1 < 1681){ // fix
        obst2top.h = 200 + randNum2; // calculates where the obst will be placed
        obst2top.x = 1580 - obstTime1;
        borderArr[4] = &obst2top;
        if (rect.getRectangleX() > obst2top.x + 50 && obst2Count == false){
            score++;
            obst2Count = true;
        }
    
        obst2bottom.y = 375 + randNum2;
        obst2bottom.x = 1580 - obstTime1;
        borderArr[5] = &obst2bottom;
    }
    else if(obstTime3 > 1680){
        obstTime1 = 0;
        obst1Count = false;
        obst2Count = false;
        randNum2 = random();
        randNum = random();
        obType[0] = objRand();
        obType[1] = objRand();
     }
    if (obstTime3 < 2180){ // fix
        obst3top.h = 200 + randNum3; // calculates where the obst will be placed
        obst3top.x = 2080 - obstTime3;
        borderArr[6] = &obst3top;
        if (rect.getRectangleX() > obst3top.x + 50 && obst3Count == false){
            score++;
            obst3Count = true;
        }
        obst3bottom.y = 375 + randNum3;
        obst3bottom.x = 2080 - obstTime3;
        borderArr[7] = &obst3bottom;
    }
    else{
        obstTime3 = 0;
        obst3Count = false;
        randNum3 = random();
        obType[2] = objRand();
    }    
}

string Borders::printBorders(){
    bool quit = false;
    quit = rect.rectInput(windowEvent, quit);
    if (quit == true){
        rect.close();
        return "quit";
    }
    //rect.setRectangleX();
    int totalBorder = get_rect_count();
    createObstacles();
    cout << "SCORE: " << score << endl;
    for (int i = 2; i < totalBorder; i++){
        if (gameCont == true)
            break;
        if(obType[(i-2)/2] == "ob1")
            gameCont = type1collision(i);
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

    rect.printRect();
    

    colors(color1, color1Up);
    colors(color2, color2Up);
    colors(color3, color3Up);
    if (score > 3){
        speed = 2;
    }
    if (score > 6){
        speed = 3;
    }
    if (score > 10){
        speed = 4;
    }
    if (score > 15){
        speed = 5;
    }
    obstTime1+= 3 + speed;
    obstTime2+= 3 + speed;
    obstTime3+= 3 + speed;
    if (gameCont ==  true)
        return "gameOver";
    else 
        return "";
}