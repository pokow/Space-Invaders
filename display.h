#ifndef DISPLAY_HEADER
#define DISPLAY_HEADER
#include <allegro5/allegro5.h>
#include "general.h"

#define BUFFER_W 320
#define BUFFER_H 240

#define DISP_SCALE 2.9
#define DISP_W (BUFFER_W * DISP_SCALE)
#define DISP_H (BUFFER_H * DISP_SCALE)

#define WIN_W (DISP_W + 20)
#define WIN_H (DISP_H + 20)

#define BUFFER_X (WIN_W - DISP_W) / 2
#define BUFFER_Y (WIN_H - DISP_H) / 2

void display_init();

void draw_pre_game();

void pre_draw_disp();

void pre_draw_disp();

void pos_draw_disp();

void draw_pos_game();

void destroy_disp_buff();

extern ALLEGRO_DISPLAY* display;
extern ALLEGRO_BITMAP* buffer;

#endif
