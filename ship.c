#include "sprites.h"
#include "general.h"
#include "ship.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

SHIP ship;
int SHIP_LIVES = 3;

void init_ship()
{
  int x = (BUFFER_W / 2) - (SHIP_W / 2);
  int y = (BUFFER_H - SHIP_H) - 4;
  ship.x = x;
  ship.y = y;
  ship.lives = SHIP_LIVES;
  ship.hitbox.x1 = x;
  ship.hitbox.y1 = y;
  ship.hitbox.x2 = x + SHIP_W;
  ship.hitbox.y2 = y + SHIP_H;
}

void update_ship ()
{
  if (ship.lives > 0)
  {
    if (key[ALLEGRO_KEY_D]) 
    {
      ship.x += SHIP_SPEED;
    }
    if (key[ALLEGRO_KEY_A])
    {
      ship.x -= SHIP_SPEED;
    }
    if (ship.x < 0) ship.x = 0;
    if (ship.x > SHIP_MAX_X) ship.x = SHIP_MAX_X;
    ship.hitbox.x1 = ship.x;
    ship.hitbox.x2 = ship.x + SHIP_W;
  }
}

void verify_game_over(bool* game_over)
{
  if (ship.lives > 0) 
  {
    *game_over = false;
  }
  else {
    *game_over = true;
  }
}

void draw_ship ()
{
  if (ship.lives > 0)
  {
    al_draw_bitmap(sprites.ship, ship.x, ship.y, 0);
  }
  for (int i = 0; i < ship.lives; i ++)
  {
    al_draw_bitmap(sprites.ship_life, 5 + (i * 10), 15, 0);
  }
}
