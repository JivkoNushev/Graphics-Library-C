#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <errno.h>

#include "Errorhandling/errorHandler.h"
#include "pencil.h"

#define WIDTH 800
#define HEIGHT 600

#define SDL_PLATFORM 1

static uint32_t pixels[WIDTH * HEIGHT];

uint32_t* render(float dt)
{
    pencil_fill_full(pixels, WIDTH, HEIGHT, 0xFF00FF00);
    pencil_draw_rectangle(pixels, WIDTH, HEIGHT, 200, 200, 20, 20, 0xFF00FFFF);

    return pixels;
}

#if SDL_PLATFORM == 1

#include <SDL2/SDL.h>

#endif


int main(int argc, char const *argv[])
{
    pencil_fill_full(pixels, WIDTH, HEIGHT, 0xFF00FF00);
    pencil_draw_rectangle(pixels, WIDTH, HEIGHT, 200, 200, 20, 20, 0xFF00FFFF);

    if(-1 == pencil_save_to_ppm(pixels, WIDTH, HEIGHT, "../ppmImages/greenBackground.ppm"))
        perror("saving to ppm");

    return 0;
}
