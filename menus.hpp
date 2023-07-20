#include <iostream>
#include <SDL2/SDL.h>
//#include <SDL2/SDL_ttf.h>
#include <vector>

using namespace std;
class Menus{

    public:
        
        void menusInit(SDL_Window*, SDL_Renderer*, SDL_Event &, SDL_Surface*);
        string splash();
        string mainMenu();
        string game_screen();
        string instructions();
        string game_over();
        string good_bye();
        bool loadMedia();
        bool init();
        void close();
    
    private:
        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;
        SDL_Event windowEvent;
        SDL_Surface* screenSurface = nullptr;
        SDL_Surface* test = nullptr;
        //TTF_Font* Sans = TTF_OpenFont("Sans.ttf", 24); //TODO figure out fonts
        SDL_Color White = {255, 255, 255};
        const int FPS = 60;
};

