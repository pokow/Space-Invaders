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
  //descobrir largura e altura do monitor para centralizar janela
  ALLEGRO_MONITOR_INFO info;
  al_get_monitor_info(0, &info);
  int screen_w = info.x2 - info.x1; 
  int screen_h = info.y2 - info.y1;

  //com base nas medidas do monitor define posicao do display
  int disp_x = (screen_w - WIN_W)/2;
  int disp_y = (screen_h - WIN_H)/2;

  //cria display e buffer com as escalas adequadas
  display = al_create_display(WIN_W, WIN_H);
  must_init(display, "display");
  al_set_window_position(display, disp_x, disp_y);
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
  int buff_x = (WIN_W - DISP_W)/2;
  int buff_y = (WIN_H - DISP_H)/2;
  al_draw_scaled_bitmap(buffer, 0, 0, BUFFER_W, BUFFER_H, buff_x, buff_y, DISP_W, DISP_H, 0);
  al_flip_display();
}

void destroy_disp_buff()
{
  al_destroy_bitmap(buffer);
  al_destroy_display(display);
}
