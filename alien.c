#include "alien.h"

ALIEN aliens[ALIEN_ROW][ALIEN_COL];

void init_aliens()
{
  for (int i = 0; i < ALIEN_ROW; i ++)
  {
    for (int j = 0; j < ALIEN_COL; j ++)
    {
      int alien_x = FIRST_ALIEN_X + ALIEN_DISTANCE * j;
      int alien_y = FIRST_ALIEN_Y + ALIEN_W * i;
      aliens[i][j].x = alien_x;
      aliens[i][j].y = alien_y;
      aliens[i][j].alive = 1;
      aliens[i][j].dir = 1;
      aliens[i][j].hitbox.x1 = alien_x;
      aliens[i][j].hitbox.y1 = alien_y;
      aliens[i][j].hitbox.x2 = alien_x + ALIEN_W;
      aliens[i][j].hitbox.y2 = alien_y + ALIEN_H;
    }
  }
}

ALIEN find_last()
{
  ALIEN *last = NULL;
  for (int i = 0; i < ALIEN_ROW; i++) 
  {
    for (int j = 0; j < ALIEN_COL; j++) 
    {
      if (!aliens[i][j].alive) 
      {
        continue;
      }
      int last_is_NULL = !last;
      if (last_is_NULL)
      {
        last = &aliens[i][j];
        continue;
      }
      int aln_to_right_further = aliens[i][j].dir == 1 && aliens[i][j].x > last -> x;
      int aln_to_left_further = aliens[i][j].dir == -1 && aliens[i][j].x < last -> x;
      if (last_is_NULL || aln_to_right_further || aln_to_left_further)
      {
        last = &aliens[i][j];
      }
    }
  }
  if (!last)
  {
    ALIEN dummy = {0};
    return dummy;
  }
  return *last;
}


void update_aliens()
{
  ALIEN last = find_last();
  int dir = last.dir;
  float dx = ALIEN_SPEED * dir;
  float next_x = last.x + dx;
  if (next_x < 0 || next_x > BUFFER_W - ALIEN_W)
  {
    for (int i = 0; i < ALIEN_ROW; i ++)
    {
      for (int j = 0; j < ALIEN_COL; j ++)
      {
        if (aliens[i][j].alive)
        {
          aliens[i][j].dir *= -1;
          aliens[i][j].y += ALIEN_H;
          aliens[i][j].hitbox.y1 += ALIEN_H;
          aliens[i][j].hitbox.y2 += ALIEN_H;
        }
      }
    }
  }
  else {
    for (int i = 0; i < ALIEN_ROW; i ++)
    {
      for (int j = 0; j < ALIEN_COL; j ++)
      {
        aliens[i][j].x += dx;
        aliens[i][j].hitbox.x1 += dx;
        aliens[i][j].hitbox.x2 += dx;
      }
    }
  }
}

void draw_aliens()
{
  for (int i = 0; i < ALIEN_ROW; i ++)
  {
    for (int j = 0; j < ALIEN_COL; j ++)
    {
      if (aliens[i][j].alive)
      {
        int alien_x = aliens[i][j].x;
        int alien_y = aliens[i][j].y;
        al_draw_bitmap(sprites.alien, alien_x, alien_y, 0);
      }
    }
  }
}
