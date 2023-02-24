#ifndef PENCIL
#define PENCIL

#include "ErrorHandling/errorHandler.h"

// fills the canvas with one color
void pencil_fill_full(uint32_t *pixels,  size_t pixels_width, size_t pixels_height, uint32_t color);

// saves an image to a ppm file
Errno pencil_save_to_ppm(uint32_t *pixels, size_t pixels_width, size_t pixels_height, char *file_path);

#endif
