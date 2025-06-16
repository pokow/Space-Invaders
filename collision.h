#ifndef COLLISION_HEADER
#define COLLISION_HEADER


#include "alien.h"
#include "ship_shot.h"

bool collision (HITBOX hitbox1, HITBOX hitbox2);
bool ship_shot_collision(SHIP_SHOT *shot, ALIEN aliens[ALIEN_ROW][ALIEN_COL]);

#endif
