#include "general.h"

float FPS_aliens = INITIAL_FPS_aliens;
ALLEGRO_TIMER* timer;
ALLEGRO_TIMER* alien_timer;
ALLEGRO_EVENT_QUEUE* queue;
FONT font;
MUSIC music;
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

void update_score(int add_to_score)
{
  current_score += add_to_score;

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

void music_init()
{
  music.current = NULL;
  music.menu = al_load_audio_stream("Sounds/Menu.ogg", 2, 2048);
  must_init(music.menu, "Menu_music");
  music.normal_phase = al_load_audio_stream("Sounds/Normal_phase.ogg", 2, 2048);
  must_init(music.normal_phase, "Normal_phase_music");
  music.game_over = al_load_audio_stream("Sounds/Game_over.ogg", 2, 2048);
  must_init(music.game_over, "Game_over_sound");
  music.boss_phase = al_load_audio_stream("Sounds/Boss_phase.ogg", 2, 2048);
  must_init(music.boss_phase, "Boss_phase_sound");
  music.shot = al_load_sample("Sounds/Audio_shot.flac");
  must_init(music.shot, "Shot_sound");
  music.hit = al_load_sample("Sounds/Hit.flac");
  must_init(music.hit, "Hit_sound");
  music.boss_attack = al_load_sample("Sounds/Boss_attack.flac");
  must_init(music.boss_attack, "Boss_attack_sound");
}

void restart_all_music_streams()
{
  al_seek_audio_stream_secs(music.menu, 0.0);
  al_seek_audio_stream_secs(music.normal_phase, 0.0);
  al_seek_audio_stream_secs(music.game_over, 0.0);
  al_seek_audio_stream_secs(music.boss_phase, 0.0);
}

void music_destroy()
{
  al_detach_audio_stream(music.current);
  al_destroy_audio_stream(music.menu);
  al_destroy_audio_stream(music.normal_phase);
  al_destroy_audio_stream(music.boss_phase);
  al_destroy_audio_stream(music.game_over);
  al_destroy_sample(music.shot);
  al_destroy_sample(music.hit);
  al_destroy_sample(music.boss_attack);
}

void allegro_inits()
{
  must_init(al_init(), "allegro");
  must_init(al_install_keyboard(), "keyboard");
  must_init(al_init_image_addon(), "image_addon()");
  must_init(al_install_audio(), "audio");
  must_init(al_init_acodec_addon(), "audio codecs");
  must_init(al_reserve_samples(16), "reserve samples");
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
    init_score();
    *done = true;
  }
}

int rand_int(int min, int max)
{
  int aux = max - min + 1;
  return (rand() % aux) + min;
}

void switch_music(ALLEGRO_AUDIO_STREAM* new_music)
{
  if (music.current && al_get_audio_stream_attached(music.current)) 
  {
      al_detach_audio_stream(music.current);
  }
  music.current = new_music;
  if (music.current) 
  {
    al_set_audio_stream_playmode(music.current, ALLEGRO_PLAYMODE_LOOP);
    al_attach_audio_stream_to_mixer(music.current, al_get_default_mixer());
    al_set_audio_stream_gain(music.current, 0.2);
  }
}

