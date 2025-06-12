#ifndef GENERAL_HEADER
#define GENERAL_HEADER

#include <allegro5/allegro.h>

#define KEY_SEEN 1
#define KEY_DOWN 2

extern unsigned char key[ALLEGRO_KEY_MAX];

void key_init ();

#endif
