#ifndef PLAYER_H
#define PLAYER_H

#include "definitions.h"

void handle_player_movement(Player* player, const uint8_t* keystate, float moveSpeed);
void rotate_player(Player* player, float angle, float rotateSpeed);

#endif // PLAYER_H

