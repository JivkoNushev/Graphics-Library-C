#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <errno.h>

#include "pencil.h"

#define WIDTH 800
#define HEIGHT 600

static uint32_t pixels[WIDTH * HEIGHT];

int main(int argc, char const *argv[])
{
    pencil_fill_full(pixels, WIDTH, HEIGHT, 0xFF00FF00);

    if(-1 == pencil_save_to_ppm(pixels, WIDTH, HEIGHT, "../ppmImages/greenBackground.ppm"))
        perror("saving to ppm");

    return 0;
}
