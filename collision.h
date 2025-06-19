#ifndef COLLISION_HEADER
#define COLLISION_HEADER


#include "alien.h"
#include "ship_shot.h"
#include "alien_shot.h"
#include "general.h"
#include "ship.h"

bool collision (HITBOX hitbox1, HITBOX hitbox2);
bool shipshot_collided_to_alien();
bool alienshot_collided_to_ship();
bool ship_collided_to_alien();
bool alien_collided_to_ground();

#endif
