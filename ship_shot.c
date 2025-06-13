#include "ship_shot.h"

SHIP_SHOT ship_shot;

void ship_shot_init()
{
  ship_shot.reloaded = 1;
  ship_shot.exists = 0;
}

void shoot()
{
  if (ship_shot.reloaded)
  {
    if (key[ALLEGRO_KEY_SPACE])
    {
      float ship_shot_x = ship.x + (SHIP_W / 2.0) - (SHIP_SHOT_W / 2.0);
      ship_shot.x = ship_shot_x;
      ship_shot.y = ship.y;
      ship_shot.exists = 1;
    }
  }
}

void update_ship_shot()
{
  if (ship_shot.exists) ship_shot.y -= 5;
}

void draw_ship_shot()
{
  if (ship_shot.exists)
  {
    int x = ship_shot.x;
    int y = ship_shot.y;
    al_draw_bitmap(sprites.ship_shot, x, y, 0);
    ship_shot.reloaded = 0;
    if (y <= 0) ship_shot.reloaded = 1;
  }
}

