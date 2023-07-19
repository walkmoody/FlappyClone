#include <iostream>
#include <SDL2/SDL.h>
#include <vector>

//#include "rects.hpp"
using namespace std;
class Menus{

    public:
        
        void menusInit(SDL_Window* window, SDL_Renderer* renderer);
        string splash();
        string mainMenu();
    
    private:
        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;
};