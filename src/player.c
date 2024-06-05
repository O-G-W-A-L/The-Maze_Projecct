#include "../inc/definitions.h"
#include "../inc/player.h"
#include "../inc/raycast.h"

void handle_player_movement(Player* player, const uint8_t* keystate, float moveSpeed) {
    if (keystate[SDL_SCANCODE_W]) {
        if (!MAP[xy2index((int)(player->pos.x + player->dir.x * moveSpeed), (int)player->pos.y, MAP_SIZE)]) {
            player->pos.x += player->dir.x * moveSpeed;
        }
        if (!MAP[xy2index((int)player->pos.x, (int)(player->pos.y + player->dir.y * moveSpeed), MAP_SIZE)]) {
            player->pos.y += player->dir.y * moveSpeed;
        }
    }

    if (keystate[SDL_SCANCODE_S]) {
        if (!MAP[xy2index((int)(player->pos.x - player->dir.x * moveSpeed), (int)player->pos.y, MAP_SIZE)]) {
            player->pos.x -= player->dir.x * moveSpeed;
        }
        if (!MAP[xy2index((int)player->pos.x, (int)(player->pos.y - player->dir.y * moveSpeed), MAP_SIZE)]) {
            player->pos.y -= player->dir.y * moveSpeed;
        }
    }

    if (keystate[SDL_SCANCODE_D]) {
        Vec2F perpDir = {.x = player->dir.y, .y = -player->dir.x};
        if (!MAP[xy2index((int)(player->pos.x + perpDir.x * moveSpeed), (int)player->pos.y, MAP_SIZE)]) {
            player->pos.x += perpDir.x * moveSpeed;
        }
        if (!MAP[xy2index((int)player->pos.x, (int)(player->pos.y + perpDir.y * moveSpeed), MAP_SIZE)]) {
            player->pos.y += perpDir.y * moveSpeed;
        }
    }

    if (keystate[SDL_SCANCODE_A]) {
        Vec2F perpDir = {.x = player->dir.y, .y = -player->dir.x};
        if (!MAP[xy2index((int)(player->pos.x - perpDir.x * moveSpeed), (int)player->pos.y, MAP_SIZE)]) {
            player->pos.x -= perpDir.x * moveSpeed;
        }
        if (!MAP[xy2index((int)player->pos.x, (int)(player->pos.y - perpDir.y * moveSpeed), MAP_SIZE)]) {
            player->pos.y -= perpDir.y * moveSpeed;
        }
    }
}

void rotate_player(Player* player, float angle, float rotateSpeed) {
    float oldDirX = player->dir.x;
    player->dir.x = player->dir.x * cosf(angle * rotateSpeed) - player->dir.y * sinf(angle * rotateSpeed);
    player->dir.y = oldDirX * sinf(angle * rotateSpeed) + player->dir.y * cosf(angle * rotateSpeed);

    float oldPlaneX = player->plane.x;
    player->plane.x = player->plane.x * cosf(angle * rotateSpeed) - player->plane.y * sinf(angle * rotateSpeed);
    player->plane.y = oldPlaneX * sinf(angle * rotateSpeed) + player->plane.y * cosf(angle * rotateSpeed);
}
