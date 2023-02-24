#ifndef PENCIL
#define PENCIL

#include "ErrorHandling/errorHandler.h"

typedef struct 
{
    int x;
    int y;
    size_t width;
    size_t height;
    uint32_t color;

} Rectangle;

// fills the canvas with one color
void pencil_fill_full(
    uint32_t *pixels,  
    size_t pixels_width, 
    size_t pixels_height, 
    uint32_t color
);

// saves an image to a ppm file
Errno pencil_save_to_ppm(
    uint32_t *pixels, 
    size_t pixels_width, 
    size_t pixels_height, 
    char *file_path
);

// draw a rectangle on the canvas
void pencil_draw_rectangle(
    uint32_t *pixels, 
    size_t pixels_width,
    size_t pixels_height,
    int rectangle_x,
    int rectangle_y,
    size_t rectangle_width,
    size_t rectangle_height,
    uint32_t color
);

// draw a rectangle on the canvas with a structure
void pencil_draw_rectangle_t(
    uint32_t *pixels, 
    size_t pixels_width,
    size_t pixels_height,
    Rectangle* rectangle
);

#endif
