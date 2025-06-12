#include "sprites.h"
#include "general.h"
#include "ship.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

SHIP ship;

void init_ship()
{
  ship.x = (BUFFER_W / 2) - (SHIP_W / 2);
  ship.y = (BUFFER_H - SHIP_H);
  ship.lives = 3;
}

void update_ship ()
{
  if (key[ALLEGRO_KEY_D]) ship.x ++;
  if (key[ALLEGRO_KEY_A]) ship.x --;

  if (ship.x < 0) ship.x = 0;
  if (ship.x > SHIP_MAX_X) ship.x = SHIP_MAX_X;

  //fazer codigo para se colidir com algum tiro, perde vida.
  //fazer codigo que permite atirar se o can_shoot for verdadeiro.
}

void draw_ship ()
{
  al_draw_bitmap(sprites.ship, ship.x, ship.y, 0);
}
