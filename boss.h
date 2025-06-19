#ifndef BOSS_HEADER
#define BOSS_HEADER

#include "sprites.h"

#define INITIAL_BOSS_X 40
#define INITIAL_BOSS_Y 30

typedef struct
{
  int x, y;
  int lives;
  HITBOX hitbox;
} BOSS;

void init_boss();
void draw_boss();

extern BOSS boss;

#endif
