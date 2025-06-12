#include <allegro5/allegro.h>
#include "general.h"

unsigned char key[ALLEGRO_KEY_MAX];

void key_init ()
{
    memset(key, 0, sizeof(key));
}
