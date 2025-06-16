#include "sprites.h"
#include "general.h"
#include "ship.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

SHIP ship;

void init_ship()
{
  int x = (BUFFER_W / 2) - (SHIP_W / 2);
  int y = (BUFFER_H - SHIP_H) - 4;
  ship.x = x;
  ship.y = y;
  ship.lives = 3;
  ship.hitbox.x1 = x;
  ship.hitbox.y1 = y;
  ship.hitbox.x2 = x + SHIP_W;
  ship.hitbox.y2 = y + SHIP_H;
}

void update_ship ()
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
  //fazer codigo para se colidir com algum tiro, perde vida.
}

void draw_ship ()
{
  al_draw_bitmap(sprites.ship, ship.x, ship.y, 0);
}
