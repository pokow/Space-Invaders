
# Nomes dos executáveis
TARGETS = test 
# Arquivos fonte
SRC = test.c 
# Compilador
CC = gcc

# Flags do compilador e linker via pkg-config
CFLAGS = $(shell pkg-config --cflags allegro-5 allegro_main-5 allegro_primitives-5 allegro_image-5 allegro_font-5)
LIBS = $(shell pkg-config --libs allegro-5 allegro_main-5 allegro_primitives-5 allegro_image-5 allegro_font-5)

# Regra padrao: compila todos os alvos
all: $(TARGETS)

# Compila test.c --> test.exe
test: test.c
	$(CC) $(CFLAGS) test.c -o test $(LIBS)

# Limpeza
clean:
	rm -f $(TARGETS)
