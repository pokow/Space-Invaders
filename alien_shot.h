#ifndef ALIEN_SHOT_HEADER
#define ALIEN_SHOT_HEADER

#include "general.h"
#include "display.h"
#include "sprites.h"
#include "alien.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

#define ALIEN_SHOT_SPEED 5

typedef struct
{
  int x, y;
  int reloaded;
  int exists;
  int col;
  HITBOX hitbox;
} ALIEN_SHOT;

void alien_shot_init();
void alien_shoot(ALIEN* alien);
void aliens_shooting(ALIEN alien[ALIEN_ROW][ALIEN_COL]);
void update_alien_shots();
void draw_alien_shots();

extern ALIEN_SHOT alien_shot[ALIEN_COL];

#endif 
