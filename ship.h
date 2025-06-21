#ifndef SHIP_HEADER
#define SHIP_HEADER

#include "display.h"
#include "sprites.h"
#include "general.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

#define SHIP_MAX_X (BUFFER_W - SHIP_W)
#define SHIP_MAX_Y (BUFFER_H - SHIP_H)

extern float SHIP_SPEED;
#define INITIAL_SHIP_SPEED 1.0

#define INITIAL_SHIP_LIVES 3
extern int SHIP_LIVES;

typedef struct 
{
  float x, y;
  int lives;
  bool can_shoot;
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
extern int ship_frames;

#endif
