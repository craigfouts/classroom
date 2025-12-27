#include <stdio.h>
#include <stdlib.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

bool init();
void end();
bool makeWindow();
bool loadMedia();
void loop();

SDL_Window *gWindow = NULL;
SDL_Surface *gScreenSurface = NULL;
SDL_Surface *gHelloWorld = NULL;

int main(void) {
    if (!init())
        return -1;

    if (!makeWindow())
        return -2;

    if (!loadMedia())
        return -4;

    loop();
    end();

    return 0;
}

bool init() {
    bool success = SDL_Init(SDL_INIT_VIDEO);

    if (!success)
        SDL_Log("Initialization failed: %s\n", SDL_GetError());

    return success;
}

void end() {
    SDL_DestroySurface(gHelloWorld);
    gHelloWorld = NULL;
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    gScreenSurface = NULL;
    SDL_Quit();
}

bool makeWindow() {
    const int kScreenWidth = 640;
    const int kScreenHeight = 480;

    gWindow = SDL_CreateWindow("Hello, World!", kScreenWidth, kScreenHeight, 0);

    if (gWindow == NULL) {
        SDL_Log("Failed to create window: %s\n", SDL_GetError());

        return false;
    }

    gScreenSurface = SDL_GetWindowSurface(gWindow);

    return true;
}

bool loadMedia() {
    char *imagePath = "assets/hello.bmp";

    gHelloWorld = SDL_LoadBMP(imagePath);

    if (gHelloWorld == NULL) {
        SDL_Log("Failed to load media: %s\n", SDL_GetError());

        return false;
    }

    return true;
}

void loop() {
    bool quit = false;
    SDL_Event e;
    SDL_zero(e);

    while (!quit) {
        while (SDL_PollEvent(&e))
            if (e.type == SDL_EVENT_QUIT)
                quit = true;

        SDL_FillSurfaceRect(gScreenSurface, NULL, SDL_MapSurfaceRGB(gScreenSurface, 0xFF, 0xFF, 0xFF));
        SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
        SDL_UpdateWindowSurface(gWindow);
    }
}
