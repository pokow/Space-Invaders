#ifndef GENERAL_HEADER
#define GENERAL_HEADER

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>

#define FPS 60
#define INITIAL_FPS_aliens 2

#define KEY_SEEN 1
#define KEY_DOWN 2

typedef struct
{
  int x1, y1;
  int x2, y2;
} HITBOX;

extern unsigned char key[ALLEGRO_KEY_MAX];

void must_init(bool test, const char *description);
void timers_init ();
void event_queue_init();
void events_register();
void font_init();
void key_init ();
void key_update(ALLEGRO_EVENT *ev);
void key_reset();
void esc_to_quit(bool* done);

extern float FPS_aliens;
extern ALLEGRO_TIMER* timer;
extern ALLEGRO_TIMER* alien_timer;
extern ALLEGRO_EVENT_QUEUE* queue;
extern ALLEGRO_FONT* font;

#endif
