#include "../inc/header.h"

void ingame_main_menu_set(SDL_Event event, bool *isMenuOpen, bool *settingsOpened) {
    if(handle_mouse_button_down(event, 680, 1280, 300, 450)) {
        *isMenuOpen = false;
    }
    if(handle_mouse_button_down(event, 680, 1280, 500, 650)) {
        *settingsOpened = true;
    }
    if(handle_mouse_button_down(event, 680, 1280, 700, 850)) {
        SDL_Quit();
        exit(0);
    }
}


