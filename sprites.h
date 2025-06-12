#ifndef SHIP_HEADER
#define SHIP_HEADER

#include <allegro5/allegro5.h>

#define SHIP_W 12
#define SHIP_H 13
#define SHIP_SHOT_W 2
#define SHIP_SHOT_H 9 
#define SHIP_LIFE_W 6
#define SHIP_LIFE_H 6

#define ALIEN_W 14
#define ALIEN_H 9
#define ALIEN_SHOT_W 4
#define ALIEN_SHOT_H 4

#define BOSS_W 45
#define BOSS_H 27
#define BOSS_SHOT_W 13
#define BOSS_SHOT_H 10

typedef struct {
  ALLEGRO_BITMAP* _sheet;
  ALLEGRO_BITMAP* ship;
  ALLEGRO_BITMAP* ship_shot;
  ALLEGRO_BITMAP* ship_life;
  ALLEGRO_BITMAP* alien;
  ALLEGRO_BITMAP* alien_shot;
  ALLEGRO_BITMAP* boss;
  ALLEGRO_BITMAP* boss_shot;
} SPRITES;

void init_sprites();
void destroy_sprites();
extern SPRITES sprites;

#endif
