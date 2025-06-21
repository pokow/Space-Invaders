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
  ship.lives = SHIP_LIVES;
  FPS_aliens = INITIAL_FPS_aliens;
  al_set_timer_speed(alien_timer, 1.0/FPS_aliens);
  init_aliens();
  alien_shot_init();
}

void start_boss_phase()
{
  ship.lives = SHIP_LIVES + 2;
  init_boss();
  init_boss_attacks();
  init_boss_shots();
  switch_music(music.boss_phase);
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
    switch_music(music.normal_phase);
  }
  else if (*in_game && *game_over)
  {
    *in_game = false;
    *pos_game = true;
    switch_music(music.game_over);

  }
  else if (*pos_game && key[ALLEGRO_KEY_TAB])
  {
    *pre_game = true;
    *pos_game = false;
    reset_difficulty();
    switch_music(music.menu);
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
    switch_music(music.normal_phase);
  }
}

void increase_difficulty()
{
  reset_all();
  if (normal_phase)
  {
    int hardness_increase = rand_int(1, 3) ;

    if (hardness_increase == 1 && ALIEN_ROW <= 6)
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
    start_normal_phase();
  }
  else if (boss_phase)
  {
    start_boss_phase();
    BOSS_LIVES *= 2;
    BOSS_SHOOT_COULDOWN -= 0.1;
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
  SHIP_LIVES = INITIAL_SHIP_LIVES;
  SHIP_SPEED = INITIAL_SHIP_SPEED;
  COULDOWN = INITIAL_COULDOWN;
  BOSS_SHOOT_COULDOWN = INITIAL_BOSS_SHOOT_COULDOWN;
  BOSS_ATTACK_COULDOWN = INITIAL_BOSS_ATTACK_COULDOWN;
  restart_all_music_streams();
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
      update_score(50);
      phase ++;
      define_type_of_phase();
      increase_difficulty();
      COULDOWN -= 0.1;
      SHIP_SPEED += 0.075;
      SHIP_LIVES ++;
      init_ship();
      switch_music(music.normal_phase);
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

void update_all_frames()
{
  update_ship_shot_frames();
  update_boss_attack_frames();
  update_boss_shot_frames();
  update_ship_frames();
}
