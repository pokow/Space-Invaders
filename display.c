#include "display.h"
#include <allegro5/allegro5.h>

ALLEGRO_DISPLAY* display;
ALLEGRO_BITMAP* buffer;

void display_init()
{
  //suavizacao de graficos
  al_set_new_display_option(ALLEGRO_VSYNC, 0, ALLEGRO_SUGGEST);
  al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
  al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);
  //cria display e buffer com as escalas adequadas
  al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
  display = al_create_display(DISP_W, DISP_H);
  must_init(display, "display");
  buffer = al_create_bitmap(BUFFER_W, BUFFER_H);
  must_init(buffer, "buffer");
}

void pre_draw_disp()
{
  // o pre-draw e' o desenho feito primeiro no buffer
  al_set_target_bitmap(buffer);
}

void pos_draw_disp()
{
  // o pos-draw e' o redimensionamento do desenho do buffer para o display
  al_set_target_backbuffer(display);
  al_draw_scaled_bitmap(buffer, 0, 0, BUFFER_W, BUFFER_H, 0, 0, DISP_W, DISP_H, 0);
  al_flip_display();
}

void destroy_disp_buff()
{
  al_destroy_bitmap(buffer);
  al_destroy_display(display);
}
