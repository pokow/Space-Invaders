#ifndef SHIP_SHOT_HEADER
#define SHIP_SHOT_HEADER

#include "general.h"
#include "ship.h"
#include "display.h"
#include "sprites.h"
#include "alien.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

#define SHIP_SHOT_SPEED 5

typedef struct
{
  int x, y;
  int reloaded;
  int exists;
  HITBOX hitbox;
} SHIP_SHOT;

void ship_shot_init();
void shoot();
void update_ship_shot();
void draw_ship_shot();

extern SHIP_SHOT ship_shot;

#endif 
