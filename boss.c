#include "boss.h"

BOSS boss;
int BOSS_LIVES = INITIAL_BOSS_LIVES;

int boss_shot_frames = 0;

float BOSS_SHOOT_COULDOWN = INITIAL_BOSS_SHOOT_COULDOWN;

int attack_frames = 0;

float BOSS_ATTACK_COULDOWN = INITIAL_BOSS_ATTACK_COULDOWN;

BOSS_SHOT boss_shot[BOSS_SHOTS];

ATTACK_1 attack_1;

ATTACK_2 attack_2;

bool attack_3 = false;
HITBOX hitbox_attack_3;

void init_boss()
{
  boss.x = INITIAL_BOSS_X;
  boss.y = INITIAL_BOSS_Y;
  boss.dir = 1;
  boss.lives = BOSS_LIVES;
  boss.can_attack = false;
  boss.hitbox.x1 = INITIAL_BOSS_X;
  boss.hitbox.y1 = INITIAL_BOSS_Y;
  boss.hitbox.x2 = INITIAL_BOSS_X + BOSS_W;
  boss.hitbox.y2 = INITIAL_BOSS_Y + BOSS_H;
}

void init_boss_shots()
{
  for (int i = 0; i < BOSS_SHOTS; i ++)
  {
    boss_shot[i].reloaded = true;
    boss_shot[i].exists = false;
  }
}

void boss_shoots()
{
  if (boss.can_shoot)
  {
    for (int i = 0; i < BOSS_SHOTS; i ++)
    {
      if (boss_shot[i].reloaded)
      {
        float boss_shot_x = boss.x + (BOSS_W / 2.0) - (BOSS_SHOT_W / 2.0);
        float boss_shot_y = boss.y + BOSS_H;
        boss_shot[i].x = boss_shot_x;
        boss_shot[i].y = boss_shot_y;
        boss_shot[i].exists = true;
        boss_shot[i].reloaded = false;
        boss_shot[i].hitbox.x1 = boss.x;
        boss_shot[i].hitbox.y1 = boss.y;
        boss_shot[i].hitbox.x2 = boss.x + BOSS_SHOT_W;
        boss_shot[i].hitbox.y2 = boss.y + BOSS_SHOT_H;
        boss_shot_frames = 0;
        boss.can_shoot = false;
        al_play_sample(music.shot, 0.075, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);   
        return;
      }
    }
  }
}

void update_boss()
{
  if (boss.dir == 1)
  {
    int next_x = boss.x + BOSS_SPEED * boss.dir;
    if (next_x <= BUFFER_W - BOSS_W)
    {
      boss.x = next_x;
    }
    else if (next_x > BUFFER_W - BOSS_W)
    {
      boss.x = BUFFER_W - BOSS_W;
      boss.dir *= -1;
    }
  }
  else if (boss.dir == -1)
  {
    int next_x = boss.x + BOSS_SPEED * boss.dir;
    if (next_x >= 0)
    {
      boss.x = next_x;
    }
    else if (next_x < 0)
    {
      boss.x = 0;
      boss.dir *= -1;
    }
  }
  boss.hitbox.x1 = boss.x;
  boss.hitbox.x2 = boss.x + BOSS_W;
  boss.hitbox.y1 = boss.y;
  boss.hitbox.y2 = boss.y + BOSS_H;
  if (boss.can_attack) //--> a cada 3 seugndos 
  {
    int which_attack = rand_int(1, 3);
    if (which_attack == 1)
    {
      attack_1.attack = true;
      attack_1.y = rand_int(60, BUFFER_H - attack_1.attack_height);
      boss.can_attack = false;
    }
    else if (which_attack == 2)
    {
      attack_2.attack = true;
      attack_2.x = rand_int (0 + attack_2.attack_width/2, BUFFER_H - attack_2.attack_width/2);
      boss.can_attack = false;
    }
    else if (which_attack == 3)
    {
      attack_1.attack = true;
      attack_1.y = rand_int(70, BUFFER_H - attack_1.attack_height);
      attack_2.attack = true;
      attack_2.x = rand_int (0 + attack_2.attack_width/2, BUFFER_H - attack_2.attack_width/2);
      boss.can_attack = false;
    }
  }
}

void draw_boss()
{
  if (boss.lives > 0)
  {
    al_draw_bitmap(sprites.boss, boss.x, boss.y, 0);
  }
}

