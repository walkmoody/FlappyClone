#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include "rects.hpp"

using namespace std;

class Borders{
    public:
        void initBorders(SDL_Window*, SDL_Renderer*,  SDL_Event &);
        void createBorders();
        string printBorders();
        int get_rect_count();
        void createObstacles();
        int random();
        void colors(int &, bool &);
        void closeRect();
        string objRand();
        bool type1collision(int);
        bool type2collision(int);
        bool checkCollision(int);
    private:
        Rectangle rect;
        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;
        SDL_Event windowEvent;
        int arrSize = 100;
        SDL_Rect *borderArr[100] = {};
        SDL_Rect top;
        SDL_Rect bottom;
        SDL_Rect obst1top;
        SDL_Rect obst1bottom;
        SDL_Rect obst2top;
        SDL_Rect obst2bottom;
        SDL_Rect obst3top;
        SDL_Rect obst3bottom;
        int color1 = 100;
        int color2 = 200;
        int color3 = 100;
        bool color1Up = true;
        bool color2Up = false;
        bool color3Up = true;
        int obstTime1 = 0;
        int obstTime2 = 0;
        int obstTime3 = 0;
        int randNum = 0;
        int randNum2 = 0;
        int randNum3 =0;
        int score;
        int speed = 0;
        bool obst1Count = false;
        bool obst2Count = false;
        bool obst3Count = false;
        bool gameCont = false;
        bool collideTest = false;
        std::string obType[3] ={"ob1", "ob1", "ob1"};
};
