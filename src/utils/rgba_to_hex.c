#include "cub3d.h"

int    rgba_to_hex(int r, int g, int b, int a)
{
    int    hex;

    hex = ((r & 0xff) << 24) + ((g & 0xff) << 16) + ((b & 0xff) << 8) + (a & 0xff);
    return (hex);
}