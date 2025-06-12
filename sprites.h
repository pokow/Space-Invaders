#include <allegro5/allegro5.h>

typedef struct
{
  ALLEGRO_BITMAP* _sheet;
  ALLEGRO_BITMAP* ship;
  ALLEGRO_BITMAP* ship_shot;
  ALLEGRO_BITMAP* ship_life;
  ALLEGRO_BITMAP* alien;
  ALLEGRO_BITMAP* alien_shot;
  ALLEGRO_BITMAP* boss;
  ALLEGRO_BITMAP* boss_shot;
} SPRITES;

ALLEGRO_BITMAP* sprite_grab(int x, int y, int w, int h);

void init_sprites ();

void destroy_sprites();
