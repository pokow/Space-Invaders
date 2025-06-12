#include "sprites.h"
#include <allegro5/allegro_image.h>

SPRITES sprites;

ALLEGRO_BITMAP* sprite_grab(int x, int y, int w, int h)
{
  ALLEGRO_BITMAP* sprite = al_create_sub_bitmap(sprites._sheet, x, y, w, h);
  return sprite;
}

void init_sprites ()
{
  sprites._sheet = al_load_bitmap("spritesheet.bmp");
  sprites.ship = sprite_grab(0, 0, 12, 13);
  sprites.ship_shot = sprite_grab(13, 0, 2, 9);
  sprites.ship_life = sprite_grab(0, 14, 6, 6);
  sprites.alien = sprite_grab(19, 0, 14, 9);
  sprites.alien_shot = sprite_grab(13, 10, 4, 4);
  sprites.boss = sprite_grab(0, 21, 45, 27);
  sprites.boss_shot = sprite_grab(19, 10, 13, 10);
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
