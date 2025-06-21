#ifndef GENERAL_HEADER
#define GENERAL_HEADER

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <time.h>
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

typedef struct
{
  ALLEGRO_FONT* in_game_score;
  ALLEGRO_FONT* menu1;
  ALLEGRO_FONT* menu2;
  ALLEGRO_FONT* lose1;
  ALLEGRO_FONT* lose2;
} FONT;

typedef struct
{
  ALLEGRO_AUDIO_STREAM* current;
  ALLEGRO_AUDIO_STREAM* menu;
  ALLEGRO_AUDIO_STREAM* normal_phase;
  ALLEGRO_AUDIO_STREAM* game_over;
  ALLEGRO_AUDIO_STREAM* boss_phase;
  ALLEGRO_SAMPLE* shot;
  ALLEGRO_SAMPLE* hit;
  ALLEGRO_SAMPLE* boss_attack;
} MUSIC;

extern unsigned char key[ALLEGRO_KEY_MAX];

void must_init(bool test, const char *description);
void init_score();
void update_score(int add_to_score);
void timers_init ();
void event_queue_init();
void events_register();
void font_init();
void music_init();
void restart_all_music_streams();
void music_destroy();
void allegro_inits();
void key_init ();
void key_update(ALLEGRO_EVENT *ev);
void key_reset();
void esc_to_quit(bool* done);
int rand_int(int min, int max);
void frames_and_seconds_count();
void switch_music(ALLEGRO_AUDIO_STREAM* new_music);

extern int high_score;
extern int current_score;
extern float FPS_aliens;
extern ALLEGRO_TIMER* timer;
extern ALLEGRO_TIMER* alien_timer;
extern ALLEGRO_EVENT_QUEUE* queue;
extern FONT font;
extern MUSIC music;

#endif
