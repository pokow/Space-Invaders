#ifndef GENERAL_HEADER
#define GENERAL_HEADER

#include <allegro5/allegro.h>

#define KEY_SEEN 1
#define KEY_DOWN 2

typedef struct
{
  int x1, y1;
  int x2, y2;
} HITBOX;

extern unsigned char key[ALLEGRO_KEY_MAX];

void key_init ();
void must_init(bool test, const char *description);

#endif
