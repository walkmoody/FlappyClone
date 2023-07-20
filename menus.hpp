#include <iostream>
#include <SDL2/SDL.h>
#include <vector>

//#include "rects.hpp"
using namespace std;
class Menus{

    public:
        
        void menusInit(SDL_Window*, SDL_Renderer*, SDL_Event &);
        string splash();
        string mainMenu();
        string game_screen();
        string instructions();
        string game_over();
        string good_bye();
    
    private:
        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;
        SDL_Event windowEvent;
};