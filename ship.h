#ifndef SHIP_HEADER
#define SHIP_HEADER

#include "display.h"
#include "sprites.h"
#include "general.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

#define SHIP_MAX_X BUFFER_W - SHIP_W
#define SHIP_SPEED 1

typedef struct 
{
  int x, y;
  int lives;
  bool hitted;
  bool invulnerable;
  HITBOX hitbox;
} SHIP;

//
void init_ship();
void update_ship_normal_phase ();
void update_ship_boss_phase ();
void verify_game_over(bool* game_over);
void update_ship_frames();
void draw_ship ();
extern SHIP ship;
extern int SHIP_LIVES;
extern int ship_frames;

#endif
