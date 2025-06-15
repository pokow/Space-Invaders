#ifndef ALIEN_HEADER
#define ALIEN_HEADER

#include "sprites.h"
#include "general.h"
#include "ship.h"
#include "sprites.h"
#include "display.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

#define FIRST_ALIEN_X 50
#define FIRST_ALIEN_Y 50
#define ALIEN_DISTANCE 30
#define ALIEN_ROW 6
#define ALIEN_COL 6
#define ALIEN_SPEED 4

typedef struct
{
  float x, y;
  int alive;
  int dir; // 1 --> right, -1 --> left
  HITBOX hitbox;
} ALIEN;

void init_aliens();
void draw_aliens();
ALIEN find_last ();
void update_aliens();

extern ALIEN aliens[ALIEN_ROW][ALIEN_COL];

#endif
