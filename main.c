#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <errno.h>


#define return_defer(status) do{ return_status = status; goto defer_label; }while(0)

#define WIDTH 800
#define HEIGHT 600

static uint32_t pixels[WIDTH * HEIGHT];

int write_to_file(int fd, char *data, size_t size)
{
    size_t  BLOCK_SIZE = 512;

    int     write_status = 0;
    char    *it_start = data, 
            *it_end = data + size;

    while(it_start < it_end)
    {
        printf("%s\n", it_start);

        if(size < BLOCK_SIZE)
        {
            if(-1 == (write_status = write(fd, it_start, size)))
            {
                return -1;
            }
            break;
        }

        if(-1 == (write_status = write(fd, it_start, BLOCK_SIZE)))
        {
            return -1;
        }
        printf("write-status = %d", write_status);
        it_start += write_status;
        size -= BLOCK_SIZE;
    }

    if( -1 == lseek(fd, SEEK_CUR, -size)) return -1;

    printf("file_pos = %ld\n", lseek(fd, 0, SEEK_CUR));

    return 0;
}

void pencil_fill_full(
    uint32_t *pixels, 
    size_t pixels_width,
    size_t pixels_height,
    uint32_t color)
{
    for(size_t i = 0; i < WIDTH * HEIGHT; i++)
    {
        pixels[i] = color;
    }
}

int pencil_save_to_ppm(
    uint32_t *pixels,
    size_t pixels_width,
    size_t pixels_height,
    char *file_path)
{
    int return_status = 0;

    int file_flags = O_WRONLY;
    int mode = 0;
    if(-1 == access(file_path, F_OK))
    {
        file_flags |= O_CREAT;
        mode |= S_IRWXU | S_IRWXG | S_IRWXO;
    }

    int fd_to_ppm = open(file_path, file_flags, mode);
    if(-1 == fd_to_ppm) return_defer(-1);
puts("Here");

    if(-1 == write_to_file(fd_to_ppm, "P6\n800 600 255\n", sizeof "P6\n800 600 255\n"))
        return_defer(-1);
    puts("Here");
    if(-1 == write_to_file(fd_to_ppm, (char*)pixels, sizeof (size_t) * pixels_width * pixels_height))
        return_defer(-1);
puts("Here");
defer_label:
    close(fd_to_ppm);
    return return_status;
}

int main(int argc, char const *argv[])
{
    pencil_fill_full(pixels, WIDTH, HEIGHT, 0xFF00FF00);

    if(-1 == pencil_save_to_ppm(pixels, WIDTH, HEIGHT, "greenBackground.ppx"))
        perror("saving to ppx");


    return 0;
}
