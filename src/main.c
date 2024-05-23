#include <SDL2/SDL.h>
#include <stdbool.h>
#include "definitions.h"
#include "render.h"
#include "player.h"

int main(void) {
    ASSERT(!SDL_Init(SDL_INIT_VIDEO), "SDL failed to initialize; %s\n", SDL_GetError());

    State state = {
        .quit = false,
    };

    state.window = SDL_CreateWindow(
        "Raycast",
        SDL_WINDOWPOS_CENTERED_DISPLAY(0),
        SDL_WINDOWPOS_CENTERED_DISPLAY(0),
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_ALLOW_HIGHDPI
    );
    ASSERT(state.window, "Failed to create SDL window: %s\n", SDL_GetError());

    state.renderer = SDL_CreateRenderer(state.window, -1, SDL_RENDERER_PRESENTVSYNC);
    ASSERT(state.renderer, "Failed to create SDL renderer: %s\n", SDL_GetError());

    SDL_SetHint(SDL_HINT_MOUSE_RELATIVE_MODE_WARP, "1");
    SDL_SetRelativeMouseMode(true);

    Player player = {
        .pos = {.x = 4.0f, .y = 4.0f},
        .dir = {.x = -1.0f, .y = 0.0f},
        .plane = {.x = 0.0f, .y = 0.66f},
    };

    const float rotateSpeed = 0.025;
    const float moveSpeed = 0.05;

    while (!state.quit) {
        SDL_Event event;
        int mouse_xrel = 0;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    state.quit = true;
                    break;
                case SDL_MOUSEMOTION:
                    mouse_xrel = event.motion.xrel;
                    break;
            }
        }

        const uint8_t* keystate = SDL_GetKeyboardState(NULL);
        if (keystate[SDL_SCANCODE_ESCAPE]) state.quit = true;

        if (mouse_xrel != 0) {
            rotate_player(&player, mouse_xrel * -0.1, rotateSpeed);
        }

        handle_player_movement(&player, keystate, moveSpeed);

        SDL_SetRenderDrawColor(state.renderer, 0x18, 0x18, 0x18, 0xFF);
        SDL_RenderClear(state.renderer);

        render(&state, &player);

        SDL_RenderPresent(state.renderer);
    }

    SDL_DestroyRenderer(state.renderer);
    SDL_DestroyWindow(state.window);
    SDL_Quit();
    return 0;
}

