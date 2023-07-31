#include "cub3d.h"

int set_back_fog(int hex_color, float dist, int fog_color)
{
    int red;
    int green;
    int blue;

    dist = ((float)-dist / (HEIGHT / 2.0));
    red = (hex_color >> 24) & fog_color;
    green = (hex_color >> 16) & fog_color;
    blue = (hex_color >> 8) & fog_color;
    red = red * (dist);
    green = green * (dist);
    blue = blue * (dist);
    return (rgba_to_hex(red, green, blue, 255));
}