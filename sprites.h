#ifndef SPRITES_HEADER
#define SPRITES_HEADER

#include <allegro5/allegro5.h>
#include "general.h"

#define SHIP_W 12
#define SHIP_H 13
#define SHIP_SHOT_W 2
#define SHIP_SHOT_H 11
#define SHIP_LIFE_W 8
#define SHIP_LIFE_H 8

#define ALIEN_W 16
#define ALIEN_H 13
#define ALIEN_FROG_W 16
#define ALIEN_FROG_H 16
#define ALIEN_SHOT_W 2
#define ALIEN_SHOT_H 10

#define EXPLOSION_W 10
#define EXPLOSION_H 8

#define BOSS_W 45
#define BOSS_H 27
#define BOSS_SHOT_W 13
#define BOSS_SHOT_H 10


typedef struct 
{
  ALLEGRO_BITMAP* _sheet;
  ALLEGRO_BITMAP* ship;
  ALLEGRO_BITMAP* ship_shot;
  ALLEGRO_BITMAP* ship_life;
  ALLEGRO_BITMAP* alien[3];
  ALLEGRO_BITMAP* alien_frog[3];
  ALLEGRO_BITMAP* alien_shot;
  ALLEGRO_BITMAP* explosion;
  ALLEGRO_BITMAP* boss;
  ALLEGRO_BITMAP* boss_shot;
} SPRITES;

void init_sprites();
void destroy_sprites();
extern SPRITES sprites;

#endif
