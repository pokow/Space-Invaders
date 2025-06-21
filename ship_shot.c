#include "ship_shot.h"

SHIP_SHOT ship_shot[MAX_BULLETS];
float COULDOWN = INITIAL_COULDOWN;

int ship_shot_frames = 0;

void update_ship_shot_frames()
{
  ship_shot_frames ++;
  if (ship_shot_frames >= FPS * COULDOWN) // define couldown do tiro
  {
    ship.can_shoot = true;
    ship_shot_frames = 0;
  }
}

void ship_shot_init()
{
  for (int i = 0; i < MAX_BULLETS; i ++)
  {
    ship_shot[i].reloaded = 1;
    ship_shot[i].exists = 0;
  }
}

void ship_shoots()
{
  if (ship.can_shoot)
  {
    for (int i = 0; i < MAX_BULLETS; i ++)
    {
      if (ship_shot[i].reloaded && key[ALLEGRO_KEY_SPACE])
      {
        float ship_shot_x = ship.x + (SHIP_W / 2.0) - (SHIP_SHOT_W / 2.0);
        ship_shot[i].x = ship_shot_x;
        ship_shot[i].y = ship.y;
        ship_shot[i].hitbox.x1 = ship_shot_x;
        ship_shot[i].hitbox.y1 = ship.y;
        ship_shot[i].hitbox.x2 = ship_shot_x + SHIP_SHOT_W;
        ship_shot[i].hitbox.y2 = ship.y + SHIP_SHOT_H;
        ship_shot[i].exists = 1;
        ship_shot[i].reloaded = 0;
        ship_shot_frames = 0;
        ship.can_shoot = false;
        al_play_sample(music.shot, 0.2, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);   
        return; //--> impede de todos os tiros sairem de uma vez 
      }
    }
  }
}

void update_ship_shot()
{
  for (int i = 0; i < MAX_BULLETS; i ++)
  {
    if (ship_shot[i].exists)
    {
      ship_shot[i].y -= SHIP_SHOT_SPEED;
      ship_shot[i].hitbox.y1 -= SHIP_SHOT_SPEED;
      ship_shot[i].hitbox.y2 -= SHIP_SHOT_SPEED;

      if (ship_shot[i].y + SHIP_SHOT_H < 0)
      {
        ship_shot[i].exists = false;
        ship_shot[i].reloaded = true;
      }
    }
  }
}


void draw_ship_shot()
{
  for (int i = 0; i < MAX_BULLETS; i ++)
  {
    if (ship_shot[i].exists)
    {
      int x = ship_shot[i].x;
      int y = ship_shot[i].y;
      al_draw_bitmap(sprites.ship_shot, x, y, 0);
    }
  }
}

