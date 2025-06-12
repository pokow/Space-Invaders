#ifndef SPRITE_HEADER
#define SPRITE_HEADER

#include "display.h"
#include "sprites.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

#define SHIP_MAX_X BUFFER_W - (SHIP_W/2)

typedef struct 
{
  int x, y;
  int can_shoot;
  int lives;
} SHIP;


void init_ship();
void update_ship ();
void draw_ship ();
extern SHIP ship;

#endif
