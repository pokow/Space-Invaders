#include "collision.h" 

bool collision (HITBOX hitbox1, HITBOX hitbox2)
{
  if (hitbox1.x2 < hitbox2.x1) return false;
  if (hitbox1.x1 > hitbox2.x2) return false;
  if (hitbox1.y2 < hitbox2.y1) return false;
  if (hitbox1.y1 > hitbox2.y2) return false;
  return true;
}

void shipshot_collided_to_alien()
{
  for (int k = 0; k < MAX_BULLETS; k ++)
  {
    if (!ship_shot[k].exists)
      continue;

    for (int i = 0; i < ALIEN_ROW; i++)
    {
      for (int j = 0; j < ALIEN_COL; j++)
      {
        if (aliens[i][j].alive && collision(ship_shot[k].hitbox, aliens[i][j].hitbox))
        {
          aliens[i][j].alive = 0;
          ship_shot[k].exists = false;
          ship_shot[k].reloaded = true;
          FPS_aliens += INCREASE_ALIEN_SPEED;
          al_set_timer_speed(alien_timer, 1.0/FPS_aliens);
          al_play_sample(music.hit, 0.03, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);   
          update_score(1);
          return;
        }
      }
    }
  }
}

void alienshot_collided_to_ship()
{
  if (!alien_shot) return;
  for (int i = 0; i < ALIEN_COL; i ++)
  {
    if (alien_shot[i].exists && !ship.invulnerable && collision(ship.hitbox, alien_shot[i].hitbox))
    {
      alien_shot[i].exists = 0;
      alien_shot[i].reloaded = 1;
      ship.lives --;
      ship.hitted = true;
      ship.invulnerable = true;
      ship_frames = 0;
      al_play_sample(music.hit, 0.03, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);   
      return;
    }
  }
}

void ship_collided_to_alien()
{
  if (!aliens) return;
  for (int i = 0; i < ALIEN_ROW; i ++)
  {
    for (int j = 0; j < ALIEN_COL; j ++)
    {
      HITBOX alien_plus = aliens[i][j].hitbox;
      alien_plus.y2 += 5;
      if (aliens[i][j].alive && ship.lives > 0 && collision(alien_plus, ship.hitbox))
      {
        ship.lives = 0;
        al_play_sample(music.hit, 0.03, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);   
        return;
      }
    }
  }
}

void alien_collided_to_ground()
{
  if (!aliens) return;
  for (int i = 0;i < ALIEN_ROW; i ++)
  {
    for (int j = 0; j < ALIEN_COL; j ++)
    {
      if (aliens[i][j].alive &&  aliens[i][j].y + ALIEN_H >= BUFFER_H)
      {
        ship.lives = 0;
        al_play_sample(music.hit, 0.03, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);   
        return;
      }
    }
  }
}

void shipshot_collided_to_boss()
{
  for (int i = 0; i < MAX_BULLETS; i ++)
  {
    if (!ship_shot[i].exists)
      continue;
    if (boss.lives > 0 && collision(boss.hitbox, ship_shot[i].hitbox))
    {
      boss.lives --;
      ship_shot[i].exists = false;
      ship_shot[i].reloaded = true;
      al_play_sample(music.hit, 0.03, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);   
      return;
    }
  }
}

void ship_collided_to_boss_attack()
{
  if (!ship.invulnerable && (collision(attack_1.hitbox, ship.hitbox) || collision(attack_2.hitbox, ship.hitbox)))
  {
    ship.lives --;
    ship.hitted = true;
    ship.invulnerable = true;
    ship_frames = 0;
    al_play_sample(music.hit, 0.03, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);   
  }
}

void ship_collided_to_boss()
{
  if(!ship.invulnerable && (collision(ship.hitbox, boss.hitbox)))
  {
    ship.lives --;
    ship.hitted = true;
    ship.invulnerable = true;
    ship_frames = 0;
    al_play_sample(music.hit, 0.03, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);   
  }
}

void bossshot_collided_to_ship()
{
  if (!ship.invulnerable)
  {
    for (int i = 0; i < BOSS_SHOTS; i ++)
    {
      if (boss_shot[i].exists && collision(boss_shot[i].hitbox, ship.hitbox))
      {
        ship.lives --;
        ship.hitted = true;
        boss_shot[i].exists = false;
        boss_shot[i].reloaded = true;
        ship.invulnerable = true;
        ship_frames = 0;
        al_play_sample(music.hit, 0.03, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);   
        return;
      }
    }
  }
}
