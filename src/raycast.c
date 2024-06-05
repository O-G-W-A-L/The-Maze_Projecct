#include "../inc/definitions.h"
#include "../inc/raycast.h"
#include "../inc/textures.h"
#include <SDL2/SDL.h>
#include <math.h>
#include <stdio.h>

void render(State *state, Player* player) {
    for (int x = 0; x < SCREEN_WIDTH; ++x) {
        float cameraX = 2 * x / (float)SCREEN_WIDTH - 1;
        Vec2F rayDir = {
            .x = player->dir.x + player->plane.x * cameraX,
            .y = player->dir.y + player->plane.y * cameraX,
        };

        Vec2I mapBox = {
            .x = (int)player->pos.x,
            .y = (int)player->pos.y
        };

        Vec2F sideDist = {};
        Vec2F deltaDist = {
            .x = (rayDir.x == 0) ? 1e30 : fabsf(1 / rayDir.x),
            .y = (rayDir.y == 0) ? 1e30 : fabsf(1 / rayDir.y),
        };
        float perpWallDist;
        Vec2I stepDir = {};

        bool hit = false;
        Side side;

        if (rayDir.x < 0) {
            stepDir.x = -1;
            sideDist.x = (player->pos.x - mapBox.x) * deltaDist.x;
        } else {
            stepDir.x = 1;
            sideDist.x = (mapBox.x + 1.0f - player->pos.x) * deltaDist.x;
        }
        if (rayDir.y < 0) {
            stepDir.y = -1;
            sideDist.y = (player->pos.y - mapBox.y) * deltaDist.y;
        } else {
            stepDir.y = 1;
            sideDist.y = (mapBox.y + 1.0f - player->pos.y) * deltaDist.y;
        }

        while (!hit) {
            if (sideDist.x < sideDist.y) {
                sideDist.x += deltaDist.x;
                mapBox.x += stepDir.x;
                side = EastWest;
            } else {
                sideDist.y += deltaDist.y;
                mapBox.y += stepDir.y;
                side = NorthSouth;
            }

            if (MAP[xy2index(mapBox.x, mapBox.y, MAP_SIZE)] > 0) {
                hit = true;
            }
        }

        switch (side) {
            case EastWest:
                perpWallDist = (sideDist.x - deltaDist.x);
                break;
            case NorthSouth:
                perpWallDist = (sideDist.y - deltaDist.y);
                break;
        }

        int lineHeight = (int)(SCREEN_HEIGHT / perpWallDist * 1.5);

        int drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
        if (drawStart < 0) drawStart = 0;
        int drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
        if (drawEnd >= SCREEN_HEIGHT) drawEnd = SCREEN_HEIGHT - 1;

        int textureIndex = MAP[xy2index(mapBox.x, mapBox.y, MAP_SIZE)] - 1;
        if (textureIndex >= NUM_TEXTURES) {
            textureIndex = 0;
        }

        double wallX;
        if (side == EastWest) {
            wallX = player->pos.y + perpWallDist * rayDir.y;
        } else {
            wallX = player->pos.x + perpWallDist * rayDir.x;
        }
        wallX -= floor(wallX);

        int texX = (int)(wallX * (double)TEXTURE_WIDTH);
        if ((side == EastWest && rayDir.x > 0) || (side == NorthSouth && rayDir.y < 0)) {
            texX = TEXTURE_WIDTH - texX - 1;
        }

        // Sky rendering
        SDL_SetRenderDrawColor(state->renderer, 135, 206, 235, 255);
        for (int y = 0; y < drawStart; y++) {
            SDL_RenderDrawPoint(state->renderer, x, y);
        }

        // Wall rendering
        for (int y = drawStart; y < drawEnd; y++) {
            int d = y * 256 - SCREEN_HEIGHT * 128 + lineHeight * 128;
            int texY = ((d * TEXTURE_HEIGHT) / lineHeight) / 256;
            SDL_Rect srcRect = { texX, texY, 1, 1 };
            SDL_Rect dstRect = { x, y, 1, 1 };
            SDL_RenderCopy(state->renderer, textures[textureIndex], &srcRect, &dstRect);
        }

        // Floor casting with gray color
        SDL_SetRenderDrawColor(state->renderer, 139, 69, 19, 255); 
        for (int y = drawEnd + 1; y < SCREEN_HEIGHT; y++) {
            SDL_RenderDrawPoint(state->renderer, x, y);
        }
    }

    SDL_RenderPresent(state->renderer);
}
