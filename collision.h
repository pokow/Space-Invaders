#ifndef COLLISION_HEADER
#define COLLISION_HEADER


#include "alien.h"
#include "ship_shot.h"
#include "alien_shot.h"
#include "general.h"
#include "ship.h"
#include "boss.h"
#include "boss_attack.h"

bool collision (HITBOX hitbox1, HITBOX hitbox2);
void shipshot_collided_to_alien();
void alienshot_collided_to_ship();
void ship_collided_to_alien();
void alien_collided_to_ground();
void ship_collided_to_boss_attack();
void shipshot_collided_to_boss();
void ship_collided_to_boss();
void bossshot_collided_to_ship();

#endif
