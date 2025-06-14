# Nome do executável
EXEC = jogo

# Compilador
CC = gcc

# Flags do compilador
CFLAGS = -Wall -std=c11 -g

# Arquivos fonte
SRC = main.c display.c ship.c sprites.c general.c ship_shot.c alien.c

# Objetos
OBJ = $(SRC:.c=.o)

# Flags do Allegro
ALLEGRO_FLAGS = $(shell pkg-config --cflags --libs allegro-5 allegro_image-5 allegro_font-5 allegro_ttf-5 allegro_primitives-5 allegro_audio-5 allegro_acodec-5 allegro_main-5 allegro_dialog-5)

# Regra padrão
all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(ALLEGRO_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< $(ALLEGRO_FLAGS)

clean:
	rm -f $(OBJ) $(EXEC)
