#include "alien_shot.h"

ALIEN_SHOT *alien_shot;

void alien_shot_init()
{
  if (alien_shot) free(alien_shot); 

  alien_shot = malloc(ALIEN_COL * sizeof(ALIEN_SHOT));

  if (!alien_shot) {
    fprintf(stderr, "Erro ao alocar alien_shot!\n");
    exit(1);
  }

  for (int i = 0; i < ALIEN_COL; i ++)
  {
    alien_shot[i].reloaded = 1;
    alien_shot[i].exists = 0;
    alien_shot[i].col = i;
  }
}

void free_alien_shots()
{
  free(alien_shot);
}

void alien_shoots(ALIEN* alien)
{
  int index = alien->col;
  if (alien_shot[index].reloaded)
  {
    float alien_shot_x = alien->x + (ALIEN_W / 2.0) - (ALIEN_SHOT_W / 2.0);
    float alien_shot_y = alien->y + ALIEN_H;
    alien_shot[index].x = alien_shot_x;
    alien_shot[index].y = alien_shot_y;
    alien_shot[index].hitbox.x1 = alien_shot_x;
    alien_shot[index].hitbox.y1 = alien_shot_y;
    alien_shot[index].hitbox.x2 = alien_shot_x + ALIEN_SHOT_W;
    alien_shot[index].hitbox.y2 = alien_shot_y + ALIEN_SHOT_H;
    alien_shot[index].exists = 1;
    alien_shot[index].reloaded = 0;
  }
}

void aliens_shooting(ALIEN** alien)
{
  for (int i = 0; i < ALIEN_ROW; i++)
  {
    for (int j = 0; j < ALIEN_COL; j++)
    {
      if (alien[i][j].shoot)
      {
        alien_shoots(&alien[i][j]);
        alien[i][j].shoot = 0;
      }
    }
  }
}

void update_alien_shots()
{
  if (!alien_shot) return;
  for (int i = 0; i < ALIEN_COL; i ++)
  {
    if (alien_shot[i].exists)
    {
      alien_shot[i].y += ALIEN_SHOT_SPEED;
      alien_shot[i].hitbox.y1 += ALIEN_SHOT_SPEED;
      alien_shot[i].hitbox.y2 += ALIEN_SHOT_SPEED;
    }
  }
}


void draw_alien_shots()
{
  for (int i = 0; i < ALIEN_COL; i ++)
  {
    if (alien_shot[i].exists)
    {
      int x = (int)alien_shot[i].x;
      int y = (int)alien_shot[i].y;
      al_draw_bitmap(sprites.alien_shot, x, y, 0);
      if (y > BUFFER_H)
      {
        alien_shot[i].exists = 0;
        alien_shot[i].reloaded = 1;
      }
    }
  }
}


