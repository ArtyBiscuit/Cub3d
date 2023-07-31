#include "cub3d.h"

t_texture   *img_to_struct(mlx_image_t *img)
{
    int         i;
    int         j;
    uint8_t     *pixels;
    t_texture   *texture;

    i = 0;
    j = 0;
    pixels = img->pixels;
    texture = malloc(sizeof(t_texture));
    texture->pixels = malloc((int)(img->height * img->width) * sizeof(int));
    texture->size_x = img->width;
    texture->size_y = img->height;
    while (i < (int)((img->height * img->width) * 4))
    {
        texture->pixels[j] = rgba_to_hex(pixels[i],pixels[i + 1],pixels[i + 2], pixels[i + 3]);
        j += 1;
        i += 4;
    }
    return (texture);
}