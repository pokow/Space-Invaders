#include "sprites.h"
#include <allegro5/allegro_image.h>

SPRITES sprites;

static ALLEGRO_BITMAP* sprite_grab(int x, int y, int w, int h)
{
  ALLEGRO_BITMAP* sub = al_create_sub_bitmap(sprites._sheet, x, y, w, h);
  must_init(sub, "sub_bitmap sprites");
  return sub;
}

void init_sprites()
{
  sprites._sheet = al_load_bitmap("spritesheet.png");
  int failed_to_load_png = !sprites._sheet;
  if (failed_to_load_png)
  {
    sprites._sheet = al_load_bitmap("spritesheet.bmp");
  }
  must_init(sprites._sheet, "spritesheet");

  sprites.ship        = sprite_grab(0, 0, SHIP_W, SHIP_H);
  sprites.ship_shot   = sprite_grab(13, 0, SHIP_SHOT_W, SHIP_SHOT_H);
  sprites.ship_life   = sprite_grab(0, 14, SHIP_LIFE_W, SHIP_LIFE_H);
  sprites.alien       = sprite_grab(19, 0, ALIEN_W, ALIEN_H);
  sprites.alien_shot  = sprite_grab(13, 10, ALIEN_SHOT_W, ALIEN_SHOT_H);
  sprites.boss        = sprite_grab(0, 21, BOSS_W, BOSS_H);
  sprites.boss_shot   = sprite_grab(19, 10, BOSS_SHOT_W, BOSS_SHOT_H);
}

void destroy_sprites()
{
  al_destroy_bitmap(sprites._sheet);
  al_destroy_bitmap(sprites.ship);
  al_destroy_bitmap(sprites.ship_shot);
  al_destroy_bitmap(sprites.ship_life);
  al_destroy_bitmap(sprites.alien);
  al_destroy_bitmap(sprites.alien_shot);
  al_destroy_bitmap(sprites.boss);
  al_destroy_bitmap(sprites.boss_shot);
}
