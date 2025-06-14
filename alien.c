#include "alien.h"

ALIEN aliens[ALIEN_ROW][ALIEN_COL];

void init_aliens()
{
  for (int i = 0; i < ALIEN_ROW; i ++)
  {
    for (int j = 0; j < ALIEN_COL; j ++)
    {
      float alien_x = FIRST_ALIEN_X + ALIEN_DISTANCE * j;
      float alien_y = FIRST_ALIEN_Y + ALIEN_W * i;
      aliens[i][j].x = alien_x;
      aliens[i][j].y = alien_y;
      aliens[i][j].alive = 1;
      aliens[i][j].dir = 1;
    }
  }
}

ALIEN find_last ()
{
  ALIEN last;
  int dir, flag = 0;
  for (int i = 0; i < ALIEN_ROW && !flag; i ++)
  {
    for (int j = 0; j < ALIEN_COL && !flag; j ++)
    {
      if (aliens[i][j].alive)
      {
        last = aliens[i][j];
        dir = aliens[i][j].dir;
        flag ++;
      }
    }
  }
  if (dir == 1)
  {
    for (int i = 0; i < ALIEN_ROW; i ++)
    {
      for (int j = 0; j < ALIEN_COL; j ++)
      {
        if (aliens[i][j].alive && aliens[i][j].x >= last.x)
        {
          last = aliens[i][j];
        }
      }
    }
  }
  if (dir == -1)
  {
    for (int i = 0; i < ALIEN_ROW; i ++)
    {
      for (int j = 0; j < ALIEN_COL; j ++)
      {
        if (aliens[i][j].alive && aliens[i][j].x <= last.x)
        {
          last = aliens[i][j];
        }
      }
    }
  }
  return last;
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
