EXEC = space_invaders

CC = gcc

CFLAGS = -Wall -std=c11 -g

SRC = main.c display.c ship.c sprites.c general.c ship_shot.c alien.c collision.c alien_shot.c dinamic.c boss.c boss_attack.c

OBJ = $(SRC:.c=.o)

ALLEGRO_FLAGS = $(shell pkg-config --cflags --libs allegro-5 allegro_image-5 allegro_font-5 allegro_ttf-5 allegro_primitives-5 allegro_audio-5 allegro_acodec-5 allegro_main-5 allegro_dialog-5)

# Regra padrão
all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(ALLEGRO_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< $(ALLEGRO_FLAGS)

clean:
	rm -f $(OBJ) $(EXEC)
