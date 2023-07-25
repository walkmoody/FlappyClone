#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>

using namespace std;
class Menus{

    public:
        
        void menusInit(SDL_Window*, SDL_Renderer*, SDL_Event &, SDL_Surface*, TTF_Font*);
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
        SDL_Texture* Message = nullptr;
        SDL_Texture* texture = nullptr;
        SDL_Rect Message_rect;
        SDL_Rect viewport;
        TTF_Font* Sans = TTF_OpenFont("Sans.ttf", 24);
        SDL_Color White = {255, 255, 255};
        SDL_Color Black = {10, 10, 10};
        const int FPS = 60;
};

