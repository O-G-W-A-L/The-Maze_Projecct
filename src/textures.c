#include "../inc/textures.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

SDL_Texture* textures[NUM_TEXTURES];
void load_textures(SDL_Renderer* renderer) {
    const char* texture_files[NUM_TEXTURES] = {
        "image/wall.png",
        "image/img.png",
    };

    for (int i = 0; i < NUM_TEXTURES; i++) {
        printf("Loading texture: %s\n", texture_files[i]); // Debug statement
        SDL_Surface* surface = IMG_Load(texture_files[i]);
        if (!surface) {
            fprintf(stderr, "IMG_Load Error for %s: %s\n", texture_files[i], IMG_GetError());
            exit(1);
        }
        textures[i] = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
        if (!textures[i]) {
            fprintf(stderr, "SDL_CreateTextureFromSurface Error: %s\n", SDL_GetError());
            exit(1);
        } else {
            printf("Loaded texture %s successfully.\n", texture_files[i]);
        }
    }
}

void free_textures() {
    for (int i = 0; i < NUM_TEXTURES; i++) {
        if (textures[i]) {
            SDL_DestroyTexture(textures[i]);
            textures[i] = NULL;
        }
    }
}
