#include <stdio.h>
#include <stdint.h>
#include <errno.h>

#include "ErrorHandling/errorHandler.h"
#include "pencil.h"

void pencil_fill_full(
    uint32_t *pixels, 
    size_t pixels_width,
    size_t pixels_height,
    uint32_t color)
{
    // coloring every pixel one by one
    for(size_t i = 0; i < pixels_width * pixels_height; i++)
    {
        pixels[i] = color;
    }
}

Errno pencil_save_to_ppm(
    uint32_t *pixels,
    size_t pixels_width,
    size_t pixels_height,
    char *file_path)
{
    int return_status = 0;

    // opening a file with write permissions
    FILE *f = fopen(file_path, "wb");
    if(NULL == f) return_(errno);

    // writing the ppm format header to the file
    fprintf(f, "P6\n%lu %lu 255\n", pixels_width, pixels_height);
    if(ferror(f)) return_(errno);


    // writing the pixels to file one by one
    for(size_t i = 0; i < pixels_width * pixels_height; ++i)
    {
        // 0xAABBGGRR
        // removing the alpha, because ppm doesn't support it
        uint32_t pixel = pixels[i];
        uint8_t bytes[3] = {
            (pixel >> (8 * 0)) & 0xFF,
            (pixel >> (8 * 1)) & 0xFF,
            (pixel >> (8 * 2)) & 0xFF
        };

        // writing the pixel to the file
        fwrite(bytes, sizeof bytes, 1, f);
        if (ferror(f)) return_(errno);
    }

return_label: 
    if (f) fclose(f);
    return return_status;
}