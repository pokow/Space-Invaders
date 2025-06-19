#include "collision.h" 

bool collision (HITBOX hitbox1, HITBOX hitbox2)
{
  if (hitbox1.x2 < hitbox2.x1) return false;
  if (hitbox1.x1 > hitbox2.x2) return false;
  if (hitbox1.y2 < hitbox2.y1) return false;
  if (hitbox1.y1 > hitbox2.y2) return false;
  return true;
}

bool shipshot_collided_to_alien()
{
  if (!ship_shot.exists)
    return false;

  for (int i = 0; i < ALIEN_ROW; i++)
  {
    for (int j = 0; j < ALIEN_COL; j++)
    {
      if (aliens[i][j].alive && collision(ship_shot.hitbox, aliens[i][j].hitbox))
      {
        aliens[i][j].alive = 0;
        ship_shot.exists = 0;
        FPS_aliens += INCREASE_ALIEN_SPEED;
        al_set_timer_speed(alien_timer, 1.0/FPS_aliens);
        return true;
      }
    }
  }
  return false;
}

bool alienshot_collided_to_ship()
{
  for (int i = 0; i < ALIEN_COL; i ++)
  {
    if (alien_shot[i].exists && collision(ship.hitbox, alien_shot[i].hitbox))
    {
      alien_shot[i].exists = 0;
      ship.lives --;
      alien_shot[i].reloaded = 1;
      return true;
    }
  }
  return false;
}

bool ship_collided_to_alien()
{
  for (int i = 0; i < ALIEN_ROW; i ++)
  {
    for (int j = 0; j < ALIEN_COL; j ++)
    {
      HITBOX alien_plus = aliens[i][j].hitbox;
      alien_plus.y2 += 5;
      if (aliens[i][j].alive && ship.lives > 0 && collision(alien_plus, ship.hitbox))
      {
        ship.lives = 0;
        return true;
      }
    }
  }
  return false;
}

bool alien_collided_to_ground()
{
  for (int i = 0;i < ALIEN_ROW; i ++)
  {
    for (int j = 0; j < ALIEN_COL; j ++)
    {
      if (aliens[i][j].alive &&  aliens[i][j].y + ALIEN_H >= BUFFER_H)
      {
        ship.lives = 0;
        return true;
      }
    }
  }
  return false;
}
