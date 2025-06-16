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
  sprites._sheet = al_load_bitmap("spritesheetnew.png");
  int failed_to_load_png = !sprites._sheet;
  if (failed_to_load_png)
  {
    sprites._sheet = al_load_bitmap("spritesheet.bmp");
  }
  must_init(sprites._sheet, "spritesheet");

  sprites.ship        = sprite_grab(0, 29, SHIP_W, SHIP_H);
  sprites.ship_shot   = sprite_grab(0, 43, SHIP_SHOT_W, SHIP_SHOT_H);
  sprites.ship_life   = sprite_grab(49, 0, SHIP_LIFE_W, SHIP_LIFE_H);
  for (int i = 0; i < 3; i ++)
  {
    sprites.alien[i] = sprite_grab(i * ALIEN_W, 0, ALIEN_W, ALIEN_H);
    sprites.alien_frog[i] = sprite_grab(i * ALIEN_FROG_W, 13, ALIEN_FROG_W, ALIEN_FROG_H);
  }
  sprites.alien_shot  = sprite_grab(3, 43, ALIEN_SHOT_W, ALIEN_SHOT_H);
  sprites.explosion   = sprite_grab(19, 29, EXPLOSION_W, EXPLOSION_W);
  sprites.boss        = sprite_grab(19, 37, BOSS_W, BOSS_H);
  sprites.boss_shot   = sprite_grab(49, 19, BOSS_SHOT_W, BOSS_SHOT_H);
}

void destroy_sprites()
{
  al_destroy_bitmap(sprites._sheet);
  al_destroy_bitmap(sprites.ship);
  al_destroy_bitmap(sprites.ship_shot);
  al_destroy_bitmap(sprites.ship_life);
  for (int i = 0; i < 3; i ++)
  {
    al_destroy_bitmap(sprites.alien[i]);
    al_destroy_bitmap(sprites.alien_frog[i]);
  }
  al_destroy_bitmap(sprites.alien_shot);
  al_destroy_bitmap(sprites.boss);
  al_destroy_bitmap(sprites.boss_shot);
}
