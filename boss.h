#ifndef BOSS_HEADER
#define BOSS_HEADER

#include <allegro5/allegro_primitives.h>
#include "sprites.h"
#include "display.h"
#include "general.h"

#define INITIAL_BOSS_LIVES 25
#define INITIAL_BOSS_X 40
#define INITIAL_BOSS_Y 30

extern float BOSS_SHOOT_COULDOWN;
#define INITIAL_BOSS_SHOOT_COULDOWN 0.8
extern float BOSS_ATTACK_COULDOWN;
#define INITIAL_BOSS_ATTACK_COULDOWN 3;

#define BOSS_SHOT_SPEED 4
#define BOSS_SHOTS 6
#define BOSS_SPEED 3

typedef struct
{
  int x, y;
  int lives;
  bool can_shoot;
  bool can_attack;
  int dir;
  HITBOX hitbox;
} BOSS;

typedef struct
{
  int x, y;
  bool exists;
  bool reloaded;
  HITBOX hitbox;
} BOSS_SHOT;

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
void init_boss_shots();
void boss_shoots();
void update_boss();
void boss_attack();
void draw_boss();

extern BOSS boss;
extern int BOSS_LIVES;
extern BOSS_SHOT boss_shot[BOSS_SHOTS];
extern int boss_shot_frames;

extern int attack_frames;

extern ATTACK_1 attack_1;

extern ATTACK_2 attack_2;

extern bool attack_3;
extern HITBOX hitbox_attack_3;

#endif
