//Para salvar no github:

//git add.   ---> adiciona todos os arquivos alterados.
//git commit -m "Descreva aqui o que voce mudou" 
//git push   ---> envia as mudancas para o github
//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

#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>

#include "alien.h"
#include "ship_shot.h"
#include "general.h"
#include "display.h"
#include "sprites.h"
#include "ship.h"
#include "collision.h"
#include "alien_shot.h"
#include "dinamic.h"
#include "boss.h"

int main()
{
  // Inicializações básicas
  must_init(al_init(), "allegro");
  must_init(al_install_keyboard(), "keyboard");
  must_init(al_init_image_addon(), "image_addon()");

  display_init();
  timers_init();
  event_queue_init();
  font_init();
  primitives_init();
  events_register();

  init_sprites();
  key_init();
  init_ship();
  ship_shot_init();
  init_score();

  bool done = false;
  bool pre_game = true;
  bool in_game = false;
  bool pos_game = false;
  bool game_over = false;
  bool redraw = true;

  reset_difficulty();  

  al_start_timer(timer);
  al_start_timer(alien_timer);

  while (1)
  {
    ALLEGRO_EVENT ev;
    al_wait_for_event(queue, &ev);
    
    switch (ev.type)
    {
      case ALLEGRO_EVENT_TIMER:
        if (ev.timer.source == timer)
        {
          update_game_state(&pre_game, &in_game, &pos_game, &game_over);
          update_phase();
          update_boss_attack_frames();
          update_ship_frames();
          define_type_of_phase();
          shoot();
          update_ship_shot();
          verify_game_over(&game_over);
          if (normal_phase)
          {
            update_ship_normal_phase();
            update_alien_shots();
            alienshot_collided_to_ship();
            ship_collided_to_alien();
            alien_collided_to_ground();
            shipshot_collided_to_alien();
          }
          else if (boss_phase)
          {
            update_ship_boss_phase();
            update_boss();
            shipshot_collided_to_boss();
            ship_collided_to_boss_attack(); 
          }
        }
        if (ev.timer.source == alien_timer)
        {
          if (in_game)
          {
            if (normal_phase)
            {
              update_aliens();
              define_shooter();
              aliens_shooting(aliens);
            }
          }
        }
        key_reset();
        redraw = true;
        esc_to_quit(&done);
        break;
      case ALLEGRO_EVENT_KEY_DOWN:
      case ALLEGRO_EVENT_KEY_UP:
        key_update(&ev);
      break;

      case ALLEGRO_EVENT_DISPLAY_CLOSE:
        current_score = 0;
        done = true;
        break;
    }

    if (done) break;

    // Desenho
    else if (redraw && al_is_event_queue_empty(queue)) {
      if (pre_game == true)
      {
        draw_pre_game();
      }
      else if (in_game == true)
      { 
        pre_draw_disp();
        draw_ship(); 
        draw_ship_shot();
        if (normal_phase)
        {
          draw_aliens();
          draw_alien_shots();
        }
        else if (boss_phase)
        {
          draw_boss();
          boss_attack();
        }
        al_draw_textf(font.in_game_score, al_map_rgb_f(1, 1, 1), 5, 5, 0, "%06d", current_score);
        pos_draw_disp();
      }
      else if (pos_game == true)
      {
        draw_pos_game();
      }
      redraw = false;
    }
  }

  // Libera recursos
  destroy_sprites();
  destroy_disp_buff();
  al_destroy_timer(timer);
  al_destroy_event_queue(queue);

  return 0;
}
