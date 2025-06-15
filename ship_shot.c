#include "ship_shot.h"

SHIP_SHOT ship_shot;

void ship_shot_init()
{
  ship_shot.reloaded = 1;
  ship_shot.exists = 0;
}

void shoot()
{
  if (ship_shot.reloaded && key[ALLEGRO_KEY_SPACE])
  {
    float ship_shot_x = ship.x + (SHIP_W / 2.0) - (SHIP_SHOT_W / 2.0);
    ship_shot.x = ship_shot_x;
    ship_shot.y = ship.y;
    ship_shot.hitbox.x1 = ship_shot_x;
    ship_shot.hitbox.y1 = ship.y;
    ship_shot.hitbox.x2 = ship_shot_x + SHIP_SHOT_W;
    ship_shot.hitbox.y2 = ship.y + SHIP_SHOT_W;
    ship_shot.exists = 1;
    ship_shot.reloaded = 0;
  }
}

void update_ship_shot()
{
  if (ship_shot.exists)
  {
    ship_shot.y -= SHIP_SHOT_SPEED;
    ship_shot.hitbox.y1 -= SHIP_SHOT_SPEED;
    ship_shot.hitbox.y2 -= SHIP_SHOT_SPEED;
  }
}


void draw_ship_shot()
{
  if (ship_shot.exists)
  {
    int x = ship_shot.x;
    int y = ship_shot.y;
    al_draw_bitmap(sprites.ship_shot, x, y, 0);
    if (y <= 0)
    {
      ship_shot.exists = 0;
      ship_shot.reloaded = 1;
    }
  }
}

