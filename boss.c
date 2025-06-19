#include "boss.h"

BOSS boss;

void init_boss()
{
  boss.x = INITIAL_BOSS_X;
  boss.y = INITIAL_BOSS_Y;
  boss.lives = 25;
}

void draw_boss()
{
  al_draw_bitmap(sprites.boss, boss.x, boss.y, 0);
}
