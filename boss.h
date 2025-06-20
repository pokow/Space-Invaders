#ifndef BOSS_HEADER
#define BOSS_HEADER

#include <allegro5/allegro_primitives.h>
#include "sprites.h"
#include "display.h"
#include "general.h"

#define INITIAL_BOSS_LIVES 25
#define INITIAL_BOSS_X 40
#define INITIAL_BOSS_Y 30
#define BOSS_SPEED 3

typedef struct
{
  int x, y;
  int lives;
  bool can_attack;
  int dir;
  HITBOX hitbox;
} BOSS;

typedef struct
{
  bool attack;
  int y;
  int pre_attack_height;
  int attack_height;
  HITBOX hitbox;
} ATTACK_1;

typedef struct
{
  bool attack;
  int x;
  int pre_attack_width;
  int attack_width;
  HITBOX hitbox;
} ATTACK_2;

void init_boss();
void update_boss();
void boss_attack();
void draw_boss();

extern BOSS boss;
extern int BOSS_LIVES;

extern int attack_frames;

extern ATTACK_1 attack_1;

extern ATTACK_2 attack_2;

extern bool attack_3;
extern HITBOX hitbox_attack_3;

#endif
