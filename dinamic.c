#include "dinamic.h"

int phase = 1;
bool normal_phase = true;
bool boss_phase = false;

void reset_all()
{
  free_aliens();
  free_alien_shots();
  aliens = NULL;
  alien_shot = NULL;
}

void start_game()
{
  init_ship();
  ship_shot_init();
  if (normal_phase)
  {
    FPS_aliens = INITIAL_FPS_aliens;
    al_set_timer_speed(alien_timer, 1.0/FPS_aliens);
    init_aliens();
    alien_shot_init();
  }
  else if (boss_phase)
  {
    init_boss();
  }
}

void update_game_state(bool* pre_game, bool* in_game, bool* pos_game, bool* game_over)
{
  if (*pre_game && key[ALLEGRO_KEY_ENTER])
  {
    *pre_game = false;
    *in_game = true;
    start_game();
  }
  else if (*in_game && *game_over)
  {
    *in_game = false;
    *pos_game = true;
  }
  else if (*pos_game && key[ALLEGRO_KEY_TAB])
  {
    *pre_game = true;
    *pos_game = false;
    reset_difficulty();
  }
  else if (*pos_game && key[ALLEGRO_KEY_ENTER])
  {
    *in_game = true;
    *pos_game = false;
    *game_over = false;
    reset_difficulty();
    start_game();
  }
}

void increase_difficulty()
{
  reset_all();
  int hardness_increase = rand() % 3 + 1;

  if (hardness_increase == 1 && ALIEN_ROW <= 8)
  {
    ALIEN_ROW ++;
  }
  else if (hardness_increase == 2 && ALIEN_COL <= 6)
  {
    ALIEN_COL ++;

  }
  else
  {
    ALIEN_SPEED += 1;
    INCREASE_ALIEN_SPEED += 0.2;
    if (SHOOT_CHANCE > 0)
    {
      SHOOT_CHANCE --; //--> quanto menor, maior a chance
    }
  }
  start_game();
}

void reset_difficulty()
{
  phase = 1;
  FPS_aliens = INITIAL_FPS_aliens;
  al_set_timer_speed(alien_timer, 1.0/FPS_aliens);
  ALIEN_SPEED = INITIAL_ALIEN_SPEED;
  ALIEN_ROW = INITIAL_ALIEN_ROW;
  ALIEN_COL = INITIAL_ALIEN_COL;
  INCREASE_ALIEN_SPEED = INITIAL_INCREASE_ALIEN_SPEED;
  SHOOT_CHANCE = INITIAL_SHOOT_CHANCE;
}

void update_phase()
{
  define_type_of_phase();
  if (normal_phase)
  {
    for (int i = 0; i < ALIEN_ROW; i ++)
    {
      for(int j = 0; j < ALIEN_COL; j ++)
      {
        if (aliens[i][j].alive)
        {
          return;
        }
      }
    }
    phase ++;
    define_type_of_phase();
    increase_difficulty();
  }
}

void define_type_of_phase()
{
  if (phase % 5)
  {
    normal_phase = true;
    boss_phase = false;
  }
  else {
    normal_phase = false;
    boss_phase = true;
  }
}
