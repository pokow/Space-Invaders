#include <stdio.h>
#include <allegro5/allegro.h>
#include "general.h"

unsigned char key[ALLEGRO_KEY_MAX];

void key_init ()
{
  memset(key, 0, sizeof(key));
}

void must_init(bool test, const char *description)
{
  if(test) return;

  printf("couldn't initialize %s\n", description);
  exit(1);
}

