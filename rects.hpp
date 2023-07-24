#include <iostream>
#include <SDL2/SDL.h>
#include <vector>

//#include "rects.cpp"

using namespace std;

class Rectangle{
    public:
        bool rectInput(SDL_Event &, bool &);
        void initRectangle(SDL_Window* , SDL_Renderer* );
        void setRectangleX();
        void setRectangleY(int);
        int getRectangleX();
        int getRectangleY();
        SDL_Rect getRect();
        void printRect();
        SDL_Surface* load_surface();
        void close();
        void right();
        void left();
    private:
        SDL_Rect user;
        bool down = false;
        bool rightPress = false;
        bool leftPress = false;
        int downAccel = 0;
        int upAccel = 0;
        int userFSpeed = 7; // forward speed
        int userBSpeed = 5; // backward speed
        SDL_Surface* screenSurface = nullptr;
        SDL_Surface* charSprite = nullptr;
        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;
        SDL_Texture* texture = nullptr;
};

