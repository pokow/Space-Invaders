#include "sprites.h"
#include "general.h"
#include "ship.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

SHIP ship;

int SHIP_LIVES = INITIAL_SHIP_LIVES;

float SHIP_SPEED = INITIAL_SHIP_SPEED;

int ship_frames = 0;

void init_ship()
{
  float x = (BUFFER_W / 2.0) - (SHIP_W / 2.0);
  float y = (BUFFER_H - SHIP_H) - 4;
  ship.x = x;
  ship.y = y;
  ship.hitted = false;
  ship.lives = SHIP_LIVES;
  ship.hitbox.x1 = x;
  ship.hitbox.y1 = y;
  ship.hitbox.x2 = x + SHIP_W;
  ship.hitbox.y2 = y + SHIP_H;
}

void update_ship_normal_phase ()
{
  if (ship.lives > 0)
  {
    if (key[ALLEGRO_KEY_D] || key[ALLEGRO_KEY_RIGHT]) 
    {
      ship.x += SHIP_SPEED;
    }
    if (key[ALLEGRO_KEY_A] || key[ALLEGRO_KEY_LEFT])
    {
      ship.x -= SHIP_SPEED;
    }

    if (ship.x < 0) ship.x = 0;
    if (ship.x > SHIP_MAX_X) ship.x = SHIP_MAX_X;

    ship.hitbox.x1 = ship.x;
    ship.hitbox.x2 = ship.x + SHIP_W;
  }
}

void update_ship_boss_phase ()
{
  if (ship.lives > 0)
  {
    if (key[ALLEGRO_KEY_D] || key[ALLEGRO_KEY_RIGHT]) 
    {
      ship.x += SHIP_SPEED;
    }
    if (key[ALLEGRO_KEY_A] || key[ALLEGRO_KEY_LEFT])
    {
      ship.x -= SHIP_SPEED;
    }
    if (key[ALLEGRO_KEY_W] || key[ALLEGRO_KEY_UP])
    {
      ship.y -= SHIP_SPEED;
    }
    if (key[ALLEGRO_KEY_S] || key[ALLEGRO_KEY_DOWN])
    {
      ship.y += SHIP_SPEED;
    }

    if (ship.x < 0) ship.x = 0;
    if (ship.x > SHIP_MAX_X) ship.x = SHIP_MAX_X;
    if (ship.y < 0) ship.y = 0;
    if (ship.y > SHIP_MAX_Y) ship.y = SHIP_MAX_Y;

    ship.hitbox.x1 = ship.x;
    ship.hitbox.x2 = ship.x + SHIP_W;
    ship.hitbox.y1 = ship.y;
    ship.hitbox.y2 = ship.y + SHIP_H;
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

void update_ship_frames()
{
  ship_frames ++;
  if (ship_frames >= 90)
  {
    ship.invulnerable = false;
    ship.hitted = false;
    ship_frames = 0;
  }
}

void draw_ship ()
{
  if (ship.lives > 0)
  {
    if (ship.hitted)
    {
      if (ship_frames*4 / FPS == 0 || ship_frames*4 / FPS == 2 || ship_frames*4 / FPS == 4)
      {
        //nao desenha por meio segundo
      }
      else {
        al_draw_bitmap(sprites.ship, ship.x, ship.y, 0);
      }
    }
    else
    {
      al_draw_bitmap(sprites.ship, ship.x, ship.y, 0);
    }
  }
  for (int i = 0; i < ship.lives; i ++)
  {
    al_draw_bitmap(sprites.ship_life, 5 + (i * 10), 15, 0);
  }
}
