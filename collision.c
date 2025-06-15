#include "collision.h" 

bool collision (HITBOX hitbox1, HITBOX hitbox2)
{
  if (hitbox1.x2 < hitbox2.x1) return false;
  if (hitbox1.x1 > hitbox2.x2) return false;
  if (hitbox1.y2 < hitbox2.y1) return false;
  if (hitbox1.y1 > hitbox2.y2) return false;
  return true;
}
void ship_shot_collision(SHIP_SHOT *shot, ALIEN aliens[ALIEN_ROW][ALIEN_COL])
{
  if (!shot->exists)
    return;

  for (int i = 0; i < ALIEN_ROW; i++)
  {
    for (int j = 0; j < ALIEN_COL; j++)
    {
      if (aliens[i][j].alive && collision(shot->hitbox, aliens[i][j].hitbox))
      {
        aliens[i][j].alive = 0;
        shot->exists = 0;
        shot->reloaded = 1;
        return;
      }
    }
  }
}

