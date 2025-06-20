#include "dinamic.h"

int phase = 0;
bool normal_phase = false;
bool boss_phase = false;

void reset_all()
{
  if (aliens)
  {
    free_aliens();
    aliens = NULL;
  }

  if (alien_shot)
  {
    free_alien_shots();
    alien_shot = NULL;
  }
}

void start_normal_phase()
{
  ship.lives = 3;
  FPS_aliens = INITIAL_FPS_aliens;
  al_set_timer_speed(alien_timer, 1.0/FPS_aliens);
  init_aliens();
  alien_shot_init();
}

void start_boss_phase()
{
  ship.lives = 5;
  init_boss();
  init_boss_attacks();
}

void update_game_state(bool* pre_game, bool* in_game, bool* pos_game, bool* game_over)
{
  if (*pre_game && key[ALLEGRO_KEY_ENTER])
  {
    *pre_game = false;
    *in_game = true;
    phase++;
    init_ship();
    init_score();
    start_normal_phase();
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
    phase++;
    init_ship();
    init_score();
    start_normal_phase();
  }
}

void increase_difficulty()
{
  reset_all();
  if (normal_phase)
  {
    int hardness_increase = rand() % 3 + 1;

    if (hardness_increase == 1 && ALIEN_ROW < 8)
    {
      ALIEN_ROW ++;
    }
    else if (hardness_increase == 2 && ALIEN_COL < 6)
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
    start_normal_phase();
  }
  else if (boss_phase)
  {
    start_boss_phase();
    BOSS_LIVES *= 2;
  }
}

void reset_difficulty()
{
  phase = 0;
  FPS_aliens = INITIAL_FPS_aliens;
  al_set_timer_speed(alien_timer, 1.0/FPS_aliens);
  ALIEN_SPEED = INITIAL_ALIEN_SPEED;
  ALIEN_ROW = INITIAL_ALIEN_ROW;
  ALIEN_COL = INITIAL_ALIEN_COL;
  INCREASE_ALIEN_SPEED = INITIAL_INCREASE_ALIEN_SPEED;
  SHOOT_CHANCE = INITIAL_SHOOT_CHANCE;
  BOSS_LIVES = INITIAL_BOSS_LIVES;
}

void update_phase()
{
  define_type_of_phase();

  if (normal_phase)
  {
    if (!aliens) return;
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
    return;
  }
  if (boss_phase)
  {
    if (boss.lives == 0)
    {
      phase ++;
      define_type_of_phase();
      increase_difficulty();
      init_ship();
      return;
    }
  }
}

void define_type_of_phase()
{
  if (phase > 0 && phase % 5 == 0)
  {
    normal_phase = false;
    boss_phase = true;
  }
  else
  {
    normal_phase = true;
    boss_phase = false;
  }
}
