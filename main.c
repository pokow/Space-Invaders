//Para salvar no github:

//git add.   ---> adiciona todos os arquivos alterados.
//git commit -m "Descreva aqui o que voce mudou" 
//git push   ---> envia as mudancas para o github
//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

#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

#include "alien.h"
#include "ship_shot.h"
#include "general.h"
#include "display.h"
#include "sprites.h"
#include "ship.h"

int main()
{
  // Inicializações básicas
  must_init(al_init(), "allegro");

  must_init(al_install_keyboard(), "keyboard");
  al_init_image_addon();

  ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60);
  must_init(timer, "timer");
  ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
  must_init(queue, "event_queue");

  // Inicializa display, sprites, nave
  display_init();
  init_sprites();
  init_ship();
  ship_shot_init();
  init_aliens();

  al_register_event_source(queue, al_get_keyboard_event_source());
  al_register_event_source(queue, al_get_display_event_source(al_get_current_display()));
  al_register_event_source(queue, al_get_timer_event_source(timer));


  bool done = false;
  bool redraw = true;

  key_init();

  al_start_timer(timer);

  while (1)
  {
    ALLEGRO_EVENT ev;
    al_wait_for_event(queue, &ev);
    
    switch (ev.type)
    {
      case ALLEGRO_EVENT_TIMER:
        update_ship();
        update_aliens();
        shoot();
        update_ship_shot();
        for (int i = 0; i < ALLEGRO_KEY_MAX; i++)
        {
          key[i] &= ~KEY_SEEN;
        }
        redraw = true;
        if (key[ALLEGRO_KEY_ESCAPE]) done = true;
        break;
      case ALLEGRO_EVENT_KEY_DOWN:
        key[ev.keyboard.keycode] = KEY_SEEN | KEY_DOWN;
      break;

      case ALLEGRO_EVENT_KEY_UP:
        key[ev.keyboard.keycode] &= ~KEY_DOWN;
      break;

      case ALLEGRO_EVENT_DISPLAY_CLOSE:
        done = true;
        break;
    }

    if (done) break;

    // Desenho
    else if (redraw && al_is_event_queue_empty(queue)) {
      pre_draw_disp();
      al_clear_to_color(al_map_rgb(0, 0, 0)); // fundo preto
      draw_ship_shot();
      draw_aliens();
      draw_ship();
      pos_draw_disp();
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
