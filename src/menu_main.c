#include "../inc/header.h"

int menu() {
    sdl_init();
    SDL_Window* window = sdl_window();
    SDL_Renderer* renderer = sdl_render(window);

    SDL_Texture* backgroundTexture[4];
    SDL_Texture* authorsBackgroundTexture;
    SDL_Texture* buttonTextures[4];
    SDL_Texture* settingsButtonTextures[7];

    init_texture_menu(renderer, backgroundTexture, &authorsBackgroundTexture, buttonTextures, settingsButtonTextures);

    SDL_Event e;

    bool SetWindowSize1280x720 = false;
    bool SetWindowSize800x600 = false;
    bool SetWindowSize1920x1080 = true;

    bool inSettingsPage = false;
    bool inAuthorsPage = false;
    bool quit = false;


    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {

            if (e.type == SDL_QUIT)
                quit = true;

            else if (e.type == SDL_MOUSEBUTTONDOWN) {
                if (SetWindowSize1920x1080 && !SetWindowSize1280x720 && !SetWindowSize800x600) {

                    if (!inSettingsPage && !inAuthorsPage) {
                        if (handle_mouse_button_down(e, 100, 800, 210, 370)) {
                            start_game(window, renderer);
                        }
                        if (handle_mouse_button_down(e, 100, 800, 390, 550)) {
                            inSettingsPage = true;
                        }
                        inAuthorsPage = handle_mouse_button_down(e, 100, 800, 570, 730) ? true: inAuthorsPage;
                        quit = handle_mouse_button_down(e, 100, 800, 750, 910) ? true : quit;
                    }

                    if (inSettingsPage) {
                        handle_mouse_button_down(e, 460, 760, 570, 681); // Первая кнопка
                        if (handle_mouse_button_down(e, 290, 490, 380, 455)) {
                            SDL_SetWindowSize(window, 800, 600);
                            SetWindowSize1920x1080 = false;
                            SetWindowSize800x600 = true;
                            SetWindowSize1280x720 = false;
                        }
                        if (handle_mouse_button_down(e, 810, 1120, 570, 681)) {
                            SDL_SetWindowSize(window, 1280, 720);
                            SetWindowSize1920x1080 = false;
                            SetWindowSize800x600 = false;
                            SetWindowSize1280x720 = true;
                        }
                        if (handle_mouse_button_down(e, 1170, 1470, 570, 681)) {
                            SDL_SetWindowSize(window, 1920, 1080);
                            SetWindowSize1920x1080 = true;
                            SetWindowSize800x600 = false;
                            SetWindowSize1280x720 = false;
                        }
                        handle_mouse_button_down(e, 720, 920, 815, 890); // Кнопка "Настройка 1"
                        handle_mouse_button_down(e, 1020, 1220, 815, 890); // Кнопка "Настройка 2"
                    }
                }

                if (!SetWindowSize1920x1080 && SetWindowSize1280x720 && !SetWindowSize800x600) {
                    if (!inSettingsPage && !inAuthorsPage) {
                        handle_mouse_button_down(e, 50, 500, 140, 250);
                        inSettingsPage = handle_mouse_button_down(e, 50, 500, 270, 380) ? true
                                                                                                                 : inSettingsPage;
                        inAuthorsPage = handle_mouse_button_down(e, 50, 500, 400, 510) ? true
                                                                                                                : inAuthorsPage;
                        quit = handle_mouse_button_down(e, 50, 500, 530, 640) ? true : quit;
                    }
                    if (inSettingsPage) {
                        if (handle_mouse_button_down(e, 290, 490, 380, 455)) {
                            SDL_SetWindowSize(window, 800, 600);
                            SetWindowSize1920x1080 = false;
                            SetWindowSize800x600 = true;
                            SetWindowSize1280x720 = false;
                        }
                        if (handle_mouse_button_down(e, 540, 740, 380, 455)) {
                            SDL_SetWindowSize(window, 1280, 720);
                            SetWindowSize1920x1080 = false;
                            SetWindowSize800x600 = false;
                            SetWindowSize1280x720 = true;
                        }
                        if (handle_mouse_button_down(e, 790, 990, 380, 455)) {
                            SDL_SetWindowSize(window, 1920, 1080);
                            SetWindowSize1920x1080 = true;
                            SetWindowSize800x600 = false;
                            SetWindowSize1280x720 = false;
                        }
                        handle_mouse_button_down(e, 510, 645, 540, 595);
                        handle_mouse_button_down(e, 695, 830, 540, 595);
                    }
                }

                if (!SetWindowSize1920x1080 && !SetWindowSize1280x720 && SetWindowSize800x600) {
                    if (!inSettingsPage && !inAuthorsPage) {
                        handle_mouse_button_down(e, 60, 370, 100, 190);
                        inSettingsPage = handle_mouse_button_down(e, 60, 370, 210, 300) ? true
                                                                                                                 : inSettingsPage;
                        inAuthorsPage = handle_mouse_button_down(e, 60, 370, 320, 410) ? true
                                                                                                                : inAuthorsPage;
                        quit = handle_mouse_button_down(e, 60, 370, 430, 520) ? true : quit;
                    }
                    if (inSettingsPage) {
                        if (handle_mouse_button_down(e, 290, 490, 380, 455)) {
                            SDL_SetWindowSize(window, 800, 600);
                            SetWindowSize1920x1080 = false;
                            SetWindowSize800x600 = true;
                            SetWindowSize1280x720 = false;
                        }
                        if (handle_mouse_button_down(e, 540, 740, 380, 455)) {
                            SDL_SetWindowSize(window, 1280, 720);
                            SetWindowSize1920x1080 = false;
                            SetWindowSize800x600 = false;
                            SetWindowSize1280x720 = true;
                        }
                        if (handle_mouse_button_down(e, 790, 990, 380, 455)) {
                            SDL_SetWindowSize(window, 1920, 1080);
                            SetWindowSize1920x1080 = true;
                            SetWindowSize800x600 = false;
                            SetWindowSize1280x720 = false;
                        }
                        handle_mouse_button_down(e, 300, 390, 455, 495);
                        handle_mouse_button_down(e, 450, 540, 455, 495);
                    }
                }
            } else if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.sym == SDLK_ESCAPE) {
                    if (inSettingsPage) {
                        inSettingsPage = false;
                    }
                    if (e.key.keysym.sym == SDLK_ESCAPE) {
                        if (inAuthorsPage) {
                            inAuthorsPage = false;
                        }
                    }
                }
            }

            if (SetWindowSize1920x1080) {
                win_buildFHD(renderer, window, backgroundTexture, buttonTextures, settingsButtonTextures,
                             authorsBackgroundTexture, e, inSettingsPage, inAuthorsPage);
            } else if (SetWindowSize1280x720) {
                win_buildHD(renderer, window, backgroundTexture, buttonTextures, settingsButtonTextures,
                            authorsBackgroundTexture, e, inSettingsPage, inAuthorsPage);
            } else if (SetWindowSize800x600) {
                win_buildNHD(renderer, window, backgroundTexture, buttonTextures, settingsButtonTextures,
                             authorsBackgroundTexture, e, inSettingsPage, inAuthorsPage);
            }
        }
    }
    for (int i = 0; i < 4; ++i)
        SDL_DestroyTexture(*backgroundTexture);
    for (int i = 0; i < 7; ++i)
        SDL_DestroyTexture(settingsButtonTextures[i]);
    for (int i = 0; i < 4; ++i)
        SDL_DestroyTexture(buttonTextures[i]);
    SDL_DestroyTexture(authorsBackgroundTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;  
}


