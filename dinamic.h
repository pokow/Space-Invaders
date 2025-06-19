#ifndef DINAMIC_HEADER
#define DINAMIC_HEADER

#include <allegro5/allegro5.h>
#include "general.h"
#include "ship.h"
#include "ship_shot.h"
#include "alien.h"
#include "sprites.h"
#include "alien_shot.h"
#include "boss.h"

void reset_all();
void start_game();
void update_game_state(bool* pre_game, bool* in_game, bool* pos_game, bool* game_over);
void increase_difficulty();
void reset_difficulty();
void update_phase();
void define_type_of_phase();

extern int phase;
extern bool normal_phase;
extern bool boss_phase;

#endif
