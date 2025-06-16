#include "alien.h"

ALIEN aliens[ALIEN_ROW][ALIEN_COL];

int alien_frame = 0;

void init_aliens()
{
  srand(time(NULL));
  for (int i = 0; i < ALIEN_ROW; i ++)
  {
    for (int j = 0; j < ALIEN_COL; j ++)
    {
      if ( (i + j) % 2 == 0 )
      {
        //alien normal
        aliens[i][j].type = 1;
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
        aliens[i][j].frame = 0;
        aliens[i][j].below = 0;
        aliens[i][j].col = j;
      }
      else {
        //alien frog
        aliens[i][j].type = 2;
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
        aliens[i][j].frame = 0;
        aliens[i][j].below = 0;
        aliens[i][j].col = j;
      }
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

void define_below()
{
  for (int i = 0; i < ALIEN_ROW; i ++)
  {
    for (int j = 0; j < ALIEN_COL; j ++)
    {
      aliens[i][j].below = 0;
    }
  }
  for (int j = 0; j < ALIEN_COL; j ++)
  {
    ALIEN below = aliens[0][j];
    int b_i = 0;
    int b_j = j;
    for (int i = 0; i < ALIEN_ROW; i ++)
    {
      if (aliens[i][j].y >= below.y && aliens[i][j].alive)
      {
        below = aliens[i][j];
        b_i = i;
        b_j = j;
      }
    }
    if (aliens[b_i][b_j].alive)
    {
      aliens[b_i][b_j].below = 1;
    }
  }
}

void update_aliens()
{
  alien_frame = (alien_frame + 1) % 3;
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
        aliens[i][j].frame = alien_frame;
        aliens[i][j].x += dx;
        aliens[i][j].hitbox.x1 += dx;
        aliens[i][j].hitbox.x2 += dx;
      }
    }
  }
  define_below();
}

void define_shooter()
{
  int shoot_chance = rand() % 3;
  ALIEN* candidates[ALIEN_COL];
  int counter = 0;
  for (int i = 0; i < ALIEN_ROW; i ++)
  {
    for (int j = 0; j < ALIEN_COL; j ++)
    {
      if (aliens[i][j].below)
      {
        candidates[counter] = &aliens[i][j];
        counter++;
      }
    }
  }
  if (counter > 0)
  {
    int chosen = rand() % counter;
    if (!shoot_chance)
    {
      candidates[chosen]->shoot = 1;
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
        if (aliens[i][j].type == 1)
        {
          al_draw_bitmap(sprites.alien[alien_frame], alien_x, alien_y, 0);
        }
        else {
          al_draw_bitmap(sprites.alien_frog[alien_frame], alien_x, alien_y, 0);
        }
      }
    }
  }
}
