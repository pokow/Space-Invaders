#include "general.h"

float FPS_aliens = INITIAL_FPS_aliens;
ALLEGRO_TIMER* timer;
ALLEGRO_TIMER* alien_timer;
ALLEGRO_EVENT_QUEUE* queue;
ALLEGRO_FONT* font;

unsigned char key[ALLEGRO_KEY_MAX];

void must_init(bool test, const char *description)
{
  if(test) return;

  printf("couldn't initialize %s\n", description);
  exit(1);
}


void timers_init ()
{
  timer = al_create_timer(1.0 / FPS);
  must_init(timer, "timer");
  alien_timer = al_create_timer(1.0/FPS_aliens);
  must_init(alien_timer, "alien_timer");
}

void event_queue_init()
{
  queue = al_create_event_queue();
  must_init(queue, "event_queue");
}

void events_register()
{
  al_register_event_source(queue, al_get_keyboard_event_source());
  al_register_event_source(queue, al_get_display_event_source(al_get_current_display()));
  al_register_event_source(queue, al_get_timer_event_source(timer));
  al_register_event_source(queue, al_get_timer_event_source(alien_timer));
}

void font_init()
{
  font = al_create_builtin_font();
  must_init(font, "font");
}

void key_init ()
{
  memset(key, 0, sizeof(key));
}

void key_update(ALLEGRO_EVENT *ev)
{
  if (ev->type == ALLEGRO_EVENT_KEY_DOWN)
    key[ev->keyboard.keycode] = KEY_SEEN | KEY_DOWN;

  if (ev->type == ALLEGRO_EVENT_KEY_UP)
    key[ev->keyboard.keycode] &= ~KEY_DOWN;
}

void key_reset()
{
  for (int i = 0; i < ALLEGRO_KEY_MAX; i++)
  {
    key[i] &= ~KEY_SEEN;
  }
}

void esc_to_quit(bool* done)
{
  if (key[ALLEGRO_KEY_ESCAPE])
  {
    *done = true;
  }
}



