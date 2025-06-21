#ifndef ALIEN_HEADER
#define ALIEN_HEADER

#include "sprites.h"
#include "general.h"
#include "ship.h"
#include "sprites.h"
#include "display.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define FIRST_ALIEN_X 25
#define FIRST_ALIEN_Y 25
#define ALIEN_DISTANCE 30
#define INITIAL_ALIEN_ROW 3
#define INITIAL_ALIEN_COL 3
#define INITIAL_ALIEN_SPEED 4
#define INITIAL_INCREASE_ALIEN_SPEED 0.5
#define INITIAL_SHOOT_CHANCE 10   // 1/10 de chance
extern int ALIEN_ROW;
extern int ALIEN_COL;
extern int ALIEN_SPEED;
extern float INCREASE_ALIEN_SPEED; // --> a cada alien morto, seu fps aumenta essa quantia
extern int SHOOT_CHANCE; // --> quanto menor, maior a chance do alien atirar

typedef struct
{
  float x, y;
  int alive;
  int dir; // 1 --> right, -1 --> left
  HITBOX hitbox;
  int type;  // 1 --> normal, 2 --> frog
  int frame;
  int below;
  int col;
  int shoot;
} ALIEN;

void init_aliens();
void free_aliens();
void define_below();
void define_shooter();
void draw_aliens();
ALIEN find_last ();
void update_aliens();

extern ALIEN **aliens;

#endif
