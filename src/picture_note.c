#include "../inc/header.h"

void book_note(SDL_Renderer* render, SDL_Texture** texture, SDL_Rect* position, SDL_Texture** this_texture) {
    *texture = load_texture("resource/static/first_room/active/note_2.PNG", render);
    *position = (SDL_Rect) {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    printf("Book is opened\n");
}

