CC=clang
CFLAGS=-std=c11 -Wall -pedantic -Iresource -Isrc
LDFLAGS=-Lresource/SDL2-2.30.0/lib/x64 -Lresource/SDL2_mixer-2.8.0/i686-w64-mingw32/lib -Lresource/SDL2_image-2.8.2/lib/x64  -Lresource/SDL2_ttf-2.22.0/lib/x64
LDLIBS=-lSDL2  -lSDL2_mixer -lSDL2_image -lSDL2_ttf
SRC=$(wildcard src/*.c)
OBJ=$(SRC:.c=.o)
EXEC=endgame

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(LDFLAGS) $^ -o $@ $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)
