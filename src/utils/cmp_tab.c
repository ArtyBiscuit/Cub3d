#include "cub3d.h"

int get_map_size_x(char **map)
{
    int f_len;
    int i;

    i = 0;
    f_len = 0;
    while (map[i])
	{
		if ((int)ft_strlen(map[i]) > f_len)
			f_len = ft_strlen(map[i]);
		i++;
	}
    return (f_len);
}

int get_map_size_y(char **map)
{
    int i;

    i = 0;
    while(map[i])
        i++;
    return (i);
}