#ifndef TEXTURES_H
#define TEXTURES_H

#include <SDL2/SDL.h>

#define NUM_TEXTURES 2
#define TEXTURE_WIDTH 64
#define TEXTURE_HEIGHT 64

extern SDL_Texture* textures[NUM_TEXTURES];

void load_textures(SDL_Renderer *renderer);
void free_textures();

#endif // TEXTURES_H
