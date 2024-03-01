#include "../inc/header.h"

void ingame_menu_esc_render(bool *isMenuOpen, bool *settingsOpened) {
    if (!(*isMenuOpen)) {
        *isMenuOpen = true;
    } else if (*isMenuOpen && *settingsOpened) {
        *settingsOpened = false;
    } else if (*isMenuOpen) {
        *isMenuOpen = false;
    }
    if (*settingsOpened) {
        *settingsOpened = false;
    }
}

