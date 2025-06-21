#ifndef SHIP_SHOT_HEADER
#define SHIP_SHOT_HEADER

#include "general.h"
#include "ship.h"
#include "display.h"
#include "sprites.h"
#include "alien.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

#define MAX_BULLETS 6

#define SHIP_SHOT_SPEED 5
extern float COULDOWN;
#define INITIAL_COULDOWN 0.7

typedef struct
{
  int x, y;
  int reloaded;
  int exists;
  HITBOX hitbox;
} SHIP_SHOT;

void update_ship_shot_frames();
void ship_shot_init();
void ship_shoots();
void update_ship_shot();
void draw_ship_shot();

extern SHIP_SHOT ship_shot[MAX_BULLETS];
extern int ship_shot_frames;

#endif 
