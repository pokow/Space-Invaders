#include "general.h"

float FPS_aliens = INITIAL_FPS_aliens;
ALLEGRO_TIMER* timer;
ALLEGRO_TIMER* alien_timer;
ALLEGRO_EVENT_QUEUE* queue;
FONT font;
int current_score = 0;
int high_score;

unsigned char key[ALLEGRO_KEY_MAX];

void must_init(bool test, const char *description)
{
  if(test) return;

  printf("couldn't initialize %s\n", description);
  exit(1);
}

void init_score()
{
  current_score = 0;
  FILE* score;
  score = fopen ("score.txt", "r");
  must_init(score, "score.txt");
  fscanf(score, "%*s %*d %*s %d", &high_score);
  fclose(score);
  score = fopen("score.txt", "w");
  must_init(score, "score.txt");
  fprintf(score, "CURRENT_SCORE: %d HIGH_SCORE: %d",current_score, high_score);
  fclose(score);
}

void update_score()
{
  current_score ++;

  if (current_score > high_score)
  {
    high_score = current_score;
  }

  FILE* score = fopen("score.txt", "w");
  must_init(score, "score.txt");
  fprintf(score, "CURRENT_SCORE: %d HIGH_SCORE: %d", current_score, high_score);
  fclose(score);
}

void timers_init ()
{
  srand(time(NULL));
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
  font.in_game_score = al_create_builtin_font();
  must_init(font.in_game_score, "font");
  font.menu1 = al_create_builtin_font();
  must_init(font.menu1, "font");
  font.menu2 = al_create_builtin_font();
  must_init(font.menu2, "font");
  font.lose1 = al_create_builtin_font();
  must_init(font.lose1, "font");
  font.lose2 = al_create_builtin_font();
  must_init(font.lose2, "font");
}

void primitives_init()
{
  must_init(al_init_primitives_addon(), "primitives");
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
    current_score = 0;
    *done = true;
  }
}

int rand_int(int min, int max)
{
  int aux = max - min + 1;
  return (rand() % aux) + min;
}

