#include "boss_attack.h"

void init_boss_attacks()
{
  attack_1.attack = false;
  attack_1.pre_attack_height = 2;
  attack_1.attack_height = 20;
  attack_2.attack = false;
  attack_2.pre_attack_width = 2;
  attack_2.attack_width = 20;
}

void update_boss_shot_frames()
{
  boss_shot_frames ++;
  if (boss_shot_frames >= FPS * BOSS_SHOOT_COULDOWN)
  {
    boss.can_shoot = true;
    boss_shot_frames = 0;
  }
}

void update_boss_shots()
{
  for (int i = 0; i < BOSS_SHOTS; i ++)
  {
    if (boss_shot[i].exists)
    {
      boss_shot[i].y += BOSS_SHOT_SPEED;

      boss_shot[i].hitbox.x1 = boss_shot[i].x;
      boss_shot[i].hitbox.y1 = boss_shot[i].y;
      boss_shot[i].hitbox.x2 = boss_shot[i].x + BOSS_SHOT_W;
      boss_shot[i].hitbox.y2 = boss_shot[i].y + BOSS_SHOT_H;

      if (boss_shot[i].y > BUFFER_H)
      {
        boss_shot[i].exists = false;
        boss_shot[i].reloaded = true;
      }
    }
  }
}

void draw_boss_shots()
{
  for (int i = 0; i < BOSS_SHOTS; i ++)
  {
    if (boss_shot[i].exists)
    {
      al_draw_bitmap(sprites.boss_shot, boss_shot[i].x, boss_shot[i].y, 0);
    }
  }
}

void update_boss_attack_frames()
{
  attack_frames ++;
  if (attack_frames >= FPS * BOSS_ATTACK_COULDOWN)
  {
    boss.can_attack = true;
    attack_frames = 0;
  }
}

void boss_attack()
{
  if (attack_1.attack)
  {
    if (attack_frames*2 / FPS <= 1)
    {
      int y1 = attack_1.y - attack_1.pre_attack_height / 2.0; 
      int y2 = attack_1.y + attack_1.pre_attack_height / 2.0;

      al_draw_filled_rectangle(0, y1,BUFFER_W, y2, al_map_rgb_f(1, 1, 1));
    }
    else if (attack_frames*2 / FPS == 3 || attack_frames*2 / FPS == 4)
    {
      int y1 = attack_1.y - attack_1.attack_height / 2.0;
      int y2 = attack_1.y + attack_1.attack_height / 2.0;

      al_draw_filled_rectangle(0, y1, BUFFER_W, y2, al_map_rgb_f(1, 1, 1));
      if (attack_frames == FPS * 3/2)
      {
        al_play_sample(music.boss_attack, 0.09, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);   
      }
      attack_1.hitbox.x1 = 0;
      attack_1.hitbox.y1 = y1;
      attack_1.hitbox.x2 = BUFFER_W;
      attack_1.hitbox.y2 = y2;
    }
    else if (attack_frames*2 / FPS >= 5)
    {
      attack_1.attack = false;
      attack_1.hitbox.x1 = 0;
      attack_1.hitbox.y1 = 0;
      attack_1.hitbox.x2 = 0;
      attack_1.hitbox.y2 = 0;
    }
  }
  if (attack_2.attack)
  {
    if (attack_frames*2 / FPS <= 1)
    {
      int x1 = attack_2.x - attack_2.pre_attack_width / 2.0; 
      int x2 = attack_2.x + attack_2.pre_attack_width / 2.0;

      al_draw_filled_rectangle(x1, 0,x2, BUFFER_H, al_map_rgb_f(1, 1, 1));
    }
    else if (attack_frames*2 / FPS == 3 || attack_frames*2 / FPS == 4)
    {
      int x1 = attack_2.x - attack_2.attack_width / 2.0;
      int x2 = attack_2.x + attack_2.attack_width / 2.0;

      al_draw_filled_rectangle(x1, 0, x2, BUFFER_H, al_map_rgb_f(1, 1, 1));
      if (attack_frames == FPS * 3/2)
      {
        al_play_sample(music.boss_attack, 0.09, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);   
      }
      attack_2.hitbox.x1 = x1;
      attack_2.hitbox.y1 = 0;
      attack_2.hitbox.x2 = x2;
      attack_2.hitbox.y2 = BUFFER_H;
    }
    else if (attack_frames*2 / FPS >= 5)
    {
      attack_2.attack = false;
      attack_2.hitbox.x1 = 0;
      attack_2.hitbox.y1 = 0;
      attack_2.hitbox.x2 = 0;
      attack_2.hitbox.y2 = 0;
    }
  }
}
