#include <iostream>
#include <SDL.h>
#include <bits/stdc++.h>

using namespace std;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
int RAND(int l,int r) {return l + rd() % (r - l + 1);}

const int SCREEN_WIDTH = RAND(500, 800);
const int SCREEN_HEIGHT = RAND(500, 800);

const string WINDOW_TITLE = ":) by Bui Minh Hoat";

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);

void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal = false);

void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

void waitUntilKeyPressed();

int main(int argc, char* argv[]) {
    for (int j = 1; j <= 1; ++j) {
        SDL_Window* window;
        SDL_Renderer* renderer;
        initSDL(window, renderer);

        // Your drawing code here
        // use SDL_RenderPresent(renderer) to show it
        SDL_RenderClear(renderer);
//        waitUntilKeyPressed();
        for (int i = 1; i <= 10000; ++i) {
            SDL_SetRenderDrawColor(renderer, RAND(0, 256), RAND(0, 256), RAND(0, 256), RAND(0, 256));   // white
            SDL_RenderDrawPoint(renderer, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
            // SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);   // red
            // SDL_RenderDrawLine(renderer, 100, 100, 200, 200);
            SDL_Rect filled_rect;
            filled_rect.x = RAND(0, SCREEN_WIDTH);
            filled_rect.y = RAND(0, SCREEN_HEIGHT);
            filled_rect.w = RAND(0, SCREEN_WIDTH - filled_rect.x);
            filled_rect.h = RAND(0, SCREEN_HEIGHT - filled_rect.y);
            SDL_SetRenderDrawColor(renderer, RAND(0, 256), RAND(0, 256), RAND(0, 256), RAND(0, 256)); // green
            SDL_RenderFillRect(renderer, &filled_rect);


            //Khi thông thường chạy với môi trường bình thường ở nhà
            SDL_RenderPresent(renderer);
            //Khi chạy ở máy thực hành WinXP ở trường (máy ảo)
            //SDL_UpdateWindowSurface(window);
    //        waitUntilKeyPressed();
        }
//        waitUntilKeyPressed();
        quitSDL(window, renderer);
    }
    return 0;
}

void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal) {
    os << msg << " Error: " << SDL_GetError() << std::endl;
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logSDLError(std::cout, "SDL_Init", true);

    window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    //window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
//       SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (window == nullptr) logSDLError(std::cout, "CreateWindow", true);


    //Khi thông thường chạy với môi trường bình thường ở nhà
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                  SDL_RENDERER_PRESENTVSYNC);
    //Khi chạy ở máy thực hành WinXP ở trường (máy ảo)
    //renderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));
    if (renderer == nullptr) logSDLError(std::cout, "CreateRenderer", true);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void quitSDL(SDL_Window* window, SDL_Renderer* renderer) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void waitUntilKeyPressed() {
    SDL_Event e;
    while (true) {
        if ( SDL_WaitEvent(&e) != 0 &&
                (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}

/*
    :)
*/
